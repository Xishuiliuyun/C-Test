#include "TemplateTest.h"
#include "TemplateFileTest.hpp"
#include "TemplateFileTest.h"
#include "TemplateFileTest.cpp"
#include "MyclassTest.hpp"


namespace
{
	template<typename T>
	T fun1_1(T& a, T& b)
	{
		T temp;
		temp = a;
		a = b;
		b = temp;
		return temp;
	}
	//T fun1_2() {}//报错 T未定义标识符 //模板定义和模板参数只可以用在紧随其后的模板
	template<typename T1, typename T2>
	void fun1_3(T1 a, T2 b) {}

	template <typename T>
	void fun1_4()
	{
		cout << "fun1_4_Test" << endl;
	}

	void fun1()
	{
		cout << "\n\nTest_fun1" << endl;
		int a = 10;
		int b = 20;
		fun1_1(a, b);
		cout << a << endl;
		cout << b << endl;

		float c = 1.1f;
		float d = 2.2f;
		fun1_1<float>(c, d);
		cout << c << endl;
		cout << d << endl;


		char f = 'a';
		//fun1_1(a, f);//报错 //自动类型推导，必须推导出一致的数据类型T才可以使用
		//fun1_4();//报错 //模板必须要确定出T的数据类型，才可以使用
		fun1_4<int>();

	}


