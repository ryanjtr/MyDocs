PULP Toolchain and SDK
-------------------------------

Introduction
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

PULP (Parallel Ultra-Low Power) Platform is a holistic initiative aimed at developing energy-efficient 
parallel computing solutions. It encompasses various hardware and software components tailored for 
embedded and IoT applications, along with a vibrant community promoting collaboration and innovation. 
The hardware components include PULP cores and systems designed for minimal power consumption and 
optimized performance. On the software side, the platform supports operating systems, compilers, 
development tools, libraries, middleware, and frameworks to streamline application development. 
The open-source nature of PULP encourages innovation and knowledge-sharing, while educational 
resources empower developers to harness parallel computing for energy-efficient solutions. 
Overall, the PULP Platform provides a comprehensive ecosystem to foster the advancement of 
energy-efficient computing in diverse embedded and IoT domains.

PULP Toolchain installation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Open new terminal to create new directory:

.. code-block:: bash

    cd
    cd /opt
    sudo mkdir riscv
    cd riscv
    sudo mkdir bin

Setup path:

.. code-block:: bash

    nano ~/.profile

Add

.. code-block:: bash 

    if [ -d "/opt/riscv" ] ; then
        PATH="/opt/riscv:$PATH"
    fi

.. Note:: 

    Log out Ubuntu and then log in after edit ``.profile``

Prerequisite

.. code-block:: bash 

    sudo apt-get install autoconf automake autotools-dev curl libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev

Follow these steps to install toolchain:

.. code-block:: bash

    git clone https://github.com/pulp-platform/pulp-riscv-gnu-toolchain
    cd pulp-riscv-gnu-toolchain
    git submodule update --init --recursive

Cause ``/opt/riscv/bin`` is in ``root``, so must use ``sudo`` in ``make``

.. code-block:: bash

    ./configure --prefix=/opt/riscv --with-arch=rv32imc --with-cmodel=medlow --enable-multilib
    sudo make

PULP SDK installation
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Prerequisite

.. code-block:: bash

    sudo apt-get install -y build-essential git libftdi-dev libftdi1 doxygen python3-pip libsdl2-dev curl cmake libusb-1.0-0-dev scons gtkwave libsndfile1-dev rsync autoconf automake texinfo libtool pkg-config libsdl2-ttf-dev

Follow these steps:

.. code-block:: bash

    pip install argcomplete pyelftools six
    pip install prettytable

Clone pulp SDK and update submodule:

.. code-block:: bash
    
    git clone https://github.com/pulp-platform/pulp-sdk.git
    cd pulp-sdk
    git submodule update --init --recursive

Edit ``pulp-sdk/configs/pulp-open.sh``, below line 32:

.. code-block:: bash

    export PULP_RISCV_GCC_TOOLCHAIN=/opt/riscv 

Build gvsoc

.. code-block:: bash

    source configs/pulp-open.sh
    make build

.. Note:: 

    Always run command ``source configs/pulp-open.sh`` before running or doing anything in ``pulp-sdk`` directory

First simple test
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    cd pulp-sdk
    source configs/pulp-open.sh
    cd tests/hello

    make clean all run

References
~~~~~~~~~~~~~~~~~~

`[1]. Installation toolchain and sdk <https://www.pulp-platform.org/docs/pulp_training/NBruschi_gvsoc_tutorial_part1.pdf>`_



.. Environments module installation
.. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. Prerequisite: ``tcl``

.. .. code-block:: bash

..     sudo apt-get install tcl8.6-dev



..  ./configure --with-to /usr/lib/tlc8.6/


Run code in pulp-sdk
~~~~~~~~~~~~~~~~~~~~~~~~

Copy project folder to path ``pulp-sdk/tests/`` and then run.


Lab
~~~~~~

LAB3
**********
`Slide and assignemnts <https://github.com/EEESlab/APAI23-LAB03-PULP-Embedded-Programming/blob/f862501580a95426f8a420779cf88869e134b596/docs/slides.pdf>`_

#. Task 1


If we change define N with 350. The checksum and the result will not be correct due to the limited range of data type ``unsigned char``, just 0-255. 
So we must change the data type of array to ``unsigned int`` to have better range.

