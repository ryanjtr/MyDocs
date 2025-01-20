Raspberry Pi 
=================

.. contents:: 
    :depth: 2

Install Raspberry Pi OS without monitor or keyboard
-------------------------------------------------------

#. First, visit this `link Raspberry Pi Imager <https://www.raspberrypi.com/software/>`_ to download Raspberry Pi Imager.

#. Insert your microSD card into a card reader and connect it to your computer. Then, launch the Raspberry Pi Imager application.

#. Configure the following settings in the Raspberry Pi Imager:

    * Raspberry Pi Device: Select the device model you are using.
    * Raspberry Pi OS: Select Raspberry Pi OS 64 bit
    * Storage: Select your microSD card.

#. Click Next, then proceed to Edit Settings. In the settings window:

    * General tab:
        * Set a hostname.
        * Configure a username and password.
        * Connect to your Wi-Fi network (make sure the Wi-Fi network matches the one your computer is using).
    * Services tab: Enable SSH.

#. After configuring the settings, click Save and confirm with Yes when prompted. Finally, allow the program to write the operating system to the microSD card.


Boot Raspberry Pi
------------------------

#. Insert the microSD card into the Raspberry Pi board before connecting the power supply.

#. Connect a power source 5V (minimum 3A) to the Raspberry Pi.

#. Observe the green LED on the board. It should start blinking, indicating that the system is booting.


Find Raspberry Pi address and use SSH
----------------------------------------

#. Go to ``User/user_name/.ssh``, remove all file in this folder 
#. Visit this link to download Angry IP Scanner.
#. Install and launch the application.
#. Use it to scan for IP addresses on your network.
#. Look for the hostname that matches the Raspberry Pi username you set earlier. This will help you identify your Raspberry Pi's IP address.

#. Open the terminal (or Command Prompt on Windows).
#. Use the following command to connect to your Raspberry Pi via SSH:

    .. code-block:: bash

        ssh username@ip-address

        Example: ssh Pi@192.168.1.9

#. Then type **Yes** and type your password and terminal change to Pi user

Enable VNC and use VNCTiger
------------------------------

#. When you are logged in as pi@raspberrypi, run the following command to open the Raspberry Pi configuration tool:

    .. code-block:: bash

        sudo raspi-config

#. Configure the settings as follows:

    * Interface Options:
        * Select VNC and press Enter.
        * Choose Yes to enable VNC.
    * System Options:
        * Select Boot/Auto login.
        * Choose Desktop Auto login and press Enter.
#. Navigate to Finish and confirm with Yes to reboot the Raspberry Pi and close terminal.

#. Visit this `link <https://sourceforge.net/projects/tigervnc/>`_ to download TigerVNC.
#. Install and launch the application.
#. Enter the VNC server address (e.g., the IP address of your Raspberry Pi) and proceed.
#. Confirm any prompts with Yes until the VNC authentication window appears.
#. Enter the username and password you set for your Raspberry Pi to connect to the server.

Changing Wi-Fi When in a New Location
-----------------------------------------

#. Create a Wireless Hotspot:

    * Click the Wi-Fi symbol on the top-right of the Raspberry Pi desktop.
    * Select Advanced Options → Create Wireless Hotspot.
    * Enter the following details:
        * Network Name: Provide a name for the hotspot.
        * Wi-Fi Security: Choose WPA & WPA2 Personal.
        * Password: Set a secure password for the hotspot.

#. Connect Your Laptop to the Hotspot:

    * On your laptop, connect to the newly created hotspot.
    * Open TigerVNC and scan for the Raspberry Pi's Wi-Fi IP address.
    * Connect to the Raspberry Pi using the same method as before.

#. Connect to a Hidden Wireless Network:

    * On the Raspberry Pi, click the Wi-Fi symbol again.
    * Select Connect to Hidden Wireless Network.
    * Enter the following details:

        * Network Name: Provide the name of the hidden network.
        * Wi-Fi Security: Choose WPA & WPA2 Personal.
        * Password: Enter the network password.

#. Scan and Connect via TigerVNC:

    * Scan for the Raspberry Pi's IP address again and connect via TigerVNC as before.

#. Repeat as Needed:

    * Repeat this process whenever you move to a new location with a different network.



Command for ubuntu sever terminal
------------------------------------

Shut down command
~~~~~~~~~~~~~~~~~~~~~

* Shut down now
    .. code-block:: bash
        
        sudo shutdown now 

* shut down after 5 minutes

    .. code-block:: bash
        
        sudo shutdown +5 

* shut down at specific time

    .. code-block:: bash

        sudo shutdown 23:00



Reboot Command
~~~~~~~~~~~~~~~~~

    .. code-block:: bash

        sudo reboot

Power off command
~~~~~~~~~~~~~~~~~~~~

    .. code-block:: bash

        sudo poweroff   

Install gpiozero library for ubuntu sever OS
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    sudo apt install python3-gpiozero

Add new Wifi
----------------

