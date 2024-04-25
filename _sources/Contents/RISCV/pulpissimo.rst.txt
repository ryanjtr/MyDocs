Pulpissimo
--------------------

Install riscv-gnu-toolchain
export toolchain, path to  .bashrc

`1.  watch video WOSH: Understanding and working with PULP <https://youtu.be/27tndT6cBH0?t=8757>`_

`2. Go to this link and invoke command in Building the RTL simulation platform <https://github.com/pulp-platform/pulp/tree/master>`_


other link

https://github.com/hakatu/pulpissimo?tab=readme-ov-file#building-the-rtl-simulation-platform

https://github.com/pulp-platform/pulp-runtime/blob/master/README.md

https://github.com/pulp-platform/pulpissimo?tab=readme-ov-file#building-and-using-the-virtual-platform


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

    make clean all run platform=gvsoc


**Uart-send example**

.. code-block:: bash

    make clean all io=uart

Generate ``.vcd`` file to see gtkwave

.. code-block:: bash

    make clean all run platform=gvsoc runner_args=--vcd

Simulation error

Solution: Open ``vp_runner.py`` in path: ``pulpisisimo/pulp_sdk/pkg/sdk/dev/install/ws/python`` copy command in `this vp_runner file <https://github.com/pulp-platform/gvsoc/blob/9443305264a2a1507bf000950bed442ad27a9bbb/engine/python/vp_runner.py>`_ and paste to your ``vp_runner.py``.



