cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
 
project(PCL_openni2_viewer)
 
find_package(PCL 1.8 REQUIRED)

set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/bin
    )
 
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
 
set(PCL_BUILD_TYPE Release)
 
file(GLOB PCL_openni2_viewer_SRC
    "src/*.h"
    "src/*.cpp"
)

add_executable(PCL_openni2_viewer ${PCL_openni2_viewer_SRC})
 
target_link_libraries (PCL_openni2_viewer ${PCL_LIBRARIES})
