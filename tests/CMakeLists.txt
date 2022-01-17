
# see: https://lesleylai.info/en/unit-test-with-cmake/

add_executable(test_suite test_basic.cpp)
target_link_libraries(test_suite
	# Doctest
    SQLiteCpp
    sqlite3
    pthread
    dl
    m
)
add_test(NAME test_basic
         COMMAND test_suite)

set_target_properties(test_suite PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

enable_testing()
