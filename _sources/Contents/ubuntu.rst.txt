Ubuntu
====================


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