.. code-block:: c

        /*
    * Copyright (C) 2021 University of Bologna
    * All rights reserved.
    *
    * This software may be modified and distributed under the terms
    * of the BSD license.  See the LICENSE file for details.
    *
    * Authors: Manuele Rusci 	  UniBO (manuele.rusci@unibo.it)
    * 			Lorenzo Lamberti  UniBO (lorenzo.lamberti@unibo.it)
    */

    #include "pmsis.h"

    #define N 350			 // array size
    unsigned int array_1[N]; // define array of size N. 	[important note]: "char" data type means its elements are 8 bit! (range from 0 to 255)

    // intialize an array A_ar with _size_ number of elements
    // and precompute the result (we use this as a checksum)
    int init_array(unsigned int *A_ar, int size)
    {
        for (int i = 0; i < size; i++)
            A_ar[i] = i + 1; // this can be changed to whatever pattern

        return (size * (size + 1)) >> 1; // this computes the sum as the vector_sum() function. only needed as a checksum.
    }

    // print array elements
    void print_array(unsigned int *A_ar, int size)
    {
        for (int i = 0; i < size; i++)
            printf("%d ", A_ar[i]); // print array element
        printf("\n");
    }

    // return the index of the item==element of the array A_ar with size number of elements
    int vector_sum(unsigned int *A_ar, int size)
    {
        int sum = 0; // initialize accumulator to 0

        // perform the sum
        for (int i = 0; i < size; i++)
        {
            sum += A_ar[i];
        }
        return sum;
    }

    int main()
    {
        printf("This example program computes the sum of %d integer numbers!\n", N);

        // initialize the array and get the expected result
        int expected_result = init_array(array_1, N);

        // inspect the array. let's print its values !
        print_array(array_1, N);

        // call the vector_sum function
        int computed_result = vector_sum(array_1, N);

        // check if the results is correct
        if (computed_result == expected_result)
            printf("Result is correct. Got %d\n", computed_result);
        else
            printf("Result is not correct. Got %d instead of %d\n", computed_result, expected_result);
    }

#. Task 2


Code in task 2 performs maxtrix-vector multiplication and measures its performance using performance counter
on the PULP platform.

