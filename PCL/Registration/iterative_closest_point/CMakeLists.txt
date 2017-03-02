cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(iterative_closest_point)

find_package(PCL 1.8 REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

set(PCL_BUILD_TYPE Release)

file(GLOB iterative_closest_point_SRC
    "src/*.h"
    "src/*.cpp"
)

add_executable(iterative_closest_point ${iterative_closest_point_SRC})
target_link_libraries(iterative_closest_point ${PCL_LIBRARIES})
