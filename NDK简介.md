## C/C++开发工具简介
### GCC,GNU
GCC原名为GNU C语言编译器（GNU C Compiler），只能处理C语言。但其很快扩展，变得可处理C++，后来又扩展为能够支持更多编程语言，如Fortran、Pascal、Objective -C、Java、Ada、Go以及各类处理器架构上的汇编语言等，所以改名GNU编译器套件（GNU Compiler Collection）

虽然我们称GCC是C语言的编译器，但使用gcc由C语言源代码文件生成可执行文件的过程不仅仅是编译的过程，而是要经历四个相互关联的步骤∶预处理（也称预编译，Preprocessing）、编译（Compilation）、汇编（Assembly）和链接（Linking）。

### MinGW-w64

​ MinGW 的全称是：Minimalist GNU on Windows 。它实际上是将经典的开源 C语言编译器 GCC 移植到了 Windows 平台下，并且包含了 Win32API ，因此可以将源代码编译为可在 Windows 中运行的可执行程序。而且还可以使用一些 Windows 不具备的，Linux平台下的开发工具。一句话来概括：MinGW 就是 GCC 的 Windows 版本 。

​ MinGW 现已被 MinGW-w64 所取代，且 MinGW 也早已停止了更新，以后介绍和使用均默认是指MinGW-w64。
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
LLVM（Low Level Virtual Machine），是以 BSD 许可来开发的开源的编译器框架系统，基于 C++ 编写而成，利用虚拟技术来优化以任意程序语言编写的程序的编译时间、链接时间、运行时间以及空闲时间，最早以 C/C++ 为实现对象，对开发者保持开放，并兼容已有脚本。LLVM 计划启动于 2000 年，最初由 University of Illinois at Urbana-Champaign 的 Chris Lattner 主持开展，2006 年 Chris Lattner 加盟苹果公司并致力于 LLVM 在苹果公司开发体系中的应用，所以苹果公司也是 LLVM 计划的主要资助者。目前 LLVM 因其宽松的许可协议，更好的模块化、更清晰的架构，成为很多厂商或者组织的选择，已经被苹果 IOS 开发工具、Facebook、Google 等各大公司采用，像 Swift、Rust 等语言都选择了以 LLVM 为后端。

在理解 LLVM 之前，先说下传统编译器的工作原理，基本上都是三段式的，可以分为前端、优化器和后端。

* 前端负责解析源代码，检查语法错误，并将其翻译为抽象的语法树；
* 优化器对这一中间代码进行优化，试图使代码更高效；
* 后端则负责将优化器优化后的中间代码转换为目标机器的代码，这一过程后端会最大化的利用目标机器的特殊指令，以提高代码的性能。

基于这个认知，我们可以认为 LLVM 包括了两个概念：一个广义的 LLVM 和一个狭义的 LLVM 。广义的 LLVM 指的是一个完整的 LLVM 编译器框架系统，包括了前端、优化器、后端、众多的库函数以及很多的模块；而狭义的 LLVM 则是聚焦于编译器后端功能的一系列模块和库，包括代码优化、代码生成、JIT 等。

![](./Clang-LLVM.jpg)

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
CMake是一个跨平台的安装（编译）工具，可以用简单的语句来描述所有平台的安装(编译过程)。他能够输出各种各样的makefile或者project文件，能测试编译器所支持的C++特性,类似UNIX下的automake。 CMake 的组态档取名为 CMakeLists.txt。Cmake 并不直接建构出最终的软件，而是产生标准的建构档（如 Unix 的 Makefile 或 Windows Visual C++ 的 projects/workspaces），然后再依一般的建构方式使用。

CMake生成器负责为底层构建系统编写输入文件(例如Makefile)。运行cmake--help将显示可用的生成器。对于cmake v2.8.12.2，我的系统支持的生成器包括：

	Generators
	
	The following generators are available on this platform:
	  Unix Makefiles              = Generates standard UNIX makefiles.
	  Ninja                       = Generates build.ninja files (experimental).
	  CodeBlocks - Ninja          = Generates CodeBlocks project files.
	  CodeBlocks - Unix Makefiles = Generates CodeBlocks project files.
	  Eclipse CDT4 - Ninja        = Generates Eclipse CDT 4.0 project files.
	  Eclipse CDT4 - Unix Makefiles
	                              = Generates Eclipse CDT 4.0 project files.
	  KDevelop3                   = Generates KDevelop 3 project files.
	  KDevelop3 - Unix Makefiles  = Generates KDevelop 3 project files.
	  Sublime Text 2 - Ninja      = Generates Sublime Text 2 project files.
	  Sublime Text 2 - Unix Makefiles
	                              = Generates Sublime Text 2 project files.Generators

