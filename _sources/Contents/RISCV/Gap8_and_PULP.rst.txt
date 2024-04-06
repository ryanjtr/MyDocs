GVSOC-GAP8 - PULP PLATFORM - TOOLCHAIN
-------------------------------




PULP platform
~~~~~~~~~~~~~~~~~~~~

Introduction
*****************

The PULP (Parallel Ultra-Low Power) Platform is a comprehensive initiative 
focused on creating energy-efficient parallel computing solutions. Here's a more detailed breakdown:

Hardware Components:

PULP Cores: These are processor cores specifically designed for energy efficiency 
and parallel computing. They are optimized to perform computations while consuming 
minimal power. Examples include PULPino, RI5CY, and Zero-riscy cores, each suited for 
different types of applications and power constraints.
PULP Systems: The platform provides reference designs and integration frameworks for 
assembling complete computing systems using PULP cores. These systems typically include 
processors, memory components, interfaces for peripherals (such as sensors or communication modules), and other necessary hardware elements.
Software Components:

Operating Systems: The PULP Platform supports various operating systems tailored for embedded and 
IoT applications. These operating systems provide the necessary infrastructure for managing hardware 
resources, scheduling tasks, and running applications efficiently.
Compilers and Development Tools: The platform offers compilers, debuggers, and other development tools 
to facilitate software development for PULP-based systems. These tools enable developers to write, compile, 
and debug code for their applications running on PULP cores.
Libraries and Middleware: PULP provides libraries and middleware to simplify common tasks in embedded 
software development, such as communication protocols, signal processing algorithms, and sensor data processing.
Development Frameworks: PULP offers development frameworks and methodologies to help developers design, 
optimize, and deploy applications on PULP-based systems. These frameworks provide guidelines, 
best practices, and reusable components to streamline the development process.
Community and Ecosystem:

Collaboration: The PULP community encourages collaboration among developers, researchers, and 
enthusiasts interested in energy-efficient computing. Collaboration happens through forums, 
mailing lists, workshops, and collaborative projects.
Open Source: PULP is an open-source project, meaning that its hardware and software components 
are freely available for anyone to use, modify, and contribute to. This open approach fosters 
innovation and accelerates the development of new technologies and applications.
Education and Outreach: The PULP Platform provides educational resources, tutorials, and 
documentation to help users get started with PULP-based development. It aims to educate and 
empower developers to leverage parallel computing for energy-efficient IoT and embedded applications.
In summary, the PULP Platform offers a comprehensive ecosystem of hardware and software components, 
along with a vibrant community, to support the development of energy-efficient parallel computing 
solutions for a wide range of embedded and IoT applications.



PULP Toolchain
----------------

Follow these steps:

.. code-block:: bash

    git clone https://github.com/pulp-platform/pulp-riscv-gnu-toolchain
    cd pulp-riscv-gnu-toolchain
    git submodule update --init --recursive

Open new terminal to create new directory:

.. code-block:: bash

    cd
    cd /opt
    sudo mkdir riscv
    cd riscv
    sudo mkdir bin

Then type:

.. code-block:: bash

    export PATH=/opt/riscv/bin:$PATH
    ./configure --prefix=/opt/riscv --with-arch=rv32imc --with-cmodel=medlow --enable-multilib
    make

PULP SDK
----------------

Follow these steps:

.. code-block:: bash

    pip install argcomplete pyelftools six
    pip install prettytable

Clone pulp SDK and update submodule:

.. code-block:: bash

    export PULP_RISCV_GCC_TOOLCHAIN=/opt/riscv 
    cd pulp-sdk
    git submodule update --init --recursive
    source configs/pulp-open.sh
    make build

