cmake_minimum_required(VERSION 3.31.0)
project(computing_at_scale CXX)

add_subdirectory(mathlibrary)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC mathlibrary)

add_executable(virtual virtual.cpp)