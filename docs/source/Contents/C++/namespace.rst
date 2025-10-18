Namespace
===========

.. contents:: Table of Contents
    :depth: 2
    
Use entire std namespace
---------------------------

.. code-block:: c++

    #include <iostream>

    using namespace std;

    int main()
    {
        cout << "hello world";
        return 0;
    }


Use only what you need
--------------------------


.. code-block:: c++

    #include <iostream>

    using std::cout;
    using std::cin;
    int main()
    {
        int number;
        cout << "Enter a number: ";
        cin >> number;
        cout << "Your number is " << number << std::endl;
        return 0;
    }
         