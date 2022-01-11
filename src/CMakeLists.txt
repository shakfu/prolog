
add_subdirectory(core)
add_subdirectory(model)


# add_library (prolog-lib
#    STATIC
#    core/process.cpp
#    model/vehicle.cpp
# )
# set_target_properties(prolog-lib
#         PROPERTIES OUTPUT_NAME prolog)

# set_target_properties(prolog-lib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/obj")


add_executable(prolog-exe program.cpp)

set_target_properties(prolog-exe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

target_link_libraries(prolog-exe
   PRIVATE
   core
   model
)

# this works too
# target_link_libraries(prolog-exe PRIVATE prolog-lib)


# rename the cmake name of the exec to the project name
set_target_properties(prolog-exe
        PROPERTIES OUTPUT_NAME prolog)

