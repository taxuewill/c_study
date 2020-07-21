cmake_minimum_required(VERSION 3.5)

project(c_study C)

set(CMAKE_BUILD_TYPE "Debug")

find_package (Threads)

#[[
add_executable(test1 src/pthread/test1.c)
target_link_libraries (test1 ${CMAKE_THREAD_LIBS_INIT})
]]
add_executable(enum_test src/basic/enum_test.c)

add_executable(open_device src/basic/open_device.c)

add_executable(bool_test src/basic/bool_test.c)
add_executable(struct_aligned src/basic/struct_aligned.c)

add_executable(rbtree_test 
    src/rbtree/rbtree_ts.c
    src/rbtree/rbtree.c
)

add_executable(malloc   src/basic/malloc.c)
add_executable(container_of   src/basic/container_of.c)