.. code-block:: C

        /*
    * Copyright (C) 2022 University of Bologna
    * All rights reserved.
    *
    * This software may be modified and distributed under the terms
    * of the BSD license.  See the LICENSE file for details.
    *
    * Authors: Manuele Rusci 	  UniBO (manuele.rusci@unibo.it)
    * 			Lorenzo Lamberti  UniBO (lorenzo.lamberti@unibo.it)
    */
    #include "pmsis.h"
    #include "stdbool.h" // to use "bool" data type

    /*  defines */
    #define N 50 // the matrix size is NxM, and the vector size is M.
    #define M 50
    #define MAT_EL (2) // matrix constant values
    #define VEC_EL (4) // vector constant values
    int mac_counter = 0;

    /* Allocation of IO variables into L2 memory */
    // input variables
    PI_L2 int matrix[N * M]; // the matrix as an array of size N*M
    PI_L2 int vector[M];	 // the vector as an array of size M
    // output variable
    PI_L2 int output_vec[N]; // N*M x M*1 -> N*1
    /*  Note: PI_L2 is an attribute for "forcing" allocation in L2 memory.
        Ref: /pulp/pulp-sdk/rtos/pulpos/common/include/pos/data/data.h:54: */

    void start_perf_counter()
    {
        // enable the perf counter of interest
        pi_perf_conf(1 << PI_PERF_CYCLES /*YOUR_CODE_HERE*/ | // count cycles
                    1 << PI_PERF_INSTR /*YOUR_CODE_HERE*/);  // count instructions
        // reset the perf counters
        pi_perf_reset();
        //  start the perf counter
        pi_perf_start();
    }

    void stop_perf_counter()
    {
        // stop the perf counter
        pi_perf_stop();
        // collect and print statistics
        uint32_t cycles_counter = pi_perf_read(PI_PERF_CYCLES);
        uint32_t instr_counter = pi_perf_read(PI_PERF_INSTR);

        /*
            TASK 2.2
            Measure:
                - How many MAC operations are needed for the gemv
            Calculate:
                - CPI
                - MACs/Cycles
                - Instructions/Cycles
                - Instructions/ MACs
        */

        // N° Multiply Accumulate Operations (MACs)
        /* already done with task 2.1. use the mac_counter global variable */
        // CPI = cycles / n°instructions_executed
        float cpi = cycles_counter / instr_counter; /* YOUR CODE HERE*/
        // MAC/Cycles
        float mac_on_cycles = (N * M) / cycles_counter; /* YOUR CODE HERE*/
        // Instructions/Cycles
        float instructions_on_cycles = instr_counter / cycles_counter; /* YOUR CODE HERE*/
        // Instructions/MAC
        float instructions_on_mac = instr_counter / (N * M); /* YOUR CODE HERE*/

        // print results
        printf("--- Performances ---------\n");
        printf("Cycles: %d \n", cycles_counter);					  // this comes from the performance counter
        printf("N° of Intructions: %d\n", instr_counter);			  // this comes from the performance counter
        printf("mac: %d \n", mac_counter);							  // you must measure this
        printf("CPI: %f \n", cpi);									  // calculate it
        printf("Instructions/Cycles: %f \n", instructions_on_cycles); // calculate it
        printf("Instructions/MAC: %f \n", instructions_on_mac);		  // calculate it
        printf("-------------------------\n");
    }

    // print array elements
    void print_array(int *A_ar, int size)
    {
        for (int i = 0; i < size; i++)
            printf("%d ", A_ar[i]); // print array element
        printf("\n");
    }

    /* generic matrix-vector multiplication */
    int __attribute__((noinline)) gemv(int size_N, int size_M, int *mat_i, int *vec_i, int *vec_o)
    {
        /*
        TASK 2.1
        - you must count the MAC by increasing a counter in the inner loop of the gemv.
        - use the "mac_counter" global variable
        */
        mac_counter = 0;
        for (int i = 0; i < size_N; i++) // outer looop of the gemv
        {
            for (int j = 0; j < size_M; j++) // inner loop of the gemv
            {
                // multiply accumulate operation (MAC)
                vec_o[i] += mat_i[i * size_M + j] * vec_i[j];
                // *(vec_o + i) += *(mat_i + i * M + j) * (*(vec_i + j)); // try to uncomment this and comment the above line. You will notice a speedup in cycles
                ++mac_counter;
            }
        }
    }

    int main()
    {
        start_perf_counter();
        // Initialization of operands: matrix
        for (int i = 0; i < (N * M); i++)
        {
            matrix[i] = MAT_EL;
        }
        // Initialization of operands: vector
        for (int i = 0; i < M; i++)
        {
            vector[i] = VEC_EL;
        }
        // Initialization of the output to 0
        for (int i = 0; i < N; i++)
        {
            output_vec[i] = 0;
        }
        printf("\n");

        /* call the GEneric Matrix-Vector (gemv) function */
        gemv(N, M, matrix, vector, output_vec);

        // print and check the results
        printf("\nThe %d output elements are: \n", N);
        print_array(output_vec, N);

        // check here the results
        int correctness = 1;
        for (int i = 0; i < N; i++)
        {
            if (output_vec[i] != (M * MAT_EL * VEC_EL))
            {
                correctness = 0;
                break;
            }
        }
        printf(correctness ? "\nRESULTS MATCHING: correct\n" : "RESULTS NOT MATCHING: not correct\n");

        stop_perf_counter();
    }

.. list-table:: Performance
    :widths: 25 25 25 25
    :header-rows: 1

    * 
      - 
      - -01
      - -03
      - -03 HWLoops
    *
      - Clock Cycles
      - 198615
      - 186262
      - 190599
    *
      - Instr
      - 71427
      - 60329
      - 62622
    * 
      - MAC
      - 2500
      - 2500
      - 2500
    * 
      - CPI 
      - 2
      - 3
      - 3
    *
      - Intr/Cycles
      - 0
      - 0
      - 0
    *
      - Intr/MAC
      - 28
      - 24
      - 25