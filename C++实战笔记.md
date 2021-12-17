
## 预处理

 #include”其实是非常“弱”的，不做什么检查，就是“死脑筋”把数据合并进源文件

	static uint32_t  calc_table[] = {
	#  include "calc_values.inc"        // 非常大的一个数组，细节被隐藏
	};

可以让 GCC 使用“-E”选项，略过后面的编译链接，只输出预处理后的源码

	g++ test03.cpp -E -o a.cxx    #输出预处理后的源码

写头文件的时候，为了防止代码被重复包含，通常要加上“Include Guard”，也就是用“#ifndef/#define/#endif”来保护整个头文件

	#ifndef _XXX_H_INCLUDED_
	#define _XXX_H_INCLUDED_
	
	...    // 头文件内容
	
	#endif // _XXX_H_INCLUDED_

宏定义前先检查，如果之前有定义就先 undef，然后再重新定义

	#ifdef AUTH_PWD                  // 检查是否已经有宏定义
	#  undef AUTH_PWD                // 取消宏定义
	#endif                           // 宏定义检查结束
	#define AUTH_PWD "xxx"           // 重新宏定义

_cplusplus”，它标记了 C++ 语言的版本号，使用它能够判断当前是 C 还是 C++，是 C++98 还是 C++11。
	
	#ifdef __cplusplus                      // 定义了这个宏就是在用C++编译
	    extern "C" {                        // 函数按照C的方式去处理
	#endif
	    void a_c_function(int a);
	#ifdef __cplusplus                      // 检查是否是C++编译
	    }                                   // extern "C" 结束
	#endif
	
	#if __cplusplus >= 201402                // 检查C++标准的版本号
	    cout << "c++14 or later" << endl;    // 201402就是C++14
	#elif __cplusplus >= 201103              // 检查C++标准的版本号
	    cout << "c++11 or before" << endl;   // 201103是C++11
	#else   // __cplusplus < 201103          // 199711是C++98
	#   error "c++ is too old"               // 太低则预处理报错
	#endif  // __cplusplus >= 201402         // 预处理语句结束

使用“#if 1”“#if 0”来显式启用或者禁用大段代码，要比“/* … */”的注释方式安全得多，也清楚得多


	#if 0          // 0即禁用下面的代码，1则是启用
	  ...          // 任意的代码
	#endif         // 预处理结束
	
	#if 1          // 1启用代码，用来强调下面代码的必要性
	  ...          // 任意的代码
	#endif         // 预处理结束
