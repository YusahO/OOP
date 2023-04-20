cmake_minimum_required(VERSION 3.0.0)
project(lab2 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab2 src/main.cpp)
target_include_directories(lab2 PUBLIC include)
