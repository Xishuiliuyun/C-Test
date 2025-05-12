#include"Stack_Queue_Test.h"


namespace
{
	template<typename T>
	void fun1_1(T s)//只是展示容器中的数据，不用引用方式传递，否则会修改原stack中的数据
	{
		int size = s.size();//要用临时变量，s.size()在pop后会被修改
		for (int i = 0;i < size;i++)
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
	//构造测试
	void fun1()
	{
		cout << "\n\nTest_fun1" << endl;
		//函数原型：
		//	 stack()	默认构造空栈	stack<int> s1;
		// 	//使用已有容器构造stack容器时，只能用和stack容器底层容器一致的容器对象进行构造
		//	 stack(const Container & cont)	用已有容器构造	deque<int> d{ 1,2,3 }; stack<int> s2(d);
		//	 stack(Container && cont)	移动构造(C++11)	stack<int> s3(deque<int>{1, 2, 3});
		//	 stack(const stack & other)	拷贝构造	stack<int> s4(s3);
		//	 stack(stack && other)	移动构造(C++11)	stack<int> s5(std::move(s4));
		//	指定底层容器类型：
		//	 stack<int, vector<int>> s1;  // 使用vector作为底层容器
		//	 stack<string, list<string>> s2; // 使用list作为底层容器

		//默认构造
		stack<int> s1;
		for (int i = 0;i < 10;i++) { s1.push(i); }
		for (int i = 0;i < 10;i++)
		{
			cout << s1.top() << " ";
			if(!s1.empty())s1.pop();
		}
		cout << endl;

		//使用已有容器进行构造
		//stack容器底层容器只可以是deque、vector、list
		vector<int>v1 = { 1,2,3,4,5 };
		deque<int>d1{ 1,2,3,4,5 };
		list<int> l1{ 1,2,3,4,5 };
		stack<int>s2(d1);//底层容器默认为deque容器，可以直接用deque对象进行初始化
		//stack<int>s3(v1);//报错，类型不匹配
		stack<int, vector<int>>s3(v1);
		stack<int, list<int>>s4(l1);//显式指定底层使用list容器
		fun1_1(s2);
		fun1_1(s3);
		fun1_1(s4);

		//移动构造
		auto li = { 10,20,30,40,50 };
		stack<int>s5(li);
		fun1_1(s5);
		stack<int>s6(move(s5));
		fun1_1(s5);//s5容器被置空
		fun1_1(s6);
		deque<int>d2{ 1,2,3,4,5 };
		stack<int>s7(move(d2));
		for (int i = 0;i < d2.size();i++) { cout << d2.at(i); }//d2容器被置空
		cout << endl;
		fun1_1(s7);


		//拷贝构造
		stack<int>s8(s6);
		fun1_1(s8);

	}

	//stack成员测试
	void fun2()
	{
		cout << "\n\nTest_fun2" << endl;
		//函数原型：
		// 3. 核心成员函数
		//	元素访问：
		//	 top()	返回栈顶元素的引用	O(1)
		//	容量操作：
		//	 empty()	检查栈是否为空	O(1)
		//	 size()	返回元素数量	O(1)
		//	修改操作：
		//	 push(const T& value)	压入元素到栈顶	O(1)
		//	 push(T && value)	移动元素到栈顶(C++11)	O(1)
		//	 emplace(Args&&... args)	在栈顶直接构造元素(C++11)	O(1)
		//	 pop()	移除栈顶元素	O(1)
		//	 swap(stack & other)	交换两个栈的内容(C++11)	O(1)
		// 
		// 4. 非成员函数
		//	operator==等	比较两个栈	if (s1 == s2)
		//	swap(stack & a, stack & b)	交换两个栈	swap(s1, s2);

		stack<int>s1;
		for (int i = 0;i < 5;i++) { s1.push(i) ; }
		fun1_1(s1);
		if (!s1.empty())s1.top() = 100;
		fun1_1(s1);
		cout << s1.size() << endl;

		stack<int>s2(s1);
		//s1中的元素没有减少，详情看fun3测试结果
		s2.push(move(s1.top()));
		fun1_1(s1);
		fun1_1(s2);

		s2.emplace(1000);
		fun1_1(s2);

		s2.pop();
		fun1_1(s2);

		s2.swap(s1);
		fun1_1(s1);
		fun1_1(s2);

		cout << (s1 == s2) << endl;
		swap(s1, s2);
		fun1_1(s1);
		fun1_1(s2);
	}

	//move研究
	template<typename T>
	void fun3_1(T && val)
	{
		//cout << typeid(T).name() << endl;
		val = T();//T&&实际上也是一种引用，只不过和T&左值引用在使用场景上有些不同
	}
	//正常实现移动后删除的类
	class Class3
	{
		friend ostream& operator<<(ostream& cout, const Class3& c);
	public:
		int m_Num;
		string m_Str;
		Class3():m_Num(0), m_Str("str") {}
		Class3(int num,string str)
		{
			m_Num = num;
			m_Str = str;
		}
		Class3(const Class3& other)//拷贝构造
		{
			cout << "Class3拷贝构造被调用" << endl;
			m_Num = other.m_Num;
			m_Str = other.m_Str;
		}
		Class3(Class3&& other) noexcept//移动构造
		{
			cout << "Class3移动构造被调用" << endl;
			m_Num = move(other.m_Num);
			m_Str = move(other.m_Str);
			other.m_Num = int();
			other.m_Str = string();
		}
		Class3& operator=(const Class3& other)//拷贝赋值
		{
			cout << "Class3拷贝赋值被调用" << endl;
			m_Num = other.m_Num;
			m_Str = other.m_Str;
			return *this;
		}
		Class3& operator=(Class3&& other) noexcept//移动赋值
		{
			cout << "Class3移动赋值被调用" << endl;
			m_Num = move(other.m_Num);
			m_Str = move(other.m_Str);
			other.m_Num = int();
			other.m_Str = string();
			return *this;
		}
	};
	ostream& operator<<(ostream& cout, const Class3& c)
	{
		return cout << "\tClass3.m_Num :" << c.m_Num << "\tClass3.m_Str :" << c.m_Str;
	}
	//没实现移动后删除的类
	class Class3_1
	{
		friend ostream& operator<<(ostream& cout, const Class3_1& c);
	public:
		int m_Num;
		string m_Str;
		Class3_1() :m_Num(0), m_Str("str") {}
		Class3_1(int num, string str)
		{
			m_Num = num;
			m_Str = str;
		}
		Class3_1(const Class3_1& other)//拷贝构造
		{
			//cout << "Class3_1拷贝构造被调用" << endl;
			m_Num = other.m_Num;
			m_Str = other.m_Str;
		}
		Class3_1(Class3_1&& other) noexcept//移动构造
		{
			cout << "Class3_1移动构造被调用" << endl;
			m_Num = other.m_Num;
			m_Str = other.m_Str;
		}
		Class3_1& operator=(const Class3_1& other)//拷贝赋值
		{
			cout << "Class3_1拷贝赋值被调用" << endl;
			m_Num = other.m_Num;
			m_Str = other.m_Str;
			return *this;
		}
		Class3_1& operator=(Class3_1&& other) noexcept//移动赋值
		{
			cout << "Class3_1移动赋值被调用" << endl;
			m_Num = other.m_Num;
			m_Str = other.m_Str;
			return *this;
		}
	};
	ostream& operator<<(ostream& cout, const Class3_1& c)
	{
		return cout << "\tClass3_1.m_Num :" << c.m_Num << "\tClass3_1.m_Str :" << c.m_Str;
	}
	void fun3()
	{
		cout << "\n\nTest_fun3" << endl;

		//move
		// std::move 是 C++11 引入的一个关键工具，用于启用移动语义（move semantics），它是现代 C++ 中实现高效资源管理的核心机制之一。
		// 移动主要是用来减少资源消耗的，资源消耗会比拷贝小
		// 
		// 本质​​：std::move 是一个​​类型转换函数​​
		// 作用​​：将表达式转换为右值引用（xvalue），表示对象可以被"移动"
		//	 相当于将传入的对象设置为&&类型，表明该对象可以被移动，用于触发特定的函数(移动构造，移动赋值)
		//	 move只是修改了对象的数据类型，不会对对象中的数据进行任何修改，实际修改了原对象中的数据中的操作是在，其他函数中实现的
		//	 例如Class1中有移动构造函数 Class1(Class1&& other){}，当初始化构造对象时 Class1 c2(move(c1))
		//	 实际上就是将c1对象通过move函数，将类型改为了Class1&&，此时刚好满足Class1类中的移动构造函数的调用
		//	 调用Class1的移动构造函数后，在移动构造中才实际实现了修改原对象的数据的功能，如果移动构造中不实现修改原对象的功能的话
		//	 原对象是不会有任何变化的，可能会导致多个对象引用同一资源，或内存重复释放等问题
		// 
		// T&&实际上也是一种引用，只不过和T&左值引用在使用场景上有些不同
		//

		//T&&测试
		stack<int>s1;
		s1.push(100);
		cout << s1.top() << endl;
		fun3_1(move(s1.top()));
		cout << s1.top() << endl;
		//T&&测试
		Class3 c1(100, "str1");
		cout << c1 << endl;
		fun3_1(move(c1));
		cout << c1 << endl;

		//类对象的移动测试
		c1.m_Num = 200;
		c1.m_Str = "str2";
		Class3 c2(move(c1));
		cout << c1 << endl;
		cout << c2 << endl;
		Class3_1 c11(300, "str3");
		Class3_1 c22(move(c11));
		cout << c11 << endl;
		cout << c22 << endl;

		cout << "\n容器对象的移动测试111111：" << endl;
		//容器对象的移动测试
		deque<Class3> d1{ Class3(1,"str1"),Class3(2,"str2") ,Class3(3,"str3") };//调用拷贝构造
		stack<Class3> s2(d1);//调用拷贝构造
		stack<Class3> s3(move(s2));//没有调用移动相关的函数，可能容器的STL实现是直接移动容器的指针，没有逐个移动元素
		fun1_1(s2);//s2中的元素被删除
		fun1_1(s3);//调用拷贝构造

		deque<Class3_1> d11{ Class3_1(1,"str1"),Class3_1(2,"str2") ,Class3_1(3,"str3") };//调用拷贝构造
		stack<Class3_1> s22(d11);//调用拷贝构造
		stack<Class3_1> s33(move(s22));//没有调用移动相关的函数，可能容器的STL实现是直接移动容器的指针，没有逐个移动元素
		fun1_1(s22);//s22中的元素被删除
		fun1_1(s33);//调用拷贝构造

		cout << "\n容器对象的移动测试22222：" << endl;
		deque<Class3> d2{ Class3(1,"str1"),Class3(2,"str2") ,Class3(3,"str3") };//调用拷贝构造
		stack<Class3>s4(move(d2));//没有调用移动相关的函数，可能容器的STL实现是直接移动容器的指针，没有逐个移动元素
		stack<Class3>s5;
		s5.push(move(s4.top()));//调用了Class3中的移动构造函数
		fun1_1(s4);//s4中的第一个元素被移动构造函数修改，但s4.size()没有被修改
		fun1_1(s5);//调用拷贝构造

		deque<Class3_1> d22{ Class3_1(1,"str1"),Class3_1(2,"str2") ,Class3_1(3,"str3") };//调用拷贝构造
		stack<Class3_1>s44(move(d22));//没有调用移动相关的函数，可能容器的STL实现是直接移动容器的指针，没有逐个移动元素
		stack<Class3_1>s55;
		s55.push(move(s44.top()));//调用了Class3_1中的移动构造函数
		fun1_1(s44);//s44中的第一个元素被移动构造函数修改，但s44.size()没有被修改
		fun1_1(s55);//调用拷贝构造

		cout << "\n容器对象的移动测试33333：" << endl;
		Class3 c3(3, "str3");
		cout << c3 << endl;
		stack<Class3> s6;
		s6.push(move(c3));//调用了Class3中的移动构造函数
		s6.push(c3);//调用了Class3中的拷贝构造函数
		cout << c3 << endl;//c3对象中的值被修改
		fun1_1(s6);//调用拷贝构造
	}

	//底层容器操作
	//通过继承实现访问stack容器中的protected容器成员
	template<typename T,typename Container = std::deque<T>>
	class HackStack :public stack<T, Container>
	{
	public:
		using stack<T, Container>::c;
		HackStack(const Container& c) :stack<T, Container>(c) {}
	};
	void fun4()
	{
		cout << "\n\nTest_fun4" << endl;
		// 底层容器操作：
		//	虽然stack不直接提供迭代器，但可以通过底层容器访问：
		//	注意：直接修改底层容器可能破坏栈的不变性，应谨慎使用。
		//	 stack<int, vector<int>> s;
		//	 s.push(1);
		//	 s.push(2);
		//	 // 获取底层vector的引用
		//	 //即使通过指针到成员（.*）语法强行访问，也违反了 C++ 标准，编译器会拒绝编译。
		//	 auto& underlying_vec = s.*(&stack<int, vector<int>>::c);//实际提示protected成员无法访问
		//	 for (int n : underlying_vec) {
		//	 	cout << n << " ";  // 1 2
		//	 }

		deque<int>d1{ 1,2,3 };
		stack<int>s1(move(d1));
		for (deque<int>::iterator it = d1.begin();it != d1.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		fun1_1(s1);

		//stack 的_Get_container函数（MSVC 特有，非标准）
		auto& underlying_deq = s1._Get_container();/**(&stack<int,deque<int>>::c)*/
		cout << typeid(underlying_deq).name() << endl;
		for (int n : underlying_deq)
		{
			cout << n << " ";
		}
		cout << endl;

		//stack<int, vector<int>> s;
		//s.push(1);
		//s.push(2);
		//// 获取底层vector的引用
		//auto& underlying_vec = s.*(&stack<int, vector<int>>::c);//实际提示protected成员无法访问
		//for (int n : underlying_vec) {
		//cout << n << " ";  // 1 2
		//}

		//通过继承实现访问stack容器中的protected容器成员
		deque<int>d2{ 10,20,30 };
		HackStack<int> hs1(d2);
		for (int n : hs1.c)
		{
			cout << n << " ";
		}
		cout << endl;
	}

	//构造测试
	template<typename T>
	void fun5_1(T q)
	{
		int size = q.size();
		for (int i = 0;i < size;i++)
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
	void fun5()
	{
		cout << "\n\nTest_fun5" << endl;

		//	基本构造方式：
		//	 queue()	默认构造空栈	queue<int> s1;
		//	  //使用已有容器构造queue容器时，不会影响queue容器的底层实现容器，queue容器的底层实现容器是在声明时的模板参数时指定的 queue<int,vector<int>>
		//	 queue(const Container & cont)	用已有容器构造	deque<int> d{ 1,2,3 }; queue<int> q2(d);
		//	 queue(Container && cont)	移动构造(C++11)	queue<int> q3(deque<int>{1, 2, 3});
		//	 queue(const queue & other)	拷贝构造	queue<int> q4(q3);
		//	 queue(queue && other)	移动构造(C++11)	queue<int> q5(std::move(q4));
		//	指定底层容器类型：
		//	 queue<int, vector<int>> q1;  // 使用vector作为底层容器
		//	 queue<string, list<string>> q2; // 使用list作为底层容器

		//默认构造
		queue<int>q1;
		for (int i = 0;i < 5;i++) { q1.push(i); }
		fun5_1(q1);

		//使用已有容器构造
		deque<int>d1{ 1,2,3 };
		vector<int>v1{ 10,20,30 };
		list<int>l1{ 100,200,300 };
		queue<int, deque<int>> q2(d1);
		queue<int, vector<int>> q3(v1);
		queue<int, list<int>> q4(l1);
		fun5_1(q2);
		//q3.pop();//底层容器设置为vector时，由于vector容器没有实现pop_front()函数，会报错，和vector内存连续有关，抛出首元素需要移动所有元素，效率低
		//fun5_1(q3);
		fun5_1(q4);

		//移动构造(移动容器元素)
		deque<int>d2{ 1000,2000,3000 };
		queue<int>q5(move(d2));//d2中的元素被转移
		for (int i = 0;i < d2.size();i++) { cout << d2.at(i) << " "; }
		cout << endl;
		fun5_1(q5);
		//移动构造(移动队列)
		queue<int>q6(move(q5));//q5中的元素被转移
		fun5_1(q5);
		fun5_1(q6);

		//拷贝构造
		queue<int>q7(q6);
		fun5_1(q6);
		fun5_1(q7);

	}

	//queue成员测试
	void fun6()
	{
		cout << "\n\nTest_fun6" << endl;

		// 3. 核心成员函数
		//	元素访问：
		//	 front()	返回队首元素的引用	O(1)
		//	 back()	返回队尾元素的引用	O(1)
		//	容量操作：
		//	 empty()	检查栈是否为空	O(1)
		//	 size()	返回元素数量	O(1)
		//	修改操作：
		//	 push(const T& value)	在队尾插入元素	O(1)
		//	 push(T && value)	移动元素到队尾(C++11)	O(1)
		//	 emplace(Args&&... args)	在队尾直接构造元素(C++11)	O(1)
		//	 pop()	移除队首元素	O(1)
		//	 swap(queue & other)	交换两个队列的内容(C++11)	O(1) 
		//	特殊成员函数：
		//	 queue& operator=(const queue& other);  // 拷贝赋值
		//	 queue& operator=(queue&& other);       // 移动赋值(C++11)
		// 
		// 4. 非成员函数
		//	operator==等	比较两个队列	if (q1 == q2)
		//	swap(queue & a, queue & b)	交换两个栈	swap(q1, q2);

		queue<int>q1({ 1,2,3,4,5 });
		q1.front() = 10;
		cout << "q1.front() :" << q1.front() << endl;
		cout << "q1.back() :" << q1.back() << endl;
		cout << "q1.empty() :" << q1.empty() << endl;
		cout << "q1.size() :" << q1.size() << endl;

		queue<int>q2;
		for (int i = 0;i < 10;i++) { q2.push(i); }
		q2.push(move(q1.front()));//q1中的第一个元素不会被移除，原因同stack
		fun5_1(q1);
		fun5_1(q2);
		q2.emplace(100);
		q2.pop();
		fun5_1(q2);
		q2.swap(q1);
		fun5_1(q1);
		fun5_1(q2);

		queue<int>q3 = q2;//拷贝赋值
		queue<int>q4 = move(q2);//移动赋值
		fun5_1(q2);
		fun5_1(q3);
		fun5_1(q4);

		cout << (q3 == q4) << endl;
		swap(q1, q2);
		fun5_1(q1);
		fun5_1(q2);
	}

	//底层容器操作
	template<typename T,typename Container = deque<T>>
	class HackQueue :public queue<T, Container>
	{
	public:
		using queue<T, Container>::c;
		HackQueue() :queue<T, Container>() {}
		HackQueue(const Container& con):queue<T, Container>(con){}
	};
	void fun7()
	{
		cout << "\n\nTest_fun7" << endl;

		// 5. 底层容器操作
		//	同stack
		//	底层容器可以设置为deque(默认)、vector、list
		//	虽然stack不直接提供迭代器，但可以通过底层容器访问：
		//	注意：直接修改底层容器可能破坏栈的不变性，应谨慎使用。
		//	可通过继承或_Get_container函数（MSVC 特有，非标准）实现访问底层容器

		queue<int>q1;
		for (int i = 0;i < 10;i++) { q1.push(i); }
		fun5_1(q1);

		deque<int>d1 = q1._Get_container();
		d1.at(0) = 100;//不会修改到原queue容器中的元素
		for (int i = 0;i < d1.size();i++) { cout << d1.at(i) << " "; }
		cout << endl;
		fun5_1(q1);

		HackQueue<int>hq1;
		for (int i = 5;i < 10;i++) { hq1.push(i); }
		fun5_1(hq1);
		for (int n : hq1.c)
		{
			cout << n << " ";
		}
		cout << endl;
	}
}







void testStackQueue()
{
	//stack容器
	// std::stack 是 C++ 标准模板库(STL)中的一个容器适配器，它提供了栈(后进先出, LIFO)数据结构的功能。
	// 
	// 1. 基本特性
	//	头文件​​：#include <stack>
	//	命名空间​​：std
	//	底层容器​​：默认基于std::deque，也可指定其他序列容器(vector / list)
	//	操作限制​​：只允许在一端(栈顶)进行插入和删除操作
	//	时间复杂度​​：
	//	插入 / 删除：O(1)
	//	访问栈顶：O(1)
	//	大小查询：O(1)
	// 
	// 2. 构造与初始化
	//	基本构造方式：
	//	 stack()	默认构造空栈	stack<int> s1;
	//	  //使用已有容器构造stack容器时，不会影响stack容器的底层实现容器，stack容器的底层实现容器是在声明时的模板参数时指定的 stack<int,vector<int>>
	//	 stack(const Container & cont)	用已有容器构造	deque<int> d{ 1,2,3 }; stack<int> s2(d);
	//	 stack(Container && cont)	移动构造(C++11)	stack<int> s3(deque<int>{1, 2, 3});
	//	 stack(const stack & other)	拷贝构造	stack<int> s4(s3);
	//	 stack(stack && other)	移动构造(C++11)	stack<int> s5(std::move(s4));
	//	指定底层容器类型：
	//	 stack<int, vector<int>> s1;  // 使用vector作为底层容器
	//	 stack<string, list<string>> s2; // 使用list作为底层容器
	// 
	// 3. 核心成员函数
	//	元素访问：
	//	 top()	返回栈顶元素的引用	O(1)
	//	容量操作：
	//	 empty()	检查栈是否为空	O(1)
	//	 size()	返回元素数量	O(1)
	//	修改操作：
	//	 push(const T& value)	压入元素到栈顶	O(1)
	//	 push(T && value)	移动元素到栈顶(C++11)	O(1)
	//	 emplace(Args&&... args)	在栈顶直接构造元素(C++11)	O(1)
	//	 pop()	移除栈顶元素	O(1)
	//	 swap(stack & other)	交换两个栈的内容(C++11)	O(1)
	// 
	// 4. 非成员函数
	//	operator==等	比较两个栈	if (s1 == s2)
	//	swap(stack & a, stack & b)	交换两个栈	swap(s1, s2);
	// 
	// 5. 底层容器操作
	//	虽然stack不直接提供迭代器，但可以通过底层容器访问：
	//	注意：直接修改底层容器可能破坏栈的不变性，应谨慎使用。
	//	 stack<int, vector<int>> s;
	//	 s.push(1);
	//	 s.push(2);
	//	 // 获取底层vector的引用
	//	 auto& underlying_vec = s.*(&stack<int, vector<int>>::c);
	//	 for (int n : underlying_vec) {
	//	 	cout << n << " ";  // 1 2
	//	 }
	// 
	// 6. 性能与实现细节
	//	底层容器选择的影响：
	//	 deque (默认)	两端操作高效，内存占用平衡	内存不连续
	//	 vector	内存连续，缓存友好	扩容时可能性能下降
	//	 list	无扩容开销，稳定性能	内存不连续，额外指针开销
	//	内存管理：
	//	 stack本身不直接管理内存，依赖底层容器
	//	 使用vector时，push可能导致重新分配内存
	//	 使用list或deque时，每次push都是独立分配节点
	// 
	// 7. 注意事项
	// ​​	1、空栈访问​​：调用top()或pop()前必须检查empty()
	//	2、线程安全：
	//	 不同线程可以同时读取同一个栈
	//	 任何写操作都需要同步机制
	//	3、迭代器缺失​​：
	//	 stack不提供迭代器，如需遍历需要临时弹出元素
	//	4、​异常安全​​：
	//	 push / emplace可能抛出内存分配异常
	//	 pop不抛出异常（前提是元素析构不抛出）
	//	5、​自定义元素类型​​：
	//	 元素类型必须可拷贝 / 移动构造 / 析构不抛异常
	//	 对于大型对象，考虑存储指针或智能指针

	//构造测试
	fun1();

	//stack成员测试
	fun2();

	//move研究
	fun3();

	//底层容器操作
	fun4();




	//queue容器
	// std::queue 是 C++ 标准模板库(STL)中的一个容器适配器，它提供了先进先出(FIFO)的数据结构功能。
	// 
	// 1. 基本特性
	// ​​	类型性质​​：序列容器适配器
	//	​​底层实现​​：默认基于 std::deque，可指定其他序列容器
	//	迭代器特性​​：​​不提供​​任何迭代器访问（设计上禁止遍历）
	//	线程安全​​：标准实现非线程安全，需外部同步
	//	异常安全​​：基本操作提供基本异常保证
	// 
	// 2. 构造与初始化
	//	基本构造方式：
	//	 queue()	默认构造空栈	queue<int> s1;
	//	  //使用已有容器构造queue容器时，不会影响queue容器的底层实现容器，queue容器的底层实现容器是在声明时的模板参数时指定的 queue<int,vector<int>>
	//	 queue(const Container & cont)	用已有容器构造	deque<int> d{ 1,2,3 }; queue<int> q2(d);
	//	 queue(Container && cont)	移动构造(C++11)	queue<int> q3(deque<int>{1, 2, 3});
	//	 queue(const queue & other)	拷贝构造	queue<int> q4(q3);
	//	 queue(queue && other)	移动构造(C++11)	queue<int> q5(std::move(q4));
	//	指定底层容器类型：
	//	 queue<int, vector<int>> q1;  // 使用vector作为底层容器
	//	 queue<string, list<string>> q2; // 使用list作为底层容器
	// 
	// 3. 核心成员函数
	//	元素访问：
	//	 front()	返回队首元素的引用	O(1)
	//	 back()	返回队尾元素的引用	O(1)
	//	容量操作：
	//	 empty()	检查栈是否为空	O(1)
	//	 size()	返回元素数量	O(1)
	//	修改操作：
	//	 push(const T& value)	在队尾插入元素	O(1)
	//	 push(T && value)	移动元素到队尾(C++11)	O(1)
	//	 emplace(Args&&... args)	在队尾直接构造元素(C++11)	O(1)
	//	 pop()	移除队首元素	O(1)
	//	 swap(queue & other)	交换两个队列的内容(C++11)	O(1) 
	//	特殊成员函数：
	//	 queue& operator=(const queue& other);  // 拷贝赋值
	//	 queue& operator=(queue&& other);       // 移动赋值(C++11)
	// 
	// 4. 非成员函数
	//	operator==等	比较两个队列	if (q1 == q2)
	//	swap(queue & a, queue & b)	交换两个栈	swap(q1, q2);
	// 
	// 5. 底层容器操作
	//	同stack
	//	底层容器可以设置为deque(默认)、vector、list
	//	虽然stack不直接提供迭代器，但可以通过底层容器访问：
	//	注意：直接修改底层容器可能破坏栈的不变性，应谨慎使用。
	//	可通过继承或_Get_container函数（MSVC 特有，非标准）实现访问底层容器
	// 
	// 6. 性能与实现细节
	//	底层容器选择的影响：
	//	 deque (默认)	两端操作O(1)，内存分配高效	内存分块不连续	通用队列场景
	//	 list	稳定性能，无容量限制	额外指针开销，缓存不友好	需要稳定指针或频繁中间删除
	//	 vector	内存连续，缓存命中率高	pop_front()效率低(O(n))	不推荐用于队列
	//	内存管理机制：
	//	​​ 1.内存分配策略​​：
	//		deque：分块分配（典型块大小4KB），动态增长时分配新块
	//		list：每个元素独立分配节点，包含前后指针
	//		vector：单块连续内存，扩容时重新分配（通常2倍增长）
	//	 2.​​性能关键点​​：
	//		deque：push_back/pop_front都是O(1)，但随机访问比vector慢
	//		list：每次操作都涉及动态内存分配，适合大对象
	//		vector：push_back均摊O(1)，但pop_front需要移动所有元素
	// 
	// 7. 注意事项
	//	1、空队列访问防护：调用top()或pop()前必须检查empty()
	//	2、线程安全：
	//	 不同线程可以同时读取同一个队列
	//	 任何写操作都需要同步机制
	//	3、迭代器缺失​​：
	//	 queue不提供迭代器，如需遍历需要临时弹出元素
	//	4、异常安全保证
	//	 push()	强异常安全	失败时队列状态不变
	//	 emplace()	强异常安全	同上
	//	 pop()	nothrow	前提：元素析构不抛异常
	//	 front()	nothrow	纯访问操作
	//	5、​自定义元素类型​​：
	//	 元素类型必须可拷贝 / 移动构造 / 析构不抛异常
	//	 对于大型对象，考虑存储指针或智能指针


	//构造测试
	fun5();

	//queue成员测试
	fun6();

	//底层容器操作
	fun7();



}
