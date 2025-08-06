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
# 1.a) Why do we have two different calls to find_package for components SDL2main and SDL2?
# 1.b) Why is the "CONFIG" argument used when calling find_package with SDL2?
# 1.c) Why does only one call include the "REQUIRED" argument before "COMPONENTS"?
# 1.d) When compiling on Windows, what happens if we link SDL2main after SDL2? Why does this error happen?

set_target_properties(HelloSDL PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED True)

# Pop Quiz
# 2.a) What happens if we take away STANDARD_REQUIRED? What if we change the standard to 17?
# 2.b) Why would we want to require C++20 in the first place?
# 2.c) Are there any other ways to set the C++ standard than set_target_properties?
# 2.d) Why would you prefer or not prefer to use set_target_properties over other methods?
