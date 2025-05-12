#include "STLTest.h"


namespace {

	void fun1()
	{
		cout << "\n\nTest_fun1" << endl;
		using namespace placeholders;
		int arr[6] = { 72,16,23,58,96,75 };
		vector<int, allocator<int>> vi(arr, arr + 6);//不同的容器有不同的设初值的方式，此处是将数组arr的首地址和arr的最后一个元素的下一个的地址传进去初始化容器
		/*cout << count_if(vi.begin(), vi.end(),
			not1(bind2nd(less<int>(), 40)));*/ //C++17中not1和bind2nd已被弃用，用下面的方式替代了
		cout << count_if(vi.begin(), vi.end(),
			not_fn(bind(less<int>(), _1, 40)));
		//上述代码解析：
		// 声明了一个有6个元素的int类型的容器，输出该容器中大于等于40的数的个数
		// vector<int , allocator<int>> vi 实例化了一个int类型的vector容器vi
		// vector为容器 allocator为空间配置器(容器的模板类型中如果不显式传入的话，会有默认值，当前情况默认值也为allocator<int>)
		// count_if为算法，作用是统计传入的范围内的，符合条件的元素的个数
		// vi.begin()、vi.end()的返回值为迭代器，可以视为指向容器vi的第一个元素的指针，和指向容器vi的最后一个元素的下一个元素的指针
		// not1(bind2nd(less<int>(),40))
		// less<int>()为仿函数，作用为比较两个数的大小，如果第一个数小于第二个数，返回true，否则返回false
		// bind2nd为仿函数的适配器，作用是绑定第二个参数，此处会将less仿函数的第二个参数绑定为40，即比较传入的参数是否小于40
		// not1为仿函数的适配器，作用为逻辑取反，即如果原结果为true，此时结果为false
		// not1(bind2nd(less<int>(), 40))在此处是一个判断式predicate，取反元素与40的比较的结果，即判断元素是否大于等于40
		// 所以最后的结果即为count_if，计算从容器vi中的所有元素中，大于等于40的元素的个数
		//

		
	}


	void fun2()
	{
		cout << "\n\nTest_fun2" << endl;
		for (int i : {12, 5, 6, 78, 129, 45})
		{
			cout << i << "\t";
		}
		cout << endl;

		char str[] = "hello world";
		/*cout << sizeof(str) / sizeof(str[0]);
		for (char i : str)
		{
			cout << i << endl;
		}*/
		vector<char> strv(str, str + 12);
		for (auto elem : strv)//elem会被自动类型推导为vector<char>::iterator迭代器解引用后的类型，即为char
		{
			//cout << typeid(elem).name();
			cout << elem << endl;
		}
		for (auto& elem : strv)
		{
			elem++;
			cout << elem << endl;
		}

	}


	//容器性能及测试
	#define MAX_RAND_NUM 100000//随机数生成范围
	#define CONTAINERS_SIZE 5000000//容器大小
	#define TEST_NUM 53159//用于测试数
	int compareLongs(const void* a, const void* b)//排序时用的比较函数
	{
		return (*(long*)a - *(long*)b);
	}
	int compareStrings(const void* a,const void* b)//排序时用的比较函数
	{
		if (*(string*)a > *(string*)b)
		{
			return 1;
		}
		else if (*(string*)a < *(string*)b)
		{
			return -1;
		}
		else return 0;
	}
	unsigned long bigRand()
	{
		return ((unsigned long)rand() << 15 | rand());
	}
	void test_array()//arrary容器测试
	{
		cout << "-----------test_array-----------" << endl;
		//array<long, CONTAINERS_SIZE> arr;//array声明的变量不会直接放在堆上，局部变量，会放在栈上，导致栈溢出
		array<long, CONTAINERS_SIZE>* arr = new array<long, CONTAINERS_SIZE>();
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;i++)//测试放置元素花费的时间
		{
			(*arr)[i] = bigRand() % MAX_RAND_NUM;
		}
		cout << "place elements cost time :" << (clock() - startTime) << endl;
		cout << "array.size() = " << (*arr).size() << endl;//元素数量
		cout << "array.front() = " << (*arr).front() << endl;//第一个元素
		cout << "array.back() = " << (*arr).back() << endl;//最后一个元素
		cout << "array.data() = 0x" << uppercase << hex << (long)((*arr).data()) << endl;//指向底层数组的指针
		//hex会修改后续数字的输出都为16进制
		cout << dec;
		//uppercase会修改后续十六进制等的字母输出为大写(不影响字符串)
		cout << nouppercase;

		//排序查找测试
		long testNum = TEST_NUM;
		startTime = clock();
		//测试排序及查找元素花费的时间
		qsort((*arr).data(), CONTAINERS_SIZE, sizeof(long), compareLongs);//排序
		clock_t endTime = clock();
		cout << "qsort cost time :" << endTime - startTime << endl;
		long* pRet = (long*)bsearch(&testNum, ((*arr).data()), CONTAINERS_SIZE, sizeof(long), compareLongs);
		cout << "bsearch cost time :" << (clock() - endTime) << endl;
		if (pRet != NULL)//在容器中找到了元素
		{
			cout << "found :" << *pRet << endl;
		}
		else cout << "not found" << endl;
		cout << "array.back() = " << (*arr).back() << endl;//最后一个元素

