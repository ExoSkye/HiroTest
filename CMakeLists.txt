project(HiroTest)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(nall)
add_subdirectory(hiro)

add_executable(test main.cpp)
target_link_libraries(test nall hiro)