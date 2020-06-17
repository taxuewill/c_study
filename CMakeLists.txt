cmake_minimum_required(VERSION 3.5)

project(c_study C)

find_package (Threads)


add_executable(test1 src/pthread/test1.c)
target_link_libraries (test1 ${CMAKE_THREAD_LIBS_INIT})