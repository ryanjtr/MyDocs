Zephyr
======

.. contents::
    :depth: 2

.. note:: 

    Once activated your shell will be prefixed with (.venv). The virtual environment can be deactivated at any time by running: deactivate.

Nạp code
--------

Nếu lần đầu chạy code phải chạy lệnh sau trên terminal

.. code-block:: python

    sudo apt install python3-venv
    python3 -m venv ~/zephyrproject/.venv

Sau đó vô môi trường .venv

.. code-block:: 

    source ~/zephyrproject/.venv/bin/activate

**Nạp blinky code cho board stm32f401**

Sử dụng cáp USB, giữ nút ``BOOT0`` và nhấn nút ``Reset``

.. code-block:: 

    source ~/zephyrproject/.venv/bin/activate
    cd ~/zephyrproject/zephyr
    west build -p always -b stm32f401_mini samples/basic/blinky
    west flash

**Nạp blinky code cho board stm32f103**

Sử dụng st-link, nếu lỗi thì nhấn nút ``Reset`` và flash lại, sau đó flash lại 1 lần nữa.

.. code-block::

    source ~/zephyrproject/.venv/bin/activate
    cd ~/zephyrproject/zephyr
    west build -p always -b stm32_min_dev_blue samples/basic/blinky
    west flash

**Nạp blinky code cho board stm32f407**

Blink LED for stm32f407 (LED4 = PD12)

.. code-block::

    source ~/zephyrproject/.venv/bin/activate
    cd ~/zephyrproject/zephyr
    west build -p always -b stm32f4_disco samples/basic/blinky
    west flash


