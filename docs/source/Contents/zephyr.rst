Zephyr
======

.. contents::
    :depth: 2

.. note:: 

    Once activated your shell will be prefixed with (.venv). The virtual environment can be deactivated at any time by running: deactivate.

Upload code
--------------

If running the code for the first time, you must execute the following command in the terminal

.. code-block:: python

    sudo apt install python3-venv
    python3 -m venv ~/zephyrproject/.venv

Then enter the ``.venv``environment.

.. code-block:: 

    source ~/zephyrproject/.venv/bin/activate

**Upload blinky code to the stm32f401 board**

Connect board with a USB cable, hold the ``BOOT0`` button, and press the ``Reset`` button

.. code-block:: 

    source ~/zephyrproject/.venv/bin/activate
    cd ~/zephyrproject/zephyr
    west build -p always -b stm32f401_mini samples/basic/blinky
    west flash

**Upload blinky code to the stm32f103 board**

Use the ST-Link, if there is an error, press the Reset button and flash again, then flash one more time.

.. code-block::

    source ~/zephyrproject/.venv/bin/activate
    cd ~/zephyrproject/zephyr
    west build -p always -b stm32_min_dev_blue samples/basic/blinky
    west flash

**Upload blinky code to the stm32f407 board**

Blink LED for stm32f407 (LED4 = PD12)

.. code-block::

    source ~/zephyrproject/.venv/bin/activate
    cd ~/zephyrproject/zephyr
    west build -p always -b stm32f4_disco samples/basic/blinky
    west flash


