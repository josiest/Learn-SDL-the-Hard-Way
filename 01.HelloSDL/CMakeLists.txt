cmake_minimum_required(VERSION 3.31)
project(HelloSDL)

add_executable(HelloSDL hello.cpp)

find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
if (TARGET SDL2::SDL2main)
    target_link_libraries(HelloSDL PUBLIC SDL2::SDL2main)
endif()

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
target_link_libraries(HelloSDL PUBLIC SDL2::SDL2)

# Pop Quiz
# reminder: read the documentation for the cmake functions!
# https://cmake.org/cmake/help/latest/index.html
#
# 1.a) How does find_package actually find the packages you specify: how does it perform its search?
#
# 1.b) Does SDL define its own cmake package?
#      (hint: you can find the answer to this in source code at https://github.com/libsdl-org/SDL)
#
# 1.c) Why is the "CONFIG" argument used when calling find_package with SDL3?
#
# 2) In the second call to find_package, there are two instances of the REQUIRED keyword.
#    What parts of the call to find_package do the different instances of REQUIRED apply to?
#
# For the following questions, these resources may be useful if you get stuck
# - https://wiki.libsdl.org/SDL2/README-cmake
# - https://wiki.libsdl.org/SDL2/FAQWindows
#
# 3.a) Why do we sometimes link SDL2main? Why is not required?
#      (hint: Try commenting out the line where we link SDL2main. What happens if you run on Windows vs on Linux?)
#
# 3.b) When compiling on Windows, what happens if we link SDL2main after SDL2? Why do we get an error?
