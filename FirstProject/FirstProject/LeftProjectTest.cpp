//用于快速测试一些被剩下的未处理的项：
// set、map、仿函数、算法等
// 此些项暂时不细致处理了，迟点再处理

#include"LeftProjectTest.h"

namespace
{
	template<typename T>
	void fun1_1(const T& s)
	{
		for (typename T::const_iterator it = s.begin();it != s.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	//set测试项
	template<typename T>
	struct MyCompare
	{
		bool operator()(T val1,T val2)const
		{
			return val1 > val2;
		}
	};
	template<typename T>
	bool myCom(T v1, T v2)
	{
		return v1 > v2;
	}
	template<typename T>
	auto com = [](T v1, T v2) {
		return v1 > v2;
	};
	template<typename T>
	struct RuntimeCom
	{
		bool reverse;//是否降序
		bool operator()(T v1, T v2) const
		{
			return reverse ? (v1 > v2) : (v1 < v2);
		}
	};
	class Class1
	{
		friend ostream& operator<<(ostream& ostr, const Class1& c);
	public:
		bool operator<(const Class1& other)const
		{
			return this->m_Num < other.m_Num;
		}
		bool operator>(const Class1& other)const
		{
			return this->m_Num > other.m_Num;
		}
	public:
		string m_Str;
		int m_Num;
		Class1() :m_Str("str"), m_Num(0) {}
		Class1(string str,int num) :m_Str(str), m_Num(num) {}
	};
	ostream& operator<<(ostream& ostr, const Class1& c)
	{
		return cout << "m_Str : " << c.m_Str << " m_Num : " << c.m_Num << endl;
	}
	void fun1()
	{
		cout << "\n\nTest_fun1" << endl;

		//set insert()的返回值
		set<int>s1;
		pair<set<int>::iterator,bool> ret = s1.insert(1);
		cout << "val = " << *(ret.first) << "  is insert success:" << ret.second << endl;
		ret = s1.insert(1);//重复插入插入失败时，返回的迭代器指向的是容器中已经存在的那个相同元素
		cout << "val = " << *(ret.first) << "  is insert success:" << ret.second << endl;

		//set容器排序
		// 可以粗略地理解set的第二个模板参数(比较函数对象)，实际需要的是能满足在放置数据时进行比较的一个函数 的类型
		// 即需要满足 可以使用()方式调用 例：第二个模板参数(T a ,T b) ，且返回bool值，且其中的比较能满足需要的规则(未细究)
		// 所以	函数对象(仿函数)，可实现 MyCompare()方式调用
		//		函数指针，也可实现 myCom()方式调用
		//		Lambda表达式，也可实现 com()方式调用，所以上述内容都可以实现第二个模板参数的要求，都可以用
		// 因为set的第二个模板参数需要的是一个类型，所以需要使用decltype关键字，且在构造时需要传入函数指针
		//set<int>s2;//使用默认值 默认第二个参数是less<int> 库中已实现的函数对象(仿函数)
		//set<int, greater<int>>s2;//库中已实现的函数对象(仿函数)
		//set<int, MyCompare<int>>s2;//使用函数对象(仿函数) 效果同上
		//set<int, decltype(&myCom<int>)>s2(myCom<int>);//使用函数指针，构造时需要传入函数指针
		//set<int, decltype(com<int>)>s2(com<int>);//使用Lambda表达式
		RuntimeCom<int> comp{ true };
		set<int, RuntimeCom<int>>s2(comp);//运行时指定排序方式

		//上述示例中的 函数对象 函数指针 和 Lambda表达式 这三种方式实现时有区别的详细分析
		// 可以理解为set容器在构造时，需要有一个东西存储 可调用对象 后续用于插入时进行比较
		// 以示例中举例，可以理解为，set在构造时， 在set容器内 需要生成一个对象用于比较时调用
		// 例：
		// template<typename Key, typename Compare> //简化的set容器的假设实现
		// class set {
		//		Compare comp;  // 存储比较器
		// public:
		//		set() : comp(Compare()) {}  // 构造时调用函数对象的默认构造生成比较器实例
		//		set(Compare c) : comp(c) {}  // 构造时拷贝比较器
		//	};
		//	在插入数据时，调用comp(Key k1,Key k2)进行数据比较用于排序
		// 
		// 当第二个模板参数是 函数对象的类型时，实际可以理解为传入了一个类或结构体 的类型
		// set<int, MyCompare<int>>s2;
		// 类或结构体这种类型 可以调用其构造函数，生成可调用对象 
		// 所以在set<int, MyCompare<int>>s2;构造容器时，s2不需要传入值，调用set的默认构造
		// 可以调用函数对象的构造函数，生成比较器实例，用于后续数据比较用于排序
		// 相当于 Compare comp = MyCompare<int>(); ，比较时调用comp(Key k1,Key k2)
		// 
		// 当第二个模板参数是 函数指针时，需要传入函数的地址的类型 ，且构造时需要传入函数指针
		// set<int, decltype(&myCom<int>)>s2(myCom<int>);
		// 首先，构造时需要传入函数指针，即s2(myCom<int>)
		// 是因为，函数指针没法通过调用默认构造的方式生成可调用对象，不像类或结构体有这个功能
		// 所以构造时需要传入函数指针，用于构造生成存储比较器对象
		// 示例中decltype(&myCom<int>)实际的值是bool(*)(int, int) 是一个函数的指针
		// 为什么需要&，是因为myCom<int>是函数本身，而不是函数指针，类型是bool(int, int)
		// 函数本身可以直接()调用，但是不能被实例化存储，也就不能满足在set容器对象中生成Compare comp;的需求
		// 即在set(Compare c) : comp(c)构造时，会导致异常
		// 使用&后，其类型变为指针，指针就可以直接在构造时被赋值给comp成员了
		// set<int, decltype(&myCom<int>)>s2(myCom<int>);构造时的流程可以理解为
		//	set的第二个模板参数Compare是&myCom<int>这个类型的
		//	调用set(Compare c) : comp(c)，用myCom<int>指针对comp进行赋值
		//	后续比较时调用(*comp)(Key k1,Key k2)
		// 
		// 当第二个模板参数是 Lambda表达式时，传入的实际是一个类的对象 ，构造时传入的实际也是一个类的对象
		// set<int, decltype(com<int>)>s2(com<int>);
		//	template<typename T>
		//	auto com = [](T v1, T v2) {
		//		return v1 > v2;
		//	};
		// 上述的Lambda表达式[](T v1, T v2) { return v1 > v2; };，可以理解为，生成了一个​唯一的匿名类
		// 即：
		//	template<typename T>
		//	class __AnonymousLambdaClass {
		//	public:
		//		bool operator()(T v1, T v2) const {
		//			return v1 > v2;
		//		}
		//	};
		// 然后，auto com =该Lambda表达式，可以理解为实例化了该类，并赋值给com，即com实际是一个类的对象
		// 且其重载了()运算符，实际上是一个函数对象
		// 所以set<int, decltype(com<int>)>s2(com<int>);
		// 实际第二个模板参数decltype(com<int>)，表示的是函数对象的类型
		// 在构造时s2(com<int>)，传入的是函数对象，用于拷贝赋值给comp成员
		// 后续比较时调用comp(Key k1,Key k2)
		//
		//补充扩展
		// 算法库中的sort中的第三个参数需求就和上述描述中 set容器中生成Compare comp;存储比较器 的情况类似
		// sort第三个参数也可以用 函数对象 函数指针 和 Lambda表达式 这三种方式实现
		//	函数对象：sort(c.begin(),c.end(),gerater<int>())
		//	//需要函数对象实例，所以需要在gerater<int>后有()，相当于生成匿名的函数对象
		//	函数指针：sort(c.begin(),c.end(),fun)
		//	//此时传入的是函数指针，在算法内部可能也是用拷贝函数指针，再用函数指针调用函数的方式实现比较
		//	Lambda表达式：sort(c.begin(), c.end(), [](int v1, int v2) {return v1 > v2;});
		//	//由于Lambda表达式实际上就是生成了一个匿名的函数对象，所以可以直接用Lambda表达式
		//	//如果Lambda表达式在其他地方声明，且赋值给了变量，直接传入变量即可，相当于传入函数对象
		//	例：sort(c.begin(), c.end(),com<int>);//以上述实例为例



		//类型测试
		//cout <<"MyCompare<int> typename : " << typeid(MyCompare<int>).name() << endl;
		//decltype(myCom<int>) temp1;
		//cout <<"decltype(myCom<int>) typename : " << typeid(temp1).name() << endl;
		//decltype(&com<int>) temp2;
		//cout <<"decltype(&com<int>) typename : " << typeid(temp2).name() << endl;
		//cout <<"decltype(com<int>) typename : " << typeid(decltype(com<int>)).name() << endl;
		//cout <<"com<int> typename : " << typeid(com<int>).name() << endl;
		for (int i = 0;i < 10;i++) { s2.insert(i); }
		fun1_1(s2);
		

		//自定义数据类型及其排序规则设置
		//set<Class1> s3;//Class1实现了><运算符重载，或者可以传入set的第二个模板参数，进行排序规则控制
		set<Class1,decltype(com<Class1>)> s3(com<Class1>);
		for (int i = 0;i < 10;i++) { s3.insert(Class1(("str" + to_string(i)),i)); }
		fun1_1(s3);


	}

	//map测试项
	void fun2()
	{
		cout << "\n\nTest_fun2" << endl;
		//map和set基本类似，不过存储的是键值对

		//map insert()的返回值
		map<int, int>m1;
		auto ret =  m1.insert(pair<int, int>(1, 1));
		cout << "return type: " << typeid(ret).name() << endl;
		cout << "key: " << (*ret.first).first << " value: " << (*ret.first).second << " bool: " << ret.second << endl;
		ret = m1.insert(pair<int, int>(1, 1));
		cout << "key: " << (*ret.first).first << " value: " << (*ret.first).second << " bool: " << ret.second << endl;


		//map insert的不同方式，暂不做测试

		//map元素访问 支持[]和at访问
		map<int, int,greater<int>>m2;
		for (int i = 0;i < 10;i++) { m2.insert(pair<int,int>(i,i)); }
		for_each(m2.begin(), m2.end(),[](pair<int,int> p){
			cout << "key: " << p.first << " value: " << p.second << endl;
		});
		cout << endl;
		//确实是降序了，但是[]和at访问却没有变
		//是因为[]和at访问的是对应键的值，键为3、4的值就是3、4
		cout << m2[3] << endl;
		cout << m2.at(4) << endl;

		//map容器排序，按key进行排序，规则与set容器类似，参考set容器即可，不做测试
	}

	//案例-员工分组
	#define DepartmentNum 3
	class Class3
	{
	public:
		string m_Name;
		int m_Salary;
		int m_DepartmentId;
		Class3(string name, int salary, int dId) :m_Name(name), m_Salary(salary), m_DepartmentId(dId) {}
	};
	ostream& operator<<(ostream& ostr, const Class3& other)
	{
		return cout << "name :" << other.m_Name << " salary :" << other.m_Salary << " departmentId :" << other.m_DepartmentId << endl;
	}
	void fun3_1(int& cutDID,int empDID)//用于输出 部门 行//递归输出，直到没有员工的 部门 行 都输出完毕
	{
		if (cutDID != empDID)
		{
			cutDID++;
			cout << "部门" << cutDID << ": " << endl;
			fun3_1(cutDID, empDID);
		}
	}
	void fun3()
	{
		cout << "\n\nTest_fun3" << endl;

		//设置随机数种子
		srand((unsigned int)time(NULL));

		char temp[] = "ABCDEFGHIJ";
		multimap<int, Class3> employeeMap;
		for (int i = 0;i < 10;i++)
		{
			int id = rand() % DepartmentNum;
			employeeMap.insert(pair<int, Class3>(id, Class3(string(1,temp[i]), rand()%6000+6000, id)));
		}

		int department = -1;
		for (multimap<int, Class3>::iterator it = employeeMap.begin();it != employeeMap.end();it++)
		{
			fun3_1(department, (*it).first);
			cout << "\t" << (*it).second;
		}

	}

	//函数对象(仿函数)测试项
	void fun4()
	{
		cout << "\n\nTest_fun4" << endl;
		//暂不做测试
		//类或结构体中重载了()运算符，被称为函数对象(仿函数)
		//其实例化的对象可以直接()的方式调用其重载的()运算符，达到类似函数调用的效果
		//其实例化的对象，可以作为函数的参数，传入函数中后，再用()的方式调用其重载的()运算符
		//其实例化的对象中，可以存在成员变量，且可以在调用仿函数时调用


		//暂不做测试
		//谓词
		//返回bool类型的仿函数称为谓词
		//如果operator()接收一个参数，叫做一元谓词
		//如果operator()接收两个参数，叫做二元谓词


		//暂不做测试
		//内建的函数对象
		//需#include<functional>
		//分类：
		// 算术仿函数
		// 关系仿函数
		// 逻辑仿函数
		// 

	}

	//算法测试项
	void fun5()
	{
		cout << "\n\nTest_fun5" << endl;

		//暂不做测试
		//主要是了解算法的作用，参数和返回值，还有算法支持的容器或迭代器
		//很多内容在视频中没有涉及到需要自己去看和补充
		//	很多的算法和仿函数都没有涉及
		//	仿函数和算法的搭配使用没有涉及
		//	bind绑定辅助解决二元谓词变为一元谓词
		//	很多常用处理方式可能需要自己去发掘
		//	各种语法糖可能需要自己去发掘



	}

	void fun6()
	{
		cout << "\n\nTest_fun6" << endl;
	}

}




void testLeftProject()
{
	//set测试项
	fun1();

	//map测试项
	fun2();

	//案例-员工分组
	fun3();

	//函数对象(仿函数)测试项
	fun4();

	//算法测试项
	fun5();



}




