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

target_link_libraries(prolog-exe
    PRIVATE
        core
        model
        db

    PUBLIC
    # sqlite3
        SQLiteCpp
        sqlite3

    # sol2
        pthread
        dl
        lua
        m

    # cpp-terminal
        cpp-terminal

    # workflow
        workflow
        ssl
        crypto

    # webview
        "-framework WebKit"

    # spdlog
        spdlog

    # zmq
        zmq

    # pqxx
        pqxx
        pgcommon
        pgport
        pq

    # cpr
        cpr
        curl-d
        z
        ssh2
        "-framework CoreFoundation"
        "-framework Security"
        "-framework SystemConfiguration"

)


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


set_target_properties(lua_prolog PROPERTIES 
   LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

set_target_properties(lua_prolog PROPERTIES 
   LIBRARY_OUTPUT_NAME prolog)

set_target_properties(lua_prolog PROPERTIES
    PREFIX "")

