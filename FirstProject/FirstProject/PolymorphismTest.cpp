#include "PolymorphismTest.h"


namespace {
	//多态实现和调用
	class BaseClass1
	{
	public:
		virtual void print()
		{
			cout << "BaseClass1" << endl;
		}
	};
	class Class1 :public BaseClass1
	{
	public:
		void print()//重写父类的虚函数 重写(函数的返回值类型、函数名、参数列表 完全相同 )
		{
			cout << "Class1" << endl;
		}
	};
	class Class1_1 :public BaseClass1
	{
	public:
		void print()
		{
			cout << "Class2" << endl;
		}
	};
	void fun1_1(BaseClass1& c)
	{
		c.print();
	}
	void fun1()
	{
		cout << "\n\nTest_fun1" << endl;
		BaseClass1* c1 = new Class1();
		BaseClass1* c2 = new Class1_1();
		
		c1->print();
		c2->print();
		Class1 c3;
		Class1_1 c4;
		fun1_1(c3);
		fun1_1(c4);

		BaseClass1& c5 = c3;
		c5.print();


		delete c1;
		delete c2;
	}


	//一些虚函数实现相关的测试
	class BaseClass2
	{
	public:
		virtual void PFun()
		{
			cout << "BaseClass2" << endl;
		}
	};
	class Class2 :public BaseClass2
	{

	};
	void fun2()
	{
		cout << "\n\nTest_fun2" << endl;
		Class2 c1;
		c1.PFun();
	}
	class BaseClass3
	{
	public:
		virtual void PFun()
		{
			cout << "BaseClass3" << endl;
		}
	};
	class Class3:public BaseClass3 {};
	void fun3_1(BaseClass3& c)
	{
		c.PFun();
	}
	void fun3()
	{
		cout << "\n\nTest_fun3" << endl;
		Class3 c1;
		fun3_1(c1);
	}


	//案例：多态实现计算机类
	class AbstractCalculator
	{
	public:
		int m_Num1;
		int m_Num2;

		virtual int getResult() { return -1; }
	};
	class SumCalculator:public AbstractCalculator
	{
	public:
		int getResult()
		{
			return m_Num1 + m_Num2;
		}
	};
	class SubCalculator :public AbstractCalculator
	{
	public:
		int getResult()
		{
			return m_Num1 - m_Num2;
		}
	};
	class MulCalculator :public AbstractCalculator
	{
	public:
		int getResult()
		{
			return m_Num1 * m_Num2;
		}
	};
	void fun4()
	{
		cout << "\n\nTest_fun4" << endl;
		AbstractCalculator* pCal = new SumCalculator();
		pCal->m_Num1 = 10;
		pCal->m_Num2 = 10;
		cout << pCal->getResult() << endl;

		delete pCal;
		pCal = new SubCalculator();
		pCal->m_Num1 = 10;
		pCal->m_Num2 = 10;
		cout << pCal->getResult() << endl;

		delete pCal;
		pCal = new MulCalculator();
		pCal->m_Num1 = 10;
		pCal->m_Num2 = 10;
		cout << pCal->getResult() << endl;

		delete pCal;
	}


	//纯虚函数和抽象类
	class BaseClass5
	{
	public:
		virtual void fun() = 0;//定义纯虚函数
	};
	class Class5 :public BaseClass5
	{

	};
	class Class5_1 :public BaseClass5
	{
	public:
		void fun()
		{
			cout << "Class5_1" << endl;
		}
	};
	void fun5()
	{
		cout << "\n\nTest_fun5" << endl;
		//BaseClass5 c1;//报错//类中包含纯虚函数，该类不能直接实例化对象
		//BaseClass5* c2 = new BaseClass5();//报错//类中包含纯虚函数，该类不能直接实例化对象
		//Class5 c1;//报错//未重写父类纯虚函数，也是抽象类，无法实例化对象
		//Class5* c2 = new Class5();//报错//未重写父类纯虚函数，也是抽象类，无法实例化对象
		Class5_1 c1;
		c1.fun();//静态调用
		BaseClass5* c2 = &c1;
		c2->fun();//动态调用
	}


