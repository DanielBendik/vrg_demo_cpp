cmake_minimum_required(VERSION 3.20)
project(ShootingSimulator CXX)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/third_party/entt)
include(FetchContent)

# Catch2 library
#FetchContent_Declare(
#  catch2
#  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#  GIT_TAG v3.0.1
#)
#FetchContent_MakeAvailable(catch2)

# EnTT library
FetchContent_Declare(
  entt
  GIT_REPOSITORY https://github.com/skypjack/entt.git
  GIT_TAG v3.13.0
)
FetchContent_MakeAvailable(entt)

add_executable(ShootingSimulator main.cpp)
#add_executable(TestExecutable test.cpp)

target_link_libraries(ShootingSimulator PRIVATE EnTT::EnTT)
#target_link_libraries(TestExecutable PRIVATE Catch2::Catch2)
