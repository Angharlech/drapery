
cmake_minimum_required(VERSION 2.6)

project(openGLDemo) 

find_package ( SDL REQUIRED )
find_package(Boost COMPONENTS filesystem REQUIRED)
#find_package(GLUT)
find_package(OpenGL)

include_directories( ${SDL_INCLUDE_DIR} 
                     ${OPENGL_INCLUDE_DIR}
                     ${Boost_INCLUDE_DIR})

file(GLOB DEMO_SOURCE_FILES "*.cpp")
add_executable(demo ${DEMO_SOURCE_FILES})


target_link_libraries(demo ${SDL_LIBRARY} 
                           SDLmain 
                           ${OPENGL_LIBRARIES}
                           ${Boost_FILESYSTEM_LIBRARY} )

#target_link_libraries(demo ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} SDL) 
