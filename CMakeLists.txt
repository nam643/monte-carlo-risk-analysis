cmake_minimum_required(VERSION 3.28)

project(
    qrw
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/core)
add_subdirectory(src/analytics)
add_subdirectory(src/app)
add_subdirectory(src/tests)