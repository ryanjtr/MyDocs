Wiregaurd
----------------

Installation
~~~~~~~~~~~~~~~~~

This installation for Ubuntu

.. code-block:: bash

    sudo apt install wireguard

    sudo apt install openresolv

To **open** wiregaurd use the command below

.. code-block:: bash

    ``wg-quick up lab209_riscv`` to quit wiregaurd

To **quit** wiregaurd use the command below

.. code-block:: bash

    ``wg-quick down lab209_riscv`` to quit wiregaurd

sudo rm -r -f /path/

Remmina
~~~~~~~~~~~~~~~~~

`Remmina installation https://remmina.org/how-to-install-remmina/`_


https://www.wireguard.com/quickstart/

./configure --prefix=/opt/riscv_pulpissimo --with-arch=rv32imfcxpulpv3 --with-abi=ilp32 --enable-multilib

make