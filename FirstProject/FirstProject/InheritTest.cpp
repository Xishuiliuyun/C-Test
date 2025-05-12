#include "InheritTest.h"

namespace {

	//继承方式测试
	class BaseClass20
	{
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_C = 100;
	public:
		void PVal()
		{
			cout << "m_A = \t" << m_A << endl;
			cout << "m_B = \t" << m_B << endl;
			cout << "m_C = \t" << m_C << endl;
			cout << "&m_A = \t" << &m_A << endl;
			cout << "&m_B = \t" << &m_B << endl;
			cout << "&m_C = \t" << &m_C << endl;
			cout << endl;
		}
	};
	class Class20 :public BaseClass20
	{
	public:
		void fun()
		{
			m_A = 100;//继承后维持原访问权限
			m_B = 100;//继承后维持原访问权限
			//m_C = 100;//私有权限private的内容无法访问
			PVal();
		}
	};
	class Class20_1 :protected BaseClass20
	{
	public:
		void fun()
		{
			m_A = 200;//继承后设置为保护权限protected
			m_B = 200;//继承后设置为保护权限protected
			//m_C = 200;//私有权限private的内容无法访问
			PVal();
		}
	};
	class Class20_2 :private BaseClass20
	{
	public:
		void fun()
		{
			m_A = 300;//继承后设置为私有权限private
			m_B = 300;//继承后设置为私有权限private
			//m_C = 300;//私有权限private的内容无法访问
			PVal();
		}
	};
	class Class20_3 :public Class20_2
	{
	public:
		void fun()
		{
			//m_A = 400;//私有权限private的内容无法访问
			//m_B = 400;//私有权限private的内容无法访问
			//m_C = 400;//私有权限private的内容无法访问
			//PVal();//私有权限private的内容无法访问
		}
	};
	void fun20()
	{
		cout << "\n\nTest_fun20" << endl;
		Class20 c1;
		c1.m_A = 110;
		//c1.m_B = 110;//protected权限，类外无法访问
		//c1.m_C = 110;//无法访问

		Class20_1 c2;
		//c2.m_A = 220;//protected权限，类外无法访问
		//c2.m_B = 220;//protected权限，类外无法访问
		//c2.m_C = 220;//无法访问

		Class20_2 c3;
		//c3.m_A = 330;//私有权限private，类外无法访问
		//c3.m_B = 330;//私有权限private，类外无法访问
		//c3.m_C = 330;//无法访问

		Class20_3 c4;
		//c4.m_A = 440;//无法访问
		//c4.m_B = 440;//无法访问
		//c4.m_C = 440;//无法访问
		c1.PVal();
		//c2.PVal();//protected权限，类外无法访问
		//c3.PVal();//私有权限private，类外无法访问
		//c4.PVal();//无法访问

		c1.fun();
		c2.fun();
		c3.fun();
		c4.fun();

	}

	// 继承中构造和析构的顺序
	class BaseClass21
	{
	public:
		BaseClass21()
		{
			cout << "父类构造" << endl;
		}
		~BaseClass21()
		{
			cout << "父类析构" << endl;
		}
	};
	class Class21 :public BaseClass21
	{
	public:
		Class21()
		{
			cout << "子类构造" << endl;
		}
		~Class21()
		{
			cout << "子类析构" << endl;
		}
	};
	void fun21()
	{
		cout << "\n\nTest_fun21" << endl;
		Class21 c1;
	}


