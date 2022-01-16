# ----------------------------------------------------------------------------
# consolidated static library

add_library(prolog-lib)
set_target_properties(prolog-lib PROPERTIES OUTPUT_NAME prolog)
set_target_properties(prolog-lib PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/obj")

# ----------------------------------------------------------------------------
# directory dependencies

add_subdirectory(core)
add_subdirectory(model)
add_subdirectory(db)

# ----------------------------------------------------------------------------
# program executable

add_executable(prolog-exe program.cpp)

set_target_properties(prolog-exe PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# target_include_directories(prolog-exe
#     PRIVATE
#         /usr/local/opt/openssl@1.1/include
# )

# target_link_directories(prolog-exe
#     PRIVATE
#         /usr/local/opt/openssl@1.1/lib
# )

target_link_libraries(prolog-exe
    PRIVATE
        core
        model
        db
    PUBLIC
        SQLiteCpp
        sqlite3
        pthread
        dl
        lua
        m
        cpp-terminal
        workflow
        ssl
        crypto
        "-framework WebKit"
)

# this works too
# target_link_libraries(prolog-exe PRIVATE prolog-lib)


# rename the cmake name of the exec to the project name
set_target_properties(prolog-exe PROPERTIES OUTPUT_NAME prolog)


# ----------------------------------------------------------------------------
# python scripting plugin

find_package(pybind11 REQUIRED)
pybind11_add_module(prolog scripting_py.cpp)
target_link_libraries(prolog
    PRIVATE
    core
    model
)

# this works too
# target_link_libraries(prolog PRIVATE prolog-lib)

set_target_properties(prolog PROPERTIES 
   LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# ----------------------------------------------------------------------------
# lua scripting plugin

add_library(lua_prolog MODULE scripting_lua.cpp)
target_compile_options(lua_prolog PRIVATE
    -fPIC)
target_link_libraries(lua_prolog
    PRIVATE
    core
    model
    PUBLIC
    lua
    m
)

# this works too
# target_link_libraries(prolog PRIVATE prolog-lib)

set_target_properties(lua_prolog PROPERTIES 
   LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

set_target_properties(lua_prolog PROPERTIES 
   LIBRARY_OUTPUT_NAME prolog)

set_target_properties(lua_prolog PROPERTIES
    PREFIX "")

# set_target_properties(lua_prolog PROPERTIES OUTPUT_NAME prolog)

