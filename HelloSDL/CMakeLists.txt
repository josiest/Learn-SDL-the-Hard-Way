cmake_minimum_required(VERSION 3.31)
project(HelloSDL)

add_executable(HelloSDL main.cpp)

find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
if (TARGET SDL2::SDL2main)
    target_link_libraries(HelloSDL PUBLIC SDL2::SDL2main)
endif()

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
target_link_libraries(HelloSDL PUBLIC SDL2::SDL2)

# Pop Quiz
# - Why do we have two different calls to find_package for SDL2main and SDL2?
# - What happens if we link SDL2main after SDL2

set_target_properties(HelloSDL PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED True)

# Pop Quiz
# - Why set_target_properties? Are there any other ways to set the C++ standard
#   and why would we prefer one over the other
# - What happens if we take away STANDARD_REQUIRED? What if we change the standard to 17?
# - Why would we want to require C++20 in the first place?