命令行生成工具生成器

这些生成器用于命令行构建工具，如Make和Ninja。在使用CMake生成构建系统之前，必须配置所选的工具链。
支持的生成器包括：

* Borland Makefiles
* MSYS Makefiles
* MinGW Makefiles
* NMake Makefiles
* NMake Makefiles JOM
* Ninja
* Unix Makefiles
* Watcom WMake

IDE构建工具生成器

这些生成器用于集成开发环境，其中包括它们自己的编译器。例如Visual Studio和Xcode，它们本身就包含一个编译器。
支持的生成器包括：

* Visual Studio 6
* Visual Studio 7
* Visual Studio 7 .NET 2003
* Visual Studio 8 2005
* Visual Studio 9 2008
* Visual Studio 10 2010
* Visual Studio 11 2012
* Visual Studio 12 2013
* Xcode

### Ninja
Ninja是一个专注于速度的构建系统，和其他构建系统相比，主要有两点不同：
Ninja的输入文件一般都是有更高级的构建系统产生的，比如cmake；
Ninja设计之初就是为了更快的构建；
 其实从第一点，我们就能看出来Ninja的设计哲学：相比Makefile是设计出来给人手写的，但是Ninja设计出来是给其它程序生成的。 如果说Makefile是C语言，那么Ninja就是汇编语言。 如果说Makefile是一个DSL，那么Ninja就是一种配置文件。 Makefile支持分支、循环等流程控制，而Ninja只支持一些固定形式的配置。

简单使用，工程目录有以下文件：
bar.c中定义了一个变量和函数，供foo.c调用:

	// Filename:  bar.c
	#include "bar.h"
	#include <stdio.h>
	
	int g_bar = 0;
	
	int run_bar()
	{
		printf("g_bar  = %d\n", g_bar);
		return 0;
	}

foo.c内存为

	// Filename: foo.c
	#include <stdio.h>
	int main() 
	{
		int a = 10;
		int b = 5;
		printf("ok");
	}

ninja编译脚本内容为：

	# Filename: build.ninja
	
	cc = g++
	cflags = -Wall
	
	rule cc
	  command = gcc $cflags -c $in -o $out
	  description = compile .cc
	
	build out/bar.o: cc bar.c
	build out/foo.o: cc foo.c

### 交叉编译

交叉编译是在一个平台上生成另一个平台上的可执行代码。**同一个体系结构可以运行不同的操作系统；同样，同一个操作系统也可以在不同的体系结构上运行。

​一个经常会被问到的问题就是，“既然我们已经有了主机编译器，那为什么还要交叉编译呢？”其实答案很简单：

* 有时是因为目的平台上不允许或不能够安装我们所需要的编译器，而我们又需要这个编译器的某些特征；
* 有时是因为目的平台上的资源贫乏，无法运行我们所需要编译器；
* 有时又是因为目的平台还没有建立，连操作系统都没有，根本谈不上运行什么编译器。


要进行交叉编译，我们需要在主机平台上安装对应的交叉编译工具链（cross compilation tool chain），然后用这个交叉编译工具链编译我们的源代码，最终生成可在目标平台上运行的代码。

## Android NDK
### 安装
![](./NDK1.png)
![](./NDK3.png)
![](./NDK4.png)
### 配置

	ndkVersion "21.4.7075529"

	externalNativeBuild{
		cmake{
			path file('CMakeLists.txt')
		}
	}

![](./NDK2.png)


### [Cmake](https://developer.android.com/ndk/guides/cmake?hl=zh-cn)

NDK 通过工具链文件支持 CMake。工具链文件是用于自定义交叉编译工具链行为的 CMake 文件。用于 NDK 的工具链文件位于 NDK 中的 <NDK>/build/cmake/android.toolchain.cmake 内,最后会使用各种平台下的Clang[将 NDK 与其他构建系统配合使用](https://developer.android.com/ndk/guides/other_build_systems)

在调用 Clang 时使用 -target 传递适当的目标，或调用具有目标前缀的 Clang。例如，若要为 64 位 ARM Android 编译值为 21 的 minSdkVersion，可使用以下两种方法，您可以选择使用其中最方便的方法：

    $ $NDK/toolchains/llvm/prebuilt/$HOST_TAG/bin/clang++ \
        -target aarch64-linux-android21 foo.cpp



**Cmkae使用参考**

[Android NDK 开发之 CMake 必知必会](https://juejin.cn/post/6844903678311153672)

[Android NDK 开发：CMake 使用](http://cfanr.cn/2017/08/26/Android-NDK-dev-CMake-s-usage/)





