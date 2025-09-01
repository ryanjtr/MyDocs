SPI PIO
==============

.. contents:: Table of Contents
    : depth: 3
    :local:


Build spi.pio file
-----------------------

The content in spi.pio file included 



Content pio_spi.c
-----------------------

General
~~~~~~~~~~~~~

* __time_critical_func(...): tell compiler/linker to set this function to  "fast" RAM/flash area, this is good for I/O realtime

* Check FIFO before read/write
    * pio_sm_is_tx_fifo_full(...): avoid writing when TX FIFO is full
    * pio_sm_is_rx_fifo_empty(...): avoid reading when RX FIFO is full

