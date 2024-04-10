Examples and Explanations
---------------------------------

.. contents:: 
        :depth: 2

Add 2 numbers
~~~~~~~~~~~~~~~

.. code-block:: asm

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


``lui a0, %hi(x_addr)`` Lệnh này nạp 16 bit hàng đầu của địa chỉ của biến ``x_addr`` vào thanh ghi a0.
Trong RISC-V, để truy cập đến một biến trong bộ nhớ, chúng ta cần biết địa chỉ của nó. 
Tuy nhiên, do hạn chế về kích thước của lệnh, chúng ta chỉ có thể lưu trữ một phần của địa chỉ 
trong một lệnh. Để làm điều này, chúng ta sử dụng lệnh lui (Load Upper Immediate), nó nạp giá trị 
ngay sau dấu ``%hi`` vào thanh ghi. Đối với ``%hi(x_addr)``, nó chỉ lấy 16 bit hàng đầu của địa chỉ của biến ``x_addr`` và lưu vào ``a0``.

``addi a0, a0, %lo(x_addr)`` Lệnh này nạp 16 bit còn lại của địa chỉ của biến x_addr vào thanh ghi ``a0``. Lệnh 
``addi`` (Add Immediate) thêm một giá trị cố định vào một thanh ghi. Ở đây, ``%lo(x_addr)`` chỉ lấy 16 bit thấp 
nhất của địa chỉ của biến ``x_addr``, sau đó cộng thêm vào giá trị hiện tại của thanh ghi ``a0``. Kết quả là ``a0`` 
sẽ chứa toàn bộ địa chỉ của biến ``x_addr``.

``lw t0, 0(a0)`` Lệnh này nạp giá trị từ địa chỉ mà ``a0`` trỏ tới vào thanh ghi ``t0``. Trong trường hợp này, 
nó tương đương với việc đọc giá trị của biến ``x_addr`` từ bộ nhớ và lưu vào ``t0``. Điều này giúp chương 
trình có thể sử dụng giá trị của biến ``x_addr`` để thực hiện các phép toán hoặc tính toán khác.

Tương tự cho ``a1`` và ``t1``.

``add t2, t0, t1`` Thực hiện phép cộng của giá trị trong thanh ghi ``t0`` và ``t1``, sau đó kết quả được 
lưu vào thanh ghi ``t2``. Điều này tương đương với việc thực hiện phép tính ``t2 = t0 + t1.``

``lui a2, %hi(z_addr)`` Lệnh này tải 16 bit hàng đầu của địa chỉ của biến ``z_addr`` vào thanh ghi 
``a2``. Lưu ý rằng ``%hi(z_addr)`` chỉ lấy 16 bit hàng đầu của địa chỉ của biến ``z_addr.``

``addi a2, a2, %lo(z_addr)`` Lệnh này tải 16 bit còn lại của địa chỉ của biến ``z_addr`` vào thanh ghi 
``a2``. Lưu ý rằng ``%lo(z_addr)`` chỉ lấy 16 bit thấp nhất của địa chỉ của biến ``z_addr``, sau đó cộng thêm 
vào giá trị hiện tại của thanh ghi ``a2``.

``sw t2, 0(a2)`` Lệnh này lưu giá trị từ thanh ghi t2 vào bộ nhớ. Địa chỉ lưu trữ được xác định bằng 
cách kết hợp giá trị của thanh ghi a2 và một độ dịch chuyển 0 (vì ``0(a2)`` ), tức là giá trị địa chỉ 
mà ``a2 `` trỏ tới. Kết quả của phép cộng ``t2 và z_addr`` được lưu vào ô nhớ này, đó cũng chính là giá trị 
của biến ``z``.

``jr ra`` Lệnh này trả về từ hàm, trở lại địa chỉ được lưu trong thanh ghi ra. Điều này thường được 
sử dụng để kết thúc một hàm.

Find max value
~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: asm

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

        

Decision making
~~~~~~~~~~~~~~~~~~~

``beq reg1, reg2, L1``
means: go to statements labeled L1 if(value in reg1) == (value in reg2), otherwise go to next statement
``beq`` stand for *branch if equal*
Other wise instruction ``bne`` stand for *branch not equal*

``blt`` stand for *branch if less than*
``bge`` stand for *branch if greater than*
And unsigned version ``bltu``, ``bgeu``

``j`` stand for jump. Ex: ``j Label``

.. image:: ../image/ass1.png
.. image:: ../image/ass2.png
.. image:: ../image/ass3.png
.. image:: ../image/ass4.png
.. image:: ../image/ass5.png
.. image:: ../image/ass6.png
