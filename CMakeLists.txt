cmake_minimum_required(VERSION 3.15)

project(CipheFile LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(programa
    src/main.cpp
    src/core/FileManager.cpp
)

target_include_directories(programa
    PRIVATE src
)