	//继承中同名成员的处理方式
	class BaseClass22
	{
	public:
		int m_A;
		static int m_B;
		BaseClass22()
		{
			m_A = 100;
		}
		void fun()
		{
			cout << "BaseClass22" << endl;
		}
		void fun(int a)
		{
			cout << "BaseClass22_fun(int a)" << endl;
		}
		static void fun1()
		{
			cout << "BaseClass22 static void fun1()" << endl;
		}
		static void fun1(int a)
		{
			cout << "BaseClass22 static void fun1(int a)" << endl;
		}
	};
	int BaseClass22::m_B = 100;
	class Class22:public BaseClass22
	{
	public:
		int m_A;
		static int m_B;
		Class22()
		{
			m_A = 200;
		}
		void fun()
		{
			cout << "Class22" << endl;
		}
		static void fun1()
		{
			cout << "Class22 static void fun1()" << endl;
		}
	};
	int Class22::m_B = 200;
	void fun22()
	{
		cout << "\n\nTest_fun22" << endl;
		//访问成员变量
		Class22 c1;
		cout << c1.m_A << endl;
		cout << c1.BaseClass22::m_A << endl;

		//访问成员函数
		c1.fun();
		c1.BaseClass22::fun();
		//c1.fun(100);//报错，子类中有同名成员函数时，会隐藏父类中所有的同名成员函数
		c1.BaseClass22::fun(100);

		//访问静态成员变量
		cout << "Class22_static int m_B = \t" << c1.m_B << endl;//对象实例访问
		cout << "BaseClass22_static int m_B = \t" << c1.BaseClass22::m_B << endl;//对象实例访问
		cout << "Class22_static int m_B = \t" << Class22::m_B << endl;//类名访问
		cout << "BaseClass22_static int m_B = \t" << Class22::BaseClass22::m_B << endl;//类名访问

		//访问静态成员函数
		c1.fun1();
		c1.BaseClass22::fun1();
		Class22::fun1();
		Class22::BaseClass22::fun1();
		//c1.fun1(100);//报错，子类中有同名成员函数时，会隐藏父类中所有的同名成员函数
		//Class22::fun1(100);//报错，子类中有同名成员函数时，会隐藏父类中所有的同名成员函数
		c1.BaseClass22::fun1(100);
		Class22::BaseClass22::fun1(100);
	}


	//多继承
	class BaseClass23
	{
	public:
		int m_A;
		BaseClass23()
		{
			cout << "BaseClass23构造函数" << endl;
			m_A = 100;
		}
		~BaseClass23()
		{
			cout << "BaseClass23析构函数" << endl;
		}
	};
	class BaseClass23_1
	{
	public:
		int m_A;
		BaseClass23_1()
		{
			cout << "BaseClass23_1构造函数" << endl;
			m_A = 200;
		}
		~BaseClass23_1()
		{
			cout << "BaseClass23_1析构函数" << endl;
		}
	};
	class Class23:public BaseClass23,public BaseClass23_1
	{
	public:
		int m_A;
		Class23()
		{
			cout << "Class23构造函数" << endl;
			m_A = 300;
		}
		~Class23()
		{
			cout << "Class23析构函数" << endl;
		}
	};

	void fun23()
	{
		cout << "\n\nTest_fun23" << endl;
		Class23 c1;
		cout << c1.m_A << endl;
		cout << c1.BaseClass23::m_A << endl;
		cout << c1.BaseClass23_1::m_A << endl;
	}


	//虚继承
	class BaseClass24
	{
	public :
		int m_A;
		BaseClass24(int a) :m_A(a) {
			cout << "BaseClass24构造函数" << endl;
		}
		~BaseClass24()
		{
			cout << "BaseClass24析构函数" << endl;
		}
	};
	class BaseClass24_1 :public BaseClass24//普通继承
	{
	public:
		BaseClass24_1(int a):BaseClass24(a)
		{
			cout << "BaseClass24_1构造函数" << endl;
		}
		~BaseClass24_1()
		{
			cout << "BaseClass24_1析构函数" << endl;
		}
	};
	class BaseClass24_2 :public BaseClass24//普通继承
	{
	public:
		BaseClass24_2(int a) :BaseClass24(a)
		{
			cout << "BaseClass24_2构造函数" << endl;
		}
		~BaseClass24_2()
		{
			cout << "BaseClass24_2析构函数" << endl;
		}
	};
	class Class24:public BaseClass24_1,public BaseClass24_2
	{
	public:
		Class24(int a):BaseClass24_1(a), BaseClass24_2(a)
		{
			cout << "Class24构造函数" << endl;
		}
		~Class24()
		{
			cout << "Class24析构函数" << endl;
		}
	};

	class BaseClass24_3 :virtual public BaseClass24//虚继承
	{
	public:
		BaseClass24_3(int a) :BaseClass24(a)
		{
			cout << "BaseClass24_3构造函数" << endl;
		}
		~BaseClass24_3()
		{
			cout << "BaseClass24_3析构函数" << endl;
		}
	};
	class BaseClass24_4 :virtual public BaseClass24//虚继承
	{
	public:
		BaseClass24_4(int a) :BaseClass24(a)
		{
			cout << "BaseClass24_4构造函数" << endl;
		}
		~BaseClass24_4()
		{
			cout << "BaseClass24_4析构函数" << endl;
		}
	};
	class Class24_1 :public BaseClass24_3, public BaseClass24_4
	{
	public:
		Class24_1(int a) :BaseClass24(a), BaseClass24_3(a), BaseClass24_4(a)//虚基类的构造函数须由最终的派生类直接调用
		{
			cout << "Class24_1构造函数" << endl;
		}
		~Class24_1()
		{
			cout << "Class24_1析构函数" << endl;
		}
	};

