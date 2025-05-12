#include "VectorTest.h"

namespace
{
	//构造测试
	class Class1
	{
	public:
		string m_Str;
		friend ostream& operator<<(ostream& cout, const Class1& c);
		Class1() :m_Str("str") {}
		Class1(string str) :m_Str(str) {}

	};
	ostream& operator<<(ostream& cout, const Class1& c)
	{
		return cout << c.m_Str;
	}
	template<typename T>
	void fun1_1(vector<T> v)
	{
		for_each(v.begin(), v.end(), [](T elem) {
			cout << elem << " ";
		});
		cout << endl;
	}
	void fun1()
	{
		cout << "\n\nTest_fun1" << endl;
		//默认构造
		vector<int> v1;
		for (int i = 0;i < 10;++i) { v1.push_back(i); }
		fun1_1(v1);
		cout << v1.capacity() << endl;
		//构造含有n个默认值元素的容器
		vector<Class1> v2(5);
		fun1_1(v2);
		cout << v2.capacity() << endl;
		//构造含有n个value的容器
		vector<Class1> v3(5, Class1("str2"));
		fun1_1(v3);
		cout << v3.capacity() << endl;
		//拷贝构造
		vector<Class1> v4(v3);
		fun1_1(v4);
		cout << v4.capacity() << endl;
		//移动构造
		vector<Class1> v5(move(v4));
		fun1_1(v5);
		cout << v5.capacity() << endl;
		fun1_1(v4);
		cout << v4.capacity() << endl;
		//初始化列表构造
		vector<int> v6{ 1,2,3 };
		vector<Class1> v7{ Class1(),Class1("str2"),Class1("str3") };
		fun1_1(v6);
		fun1_1(v7);
		cout << v6.capacity() << endl;
		cout << v7.capacity() << endl;
		//从数组初始化
		Class1 arr1[3];
		vector<Class1> v8(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
		//vector<Class1> v8(arr1, arr1 + 5);//作用同上
		fun1_1(v8);
		cout << v8.capacity() << endl;
		//从迭代器范围初始化
		vector<int> v9(v1.begin(), v1.end());
		vector<int> v10(v1.begin()+1, v1.end()-1);
		fun1_1(v9);
		fun1_1(v10);
		cout << v9.capacity() << endl;
		cout << v10.capacity() << endl;
		//C++1统一初始化
		vector<string> v11 = { "a","b","c" };
		fun1_1(v11);
		cout << v11.capacity() << endl;
	}

	//vector赋值操作
	void fun2()
	{
		//函数原型：
		//	vector& operator=( const vector& other );//拷贝赋值
		//	vector& operator=(vector && other);//移动赋值
		//	vector& operator=(vector && other) noexcept//移动赋值
		//	vector& operator=(std::initializer_list<value_type> ilist);//初始化列表赋值
		//	void assign( size_type count, const T& value );
		//	template< class InputIt >
		//	void assign(InputIt first, InputIt last);
		//	void assign(std::initializer_list<T> ilist);

		cout << "\n\nTest_fun2" << endl;
		vector<int> v1 = { 1,2,3,4,5 };
		vector<int> v2;
		for (int i = 0;i < 5;++i) { v2.push_back(i); }
		cout << v1.capacity() << endl;
		cout << v2.capacity() << endl;
		v2 = v1;
		cout << v2.capacity() << endl;
		v2.shrink_to_fit();
		cout << v2.capacity() << endl;

		vector<int>v3;
		v3 = v1;
		fun1_1(v3);
		vector<int>v4;
		v4 = move(v3);
		fun1_1(v3);
		fun1_1(v4);
		vector<int>v5;
		auto ilist = { 100,100,100,100,100 };
		v5 = ilist;
		cout << typeid(ilist).name() << endl;
		fun1_1(v5);

		vector<int>v6;
		v6.assign(5, 1);
		fun1_1(v6);
		vector<int>v7;
		v7.assign(v6.begin(), v6.end() - 1);
		fun1_1(v7);
		vector<int>v8;
		v8.assign({ 1,2,3,4,5 });
		fun1_1(v8);
	}

	//vector容量和大小
	void fun3()
	{
		cout << "\n\nTest_fun3" << endl;

		//函数原型：
		//	empty()	检查是否为空	if(v.empty())
		//	size()	返回元素数量	size_t n = v.size();
		//	max_size()	返回容器可容纳的最大元素数量	size_t n = v.max_size();
		//	capacity()	返回当前存储容量	size_t cap = v.capacity();
		//	reserve(size_type n)	预留存储空间	v.reserve(100);
		//	shrink_to_fit()	减少容量以适应大小(C++11)	v.shrink_to_fit();
		//	resize(size_type n)	调整元素数量	O(n)
		//		重新执行容器的长度后，若容器变长，则以默认值填充新的位置，变长时会修改capacity()
		//		重新执行容器的长度后，若容器变短，末尾超出容器长度的元素被删除，变短时不会修改capacity()被删除
		//	resize(size_type n ,const T& value)	调整元素数量	O(n)
		//		重新执行容器的长度后，若容器变长，则以value填充新的位置，变长时会修改capacity()
		//		重新执行容器的长度后，若容器变短，末尾超出容器长度的元素被删除，变短时不会修改capacity()被删除

		vector<int>v1;
		cout << v1.empty() << endl;
		for (int i = 0;i < 10;++i) { v1.push_back(i); }
		fun1_1(v1);
		cout << v1.empty() << endl;

		cout << v1.size() << endl;
		cout << v1.max_size() << endl;
		cout << v1.capacity() << endl;

		v1.reserve(100);
		fun1_1(v1);
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;

		v1.shrink_to_fit();
		fun1_1(v1);
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;

		v1.resize(20);
		fun1_1(v1);
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;

		v1.resize(5);
		fun1_1(v1);
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;

		v1.resize(10,100);
		fun1_1(v1);
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;

		v1.resize(1, 100);
		fun1_1(v1);
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
	}

	//vector插入和删除
	void fun4()
	{
		cout << "\n\nTest_fun4" << endl;
		//函数原型：
		//	push_back(const T&)	末尾添加元素	O(1)分摊
		//	emplace_back(Args&&...)	末尾直接构造元素(C++11)	O(1)分摊
		//	pop_back()	删除末尾元素	O(1)//返回void，不会返回删除的元素
		//	insert(iterator pos, const T&)	在指定位置插入元素	O(n)
		//	insert(iterator pos, size_type n, const T&)	在指定位置插入n个元素	O(n)
		//	emplace(iterator pos, Args&&...)	在指定位置直接构造元素(C++11)	O(n)
		//	erase(iterator pos)	删除指定位置元素	O(n)
		//	erase(iterator start, iterator end)	删除迭代器范围的元素，前闭后开	O(n)
		//	clear()	清空所有元素	O(n)

		vector<int> v1;
		fun1_1(v1);
		v1.push_back(1);
		fun1_1(v1);
		v1.emplace_back(2);
		fun1_1(v1);
		v1.pop_back();
		fun1_1(v1);
		//vector容器是一个连续的动态数组，必须按顺序填充元素，不能跳过前面的位置直接在后面插入元素。
		//v1.insert(v1.begin()+10, 100);//超出capacity时会报错
		//v1.reserve(100);
		//cout << v1.capacity() << endl;
		//v1.insert(v1.begin() + 10, 100);//设置capacity后插入依旧报错
		v1.resize(10);
		//cout << v1.capacity() << endl;//10
		v1.insert(v1.begin() + 9, 100);//将v1[9]放置100，原来的所有元素往后移
		v1.insert(v1.end(), 100);//在末尾，原本无意义的位置放置100
		fun1_1(v1);
		//cout << v1.capacity() << endl;//15
		v1.insert(v1.begin() + 1, 3, 200);
		fun1_1(v1);
		v1.emplace(v1.begin(), 300);
		fun1_1(v1);
		v1.erase(v1.begin() + 1);
		fun1_1(v1);
		v1.erase(v1.begin() + 1, v1.end() - 1);
		fun1_1(v1);
		v1.clear();
		fun1_1(v1);
		cout << v1.size() << endl;
		cout << v1.empty() << endl;
		cout << v1.capacity() << endl;//22
	}

	//vector数据存取
	void fun5()
	{
		cout << "\n\nTest_fun5" << endl;
		//函数原型：
		//	operator[]	无检查访问	O(1)
		//	at(size_type pos)	有边界检查的访问	O(1)
		//	front()	访问首元素	O(1)
		//	back()	访问末元素	O(1)
		//	data()	返回底层数组指针(C++11)	O(1)

		vector<int>v1(5);
		fun1_1(v1);
		v1[0] = 10;
		fun1_1(v1);
		v1.at(1) = 20;
		fun1_1(v1);
		cout << v1.front() << endl;
		cout << v1.back() << endl;
		cout << v1.data() << endl;

	}

	//vector互换容器
	void fun6()
	{
		cout << "\n\nTest_fun6" << endl;
		//函数原型：
		//	swap(vector&)	交换内容	O(1)

		vector<int>v1 = { 1,2,3 };
		vector<int>v2 = { 10,20,30 };
		fun1_1(v1);
		fun1_1(v2);
		v1.swap(v2);
		fun1_1(v1);
		fun1_1(v2);

		vector<int>v3(5);
		v3.reserve(100);
		cout << v3.size() << endl;
		cout << v3.capacity() << endl;

		//可以用匿名容器对象和swap实现收缩容器capacity
		vector<int>(v3).swap(v3);//先用拷贝构造传入v3，声明了一个匿名对象，匿名对象执行swap函数，将v3和匿名对象进行互换，实现了v3容器对象的capacity收缩，匿名对象在这行代码执行后，会被系统回收
		//v3.shrink_to_fit()//效果同上
		cout << v3.size() << endl;
		cout << v3.capacity() << endl;
	}

	//vector预留空间
	void fun7()
	{
		cout << "\n\nTest_fun7" << endl;
		//函数原型：
		//	reserve(size_type n)	预留存储空间	v.reserve(100);

		int num = 0;
		int capacity = 0;
		vector<int>v1;
		clock_t startTime = clock();
		for (int i = 0;i < 100000;++i)
		{
			if (capacity != v1.capacity())
			{
				capacity = v1.capacity();
				num++;
			}
			v1.push_back(i);
		}
		clock_t endTime = clock();
		cout << num << endl;
		cout << "way1 cost time :" << endTime - startTime << endl;

		int num2 = 0;
		vector<int>v2;
		int* p = nullptr;
		startTime = clock();
		for (int i = 0;i < 100000;i++)
		{
			v2.push_back(i);
			if (p != &v2[0])
			{
				p = &v2[0];
				num2++;
			}
		}
		endTime = clock();
		cout << num2 << endl;
		cout << "way2 cost time :" << endTime - startTime << endl;

		int num3 = 0;
		vector<int>v3;
		int* p2 = nullptr;
		startTime = clock();
		for (int i = 0;i < 100000;i++)
		{
			v3.push_back(i);
			if (p2 != v3.data())
			{
				p2 = v3.data();
				num3++;
			}
		}
		endTime = clock();
		cout << num3 << endl;
		cout << "way3 cost time :" << endTime - startTime << endl;

		int num4 = 0;
		int capacity2 = 0;
		vector<int>v4;
		startTime = clock();
		v4.reserve(100000);
		for (int i = 0;i < 100000;i++)
		{
			if (capacity2 != v4.capacity())
			{
				capacity2 = v4.capacity();
				num4++;
			}
			v4.push_back(i);
		}
		endTime = clock();
		cout << num4 << endl;
		cout << "way4 cost time :" << endTime - startTime << endl;
	}

}



void testVector()
{
	//vector容器
	// std::vector 是 C++ 标准模板库 (STL) 中最重要且最常用的序列容器之一，它提供了动态数组的功能，能够自动管理内存并在运行时动态调整大小。
	// 
	// 1. 基本特性
	//	​​头文件​​：#include <vector>
	//	命名空间​​：std
	//	本质​​：动态数组的类模板实现
	//	内存管理​​：自动处理内存分配和释放
	//	访问效率​​：支持O(1)时间的随机访问
	//	插入 / 删除效率​​：
	//		末尾操作：O(1)分摊时间
	//		中间/开头操作：O(n)时间
	//	
	// 2. 构造与初始化
	// 基本构造方式：
	//	vector()	默认构造空vector	vector<int> v1;
	//	vector(size_type n)	构造含n个默认值元素的vector	vector<int> v2(5); // 5个0
	//	vector(size_type n, const T & value)	构造含n个value的vector	vector<int> v3(5, 10); // 5个10
	//	vector(const vector & other)	拷贝构造	vector<int> v4(v3);
	//	vector(vector && other)	移动构造(C++11)	vector<int> v5(std::move(v4));
	//	vector(initializer_list<T> il)	初始化列表构造(C++11)	vector<int> v6{ 1, 2, 3 };
	// 特殊初始化方式：
	//	从数组初始化
	//	int arr[] = { 1, 2, 3 };
	//	vector<int> v7(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//	从迭代器范围初始化//注意，此方式初始化时，区间为前闭后开，v7.begin()元素会被初始化，v7.end()(无意义元素)元素不会被初始化
	//	vector<int> v8(v7.begin(), v7.end());
	//	C++11统一初始化
	//	vector<string> v9 = { "apple", "banana", "orange" };
	//	
	// 3. 核心成员函数
	// 元素访问：
	//	operator[]	无检查访问	O(1)
	//	at(size_type pos)	有边界检查的访问	O(1)
	//	front()	访问首元素	O(1)
	//	back()	访问末元素	O(1)
	//	data()	返回底层数组指针(C++11)	O(1)
	// 容量操作：
	//	empty()	检查是否为空	if(v.empty())
	//	size()	返回元素数量	size_t n = v.size();
	//	max_size()	返回容器可容纳的最大元素数量	size_t n = v.max_size();
	//	capacity()	返回当前存储容量	size_t cap = v.capacity();
	//	reserve(size_type n)	预留存储空间	v.reserve(100);
	//	shrink_to_fit()	减少容量以适应大小(C++11)	v.shrink_to_fit();
	// 修改操作：
	//	operator=	赋值操作	v1 = v2;
	//	assign()	多种重载的赋值	//使用迭代器范围进行赋值时，前闭后开
	//	push_back(const T&)	末尾添加元素	O(1)分摊
	//	emplace_back(Args&&...)	末尾直接构造元素(C++11)	O(1)分摊
	//	pop_back()	删除末尾元素	O(1)//返回void，不会返回删除的元素
	//	insert(iterator pos, const T&)	在指定位置插入元素	O(n)
	//	insert(iterator pos, size_type n, const T&)	在指定位置插入n个元素	O(n)
	//	emplace(iterator pos, Args&&...)	在指定位置直接构造元素(C++11)	O(n)
	//	erase(iterator pos)	删除指定位置元素	O(n)
	//	erase(iterator start, iterator end)	删除迭代器范围的元素，前闭后开	O(n)
	//	clear()	清空所有元素	O(n)
	//	resize(size_type n)	调整元素数量	O(n)
	//		重新执行容器的长度后，若容器变长，则以默认值填充新的位置，变长时会修改capacity()
	//		重新执行容器的长度后，若容器变短，末尾超出容器长度的元素被删除，变短时不会修改capacity()
	//	resize(size_type n ,const T& value)	调整元素数量	O(n)
	//		重新执行容器的长度后，若容器变长，则以value填充新的位置，变长时会修改capacity()
	//		重新执行容器的长度后，若容器变短，末尾超出容器长度的元素被删除，变短时不会修改capacity()
	//	swap(vector&)	交换内容	O(1)
	//	
	// 4. 迭代器支持
	//	vector容器的迭代器支持随机访问
	//	v.begin()	//指向第一个元素
	//	v.end()		//指向最后一个元素的下一个位置
	//	v.rbegin()	//指向第一个元素的上一个位置
	//	v.rend()	//指向倒数第一个元素
	//	vector 支持所有标准迭代器操作：
	//	vector<int> v = {1, 2, 3, 4, 5};
	//	正向迭代
	//	for (auto it = v.begin(); it != v.end(); ++it) {
	//		cout << *it << " ";
	//	}
	//	// 反向迭代
	//	for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
	//		cout << *rit << " ";
	//	}
	//	// 基于范围的for循环 (C++11)
	//	for (int num : v) {
	//		cout << num << " ";
	//	}
	//	// 常量迭代器
	//	for (auto cit = v.cbegin(); cit != v.cend(); ++cit) {
	//		// *cit = 10; // 错误，不能修改
	//	}
	//	
	// 5. 内存管理与性能
	//	内存增长策略
	//		当vector需要扩容时：
	//		1、分配新的更大的内存块（通常是当前容量的2倍）
	//		2、将现有元素拷贝 / 移动到新内存
	//		3、释放旧内存
	//	性能优化技巧
	//	 1、​​使用reserve()预分配内存​​：
	//		vector<int> v;
	//		v.reserve(1000); // 预分配1000个元素空间
	//		for (int i = 0; i < 1000; ++i) {
	//			v.push_back(i); // 不会触发多次重新分配
	//		}
	//	 2、​​优先使用emplace_back而非push_back​​：
	//		vector<pair<int, string>> v;
	//		v.emplace_back(1, "one"); // 直接构造，避免临时对象
	//		优于 v.push_back(make_pair(1, "one"));
	//	 3、​​减少中间插入/删除​​：
	//		末尾操作效率最高
	//		中间操作会导致元素移动，性能较差
	// 
	// 6.注意事项
	//	迭代器失效​​：
	//		插入操作可能使所有迭代器失效（触发重新分配时）
	//		删除操作会使被删除元素之后的迭代器失效
	//	边界检查​​：
	//		operator[] 不检查边界，at() 会检查并抛出std::out_of_range
	//	对象生命周期​​：
	//		vector析构时会自动销毁所有元素
	//		存储原始指针时不会自动释放指向的内存
	//	线程安全​​：
	//		不同线程可以同时读取同一vector
	//		任何写操作都需要同步机制


	//构造测试
	fun1();

	//vector赋值操作
	fun2();

	//vector容量和大小
	fun3();

	//vector插入和删除
	fun4();

	//vector数据存取
	fun5();

	//vector互换容器
	fun6();

	//vector预留空间
	fun7();
}
