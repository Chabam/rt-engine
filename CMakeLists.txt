# Projects Settings
cmake_minimum_required (VERSION 3.1)
project (rt-engine)

set(SOURCE_DIR              ${CMAKE_SOURCE_DIR}/src)
set(LIB_DIR                 ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/bin)

# The main executable
add_executable(rt-engine
  ${SOURCE_DIR}/main.cpp
)

set_property(TARGET rt-engine PROPERTY CXX_STANDARD 17)
target_compile_options(rt-engine PRIVATE -Wall)

# glfw
add_subdirectory(${LIB_DIR}/glfw EXCLUDE_FROM_ALL)
target_link_libraries(rt-engine PRIVATE glfw)

# glew
add_definitions(-DGLEW_STATIC)
add_subdirectory(${LIB_DIR}/glew EXCLUDE_FROM_ALL)
target_link_libraries(rt-engine PRIVATE libglew_static)

# glm
add_subdirectory(${LIB_DIR}/glm EXCLUDE_FROM_ALL)
target_link_libraries(rt-engine PRIVATE glm)