#. Check the current network configuration: Ubuntu uses Netplan or wpa_supplicant to manage Wi-Fi, depending on the version. Open the Netplan configuration file (usually located in the /etc/netplan/ directory):

    .. code-block:: bash

        sudo nano /etc/netplan/*.yaml

#. Add a new Wi-Fi network configuration: If you are using Netplan: In the YAML configuration file, you will see a section like the following:

    .. code-block:: bash

        network:
            version: 2
            renderer: networkd
            wifis:
                wlan0:
                access-points:
                    "namchau3":
                    password: "your_password_here"
                    "wifi_moi":
                    password: "password_moi"
                dhcp4: true

#. Save the file (Ctrl + O, Enter) and exit (Ctrl + X).
#. Apply the new configuration:

    .. code-block:: bash

        sudo netplan apply



Display SSID of Wifi
---------------------------

#. Install wireless-tool

    .. code-block:: bash

        sudo apt install wireless-tools

#. Display SSID

    .. code-block:: bash

        iwgetid

Install Visual Studio Code on an Ubuntu Server without a GUI
---------------------------------------------------------------

You can use VS Code Remote Development by connecting to your server via SSH from another machine that has the VS Code GUI. Here's a step-by-step guide:

#. Install Visual Studio Code on Your Personal Computer

#. Install the Remote Development Extension in VS Code

    * Open VS Code on your personal computer
    * Open the Extensions Marketplace (press Ctrl+Shift+X or click the Extensions icon in the sidebar).
    * Search for and install the Remote - SSH extension.
    * After installation, you'll see a ``><`` icon in the sidebar. Click on this icon.

#. Install VS Code Tools on Ubuntu Server via SSH

    * SSH into your Ubuntu Server from your personal computer:

        .. code-block:: bash

            ssh username@your_server_ip
    
    * Install OpenSSH on the server (if it's not already installed) to enable SSH connections:

        .. code-block:: bash

            sudo apt update
            sudo apt install openssh-server


    * Check the SSH service status:

        .. code-block:: bash

            sudo systemctl status ssh

    * Make sure the SSH service is running. If it's not, start it:

        .. code-block:: bash

            sudo systemctl start ssh


#. Use VS Code to Connect to Ubuntu Server via SSH

    * In VS Code on your personal computer, open the Remote Explorer.
    * Click the + button to add a new SSH connection.
    * Enter the Ubuntu server's username and IP address.
    * Provide the password when prompted, or configure the connection with an SSH key.

#. Edit and Work Remotely on the Server

Once connected, you can edit files on the server as if you're working locally. 
VS Code on your personal computer will interact with the files on your Ubuntu Server through SSH, 
while the server doesn't need to have a GUI.

.. note:: 

    * Visual Studio Code runs on your personal computer but interacts with the code and files on the Ubuntu Server.

    * This method allows you to avoid installing a GUI on the server, yet still enjoy the full functionality of VS Code for development and remote work.

Add priority for Wi-Fi networks
-----------------------------------

#. Open the ``wpa_supplicant.conf`` file

    If the ``wpa_supplicant.conf`` file does not exist, you can create it. To edit the file, use the following command:

    .. code-block:: bash

        sudo nano /etc/wpa_supplicant/wpa_supplicant.conf

#. Add Wi-Fi Network Configurations with Priority

    In the ``wpa_supplicant.conf`` file, add the configurations for the Wi-Fi networks, specifying the priority for each network. A lower priority number indicates higher priority.

    Example configuration:

    .. code-block:: bash

        network={
            ssid="namchau3"
            psk="your_password_here"
            priority=1
        }

        network={
            ssid="wifi_moi"
            psk="password_moi"
            priority=2
        }

    In this case:

        * The network namchau3 has a priority of 1 (higher priority).
        * The network wifi_moi has a priority of 2 (lower priority).

#. Save and Exit

#. Apply the Network Configuration

    #. To apply the changes with netplan

        .. code-block:: bash

            sudo netplan apply


    #. Alternatively, restart the wpa_supplicant service:

        .. code-block:: bash

            sudo systemctl restart wpa_supplicant


#. Check the Connection Status

    To verify the Wi-Fi network connection and the priority settings, use the following command:

    .. code-block:: bash

        sudo snap install network-manager

        nmcli device status


Add Hotspot for Raspberry Pi
--------------------------------

#. Use following command to open ``50-cloud-init.yaml``.
#. Edit file like below

    .. code-block:: bash

        network:
            version: 2
            renderer: networkd
            wifis:
                wlan0:
                    access-points:
                        "Nam Chau 3":
                            hidden: true
                            password: "password"
                        "RaspberryPi-Hotspot":
                            mode: ap
                            password: "HotspotPassword"
                    dhcp4: true
                    addresses:
                        - 192.168.4.1/24
                    optional: true

Observe RAM/ROM resources of system
--------------------------------------

#. Use the following command to observe status

    .. code-block:: bash

        htop

    .. image:: image/raspberry/ram_and_rom_resources.png 



