CAN
=========

.. contents::
    :depth: 2

Module MCP2515
-------------------

The MCP2515 is a stand-alone CAN (Controller Area Network) controller developed by 
Microchip Technology. It is widely used in automotive and industrial applications for 
communication between microcontrollers or other devices on a CAN bus.

Initialize
~~~~~~~~~~~~~~~


Configuration mode 
~~~~~~~~~~~~~~~~~~~~

Normal mode
~~~~~~~~~~~~~~~

LoopBack mode
~~~~~~~~~~~~~~~

Transmission
~~~~~~~~~~~~~~~

Reception
~~~~~~~~~~~~~~~


Interrupt
~~~~~~~~~~~~~~~

Can interrupt when

#. Transmit request completed

#. Frame is received in RX FIFO0

#. Frame is received in RX FIFO1

#. During CAN status change or Error

.. note:: 

    Four interrupt vectors are dedicated to bxcan


Filter Bank
~~~~~~~~~~~~~~~

Mask mode

.. image:: image/maskmodediagram.png

Ex: Accept frame only if first 3 msbs of the standard identifier are 1s

.. image:: image/maskmode.png

Ex: Accept only Request frames

.. image:: image/maskmodeRequestframe.png

Ex: Accept only Extended id frames

.. image:: image/maskmodeExtendID.png

Ex: Accept all frames

.. image:: image/acceptallframe.png

List/ID mode


    
Ex: Accept fgrame only if standard identifier value exactly = 0x65D or 0x651

.. image:: image/listmode.png









