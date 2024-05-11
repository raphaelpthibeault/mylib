cmake_minimum_required(VERSION 3.28)
project(mylib C CXX)

include_directories(
    src/
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# $ START TESTING

enable_testing()
find_package(GTest REQUIRED)

add_executable(mylib_test
    tests/str_h_tests.cpp
)

target_include_directories(mylib_test PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(mylib_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})

# $ END TESTING

add_executable(mylib
        main.c
)

target_compile_definitions(mylib PRIVATE _GNU_SOURCE)
