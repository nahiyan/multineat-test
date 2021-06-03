cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)
project(MultiNeatTest)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/MultiNeat)
add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(main MultiNEAT)
target_include_directories(main
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/MultiNeat/src)
