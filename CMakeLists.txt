cmake_minimum_required(VERSION 3.10)
project(AVL)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCE_FILES
    src/main.cpp
    src/Window.cpp
    src/TreeDraw.cpp
)

set(HEADER_FILES
    include/AVL.h
    include/Node.h
    include/Window.h
    include/TreeDraw.h
)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
link_directories(${OPENGL_LIBRARY_DIRS} ${GLFW_LIBRARY_DIRS} ${GLUT_LIBRARY_DIRS})

add_compile_options(-g)
add_definitions(${OPENGL_DEFINITIONS} ${GLUT_DEFINITIONS})

add_executable(AVL ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(AVL ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} -lGL -lGLU -lglut glfw)
