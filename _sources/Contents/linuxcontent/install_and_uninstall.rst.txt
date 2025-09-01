Install/Uninstall
====================

.. contents:: 
    :depth: 2

Ubuntu partition
----------------------------

.. note::

    If your hard drive size is less than 60GB, 
    just ignore partitioning and use entire drive to install Ubuntu. 
    
#. EFI System Partition

    This partition is mandatory if your laptop/computer is booting using UEFI instead of Legacy. 
    It is usually allocated 200 MB of space.

    * Mount point: Not required
    * Type: efi
    * Size: 200 MB

#. Swap Partition

    This partition is used when the RAM is insufficient to run applications. 
    Its function is similar to paging in Windows. 
    You should allocate at least as much space for this partition as your RAM.

    * Mount point: Not required
    * Type: swap
    * Size: 8 GB (if RAM is 8 GB)

#. Root Partition

    This is a mandatory partition. It will be mounted at ``/``. 
    I usually allocate 30 GB to it, but you can assign more if you wish.

    * Mount point: /
    * Type: ext4
    * Size: 30 GB

#. Home Partition

    This partition stores personal files. 
    Each user will have a folder here. 
    I create a separate partition for it so that if Ubuntu is reinstalled or upgraded, 
    all user files will be preserved.

    * Mount point: /home
    * Type: ext4
    * Size: 100 GB (can be more if needed for extensive use)

#. Data Partition

    This partition is used to store data shared with Windows. 
    That's why it has the NTFS file system. Later, if I plan to return to Windows, 
    I won't format or delete this partition. Since it uses NTFS, Windows can easily read it.

    * Mount point: Not required
    * Type: ntfs
    * Size: The remaining space on the hard drive


App installation
------------------------

Unikey installation
~~~~~~~~~~~~~~~~~~~~~~~~~

`Uinikey tutorial <https://tuong.me/huong-dan-cai-dat-bo-go-tieng-viet-cho-ubuntu-ibus-unikey/>`_

Chrome installation
~~~~~~~~~~~~~~~~~~~~~~~~

`Chrome tutorial <https://linuxhint.com/install-google-chrome-on-ubuntu-22-04/>`_

Uninstall Ubuntu(UEFI)
---------------------------

`Uninstall tutorial <https://youtu.be/T71OKoph3YU>`_

Commands in tutorial

.. code-block:: bash

    bcdedit /enum all

    Copy indentifier of Ubuntu

    bcdedit /delete {indenifier of Ubuntu}

    cls

    bcdedit /enum all

    diskpart

    list disk

    sel disk 0

    list par

    list vol

    sel vol ( partrition 100 mb+ with formatted as fat32)

    assign letter = (any letter not already in use on the computer`disk)

    exit

    rmdir /S (Capital letter chosen above):\EFI\ubuntu # Z:\EFI\ubuntu

    if prompted y/n --> press y --> Enter

    dir /a (chosen letter above):\EFI

    if  a mount of bytes free appear --> Success

    exit

Issues
-----------

**Could not get lock /var/lib/dpkg/lock Error on Ubuntu 22.04** 

Solution: Check for Software Updates

**what is the "~/.local" and can I delete it?**

``~/.local - or more precisely, ~/.local/share - ``is where XDG-compliant programs store user data (e.g., fonts, mail messages) according to the XDG Base Directory specification.``

The ``~/.local`` folder also contains ``share/Trash``, which is your trash bin. Everything you put in there of course takes up space. I assume this is the most likely cause of disk usage.

Check how much space it takes up with:

.. code-block:: bash

    du -hs ~/.local/share/Trash

If you don't need to keep items in the trash, empty it through your file manager or just delete everything in ``share/Trash`` with:

.. code-block:: bash

    rm -rf ~/.local/share/Trash

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


Minicom
~~~~~~~~~~~~~~~~~~~~~~~

`Minicom documentation <https://help.ubuntu.com/community/Minicom>`_

Uninstall openocd
~~~~~~~~~~~~~~~~~~~~~~~~~~

`Go to here <https://www.thelinuxfaq.com/ubuntu/ubuntu-17-04-zesty-zapus/openocd?type=uninstall>`_


GCC 12 installation
~~~~~~~~~~~~~~~~~~~~~~~~~~~

`Tutorial <https://www.dedicatedcore.com/blog/install-gcc-compiler-ubuntu/>`_