	void fun24()
	{
		cout << "\n\nTest_fun24" << endl;
		Class24 c1(10);
		//c1.m_A;//报错 二义，无法确定要访问哪个m_A
		cout << "\n" << c1.BaseClass24::m_A << endl;
		cout << c1.BaseClass24_1::m_A << endl;
		cout << c1.BaseClass24_2::m_A << endl;
		cout << &c1.BaseClass24::m_A << endl;
		cout << &c1.BaseClass24_1::m_A << endl;
		cout << &c1.BaseClass24_2::m_A << endl;
		cout << "sizeof Class24 = \t" << sizeof(Class24) << endl;
		cout << endl;

		Class24_1 c2(20);
		cout << endl;
		cout << c2.m_A << endl;
		cout<< c2.BaseClass24::m_A << endl;
		cout << c2.BaseClass24_3::m_A << endl;
		cout << c2.BaseClass24_4::m_A << endl;
		cout << &c2.m_A << endl;
		cout << &c2.BaseClass24::m_A << endl;
		cout << &c2.BaseClass24_3::m_A << endl;
		cout << &c2.BaseClass24_4::m_A << endl;
		cout << "sizeof Class24_1 = \t" << sizeof(Class24_1) << endl;
		cout << endl;

		cout << "sizeof BaseClass24_3 = \t" << sizeof(BaseClass24_3) << endl;
		cout << "sizeof BaseClass24_1 = \t" << sizeof(BaseClass24_1) << endl;
		cout << endl;

	}

	//虚继承其他测试
	class Class25
	{
	public:
		int m_A;
		int m_B;
		Class25(int a) :m_A(a) {}
	};
	class Class25_1:public Class25
	{ 
	public:
		Class25_1(int a):Class25(a) {}
	};
	class Class25_2:virtual public Class25
	{ 
	public:
		Class25_2(int a) :Class25(a) {}
	};
	class Class25_3 :public Class25_2
	{
	public:
		Class25_3(int a):Class25(a), Class25_2(a){}
	};
	void fun25()
	{
		cout << "\n\nTest_fun25" << endl;
		cout << "sizeof Class25_1 " << sizeof(Class25_1) << endl;//4--int4
		cout << "sizeof Class25_2 " << sizeof(Class25_2) << endl;//16 -- 指针8+int4，且内存对齐，对齐后为16
		cout << "sizeof Class25_2::m_A " << sizeof(Class25_2::m_A) << endl;//4--int4
		cout << endl;

		Class25_2 c1(10);
		cout << c1.m_A << endl;
		cout << c1.Class25_2::m_A << endl;
		cout << c1.Class25::m_A << endl;
		cout << &c1.m_A << endl;
		cout << &c1.Class25_2::m_A << endl;
		cout << &c1.Class25::m_A << endl;
		cout << endl;

		Class25_1 c2(20);
		cout << c2.m_A << endl;
		cout << c2.Class25_1::m_A << endl;
		cout << c2.Class25::m_A << endl;
		cout << &c2.m_A << endl;
		cout << &c2.Class25_1::m_A << endl;
		cout << &c2.Class25::m_A << endl;
		cout << endl;

		Class25_3 c3(30);
		cout << c3.m_A << endl;
		cout << c3.Class25_2::m_A << endl;
		cout << c3.Class25::m_A << endl;
		cout << &c3.m_A << endl;
		cout << &c3.Class25_2::m_A << endl;
		cout << &c3.Class25::m_A << endl;
		cout << endl;

	}
}

