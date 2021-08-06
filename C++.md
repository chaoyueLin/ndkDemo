## 引用
一般说的引用是指的左值引用

引用：引用是一个对象的别名，引用类型引用（refer to）另外一种类型。如int &refVal = val;。

引用必须初始化。

引用和它的初始值是绑定bind在一起的，而不是拷贝。一旦定义就不能更改绑定为其他的对象

## 指针
int *p; //指向int型对象的指针

是一种 "指向（point to）"另外一种类型的复合类型。

定义指针类型： int *ip1;，从右向左读有助于阅读，ip1是指向int类型的指针。

指针存放某个对象的地址。

### 指针和引用的区别
引用本身并非一个对象，引用定义后就不能绑定到其他的对象了；指针并没有此限制，相当于变量一样使用。

void*指针可以存放任意对象的地址。因无类型，仅操作内存空间，对所存对象无法访问。

其他指针类型必须要与所指对象严格匹配。

int* p1, p2;//*是对p1的修饰，所以p2还是int型

解引用指针得到引用

## const限定符

const对象必须初始化，且不能被改变。const int ival=1;

const的引用,reference to const（对常量的引用）：指向const对象的引用，如 const int ival=1; const int &refVal = ival;，可以读取但不能修改

### 指针和const

* pointer to const（指向常量的指针）：不能用于改变其所指对象的值, 如 const double pi = 3.14; const double *cptr = &pi;。
* const pointer：指针本身是常量，也就是说指针固定指向该对象，（存放在指针中的地址不变，地址所对应的那个对象值可以修改）如 int i = 0; int *const ptr = &i;

### 顶层const

* 顶层const：指针本身是个常量。
* 底层const：指针指向的对象是个常量。拷贝时严格要求相同的底层const资格。

## typedef
传统别名：使用typedef来定义类型的同义词。 typedef double wages;

新标准别名：别名声明（alias declaration）： using SI = Sales_item;

### 指针
对于复合类型（指针等）不能代回原式来进行理解

typedef char *pstring;  // pstring是char*的别名

const pstring cstr = 0; // 指向char的常量指针（const pointer），即为(const char *) cstr = 0;

## auto
会忽略顶层const,对引用其实使用引用的对象

	int i=0,&r=i;
	auto a=r;//a是一个整数
	const int ci=i;&cr=ci;
	auto b=ci;//b是一个整数
	auto c=cr;//c是一个整数
	auto d=&i;//d是一个整型指针
	auto e=$ci;//e是一个指向整数常量的指针

## decltype
返回改变量的类型（包括顶层const和引用在内）

	const int ci=0;&cj=ci;
	decltype(ci) x=0;//x的类型是const int
	decltype(cj)y=x;//y的类型是const int &,y绑定到变量x

使用的表达式不是一个变量，返回表达式结果对象的类型

	int i=42,*p=&i,&r=i;
	decltype(r+0) b;//正确，结果是int
	decltype(*p) c;//错误，解引用指针得到引用，int&必须初始化

变量加上括号变成表达式
	
	decltype((i)) d://错误,d是int&,必须初始化
	decltype(i) e;//正确，e是int