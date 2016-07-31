cmake_minimum_required(VERSION 2.6)
project(robopuzzle)

add_executable(robopuzzle main.cpp)

install(TARGETS robopuzzle RUNTIME DESTINATION bin)
