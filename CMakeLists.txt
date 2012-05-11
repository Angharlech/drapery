
cmake_minimum_required(VERSION 2.6)

project(openGLDemo) 
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeScripts)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE release)

set(CMAKE_VERBOSE_MAKEFILE off)

find_package ( SDL REQUIRED )
find_package(Boost COMPONENTS filesystem REQUIRED)
find_package(Eigen3)
find_package(OpenGL)

include_directories( ${EIGEN3_INCLUDE_DIR}
                     ${SDL_INCLUDE_DIR} 
                     ${OPENGL_INCLUDE_DIR}
                     ${Boost_INCLUDE_DIR})

file(GLOB DEMO_SOURCE_FILES "*.cpp")
add_executable(demo ${DEMO_SOURCE_FILES})


target_link_libraries(demo ${SDL_LIBRARY} 
                           SDLmain 
                           ${OPENGL_LIBRARIES}
                           GLEW
                           ${Boost_FILESYSTEM_LIBRARY} )

#target_link_libraries(demo ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} SDL) 
