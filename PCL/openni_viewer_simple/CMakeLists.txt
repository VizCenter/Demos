cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(openni_viewer_simple)

find_package(PCL 1.2 REQUIRED)

set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/bin
    )

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

file(GLOB openni_viewer_simple_SRC
    "src/*.h"
    "src/*.cpp"
)

add_executable (openni_viewer_simple ${openni_viewer_simple_SRC})
target_link_libraries (openni_viewer_simple ${PCL_LIBRARIES})