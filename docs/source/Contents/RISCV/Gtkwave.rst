Gtkwave
------------------

Introduction
~~~~~~~~~~~~~~~~~

Gtkwave is a viewer for VCD (Value Change Dump) files which are usually created by digital circuit simulators.

Installation
~~~~~~~~~~~~~~~~~~

Ubuntu version 22.04.4

Update apt database with apt-get using the following command.

.. code-block:: bash

    sudo apt-get update

After updating apt database, We can install gtkwave using apt-get by running the following command:

.. code-block:: bash

    sudo apt-get -y install gtkwave


if you have this error ``Failed to load module "canberra-gtk-module"``

The following command will solve the problem

.. code-block:: bash

    sudo apt install libcanberra-gtk-module libcanberra-gtk3-module


.. note::
    
    To run gtkview you must have ``all.vcd`` and ``view.gtkw``
