cmake_minimum_required(VERSION 3.4)

project(prolog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY         ${CMAKE_SOURCE_DIR}/build                    )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/release/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/debug/bin  )

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

# create python scripting plugin
find_package(pybind11 REQUIRED)
pybind11_add_module(prolog src/scripting.cpp)
target_link_libraries(prolog
   PRIVATE
   core
   model
)

# this works too
# target_link_libraries(prolog PRIVATE prolog-lib)