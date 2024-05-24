Pulpissimo
--------------------

Installation
~~~~~~~~~~~~~~~~~~~~~~~

`Installation tutorial <https://singularitykchen.github.io/blog/2020/12/20/Tutorial-Configure-and-Run-Pulpissimo/>`_


Error may appear:

**Numpy error**

.. code-block:: bash
    
    /home/*.*/.local/lib/python3.10/site-packages/openpyxl/compat/numbers.py

Solution: Go to file ``numbers.py`` then edit ``numpy.float = float``

**GCC error**

.. code-block:: bash

    ((vp::trace *)(trace_ptr))->fatal(msg);  : GCC version error - select gcc 9

`Solution for gcc <https://gist.github.com/cobaohieu/ded429cb892b46ae9bfd9919a11e593a>`_

.. note:: 
    
    Installing Multiple GCC Versions

    .. code-block:: bash

        sudo apt install gcc-9 g++-9 gcc-10 g++-10 gcc-11 g++-11 -y

Clone example
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Put this example in pulpissimo directory

.. code-block:: bash

    git clone https://github.com/pulp-platform/pulp-runtime-examples.git


Implement code
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Prepare the environments before running any example

.. code-block:: bash

    source ./pulp-runtime/configs/pulpissimo.sh
    source ./env/pulpissimo.sh
    source ./pulp-sdk/configs/pulpissimo.sh 
    source ./pulp-sdk/configs/platform-rtl.sh
    source ./pulp-sdk/pkg/sdk/dev/sourceme.sh
    source ./pulp-sdk/configs/fpgas/pulpissimo/genesys2.sh
    source ./pulp-sdk/sourceme.sh
    source setup/vsim.sh

**Hello example**

.. code-block:: bash

    make clean all run platform=gvsoc # run code on virtual platform

**Uart-send example**

.. code-block:: bash

    make clean all io=uart # build binary file

Generate ``.vcd`` file to see gtkwave

.. code-block:: bash

    make clean all run platform=gvsoc runner_args=--vcd

**Error about runner**

Solution: Open ``vp_runner.py`` in path: ``pulpisisimo/pulp_sdk/pkg/sdk/dev/install/ws/python`` copy the whole commands in `this vp_runner file <https://github.com/pulp-platform/gvsoc/blob/9443305264a2a1507bf000950bed442ad27a9bbb/engine/python/vp_runner.py>`_ and paste to your ``vp_runner.py``.

Generate bitstream
~~~~~~~~~~~~~~~~~~~~~~~~

**Prerequisite**

Vivado 2023.2 Enterprise (You can check vivado installation instruction).

Following these steps below:

#. ``make scripts`` in folder pulpissimo

#. Install Genesys2 board (if haven't done). Open vivado, select ``Window`` then ``Tcl console``. In the console invoke command

    .. code-block:: bash

        xhub::refresh_catalog [xhub::get_xstores xilinx_board_store]

        xhub::install [xhub::get_xitems]

    Then install Genesys2 board by going to ``Tools`` then ``Vivado store``. Search for Genesys2 and install.

#. Add the line below before:

    ``line 9 pulpissimo/fpga/pulpissimo-genesys2/tcl/run.tcl``

    ``line 11 pulpissimo/fpga/pulpissimo-genesys2/tcl/common.tcl``

    ``line  21 pulpissimo/fpga/pulpissimo-genesys2/ips/xilinx_clk_mngr/tcl/run.tcl``

    ``line 16 pulpissimo/fpga/pulpissimo-genesys2/ips/xilinx_slow_clk_mngr/tcl/run.tcl``

    .. code-block:: bash

        set_param board.repoPaths [get_property LOCAL_ROOT_DIR [xhub::get_xstores xilinx_board_store]]

#. Invoke command in folder ``fpga``:

    .. code-block:: bash

        make genesys2

    if you have an error:

    .. code-block:: bash

        ERROR: [Runs 36-527] DCP does not exist: /home/ryan/pulpissimo/fpga/pulpissimo-genesys2/ips/xilinx_slow_clk_mngr/xilinx_slow_clk_mngr.gen/sources_1/ip/xilinx_slow_clk_mngr/xilinx_slow_clk_mngr.dcp

    Then go to ``pulpissimo/fpga/pulpissimo-genesys2/ips/xilinx_clk_mngr`` and invoke commands:

    .. code-block:: bash 

        make clean 

        make all

    .. note:: 

        All similar errors can use the solution above.
    
    
    Then ``make genesys2`` again and wait until it shows error:
    
    .. code-block:: bash
        
        ERROR: [Synth 8-9123] an enum variable may only be assigned the same enum typed variable or one of its values [.../pulpissimo/.bender/git/checkouts/pulp_soc-125142425fefd4e5/rtl/pulp_soc/soc_interconnect.sv:277] at synthesis state.

#. Add line below before line 388 in ``pulpissimo/.bender/git/checkouts/axi-xxx/src/axi_pkg.sv``

    .. code-block:: bash 
        
        MY_CUT        = MuxAw | MuxAr | MuxW,

