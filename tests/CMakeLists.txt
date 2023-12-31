cmake_minimum_required(VERSION 3.27)

project(cp-core-tests)

set(CP_CORE_SECRETS_MODULE ON)

include(FetchContent)

# GoogleTest
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571 #v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Secrets module

add_subdirectory(../src/secrets ./secrets_module)

add_executable(cp-core-test ResultTest.cpp
        ErrorTest.cpp
        secrets/BitwardenSecretsManagerTest.cpp
        secrets/BitwardenSecretsManagerTest.h)

target_link_libraries(cp-core-test GTest::gtest_main cp-core-impl cp-core-secrets)
target_include_directories(cp-core-test PRIVATE ${CMAKE_SOURCE_DIR}/src)

include(GoogleTest)
gtest_discover_tests(cp-core-test)