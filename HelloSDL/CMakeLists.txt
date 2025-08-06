cmake_minimum_required(VERSION 3.31)
project(HelloSDL)

add_executable(HelloSDL hello.cpp)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)
target_link_libraries(HelloSDL PUBLIC SDL3::SDL3)

# Pop Quiz (reminder: read the documentation for the cmake functions!)
# 1.a.i)   How does find_package actually find the packages you specify: how does it perform its search?
#
# 1.a.ii)  Does SDL define its own cmake package?
#          (hint: you can find the source code at https://github.com/libsdl-org/SDL)
#
# 1.a.iii) Why is the "CONFIG" argument used when calling find_package with SDL3?
#
# 1.b) In the call to find_package, what does the first REQUIRED keyword apply to? What about the second?

# Answer Key
# 1.a.i)   cmake's find_package function may use two different search procedures: Module or Config.
#          Module mode looks for Find<PackageName>.cmake while Config mode searches for <PackageName>Config.cmake.
#          Find<PackageName>.cmake are usually third party scripts written to find libraries that weren't built
#          with cmake in mind.
#
# 1.a.ii)  Yes! The source code has a cmake folder at the root level where it defines its own cmake package.
#          In particular notice that there's an SDL3Config.cmake.in file. CMake will use this as a template to
#
# 1.a.iii) Because SDL defines its own cmake package, we can tell find_package to skip module mode by specifying
#          the CONFIG argument
#
# 1.b) The first REQUIRED keyword specified that we need the SDL3 package in order to compile this program.
#      However the SDL3 package is composed of modular components that we can choose to include or exclude.
#      We must include the core component which is also called SDL3, so we pass in REQUIRED COMPONENTS SDL3.