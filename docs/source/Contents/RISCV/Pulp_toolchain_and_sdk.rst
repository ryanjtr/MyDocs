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

    Log out Ubuntu and then log in

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

    Before running or doing anything in ``pulp-sdk`` directory, you must run ``source configs/pulp-open.sh``

First simple test
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

