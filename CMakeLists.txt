project(uno)
cmake_minimum_required(VERSION 3.14)

enable_testing()

add_compile_options(-Wall -Werror)

add_subdirectory(uno)

add_subdirectory(project_02)
add_subdirectory(project_03)
add_subdirectory(project_04)
