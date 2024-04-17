Ubuntu
====================

Unikey installation
------------------------

`Uinikey tutorial <https://tuong.me/huong-dan-cai-dat-bo-go-tieng-viet-cho-ubuntu-ibus-unikey/>`_

Chrome installation
--------------------------

`Chrome tutorial <https://linuxhint.com/install-google-chrome-on-ubuntu-22-04/>`_

Issues
-----------

**Could not get lock /var/lib/dpkg/lock Error on Ubuntu 22.04** 

Solution: Check for Software Updates

Commands
---------------

Remove folder
~~~~~~~~~~~~~~~~

``sudo rm -r -f /path/``

.. code-block:: bash 

    sudo rm -r -f

Uninstall app
~~~~~~~~~~~~~~~~~

Update Ubuntu

.. code-block:: bash

    sudo apt update

List app

.. code-block:: bash

    sudo apt list --installed

Remove app

.. code-block:: bash

    sudo apt-get remove name_app 

To find the exact package name in the system

.. code-block:: bash

    dpkg --list | grep package-name

To remove the package and also its config files 

.. code-block:: bash
    
    sudo apt-get remove --purge package-name

if this didnt work for you . you can remove and purge later in 2 steps

.. code-block:: bash

    sudo apt-get remove package-name

Install .deb package
~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    sudo dpkg -i <pasckage.deb>


