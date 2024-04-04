# add-two-numbers.s
# Scott F. Kaplan -- sfkaplan@cs.amherst.edu
# Fall 2019
#
# Add two numbers loaded from main memory, then store the
# result back into main memory.

# Code starts here.

.section .text
        
main:

        lui     a0, %hi(x_addr)      # a0 = x_addr
        addi    a0, a0, %lo(x_addr)  #   (performed in two halves)
        lw      t0, 0(a0)            # t0 = *a0 = *x_addr = x

        lui     a1, %hi(y_addr)      # a1 = y_addr
        addi    a1, a1, %lo(y_addr)  #
        lw      t1, 0(a1)            # t1 = *a1 = *y_addr = y
        
        add     t2, t0, t1           # t2 = t0 + t1
        lui     a2, %hi(z_addr)      # a2 = z_addr
        addi    a2, a2, %lo(z_addr)  #
        sw      t2, 0(a2)            # z = *z_addr = *a2 = t2
        jr      ra                   # return
        
        
# Data is specified here.

.section .data
        
x_addr:
        .word 13                     # x = 13
y_addr:
        .word -5                     # y = -5
z_addr:
        .word 0                      # z = 0