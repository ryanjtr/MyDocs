STM32
======

FLASH
---------------

If you want to flash your program to a different sector of the flash memory, you need to modify the following files:

* In the files STM32F411VETX_FLASH.ld and STM32F411VETX_RAM.ld, change the ORIGIN and LENGTH values of the FLASH section:

    .. code-block:: c

        FLASH    (rx)    : ORIGIN = 0x8008000,   LENGTH = 224K 

* In the system_stm32f4xx.c file, enable USER_VECT_TAB_ADDRESS, and update FLASH_BASE and VECT_TAB_OFFSET accordingly:

    .. code-block:: C

        #define USER_VECT_TAB_ADDRESS
        #if defined(USER_VECT_TAB_ADDRESS)
        /*!< Uncomment the following line if you need to relocate your vector Table
            in Sram else user remap will be done in Flash. */
        /* #define VECT_TAB_SRAM */

        #if defined(VECT_TAB_SRAM)
        #define VECT_TAB_BASE_ADDRESS   SRAM_BASE       /*!< Vector Table base address field.
                                                            This value must be a multiple of 0x200. */
        #else
        #define VECT_TAB_BASE_ADDRESS   0x8008000      /*!< Vector Table base address field.
                                                            This value must be a multiple of 0x200. */
        #endif /* VECT_TAB_SRAM */
        #if !defined(VECT_TAB_OFFSET)
        #define VECT_TAB_OFFSET         0x8000U     /*!< Vector Table offset field.
                                                            This value must be a multiple of 0x200. */
        #endif /* VECT_TAB_OFFSET */
        #endif /* USER_VECT_TAB_ADDRESS */
