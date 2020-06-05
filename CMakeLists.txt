cmake_minimum_required(VERSION 3.15)

project(yonside C)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake OPTIONAL)

find_package(SDL2)



add_library(yonside SHARED src/terminal.c "src/sdl2.h")
target_compile_definitions(yonside PRIVATE YON_EXPORTS)
target_include_directories(yonside PUBLIC src/)
target_link_libraries(yonside SDL2)


