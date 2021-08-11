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

* 引用本身并非一个对象，引用定义后就不能绑定到其他的对象了；指针并没有此限制，相当于变量一样使用。
* void*指针可以存放任意对象的地址。因无类型，仅操作内存空间，对所存对象无法访问。
* 其他指针类型必须要与所指对象严格匹配。
* int* p1, p2;//*是对p1的修饰，所以p2还是int型
* 解引用指针得到引用
* 给引用赋值，修改的是该引用所关联的对象的值，而不是让引用和另一个对象相关联。

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

typedef int arrT[10];//表示的类型是含有10个整形的数组。

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

使用的表达式不是一个变量，返回表达式结果对象的类型,赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。

	int i=42,*p=&i,&r=i;
	decltype(r+0) b;//正确，结果是int
	decltype(*p) c;//错误，解引用指针得到引用，int&必须初始化
	int a = 3, b = 4;
	decltype(a = b) d = a;//正确，b是int&


变量加上括号变成表达式
	
	decltype((i)) d://错误,d是int&,必须初始化
	decltype(i) e;//正确，e是int

## using
声明,使用某个命名空间：例如 using std::cin表示使用命名空间std中的名字cin。

## 初始化
拷贝初始化（copy initialization）：使用等号=将一个已有的对象拷贝到正在创建的对象。string s1=s;

直接初始化（direct initialization）：通过括号给对象赋值。string s("hello");

列表初始化： vector<string> v{"a", "an", "the"}; （C++11）


## 数组
### 定义和初始化内置数组
初始化：char input_buffer[buffer_size];，长度必须是const表达式，或者不写，让编译器自己推断。

数组不允许直接赋值给另一个数组。

### 数组和指针

使用数组时，编译器一般会把它转换成指针。

指针访问数组：在表达式中使用数组名时，名字会自动转换成指向数组的第一个元素的指针。

### 多维数组

使用范围for语句时，除了最内层的循环外，其他所有循环的控制变量都应该是引用类型。


## 成员运算符号->
解引用 + 成员访问，it->mem等价于 (*it).mem

## 混用解引用和递增运算符
*iter++等价于*(iter++)，递增优先级较高

	auto iter = vi.begin();
	while (iter!=vi.end()&&*iter>=0)
		cout<<*iter++<<endl;	// 输出当前值，指针向前移1


## sizeof运算符
* 返回一条表达式或一个类型名字所占的字节数。
* 返回的类型是 size_t的常量表达式。

sizeof并不实际计算其运算对象的值。
两种形式：
sizeof (type)，给出类型名

sizeof expr，给出表达式

可用sizeof返回数组的大小

	int ia[10];
	// sizeof(ia)返回整个数组所占空间的大小
	// sizeof(ia)/sizeof(*ia)返回数组的大小
	constexpr size_t sz = sizeof(ia)/sizeof(*ia);
	int arr[sz];


## 显式类型转换（尽量避免）
* static_cast：任何明确定义的类型转换，只要不包含底层const，都可以使用。 double slope = static_cast<double>(j);

* dynamic_cast：支持运行时类型识别。

* const_cast：只能改变运算对象的底层const，一般可用于去除const性质。 const char *pc; char *p = const_cast<char*>(pc)

## 函数
### 有返回值函数
引用返回左值：函数的返回类型决定函数调用是否是左值。调用一个返回引用的函数得到左值；其他返回类型得到右值。

	char& get_value(const &s,string:size_type ix){
		return s[ix];
	}
	
	void test(){
		string s("hello ");
		get_value(s,0)='a';
	}

### 返回数组指针
数组不能拷贝，所以不能返回数组，可用类型别名。

	typedef int arrT[10];
	using arrT=int [10];

	arrT* fun(int i);

如果不使用别名，要定义数组的长度。

	int arr[10];
	int *p[10];//10个指针的数组
	int (*p)[10];指针，指向10个整数的数组。
	
	int (*fun(int i))[10];

