PICO TOOL
==============

.. contents:: Table of Contents
    :depth: 3
    :local:


Installation
-----------------

Install package and dependencies
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    .. code-block:: bash

        sudo apt update
        sudo apt install cmake build-essential libusb-1.0-0-dev

CLone picotool from github
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    .. code-block:: bash

        git clone https://github.com/raspberrypi/picotool.git
        cd picotool

Build pictotool
~~~~~~~~~~~~~~~~~~~~

    .. code-block:: bash

        mkdir build
        cd build
        cmake ..
        make -j$(nproc)

Verification
~~~~~~~~~~~~~~~~~

Plug pico board to laptop (hold BOOTSEL to enter USB mass storage mode), then invoke command

    .. code-block:: bash

        picotool info

If you install successfully, you will see information about the device.


Command detail
----------------------

make -j$(nproc)
~~~~~~~~~~~~~~~~~

* Meaning

    - **make** → the build program in Linux. It reads the ``Makefile`` to compile the project.  
    - **-jN** → tells ``make`` to run *N jobs in parallel* (compile multiple files at the same time).  
    - **$(nproc)** → a shell command that returns the number of CPU cores on the system.  

* Example

    If your machine has **8 cores**, then ``$(nproc) = 8``.  
    So the command expands to:

        .. code-block:: bash

            make -j8

    This runs **8 parallel build processes**, using all CPU cores to speed up the compilation.

* Comparison


    - ``make`` → only 1 job at a time.  
    - ``make -j4`` → up to 4 jobs in parallel.  
    - ``make -j$(nproc)`` → automatically uses all available CPU cores (fastest).  

* Summary

    ``make -j$(nproc)`` = *compile using as many jobs as CPU cores → maximum build speed*.  