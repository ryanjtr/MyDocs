Internet
============

.. contents::
    :depth: 2

Lệnh
-----

``ping google.com`` kiểm tra kết nối mạng tới google
``Ctrl C`` ngắt lệnh đang chạy
``nslookup google.com`` tìm địa chỉ ip tên miền

Cài mininet
------------

1. Kiểm tra internet
~~~~~~~~~~~~~~~~~~~~~

.. code-block:: 

    ping google.com

2. Cài đặt mininet
~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: 

    sudo apt update
    sudo apt install mininet

3. Cài đặt xterm
~~~~~~~~~~~~~~~~~

.. code-block:: 

    sudo apt install xterm

4. Cài đặt Wireshark 
~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: 

    sudo apt install wireshark

5. Cài đặt gói python-tk
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: 

    sudo apt install python-tk

6. Sao chép thư mục chứa các ví dụ của Mininet ra thư mục cá nhân người dùng 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Để kiểm tra xem Mininet đã được cài đặt ở đâu trên hệ thống của bạn và xác định phiên bản Python mà nó sử dụng, bạn có thể thử  lệnh sau:

.. code-block:: 

    dpkg -L mininet

Sau đó chép thư mục mininet

.. code-block:: 

    sudo cp -r /usr/lib/python3/dist-packages/mininet ~

7. Thực thi MiniEdit
~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: 

    sudo python3 ./mininet/examples/miniedit.py


Cách sử  dụng mininet
---------------------------