		delete arr;
	}
	void test_vevtor()//vector容器测试
	{
		cout << "-----------test_vevtor-----------" << endl;
		vector<string> vect;//使用字符串模拟容器中实际存放的不是数值，而是对象
		char buf[10];

		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try 
			{
				snprintf(buf, 10, "%d", (bigRand() % MAX_RAND_NUM));
				vect.push_back(string(buf));
			}
			catch(exception &p)
			{
				cout << "捕获到异常,在test_vevtor放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "vector.size() = " << vect.size() << endl;
		cout << "vector.front() = " << vect.front() << endl;
		cout << "vector.back() = " << vect.back() << endl;
		cout << "vector.data() = 0x" << uppercase << hex << (long)vect.data() << dec << nouppercase << endl;
		cout << "vector.capacity() = " << vect.capacity() << endl;//capacity会比size要大，因为开辟空间的时候不是一个空间一个空间开辟的，实际会开辟一整块空间

		//排序查找测试
		//char buf[10];
		snprintf(buf, 10, "%d", TEST_NUM);
		string testTarget = string(buf);

		//直接::find查找
		startTime = clock();
		vector<string>::iterator pRet = ::find(vect.begin(), vect.end(), testTarget);//algorithm中的find函数
		endTime = clock();
		cout << "test_vevtor  ::find cost time :" << endTime - startTime << endl;
		if (pRet != vect.end())//在容器中找到了元素
		{
			cout << "found :" << *pRet << endl;
		}
		else cout << "not found" << endl;
		cout << "vector.back() = " << vect.back() << endl;//最后一个元素

		//sort排序后查找
		startTime = clock();
		sort(vect.begin(), vect.end());
		endTime = clock();
		cout << "test_vevtor  ::sort cost time :" << endTime - startTime << endl;
		startTime = clock();
		string* pRetStr = (string*)bsearch(&testTarget, (vect.data()), CONTAINERS_SIZE, sizeof(string), compareStrings);
		endTime = clock();
		cout << "bsearch cost time :" << (endTime - startTime) << endl;
		if (pRetStr != NULL)//在容器中找到了元素
		{
			cout << "found :" << *pRetStr << endl;
		}
		else cout << "not found" << endl;
		cout << "vector.back() = " << vect.back() << endl;//最后一个元素

	}
	void test_vevtor2()//vector容器测试，容器中放置数值类型
	{
		cout << "-----------test_vevtor2-----------" << endl;
		vector<long> vect;//使用字符串模拟容器中实际存放的不是数值，而是对象

		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				vect.push_back(bigRand() % MAX_RAND_NUM);
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_vevtor放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "vector.size() = " << vect.size() << endl;
		cout << "vector.front() = " << vect.front() << endl;
		cout << "vector.back() = " << vect.back() << endl;
		cout << "vector.data() = 0x" << uppercase << hex << (long)vect.data() << dec << nouppercase << endl;
		cout << "vector.capacity() = " << vect.capacity() << endl;//capacity会比size要大，因为开辟空间的时候不是一个空间一个空间开辟的，实际会开辟一整块空间

		//排序查找测试
		//char buf[10];
		long testTarget = TEST_NUM;

		//直接::find查找
		startTime = clock();
		vector<long>::iterator pRet = ::find(vect.begin(), vect.end(), testTarget);//algorithm中的find函数
		endTime = clock();
		cout << "test_vevtor2  ::find cost time :" << endTime - startTime << endl;
		if (pRet != vect.end())//在容器中找到了元素
		{
			cout << "found :" << *pRet << endl;
		}
		else cout << "not found" << endl;
		cout << "vector.back() = " << vect.back() << endl;//最后一个元素

		//sort排序后查找
		startTime = clock();
		sort(vect.begin(), vect.end());
		endTime = clock();
		cout << "test_vevtor2  ::sort cost time :" << endTime - startTime << endl;
		startTime = clock();
		long* pRetLong = (long*)bsearch(&testTarget, (vect.data()), CONTAINERS_SIZE, sizeof(long), compareLongs);
		endTime = clock();
		cout << "bsearch cost time :" << (endTime - startTime) << endl;
		if (pRetLong != NULL)//在容器中找到了元素
		{
			cout << "found :" << *pRetLong << endl;
		}
		else cout << "not found" << endl;
		cout << "vector.back() = " << vect.back() << endl;//最后一个元素

	}
	void test_list()//list容器测试
	{
		cout << "-----------test_list-----------" << endl;
		list<long> l;

		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				l.push_back(bigRand() % MAX_RAND_NUM);
			}
			catch(exception &p)
			{
				cout << "捕获到异常,在test_list放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "list.size() = " << l.size() << endl;
		cout << "list.max_size() = " << l.max_size() << endl;
		cout << "list.front() = " << l.front() << endl;
		cout << "list.back() = " << l.back() << endl;

		//排序查找测试
		long testTarget = TEST_NUM;

		//直接::find查找
		startTime = clock();
		list<long>::iterator pRet = ::find(l.begin(), l.end(), testTarget);
		endTime = clock();
		cout << "test_list  ::find cost time :" << endTime - startTime << endl;
		if (pRet != l.end())//在容器中找到了元素
		{
			cout << "found :" << *pRet << endl;
		}
		else cout << "not found" << endl;

		//sort排序后查找
		startTime = clock();
		l.sort();
		endTime = clock();
		cout << "test_list.sort() cost time :" << endTime - startTime << endl;
		startTime = clock();
		//long* pRetLong = (long*)bsearch(&testTarget, (l.data()),CONTAINERS_SIZE,sizeof(long),compareLongs )//list容器无法使用bsearch方法查找元素，因为list容器中的元素不是存储在连续的内存上的，也没有l.data()方法获取首元素的地址
		list<long>::iterator pRetLong = lower_bound(l.begin(), l.end(), testTarget);
		endTime = clock();
		cout << "test_list lower_bound cost time :" << endTime - startTime << endl;
		if (pRetLong != l.end())//在容器中找到了元素
		{
			cout << "found :" << *pRetLong << endl;
		}
		else cout << "not found" << endl;
		cout << "list.back() = " << l.back() << endl;
	}
	void test_forward_list()
	{
		cout << "-----------test_forward_list-----------" << endl;
		forward_list<long> fl;
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				fl.push_front(bigRand() % MAX_RAND_NUM);
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_forward_list放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		//cout << "forward_list.size() = " << fl.size() << endl;//forward_list容器中无此函数
		cout << "forward_list.max_size() = " << fl.max_size() << endl;
		cout << "forward_list.front() = " << fl.front() << endl;
		//cout << "forward_list.back() = " << fl.back() << endl;//forward_list容器中无此函数

		//排序查找测试
		long testTarget = TEST_NUM;

		//直接::find查找
		startTime = clock();
		forward_list<long>::iterator pRet = ::find(fl.begin(), fl.end(), testTarget);
		endTime = clock();
		cout << "test_forward_list  ::find cost time :" << endTime - startTime << endl;
		if (pRet != fl.end())//在容器中找到了元素
		{
			cout << "found :" << *pRet << endl;
		}
		else cout << "not found" << endl;

		//sort排序后查找
		startTime = clock();
		fl.sort();
		endTime = clock();
		cout << "test_forward_list.sort() cost time :" << endTime - startTime << endl;
		startTime = clock();
		//long* pRetLong = (long*)bsearch(&testTarget, (fl.data()),CONTAINERS_SIZE,sizeof(long),compareLongs )//forward_list容器无法使用bsearch方法查找元素，因为forward_list容器中的元素不是存储在连续的内存上的，也没有l.data()方法获取首元素的地址
		forward_list<long>::iterator pRetLong = lower_bound(fl.begin(), fl.end(), testTarget);
		endTime = clock();
		cout << "test_forward_list lower_bound cost time :" << endTime - startTime << endl;
		if (pRetLong != fl.end())//在容器中找到了元素
		{
			cout << "found :" << *pRetLong << endl;
		}
		else cout << "not found" << endl;
		//cout << "list.back() = " << fl.back() << endl;
	}
	void test_deque()//deque容器测试
	{
		cout << "-----------test_deque-----------" << endl;
		deque<long> dq;
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				dq.push_back(bigRand() % MAX_RAND_NUM);
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_deque放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "deque.size() = " << dq.size() << endl;
		cout << "deque.max_size() = " << dq.max_size() << endl;
		cout << "deque.front() = " << dq.front() << endl;
		cout << "deque.back() = " << dq.back() << endl;

		//排序查找测试
		long testTarget = TEST_NUM;

		//直接::find查找
		startTime = clock();
		deque<long>::iterator pRet = ::find(dq.begin(), dq.end(), testTarget);
		endTime = clock();
		cout << "test_deque  ::find cost time :" << endTime - startTime << endl;
		if (pRet != dq.end())//在容器中找到了元素
		{
			cout << "found :" << *pRet << endl;
		}
		else cout << "not found" << endl;

		//sort排序后查找
		startTime = clock();
		sort(dq.begin(),dq.end());
		endTime = clock();
		cout << "test_deque ::sort() cost time :" << endTime - startTime << endl;
		startTime = clock();
		//long* pRetLong = (long*)bsearch(&testTarget, (dq.data()),CONTAINERS_SIZE,sizeof(long),compareLongs )//forward_list容器无法使用bsearch方法查找元素，因为forward_list容器中的元素不是存储在连续的内存上的，也没有l.data()方法获取首元素的地址
		deque<long>::iterator pRetLong = lower_bound(dq.begin(), dq.end(), testTarget);
		endTime = clock();
		cout << "test_deque lower_bound cost time :" << endTime - startTime << endl;
		if (pRetLong != dq.end())//在容器中找到了元素
		{
			cout << "found :" << *pRetLong << endl;
		}
		else cout << "not found" << endl;
		cout << "deque.back() = " << dq.back() << endl;

	}
	void test_stack()//stack容器测试//栈，先进后出
	{
		cout << "-----------test_stack-----------" << endl;
		stack<long> stk;
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				stk.push(bigRand() % MAX_RAND_NUM);
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_stack放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "stack.size() = " << stk.size() << endl;
		cout << "stack.top() = " << stk.top() << endl;
		stk.pop();
		cout << "stack.size() = " << stk.size() << endl;
		cout << "stack.top() = " << stk.top() << endl;
	}
	void test_queue()
	{
		cout << "-----------test_queue-----------" << endl;
		queue<long> q;
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				q.push(bigRand() % MAX_RAND_NUM);
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_queue放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "queue.size() = " << q.size() << endl;
		cout << "queue.front() = " << q.front() << endl;
		cout << "queue.back() = " << q.back() << endl;
		q.pop();
		cout << "queue.size() = " << q.size() << endl;
		cout << "queue.front() = " << q.front() << endl;
		cout << "queue.back() = " << q.back() << endl;

	}
	void test_multiset()
	{
		cout << "-----------test_multiset-----------" << endl;
		multiset<long> ms;
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				ms.insert(bigRand() % MAX_RAND_NUM);
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_multiset放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "multiset.size() = " << ms.size() << endl;
		cout << "multiset.max_size() = " << ms.max_size() << endl;

		//排序查找测试
		long testTarget = TEST_NUM;

		//全局find查找测试
		startTime = clock();
		multiset<long>::iterator pRet = ::find(ms.begin(), ms.end(), testTarget);
		endTime = clock();
		cout << "test_multiset  ::find cost time :" << endTime - startTime << endl;
		if (pRet != ms.end())//在容器中找到了元素
		{
			cout << "found :" << *pRet << endl;
		}
		else cout << "not found" << endl;

		//multiset.find查找测试
		startTime = clock();
		multiset<long>::iterator pRetLong = ms.find(testTarget);
		endTime = clock();
		cout << "test_multiset  multiset.find cost time :" << endTime - startTime << endl;
		if (pRetLong != ms.end())//在容器中找到了元素
		{
			cout << "found :" << *pRetLong << endl;
		}
		else cout << "not found" << endl;

	}
	void test_multimap()
	{
		cout << "-----------test_multimap-----------" << endl;
		multimap<long,long> mm;
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				long temp = bigRand() % MAX_RAND_NUM;
				mm.insert(pair<long,long>(temp, temp));//键设置为随机数
				//mm.insert(pair<long, long>(i, temp));//键设置为i
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_multimap放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "multimap.size() = " << mm.size() << endl;
		cout << "multimap.max_size() = " << mm.max_size() << endl;

		//排序查找测试
		long testTarget = TEST_NUM;

		//全局find查找测试
		startTime = clock();
		multimap<long, long>::iterator pRet = ::find(mm.begin(), mm.end(), pair<long, long>(testTarget, testTarget));
		endTime = clock();
		cout << "test_multimap  ::find cost time :" << endTime - startTime << endl;
		if (pRet != mm.end())//在容器中找到了元素
		{
			cout << "found :" << (*pRet).second << endl;
		}
		else cout << "not found" << endl;

		//multimap.find()查找测试
		startTime = clock();
		multimap<long, long>::iterator pRetLong = mm.find(testTarget);
		endTime = clock();
		cout << "test_multimap  multimap.find cost time :" << endTime - startTime << endl;
		if (pRetLong != mm.end())//在容器中找到了元素
		{
			cout << "found :" << (*pRetLong).second << endl;
		}
		else cout << "not found" << endl;
	}
	void test_unordered_multiset()
	{
		cout << "-----------test_unordered_multiset-----------" << endl;
		unordered_multiset<long> unms;
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				unms.insert(bigRand() % MAX_RAND_NUM);
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_unordered_multiset放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "unordered_multiset.size() = " << unms.size() << endl;
		cout << "unordered_multiset.max_size() = " << unms.max_size() << endl;
		cout << "unordered_multiset.bucket_count() = " << unms.bucket_count() << endl;
		cout << "unordered_multiset.bucket_size() = " << unms.bucket_size(unms.bucket(TEST_NUM)) << endl;
		cout << "unordered_multiset.max_bucket_count() = " << unms.max_bucket_count() << endl;
		cout << "unordered_multiset.load_factor() = " << unms.load_factor() << endl;
		cout << "unordered_multiset.max_load_factor() = " << unms.max_load_factor() << endl;
		for (unsigned i = 0;i < 10;i++)
		{
			cout << "bucket #" << i << " has " << unms.bucket_size(i) << " element" << endl;
		}

		//排序查找测试
		long testTarget = TEST_NUM;

		//全局find查找测试
		startTime = clock();
		unordered_multiset<long>::iterator pRet = ::find(unms.begin(), unms.end(), testTarget);
		endTime = clock();
		cout << "test_unordered_multiset  ::find cost time :" << endTime - startTime << endl;
		if (pRet != unms.end())//在容器中找到了元素
		{
			cout << "found :" << *pRet << endl;
		}
		else cout << "not found" << endl;

		//unordered_multiset.find()查找测试
		startTime = clock();
		unordered_multiset<long>::iterator pRetLong = unms.find(testTarget);
		endTime = clock();
		cout << "test_unordered_multiset unordered_multiset.find cost time :" << endTime - startTime << endl;
		if (pRetLong != unms.end())//在容器中找到了元素
		{
			cout << "found :" << *pRetLong << endl;
		}
		else cout << "not found" << endl;
	}
	void test_unordered_multimap()
	{
		cout << "-----------test_unordered_multimap-----------" << endl;
		unordered_multimap<long, long> unmap;
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				long temp = bigRand() % MAX_RAND_NUM;
				unmap.insert(pair<long, long>(temp, temp));//键设置为随机数
				//unmap.insert(pair<long, long>(i, temp));//键设置为i
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_unordered_multimap放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "unordered_multimap.size() = " << unmap.size() << endl;
		cout << "unordered_multimap.max_size() = " << unmap.max_size() << endl;
		cout << "unordered_multimap.bucket_count() = " << unmap.bucket_count() << endl;
		cout << "unordered_multimap.bucket_size() = " << unmap.bucket_size(unmap.bucket(TEST_NUM)) << endl;
		cout << "unordered_multimap.max_bucket_count() = " << unmap.max_bucket_count() << endl;
		cout << "unordered_multimap.load_factor() = " << unmap.load_factor() << endl;
		cout << "unordered_multimap.max_load_factor() = " << unmap.max_load_factor() << endl;
		for (unsigned i = 0;i < 10;i++)
		{
			cout << "bucket #" << i << " has " << unmap.bucket_size(i) << " element" << endl;
		}

		//排序查找测试
		long testTarget = TEST_NUM;

		//全局find查找测试
		startTime = clock();
		unordered_multimap<long, long>::iterator pRet = ::find(unmap.begin(), unmap.end(), pair<long, long>(testTarget, testTarget));
		endTime = clock();
		cout << "test_unordered_multimap  ::find cost time :" << endTime - startTime << endl;
		if (pRet != unmap.end())//在容器中找到了元素
		{
			cout << "found :" << (*pRet).second << endl;
		}
		else cout << "not found" << endl;

		//multimap.find()查找测试
		startTime = clock();
		unordered_multimap<long, long>::iterator pRetLong = unmap.find(testTarget);
		endTime = clock();
		cout << "test_unordered_multimap  unordered_multimap.find cost time :" << endTime - startTime << endl;
		if (pRetLong != unmap.end())//在容器中找到了元素
		{
			cout << "found :" << (*pRetLong).second << endl;
		}
		else cout << "not found" << endl;
	}
	void test_set()
	{
		cout << "-----------test_set-----------" << endl;
		set<long> s;
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				//s.insert(bigRand() % MAX_RAND_NUM);//0~99999
				s.insert(i);
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_set放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "set.size() = " << s.size() << endl;
		cout << "set.max_size() = " << s.max_size() << endl;

		//排序查找测试
		long testTarget = TEST_NUM;

		//全局find查找测试
		startTime = clock();
		set<long>::iterator pRet = ::find(s.begin(), s.end(), testTarget);
		endTime = clock();
		cout << "test_set  ::find cost time :" << endTime - startTime << endl;
		if (pRet != s.end())//在容器中找到了元素
		{
			cout << "found :" << *pRet << endl;
		}
		else cout << "not found" << endl;

		//multiset.find查找测试
		startTime = clock();
		set<long>::iterator pRetLong = s.find(testTarget);
		endTime = clock();
		cout << "test_set  set.find cost time :" << endTime - startTime << endl;
		if (pRetLong != s.end())//在容器中找到了元素
		{
			cout << "found :" << *pRetLong << endl;
		}
		else cout << "not found" << endl;
	}
	void test_map()
	{
		cout << "-----------test_map-----------" << endl;
		map<long, long> m;
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				//m.insert(pair<long,long>(i, bigRand() % MAX_RAND_NUM));
				//非multi的map可以使用[]进行元素的访问
				m[i] = bigRand() % MAX_RAND_NUM;
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_map放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "map.size() = " << m.size() << endl;
		cout << "map.max_size() = " << m.max_size() << endl;

		//排序查找测试
		long testTarget = TEST_NUM;

		//全局find查找测试
		startTime = clock();
		map<long, long>::iterator pRet = ::find(m.begin(), m.end(), pair<long, long>(testTarget, testTarget));
		endTime = clock();
		cout << "test_map  ::find cost time :" << endTime - startTime << endl;
		//存放数据时如果不是键与值相等的方式存储的，此时未找到元素是正常情况
		if (pRet != m.end())//在容器中找到了元素
		{
			cout << "found :" << (*pRet).second << endl;
		}
		else cout << "not found" << endl;

		//multimap.find()查找测试
		startTime = clock();
		map<long, long>::iterator pRetLong = m.find(testTarget);
		endTime = clock();
		cout << "test_map map.find cost time :" << endTime - startTime << endl;
		if (pRetLong != m.end())//在容器中找到了元素
		{
			cout << "found :" << (*pRetLong).second << endl;
		}
		else cout << "not found" << endl;
	}
	void test_unordered_set()
	{
		cout << "-----------test_unordered_set-----------" << endl;
		unordered_set<long> uns;
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				uns.insert(bigRand() % MAX_RAND_NUM);//0~99999
				//uns.insert(i);
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_unordered_set放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "unordered_set.size() = " << uns.size() << endl;
		cout << "unordered_set.max_size() = " << uns.max_size() << endl;
		cout << "unordered_set.bucket_count() = " << uns.bucket_count() << endl;
		cout << "unordered_set.bucket_size() = " << uns.bucket_size(uns.bucket(TEST_NUM)) << endl;
		cout << "unordered_set.max_bucket_count() = " << uns.max_bucket_count() << endl;
		cout << "unordered_set.load_factor() = " << uns.load_factor() << endl;
		cout << "unordered_set.max_load_factor() = " << uns.max_load_factor() << endl;
		for (unsigned i = 0;i < 10;i++)
		{
			cout << "bucket #" << i << " has " << uns.bucket_size(i) << " element" << endl;
		}

		//排序查找测试
		long testTarget = TEST_NUM;

		//全局find查找测试
		startTime = clock();
		unordered_set<long>::iterator pRet = ::find(uns.begin(), uns.end(), testTarget);
		endTime = clock();
		cout << "test_unordered_set ::find cost time :" << endTime - startTime << endl;
		if (pRet != uns.end())//在容器中找到了元素
		{
			cout << "found :" << *pRet << endl;
		}
		else cout << "not found" << endl;

		//multiset.find查找测试
		startTime = clock();
		unordered_set<long>::iterator pRetLong = uns.find(testTarget);
		endTime = clock();
		cout << "test_unordered_set unordered_set.find cost time :" << endTime - startTime << endl;
		if (pRetLong != uns.end())//在容器中找到了元素
		{
			cout << "found :" << *pRetLong << endl;
		}
		else cout << "not found" << endl;
	}
	void test_unordered_map()
	{
		cout << "-----------test_unordered_map-----------" << endl;
		unordered_map<long, long> unm;
		clock_t startTime = clock();
		for (long i = 0;i < CONTAINERS_SIZE;++i)
		{
			try
			{
				//long temp = bigRand() % MAX_RAND_NUM;
				//unm.insert(pair<long, long>(temp, temp));
				unm[i] = bigRand() % MAX_RAND_NUM;
			}
			catch (exception& p)
			{
				cout << "捕获到异常,在test_unordered_map放置第" << i << "个元素时发生异常" << endl;
				abort();
			}
		}
		clock_t endTime = clock();
		cout << "place elements cost time :" << (endTime - startTime) << endl;
		cout << "unordered_map.size() = " << unm.size() << endl;
		cout << "unordered_map.max_size() = " << unm.max_size() << endl;
		cout << "unordered_map.bucket_count() = " << unm.bucket_count() << endl;
		cout << "unordered_map.bucket_size() = " << unm.bucket_size(unm.bucket(TEST_NUM)) << endl;
		cout << "unordered_map.max_bucket_count() = " << unm.max_bucket_count() << endl;
		cout << "unordered_map.load_factor() = " << unm.load_factor() << endl;
		cout << "unordered_map.max_load_factor() = " << unm.max_load_factor() << endl;
		for (unsigned i = 0;i < 10;i++)
		{
			cout << "bucket #" << i << " has " << unm.bucket_size(i) << " element" << endl;
		}

		//排序查找测试
		long testTarget = TEST_NUM;

		//全局find查找测试
		startTime = clock();
		unordered_map<long, long>::iterator pRet = ::find(unm.begin(), unm.end(), pair<long, long>(testTarget, testTarget));
		endTime = clock();
		cout << "test_unordered_map  ::find cost time :" << endTime - startTime << endl;
		//存放数据时如果不是键与值相等的方式存储的，此时未找到元素是正常情况
		if (pRet != unm.end())//在容器中找到了元素
		{
			cout << "found :" << (*pRet).second << endl;
		}
		else cout << "not found" << endl;

		//multimap.find()查找测试
		startTime = clock();
		unordered_map<long, long>::iterator pRetLong = unm.find(testTarget);
		endTime = clock();
		cout << "test_unordered_map  unordered_map.find cost time :" << endTime - startTime << endl;
		if (pRetLong != unm.end())//在容器中找到了元素
		{
			cout << "found :" << (*pRetLong).second << endl;
		}
		else cout << "not found" << endl;
	}
	void fun3()
	{
		cout << "\n\nTest_fun3" << endl;
		//设置随机数种子
		srand((unsigned int)time(NULL));
		//test_array();
		//test_vevtor();
		//test_vevtor2();//存放数值类型的容器在耗时上要短不少
		//test_list();
		//test_forward_list();
		//test_deque();
		//test_stack();
		//test_queue();
		//test_multiset();
		test_multimap();
		//test_unordered_multiset();
		test_unordered_multimap();
		//test_set();
		//test_map();
		//test_unordered_set();
		//test_unordered_map();
	}
	//测试容器放置的地址
	void fun4()
	{
		cout << "\n\nTest_fun4" << endl;
		TestMemory();

		array<long, 100> arr;
		array<long, 100>* arr2 = new array<long, 100>;
		vector<long> vct;
		vct.push_back(100);

		cout<<"arr add : 0x"<< uppercase<< hex << arr.data()<< dec << nouppercase << endl;
		cout << "arr* add : 0x" << uppercase << hex << (*arr2).data() << dec << nouppercase << endl;
		cout << "vector add : 0x" << uppercase << hex << vct.data() << dec << nouppercase << endl;
	}

	//空间配置器测试 allocators
	void fun5()
	{
		cout << "\n\nTest_fun5" << endl;
		cout << "test list with special allocator" << endl;
		list<int, allocator<int>> l1;
		//std::scoped_allocator_adaptor
		//std::cout << "__cplusplus macro value: " << __cplusplus << std::endl;//输出当前C++版本，好像不准
		//MSVC的库中实现的空间配置器基本就只有C++标准库实现的空间配置器
		//使用起来比较复杂，此处不进行使用的演示
		//侯捷课程中是用的gnu环境下的不同空间配置器，测试list容器使用不同空间配置器时，放置大量数据时的效率有何差异

		//空间配置器的直接使用(一般不会使用，因为释放时需要传入开辟时的空间大小，一般使用new、delete或malloc、free)
		int* p1;
		allocator<int> alloc1;
		p1 = alloc1.allocate(1);
		alloc1.deallocate(p1, 1);//释放时参数需要指针和开辟时的空间大小

		char* p2;
		allocator<char> alloc2;
		p2 = alloc2.allocate(4);
		p2[0] = 'a';
		p2[1] = 'b';
		p2[2] = 'c';
		p2[3] = '\0';
		cout << p2 << endl;
		alloc2.deallocate(p2, 4);

	}

	//容器初识
	void fun6_2()
	{
		vector<int> v;
		v.push_back(1);
		int sum = 0;
		for_each(v.begin(),v.end(),[&sum](int n)-> void {
			sum += n;
		});
		cout << sum << endl;
	}
	void fun6_1(int n)
	{
		cout << n << endl;
	}
	class Class6
	{
	public:
		string m_Str;
		int m_Num;
		Class6(string str,int num)
		{
			this->m_Str = str;
			this->m_Num = num;
		}
	};
	void fun6()
	{
		cout << "\n\nTest_fun6" << endl;
		//vector容器存放内置数据类型
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		cout << "vector.size() = " << v.size() << endl;
		cout << "vector.capacity() = " << v.capacity() << endl;

		//第一种遍历方式
		vector<int>::iterator itBegin = v.begin();
		vector<int>::iterator itEnd = v.end();
		while (itBegin != itEnd)
		{
			cout << *itBegin << endl;
			itBegin++;
		}
		//第二种遍历方式
		for (vector<int>::iterator i = v.begin();i != v.end();i++)
		{
			cout << *i << endl;
		}
		//第三种遍历方式
		for_each(v.begin(), v.end(),fun6_1);//传入函数方式
		for_each(v.begin(), v.end(), [](int n) {//lambda表达式方式
			cout << n << endl;
		});
		//C++中的lambda表达式
		// 语法：[捕获列表](参数列表)->返回类型{函数体}//没有返回值时->可省略
		// 例：
		// vector<int> v;
		// v.push_back(1);
		// int sum = 0;
		// for_each(v.begin(),v.end(),[&sum](int n)-> void{
		//     sum+=n;
		// });
		//
		fun6_2();
		//第四种遍历方式
		//基于范围的for循环C++11以上
		for (int i : v)
		{
			cout << i << endl;
		}


		//vector容器存放自定义数据类型
		vector<Class6> v2;
		Class6 c1("a", 1);
		Class6 c2("b", 2);
		Class6 c3("c", 3);
		v2.push_back(c1);
		v2.push_back(c2);
		v2.push_back(c3);
		for_each(v2.begin(), v2.end(), [](Class6 c) {
			cout << c.m_Str << endl;
		});
		for (vector<Class6>::iterator i = v2.begin();i != v2.end();i++)
		{
			cout << (*i).m_Num << endl;
			cout << i->m_Str << endl;
		}

		//vector容器存放自定义数据类型的指针
		vector<Class6*> v3;
		v3.push_back(&c1);
		v3.push_back(&c2);
		v3.push_back(&c3);
		for (auto i = v3.begin();i != v3.end();i++)
		{
			cout << (*i)->m_Str << endl;
		}

		//vector容器嵌套
		vector<vector<int>> v4;
		vector<int> v5;
		v5.push_back(111);
		v5.push_back(1111);
		v5.push_back(11111);
		vector<int> v6;
		v5.push_back(222);
		v5.push_back(2222);
		v5.push_back(22222);
		v4.push_back(v5);
		v4.push_back(v6);
		for_each(v4.begin(), v4.end(), [](vector<int> v) {
			for_each(v.begin(), v.end(), [](int a) {
				cout << a << endl;
			});
		});

	}

}


