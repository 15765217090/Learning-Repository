cmake_minimum_required(VERSION 3.10)

project (CMake)

include_directories (testFunc testFunc2)

aux_source_directory (testfunc SRC_LIST)
aux_source_directory (testfunc2 SRC_LIST2)

add_executable (main main.cpp ${SRC_LIST} ${SRC_LIST2})

