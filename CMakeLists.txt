cmake_minimum_required(VERSION 3.25)
project(deps)

set(CMAKE_CXX_STANDARD 17)

add_executable(deps unittest.c hashtable.c)
