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

Vivado 2023.2 Enterprise (You can check vivado installation instruction in vivado documentation).

.. note::

    If you can't install vivado on your local, go to ``vlsi.doelab.site`` to do all steps below

Following the steps

#. make scripts in folder pulpissimo

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

#. Invoke command:

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

Program device
~~~~~~~~~~~~~~~~~~~~

#. Create a new project in vivado with board genesys2. There's no need to run synthesis or to implement it.

#. On ``Flow Navigator``, look at ``Program and Debug`` then select ``Open target`` to connect to your board (local or remote board).

#. Similarly, select ``Program Device`` to load bitstream file.

Debug with openocd
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#. Add ``192.168.1.177/32`` to AllowIPs in your wiregaurd configuration file

#. Open remmina and connect to site ``192.168.1.177`` with user and password allocated in discord

#. Open terminal and change directory to ``pulpissimo``, then invoke command: 

    .. code-block:: bash

        openocd -f openocd-genesys2.cfg 

    .. image:: ../image/openocdsuccess.png

#. Go to ``uart/send`` example and build (From now, do on local):

    .. code-block:: bash 
        
        cd pulp-runtime-examples/periph/uart/send

        make clean all io=uart

#. Start RISC-V GDB pointing to your ELF binary:

    .. code-block:: bash
        
        riscv32-unknown-elf-gdb build/test/test

#. Then invoke: 

    For remote board 

    .. code-block:: bash
        
        target remote 192.168.1.177:3333

    or 

    .. code-block:: bash

        target extended-remote 192.168.1.177:3333

    For local board: 

    .. code-block:: bash 

        target remote localhost:3333
        
#. Load the binary into PULPissimo's main memory and start execution:

    .. code-block:: bash
        
        load 
        
        continue

#. Open site ``192.168.2.203`` and use hercules to check the UART output for results.

.. tip::

    * ``Ctrl + C`` to stop ``continue`` status

    * ``quit`` to get out of debugging. 

.. |frog| image:: ../image/frog.gif
    :height: 20px
    :width: 24px
    :alt: frog emoji

.. |rainbowfrog| image:: ../image/rainbowfrog.gif
    :height: 20px
    :width: 24px
    :alt: frog emoji

**Congratulations! You have a big codec bug here. Enjoy!** |rainbowfrog| |frog| 


References 
~~~~~~~~~~~~~~~~~~~~~

[1]. PULPissimo_Gen2_Setup_Guide
