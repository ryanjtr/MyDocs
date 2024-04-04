Assembly Language
---------------------------

The .set and .equ diirectives
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Sử dụng ``.set``

.. code-block:: asm

    .set max_value, 42

    truncates_value_to_max:
        li t1, max_value
        ble a0, t1, ok
        mv a0, t1
    ok:
        ret

Sử dụng ``.equ``

.. code-block:: asm

    .equ MAX_SIZE, 100   ; Định nghĩa hằng số MAX_SIZE với giá trị 100

    .section .data
    array: .space MAX_SIZE    ; Sử dụng MAX_SIZE trong việc cấp phát không gian cho mảng

    .section .text
    main:
        li t0, MAX_SIZE    ; Sử dụng MAX_SIZE trong mã lệnh

.. note::
    * Dù cả hai .equ và .set đều được sử dụng để tạo ra các hằng số trong mã hợp ngữ, nhưng chúng có một số điểm khác nhau:

    * Cách đặt giá trị:

        * ``.equ``: Giá trị của hằng số được đặt khi khai báo hằng số và không thay đổi sau đó. Mỗi lần bạn sử dụng .equ để định nghĩa một hằng số, giá trị của nó sẽ được cố định.
        * ``.set``: Có thể sử dụng .set để thay đổi giá trị của một hằng số sau khi nó đã được định nghĩa. Điều này cho phép bạn thay đổi giá trị của một hằng số trong quá trình lập trình nếu cần thiết.
    * Phạm vi:

        * ``.equ``: Hằng số được định nghĩa bằng .equ chỉ có hiệu lực trong phạm vi cụ thể mà nó được định nghĩa, chẳng hạn như trong một tệp mã hợp ngữ.
        * ``.set``: Có thể sử dụng .set để định nghĩa hằng số ở một tệp mã hợp ngữ và sau đó sử dụng lại nó trong các tệp mã hợp ngữ khác. Điều này cho phép chia sẻ hằng số giữa nhiều tệp mã hợp ngữ.
Ví dụ:

.. code-block:: asm

    .equ MAX_SIZE, 100      ; Định nghĩa hằng số MAX_SIZE với giá trị 100

    .set max_value, 42      ; Định nghĩa hằng số max_value với giá trị 42

Trong ví dụ trên, giá trị của MAX_SIZE sẽ luôn là 100, trong khi giá trị của max_value có thể thay đổi trong quá trình lập trình.

Global directive 
~~~~~~~~~~~~~~~~~~~~~~~~

Theo mặc định thì các label được tạo và sử dụng ``.set``, ``.equ`` được lưu trữ trong symbol table như local symbol

Muốn chuyển sang global thì làm như sau

.. code-block:: asm

    .globl max_value
    .globl start

    .set max_value, 42

    start:
        li a0, max_value
        jal process_temp
        ret

The .align directive
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Một số hệ thống máy tính, bao gồm cả những hệ thống tuân theo Kiến trúc Tập lệnh (ISA) RV32I, 
yêu cầu các chỉ thị hoặc dữ liệu đa byte được lưu trữ trên các địa chỉ là bội số của một số cho 
trước. Ví dụ, trong RV32I, các chỉ thị phải được lưu trữ tại các địa chỉ là bội số của bốn.

Tuy nhiên, không phải tất cả các bộ dịch tự động đảm bảo sự căn chỉnh này. Ví dụ, bộ dịch GNU 
không kiểm tra xem các chỉ thị RV32I có được đặt ở địa chỉ đúng không. Vì vậy, nếu bạn dịch mã như sau:

.. code-block:: asm

    .text
    foo:
    j next
    .byte 0xa
    next:
    ret

Bộ dịch sẽ không phản ánh gì, nhưng khi chạy mã này trên một CPU RV32I, nó sẽ thất bại khi thực thi 
chỉ thị ret vì nó yêu cầu các chỉ thị phải bắt đầu từ các địa chỉ là bội số của bốn.

Để đảm bảo căn chỉnh chính xác, các lập trình viên hoặc trình biên dịch cần điều chỉnh bộ đếm vị 
trí thủ công hoặc sử dụng các chỉ thị như ``.align N``. Ví dụ:

.. code-block:: asm

    .text
    foo:
    j next
    .byte 0xa
    .align 2   # Đảm bảo chỉ thị tiếp theo được căn chỉnh với ranh giới 4 byte
    next:
    ret

Ở đây, ``.align 2`` đảm bảo sự căn chỉnh, nhưng việc sử dụng nó thủ công có thể mất thời gian và dễ gây 
lỗi. Tốt hơn hết là để trình biên dịch xử lý điều này bằng cách sử dụng các chỉ thị .``align N``. Các 
chỉ thị này đảm bảo rằng bộ đếm vị trí căn chỉnh đúng mà không cần can thiệp thủ công.

Ví dụ:

.. code-block:: asm

    .text
    .align 2
    func1:
    addi a0, a0, 2
    ret
    .align 2
    func2:
    addi a0, a0, 42
    ret

Ở đây, ``.align 2`` đảm bảo mỗi hàm bắt đầu từ một địa chỉ là bội số của bốn, nhưng nếu bộ đếm vị trí đã được 
căn chỉnh, chỉ thị sẽ không có hiệu lực.

.. note:: 

    Tương tự, dữ liệu đa byte cũng nên được căn chỉnh để có hiệu suất tối ưu. Chỉ thị ``.align N`` có thể được  
    sử dụng cho mục đích này, đảm bảo rằng dữ liệu như giá trị 16-bit, 32-bit hoặc 64-bit được lưu trữ tại 
    các địa chỉ bội số của các giá trị phù hợp (2, 4 hoặc 8 tương ứng).