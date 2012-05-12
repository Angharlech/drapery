
cmake_minimum_required(VERSION 2.8)

project(drapery) 
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(DRAPERY_SRC_DIRECTORY ${PROJECT_SOURCE_DIR}/src)
set(DRAPERY_SHADER_DIRECTORY ${PROJECT_SOURCE_DIR}/shaders)
set(DRAPERY_EXECUTABLE demo)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -std=c++11")
set(CMAKE_BUILD_TYPE debug)

set(CMAKE_VERBOSE_MAKEFILE off)

find_package ( SDL REQUIRED )
find_package(Boost COMPONENTS filesystem REQUIRED)
find_package(Eigen3)
find_package(OpenGL)

include_directories( ${EIGEN3_INCLUDE_DIR}
                     ${SDL_INCLUDE_DIR} 
                     ${OPENGL_INCLUDE_DIR}
                     ${Boost_INCLUDE_DIR})

file(GLOB DRAPERY_SOURCE_FILES "${DRAPERY_SRC_DIRECTORY}/*.cpp")
add_executable(${DRAPERY_EXECUTABLE} ${DRAPERY_SOURCE_FILES})

add_custom_command(TARGET ${DRAPERY_EXECUTABLE} PRE_BUILD 
    COMMAND ${CMAKE_COMMAND} -E remove_directory 
    "${PROJECT_BINARY_DIR}/shaders"
    COMMENT "Cleaning shaders" VERBATIM)

add_custom_command(TARGET ${DRAPERY_EXECUTABLE} POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${DRAPERY_SHADER_DIRECTORY}
    "${PROJECT_BINARY_DIR}/shaders"
    COMMENT "Copying shaders" VERBATIM)

add_custom_command(TARGET ${DRAPERY_EXECUTABLE} POST_BUILD 
                    COMMAND ctags -R 
                    WORKING_DIRECTORY ${DRAPERY_SRC_DIRECTORY} 
                    COMMENT "Creating tags" VERBATIM)

target_link_libraries(${DRAPERY_EXECUTABLE} ${SDL_LIBRARY} 
                           SDLmain 
                           ${OPENGL_LIBRARIES}
                           GLEW
                           ${Boost_FILESYSTEM_LIBRARY} )

