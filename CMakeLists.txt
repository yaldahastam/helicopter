cmake_minimum_required(VERSION 3.00)
project(Helicopter)
add_executable(app main.cpp source/user_helicopter.cpp source/enemy_helicopter.cpp source/map.cpp)
include_directories(include)