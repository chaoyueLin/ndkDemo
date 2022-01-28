# Android NDK简介
## Android NDK 开发工具简介
### GCC,GNU
GCC原名为GNU C语言编译器（GNU C Compiler），只能处理C语言。但其很快扩展，变得可处理C++，后来又扩展为能够支持更多编程语言，如Fortran、Pascal、Objective -C、Java、Ada、Go以及各类处理器架构上的汇编语言等，所以改名GNU编译器套件（GNU Compiler Collection）

### Clang
Clang是一个由Apple主导编写，基于LLVM的C/C++/Objective-C编译器。

​Clang是一个C++编写、基于LLVM、发布于LLVM BSD许可证下的C/C++/Objective-C/Objective-C++编译器。它与GNU C语言规范几乎完全兼容（当然，也有部分不兼容的内容，包括编译命令选项也会有点差异），并在此基础上增加了额外的语法特性，比如C函数重载（通过__attribute__((overloadable))来修饰函数），其目标（之一）就是超越GCC。

​2013年4月,Clang已经全面支持C++11标准，并开始实现C++1y特性（也就是C++14，这是C++的下一个小更新版本）。Clang将支持其普通lambda表达式、返回类型的简化处理以及更好的处理constexpr关键字。

Clang相比GCC的优势
* Clang 采用的是 BSD 协议的许可证，而 GCC 采用的是 GPL 协议，显然前者更为宽松；
* Clang 是一个高度模块化开发的轻量级编译器，编译速度快、占用内存小、有着友好的出错提示。

Android NDK 已在具体应用中放弃了 GCC，全面转向 Clang
* Android NDK 从 r11 开始建议大家切换到 Clang，并且把 GCC 标记为 deprecated，将 GCC 版本锁定在 GCC 4.9 不再更新；
* Android NDK 从 r13 起，默认使用 Clang 进行编译，但是暂时也没有把 GCC 删掉，Google 会一直等到 libc++ 足够稳定后再删掉 GCC；
* Android NDK 在 r17 中宣称不再支持 GCC 并在后续的 r18 中删掉 GCC，具体可见 NDK 的版本历史。
### LLVM
LLVM（Low Level Virtual Machine），是以 BSD 许可来开发的开源的编译器框架系统，基于 C++ 编写而成，利用虚拟技术来优化以任意程序语言编写的程序的编译时间、链接时间、运行时间以及空闲时间，最早以 C/C++ 为实现对象，对开发者保持开放，并兼容已有脚本。

### makefile
makefiel 编译链接脚本，
* 将源代码文件编译成可重定位目标文件.o
* 设置编译器选项，例如是否开启优化，传递宏，打开警告等
* 链接，将静态库或动态库与目标文件链接

格式

        <target> : <prerequisites> 
        [tab]  <commands>

假设要将main.c复制名为pow.c的文件

    pow.c:main.c
        cp main.c pow.c

make使用gcc流程，例如编译链接 main.c成main.o

    $ gcc -g -Wall -c main.c -o main.o
    $ gcc -o main main.o -lm

makefile可以这么写

    CC=gcc
    CFLAGS=-g -Wall
    LIBS=-lm
    OBJ=main.o
    $(OBJ):main.c
        $(CC) $(CFLAGS) -c main.c -o $(OBJ)
    TARGET=main
    $(TARGET):main.o
        $(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBS)
    .PHONY:clean
    clean:
        rm $(OBJ) $(TARGET)

**注意：makefile是跟平台相关的**
### Cmake
交叉编译是在一个平台上生成另一个平台上的可执行代码。比如，我们在Windows平台上，可使用Visual C++开发环境，编写程序并编译成可执行程序。这种方式下，我们使用PC平台上的Windows工具开发针对Windows本身的可执行程序，这种编译过程称为native compilation（本机编译）。

然而，在进行嵌入式系统的开发时，运行程序的目标平台通常具有有限的存储空间和运算能力，比如常见的ARM平台，其一般的静态存储空间大概是16到32MB，而CPU的主频大概在100MHz到500MHz之间。这种情况下，在ARM平台上进行本机编译就不太可能了，这是因为一般的编译工具链（compilation tool chain）需要很大的存储空间，并需要很强的CPU运算能力。为了解决这个问题，交叉编译工具就应运而生了。通过交叉编译工具，我们就可以在CPU能力很强、存储空间足够的主机平台上（比如PC上）编译出针对其他平台的可执行程序。

​要进行交叉编译，我们需要在主机平台上安装对应的交叉编译工具链（cross compilation tool chain），然后用这个交叉编译工具链编译我们的源代码，最终生成可在目标平台上运行的代码。

CMake是一个跨平台的安装（编译）工具，可以用简单的语句来描述所有平台的安装(编译过程)。他能够输出各种各样的makefile或者project文件，能测试编译器所支持的C++特性,类似UNIX下的automake。 CMake 的组态档取名为 CMakeLists.txt。Cmake 并不直接建构出最终的软件，而是产生标准的建构档（如 Unix 的 Makefile 或 Windows Visual C++ 的 projects/workspaces），然后再依一般的建构方式使用。

**Cmkae使用参考**

[Android NDK 开发之 CMake 必知必会](https://juejin.cn/post/6844903678311153672)

[Android NDK 开发：CMake 使用](http://cfanr.cn/2017/08/26/Android-NDK-dev-CMake-s-usage/)

## Android NDK本地环境

CMake 工具链文件[Cmake](https://developer.android.com/ndk/guides/cmake?hl=zh-cn)

NDK 通过工具链文件支持 CMake。工具链文件是用于自定义交叉编译工具链行为的 CMake 文件。用于 NDK 的工具链文件位于 NDK 中的 <NDK>/build/cmake/android.toolchain.cmake 内,最后会使用各种平台下的Clang[将 NDK 与其他构建系统配合使用](https://developer.android.com/ndk/guides/other_build_systems)

在调用 Clang 时使用 -target 传递适当的目标，或调用具有目标前缀的 Clang。例如，若要为 64 位 ARM Android 编译值为 21 的 minSdkVersion，可使用以下两种方法，您可以选择使用其中最方便的方法：

    $ $NDK/toolchains/llvm/prebuilt/$HOST_TAG/bin/clang++ \
        -target aarch64-linux-android21 foo.cpp

ndk-build 使用的 Android.mk 构建文件[Android.mk](https://developer.android.com/ndk/guides/android_mk?hl=zh-cn)

### 调试和性能分析

ndk-gdb

ndk-stack

## Crash定位,tombstone分析
demo中有使用ndk-stack解析出调用链

[C/C++ 编译和链接过程详解 (重定向表，导出符号表，未解决符号表)](https://www.cnblogs.com/wfwenchao/articles/4140771.html)
[Tombstone 分析](https://www.cnblogs.com/codertian/p/5980426.html)

[ndk-stack](https://developer.android.com/ndk/guides/ndk-stack)
