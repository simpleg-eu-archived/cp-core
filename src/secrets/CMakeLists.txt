cmake_minimum_required(VERSION 3.27)

project(cp-core-secrets)

include(FetchContent)

# JSON
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG bc889afb4c5bf1c0d8ee29ef35eaaf4c8bef8a5d #v.3.11.2
)

FetchContent_MakeAvailable(json)
FetchContent_GetProperties(json)
if (NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR})
endif ()

add_library(cp-core-secrets STATIC ISecretsManager.h
        BitwardenSecretsManager.cpp
        BitwardenSecretsManager.h
        ErrorKind.h)

target_link_libraries(cp-core-secrets PRIVATE nlohmann_json cp-core-impl)
target_include_directories(cp-core-secrets PUBLIC ${json_SOURCE_DIR}/include ../)