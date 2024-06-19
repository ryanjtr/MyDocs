STM32
======

Assert macro
---------------

``assert_param`` là một macro được sử dụng trong các thư viện chuẩn của 
STM32 để kiểm tra các điều kiện và tham số đầu vào trong các hàm. 
Nó giúp đảm bảo rằng các tham số đầu vào hợp lệ, nếu không hợp lệ 
thì nó sẽ kích hoạt một xử lý lỗi.

Dưới đây là cách sử dụng assert_param trong chương trình STM32:

1. Cấu hình *USE_FULL_ASSERT*
Trước khi sử dụng ``assert_param``, bạn cần chắc chắn rằng *USE_FULL_ASSERT* 
được định nghĩa trong dự án của bạn. Điều này thường được cấu hình trong 
tệp tiêu đề ``stm32fxx_hal_conf.h`` (thay thế xx bằng dòng vi điều khiển của bạn, 
ví dụ: stm32f4xx_hal_conf.h).

Mở tệp stm32fxx_hal_conf.h và đảm bảo rằng dòng #define USE_FULL_ASSERT không bị chú thích:

.. code-block:: c

    #define USE_FULL_ASSERT

2. Khai báo hàm *assert_failed*
Bạn cũng cần cung cấp định nghĩa của hàm ``assert_failed``. Hàm 
này sẽ được gọi khi ``assert_param`` phát hiện ra một lỗi. Thêm 
định nghĩa này vào tệp mã nguồn chính của bạn:

.. code-block:: c

    void assert_failed(uint8_t *file, uint32_t line)
    {
    /* User can add his own implementation to report the HAL error return state */
    printf("Wrong parameters value: file %s on line %d\r\n", file, line);
    // Infinite loop
    while(1)
    {
    }
    }

3. Sử dụng *assert_param*
``assert_param`` được sử dụng để kiểm tra các điều kiện 
trong các hàm của bạn. Ví dụ, nếu bạn có một hàm nhận 
một tham số mà phải nằm trong khoảng từ 0 đến 10, bạn 
có thể sử dụng ``assert_param`` để kiểm tra điều này:

.. code-block:: c

    void MyFunction(int param)
    {
    // Kiểm tra tham số đầu vào phải nằm trong khoảng từ 0 đến 10
    assert_param(param >= 0 && param <= 10);

    // Phần còn lại của hàm
    }

Ví dụ đầy đủ
Dưới đây là một ví dụ đầy đủ về việc sử dụng ``assert_param`` trong một chương trình STM32:

.. code-block:: c

    #include "main.h"
    #include <stdio.h>

    #ifdef USE_FULL_ASSERT
    void assert_failed(uint8_t *file, uint32_t line)
    {
    printf("Wrong parameters value: file %s on line %d\r\n", file, line);
    while(1)
    {
    }
    }
    #endif /* USE_FULL_ASSERT */

    void MyFunction(int param)
    {
    assert_param(param >= 0 && param <= 10);

    // Phần còn lại của hàm
    }

    int main(void)
    {
    // Khởi tạo hệ thống
    HAL_Init();
    SystemClock_Config();

    // Sử dụng hàm với tham số hợp lệ
    MyFunction(5);

    // Sử dụng hàm với tham số không hợp lệ
    MyFunction(15);

    while (1)
    {
    }
    }

Tệp *stm32fxx_hal_conf.h*

.. code-block:: c

    #ifndef __STM32FXX_HAL_CONF_H
    #define __STM32FXX_HAL_CONF_H

    /* ... các định nghĩa và cấu hình khác ... */

    /* Định nghĩa USE_FULL_ASSERT để kích hoạt assert_param */
    #define USE_FULL_ASSERT

    /* ... các định nghĩa và cấu hình khác ... */

    #endif /* __STM32FXX_HAL_CONF_H */

**Tổng kết**

``assert_param`` là một công cụ hữu ích để kiểm tra tính hợp lệ của các tham số trong các hàm của bạn.
*USE_FULL_ASSERT* cần được định nghĩa trong tệp cấu hình để kích hoạt ``assert_param``.
assert_failed là hàm sẽ được gọi khi một điều kiện ``assert_param`` không thỏa mãn, 
và bạn có thể định nghĩa hàm này để thực hiện các hành động xử lý lỗi, như in ra 
thông báo lỗi hoặc dừng chương trình.
Sử dụng ``assert_param`` giúp bạn phát hiện sớm các lỗi liên quan đến tham số và điều 
kiện không hợp lệ trong quá trình phát triển và gỡ lỗi.