RISC-V
=========

.. toctree::
   :maxdepth: 2

   Introduction
   Code
   Assembly_script
   GVSOC
   Pulp_toolchain_and_sdk
   Gap_toolchain_and_sdk   
   Labcode
   Gtkwave


* Arithmetic là một phần của toán học, tập trung vào các phép tính cơ bản như  cộng, trừ, nhân, chia và các quy tắc liên quan đến chúng.


Số nguyên không dấu và số nguyên có dấu là hai loại số nguyên được biểu diễn và xử lý khác nhau trong lập trình.
x
Số nguyên không dấu (unsigned integers):

Số nguyên không dấu chỉ biểu diễn giá trị không âm (không có dấu).
Ví dụ: 0, 1, 2, 3, ..., 65535 (nếu sử dụng 16 bit).
Trong biểu diễn nhị phân, số nguyên không dấu sẽ không có bit dấu, và tất cả các bit được sử dụng để biểu diễn giá trị số.
Số nguyên có dấu (signed integers):

Số nguyên có dấu có thể biểu diễn cả giá trị âm và giá trị dương.
Ví dụ: -32768, -1, 0, 1, 2, ..., 32767 (nếu sử dụng 16 bit).
Trong biểu diễn nhị phân, số nguyên có dấu sử dụng một bit để biểu diễn dấu (+ hoặc -), và các bit còn lại được sử dụng để biểu diễn giá trị số.
Sự khác biệt chính giữa hai loại số này là cách mà bit đầu tiên (bit dấu) được sử dụng trong biểu diễn nhị phân. Trong số nguyên không dấu, 
bit đầu tiên không có ý nghĩa về dấu, trong khi đó, trong số nguyên có dấu, bit đầu tiên được sử dụng để xác định dấu của số (0 là dương, 1 là âm).


có 32 thanhg ghi 0->31. có tên x0 x1 x2 x3...............
thanh ghi có thể được xác định bởi các aliases: a0,t1,ra,............

Các nhãn biểu tượng được lưu trữ dưới dạng ký hiệu trong bảng ký hiệu và thường được sử dụng để xác định các 
biến toàn cục và các hàm con. Chúng được định nghĩa bằng một định danh theo sau bởi dấu hai chấm (:). Định danh 
tuân theo cú pháp tên biểu tượng, như được định nghĩa trong phần trước. Mã sau chứa hai nhãn biểu tượng: age: và get_age:

1 age: .word 42
2 
3 get_age:
4     la t1, age
5     lw a0, (t1)
6     ret
Trong đoạn mã trên:

age: và get_age: là hai nhãn biểu tượng.
age: là một nhãn được sử dụng để đánh dấu vị trí của một từ trong bộ nhớ chứa giá trị 42.
get_age: là một nhãn được sử dụng để đánh dấu vị trí của một hàm con.

Trong lập trình hợp ngữ, nhãn số được sử dụng để đánh dấu các vị trí trong chương trình. Chúng 
giúp chỉ ra nơi lệnh nhảy hoặc nhãn được định nghĩa. Mỗi nhãn số được đặt bởi một chữ số duy 
nhất theo sau là dấu hai chấm (:). Các nhãn số không được liệt kê trong bảng ký hiệu của tập 
tin thực thi, điều này có nghĩa là chúng không có tác động đến bộ nhớ hoặc tác động đến việc chạy chương trình.

Các tham chiếu đến nhãn số thường được phân biệt bằng hậu tố 'b' hoặc 'f'. 'b' đại diện cho "trước" (before) và 'f' 
đại diện cho "sau" (forward). Những tham chiếu này chỉ ra rằng tham chiếu đến một nhãn số được định nghĩa trước đó hoặc sau tham chiếu đó.

Ví dụ minh họa:

.. code-block:: 

    1:  # Nhãn số 1, đánh dấu đầu của một vòng lặp
        beqz a1, 1f    # Nếu a1 = 0 thì nhảy đến nhãn số 1 sau (1f)
        mul a0, a0, a2 # Thực hiện phép nhân
        addi a1, a1, -1 # Giảm giá trị của a1
        j 1b           # Nhảy đến nhãn số 1 trước (1b) để lặp lại

    1:  # Nhãn số 1, đánh dấu kết thúc của vòng lặp
        ret            # Trở về khỏi hàm

Trong ví dụ trên, có một vòng lặp được đánh dấu bằng nhãn số 1. Lệnh nhảy j 1b nhảy đến nhãn số 1 
trước (được đánh dấu bằng 'b'). Khi vòng lặp kết thúc, lệnh nhảy j 1f nhảy đến nhãn số 1 sau 
(được đánh dấu bằng 'f') để tiếp tục thực hiện các lệnh sau vòng lặp.






