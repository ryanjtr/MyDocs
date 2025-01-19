Raspberry Pi 
=================

.. contents:: 
    :depth: 2

Install Raspberry Pi OS without monitor or keyboard
-------------------------------------------------------

#. First, visit this `link <https://www.raspberrypi.com/software/>`_ to download Raspberry Pi Imager.

#. Insert your microSD card into a card reader and connect it to your computer. Then, launch the Raspberry Pi Imager application.

#. Configure the following settings in the Raspberry Pi Imager:

    * Raspberry Pi Device: Select the device model you are using.
    * Raspberry Pi Device: Select the device model you are using.
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

#. Visit this link to download TigerVNC.
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
    * Open TigerVNC and scan for the Raspberry Pi’s Wi-Fi IP address.
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




