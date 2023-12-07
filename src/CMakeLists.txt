cmake_minimum_required(VERSION 3.27)

project(cp-core-impl)

add_library(cp-core-impl STATIC Result.h
        Result.cpp)

set_target_properties(cp-core-impl PROPERTIES LINKER_LANGUAGE CXX)