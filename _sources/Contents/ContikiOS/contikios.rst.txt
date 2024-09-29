ContikiOS
==================

.. contents:: 
    :depth: 2


Mobility Plugin
------------------

Installation
~~~~~~~~~~~~~~~~~

You can download mobility plugin from this `URL <https://sourceforge.net/p/contikiprojects/code/HEAD/tree/sics.se/mobility/>`_

Open your terminal and invoke command below to create ``mobility`` directory.

.. code-block:: bash

    cd contiki/tools/cooja/apps

    mkdir mobility

Download all file from above URL and move them to ``mobility`` directory.


Buid plugin
~~~~~~~~~~~~~

Navigate to ``mobility`` directory

.. code-block:: bash

    cd contiki/tools/apps/mobility

    sudo ant jar

Enable plugin in Cooja
~~~~~~~~~~~~~~~~~~~~~~~~~~

Start Cooja

.. code-block:: bash

    cd contiki/cooja

    sudo ant run

Then go to ``Setting`` and ``External tools paths``

Find field ``DEFAULT_PROJECTDIRS``. This field is used to add path of downloaded plugin.

Go to the end of this field and add ``;``, then add your ``mobility`` path to it like this

    [APPS_DIR]/mrm;[APPS_DIR]/mspsim;[APPS_DIR]/avrora;[APPS_DIR]/serial_socket;[APPS_DIR]/collect-view;[APPS_DIR]/powertracker;[APPS_DIR]/mobility

Then close and reopen Cooja again. Go to ``Settings`` and ``Cooja Extensions``. Find your mobility path, click it and click ``Apply for session``.

Now go to ``Tools`` and you can find ``mobility`` plugin in it.