//继承相关测试
void testInherit()
{
	//定义类的时候，如果下一级成员除了拥有上一级的共性，还有自己的特性，可以考虑使用继承，可以减少代码重复
	// 语法：class 子类名称 : 继承方式(public、protected、private) 父类名称
	// 父类也称为基类
	// 子类也称为派生类
	// 
	// 继承方式相关
	// 1、公共继承public
	//	会继承父类中所有访问权限下的内容
	//	原来的访问权限在子类中不会发生改变
	//	无法访问权限为私有权限private的内容
	// 2、保护继承protected
	//	会继承父类中所有访问权限下的内容
	// 	原来的访问权限在子类中全部设置为保护权限protected
	//	无法访问权限为私有权限private的内容
	// 3、私有继承private
	//	会继承父类中所有访问权限下的内容
	// 	原来的访问权限在子类中全部设置为私有权限private
	// 	无法访问权限为私有权限private的内容
	// 子类的子类仍然会继承父类中的所有内容，哪怕是private权限下无法访问的内容
	// 
	// 如果省略继承方式，对于类（class），默认是 private 继承；
	// 对于结构体（struct），默认是 public 继承。
	// 

	fun20();



	// 继承中构造和析构的顺序
	// 先构造父类，后构造子类  析构顺序相反，先析构子类，后析构父类
	// 在实例化子类对象时，父类的构造函数会被调用；子类对象释放时，父类的析构函数会被调用
	// 在多重继承的情况下，子类会依次调用所有父类的构造函数，按照继承声明的顺序调用。
	// 先按照继承声明的顺序构造父类，后构造子类  析构顺序相反
	// 
	// 在 C++ 中，对象的初始化顺序是严格的：
	// 1、首先调用父类的构造函数。
	// 2、然后初始化子类的成员变量。
	// 3、最后执行子类的构造函数体。
	fun21();



	//继承中同名成员的处理方式
	// 当继承时子类与父类中有同名的成员
	// 在子类中访问子类中的同名成员，直接访问即可
	// 在子类中访问父类的同名成员，需要加作用域 (语法：子类对象.父类名称::父类成员)
	// 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数(即所有的重载也只能通过作用域调用)
	// 普通成员变量或成员函数，和静态成员变量或静态成员函数，子类和父类同名时访问规则是一样的
	//

	fun22();


	//多继承
	// 在多重继承的情况下，子类会依次调用所有父类的构造函数，按照继承声明的顺序调用。
	// 先按照继承声明的顺序构造父类，后构造子类  析构顺序相反
	fun23();


	//虚继承
	// 虚继承（Virtual Inheritance）是 C++ 中一种特殊的继承方式，用于解决多重继承中的“菱形继承问题”（Diamond Problem）。通过虚继承，可以确保派生类中只有一个基类子对象，从而避免重复继承带来的数据冗余和二义性问题。
	// 语法：class 子类名: virtual 继承方式 父类名
	// 在虚继承的情况下，编译器会在派生类中生成一个指向虚基类的指针（通常称为虚基类表指针或 vbptr），用于管理虚基类的实例。
	// 该指针会指向虚基类表，表中记录了一个偏移量，该指针的位置加上虚基类表中的偏移量，所指向的位置就是派生类继承基类的变量的位置
	// 这样，即使派生类有多个路径继承自同一个基类，也只会创建一个基类的实例。
	// 当创建一个派生类对象时，虚基类的构造函数必须由最终的派生类直接调用，且只会调用一次，而不是由中间类调用。
	// 构造顺序
	// 首先调用虚基类的构造函数，然后依次调用其他基类的构造函数。
	// 析构顺序与构造顺序相反
	// 查看类的内存结构图：cl /d1 reportSingleClassLayout类名 "文件名"
	// 
	/*
	class `anonymous-namespace'::Class24_1  size(12):
			+---
	 0      | +--- (base class `anonymous-namespace'::BaseClass24_3)
	 0      | | {vbptr}//该指针偏移量为8，0+8即为m_A的位置
			| +---
	 4      | +--- (base class `anonymous-namespace'::BaseClass24_4)
	 4      | | {vbptr}//该指针偏移量为4，4+4即为m_A的位置
			| +---
			+---
			+--- (virtual base `anonymous-namespace'::BaseClass24)
	 8      | m_A
			+---

	`anonymous-namespace'::Class24_1::$vbtable@BaseClass24_3@:
	 0      | 0
	 1      | 8 (Class24_1d(BaseClass24_3+0)BaseClass24)

	`anonymous-namespace'::Class24_1::$vbtable@BaseClass24_4@:
	 0      | 0
	 1      | 4 (Class24_1d(BaseClass24_4+0)BaseClass24)
	*/

	//测试访问父类、中间类、子类的变量，测试默认构造函数，测试构造和析构顺序，测试查看子类、单独的中间类内存结构
	fun24();
	fun25();
}

