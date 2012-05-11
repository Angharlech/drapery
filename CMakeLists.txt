
cmake_minimum_required(VERSION 2.6)

project(openGLDemo) 

Find_Package ( SDL REQUIRED )


#find_package(GLUT)
find_package(OpenGL)
include_directories( ${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})
add_executable(demo demo.cpp)
target_link_libraries(demo ${SDL_LIBRARY} SDLmain ${OPENGL_LIBRARIES})

#target_link_libraries(demo ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} SDL) 
