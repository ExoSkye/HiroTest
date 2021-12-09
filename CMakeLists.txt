project(testHiroAndNall)
cmake_minimum_required(VERSION 3.0)

add_subdirectory(nall)
add_subdirectory(hiro)

add_executable(test main.cpp)
target_link_libraries(test nall hiro)