	//案例：制作饮品
	class AbstractMakeDrink
	{
	public:
		virtual void fun1() = 0;//煮水
		virtual void fun2() = 0;//冲泡
		virtual void fun3() = 0;//倒入杯中
		virtual void fun4() = 0;//加入辅料
		void fun5()//执行制作的所有步骤
		{
			fun1();
			fun2();
			fun3();
			fun4();
		}
	};
	class MakeCoffee:public AbstractMakeDrink
	{
	public:
		void fun1()
		{
			cout << "煮水" << endl;
		}
		void fun2()
		{
			cout << "冲泡咖啡" << endl;
		}
		void fun3()
		{
			cout << "倒入杯中" << endl;
		}
		void fun4()
		{
			cout << "加入牛奶和糖" << endl;
		}
	};
	class MakeTea :public AbstractMakeDrink
	{
	public:
		void fun1()
		{
			cout << "煮水" << endl;
		}
		void fun2()
		{
			cout << "冲泡茶叶" << endl;
		}
		void fun3()
		{
			cout << "倒入杯中" << endl;
		}
		void fun4()
		{
			cout << "加入辅料" << endl;
		}
	};
	void fun6()
	{
		cout << "\n\nTest_fun6" << endl;
		MakeCoffee c1;
		MakeTea c2;
		AbstractMakeDrink* cP1 = &c1;
		AbstractMakeDrink* cP2 = &c2;
		cP1->fun5();
		cP2->fun5();


	}


	//杂项测试
	class AbstractClass7
	{
	public:
		virtual void fun1() = 0;
		void fun2()
		{
			cout << this << endl;
			cout << "AbstractClass7_fun2" << endl;
			fun1();
		}
	};
	class Class7 :public AbstractClass7
	{
	public:
		void fun1()
		{
			cout << this << endl;
			cout << "fun1" << endl;
		}
		void fun2()
		{
			cout << "Class7_fun2" << endl;//不会被调用
		}
	};
	void fun7()
	{
		cout << "\n\nTest_fun7" << endl;
		AbstractClass7* cP = new Class7();
		cout << cP << endl;
		cP->fun2();	//调用fun2时，没有涉及虚函数，是直接静态调用了AbstractClass7::fun2
					//调用fun1时，通过this指针，虚函数指针和虚函数表，找到对应的函数进行调用，调用的是Class7::fun1
		//其实实际上没有实现多态的话，只会调用静态类型中对应的函数
		//Class7中的fun2不会被调用，因为cP的静态类型是AbstractClass7*，会直接调用AbstractClass7::fun2
		//只有通过实现多态的方式，才会调用到Class7中的fun2

		delete cP;
	}


	//虚析构和纯虚析构
	class BaseClass8
	{
	public:
		BaseClass8()
		{
			cout << "BaseClass8构造" << endl;
		}
		~BaseClass8()
		{
			cout << "BaseClass8析构" << endl;
		}
		virtual void fun()
		{

		}
	};
	class Class8:public BaseClass8
	{
	public:
		Class8()
		{
			cout << "Class8构造" << endl;
		}
		~Class8()
		{
			cout << "Class8析构" << endl;
		}
		void fun()
		{

		}
	};
	class BaseClass8_1
	{
	public:
		BaseClass8_1()
		{
			cout << "BaseClass8_1构造" << endl;
		}
		//virtual ~BaseClass8_1()//虚析构
		//{
		//	cout << "BaseClass8_1析构" << endl;
		//}
		virtual void fun()
		{

		}
		virtual ~BaseClass8_1() = 0;//纯虚析构
	};
	BaseClass8_1::~BaseClass8_1()
	{
		cout << "BaseClass8_1析构" << endl;
	}
	class Class8_1 :public BaseClass8_1
	{
	public:
		Class8_1()
		{
			cout << "Class8_1构造" << endl;
		}
		~Class8_1()
		{
			cout << "Class8_1析构" << endl;
		}
		void fun()
		{

		}
	};
	void fun8_1(BaseClass8& c)
	{
		cout << "fun8_1" << endl;
	}
	void fun8_2(BaseClass8* c)
	{
		delete c;//释放父类指针时，不会调用到子类的析构函数
		cout << "fun8_2" << endl;
	}
	void fun8()
	{
		cout << "\n\nTest_fun8" << endl;
		//Class8 c1;
		//fun8_1(c1);//引用方式实现多态，必须有一个初始变量？初始变量会在函数结束后自动释放

		//fun8_2(new Class8());//此时传了一个匿名对象，函数参数指针指向了该对象，此时需要在函数内手动释放该匿名对象

		BaseClass8_1* cP = new Class8_1();
		delete cP;


	}


