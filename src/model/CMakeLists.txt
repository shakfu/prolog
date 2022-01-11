
add_library (model
   STATIC
   vehicle.cpp
)

set_target_properties(model PROPERTIES 
   ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/obj")
