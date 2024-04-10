.section .text
            
main:

        # t0 = array length
        lui     a0, %hi(length)
        addi    a0, a0, %lo(length)
        lw      t0, 0(a0)

        # a1 = array base
        lui     a1, %hi(array)
        addi    a1, a1, %lo(array)

        # Loop through the array, storing the max value so far in t1.
        # WRITE THIS LOOP
        lw      t1, 0(a1)          # assumed t1 = max
        li      t3, 1              # index to compare with length
    loop:
        addi    a1, a1, 4          # array address + 4 byte
        lw      t4, 0(a1) 
        # Compare and update max if satisfied
        bge     t1, t4, not_update 
        mv      t1, t4
    not_update:                                                 
        addi    t3, t3, 1
        blt     t3, t0, loop
    exit:
        # Copy the result (the max value) into the result space.
        lui     a2, %hi(result)
        addi    a2, a2, %lo(result)
        sw      t1, 0(a2)

        # End the program by returning from main()
        jr      ra                   # return

# Data is specified here.
.section .data
            
length:
        .word 6   # The length of the array
array:
    .word 3   # The values of the array
    .word 12
    .word 37
    .word 15
    .word 8
    .word 20
result:
    .word 0   # The place to store the result
