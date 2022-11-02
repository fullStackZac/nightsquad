#engine project (shared lib)
project(engine VERSION 0.0.1)

#get all cpp files
file(GLOB_RECURSE SRC_FILES src/*.cpp CMAKE_CONFIGURE_DEPENDS)
add_library(${PROJECT_NAME} ${SRC_FILES})

#define symbols
add_definitions(-DNIGHTSQUAD_EXPORT)
add_definitions(-D_DEBUG)

#windows platform
if(WIN32)
  target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/windows/includes)
  target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/windows/libs)
endif(WIN32)

#linux platform
if(UNIX)
  #TODO: Find the crap I need for this part
endif(UNIX)

#precompile headers
target_precompile_headers(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.h)

#add include library
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)