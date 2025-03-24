ESP32
==============

.. contents:: 
    :depth: 2


Run ``idf.py`` in terminal VScode
------------------------------------

Add ``F:\esp\Espressif\frameworks\esp-idf-v5.4`` to environment path

Then invoke the command below to enter **idf environment**

    .. code-block:: bash

        export.bat

Lost component mdns in ESP-IDF 5.x
----------------------------------------

In ESP-IDF 5.4, the ``mdns`` component is no longer included. Starting 
from ESP-IDF 5.x, some components like ``mdns``, ``mqtt``, and others have 
been separated from the core and are now managed through the ESP 
Component Manager.

To add a dependency for ``mdns``, use the following command:

    .. code-block:: bash

        idf.py add-dependency "mdns^1.0.0"

