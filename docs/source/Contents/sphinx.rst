Phinx
=====
.. contents:: 
    :depth: 2

Tạo sphinx
----------

Build sphinx
------------

.. code-block:: 

    sphinx-build -b html . _build/html
    google-chrome _build/html/index.html


Deploy lên github
-----------------

Thêm extension
-------------------

**1.Copy button**
Cài đặt package

.. code-block:: python

    pip install sphinx-copybutton

Mở file conf.py và thêm extension

.. code-block:: 

    extensions = ['sphinx_copybutton']