使用尾置返回类型

	auto fun(int i) -> int(*)[10];

使用decltype

	int odd=[1,2,3,4,5];
	decltype(odd) *arrPtr(int i) {...}//decltype并不把数组变成指针。数组不能拷贝。所以要加指针*


### 函数指针
函数指针：是指向函数的指针。

函数的类型跟返回类型和参数类型有关，跟函数名无关。

	bool lengthCompare(const string &,const string &);
	bool (*pf)(const string &, const string &); //未初始化
	pf=lengthCompare;

	bool b1=pf("hello","world");//可以不用解引用
	bool b2=(*pf)("hello","world");//解引用


#### 函数指针形参

	//第三个形参是函数类型，它会自动转换成函数的指针
	void useBigger(const string &s1,const string &s2,bool pf(const string &,const string &));
	//等价的声明
	void useBigger(cosnt string &s1,const string &s2,bool (*pf)(const string &,const string &));

使用decltype简化
	
	typedef bool FunC(const string&,const string&);
	typedef decltype(lengthCompare) FunC2;
	typedef bool (*FuncP)(const string&,const string&);
	typedef decltype(lengthCompare) *FuncP2;

	void useBigger(const string&,const string&,Func);
	void useBigger(const string&,const string&,FuncP2);

#### 返回指向函数的指针
	
	using PF= int (*) (int *,int);
	PF f1(int);
	auto f1(int) ->int (*)(int* ,int);

## friend 友元
友元函数：允许特定的非成员函数访问一个类的私有成员.

友元类：如果一个类指定了友元类，则友元类的成员函数可以访问此类包括非公有成员在内的所有成员。

	#include <iostream>
	using namespace std;
	
	class Student{
	public:
	    Student(char *name, int age, float score);
	public:
	    friend void show(Student *pstu);  //将show()声明为友元函数
	private:
	    char *m_name;
	    int m_age;
	    float m_score;
	};
	
	Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){ }
	
	//非成员函数
	void show(Student *pstu){
	    cout<<pstu->m_name<<"的年龄是 "<<pstu->m_age<<"，成绩是 "<<pstu->m_score<<endl;
	}
	
	int main(){
	    Student stu("小明", 15, 90.6);
	    show(&stu);  //调用友元函数
	    Student *pstu = new Student("李磊", 16, 80.5);
	    show(pstu);  //调用友元函数
	
	    return 0;
	}


类指定了友元类：

	#include <iostream>
	using namespace std;
	
	class Address;  //提前声明Address类
	
	//声明Student类
	class Student{
	public:
	    Student(char *name, int age, float score);
	public:
	    void show(Address *addr);
	private:
	    char *m_name;
	    int m_age;
	    float m_score;
	};
	
	//声明Address类
	class Address{
	public:
	    Address(char *province, char *city, char *district);
	public:
	    //将Student类声明为Address类的友元类
	    friend class Student;
	private:
	    char *m_province;  //省份
	    char *m_city;  //城市
	    char *m_district;  //区（市区）
	};
	
	//实现Student类
	Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){ }
	void Student::show(Address *addr){
	    cout<<m_name<<"的年龄是 "<<m_age<<"，成绩是 "<<m_score<<endl;
	    cout<<"家庭住址："<<addr->m_province<<"省"<<addr->m_city<<"市"<<addr->m_district<<"区"<<endl;
	}
	
	//实现Address类
	Address::Address(char *province, char *city, char *district){
	    m_province = province;
	    m_city = city;
	    m_district = district;
	}
	
	int main(){
	    Student stu("小明", 16, 95.5f);
	    Address addr("陕西", "西安", "雁塔");
	    stu.show(&addr);
	   
	    Student *pstu = new Student("李磊", 16, 80.5);
	    Address *paddr = new Address("河北", "衡水", "桃城");
	    pstu -> show(paddr);
	
	    return 0;
	}