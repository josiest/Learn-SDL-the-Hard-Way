cmake_minimum_required(VERSION 3.31)
project(01.HelloSDL)

add_executable(HelloSDL hello.cpp)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)
target_link_libraries(HelloSDL PRIVATE SDL3::SDL3)

# Pop Quiz
# reminder: read the documentation for the cmake functions! https://cmake.org/cmake/help/latest/
# 1.a) How does find_package actually find the packages you specify: how does it perform its search?
# 1.b) Does SDL define its own cmake package?
#      (hint: you can find the source code at https://github.com/libsdl-org/SDL)
# 1.c) Why is the "CONFIG" argument used when calling find_package with SDL3?
#
# 2) In the call to find_package, what does the first REQUIRED keyword apply to? What about the second?