void testSTL()
{
	//STL(Standard Template Library)标准模板库
	// STL是 C++ 标准库的核心组成部分，提供了一系列通用的模板类和函数，用于实现常用的数据结构和算法。
	// STL 的设计基于泛型编程思想，具有高度的可复用性和效率。
	// STL的六大组件：容器containers、算法algorithms、迭代器iterators、仿函数functors、适配器adapters、空间配置器allocators
	// 
	// STL的三大核心组件 容器、算法、迭代器
	//	1、容器 (containers)
	//	容器是用来管理某一类对象的集合的数据结构，分为以下几类：
	//	 序列容器 (Sequence Containers)
	//		vector: 动态数组，支持快速随机访问(只能向后扩充元素)
	//		deque: 双端队列，支持首尾快速插入/删除(可以首尾扩充元素)
	//		list: 双向链表
	//		forward_list (C++11): 单向链表
	//		array (C++11): 固定大小数组(首尾都不可以扩充元素，即固定大小)
	//	 关联容器 (Associative Containers)//下述4种容器从底层是以红黑树的方式实现的
	//		set: 唯一键的集合，按照键排序
	//		multiset : 键可重复的集合，按照键排序
	//		map : 键 - 值对的集合，按照键排序
	//		multimap : 键可重复的键 - 值对集合
	//	 无序关联容器 (Unordered Associative Containers) (C++11)//下述4种容器都是基于哈希表的分离链接法HashTable Separate Chaining的方式实现的
	//		unordered_set: 唯一键的集合，基于哈希表
	//		unordered_multiset : 键可重复的集合
	//		unordered_map : 键 - 值对的哈希表
	//		unordered_multimap : 键可重复的键 - 值对哈希表
	//	 容器适配器 (Container Adaptors)
	//		stack: 后进先出(LIFO)栈 //由于底层实现是由deque双端队列实现的，所以被分类为了容器适配器//stack由于特殊的性质，即必须要求元素先进后出，所以不提供获取iterator的方法，避免特性遭到破坏(获取到不是最上端的元素或修改容器中间的元素)
	//		queue : 先进先出(FIFO)队列 //由于底层实现是由deque双端队列实现的，所以被分类为了容器适配器//queue由于特殊的性质，即必须要求元素先进先出，所以不提供获取iterator的方法，避免特性遭到破坏(修改了容器中间的元素)
	//		priority_queue : 优先级队列
	//	2、算法 (algorithms)
	//  STL 提供了约100种算法，主要分为以下几类：
	//	算法通过迭代器与容器交互，不直接操作容器本身。
	//	非修改序列操作​​：如 find(), count(), equal(), search()
	//	​​ 修改序列操作​​：如 copy(), swap(), replace(), fill(), remove()
	//	​​ 排序及相关操作​​：如 sort(), stable_sort(), partial_sort(), binary_search()
	//	​​ 数值运算​​：如 accumulate(), inner_product(), partial_sum()
	//	3、迭代器 (iterators)
	//  迭代器是连接容器和算法的桥梁，提供了一种方法来顺序访问容器中的元素，而不暴露容器的内部结构。主要类型包括：
	//	迭代器可以被视为一种泛化的指针
	//	 ​​输入迭代器​​：只读，单遍扫描
	//	 ​​输出迭代器​​：只写，单遍扫描
	//	 ​​前向迭代器​​：读写，多遍扫描
	//	 ​​双向迭代器​​：可前后移动
	//	 ​​随机访问迭代器​​：支持直接访问任意元素
	// 
	// STL的其他重要组件 仿函数、适配器(配接器)、空间配置器
	//  1、仿函数 (functors)
	//	也称为函数对象(Function Objects)，是重载了 operator() 的类对象，可以像函数一样被调用。STL 提供了许多预定义的函数对象：
	//	 算术运算：plus, minus, multiplies, divides, modulus, negate
	//	 比较运算：equal_to, not_equal_to, greater, less, greater_equal, less_equal
	//	 逻辑运算：logical_and, logical_or, logical_not
	//	2、适配器 (adapters)
	//	一种用来修饰容器或仿函数或迭代器接口的东西
	//	 容器适配器​​：如 stack, queue, priority_queue
	//	 迭代器适配器​​：如 reverse_iterator, move_iterator(C++11)
	//	​​ 函数适配器​​：如 bind(C++11), mem_fn, not1, not2
	//	3、空间配置器 (allocators)
	//	负责空间配置与管理
	//	从实现的角度来看，空间配置器是一个实现了动态空间配置、空间管理、空间释放的class template
	// 
	// STL六大组件之间的关系：
	//	详情参考侯捷老师的《STL源码剖析》这本书和课程
	//	容器通过空间配置器获取数据存储的空间，算法通过迭代器存取容器的内容
	//	而仿函数可以协助算法完成不同的策略变化，适配器可以修饰或套接容器、仿函数、迭代器
	// 
	// 
	// 算法有其各自的使用场景，用于实现不同的功能，所以有很多不同的算法是理所当然的
	// 但容器都是用于存放数据的，其实差别并不大，但为什么还会有这么多种类的容器
	// 实际上是因为使用场景不同，会导致效率的不同
	// 选择何种容器取决于数据的分布方式和使用方式(比如说是否需要从中间插入数据、从头或尾部插入数据、是否需要删除中间的数据)
	// 不同的容器在处理不同的数据使用方式时可能会有性能上的差异，所以设计了各种不同的容器满足不同的需求
	// 
	// 
	// 
	// 
	// 容器
	// 
	// 算法
	// 
	// 迭代器
	// 注意：
	// 假设有一容器对象c 
	// c.begin()返回的值可以看作是指向容器首元素的指针
	// c.end()返回的值不是指向容器最后一个元素的指针，而是指向的容器最后一个元素的下一个位置
	// *(c.begin())即解引用指向第一个元素的指针，可以获取到第一个元素的值
	// 但*(c.end())解引用的是容器最后一个元素的下一个位置，此个位置的元素没有放任何有意义的东西，此操作为异常操作
	// 
	//


	fun1();

	//c++11引入的基于范围的 for 循环（Range-based for loop）
	// 它是一种简化容器或数组遍历的语法糖
	// 语法：
	//	for(decl : coll){ //decl为声明 coll为聚合体(容器)
	//		statement //statement为循环体
	// }
	// 示例：
	//	for (int i : {12, 5, 6, 78, 129, 45})//循环遍历输出容器中的每个元素
	//	{
	//		cout << i << "\t";
	//	}
	// 
	// 自动类型推导auto
	// auto关键字可以实现自动类型推导，可方便程序编写
	// 
	//

	//fun2();

	//容器性能及测试
	// array容器
	//	特点：变量空间开辟到栈区、固定容量大小
	//
	//fun3();

	//fun4();


	//空间配置器测试 allocators
	//fun5();


	//容器初识
	//vector容器
	// vector.push_back()尾插数据
	// vector.begin()返回起始迭代器，指向容器的第一个元素
	// vector.end()返回结束迭代器，指向容器的最后一个元素的下一个位置
	//C++中的lambda表达式
	// 语法：[捕获列表](参数列表)->返回类型{函数体}//没有返回值时->可省略
	// 例：
	// vector<int> v;
	// v.push_back(1);
	// int sum = 0;
	// for_each(v.begin(),v.end(),[&sum](int n)-> void{
	//     sum+=n;
	// });
	fun6();


	
}

