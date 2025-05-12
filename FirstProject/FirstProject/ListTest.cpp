#include"ListTest.h"

namespace
{
	template<typename T>
	void fun1_1(const list<T>& l)
	{
		for (typename list<T>::const_iterator it = l.begin();it != l.end();++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	class Class1
	{
		friend ostream& operator<<(ostream& cout, const Class1& c);
	public:
		int m_Num;
		string m_Str;
		Class1() :m_Num(0), m_Str("str") {}
		Class1(int num,string str) :m_Num(num), m_Str(str) {}
		Class1(Class1&& other)//移动构造
		{
			this->m_Num = other.m_Num;
			this->m_Str = other.m_Str;
			other.m_Num = 0;
			other.m_Str = "";
		}
		Class1(const Class1& other)//拷贝构造
		{
			this->m_Num = other.m_Num;
			this->m_Str = other.m_Str;
		}
	};
	ostream& operator<<(ostream& cout, const Class1& c)
	{
		return cout << "m_Num: " << c.m_Num << "\tm_Str: " << c.m_Str << endl;
	}
	//构造测试
	void fun1()
	{
		cout << "\n\nTest_fun1" << endl;
		// 二、构造与初始化
		// ​​默认构造​​
		//	list()
		//		std::list<int> l1;  // 空链表 
		//	填充构造​​
		//		list(size_type n)
		//		list(size_type n, const T & value)
		//		std::list<int> l2(3);       // 3个0
		//	std::list<std::string> l3(2, "abc");  // 2个"abc" 
		//	范围构造​​
		//		template<class InputIt> list(InputIt first, InputIt last)
		//		int arr[] = { 1, 2, 3 };
		//	std::list<int> l4(arr, arr + 3);  // 从数组构造 
		// ​​	拷贝构造​​
		//		list(const list & other)
		//		std::list<int> l5 = { 1, 2, 3 };
		//	std::list<int> l6(l5);  // 拷贝 ​​
		//	移动构造(C++11)​​
		//		list(list && other)
		//		std::list<int> l7 = { 4, 5, 6 };
		//	std::list<int> l8(std::move(l7));  // 移动后l7为空
		//	初始化列表构造(C++11)​​
		//		list(initializer_list<T> init)
		//		std::list<int> l9 = { 7, 8, 9 };  // 直接初始化​​
		//	带分配器的构造​​
		//		list(const Allocator & alloc)
		//		MyAllocator<int> alloc;
		//	std::list<int, MyAllocator<int>> l10(alloc);  // 自定义分配器

		//默认构造
		list<int>l1;
		cout << (l1.begin() == l1.end()) << endl;
		for (int i = 0;i < 5;i++) { l1.push_back(i); }
		fun1_1(l1);

		//填充构造​​
		list<Class1>l2(5);
		list<Class1>l3(5, Class1(1, "str1"));
		fun1_1(l2);
		fun1_1(l3);

		//范围构造
		vector<int> v1{ 1,2,3,4,5 };
		list<int>l4(v1.begin(), v1.end());//可以从其他容器的迭代器构造，前闭后开
		fun1_1(l4);
		int arr[] = { 10,20,30,40,50 };
		list<int>l5(arr, arr + sizeof(arr) / sizeof(arr[0]));
		fun1_1(l5);

		//拷贝构造
		list<int>l6(l5);
		fun1_1(l6);

		//移动构造
		list<int>l7(move(l6));
		fun1_1(l6);
		fun1_1(l7);

		//初始化列表构造
		list<int>l8{ 100,200,300 };
		fun1_1(l8);

	}

	//成员函数测试
	void fun2()
	{
		cout << "\n\nTest_fun2" << endl;

		// 三、成员函数
		//	1. 元素访问
		//		函数	描述	时间复杂度
		//		front()	访问首元素	O(1)
		//		back()	访问尾元素	O(1)
		//	2. 容量操作
		//		函数	描述	时间复杂度
		//		empty()	检查是否为空	O(1)
		//		size()	返回元素数量	O(1)
		//		max_size()	返回可能的最大元素数	O(1)
		//		resize(size_type n)	调整元素数量	l.resize(10);
		//		resize(size_type n, const T& value)	调整元素数量	l.resize(10,100);
		//	3. 修改操作
		//		operator=	赋值操作	v1 = v2;
		//		assign()	多种重载的赋值	//使用迭代器范围进行赋值时，前闭后开
		//		函数	描述	时间复杂度
		//		push_front()	在头部插入元素	O(1)
		//		pop_front()	删除头部元素	O(1)
		//		push_back()	在尾部插入元素	O(1)
		//		pop_back()	删除尾部元素	O(1)
		//		insert()	在指定位置插入元素	O(1)
		//			insert(pos,elem)//pos位置插入elem元素，返回新数据的位置
		//			insert(pos,n,elem)//pos位置插入n个elem元素，无返回值
		//			insert(pos,beg,end)//pos位置插入[beg,end)区间的元素，无返回值
		//		erase()	删除指定位置元素	O(1)
		//			erase(beg,end)//删除[beg,end)区间的元素，返回下一个数据的位置
		//			erase(pos)//删除pos位置的元素，返回下一个数据的位置
		//		clear()	清空所有元素	O(n)
		//		resize()	改变容器大小	O(n)
		//		swap()	交换两个链表内容	O(1)
		//	4. 特殊操作
		//		函数	描述	时间复杂度
		//		splice()	移动元素到另一个链表	O(1)
		//		remove()	删除所有等于指定值的元素	O(n)
		//		remove_if()	删除满足条件的元素	O(n)
		//		unique()	删除连续重复元素	O(n)
		//		merge()	合并两个有序链表	O(n)
		//		sort()	对链表排序	O(n log n)
		//		reverse()	反转链表顺序	O(n)

		//元素访问
		cout << "\n元素访问：" << endl;
		list<int>l;
		for (int i = 1;i < 6;i++) { l.push_back(i); }
		for (int i = 1;i < 6;i++) { l.push_front(i); }
		fun1_1(l);
		cout << "l.front() =" << l.front() << endl;
		cout << "l.back() =" << l.back() << endl;
		//l[0] = 10;//不支持[]的访问方式
		for_each(l.begin(), l.end(), [](int n) {
			cout << n << " ";
		});
		cout << endl;
		list<int>::iterator it = l.begin();
		//it + 3;//不支持随机访问
		cout << *(it++) << " ";//支持++、--操作
		cout << *it << endl;

		//赋值和交换
		cout << "\n赋值和交换：" << endl;
		list<int> l1{ 1,2,3,4,5 };
		list<int> l2;
		//l2.assign((l1.begin() + 1), (l1.end() - 1));//list的迭代器不支持随机访问，不可以进行直接的加减操作
		l2.assign((++l1.begin()), (--l1.end()));
		fun1_1(l1);
		fun1_1(l2);
		vector<int>v1(5, 1000);
		list<int>l3;
		l3.assign(v1.begin() + 1, v1.end() - 1);//assign中可以传入其他容器的迭代器，vector容器的迭代器支持随机访问
		fun1_1(l3);

		list<int>l4;
		l4.assign(3, 100);
		fun1_1(l4);

		list<int>l5 = l4;
		fun1_1(l5);

		l5.swap(l1);
		fun1_1(l1);
		fun1_1(l5);

		//容量操作
		cout << "\n容量操作：" << endl;
		list<Class1>l11;
		cout << l11.size() << endl;
		cout << l11.empty() << endl;
		l11.resize(5);
		cout << l11.size() << endl;
		cout << l11.empty() << endl;
		fun1_1(l11);
		l11.resize(2);
		cout << l11.size() << endl;
		fun1_1(l11);
		l11.resize(5, Class1(1, "str1"));
		fun1_1(l11);
		cout << "list.max_size() ：" << l11.max_size() << endl;

		//修改操作
		cout << "\n修改操作：" << endl;
		list<int>l111;
		for (int i = 1;i < 6;i++) { l111.push_back(i); }
		for (int i = 1;i < 6;i++) { l111.push_front(i); }
		fun1_1(l111);
		l111.pop_back();
		l111.pop_front();
		fun1_1(l111);

		list<Class1>l222;
		Class1 c222(222, "str222");
		l222.insert(l222.begin(), c222);
		l222.insert(l222.begin(), 2, c222);
		fun1_1(l222);

		cout << c222;
		l222.insert(l222.begin(), move(c222));//会触发c222对象中的移动构造函数
		cout << c222;

		list<Class1>l333;
		vector<Class1> v111(5, Class1(222, "str222"));
		l333.insert(l333.begin(), v111.begin() + 1, v111.end() - 1);
		fun1_1(l333);

		list<int>l444{ 1,2,3,4,5,6,7 };
		fun1_1(l444);
		l444.erase(++l444.begin());
		fun1_1(l444);
		l444.erase(++l444.begin(), --l444.end());
		fun1_1(l444);
		cout << "l444.size() =" << l444.size() << endl;
		l444.clear();
		cout << "l444.size() =" << l444.size() << endl;
		cout << "l444.empty() =" << l444.empty() << endl;

		//特殊操作
		cout << "\n特殊操作：" << endl;
		//std::list<T,Allocator>::splice
		//	void splice( const_iterator pos, list& other );
		//	void splice(const_iterator pos, list && other);
		//	void splice(const_iterator pos, list & other, const_iterator it);
		//	void splice(const_iterator pos, list && other, const_iterator it);
		//	void splice(const_iterator pos, list & other,
		//		const_iterator first, const_iterator last);
		//	void splice(const_iterator pos, list && other,
		//		const_iterator first, const_iterator last);
		cout << "\nsplice：" << endl;
		list<Class1>l1111(3, Class1(1, "str1"));
		list<Class1>l2222(3, Class1(2, "str2"));
		fun1_1(l1111);
		fun1_1(l2222);

		l1111.splice(++l1111.begin(), l2222, l2222.begin());
		//l1111.splice(++l1111.begin(), move(l2222), l2222.begin());//结果同上，无论是否使用move，l2222中的元素都是会被转移走，不会留在l2222
		fun1_1(l1111);
		fun1_1(l2222);

		l1111.splice(l1111.begin(), l2222, ++l2222.begin(), l2222.end());
		//l1111.splice(l1111.begin(), move(l2222), ++l2222.begin(), l2222.end());//结果同上，无论是否使用move，l2222中的元素都是会被转移走，不会留在l2222
		fun1_1(l1111);
		fun1_1(l2222);

		l1111.splice(l1111.begin(), l2222);//无论是否使用move，l2222都会被置空
		//l1111.splice(l1111.begin(), move(l2222));
		fun1_1(l1111);
		fun1_1(l2222);

		//void remove(const T & value);//(C++20 前)
		//size_type remove(const T & value);//(C++20 起)
		//template< class UnaryPredicate >
		//void remove_if(UnaryPredicate p);//(C++20 前)
		//template< class UnaryPredicate >
		//size_type remove_if(UnaryPredicate p);//(C++20 起)
		cout << "\nremove：" << endl;
		list<int>l3333{ 1,2,2,3,1,4,5,6,2 };
		fun1_1(l3333);
		cout << typeid(l3333.remove(2)).name() << endl;//l3333中的元素没有被删除，没找到原因
		l3333.remove(2);
		fun1_1(l3333);

		l3333.remove_if([](int n) {
			return (n == 1);
		});
		fun1_1(l3333);


		//void unique();
		//(C++20 前)
		//size_type unique();
		//(C++20 起)
		//template< class BinaryPredicate >
		//void unique(BinaryPredicate p);
		//(C++20 前)
		//template< class BinaryPredicate >
		//size_type unique(BinaryPredicate p);
		//(C++20 起)
		cout << "\nunique：" << endl;
		list<int>l4444{ 1,1,2,1,2,2,1,3,3,3,5,4,9 };
		fun1_1(l4444);
		l4444.unique();
		fun1_1(l4444);
		l4444.unique([](int x,int y) {
			return x + 1 == y;//把后一个数等于前一个数+1的都删掉
		});
		fun1_1(l4444);

		//void sort();
		//template< class Compare >
		//void sort(Compare comp);
		cout << "\nsort：" << endl;
		list<int>l5555{ 7,5,9,8,6,6,4,6,4,3,2,1,8 };
		fun1_1(l5555);
		l5555.sort();
		fun1_1(l5555);
		l5555.sort(greater<int>());//greater仿函数，接收两个参数，如果第一个的值>第二个的值，返回true
		fun1_1(l5555);
		l5555.sort([](int x,int y) {
			return x < y;
		});
		fun1_1(l5555);

		//void merge(list& other);
		//void merge(list&& other);(C++11 起)
		//template< class Compare >
		//void merge(list& other, Compare comp);
		//template< class Compare >
		//void merge(list&& other, Compare comp);(C++11 起)
		cout << "\nmerge：" << endl;
		list<int>l6666{ 7,5,9,8,6,6,4,6,4,3,2,1,8 };
		list<int>l7777{ 1,2,2,3,1,4,5,6,2 };
		fun1_1(l6666);
		fun1_1(l7777);
		//l6666.merge(l7777);//列表需要排序后才能执行merge，否则会报错
		l6666.sort();
		l7777.sort();
		l6666.merge(l7777);
		//l6666.merge(l7777, less<int>());//同上
		//l6666.merge(l7777, greater<int>());//报错，list升序排列不满足条件，需要list都被降序排序后才能用
		/*l6666.sort(greater<int>());
		l7777.sort(greater<int>());
		l6666.merge(l7777, greater<int>());*/
		fun1_1(l6666);
		fun1_1(l7777);//l7777被置空

		//void reverse(); (C++11 起为 noexcept)
		cout << "\nreverse：" << endl;
		list<int>l8888{ 7,5,9,8,6,6,4,6,4,3,2,1,8 };
		fun1_1(l8888);
		l8888.reverse();
		fun1_1(l8888);

	}
	
	// 迭代器区别和失效测试
	template<typename T>
	struct is_stack_or_queue :false_type {};
	template<typename T,typename Container>
	struct is_stack_or_queue<stack<T,Container>>:true_type{};
	template<typename T, typename Container>
	struct is_stack_or_queue<queue<T, Container>> :true_type {};
	template<typename T>
	void fun3_1(T c)
	{
		//此判断实测编译时报错 提示container_type": 不是"std::vector<int,std::allocator<int>>" 的成员，已弃用
		/*if constexpr (is_same_v<T, stack<typename T::value_type, typename T::container_type>> ||
			is_same_v<T, stack<typename T::value_type, typename T::container_type>>)*///判断是否staick或queue
		if constexpr (is_stack_or_queue<T>::value)
		{
			if constexpr (is_same_v<T, stack<typename T::value_type, typename T::container_type>>)//stack类型容器
			{
				int size = c.size();
				for (int i = 0;i < size;i++)
				{
					cout << c.top() << " ";
					c.pop();
				}
			}
			else//queue容器
			{
				while (!c.empty())
				{
					cout << c.front() << " ";
					c.pop();
				}
			}
		}
		else
		{
			for (auto x : c)
			{
				cout << x << " ";
			}
		}
		cout << endl;
	}
	void fun3()
	{
		cout << "\n\nTest_fun3" << endl;

		//容器元素访问和迭代器操作的区别
		vector<int>v1;
		deque<int>d1;
		list<int>l1;
		stack<int>s1;
		queue<int>q1;
		for (int i = 0;i < 10;i++)
		{
			v1.push_back(i);
			d1.push_back(i);
			l1.push_back(i);
			s1.push(i);
			q1.push(i);
		}
		fun3_1(v1);
		fun3_1(d1);
		fun3_1(l1);
		fun3_1(s1);
		fun3_1(q1);

		cout << "容器元素访问区别：" << endl;
		//vector
		cout << "\nvector支持操作：" << endl;
		cout << "front() :" << v1.front() << endl;
		cout << "back() :" << v1.back() << endl;
		cout << "operator[] :" << v1[1] << endl;
		cout << "at() :" << v1.at(2) << endl;
		v1.push_back(2);
		v1.pop_back();
		//v1.push_front();//不支持
		//v1.pop_front();//不支持
		//v1.push();//不支持
		//v1.pop();//不支持
		//v1.top();//不支持

		//deque
		cout << "\ndeque支持操作：" << endl;
		cout << "front() :" << d1.front() << endl;
		cout << "back() :" << d1.back() << endl;
		cout << "operator[] :" << d1[1] << endl;
		cout << "at() :" << d1.at(2) << endl;
		d1.push_back(2);
		d1.pop_back();
		d1.push_front(2);
		d1.pop_front();
		//d1.push();//不支持
		//d1.pop();//不支持
		//d1.top();//不支持

		//list
		cout << "\nlist支持操作：" << endl;
		cout << "front() :" << l1.front() << endl;
		cout << "back() :" << l1.back() << endl;
		//cout << "operator[] :" << l1[1] << endl;//不支持
		//cout << "at() :" << l1.at(2) << endl;//不支持
		l1.push_back(2);
		l1.pop_back();
		l1.push_front(2);
		l1.pop_front();
		//d1.push();//不支持
		//d1.pop();//不支持
		//d1.top();//不支持

		//stack
		cout << "\nstack支持操作：" << endl;
		//cout << "front() :" << s1.front() << endl;//不支持
		//cout << "back() :" << s1.back() << endl;//不支持
		//cout << "operator[] :" << s1[1] << endl;//不支持
		//cout << "at() :" << s1.at(2) << endl;//不支持
		//s1.push_back(2);//不支持
		//s1.pop_back();//不支持
		//s1.push_front(2);//不支持
		//s1.pop_front();//不支持
		cout << "top() :" << s1.top() << endl;
		s1.push(2);
		s1.pop();

		//queue
		cout << "\nqueue支持操作：" << endl;
		cout << "front() :" << q1.front() << endl;
		cout << "back() :" << q1.back() << endl;
		//cout << "operator[] :" << q1[1] << endl;//不支持
		//cout << "at() :" << q1.at(2) << endl;//不支持
		//q1.push_back(2);//不支持
		//q1.pop_back();//不支持
		//q1.push_front(2);//不支持
		//q1.pop_front();//不支持
		q1.push(2);
		q1.pop();
		//q1.top();//不支持

		//迭代器操作的区别
		cout << "\n迭代器操作区别：" << endl;

		//stack和queue不支持迭代器
		cout << "stack和queue不支持迭代器" << endl;

		//vector
		cout << "\nvector支持操作：" << endl;
		cout << "begin() :" << *v1.begin() << endl;
		cout << "end() :" << *(--v1.end()) << endl;
		cout << "cbegin() :" << *v1.cbegin() << endl;
		cout << "cend() :" << *(--v1.cend()) << endl;
		cout << "rbegin() :" << *v1.rbegin() << endl;
		cout << "rend() :" << *(--v1.rend()) << endl;
		cout << "crbegin() :" << *v1.crbegin() << endl;
		cout << "crend() :" << *(--v1.crend()) << endl;
		cout << "迭代器支持+=等随机访问操作 :" << *(v1.begin() + 5) << endl;

		//deque
		cout << "\ndeque支持操作：" << endl;
		cout << "begin() :" << *d1.begin() << endl;
		cout << "end() :" << *(--d1.end()) << endl;
		cout << "cbegin() :" << *d1.cbegin() << endl;
		cout << "cend() :" << *(--d1.cend()) << endl;
		cout << "rbegin() :" << *d1.rbegin() << endl;
		cout << "rend() :" << *(--d1.rend()) << endl;
		cout << "crbegin() :" << *d1.crbegin() << endl;
		cout << "crend() :" << *(--d1.crend()) << endl;
		cout << "迭代器支持+=等随机访问操作 :" << *(d1.begin() + 5) << endl;

		//list
		cout << "\nlist支持操作：" << endl;
		cout << "begin() :" << *l1.begin() << endl;
		cout << "end() :" << *(--l1.end()) << endl;
		cout << "cbegin() :" << *l1.cbegin() << endl;
		cout << "cend() :" << *(--l1.cend()) << endl;
		cout << "rbegin() :" << *l1.rbegin() << endl;
		cout << "rend() :" << *(--l1.rend()) << endl;
		cout << "crbegin() :" << *l1.crbegin() << endl;
		cout << "crend() :" << *(--l1.crend()) << endl;
		cout << "迭代器不支持+=等随机访问操作 :" /*<< *(l1.begin() + 5)*/ << endl;//不支持


		//迭代器失效测试
		cout << "\n迭代器失效测试：" << endl;

		//stack和queue不支持迭代器
		//vector、deque的迭代器在插入数据或删除数据时，都可能导致迭代器失效
		//list的迭代器只有被删除元素的迭代器会失效
		//	vector​​：插入 / 删除可能使所有迭代器失效
		//	​​deque​​：中间插入 / 删除使所有迭代器失效，首尾插入仅使部分迭代器失效
		//	​​list​​：只有被删除元素的迭代器会失效

		//vector
		vector<int>::iterator vit = v1.begin() + 5;
		cout << *vit << endl;//5
		//v1.insert(v1.begin(), 10);//会导致迭代器失效
		//cout << *vit << endl;//报错，提示can't dereference invalidated vector iterator，表示正在尝试使用一个已失效的迭代器
		//v1.erase(v1.begin());
		//cout << *vit << endl;//报错，提示can't dereference invalidated vector iterator，表示正在尝试使用一个已失效的迭代器

		//deque
		deque<int>::iterator dit = d1.begin() + 5;
		cout << *dit << endl;//5
		//d1.insert(d1.begin(), 10);//会导致迭代器失效
		//cout << *dit << endl;//报错，提示cannot dereference value-initialized deque iterator，表明您正在尝试解引用一个未初始化或默认初始化的迭代器
		// 此报错的可能原因：1、​​未初始化的迭代器  2、已失效的迭代器  3、错误的迭代器位置​​
		//d1.erase(d1.begin());//没有导致迭代器失效
		//d1.erase(d1.begin()+1);//导致迭代器失效
		//cout << *dit << endl;//报错，提示cannot dereference value-initialized deque iterator，表明您正在尝试解引用一个未初始化或默认初始化的迭代器
		// 此报错的可能原因：1、​​未初始化的迭代器  2、已失效的迭代器  3、错误的迭代器位置​​

		//list
		list<int>::iterator lit = next(l1.begin(),5) ;
		cout << *lit << endl;//5
		l1.insert(l1.begin(), 10);
		cout << *lit << endl;//5，迭代器仍指向原元素
		l1.erase(l1.begin());
		cout << *lit << endl;//5，迭代器仍指向原元素
		l1.erase(++l1.begin());
		cout << *lit << endl;//5，迭代器仍指向原元素
		//l1.erase(lit);//删除迭代器指向的元素会导致迭代器失效
		//cout << *lit << endl;//报错，提示cannot dereference value-initialized list iterator，表明您正在尝试解引用一个未初始化或无效的迭代器
		// 此报错的可能原因：1、​​未初始化的迭代器  2、已失效的迭代器  3、错误的迭代器位置




		//list中的指针prev、next的访问
		//无法直接访问，只可以可以访问迭代器

		//操作迭代器的函数(下述函数vector、deque、list容器都可使用)
		// 1. std::prev 函数
		//	功能：返回迭代器前移 n 个位置后的迭代器(n默认为1)
		// 2. std::next 函数
		//	功能：返回迭代器后移 n 个位置后的迭代器(n默认为1)
		// 3. std::advance
		//	功能：将迭代器前进或后退指定数量的位置（修改原迭代器）
		// 4. std::distance//list的效果和vector、deque不同
		//	功能：计算两个迭代器之间的距离

		//操作迭代器的函数测试
		cout << "\n操作迭代器的函数测试：" << endl;

		auto temp = {0,1,2,3,4,5,6,7,8,9 };
		v1 = temp;
		d1 = temp;
		l1 = temp;
		fun3_1(v1);
		fun3_1(d1);
		fun3_1(l1);

		vit = prev(v1.end(), 5);
		cout << "prev(v1.end(), 5) :" << *vit << endl;
		vit = next(v1.begin(), 5);
		cout << "next(v1.begin(), 5) :" << *vit << endl;
		vit = v1.begin();
		advance(vit, 4);
		cout << "advance(vit, 4) :" << *vit << endl;
		cout << "distance(v1.end(), vit) :" << distance(v1.end(), vit) << endl;

		dit = prev(d1.end(), 5);
		cout << "prev(d1.end(), 5) :" << *dit << endl;
		dit = next(d1.begin(), 5);
		cout << "next(d1.begin(), 5) :" << *dit << endl;
		dit = d1.begin();
		advance(dit, 4);
		cout << "advance(dit, 4) :" << *dit << endl;
		cout << "distance(d1.end(), dit) :" << distance(d1.end(), dit) << endl;

		lit = prev(l1.end(), 5);
		cout << "prev(l1.end(), 5) :" << *lit << endl;
		lit = next(l1.begin(), 5);
		cout << "next(l1.begin(), 5) :" << *lit << endl;
		lit = l1.begin();
		advance(lit, 4);
		cout << "advance(lit, 4) :" << *lit << endl;
		cout << "distance(l1.end(), lit) :" << distance(l1.end(), lit) << endl;
		cout << "distance(l1.end(), l1.begin()) :" << distance(l1.end(), l1.begin()) << endl;
	}

	/*void fun4()
	{
		cout << "\n\nTest_fun4" << endl;
	}

	void fun5()
	{
		cout << "\n\nTest_fun5" << endl;
	}

	void fun6()
	{
		cout << "\n\nTest_fun6" << endl;
	}

	void fun7()
	{
		cout << "\n\nTest_fun7" << endl;
	}*/

	//案例测试
	class Person
	{
		friend ostream& operator<<(ostream& ostr, const Person& p);
	public:
		string m_Name;
		int m_Age;
		int m_Height;
		Person(string name,int age,int height)
		{
			m_Name = name;
			m_Age = age;
			m_Height = height;
		}
	};
	ostream& operator<<(ostream& ostr, const Person& p)
	{
		return cout << "name :" << p.m_Name<<" "
			<< "\tage :" << p.m_Age << "   "
			<< "\theight" << p.m_Height << endl;
	}
	void showPersonList(list<Person> pl)
	{
		for_each(pl.begin(), pl.end(), [](Person p) {
			cout << p ;
		});
	}
	bool myPersonComper(Person p1, Person p2)
	{
		if (p1.m_Age < p2.m_Age)
		{
			return true;
		}
		else if (p1.m_Age == p2.m_Age)
		{
			return p1.m_Height > p2.m_Height;
		}
		else return false;
	}
	void funExample()
	{
		cout << "\n\n案例测试" << endl;
		//将Person自定义数据类型进行排序
		//排序规则：按年龄进行升序，如果年龄相同，按照身高进行降序

		list<Person> pl;
		pl.push_back(Person("A", 10, 150));
		pl.push_back(Person("A2", 10, 180));
		pl.push_back(Person("B", 12, 150));
		pl.push_back(Person("C", 70, 150));
		pl.push_back(Person("D", 20, 150));
		pl.push_back(Person("D2", 20, 157));
		pl.push_back(Person("D3", 20, 140));
		pl.push_back(Person("E", 15, 150));
		pl.push_back(Person("F", 22, 150));
		pl.push_back(Person("G", 90, 150));
		pl.push_back(Person("H", 99, 150));
		pl.push_back(Person("I", 40, 160));
		pl.push_back(Person("I2", 40, 190));
		pl.push_back(Person("I3", 40, 170));
		pl.push_back(Person("I4", 40, 185));
		pl.push_back(Person("J", 30, 150));

		cout << "排序前" << endl;
		showPersonList(pl);

		cout << "排序后" << endl;
		pl.sort(myPersonComper);
		showPersonList(pl);
	}

}




void testList()
{
	//链表介绍
	// 链表是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
	//	链表的组成：链表由一系列的结点组成
	//	结点的组成：由存储数据元素的数据域、和存储下一节点地址的指针域 组成
	// 链表的优点：
	//	可以对任意位置进行快速的插入或删除，而不需要操作原容器中的其他元素
	// 链表的缺点：
	//	遍历速度没有vector等连续容器速度快
	//	占用空间比较大
	// 
	// STL实现和提供的链表
	//	STL中的链表是一个双向循环链表
	//	list.begin()的prev(指向上一结点的指针)，指向的是容器的最后一个结点
	//	list.end()的next(指向下一结点的指针)，指向的是容器的第一个结点
	//
	//
	//list容器
	// std::list 是 C++ 标准模板库(STL)中的一个双向链表容器，它提供了高效的插入和删除操作，特别适合频繁修改序列的场景。
	// 
	// 一、基本特性
	//	​​数据结构​​：双向链表
	//	头文件​​：#include <list>
	//	迭代器类型​​：双向迭代器
	//	内存分配​​：每个元素独立分配节点
	//	主要优势​​：
	//	任意位置插入 / 删除时间复杂度为 O(1)
	//	插入 / 删除不会使迭代器失效（除了被删除元素的迭代器）
	//	不需要连续内存空间
	// 
	// 二、构造与初始化
	// ​​默认构造​​
	//	list()
	//		std::list<int> l1;  // 空链表 
	//	填充构造​​
	//		list(size_type n)
	//		list(size_type n, const T & value)
	//		std::list<int> l2(3);       // 3个0
	//	std::list<std::string> l3(2, "abc");  // 2个"abc" 
	//	范围构造​​
	//		template<class InputIt> list(InputIt first, InputIt last)
	//		int arr[] = { 1, 2, 3 };
	//	std::list<int> l4(arr, arr + 3);  // 从数组构造 
	// ​​	拷贝构造​​
	//		list(const list & other)
	//		std::list<int> l5 = { 1, 2, 3 };
	//	std::list<int> l6(l5);  // 拷贝 ​​
	//	移动构造(C++11)​​
	//		list(list && other)
	//		std::list<int> l7 = { 4, 5, 6 };
	//	std::list<int> l8(std::move(l7));  // 移动后l7为空
	//	初始化列表构造(C++11)​​
	//		list(initializer_list<T> init)
	//		std::list<int> l9 = { 7, 8, 9 };  // 直接初始化​​
	//	带分配器的构造​​
	//		list(const Allocator & alloc)
	//		MyAllocator<int> alloc;
	//	std::list<int, MyAllocator<int>> l10(alloc);  // 自定义分配器
	// 
	// 三、成员函数
	//	1. 元素访问
	//		函数	描述	时间复杂度
	//		front()	访问首元素	O(1)
	//		back()	访问尾元素	O(1)
	//	2. 容量操作
	//		函数	描述	时间复杂度
	//		empty()	检查是否为空	O(1)
	//		size()	返回元素数量	O(1)
	//		max_size()	返回可能的最大元素数	O(1)
	//		resize(size_type n)	调整元素数量	l.resize(10);
	//		resize(size_type n, const T& value)	调整元素数量	l.resize(10,100);
	//	3. 修改操作
	//		operator=	赋值操作	v1 = v2;
	//		assign()	多种重载的赋值	//使用迭代器范围进行赋值时，前闭后开
	//		函数	描述	时间复杂度
	//		push_front()	在头部插入元素	O(1)
	//		pop_front()	删除头部元素	O(1)
	//		push_back()	在尾部插入元素	O(1)
	//		pop_back()	删除尾部元素	O(1)
	//		insert()	在指定位置插入元素	O(1)
	//			insert(pos,elem)//pos位置插入elem元素，返回新数据的位置
	//			insert(pos,n,elem)//pos位置插入n个elem元素，无返回值
	//			insert(pos,beg,end)//pos位置插入[beg,end)区间的元素，无返回值
	//		erase()	删除指定位置元素	O(1)
	//			erase(beg,end)//删除[beg,end)区间的元素，返回下一个数据的位置
	//			erase(pos)//删除pos位置的元素，返回下一个数据的位置
	//		clear()	清空所有元素	O(n)
	//		resize()	改变容器大小	O(n)
	//		swap()	交换两个链表内容	O(1)
	//	4. 特殊操作
	//		函数	描述	时间复杂度
	//		splice()	移动元素到另一个链表	O(1)
	//		remove()	删除所有等于指定值的元素	O(n)
	//		remove_if()	删除满足条件的元素	O(n)
	//		unique()	删除连续重复元素	O(n)
	//		merge()	合并两个有序链表	O(n)
	//		sort()	对链表排序	O(n log n)
	//		reverse()	反转链表顺序	O(n)
	// 
	// 四、迭代器操作
	//	std::list 提供双向迭代器，支持以下操作：
	//		std::list<int> l = {1, 2, 3, 4, 5};
	//		 正向遍历
	//		for (auto it = l.begin(); it != l.end(); ++it) {
	//			std::cout << *it << " ";
	//		}
	//		// 反向遍历
	//		for (auto rit = l.rbegin(); rit != l.rend(); ++rit) {
	//			std::cout << *rit << " ";
	//		}
	//		// C++11范围for循环
	//		for (int val : l) {
	//			std::cout << val << " ";
	//		}
	// 
	// 五、性能分析
	//	时间复杂度：
	//		操作					时间复杂度
	//		插入 / 删除任意位置			O(1)
	//		随机访问					O(n)
	//		排序					O(n log n)
	//		查找						O(n)
	//	与vector/deque对比：
	//		特性				list	vector	deque
	//		随机访问			慢		快		快
	//		头部插入 / 删除		快		慢		快
	//		尾部插入 / 删除		快		快		快
	//		中间插入 / 删除		快		慢		慢
	//		内存连续性			不连续	连续	分块连续
	//		迭代器失效			很少	经常	经常
	// 
	// 六、使用场景
	//	1. 频繁插入/删除
	//	2. 大型对象存储
	//	3. 需要稳定迭代器
	//	4. 特殊操作需求
	//		std::list<int> l1 = {1, 3, 5};
	//		std::list<int> l2 = { 2, 4, 6 };
	//		l1.merge(l2); // 合并两个有序链表
	//		l1.sort(); // 排序
	//		l1.unique(); // 去重
	//		l1.reverse(); // 反转
	// 
	// 七、注意事项
	// 	内存使用​​：每个元素有额外指针开销（前驱和后继指针）
	//	缓存不友好​​：数据不连续，可能导致缓存命中率低
	//	随机访问​​：不支持operator[]，需用std::advance或循环遍历
	//	线程安全​​：标准实现非线程安全，需外部同步 
	//	C++11新特性​​：
	//	emplace() / emplace_back() / emplace_front() 直接构造元素
	//	移动语义支持
	//	初始化列表支持
	// 
	// 八、std::list 与 std::vector 迭代器操作的区别：
	//	std::list 和 std::vector 在迭代器操作上有显著差异，主要体现在迭代器类型、失效规则和操作效率等方面。
	// 
	// 1. 迭代器类型
	//	特性			std::list						std::vector
	// 	迭代器类别​​	双向迭代器(Bidirectional)		随机访问迭代器(Random Access)
	//	支持的操作​​	++, --, == , !=					所有双向迭代器操作 + 随机访问(+, -, [], < 等)
	//	示例​​：
	//		std::vector<int> vec = { 1, 2, 3, 4, 5 };
	//		std::list<int> lst = { 1, 2, 3, 4, 5 };
	//		auto vec_it = vec.begin() + 3;  // vector支持随机访问
	//		auto lst_it = std::next(lst.begin(), 3);  // list需要逐步前进
	//		int a = vec[2];    // vector支持operator[]
	//		int b = lst[2]; // 错误！list不支持operator[]
	// 
	// 2. 迭代器失效规则
	//	操作			std::list 迭代器失效情况			std::vector 迭代器失效情况
	// 	插入元素​​		不会失效（除了被插入位置的迭代器）		可能全部失效（扩容时）
	//	删除元素​​		只有被删除元素的迭代器失效				被删除元素及其后的迭代器都失效
	//	修改大小​​		不会失效								可能全部失效
	//	swap / assign​​	不会失效								全部失效
	//	示例​​：
	//		std::vector<int> v = { 1, 2, 3 };
	//		auto v_it = v.begin() + 1;
	//		v.insert(v.begin(), 0);  // v_it可能失效！
	//		std::list<int> l = { 1, 2, 3 };
	//		auto l_it = ++l.begin();
	//		l.insert(l.begin(), 0);  // l_it仍然有效
	// 
	// 3. 操作效率对比
	//	操作					std::list 时间复杂度	std::vector 时间复杂度
	//	++ / --							O(1)					O(1)
	//	随机访问(+n / -n)				O(n)					O(1)
	//	begin() / end()					O(1)					O(1)
	//	遍历所有元素					O(n)					O(n)
	// 
	// 4. 特殊操作支持
	//	std::list 特有的迭代器操作​​：
	//		// splice：将元素从一个list移动到另一个list（不失效迭代器）
	//		std::list<int> l1 = { 1, 2, 3 }, l2 = { 4, 5 };
	//		auto it = l1.begin();
	//		++it;
	//		l1.splice(it, l2);  // l1变为{1, 4, 5, 2, 3}, l2为空
	//		// merge/remove/unique等算法直接作为成员函数提供
	//		l1.sort();  // 成员函数排序
	//	std::vector 的优势操作​​：
	//		std::vector<int> v = { 3, 1, 4, 2, 5 };
	//		std::sort(v.begin(), v.end());  // 随机访问迭代器支持高效排序
	//		// 随机访问
	//		int val = v[2];  // O(1)访问
	// 
	// 5. 实际应用建议
	//	使用 std::list 当​​：
	//		需要频繁在中间位置插入 / 删除
	//		需要保证迭代器长期有效
	//		元素很大且移动成本高
	//		需要特殊操作如 splice()
	// 	使用 std::vector 当​​：
	//		需要频繁随机访问
	//		主要进行尾部操作
	//		需要与C风格数组交互
	//		内存连续性很重要
	// 
	// 九、list容器的优缺点
	//	list的优点：
	//		采用动态存储分配，不会造成内存浪费和溢出	(vector容器扩容机制会导致内存浪费，可用shrink_to_fit适应容器大小和元素数量匹配)
	//		链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
	//	list的缺点：
	//		链表灵活，但是空间(需存储指针域)和时间(遍历)额外耗费较大
	//	list有一个重要的性质：插入操作和删除操作都不会造成原有list迭代器的失效，vector不行
	// 


	// 未测试项
	// list中的指针prev、next的访问
	// 迭代器区别和失效测试
	// 对于实现函数中传入函数进行测试(暂不处理)


	//构造测试
	fun1();

	//成员函数测试
	fun2();

	//迭代器区别和失效测试
	fun3();

	//案例测试
	//funExample();
}