	//案例
	template<typename T>
	void fun2_1(T arr[],int len)
	{
		for (int i = 0;i < len;i++)
		{
			int maxIndex = i;
			for (int j = i+1;j < len;j++)
			{
				if (arr[maxIndex] < arr[j])
				{
					maxIndex = j;
				}
			}
			if (maxIndex != i)
			{
				T temp = arr[i];
				arr[i] = arr[maxIndex];
				arr[maxIndex] = temp;
			}
		}
	}
	template<typename T>
	void fun2_2(T arr[],int len)
	{
		for (int i = 0;i < len;i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void fun2()
	{
		cout << "\n\nTest_fun2" << endl;
		int arr1[10] = { 0,222,5,6,1,8,9,1,11,33 };
		char arr2[8] = { '7','5','6','3','5','9','5','1' };

		fun2_2(arr1, sizeof(arr1)/sizeof(arr1[0]));
		fun2_2<char>(arr2, sizeof(arr2) / sizeof(arr2[0]));

		fun2_1<int>(arr1, sizeof(arr1) / sizeof(arr1[0]));
		fun2_1(arr2, sizeof(arr2) / sizeof(arr2[0]));

		fun2_2(arr1, sizeof(arr1) / sizeof(arr1[0]));
		fun2_2<char>(arr2, sizeof(arr2) / sizeof(arr2[0]));

	}


	//普通函数和模板函数的区别
	int fun3_1(int a,int b)
	{
		return a + b;
	}
	template<typename T>
	T fun3_2(T a, T b)
	{
		return a + b;
	}
	void fun3()
	{
		cout << "\n\nTest_fun3" << endl;
		int a = 10;
		int b = 20;
		char c = 'a';

		cout << fun3_1(a, c) << endl;
		//cout << fun3_2(a, c) << endl;//报错//自动类型推导，不会发生隐式类型转换
		cout << fun3_2<int>(a, c) << endl;//显示指定类型的方式调用模板，可以发生隐式类型转换
	}


	//普通函数和模板函数的调用规则
	void fun4_1(int a,int b)
	{
		cout << "fun4_1 called" << endl;
	}
	template<typename T>
	void fun4_1(T a, T b)
	{
		cout << "template fun4_1 called" << endl;
	}
	template<typename T>
	void fun4_1(T a, T b,T c)
	{
		cout << "template fun4_1 called" << endl;
	}
	void fun4()
	{
		cout << "\n\nTest_fun4" << endl;
		int a = 10;
		int b = 20;
		char c = 'a';
		char d = 'b';
		fun4_1(a, b);//如果函数模板和普通函数都可以实现，优先调用普通函数
		fun4_1<>(a, b);//可以通过空模板参数列表来强制调用函数模板
		fun4_1(a, b, a);//函数模板也可以发生重载
		fun4_1(c, d);//如果函数模板可以产生更好的匹配，优先调用函数模板


	}


	//函数模板特化
	//尝试多模板参数的特化
	class Class5
	{
	public:
		string m_Str;
		int m_Num;
		Class5(string str, int num):m_Str(str),m_Num(num) {}

	};
	class Class5_1
	{
	public:
		string m_Str;
		int m_Num;
		Class5_1(string str, int num) :m_Str(str), m_Num(num) {}

	};
	template<typename T>
	bool fun5_1(T a, T b)
	{
		return a == b;
	}
	template<>
	bool fun5_1(int a,int b)
	{
		cout << "fun5_1模板全特化" << endl;
		return a == b;
	}
	template<>
	bool fun5_1/*<Class5_1>*/(Class5_1 a, Class5_1 b)
	{
		if (a.m_Str == b.m_Str && a.m_Num == b.m_Num)
		{
			return true;
		}
		else return false;
	}
	template<typename T1,typename T2>
	void fun5_2(T1 a,T2 b)
	{
		cout << "fun5_2模板" << a << b << endl;
	}
	template<typename T1>
	void fun5_2(T1 a, int b)//其实是函数重载
	{
		cout << "fun5_2偏特化?" << a << b << endl;
	}
	/*template<>//报错//单独的模板函数，不可以在模板参数列表中置空//template<>一般表示模板特化
	void fun5_3()
	{
		cout << "here" << endl;
	}*/
	void fun5()
	{
		cout << "\n\nTest_fun5" << endl;
		int a = 10;
		int b = 10;
		cout << fun5_1(a, b) << endl;//特化int类型版本后，该特化版本会被优先调用

		Class5 c1("xiaoming", 12);
		Class5 c2("xiaoming", 12);
		//cout << fun5_1(c1, c2) << endl;//报错//Class5类没有==运算符的实现，无法进行a == b判断，可通过Class5类中重载==运算符解决
		Class5_1 c3("xiaoming", 12);
		Class5_1 c4("xiaoming", 12);
		cout << fun5_1(c3, c4) << endl;//模板全特化后，可以正常运行

		fun5_2("str1", 'a');
		fun5_2("str2", 10);
	}


	//类模板
	template<typename T>
	class Class6
	{
	public:
		T m_Value;
		Class6(T val) :m_Value(val) {}
		T show()
		{
			return m_Value;
		}
	};
	template<typename T1, typename T2 = int>
	class Class6_1
	{
	public:
		T1 m_Val1;
		T2 m_Val2;
		Class6_1(T1 val1,T2 val2):m_Val1(val1),m_Val2(val2){}
		void show()
		{
			cout << m_Val1 << "\n" << m_Val2 << endl;
		}
	};
	
	void fun6()
	{
		cout << "\n\nTest_fun6" << endl;
		Class6<int> c1(10);
		cout << c1.show() << endl;

		//Class6_1 c3("str", 100);//报错，没有自动类型推导
		Class6_1<string> c2("str", 100);
		c2.show();
	}


	//类模板中成员函数的创建时机
	class Class7_1
	{
	public:
		void show1()
		{
			cout << "Class7_1" << endl;
		}
	};
	class Class7_2
	{
	public:
		void show2()
		{
			cout << "Class7_2" << endl;
		}
	};
	template<typename T>
	class Class7
	{
	public:
		T obj;
		void show1()
		{
			obj.show1();
		}
		void show2()
		{
			obj.show2();
		}
	};

	//类模板显式实例化
	template class Class6_1<string, int>;
	//类模板显式实例化时，所有成员函数都会被实例化
	//template class Class7<Class7_1>;//报错，类模板显式实例化时，所有成员函数都会被实例化
	
	void fun7()
	{
		cout << "\n\nTest_fun7" << endl;
		//类模板中的成员函数在调用时才创建
		//Class7中的show2函数在调用前没创建，所以即使obj中没有show2函数也不会报错
		Class7<Class7_1> c1;
		c1.show1();
		//c1.show2();//报错Class7_1类型的c1中没有show2函数
	}


	//类模板对象做函数参数
	template<typename T1,typename T2>
	class Class8
	{
	public:
		T1 m_Val1;
		T2 m_Val2;
		Class8(T1 val1,T2 val2)
		{
			m_Val1 = val1;
			m_Val2 = val2;
		}
		void show()
		{
			cout << m_Val1 << "\n" << m_Val2 << endl;
		}
	};
	//1、指定传入的类型
	void fun8_1(Class8<string, int>& c)
	{
		c.show();
	}
	//2、参数模板化	
	template<typename T1, typename T2>
	void fun8_2(Class8<T1,T2>&c)
	{
		c.show();
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	//3、整个类模板化	
	template<typename T>
	void fun8_3(T& c)
	{
		c.show();
		cout << typeid(T).name() << endl;
	}
	void fun8()
	{
		cout << "\n\nTest_fun8" << endl;
		Class8<string, int> c1("str1", 10);
		fun8_1(c1);

		Class8<string, int> c2("str2", 20);
		fun8_2(c2);

		Class8<string, int> c3("str3", 30);
		fun8_3(c3);
	}


	//类模板和继承
	// 1. 普通类继承类模板
	template<typename T1,typename T2>
	class Class9
	{
	public:
		T1 m_Val1;
		T2 m_Val2;
		Class9(T1 val1, T2 val2)
		{
			m_Val1 = val1;
			m_Val2 = val2;
		}
		void show()
		{
			cout << m_Val1 << "\n" << m_Val2 << endl;
		}
	};
	//class Class9_1:public Class9 {};//报错//非模板继承类模板必须要指定模板参数的类型
	class Class9_2 :public Class9<string, int>
	{
	public:

	};
	class Class9_3 :public Class9<string, int>
	{
	public:
		Class9_3(string val1, int val2) :Class9::Class9(val1, val2) {}
	};
	//2. 类模板继承普通类
	class Class9_4
	{
	public:
		void show()
		{
			cout << "类模板继承普通类" << endl;
		}
	};
	template<typename T>
	class Class9_5 :public Class9_4
	{
	public:
		T m_Val;
		void fun()
		{
			show();//类模板继承普通类时，定义时可以正常调用成员函数
		}
	};
	// 3. 类模板继承类模板
	template<typename T1, typename T2>
	class Class9_6 :public Class9_4
	{
	public:
		T1 m_Val1;
		T2 m_Val2;
		void show2()
		{
			cout << m_Val1 << "\n" << m_Val2 << endl;
		}
	};
	template<typename T1, typename T2>
	class Class9_7 :public Class9_6<T1, T2>
	{
	public:
		Class9_7(T1 val1,T2 val2)
		{
			//m_Val1 = val1;//报错//不会自动查找基类中的名称，会导致变量未声明异常
			//m_Val2 = val2;//报错
			//	1、this指针显式指定
			this->m_Val1 = val1;
			this->m_Val2 = val2;
		}
		void fun()
		{
			//show();//报错//即使是继承自普通类的函数，也不能直接调用
			//	1、this指针显式指定
			this->show();
			this->show2();
		}
		
	};
	template<typename T1, typename T2>
	class Class9_8 :public Class9_6<T1, T2>
	{
	public:
		Class9_8(T1 val1, T2 val2)
		{
			//m_Val1 = val1;//报错//不会自动查找基类中的名称，会导致变量未声明异常
			//m_Val2 = val2;//报错
			//	2、使用基类名限定作用域
			Class9_6<T1, T2>::m_Val1 = val1;
			Class9_6<T1, T2>::m_Val2 = val2;
		}
		void fun()
		{
			//show();//报错//即使是继承自普通类的函数，也不能直接调用
			//	2、使用基类名限定作用域
			Class9_6<T1, T2>::show();
			Class9_6<T1, T2>::show2();
		}

	};
	template<typename T1, typename T2>
	class Class9_9 :public Class9_6<T1, T2>
	{
	public:
		using Class9_6<T1, T2>::m_Val1;
		using Class9_6<T1, T2>::m_Val2;
		using Class9_6<T1, T2>::show;
		using Class9_6<T1, T2>::show2;

		Class9_9(T1 val1, T2 val2)
		{
			//m_Val1 = val1;//报错//不会自动查找基类中的名称，会导致变量未声明异常
			//m_Val2 = val2;//报错
			//	3、使用using声明将基类成员引入子类作用域
			m_Val1 = val1;
			m_Val2 = val2;
		}
		void fun()
		{
			//show();//报错//即使是继承自普通类的函数，也不能直接调用
			//	3、使用using声明将基类成员引入子类作用域
			show();
			show2();
		}

	};
	//普通类测试
	class Class10
	{
	public:
		int a;
		string b;
		void fun()
		{
			a = 10;
			b = "123";
		}
	};
	class Class10_1 :public Class10
	{
	public:
		Class10_1(int c, string d)
		{
			a = c;//构造函数中可以正常调用父类中的成员
			b = d;
			fun();
		}
		void show()
		{
			cout << a << "\n" << b << endl;
		}
	};
	void fun10()
	{
		Class10_1 c1(10, "str");
		c1.show();
	}
	void fun9()
	{
		cout << "\n\nTest_fun9" << endl;
		//Class9_2 c1;//报错//父类模板没有默认构造函数，子类中需要在构造函数的初始化列表中显式调用父类的构造函数
		Class9_3 c2("str",10);
		c2.show();

		Class9_5<int> c3;
		c3.show();

		//1、this指针显式指定
		Class9_7<string, int> c4("str2",20);
		c4.fun();

		//2、使用基类名限定作用域
		Class9_8<int, string> c5(100, "str3");
		c5.fun();

		//3、使用using声明将基类成员引入子类作用域
		Class9_9<string, int> c6("str4", 1000);
		c6.fun();

		fun10();
	}


	
	//类模板成员函数的类外实现
	template<typename T>
	class Class11
	{
	public:
		using Type = T;
		Type m_Val;
		Class11(Type val);
		void fun();
	};
	template<typename T>
	Class11<T>::Class11(Type val)
	{
		m_Val = val;
	}
	template<typename T>
	void Class11<T>::fun()
	{
		cout << m_Val << "\n" << typeid(Type).name() << endl;
	}

	void fun11()
	{
		cout << "\n\nTest_fun11" << endl;
		Class11<int> c1(10);
		Class11<double> c2(100);
		Class11<string> c3("1000");
		c1.fun();
		c2.fun();
		c3.fun();

	}

	//类模板的分文件编写
	void fun12()
	{
		cout << "\n\nTest_fun12" << endl;
		templateFileTest::Class1<string, int> c1(".hpp.tpp实现分文件编写 测试", 9);
		c1.show();

		Class12<string, int> c2(".h.cpp和显式实例化实现分文件编写 测试", 99);
		c2.show();

		//未#include "TemplateFileTest.cpp"时报错，直接包含.cpp源文件后功能正常
		Class12_1<string, int> c3("直接包含.cpp源文件实现分文件编写 测试", 999);
		c3.show();

		templateFileTest::Class1_1<string, int> c4("声明和实现写在同一个.hpp文件下实现分文件编写 测试", 9999);
		c4.show();

		//普通类测试
		//没有#include "TemplateFileTest.cpp"时能正常运行
		//#include "TemplateFileTest.cpp"后会重定义，报错
		/*Class12_2 c5("普通类实现分文件编写 测试", 99999);
		c5.show();*/

	}


	//类模板与友元
	template<typename T> class Class13;//下模板函数需要用到Class13类，需要提前声明
	template<typename T> void PVal3(Class13<T> c);//前置声明模板函数
	template<typename T>
	class Class13
	{
		//全局的友元函数在类内实现
		friend void PVal(Class13<T> c)
		{
			cout << "PVal";
			cout << c.m_Val << endl;
		}
		//全局的友元函数在类外实现
		friend void PVal2(Class13<T> c);
		friend void PVal3<>(Class13<T> c);//<>相当于明确声明PVal3为一个函数模板，但此处没有模板函数的完整声明
										  //所以需要前置声明模板函数
		template<typename T>//此处的T和类模板的T不是同一个，两者作用域不同，相当于全局变量和局部变量，此处的T会在函数模板作用域范围内覆盖，类模板的T
		friend void PVal4(Class13<T> c);//此时是在类内声明了完整的全局函数模板PVal4，且将其设置为友元函数
										//所以不需要前置声明模板函数，且类外实现后，可以正常链接和调用
	
	public:
		Class13(T val)
		{
			m_Val = val;
		}
	private:
		T m_Val;
	};
	template<typename T>
	void PVal2(Class13<T> c)
	{
		cout << c.m_Val << endl;
	}
	template<typename T>
	void PVal3(Class13<T> c)
	{
		cout << "PVal3";
		cout << c.m_Val << endl;
	}
	template<typename T>
	void PVal4(Class13<T> c)
	{
		cout << "PVal4";
		cout << c.m_Val << endl;
	}
	void fun13()
	{
		cout << "\n\nTest_fun13" << endl;
		Class13<string> c1("类内友元全局函数");
		PVal(c1);

		Class13<string> c2("全局的友元函数在类外实现");
		//错误示例
		//PVal2(c2);//此时调用的是声明了友元的全局函数PVal2，但该函数的实现没有写
				  //因为类内声明的friend void PVal2(Class13<T> c);PVal2是一个普通函数，不是模板函数，与类外的模板函数PVal2不匹配
				  //所以类外的PVal2和类内声明的友元全局函数PVal2完全就是两个不同的东西
				  //此时调用类内声明的友元全局函数PVal2，只有声明，没有实现，所以会报链接错误
		//PVal2<string>(c2);//此时调用的是类外的函数模板PVal2，此函数模板不是友元函数
						  //会因为访问private权限下的成员变量报错

		PVal3(c2);
		PVal4(c2);

	}



	//实现一个通用类型的数组类
	template<typename T>
	void fun14_1(MyArr<T>& arr)
	{
		for (int i = 0;i < arr.getLen();i++)
		{
			cout << arr[i] << endl;
		}
	}
	class Class14
	{
	public:
		string m_Str;
		int m_Num;
		Class14() {};
		Class14(string str, int num) :m_Str(str), m_Num(num) {}
		friend ostream& operator<<(ostream& cout, const Class14& c);
	};
	ostream& operator<<(ostream& cout, const Class14& c)
	{
		return cout << "m_Str:\t" << c.m_Str << "\nm_Num:\t" << c.m_Num << endl;
	}
	void fun14()
	{
		cout << "\n\nTest_fun14" << endl;
		MyArr<int> arr(10);
		MyArr<int> arr1 = arr;
		MyArr<int> arr2(100);
		arr2 = arr;

		cout <<"Capacity:" << arr.getCapacity() << endl;
		cout <<"Len:" << arr.getLen() << endl;
		arr.Push_Back(100);
		cout << "Capacity:" << arr.getCapacity() << endl;
		cout << "Len:" << arr.getLen() << endl;
		cout << arr[0] << endl;
		int a = arr.Del_Back();
		cout << a << endl;
		cout << "Capacity:" << arr.getCapacity() << endl;
		cout << "Len:" << arr.getLen() << endl;

		for (int i = 0; i < arr1.getCapacity();i++)
		{
			//arr1[i] = i;//arr1[i]可以赋值，但是赋值后没有修改len的值，后续遍历输出会异常
			arr1.Push_Back(i);
		}
		fun14_1(arr1);
		cout << "Capacity:" << arr1.getCapacity() << endl;
		cout << "Len:" << arr1.getLen() << endl;

		//类及重载测试
		Class14 c("str1",10);
		cout << c << endl;

		MyArr<Class14> cArr(10);
		Class14 c1("str1", 10);
		Class14 c2("str2", 20);
		Class14 c3("str3", 30);
		Class14 c4("str4", 40);
		Class14 c5("str5", 50);
		Class14 c6("str6", 60);
		cArr.Push_Back(c1);
		cArr.Push_Back(c2);
		cArr.Push_Back(c3);
		cArr.Push_Back(c4);
		cArr.Push_Back(c5);
		cArr.Push_Back(c6);
		fun14_1(cArr);
		cout << "Capacity:" << cArr.getCapacity() << endl;
		cout << "Len:" << cArr.getLen() << endl;
		Class14 tempC = cArr.Del_Back();
		cout << tempC << endl;
		cout << "Capacity:" << cArr.getCapacity() << endl;
		cout << "Len:" << cArr.getLen() << endl;
	}
	
}



void testTemplate()
{
	//模板(主要是将数据类型参数化)
	// 模板是实现泛型编程的核心工具，允许程序员编写与类型无关的代码。
	// 模板的主要目的是提高代码的复用性和灵活性，同时保持类型安全和运行时效率。
	// 
	// 模板类型：
	// 1、函数模板
	// 2、类模板
	// 
	// 函数模板
	// 函数模板允许定义一个通用函数，适用于多种数据类型。
	// //定义模板，T为模板参数，该模板定义和模板参数只可以用在紧随其后的模板
	// 语法：template<typename T>
	// //后续可以用T代指一个任意相同的数据类型
	// 例：T fun1(T a, T b){} //表示一个 返回值类型为T，接收两个类型为T的参数 的函数(T需为同一数据类型)
	// 模板的使用：
	// 1、自动类型推导//编译器根据传入的参数推导出参数的类型
	//	例：
	//	int a = 10, b = 20;
	//	fun1(a,b)//编译器会根据传入的a和b推导出T的类型为int //传入其他类型会推导为其他类型
	//	注意事项：
	//		1、自动类型推导，必须推导出一致的数据类型T才可以使用
	//		2、模板必须要确定出T的数据类型，才可以使用
	// 2、显示指定类型
	//	例：
	//	fun1<double>(1,2.2)//显示指定T的数据类型为double
	//	//<>中指定的是T的数据类型，如果有多个T，则需要每个都指定
	//	例：
	//	template<typename T1,typename T2>
	//	void fun2(T1 a, T2 b){}
	//	fun2<int,float>(1,2.2);
	//

	fun1();


	fun2();

	//普通函数和模板函数的区别
	// 普通函数调用时可以发生自动类型转换(隐式类型转换)
	// 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
	// 如果利用显示指定类型的方式调用模板，可以发生隐式类型转换
	//

	fun3();


	//普通函数和模板函数的调用规则
	// 前提：普通函数和模板函数可以同名且发生函数重载
	// 1、如果函数模板和普通函数都可以实现，优先调用普通函数
	// 2、可以通过空模板参数列表来强制调用函数模板
	// 3、函数模板也可以发生重载
	// 4、如果函数模板可以产生更好的匹配，优先调用函数模板
	//

	fun4();

	
	//模板特化
	// 模板特化是指为模板参数的某个具体类型提供一个专门的实现。
	// 当编译器遇到特化类型的实例化请求时，会优先使用特化版本，而不是通用模板。
	// 分类：
	// 全特化（Full Specialization）：为所有模板参数提供具体的类型。
	// 偏特化（Partial Specialization）：仅对部分模板参数提供具体的类型或模式匹配。
	// 
	// 全特化：
	// 函数模板全特化
	// 语法：
	//	在已经定义了模板的情况下
	//	template<>
	//	返回值 函数名<具体类型>(参数列表){}
	//	//其中所有原来是模板参数的地方都要指定具体类型
	//	//其中<具体类型>部分可以省略
	// 
	// 偏特化
	// 函数模板不支持偏特化，直接函数重载即可了
	// 
	//

	fun5();



	//类模板
	// 类模板（Class Template）是一种泛型编程工具，允许我们定义一个通用的类结构，使其可以适用于多种数据类型
	// 定义类模板
	// 语法：template<typename T>
	// 后接类的定义即可 //类中可以用T代指一个任意相同的数据类型
	//	例：
	//	class Class1{
	//	public:
	//		T m_Val;
	//		Class1(T val):m_Val(val){}
	//	};
	// 
	// 类模板的使用：
	// 1、显示指定类型(类模板不能进行自动类型推导)
	//	例：
	//	Class1<int>c1(10);
	// 
	// 2、模板参数中设置了默认参数，设置了默认参数的模板参数可以不指定类型
	//	例：
	//	template<typename T1,typename T2 = int>
	//	class Class2
	//	{
	//	public:
	//		T1 m_Val1;
	//		T2 m_Val2;
	//		Class2(T1 val1,T2 val2):m_Val1(val1),m_Val2(val2){}
	//	};
	//	//实例化：
	//	Class2<string> c2("str",10);
	// 
	// 类模板与函数模板的区别主要有两点：
	// 1、类模板没有自动类型推导的使用方式
	// 2、类模板在模板参数列表中可以有默认参数
	//

	fun6();


	//类模板中成员函数的创建时机
	// 普通类中的成员函数一开始就被创建
	// 类模板中的成员函数在调用时才创建
	// 
	//类模板的显式实例化
	// 类模板的显式实例化是指明确告诉编译器为特定的数据类型生成类模板的代码
	// 可以确保特定类型的模板代码只生成一次，其他地方只需引用这个已实例化的版本
	// 类模板显式实例化时，所有成员函数都会被实例化。
	// 语法：
	// template class 类名<模板参数类型>;
	// 例 template class Class1<int>;
	// 注意：
	// 类模板的显式实例化，相同的模板参数类型只能实例化一次，否则会导致连接错误，因为被多个源文件重定义了
	// 可以使用预处理宏确保显式实例化类模板不会重复
	// 
	// 一般项目的类模板代码组织结构
	//	1、直接将类模板的声明和实现写在一个.hpp文件中，要使用时包含该.hpp头文件即可(常用的方式)
	//	2、.hpp.tpp分文件进行编写
	//		.hpp写类模板的声明
	//		.tpp写类模板的定义
	//		.hpp文件末尾include.tpp文件
	//		要使用时包含该.hpp头文件即可
	// //.hpp是约定的类模板头文件后缀名
	// //.tpp 文件是C++社区中一种常用的命名约定，用于存放类模板或函数的具体实现。
	// 
	//

	fun7();


	//类模板对象做函数参数
	// 类模板实例化出的对象，向函数传参的方式：
	// 1、指定传入的类型	---直接显示指定对象的数据类型
	// 例：	void fun8_1(Class8<string, int>& c)
	// 2、参数模板化		---将对象中的参数变为模板进行传递
	// 例：	template<typename T1, typename T2>
	//		void fun8_2(Class8<T1, T2>& c)
	// 3、整个类模板化		---将这个对象类型 模板化进行传递
	// 例：	template<typename T>
	//		void fun8_3(T& c)
	//

	fun8();


	//类模板和继承
	// 1. 普通类继承类模板	//适用于固定模板参数的场景。
	// 一个普通类可以继承自一个类模板，需要指定模板参数的具体类型。
	// 2. 类模板继承普通类	//适用于为类模板提供通用功能的场景。
	// 一个类模板也可以继承自一个普通类。这种情况下，类模板的行为类似于普通类，只是它具有泛型能力。
	// 3. 类模板继承类模板	//最灵活的方式，适用于复杂的泛型设计。
	// 类模板可以继承另一个类模板，这种场景最为复杂，但也最为灵活。
	//	此时如果父类中没有默认构造函数，子类必须通过初始化列表传递参数，调用父类构造函数进行初始化
	// 4. 类模板继承中的虚函数
	// 在类模板继承中，虚函数的行为与普通类继承类似。如果基类定义了虚函数，派生类可以覆盖这些函数。
	// 
	// 注意事项：
	// 1、类模板继承类模板时，子类模板定义时，使用基类中的成员，需要显示指定
	//	原因解析：
	//	子类模板在定义时，不会自动查找父类中的名称(只有类模板继承类模板时会有此问题)
	//	所以会导致子类模板在定义时的变量未声明异常
	//	解决方式：
	//	1、this指针显式指定
	//	2、使用基类名限定作用域
	//	3、使用using声明将基类成员引入子类作用域
	// 2、构造函数的调用
	//	父类没有默认构造函数时，子类要在构造函数的初始化列表中，调用父类构造函数进行初始化
	// 3、模板特化的影响
	//	如果基类或派生类涉及模板特化，可能会导致行为的变化。
	//	父类模板特化可能会导致的行为异常变化： //未写代码进行测试，感觉遇到的机会比较小
	//	1、模板特化可能破坏基类成员的连续性
	//		基类模板特化时，特定类型模板缺少成员，会导致子类特定类型模板实例中应该继承的父类成员消失
	//		例：父模板中有fun函数，特化int模板参数的版本中没有fun函数，子类模板实例化int类型的对象时，会无法访问fun函数
	//	2、特化版本改变成员类型
	//		基类模板特化时，修改了其中的类型成员的类型，会导致子类模板的 类型成员 的数据类型出现偏差
	//		例：父类模板中 using Type = T;声明了类型成员的类型为模板参数的类型，特化int版本的父类模板时，using Type = double;直接定义了类型成员Type的类型为double，当子类模板实例化int类型的对象时，其中继承的父类的类型成员Type的类型会为double
	//	3、子类模板的隐式实例化与特化冲突
	//		当子类模板隐式实例化时，可能意外匹配到基类的错误特化版本。
	//		特化导致继承关系断裂
	//		例：父类模板的int类型特化版本使用final关键字，强制禁用继承
	//		template<> 
	//		class Base<int> final {};
	//		会导致当子类模板实例化int类型的对象时编译失败
	//	4、部分特化可能会导致继承歧义
	//		基类模板的​​部分特化​​（Partial Specialization）可能引入多重继承路径，影响子类的成员访问优先级。
	//		例：父类使用两个模板参数T1,T2，部分特化父类两个模板参数均为T的版本中，实现fun函数
	//		template<typename T>
	//		class Base<T,T>{public: void fun(){}};
	//		当子类模板实例化两个模板参数一致的对象时，可以访问继承自父类的fun函数
	//		其他子类模板实例化的对象无法访问fun函数
	//	5、虚函数特化破坏多态
	//		若基类模板的特化版本中虚函数签名与通用版本不同，子类的重写可能失效。
	//		例：父类模板中实现了虚函数virtual void fun(T){}，父类模板的int类型特化修改了虚函数virtual void fun(double){}
	//			当子类模板重写了父类的虚函数后 void fun(T) override{}
	//			当子类模板实例化了int类型模板参数的对象后，会导致没有重写继承的 Base<int>::foo(double)函数
	// 4、静态成员的共享
	//	模板类的静态成员是按模板实例化的类型独立的。如果基类和派生类都定义了静态成员，它们可能是不同的实例。
	// 


	fun9();



	//类模板成员函数的类外实现

	fun11();


	//类模板的分文件编写
	// 问题产生原因：
	//	主要是由于类模板中的成员函数只有在调用时才会实例化(被创建)
	//	如果按一般的分.h(写类模板的声明)和.cpp(写类模板的实现)的方式，进行分文件编写
	//	在实际调用类模板的.cpp文件中包含.h文件时，会只有类模板的声明，链接器找不到实现，会链接错误
	// 
	// 解决方式：
	//	1、直接包含.cpp源文件
	//	2、将类模板的声明和实现都写到一个.hpp文件下，调用时包含.hpp文件(.hpp是约定的类模板头文件后缀名)
	//	3、显式实例化，若模板只需支持少数特定类型，可在.cpp中​​显式实例化​​这些类型
	//		显式实例化只能用.h和.cpp文件实现，因为.cpp文件是独立的编译单元，在编译运行时会生成独立的目标文件
	//		链接时可以通过该目标文件中找到类模板的定义，所以链接时不会报错
	//	4、使用.hpp和.tpp分文件编写
	//		使用.hpp和.tpp文件实现类模板的分文件编写，必须要在.hpp文件末尾include .tpp文件
	//		相当于在.hpp文件末尾添加了类模板的实现，因为.tpp不是独立的编译单元，不会生成独立的目标文件
	//		所以显式实例化对于，使用.hpp和.tpp文件实现类模板的分文件编写，没有太多意义(当然显式实例化避免重复实例化等的作用还是有的吧)
	// 注意事项：
	//	1、如果模板中有友元函数，需要在头文件中直接提供定义
	//	2、静态成员必须在头文件中定义
	// 


	fun12();


	//类模板与友元
	// 全局的友元函数在类内实现，直接在类内声明和定义友元函数即可
	// 全局的友元函数在类外实现，需要提前让编译器知道全局函数的存在
	// 详情看示例fun13的实现
	//

	fun13();

	//案例
	//实现一个通用类型的数组类
	// 1、可以对内置数据类型以及自定义数据类型的数据进行存储
	// 2、将数组中的数据存储到堆区
	// 3、构造函数中可以传入数组的容量
	// 4、提供对应的拷贝构造函数以及operator=防止浅拷贝问题
	// 5、提供尾插法和尾删法对数组中的数据进行增加和删除
	// 6、可以通过下标的方式访问数组中的元素
	// 7、可以获取数组中当前元素个数和数组的容量
	//
	fun14();
}













