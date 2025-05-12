#include "DequeTest.h"

namespace
{
	class Class1
	{
	public:
		string m_Str;
		Class1() :m_Str("str") {}
		Class1(string str) :m_Str(str) {}
		friend ostream& operator<<(ostream& cout, const Class1& c);
	};
	ostream& operator<<(ostream& cout,const Class1& c)
	{
		return cout << c.m_Str;
	}
	template<typename T>
	void fun1_1(deque<T> d)
	{
		//遍历方式一：
		//for (typename deque<T>::iterator it = d.begin();it != d.end();it++)
		//{
		//	cout << *it << " ";
		//	//cout << typeid(it).name() << endl;
		//}
		//遍历方式一：
		//for (auto it = d.begin();it != d.end();it++)
		//{
		//	cout << *it << " ";
		//	//cout << typeid(it).name() << endl;
		//}
		//遍历方式二：
		/*for_each(d.begin(), d.end(), [](T elem) {
			cout << elem << " ";
		});*/
		//遍历方式三：
		for (const T& elem : d)
		{
			cout << elem << " ";
		}
		cout << endl;
	}
	template<typename T>
	void fun1_2(const deque<T>& d)
	{
		//当容器是 const 时,d.begin() 和 d.end() 在 const 对象上返回的是 const_iterator
		//必须要用const_iterator(常量迭代器)类型迭代器接收返回值
		for (typename deque<T>::const_iterator it = d.begin();it != d.end();it++)
		{
			cout << *it << " ";
			//cout << typeid(it).name() << endl;
		}
		cout << endl;
	}
	//构造测试
	void fun1()
	{
		cout << "\n\nTest_fun1" << endl;

		//函数原型：
		//	基本构造方式：
		//	 deque()	默认构造空deque	deque<int> d1;
		//	 deque(size_type n)	构造含n个默认值元素的deque	deque<int> d2(5); // 5个0
		//	 deque(size_type n, const T & value)	构造含n个value的deque	deque<int> d3(5, 10); // 5个10
		//	 deque(const deque & other)	拷贝构造	deque<int> d4(d3);
		//	 deque(deque && other)	移动构造(C++11)	deque<int> d5(std::move(d4));
		//	 deque(initializer_list<T> il)	初始化列表构造(C++11)	deque<int> d6{ 1, 2, 3 };
		//	特殊初始化方式：
		//	 从数组初始化
		//	 int arr[] = { 1, 2, 3 };
		//	 deque<int> d7(arr, arr + sizeof(arr) / sizeof(arr[0]));
		//	 从迭代器范围初始化
		//	 deque<int> d8(d7.begin(), d7.end());
		//	 C++11统一初始化
		//	 deque<string> d9 = { "apple", "banana", "orange" };

		//deque()默认构造
		deque<int> d1;
		for (int i = 4;i >=0;i--) { d1.push_front(i); }
		for (int i = 5;i <10;i++) { d1.push_back(i); }
		fun1_1(d1);
		//fun1_2(d1);
		// 
		//deque(size_type n)	构造含n个默认值元素的deque
		deque<Class1>d2(5);
		fun1_1(d2);

		//deque(size_type n, const T & value)	构造含n个value的deque
		deque<Class1>d3(3, Class1("str3"));
		fun1_1(d3);

		//	 deque(const deque & other)	拷贝构造
		deque<Class1>d4(d3);
		fun1_1(d4);

		//	 deque(deque && other)	移动构造(C++11)
		deque<Class1>d5(move(d4));
		fun1_1(d4);
		fun1_1(d5);

		//	 deque(initializer_list<T> il)	初始化列表构造(C++11)
		deque<Class1>d6({ Class1("str"),Class1("str1") ,Class1("str2") });
		fun1_1(d6);

		//从数组初始化
		Class1 arr1[] = { Class1("str4"),Class1("str5") ,Class1("str6") };
		deque<Class1> d7(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
		fun1_1(d7);

		//从迭代器范围初始化
		deque<int>d8(d1.begin() + 1, d1.end() - 1);
		fun1_1(d8);

		//C++11统一初始化
		deque<Class1> d9 = { Class1("str7"),Class1("str8") ,Class1("str9") };
		fun1_1(d9);
	}

	//deque赋值操作
	void fun2()
	{
		cout << "\n\nTest_fun2" << endl;

		//函数原型：
		//	deque& operator=( const deque& other );//拷贝赋值
		//	deque& operator=(deque && other);//移动赋值
		//	deque& operator=(deque && other) noexcept;//移动赋值
		//	deque& operator=(std::initializer_list<value_type> ilist);//初始化列表赋值 (C++11)
		//	void assign( size_type count, const T& value );
		//	template< class InputIt >
		//	void assign(InputIt first, InputIt last);
		//	void assign(std::initializer_list<T> ilist);
		//
		deque<int> d1(3, 100);
		deque<int>d2 = d1;
		fun1_1(d1);
		fun1_1(d2);

		deque<int>d3 = move(d1);
		fun1_1(d3);
		fun1_1(d1);

		deque<int>d4 = { 1,2,3 };
		fun1_1(d4);

		deque<int>d5;
		d5.assign(5, 66);
		fun1_1(d5);

		deque<int>d6;
		d6.assign(d5.begin(), d5.end());
		fun1_1(d6);

		deque<int>d7;
		d7.assign({ 4,5,6 });
		fun1_1(d7);
	}

	//deque容量操作
	void fun3()
	{
		cout << "\n\nTest_fun3" << endl;

		//函数原型：
		//	 empty()	检查是否为空	if(d.empty())
		//	 size()	返回元素数量	size_t n = d.size();
		//	 resize(size_type n)	调整元素数量	d.resize(10);
		//		重新执行容器的长度后，若容器变长，则以默认值填充新的位置，变长时会修改capacity()
		// 		重新执行容器的长度后，若容器变短，末尾超出容器长度的元素被删除，变短时不会修改capacity()
		//	 resize(size_type n, const T& value)	调整元素数量	d.resize(10);
		//		重新执行容器的长度后，若容器变长，则以value填充新的位置，变长时会修改capacity()
		// 		重新执行容器的长度后，若容器变短，末尾超出容器长度的元素被删除，变短时不会修改capacity()
		//	 shrink_to_fit()	减少内存使用(C++11)	d.shrink_to_fit();

		deque<int>d1;
		cout << d1.empty() << endl;
		cout << d1.size() << endl;
		d1.push_front(0);
		cout << d1.empty() << endl;
		cout << d1.size() << endl;

		d1.resize(3);
		fun1_1(d1);
		d1.resize(5, 100);
		fun1_1(d1);
		cout << d1.size() << endl;
		d1.resize(1);
		fun1_1(d1);
		cout << d1.size() << endl;

		d1.shrink_to_fit();

	}

	//deque插入和删除
	void fun4()
	{
		cout << "\n\nTest_fun4" << endl;

		//函数原型：
		//	 push_back(const T&)	末尾添加元素	O(1)
		//	 emplace_back(Args&&...)	末尾直接构造元素(C++11)	O(1)
		//	 push_front(const T&)	开头添加元素	O(1)
		//	 emplace_front(Args&&...)	开头直接构造元素(C++11)	O(1)
		//	 pop_back()	删除末尾元素	O(1)
		//	 pop_front()	删除开头元素	O(1)
		//	 insert(iterator pos, const T&)	在指定位置插入元素	O(n)
		//	 insert(iterator pos, size_type n, const T&)	在指定位置插入n个元素	O(n)
		//	 insert(iterator pos, InputIt first, InputIt last)	在指定位置插入first到last区间的元素(左闭右开)	O(n)
		//	 emplace(iterator pos, Args&&...)	在指定位置直接构造元素(C++11)	O(n)
		//	 erase(iterator pos)	删除指定位置元素	O(n)
		//	 erase(InputIt first, InputIt last)	删除区间的元素(左闭右开)	O(n)
		//	 clear()	清空所有元素	O(n)
		//	 swap(deque&)	交换内容	O(1)
		deque<int>d1;
		for (int i = 0;i < 5;i++) { d1.push_back(i); }
		for (int i = 0;i < 5;i++) { d1.emplace_back(i); }
		for (int i = 0;i < 5;i++) { d1.push_front(i); }
		for (int i = 0;i < 5;i++) { d1.emplace_front(i); }
		fun1_1(d1);
		d1.pop_back();
		d1.pop_front();
		fun1_1(d1);

		d1.insert(d1.begin(), 100);
		d1.insert(d1.end(), 2, 100);
		fun1_1(d1);
		//d1.insert(d1.begin(), d1.begin(), d1.begin() + 3);//可能会导致迭代器失效或未定义行为，一般不使用自插入
		deque<int>temp(d1.begin(), d1.begin() + 3);
		d1.insert(d1.begin(), temp.begin(), temp.end());
		fun1_1(d1);
		d1.emplace(d1.begin() + 2, 1000);
		fun1_1(d1);

		d1.erase(d1.begin() + 2);
		fun1_1(d1);
		d1.erase(d1.begin() + 1, d1.end() - 1);
		fun1_1(d1);
		d1.clear();
		fun1_1(d1);

		deque<int>d2(5, 100);
		d1.swap(d2);
		fun1_1(d1);
		fun1_1(d2);

	}

	//deque元素访问
	void fun5()
	{
		cout << "\n\nTest_fun5" << endl;

		//函数原型：
		//	 operator[]	无检查访问	O(1)
		//	 at(size_type pos)	有边界检查的访问	O(1)
		//	 front()	访问首元素	O(1)
		//	 back()	访问末元素	O(1)
		deque<int>d1{ 0,1,2,3,4,5,6 };

		for (int i = 0;i < d1.size();i++)
		{
			cout << d1[i] << " ";
		}
		cout << endl;
		for (int i = 0;i < d1.size();i++)
		{
			//cout << d1.at(i) << " ";
			d1.at(i) = 0;
		}
		//cout << endl;
		fun1_1(d1);
		cout << d1.front() << endl;
		cout << d1.back() << endl;
		
	}

	//deque容器排序
	bool fun6_1(int a,int b)
	{
		return a > b;//降序排序
	}
	void fun6()
	{
		cout << "\n\nTest_fun6" << endl;

		//函数原型：
		//	template< class RandomIt >
		//	void sort(RandomIt first, RandomIt last);
		//	
		//	template< class RandomIt, class Compare >
		//	void sort(RandomIt first, RandomIt last, Compare comp);

		deque<int>d1{ 10,1,1,5,9,6,75,63,21,54,12,55,3,77,75,63 };
		fun1_1(d1);
		sort(d1.begin(), d1.end());
		fun1_1(d1);

		deque<int>d2{ 10,1,1,5,9,6,75,63,21,54,12,55,3,77,75,63 };
		fun1_1(d2);
		sort(d2.begin(), d2.end(), [](int a,int b) {
			return a < b;//升序排序
		});
		fun1_1(d2);

		deque<int>d3{ 10,1,1,5,9,6,75,63,21,54,12,55,3,77,75,63 };
		fun1_1(d3);
		sort(d3.begin(), d3.end(), fun6_1);
		fun1_1(d3);
	}

	//案例 评委打分
	class Class7
	{
	public:
		string m_Name;
		deque<int> m_Score;
	};
	void fun7_1(vector<Class7> pv)
	{
		for (int i = 0;i < pv.size();i++)
		{
			cout << "name :" << pv.at(i).m_Name << endl;
			cout << "score :";
			for (int j = 0;j < pv.at(i).m_Score.size();j++)
			{
				cout << " " << pv.at(i).m_Score.at(j);
			}
			cout << endl;
		}
	}
	void fun7()
	{
		cout << "\n\nTest_fun7" << endl;

		srand((unsigned int)time(NULL));

		//创建选手及放置数据
		vector<Class7> pv;
		for (int i = 0;i < 5;i++)
		{
			Class7 c;
			c.m_Name = (char)(65 + i);
			for (int j = 0;j < 10;j++)
			{
				c.m_Score.push_back((rand() % 11));
			}
			pv.push_back(c);
		}
		fun7_1(pv);
		//排序，去除最高最低分
		for (int i = 0;i < pv.size();i++)
		{
			sort(pv.at(i).m_Score.begin(), pv.at(i).m_Score.end());
			pv.at(i).m_Score.pop_back();
			pv.at(i).m_Score.pop_front();
		}
		fun7_1(pv);
		//计算总分和平均分
		for (int i = 0;i < pv.size();i++)
		{
			int sum = 0;
			double average = 0;
			for (int j = 0;j < pv.at(i).m_Score.size();j++)
			{
				sum += pv.at(i).m_Score.at(j);
			}
			average = (double)sum / pv.at(i).m_Score.size();
			cout << "name :" << pv.at(i).m_Name << endl;
			cout << "sum :" << sum << endl;
			cout << "average :" << average << endl;
		}

	}
}



void testDeque()
{
	//Deque容器
	// std::deque（双端队列，发音为"deck"）是C++标准模板库(STL)中的一个序列容器，它结合了vector和list的优点，支持在两端高效插入和删除元素。
	// 
	// 1. 基本特性
	//	头文件​​：#include <deque>
	//	命名空间​​：std
	//	本质​​：动态数组的双端队列实现
	//	内存管理​​：分块存储（通常实现为多个固定大小的数组）
	//	访问效率​​：支持O(1)时间的随机访问
	//	插入 / 删除效率​​：
	//	两端操作：O(1)时间
	//	中间操作：O(n)时间
	// 
	// 2. 构造与初始化
	//	基本构造方式：
	//	 deque()	默认构造空deque	deque<int> d1;
	//	 deque(size_type n)	构造含n个默认值元素的deque	deque<int> d2(5); // 5个0
	//	 deque(size_type n, const T & value)	构造含n个value的deque	deque<int> d3(5, 10); // 5个10
	//	 deque(const deque & other)	拷贝构造	deque<int> d4(d3);
	//	 deque(deque && other)	移动构造(C++11)	deque<int> d5(std::move(d4));
	//	 deque(initializer_list<T> il)	初始化列表构造(C++11)	deque<int> d6{ 1, 2, 3 };
	//	特殊初始化方式：
	//	 从数组初始化
	//	 int arr[] = { 1, 2, 3 };
	//	 deque<int> d7(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//	 从迭代器范围初始化
	//	 deque<int> d8(d7.begin(), d7.end());
	//	 C++11统一初始化
	//	 deque<string> d9 = { "apple", "banana", "orange" };
	// 
	// 3. 核心成员函数
	//	元素访问：
	//	 operator[]	无检查访问	O(1)
	//	 at(size_type pos)	有边界检查的访问	O(1)
	//	 front()	访问首元素	O(1)
	//	 back()	访问末元素	O(1)
	//	容量操作：
	//	 empty()	检查是否为空	if(d.empty())
	//	 size()	返回元素数量	size_t n = d.size();
	//	 resize(size_type n)	调整元素数量	d.resize(10);
	//		重新执行容器的长度后，若容器变长，则以默认值填充新的位置，变长时会修改capacity()
	// 		重新执行容器的长度后，若容器变短，末尾超出容器长度的元素被删除，变短时不会修改capacity()
	//	 resize(size_type n, const T& value)	调整元素数量	d.resize(10);
	//		重新执行容器的长度后，若容器变长，则以value填充新的位置，变长时会修改capacity()
	// 		重新执行容器的长度后，若容器变短，末尾超出容器长度的元素被删除，变短时不会修改capacity()
	//	 shrink_to_fit()	减少内存使用(C++11)	d.shrink_to_fit();
	//	修改操作：
	// 	 operator=	赋值操作	v1 = v2;
	//	 assign()	多种重载的赋值	//使用迭代器范围进行赋值时，前闭后开
	//	 push_back(const T&)	末尾添加元素	O(1)
	//	 emplace_back(Args&&...)	末尾直接构造元素(C++11)	O(1)
	//	 push_front(const T&)	开头添加元素	O(1)
	//	 emplace_front(Args&&...)	开头直接构造元素(C++11)	O(1)
	//	 pop_back()	删除末尾元素	O(1)
	//	 pop_front()	删除开头元素	O(1)
	//	 insert(iterator pos, const T&)	在指定位置插入元素	O(n)
	// 	 insert(iterator pos, size_type n, const T&)	在指定位置插入n个元素	O(n)
	//	 insert(iterator pos, InputIt first, InputIt last)	在指定位置插入first到last区间的元素(左闭右开)	O(n)
	//	 emplace(iterator pos, Args&&...)	在指定位置直接构造元素(C++11)	O(n)
	//	 erase(iterator pos)	删除指定位置元素	O(n)
	// 	 erase(InputIt first, InputIt last)	删除区间的元素(左闭右开)	O(n)
	//	 clear()	清空所有元素	O(n)
	//	 swap(deque&)	交换内容	O(1)
	// 4. 迭代器支持
	// 	deque容器的迭代器支持随机访问
	//	 v.begin()	//指向第一个元素
	//	 v.end()		//指向最后一个元素的下一个位置
	//	 v.rbegin()	//指向第一个元素的上一个位置
	//	 v.rend()	//指向倒数第一个元素
	//	deque 支持所有标准迭代器操作：
	//	 deque<int> d = {1, 2, 3, 4, 5};
	//	 正向迭代
	//	 for (auto it = d.begin(); it != d.end(); ++it) {
	//	 	cout << *it << " ";
	//	 }
	//	 // 反向迭代
	//	 for (auto rit = d.rbegin(); rit != d.rend(); ++rit) {
	//	 	cout << *rit << " ";
	//	 }
	//	 // 基于范围的for循环 (C++11)
	//	 for (int num : d) {
	//	 	cout << num << " ";
	//	 }
	//	 // 常量迭代器
	//	 for (auto cit = d.cbegin(); cit != d.cend(); ++cit) {
	//	 	// *cit = 10; // 错误，不能修改
	//	 }
	// 
	// 5. 内存管理与性能
	//	内存结构：
	//	 deque 通常实现为多个固定大小的数组块（称为"块"或"页"），通过中央控制结构管理这些块：
	//	 1、每个块存储固定数量的元素（如512字节 / 元素大小）
	//	 2、中央控制结构维护块指针数组
	//	 3、支持在两端高效扩展而不需要移动现有元素
	//	性能特点：
	//	 优点​​：
	//	 两端插入 / 删除高效
	//	 随机访问接近vector的效率
	//	 不需要像vector那样的大规模内存重分配
	//	 缺点​​：
	//	 比vector占用更多内存（需要维护控制结构）
	//	 迭代器比vector更复杂，可能影响性能
	//	 中间插入 / 删除效率不高
	// 
	// 6. 注意事项
	// ​​	1、迭代器失效​​：
	//	 插入操作可能使所有迭代器失效（与vector类似）
	//	 删除操作通常只影响被删除元素的迭代器
	//	2、​​内存使用​​：
	//	 deque通常比vector占用更多内存
	//	 没有capacity()和reserve()成员函数
	//	3、​​性能考虑​​：
	//	 如果需要频繁中间插入，考虑使用list
	//	 如果需要频繁随机访问，考虑使用vector
	//	 如果需要两端操作，deque是最佳选择
	//	4、线程安全​​：
	//	 不同线程可以同时读取同一deque
	//	 任何写操作都需要同步机制
	
	//deque和vector的区别：
	// vector对于头部的插入删除效率低，数据量越大，效率越低
	// deque相对而言，对头部的插入和删除速度比vector快
	// vector访问元素的速度会比deque快，这和两者的内部实现有关
	//  vector存放数据为完全连续的内存空间，头部插入时，需要把整个容器的所有数据都往后移动
	//  deque存放数据为部分连续的内存空间，数据存放在缓冲区，并通过中控器维护每段缓冲区的内容

	//构造测试
	fun1();

	//deque赋值操作
	fun2();

	//deque容量操作
	fun3();

	//deque插入和删除
	fun4();

	//deque元素访问
	fun5();

	//deque容器排序
	fun6();

	//案例 评委打分
	fun7();
}