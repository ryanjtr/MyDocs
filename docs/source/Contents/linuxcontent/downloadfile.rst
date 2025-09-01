Download File
===============

.. contents:: Tables of Contents
    :depth: 2
    :local:

Download file with aria2c
------------------------------

Installation
~~~~~~~~~~~~~~~~

    .. code-block:: bash

        sudo apt update
        sudo apt install aria2 -y

Download file
~~~~~~~~~~~~~~~~~~

Simple file::

    aria2c https://example.com/file.zip

Change file'name when saving::

    aria2c -o newname.zip https://example.com/file.zip


Add path when saving::

    aria2c -d ~/Downloads https://example.com/file.zip

Speed downloading with multi connection
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    .. code-block:: bash

        aria2c -x 16 -s 16 https://example.com/bigfile.iso

* ``-x 16``: maximum 16 parallel-connection
* ``-s 16``: divide file into 16 pieces for faster downloading

Resume downloading
~~~~~~~~~~~~~~~~~~~~~~~

    .. code-block:: bash

        aria2c -c https://example.com/file.zip

* ``-c``: continue

Download multiple files from a list 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Create file ``list.txt`` with below contents::

    https://example.com/file1.iso
    https://example.com/file2.zip


Then run::

    aria2c -i list.txt

    