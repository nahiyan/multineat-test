cmake_minimum_required(VERSION 3.20)
project(MultiNEAT)

set(CMAKE_CXX_STANDARD 11)

set(Boost_USE_STATIC_LIBS OFF) # only find static libs
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS date_time system filesystem serialization)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

add_definitions(-DUSE_BOOST_RANDOM)
add_definitions(-DVDEBUG)

add_library(
  MultiNEAT STATIC
  ${PROJECT_SOURCE_DIR}/src/Genome.cpp
  ${PROJECT_SOURCE_DIR}/src/Innovation.cpp
  ${PROJECT_SOURCE_DIR}/src/NeuralNetwork.cpp
  ${PROJECT_SOURCE_DIR}/src/Parameters.cpp
  ${PROJECT_SOURCE_DIR}/src/Population.cpp
  ${PROJECT_SOURCE_DIR}/src/Random.cpp
  ${PROJECT_SOURCE_DIR}/src/Species.cpp
  ${PROJECT_SOURCE_DIR}/src/Substrate.cpp
  ${PROJECT_SOURCE_DIR}/src/Utils.cpp
  ${PROJECT_SOURCE_DIR}/src/Traits.cpp)

target_link_libraries(MultiNEAT ${Boost_LIBRARIES} pthread)
