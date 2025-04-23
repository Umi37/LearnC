cmake_minimum_required(VERSION 3.10)
project(Basics_CPP)

# 이 디렉토리 안에 있는 .cpp 파일 전부 찾아서 각각 실행파일 생성
file(GLOB BASICS_CPP_FILES "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

foreach(EXECUTABLE ${BASICS_CPP_FILES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME}_cpp ${EXECUTABLE})
    set_target_properties(${EXE_NAME}_cpp PROPERTIES LINKER_LANGUAGE CXX)
endforeach()
