# http://www.pointclouds.org/documentation/tutorials/writing_pcd.php#writing-pcd

cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(pcd_write)

find_package(PCL 1.8 REQUIRED COMPONENTS common io)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

file(GLOB pcd_write_SRC
    "src/*.h"
    "src/*.cpp"
)

add_executable(pcd_write ${pcd_write_SRC})
target_link_libraries(pcd_write ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})