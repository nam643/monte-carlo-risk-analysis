cmake_minimum_required(VERSION 3.28)

project(
    qrw
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(qrw_warnings INTERFACE)

target_compile_options(
    qrw_warnings
    INTERFACE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Wshadow
)

add_subdirectory(src/core)
add_subdirectory(src/analytics)
add_subdirectory(src/app)
add_subdirectory(src/tests)