#. Change line 277 in ``pulpissimo/.bender/git/checkouts/pulp_soc-xxx/rtl/pulp_soc/soc_interconnect.sv`` to

    .. code-block:: bash 
        
        LatencyMode: axi_pkg::MY_CUT, 

#. Run again

    .. code-block:: bash

        make genesys2

#. The bitstream is generated in ``pulpissimo/fpga``

Install Cable Drivers (Linux Only)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`Go to here <https://digilent.com/reference/programmable-logic/guides/install-cable-drivers>`_

Upload bitstream
~~~~~~~~~~~~~~~~~~~~

#. Open Vivado, then go to ``Open Hardware Manager`` and open target.

#. Click ``Program Device`` and select bitstream file.

#. Similarly, select ``Program Device`` to upload bitstream file.

Debug with openocd
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#. Add ``192.168.1.177/32`` to AllowIPs in your wiregaurd configuration file

#. Open remmina and connect to site ``192.168.1.177`` with user and password allocated in discord

#. Open terminal and change directory to ``pulpissimo/fpga/pulpissimo-genesys2/``, then invoke command: 

    .. code-block:: bash

        openocd -f openocd-genesys2.cfg 

    .. image:: ../image/openocdsuccess.png

    if an error appear

    .. code-block:: bash 

        openocd-genesys2.cfg:38: Error: 
        in procedure 'script' 
        at file "embedded:startup.tcl", line 28
        at file "openocd-genesys2.cfg", line 38
    
    Solution: Comment line 38 and rerun

#. Go to ``uart/send`` example of pulpissimo folder and build (From now, do on local machine):

    .. code-block:: bash 
        
        cd pulp-runtime-examples/periph/uart/send

        make clean all io=uart

#. Start RISC-V GDB pointing to your ELF binary:

    .. code-block:: bash
        
        riscv32-unknown-elf-gdb build/test/test

#. Then invoke: 

    For remote board 

    .. code-block:: bash

        target extended-remote 192.168.1.177:3333

    For local board: 

    .. code-block:: bash 

        target remote localhost:3333
        
#. Load the binary into PULPissimo's main memory and start execution:

    .. code-block:: bash
        
        load 
        
        continue

#. Open site ``192.168.2.203`` and use either ``Hercules`` or ``Putty`` to check the UART output for results.

.. |frog| image:: ../image/frog.gif
    :height: 20px
    :width: 24px
    :alt: frog emoji

.. |rainbowfrog| image:: ../image/rainbowfrog.gif
    :height: 20px
    :width: 24px
    :alt: frog emoji

**Congratulations!** |rainbowfrog| |frog| 

.. tip::

    * ``Ctrl + C`` to stop ``continue`` status

    * ``quit`` to get out of debugging. 

Putty installation
~~~~~~~~~~~~~~~~~~~

Active Universe storage on ubuntu system

.. code-block:: bash

    sudo add-apt-repository universe

Install putty

.. code-block:: bash

    sudo apt install putty

Initialize putty

.. code-block:: bash

    putty

Select ``Serial`` to use serial connection. Then set up ``port`` and ``baudrate``. Hit ``open`` to run.

.. note:: 

    If a font error appears, just go to 'Fonts' on the left sidebar in PuTTY and configure your font.


How to find Device Dev Path on Linux
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Open new terminal and invoke commands below

.. code-block:: bash

    for sysdevpath in $(find /sys/bus/usb/devices/usb*/ -name dev); do
    (
        syspath="${sysdevpath%/dev}"
        devname="$(udevadm info -q name -p $syspath)"
        [[ "$devname" == "bus/"* ]] && exit
        eval "$(udevadm info -q property --export -p $syspath)"
        [[ -z "$ID_SERIAL" ]] && exit
        echo "/dev/$devname - $ID_SERIAL"
    )
    done

All dev paths will appear:

.. code-block:: bash

    /dev/ttyACM0 - STMicroelectronics_STM32_STLink_0668FF485157717867163038
    /dev/sda - MBED_microcontroller_0668FF485157717867163038-0:0
    /dev/input/event13 - SONIX_M87_keyboard
    /dev/input/event16 - SONIX_M87_keyboard
    /dev/input/event14 - SONIX_M87_keyboard
    /dev/input/event12 - SONIX_M87_keyboard
    /dev/input/event15 - SONIX_M87_keyboard
    /dev/input/mouse3 - SONIX_M87_keyboard
    /dev/input/event11 - SONIX_M87_keyboard
    /dev/input/event7 - Logitech_USB_Receiver
    /dev/input/mouse2 - Logitech_USB_Receiver
    /dev/video3 - Azurewave_USB2.0_HD_IR_UVC_WebCam_200901010001
    /dev/video2 - Azurewave_USB2.0_HD_IR_UVC_WebCam_200901010001
    /dev/video1 - Azurewave_USB2.0_HD_IR_UVC_WebCam_200901010001
    /dev/video0 - Azurewave_USB2.0_HD_IR_UVC_WebCam_200901010001


References 
~~~~~~~~~~~~~~~~~~~~~

[1]. PULPissimo_Gen2_Setup_Guide
