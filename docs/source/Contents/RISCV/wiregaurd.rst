Wiregaurd
----------------

Installation
~~~~~~~~~~~~~~~~~

This installation for Ubuntu

.. code-block:: bash

    sudo apt install wireguard

    sudo apt install openresolv

``lab209_riscv`` is a config file

To **open** wiregaurd use the command below

.. code-block:: bash

    wg-quick up lab209_riscv

To **quit** wiregaurd use the command below

.. code-block:: bash

    wg-quick down lab209_riscv

Remmina
~~~~~~~~~~~~~~~~~

Ubuntu version

.. code-block:: bash

    sudo apt-add-repository ppa:remmina-ppa-team/remmina-next

    sudo apt install remmina remmina-plugin-rdp remmina-plugin-secret

References
~~~~~~~~~~~~~~

`[1]. Wiregaurd<https://www.wireguard.com/quickstart/>_`

`[2]. Remmina installation https://remmina.org/how-to-install-remmina/`_