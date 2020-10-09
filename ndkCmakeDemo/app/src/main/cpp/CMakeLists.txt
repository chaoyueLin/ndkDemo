# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

set(v hello)
message(${v})

function(add a b)
    message("this is function call")
    math(EXPR num "${a} + ${b}" )
    message("result is ${num}")
endfunction()

add(1 2)


set(num 0)
if (1 AND ${num})
    message("and operation")
elseif (1 OR ${num})
    message("or operation")
else ()
    message("not reach")
endif ()


# 文件重命名
#file(RENAME "test.txt" "new.txt")

# 文件下载
# 把文件 URL 设定为变量
set(var "http://img.zcool.cn/community/0117e2571b8b246ac72538120dd8a4.jpg")

# 使用 DOWNLOAD 下载
file(DOWNLOAD ${var} "/Users/image.jpg")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             native-lib.cpp )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )