cmake_minimum_required(VERSION 3.0.0)
project(practice VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
SET (CMAKE_C_COMPILER "/usr/bin/clang")
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")

include(CTest)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(practice main.cpp main.h)

add_executable(practice_test test.cpp main.h)
target_link_libraries(practice_test ${GTEST_LIBRARIES} pthread)
add_test(NAME PracticeTest COMMAND practice_test)

add_executable(practice_fuzzer fuzzer.cpp main.h)
target_compile_options(practice_fuzzer PRIVATE $<$<C_COMPILER_ID:Clang>:-g -O1 -fsanitize=fuzzer>)
target_link_libraries(practice_fuzzer PRIVATE $<$<C_COMPILER_ID:Clang>:-fsanitize=fuzzer>)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
