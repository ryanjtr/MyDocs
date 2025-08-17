Activation Script
=================

**Activation Script** is a script used to activate Windows and Office via methods such as HWID, Ohook, KMS38, and Online KMS.  
It focuses on open-source implementation and has fewer detections by antivirus software.  
This activation script serves as a replacement for older tools such as:

- W10 Digital License Activation
- W10 LTSB 2015 Digital License Activation
- Online KMS Activation Script
- KMS38 Activation

Features
--------

- **HWID (Digital License)** – Permanently activates Windows.
- **Ohook** – Permanently activates Office.
- **KMS38** – Activates Windows/Server until the year 2038.
- **Online KMS** – Activates Windows/Server/Office for 180 days (with auto-renew option).
- Change Windows edition.
- Check activation status of Windows/Office.

How to Use
----------

1. Open **PowerShell** with *Run as Administrator*.
2. Paste the following command:

   .. code-block:: powershell

      irm https://get.activated.win | iex

Options
-------

- [1] – Activate Windows 10 or Windows 11 with digital license.
- [2] – Permanently activate Office via Ohook.
- [3] – Activate Windows 10, Windows 11, and Windows Server using KMS38.
- [4] – Activate Windows and Office via Online KMS.
- [5] – Check the activation status of Windows and Office.
