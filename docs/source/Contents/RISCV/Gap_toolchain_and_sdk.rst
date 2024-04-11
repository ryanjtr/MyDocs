Gap Toolchain and SDK
-------------------------------

Gap Toolchain installation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Ubuntu version: 22.04.4

Open new terminal to create new directory:

.. code-block:: bash

    cd
    cd /opt
    sudo mkdir riscv_gap
    cd riscv_gap
    sudo mkdir bin

Setup path:

.. code-block:: bash

    nano ~/.profile

Add

.. code-block:: bash 

    if [ -d "/opt/riscv_gap" ] ; then
        PATH="/opt/riscv_gap:$PATH"
    fi

.. Note:: 

    This will require a logout / login to take effect

Download following packages

.. code-block:: bash

    sudo apt-get install -y \
        autoconf \
        automake \
        bison \
        build-essential \
        cmake \
        curl \
        doxygen \
        flex \
        git \
        gtkwave \
        libftdi-dev \
        libftdi1 \
        libjpeg-dev \
        libsdl2-dev \
        libsdl2-ttf-dev \
        libsndfile1-dev \
        graphicsmagick-libmagick-dev-compat \
        libtool \
        libusb-1.0-0-dev \
        pkg-config \
        python3-pip \
        rsync \
        scons \
        texinfo \
        wget

SDK and some tools are all based on Python3 (version > 3.8), you can use following command to set your default python to python3.

.. code-block:: bash

    sudo update-alternatives --install /usr/bin/python python /usr/bin/python3 10

Open new terminal to install toolchain:

Prerequisite

.. code-block:: bash 

    sudo apt-get install autoconf automake autotools-dev curl libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev

Follow these steps to install toolchain:

.. code-block:: bash

    git clone https://github.com/riscv/riscv-gnu-toolchain
    cd riscv-gnu-toolchain
    git submodule update --init --recursive

Cause ``/opt/riscv_gap/bin`` is in ``root``, so must use ``sudo`` in ``make`` 

.. code-block:: bash

    ./configure --prefix=/opt/riscv --with-arch=rv32imc --with-cmodel=medlow --enable-multilib
    sudo make

Gap SDK installation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Open new terminal to install gap sdk

Clone gap sdk repository

.. code-block:: bash

    git clone https://github.com/GreenWaves-Technologies/gap_sdk.git
    cd gap_sdk

Our modules (gapy runner) require a few additional Python packages that you can install with this command from GAP SDK root folder:

.. code-block:: bash

    pip3 install -r requirements.txt
    pip3 install -r doc/requirements.txt

You can either source sourceme.sh in the root sdk folder and then select the right board from the list, or directly source the board config.

.. code-block:: bash

    source sourceme.sh

or 

Our modules (gapy runner) require a few additional Python packages that you can install with this command from GAP SDK root folder:

.. code-block:: bash

    source configs/<the target you want to use>.sh

.. note:: 

    Must select board before run any project

.. list-table:: Summary of the available boards and their configuration file.
    :widths: 15 15 25
    :header-rows: 1

    *
      - Board
      - Chip
      - Config file
    *
      - Gapuino	
      - GAP8 v1
      - configs/gapuino.sh  
    *
      - Gapuino		
      - GAP8 v2
      - configs/gapuino_v2.sh
    * 
      - Gapoc
      - GAP8 v1
      - configs/gapoc_a.sh
    * 
      - Gapoc
      - GAP8 v2	
      - configs/gapoc_a_v2.sh

After selecting the right board, run command below to build project

.. code-block:: bash

    make clean all run

Run ``make help`` to get other commands

.. code-block:: bash

    =================== GAP SDK ===================

    Main targets:
    - clean       : clean the SDK
    - all         : build the whole SDK with all tools
    - minimal     : get latest sources for all rtos and libs
    - gvsoc       : build GVSOC simulation platform
    - openocd.all : build OpenOCD tools to run simulation on boards
    - nntool      : build nntool

Depends on what you need, build the SDK accordingly

.. code-block:: bash

    make <target>



References
~~~~~~~~~~~~~~

`[1]. Gap toolchain installation <https://github.com/GreenWaves-Technologies/gap-riscv-gnu-toolchain>`_

`[2]. Gap sdk installation <https://github.com/GreenWaves-Technologies/gap_sdk>`_

`[3]. Gap8 manual <https://greenwaves-technologies.com/manuals/BUILD/HOME/html/index.html>`_