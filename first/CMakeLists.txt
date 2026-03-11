cmake_minimum_required (VERSION 3.2)

project (first)

set(   SRC_LIST
        ./main.cpp
        ./testFunc.cpp
)


add_executable(main ${SRC_LIST})