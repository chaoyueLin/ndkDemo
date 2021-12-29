cmake_minimum_required(VERSION 3.10.2)
project(cmakeDemo)


add_library(myso SHARED Native.c)

set_target_properties(myso
                      PROPERTIES
                      LIBRARY_OUTPUT_DIRECTORY
                      "${CMAKE_CURRENT_SOURCE_DIR}/lib")


target_link_libraries(myso
                     log)