cmake_minimum_required(VERSION 3.27)

project(cp-core-impl)

add_library(cp-core-impl STATIC Result.h
        Result.cpp
        Empty.h
        Error.h)

set_target_properties(cp-core-impl PROPERTIES LINKER_LANGUAGE CXX)

if (CP_CORE_SECRETS_MODULE)
    message("Building SECRETS module")
    add_subdirectory(secrets)
    target_link_libraries(cp-core-impl cp-core-secrets)
    set(CP_CORE_SECRETS_ENABLED ON)
endif ()