	//案例
	class AbstractCPU
	{
	public:
		virtual void work() = 0;
	};
	class AbstractGPU
	{
	public:
		virtual void work() = 0;
	};
	class AbstractMemory
	{
	public:
		virtual void work() = 0;
	};
	class IntelCPU:public AbstractCPU
	{
	public:
		void work()
		{
			cout << "IntelCPU work" << endl;
		}
	};
	class IntelGPU :public AbstractGPU
	{
	public:
		void work()
		{
			cout << "IntelGPU work" << endl;
		}
	};
	class IntelMemory :public AbstractMemory
	{
	public:
		void work()
		{
			cout << "IntelMemory work" << endl;
		}
	};
	class AMDCPU :public AbstractCPU
	{
	public:
		void work()
		{
			cout << "AMDCPU work" << endl;
		}
	};
	class AMDGPU :public AbstractGPU
	{
	public:
		void work()
		{
			cout << "AMDGPU work" << endl;
		}
	};
	class AMDMemory :public AbstractMemory
	{
	public:
		void work()
		{
			cout << "AMDMemory work" << endl;
		}
	};
	class Computer
	{
	public:
		AbstractCPU* cup;
		AbstractGPU* gup;
		AbstractMemory* memory;
		void work()
		{
			cup->work();
			gup->work();
			memory->work();
		}
	};

	void fun9()
	{
		cout << "\n\nTest_fun9" << endl;
		IntelCPU cpu1;
		IntelGPU gpu1;
		IntelMemory memory1;
		AMDCPU cpu2;
		AMDGPU gpu2;
		AMDMemory memory2;

		Computer c1;
		c1.cup = &cpu1;
		c1.gup = &gpu1;
		c1.memory = &memory1;

		Computer c2;
		c2.cup = &cpu2;
		c2.gup = &gpu2;
		c2.memory = &memory2;

		c1.work();
		c2.work();


	}
}




