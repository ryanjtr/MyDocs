Wiregaurd
----------------

Installation
~~~~~~~~~~~~~~~~~

This installation for Ubuntu

.. code-block:: bash

    sudo apt install wireguard

    sudo apt install openresolv

``lab209_riscv`` is a config file

Use ``sudo cp -r`` command to copy ``lab209_riscv.conf`` to ``/etc/wiregaurd`` 

To **open** wiregaurd use the command below

.. code-block:: bash

    wg-quick up lab209_riscv

To **quit** wiregaurd use the command below

.. code-block:: bash

    wg-quick down lab209_riscv

.. note:: 

    If you get error ``cp: failed to access '/etc/wiregaurd/': Not a directory``. Just add ``.conf`` like this ``lab209_riscv.conf``.

.. tip:: 

    * If you cannot connect to server, change ``AllowedIPs = 192.168.1.178/32``, then restart wiregaurd. Change domain ``vlsi.doelab.site`` to ``192.168.1.178``

    * If you want to go to wiregaurd config file, invoke command ``sudo -i``, then you have this ``root@your-computer:~#``. After that ``cd /etc/``, then ``nano wiregaurd``

Uninstallation wiregaurd
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    sudo apt remove wireguard
    
    sudo apt autoclean && sudo apt autoremove

Remmina
~~~~~~~~~~~~~~~~~

Ubuntu version

.. code-block:: bash

    sudo apt-add-repository ppa:remmina-ppa-team/remmina-next

    sudo apt install remmina remmina-plugin-rdp remmina-plugin-secret

References
~~~~~~~~~~~~~~

`[1]. Wiregaurd <https://www.wireguard.com/quickstart/>`_

`[2]. Remmina installation <https://remmina.org/how-to-install-remmina/>`_