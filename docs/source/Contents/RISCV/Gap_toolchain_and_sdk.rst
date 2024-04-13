Gap Toolchain and SDK
-------------------------------

.. contents:: 
    :depth: 2
    
Gap Toolchain installation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Ubuntu version: 22.04.4

Download precompile toolchain (for ubuntu 20)
Open new terminal to create new directory:

Setup path:

.. code-block:: bash

    nano ~/.profile

Add command below to ``profile``

.. code-block:: bash 

    if [ -d "/opt/riscv_gap" ] ; then
        PATH="/opt/riscv_gap:$PATH"
    fi

.. Note:: 

    This will require a logout / login to take effect

Open new terminal to install toolchain

Clone gap toolchain

.. code-block:: bash

    git clone https://github.com/GreenWaves-Technologies/gap_gnu_toolchain.git

In folder, delete ``README.md`` and ``install.sh``

Change name folder to ``riscv_gap``. Then copy it to ``/opt/``

.. code-block:: bash

    sudo cp -r riscv_gap /opt/

Open ``bashrc`` 

.. code-block:: bash

    nano .bashrc

Add command below to that file

.. code-block:: bash

    export GAP_RISCV_GCC_TOOLCHAIN="/opt/riscv_gap"

Run this code to take effect

.. code-block:: bash

    source .bashrc

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

Build gvsoc 

.. code-block:: bash

    source sourceme.sh

    make gvsoc

When you're asked to enter email in the first time, press ``Enter``.
Then fill out your information

.. code-block:: bash

    Enter your first name: <your name>
    Enter your last name: <your last name>
    Enter your company name: <your school>
    Enter your country: Viet Nam
    Enter your email address: <your school email address>

Then you will receive an email with an ``url``. Copy that url to ``Enter your email url:``

Press arrow down to read the agreements. Then press ``y`` to agree and wait .....

From now then

.. note:: 

    Must select board before run any project

You can either source sourceme.sh in the root sdk folder and then select the right board from the list, or directly source the board config.

.. code-block:: bash

    source sourceme.sh

or 

.. code-block:: bash

    source configs/<the target you want to use>.sh


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


Example
~~~~~~~~~~~~~~~~

Run helloworld  example 

.. code-block:: bash

    cd gap_sdk/examples/gap8/basic/helloworld

    make clean all run platform=gvsoc

.. image:: ./image/gaptesthello.png
    
Issues
~~~~~~~~~~~~~~~~~~`

**make: Nothing to be done for 'all'**
Solution: ``sudo make clean``

References
~~~~~~~~~~~~~~

`[1]. Gap toolchain installation precompile ubuntu 20 <https://github.com/GreenWaves-Technologies/gap_gnu_toolchain>`_

`[2]. Gap sdk installation <https://github.com/GreenWaves-Technologies/gap_sdk>`_

`[3]. Gap8 manual <https://greenwaves-technologies.com/manuals/BUILD/HOME/html/index.html>`_