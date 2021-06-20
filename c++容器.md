# C++容器
## string
string是STL的字符串类型，在C语言中，我们通常用char *或者char[]字符数组来表示字符串。C++的string和C语言的char *有什么区别呢？

* string是一个类，char *是指向字符的指针
* string封装了char *,管理这个字符串，是一个char *类型的容器
* string不用考虑内存释放和数组越界
* string提供了一些列的字符串操作函数
