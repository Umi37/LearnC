cmake_minimum_required(VERSION 3.10)
project(C_Test)

file(GLOB C_TEST_FILES "${CMAKE_CURRENT_LIST_DIR}/*.c")

foreach(EXECUTABLE ${C_TEST_FILES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME}_c ${EXECUTABLE})
endforeach()
