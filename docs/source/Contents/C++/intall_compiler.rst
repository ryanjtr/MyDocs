Install compiler
=======================

.. contents:: Table of Contents
    :depth: 2
    
GCC compiler for Ubuntu
---------------------------

.. code-block:: bash

    sudo apt update
    sudo apt install -y build-essential   # g++, gcc, make, libc headers
    g++ --version

Install gdb
-------------

.. code-block:: bash

    sudo apt update
    sudo apt install -y build-essential gdb

Install vscode extensions
----------------------------

* C/C++ (ms-vscode.cpptools)

* CMake Tools (ms-vscode.cmake-tools)


Run and debug simple file
-----------------------------

#. Create a file and build symbol debug

File name: ``hello.cpp``

    .. code-block:: c++

        #include <iostream>
        int main(int argc, char** argv) {
            std::cout << "argc=" << argc << "\n";
            for (int i=0;i<argc;i++) std::cout << i << ": " << argv[i] << "\n";
            return 0; // đặt breakpoint ở đây
        }

Compile the file .cpp

    .. code-block:: bash

        g++ -std=gnu++17 -O0 -g hello.cpp -o hello

#. Create debug configuration (launch.json)


VS Code → Run and Debug (Ctrl+Shift+D) → “create a launch.json” → Select C++ (GDB/LLDB).

Sample configuration:

    .. code-block:: bash

        {
        "version": "0.2.0",
        "configurations": [
            {
            "name": "Debug hello (gdb)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/hello",
            "args": ["arg1", "arg2"],           // tham số dòng lệnh
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/bin/gdb",
            "setupCommands": [
                { "text": "-enable-pretty-printing" }  // in đẹp std::vector, string...
            ]
            }
        ]
        }

Run: set breakpoint and press F5


Project using CMake
--------------------------


#. Create CMakeLists file

File name: ``CMakeLists.txt``

    .. code-block:: bash

        cmake_minimum_required(VERSION 3.16)
        project(demo LANGUAGES CXX)

        set(CMAKE_CXX_STANDARD 17)
        set(CMAKE_CXX_STANDARD_REQUIRED ON)
        set(CMAKE_CXX_EXTENSIONS OFF)

        set(CMAKE_BUILD_TYPE Debug)                # -g, -O0
        set(CMAKE_EXPORT_COMPILE_COMMANDS ON)      # VS Code IntelliSense

        add_executable(demo main.cpp)

        target_compile_options(demo PRIVATE -Wall -Wextra -Wpedantic)


Then invoke commands:

    .. code-block:: bash

        mkdir build && cd build
        cmake ..
        cmake --build .

#. Debug in vscode

* Select CMake Tools status bar → Select kit → GCC. (Select GCC of linux when using Ubuntu)

* Select preset Debug → Build.

* Create ``launch.json`` file then you don't need to care about debugging script.

File name: ``.vscode/launch.json``

    .. code-block:: bash

        {
        "version": "0.2.0",
        "configurations": [
            {
            "name": "CMake: Debug current target",
            "type": "cppdbg",
            "request": "launch",
            "program": "${command:cmake.launchTargetPath}",
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/bin/gdb",
            "stopAtEntry": false,
            "setupCommands": [{ "text": "-enable-pretty-printing" }]
            }
        ]
        }

* Invoke command ``Ctrl + Shift + D`` to open debug tab and select ``Cmake: Debug current target``
        





        


