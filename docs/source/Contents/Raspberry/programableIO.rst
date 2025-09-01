
PROGRAMABLE IO
==========================

This manual summarizes the Programmable I/O (PIO) instruction set of the
Raspberry Pi Pico, including MOV, IN, OUT, SET, side-set, PUSH, PULL, JMP,
IRQ, WAIT, DELAY, and program wrapping. The content is organized into sections
with detailed explanations and practical examples.

.. contents:: Table of Contents
   :depth: 3
   :local:

Overview of PIO Architecture
-----------------------------
- **State Machines**: Each PIO block contains 4 independent state machines.
- **Instruction Memory**: Shared by all state machines.
- **Shift Registers**:
  - **OSR (Output Shift Register)**: holds data pulled from TX FIFO, used by OUT.
  - **ISR (Input Shift Register)**: holds data collected by IN, used by PUSH.
- **FIFOs**:
  - **TX FIFO** (CPU/DMA → PIO): data supplied to PIO programs.
  - **RX FIFO** (PIO → CPU/DMA): data sent from PIO back to CPU.
- **Flow**::

      CPU -> TX FIFO -> OSR -> OUT -> GPIO
      CPU <- RX FIFO <- ISR <- IN  <- GPIO

MOV Instruction
---------------
Syntax::

    MOV destination, source

Copies data directly between registers, pins, PC, or shift registers.

- **Destinations**: PINS, X, Y, EXEC, PC, ISR, OSR
- **Sources**: PINS, X, Y, NULL, STATUS, ISR, OSR

Examples::

    MOV X, PINS      ; copy pin state into X
    MOV PINS, Y      ; write register Y to pins
    MOV PC, X        ; jump to address held in X
    MOV EXEC, Y      ; execute instruction held in Y

IN Instruction
--------------
Syntax::

    IN source, count

Shift *count* bits into ISR from a source.

Sources: PINS, X, Y, NULL, STATUS, ISR, OSR.

Example::

    IN PINS, 8       ; shift 8 pin bits into ISR
    PUSH             ; ISR -> RX FIFO -> CPU

OUT Instruction
---------------
Syntax::

    OUT destination, count

Shift *count* bits from OSR into a destination.

Destinations: PINS, X, Y, PC, ISR, OSR, PINDIRS.

Example::

    PULL             ; TX FIFO -> OSR
    OUT PINS, 8      ; shift 8 bits from OSR to pins

SET Instruction
---------------
Syntax::

    SET dest, value

Load an immediate value (0–31) into destination.

Destinations: PINS, X, Y, PINDIRS.

Example::

    SET PINS, 1      ; set output pin high
    SET PINS, 0      ; set output pin low

Side-set
--------

Side-set allows pins to be set in parallel with every instruction without extra
instructions.

Declaration::

    .side_set n [opt] [pindirs]

- **n** = number of side-set bits (0–5)
- **opt** = optional; default 0 if not written
- **pindirs** = MSB bit controls pin direction (0=input, 1=output)

Execution order per instruction:
1. Apply side-set to pins
2. Execute instruction
3. Wait for delay (if any)

Examples::

        **SPI clock + MOSI example**::

            .side_set 1 opt
        bitloop:
            out pins, 1 side 1 [1]   ; send MOSI bit + clock high
            nop        side 0 [1]    ; clock low

        **Blink LED example**::

            .side_set 1
            nop side 1 [9]           ; LED high 10 cycles
            nop side 0 [9]           ; LED low 10 cycles

        **Using pindirs**::

            .side_set 2 pindirs
            nop side 2   ; b10: DIR=1, value=0
            nop side 3   ; b11: DIR=1, value=1
            nop side 0   ; b00: DIR=0, input

PUSH Instruction
----------------
Syntax::

    PUSH [block]

Transfers ISR → RX FIFO. Clears ISR.

- block: waits if FIFO full.

Example::

    IN PINS, 8
    PUSH                ; CPU can now read RX FIFO

PULL Instruction
----------------
Syntax::

    PULL [block]

Transfers TX FIFO → OSR.

- block: waits if FIFO empty.

Example::

    PULL
    OUT PINS, 8         ; send data from CPU to pins

Explanation of PUSH/PULL
^^^^^^^^^^^^^^^^^^^^^^^^
- **PULL** goes TX FIFO → OSR → OUT → GPIO (output path).  
- **PUSH** goes IN → ISR → RX FIFO → CPU (input path).

JMP Instruction
---------------
Syntax::

    JMP condition, target

Conditions:
- Unconditional
- !X, !Y (jump if X/Y == 0)
- X--, Y-- (decrement, jump if result >= 0)
- X!=Y
- PIN (jump if pin is 1)
- !OSRE (jump if OSR empty)

Examples::

        set x, 4
    loop:
        jmp x-- loop         ; loop until x < 0

        jmp !x done          ; jump if X==0

        jmp pin got_high     ; jump if pin is high

WAIT Instruction
----------------
Syntax::

    WAIT polarity source index

- polarity: 0=wait for low, 1=wait for high
- source: pin, irq, tx

Examples::

    wait 0 pin 0         ; wait for GPIO0=0 (UART start)
    wait 1 irq 0         ; wait for IRQ0 set
    wait 1 tx            ; wait until TX FIFO has data

IRQ Instruction
---------------
Syntax::

    IRQ set n
    IRQ clear n
    IRQ wait n

- Each PIO block has 8 IRQ flags.
- Used for signalling CPU or other SMs.

Examples::

    irq set 0            ; notify CPU
    irq wait 1           ; wait until CPU sets IRQ1

DELAY Field
-----------
Each instruction can specify a delay [N] (0–31).

Execution time = 1 (instruction) + N (delay).

Examples::

    nop [5]              ; nop but hold 6 cycles

Used with side-set for timing::

    nop side 1 [9]       ; LED high 10 cycles
    nop side 0 [9]       ; LED low 10 cycles

Program Wrapping
----------------
Wrap defines auto-loop region of code.

Directives::

    .wrap_target
       ... code ...
    .wrap

- When execution reaches .wrap, PC automatically jumps back to .wrap_target.
- If no wrap is defined, program halts at end unless JMP is used.

Example::

    .program blink
    .side_set 1
    .wrap_target
        nop side 1 [9]
        nop side 0 [9]
    .wrap

This loops automatically without a manual JMP.

Summary
-------

- **MOV**: Copy between registers/pins/PC/EXEC.  
- **IN**: Collect bits into ISR.  
- **OUT**: Send bits from OSR.  
- **SET**: Load immediate into dest.  
- **Side-set**: Parallel pin updates.  
- **PUSH**: ISR → RX FIFO → CPU.  
- **PULL**: TX FIFO → OSR.  
- **JMP**: Conditional/unconditional jumps.  
- **WAIT**: Pause until pin/irq/tx condition.  
- **IRQ**: Raise, clear, or wait for interrupt flags.  
- **DELAY**: Per-instruction extra cycles.  
- **WRAP**: Define auto-loop section.

Together these make PIO a tiny but powerful state machine controller for bit-banging protocols, signal generation, and precise I/O timing.