void testPolymorphism()
{
	//多态
	// 在 C++ 中，多态（Polymorphism） 是面向对象编程的核心特性之一。它允许程序根据对象的实际类型调用相应的方法，从而实现更灵活和可扩展的代码设计。
	// 分类：
	// 静态多态：函数重载和运算符重载
	// 动态多态：派生类和虚函数实现运行时多态
	// 区别：
	// 静态多态的函数地址早绑定--编译阶段确定函数地址
	// 动态多态的函数地址晚绑定--运行阶段确定函数地址
	// 
	// 动态多态的满足条件
	// 1、有继承关系
	// 2、子类重写父类的虚函数 (重写：函数的返回值类型、函数名、参数列表 完全相同)
	// 
	// 动态多态的使用
	// 父类的指针或引用 指向子类对象 
	// 
	// 多态的好处：
	// 1、组织结构清晰
	// 2、可读性强
	// 3、对于前期和后期扩展以及维护性高
	// 
	// 多态详细实现原理：
	// 静态绑定： 普通函数或普通成员函数在编译时就已经确定了函数调用的目标地址
	// 动态绑定： 在运行时根据对象的实际类型确定函数调用的目标地址
	// 主要是通过父类定义虚函数和子类重写虚函数，再通过父类指针或引用调用虚函数，此时发生了多态，会在运行时根据对象的实际类型确定函数调用的目标地址
	// 虚函数指针（vfptr）：
	//	定义：每个包含虚函数的对象中都会有一个隐藏的成员变量，称为虚函数指针（vptr）。
	//	作用：虚函数指针指向该对象所属类的虚函数表。
	//	初始化：在对象构造时，编译器会将 vptr 初始化为指向该对象所属类的虚函数表。(同一个类的不同实例会生成不同的虚函数指针，但指向的是同一个虚函数表)
	// 虚函数表（vftable）：
	//	定义：每个包含虚函数的类都有一个虚函数表（vtable），它是一个静态数组，存储了该类及其父类的所有虚函数的地址。
	//	生成时机：编译器在编译时为每个包含虚函数的类生成一个虚函数表。
	//	内容：
	//	如果派生类重写了某个虚函数，则派生类的虚函数表中对应位置的函数地址会被替换为派生类的实现。
	//	如果派生类没有重写某个虚函数，则继承基类的虚函数地址。
	// 以fun1中实现的多态为例：
	//	BaseClass1类中有定义虚函数，此时该类中会隐式生成一个vfptr，该指针指向vftable，虚函数表中记录了虚函数的地址 &BaseClass1::print
	//	Class1类继承自BaseClass1类，在类中也会有一个vfptr，指向自己的vftable(注：与父类的虚函数表不是同一个)，
	//	同时在虚函数表中继承了一个虚函数的地址 &BaseClass1::print，当在Class1类中重写了父类的虚函数后，虚函数表中的虚函数的地址会被重写的函数覆盖掉，
	//	即替换成 &Class1::print，当使用父类的指针或引用指向子类对象的方式调用虚函数时，会根据实例中的虚函数指针找到虚函数表，调用对应的函数，此时实现了函数的动态调用，实现了多态
	// 
	// 
	// 
	// 静态类型和动态类型
	// 静态类型：
	//	定义
	//	静态类型 是指变量或表达式在编译时确定的类型。
	//	它是编译器根据代码中声明的类型推导出来的。
	//	特点
	//	静态类型由变量的声明决定，与运行时的对象无关。
	//	编译器在编译阶段就已经知道每个变量的静态类型。
	//	静态类型决定了哪些函数和操作可以在该变量上执行。
	//	示例：Base* b = new Derived(); 
	//	b 的静态类型是 Base*，因为它是声明为 Base* 类型的指针。
	//	编译器会根据 Base 类的定义来检查 b 上的操作是否合法。
	// 动态类型：
	//	定义
	//	动态类型 是指变量或表达式在运行时实际指向的对象的类型。
	//	它是由程序在运行时创建的对象的实际类型决定的。
	//	特点
	//	动态类型只有在运行时才能确定。
	//	动态类型决定了通过基类指针或引用调用虚函数时，实际调用的是哪个函数实现。
	//	动态类型通常出现在涉及多态性的场景中。
	//	示例：	Base* b = new Derived();	
	//			b->show(); 
	//	b 的静态类型是 Base*
	//	b 的动态类型是 Derived*，因为 b 实际指向的是一个 Derived 对象。
	//	调用 b->show() 时，实际调用的是 Derived::show()，因为动态类型决定了调用的具体实现。
	// 
	// 即使父类中有虚函数，子类继承父类时继承了虚函数指针，指向了虚函数表，但是如果不是使用父类指针或引用指向子类对象的方式，
	// 进行动态绑定，直接调用虚函数，即静态绑定的方式进行调用，实际上并不会通过虚函数指针和虚函数表去查找和调用函数，
	// 而是会直接调用对应类作用域下的对应函数，例：fun2示例中c1.PFun();，实际是直接调用了c1.BaseClass2::PFun();
	// 而例fun3中fun3_1函数通过父类引用指向子类对象的方式进行虚函数的调用，会通过虚函数指针和虚函数表实现函数的调用
	// 
	// 

	fun1();
	fun2();
	fun3();


	fun4();



	//纯虚函数和抽象类
	// 纯虚函数
	// 定义：纯虚函数 是一种特殊的虚函数，它没有具体的实现，仅在基类中声明。(主要用于定义接口)
	// 语法：virtual 返回值类型 函数名 (参数列表) = 0;  例：virtual void fun() = 0;
	// 特点：
	//	1、无实现：纯虚函数没有函数体，只有声明。
	//	2、强制性：如果一个类包含纯虚函数，则该类不能直接实例化对象。
	//	3、派生类的责任：派生类必须实现纯虚函数（除非派生类本身也是抽象类）。
	// 当类中有了纯虚函数，这个类被称为抽象类
	// 
	// 抽象类
	// 定义：
	//	抽象类 是包含至少一个纯虚函数的类。
	//	抽象类的主要目的是定义一个通用的接口，供派生类实现。
	// 特点：
	//	1、不可实例化：抽象类不能直接创建对象。
	//	2、作为基类：抽象类通常用作基类，派生类通过实现纯虚函数来完成具体的功能。
	//	3、部分实现：抽象类可以包含普通成员函数和数据成员，这些成员可以直接使用或继承。
	// 
	// 抽象类的作用：
	// 1、定义通用接口
	//	抽象类定义了一组通用的接口，要求所有派生类实现这些接口。
	//	这种方式非常适合用于设计框架或库，用户可以根据需要扩展功能。
	// 2、多态性支持
	//	抽象类是实现运行时多态性的基础。
	//	通过基类指针或引用调用纯虚函数，程序可以在运行时根据实际对象的类型调用对应的实现。
	// 
	//

	fun5();



	fun6();


	fun7();


	//虚析构和纯虚析构
	// 释放父类指针时，是不会调用到子类的析构函数的，如果是通过父类指针指向子类的方式实现多态
	// ，如果子类中有属性开辟到堆区，不使用虚析构，会导致内存泄露
	// 虚析构和纯虚析构确保通过基类指针删除派生类对象时，能够正确调用派生类的析构函数，从而避免资源泄漏。
	//
	// 虚析构：
	// 语法：virutal ~类名(){}
	// 
	// 纯虚析构：
	// 语法：virutal ~类名() = 0;//类内声明
	//		类名::~类名(){}//类外定义
	// 如果类中有纯虚析构，该类属于抽象类，是不能实例化对象的
	// 一个类中虚析构和纯虚析构只能有一个
	// 
	//验证一下引用方式实现多态，子类何时被析构

	fun8();




	fun9();

}



