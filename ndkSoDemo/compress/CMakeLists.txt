# Sets the minimum version of CMake required to build the native library.
cmake_minimum_required(VERSION 3.10.2)


#指定要引用的libjpeg.so的头文件目录
set(LIBJPEG_INCLUDE_DIR src/main/cpp/include)
include_directories(${LIBJPEG_INCLUDE_DIR})

#导入libjpeg动态库 SHARED；静态库为STATIC
add_library(jpeg SHARED IMPORTED)
#对应so目录，这里为了简单设置的是绝对路径（注意要先 add_library，再 set_target_properties）
set_target_properties(jpeg PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libjpeg.so)
set_target_properties(jpeg PROPERTIES IMPORTED_NO_SONAME TRUE)
add_library(
             compress
             SHARED
             src/main/cpp/compress.c
             )

find_library(graphics jnigraphics)
find_library(log-lib log)

target_link_libraries(compress jpeg ${log-lib} ${graphics})