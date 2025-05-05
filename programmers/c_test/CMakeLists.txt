cmake_minimum_required(VERSION 3.10)
project(C_test_C)

file(GLOB BASICS_C_FILES "${CMAKE_CURRENT_LIST_DIR}/*.c")

foreach(EXECUTABLE ${BASICS_C_FILES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME}_c ${EXECUTABLE})
endforeach()
