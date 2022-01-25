
enable_testing()

set(test_suite 
    test_main.cpp
    test_basic.cpp
    test_model.cpp
    test_date.cpp
)

add_executable(test_prolog ${test_suite})

target_link_libraries(test_prolog
    model
	# Doctest
    SQLiteCpp
    sqlite3
    pthread
    dl
    m
)

add_test(NAME test_prolog
         COMMAND test_prolog)


set_target_properties(test_prolog PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
