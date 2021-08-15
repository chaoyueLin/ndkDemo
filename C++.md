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
using 声明,使用某个命名空间：例如 using std::cin表示使用命名空间std中的名字cin。声明语句一次只引入命名空间的一个成员

using指示（using directive）：使得某个特定的命名空间中所有的名字都可见。using namespace std;

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

* dynamic_cast：支持运行时类型识别。用于将基类的指针或引用安全地转换曾派生类的指针或引用

		dynamic_cast<type*>(e)  // e必须是一个有效的指针
		dynamic_cast<type&>(e)  // e必须是一个左值
		dynamic_cast<type&&>(e) // e不能是左值
		// 以上，type类型必须时一个类类型，并且通常情况下该类型应该含有虚函数。
		// e的类型必须符合三个条件中的任意一个，它们是：
		// 1. e的类型是目标type的公有派生类；
		// 2. e的类型是目标type的共有基类；
		// 3. e的类型就是目标type的类型；
		
		// 指针类型的dynamic_cast
		// 假设Base类至少含有一个虚函数，Derived是Base的共有派生类。
		if (Derived *dp = dynamic_cast<Derived*>(bp)) {
		    // 使用dp指向的Derived对象
		} else {    // bp指向一个Base对象
		    // 使用dp指向的Base对象
		}
		
		// 引用类型的dynamic_cast
		void f(const Base &b) {
		    try {
		        const Derived &d = dynamic_cast<const Derived&>(b);
		        // 使用b引用的Derived对象
		    } catch (bad_cast) {
		        // 处理类型转换失败的情况
		    }
		}

* typeid运算符(typeid operator)，它允许程序向表达式提问：你的对象是什么类型？
	typeid表达式的形式是typeid(e)，其中e可以是任意表达式或类型的名字，它操作的结果是一个常量对象的引用。它可以作用于任意类型的表达式。

		Derived *dp = new Derived;
		Base *bp = dp;
		
		if (typeid(*bp) == typeid(*dp)) {
		    // bp和dp指向同一类型的对象
		}
		
		if (typeid(*bp) == typeid(Derived)) {
		    // bp实际指向Derived对象
		}


* const_cast：只能改变运算对象的底层const，一般可用于去除const性质。 const char *pc; char *p = const_cast<char*>(pc)


## constexpr函数
指能用于常量表达式的函数。constexpr int new_sz() {return 42;}

函数的返回类型及所有形参类型都要是字面值类型。



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


## 类成员指针
### 成员指针：指可以指向类的非静态成员的指针。

### 数据成员指针
和其他指针一样，在声明成员指针时也使用*来表示当前声明的名字是一个指针。与普通指针不同的时，成员指针还必须包含成员所属的类。

	// pdata可以指向一个常量(非常量)Screen对象的string成员
	const string Screen::*pdata;

	// C++11
	auto pdata = &Screen::contents;

当我们初始化一个成员指针或为成员指针赋值时，该指针没有指向任何数据。成员指针指定了成员而非该成员所属的对象，只有当解引用成员指针时才提供对象的信息。

	Screen myScreen, *pScreen = &myScreen;
	auto s = myScreen.*pdata;
	s = pScreen->*pdata;

### 成员函数指针
因为函数调用运算符的优先级较高，所以在声明指向成员函数的指针并使用这些的指针进行函数调用时，括号必不可少：(C::*p)(parms)和(obj.*p)(args)。

## lambda表达式
可以理解成是一个未命名的内联函数。

形式：[capture list](parameter list) -> return type {function body}。例如：[sz](const string &a){return a.size() >= sz;}

尽可能避免捕获指针或引用

隐式捕获：让编译器推断捕获列表，在捕获列表中写一个&（引用方式）或=（值方式）。auto f3 = [=] {return v1;}

## function类型
可调用对象：函数，函数指针，lambda表达式，bind创建的对象,重载了函数调用的类。function是一个模板，可用来存储可调用对象。

	int add(int i,int j){return i+j;}
	
	auto mod=[](int i,int j){return i%j;};
	
	struct divide{
		int operator() (int deniminator,int divisor){
			return denominator/divisor;
		}
	}
	
	funntion<int(int,int)>=add;
	funntion<int(int,int)>=divide();
	funntion<int(int,int)>=mode;
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

友元关系不能继承

	class Base{
		friend class Pal;
	};

	class Pal{
		
	};
	class D2 :public Pal{
	public:
		int mem(Base b){
			return b.prot_mem;//错误，友元关系不能继承
		}
	};

## 面向对象程序设计
### 类型转换与继承
派生类向基类的自动类型转换只对指针或引用类型有效，对象之间不存在类型转换。

只有在派生类是使用public，protected的方式继承基类时，才可以使用派生类到基类（derived-to-base）的转换。

### 访问控制与继承
在派生类的作用域内，派生访问说明符private不会影响访问基类的protected成员。

在派生类的作用域外。派生访问说明符是private,基类的方法都无法调用。派生类的派生类，也无法访问。

## union
联合(union)是一种特殊的类。一个union可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。它不能含有引用类型的成员和虚函数。