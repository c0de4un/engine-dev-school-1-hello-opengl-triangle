# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set(CMAKE_VERSION 3.22)
cmake_minimum_required(VERSION ${CMAKE_VERSION})

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROEJCT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

project("Hello OpenGL" VERSION 0.1.0)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set(SOURCES_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(SOURCES
  "${SOURCES_DIR}/main.cpp"
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Add Executable Object
add_executable(app ${SOURCES})

# Configure Executable Object
set_target_properties(app PROPERTIES
  RUNTIME_OUTPUT_NAME "Hello_OpenGL_v${PROJECT_VERSION}"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin"
)

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
