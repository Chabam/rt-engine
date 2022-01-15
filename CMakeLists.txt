# Projects Settings
cmake_minimum_required (VERSION 3.1)
project (rt-engine)

set(SOURCE_DIR              ${CMAKE_SOURCE_DIR}/src)
set(LIB_DIR                 ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/bin)

set(SOURCES
	${SOURCE_DIR}/main.cpp
	${SOURCE_DIR}/engine/engine.cpp
	${SOURCE_DIR}/logger/logger.cpp
	${SOURCE_DIR}/glContext/buffer.cpp
	${SOURCE_DIR}/glContext/shader.cpp
	${SOURCE_DIR}/glContext/window.cpp
	${SOURCE_DIR}/object/color.cpp
	${SOURCE_DIR}/object/mesh.cpp
	${SOURCE_DIR}/object/triangle.cpp
)

set(HEADERS
	${SOURCE_DIR}/config.h
	${SOURCE_DIR}/engine/engine.h
	${SOURCE_DIR}/logger/logger.h
	${SOURCE_DIR}/glContext/buffer.h
	${SOURCE_DIR}/glContext/shader.h
	${SOURCE_DIR}/glContext/window.h
	${SOURCE_DIR}/object/color.h
	${SOURCE_DIR}/object/mesh.h
	${SOURCE_DIR}/object/vertice.h
	${SOURCE_DIR}/object/triangle.h
)

# The main executable
add_executable(${CMAKE_PROJECT_NAME}
  ${HEADERS}
  ${SOURCES}
)

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 17)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall)

# glfw
add_subdirectory(${LIB_DIR}/glfw EXCLUDE_FROM_ALL)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glfw)

# glew
add_definitions(-DGLEW_STATIC)
add_subdirectory(${LIB_DIR}/glew EXCLUDE_FROM_ALL)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE libglew_static)

# glm
add_subdirectory(${LIB_DIR}/glm EXCLUDE_FROM_ALL)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glm)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${SOURCE_DIR})
