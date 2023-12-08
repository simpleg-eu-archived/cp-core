cmake_minimum_required(VERSION 3.27)

project(cp-core)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

if (CP_CORE_TEST)
    add_subdirectory(tests)
endif ()