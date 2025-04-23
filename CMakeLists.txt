cmake_minimum_required(VERSION 3.10)
project(LearnC_Project)

# C & C++ 공통 설정
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

# 하위 디렉토리 추가
add_subdirectory(c_language)
add_subdirectory(cpp_language)
