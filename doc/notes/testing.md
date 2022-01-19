# Testing Variations with cmake and doctest

## doctest (standard)


One executable



```cmake
enable_testing()

set(test_suite 
    test_main.cpp
    test_basic.cpp
    test_model.cpp
)

add_executable(test_library ${test_suite})

target_link_libraries(test_library
    model
	# Doctest
    SQLiteCpp
    sqlite3
    pthread
    dl
    m
)

add_test(NAME test_library
         COMMAND test_library)


set_target_properties(test_library PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

```




## doctest - one main multiple tests

- [example](https://github.com/a4z/cmaketestblogexample1)

```cmake
cmake_minimum_required(VERSION 3.0)
project (testexample) 

enable_testing()

add_library(test_main OBJECT test_main.cpp)

add_executable(test1 test1.cpp $<TARGET_OBJECTS:test_main>)
add_test(NAME test1 COMMAND test1)

add_executable(test2 test2.cpp $<TARGET_OBJECTS:test_main>)
add_test(NAME test2 COMMAND test2 )
```

where `test_main.cpp` is defined as 


```cpp
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int main(int argc, char** argv) {
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    return context.run(); 
} 
```

and `test1.cpp` and `test2.cpp` are doctests.


## ctest without doctest

- [unit-test-with-cmake](https://lesleylai.info/en/unit-test-with-cmake/)
- [testing-with-cmake-and-ctest](https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html)

```cmake
create_test_sourcelist (test_suite 
    # test driver
    test_driver.cpp

    # tests
    test_basic.cpp
    test_model.cpp
)


add_executable(test_driver ${test_suite})

target_link_libraries(test_driver
    model
	# Doctest
    SQLiteCpp
    sqlite3
    pthread
    dl
    m
)

# remove the test driver source file
set(tests_to_run ${test_suite})
remove(tests_to_run test_driver.cpp)

# Add all the ADD_TEST for each test
foreach (test ${tests_to_run})
    get_filename_component (TName ${test} NAME_WE)
    add_test (NAME ${TName} COMMAND test_driver ${TName})
endforeach ()

set_target_properties(test_driver PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")


enable_testing()

```
