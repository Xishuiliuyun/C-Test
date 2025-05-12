#include "StringTest.h"

namespace 
{
	//string容器
	void fun1()
	{
		cout << "\n\nTest_fun1" << endl;

		// 构造函数测试
		string s1();
		//cout << s1 << endl;
		string s2("123123");
		cout << s2 << endl;
		cout << s2.c_str() << endl;
		string s3(s2);
		cout << s3 << endl;
		string s4(3, '4');
		cout << s4 << endl;
		string s5(s2.begin(), s2.end());
		cout << s5 << endl;
		string s6(s2, 1);//从s2的第几个字符开始拷贝
		cout << s6 << endl;
		string s7(move(s2));
		cout << s7 << endl;
		char s8[] = "444555";
		string s9(s8, 2);
		cout << s9 << endl;
	}

	//赋值操作
	void fun2()
	{
		cout << "\n\nTest_fun2" << endl;
		//函数原型：
		// string& operator=(const char* s);//char*类型字符串赋值
		// string& operator=(const string& s);//string类型字符串赋值
		// string& operator=(char s);//char类型字符赋值
		// string& assign(const char* s)//将字符串赋值给调用函数的对象
		// string& assign(const char* s,int n)//将字符串s的前n个字符，赋值给调用函数的对象
		// string& assign(const string& s)//将字符串赋值给调用函数的对象
		// string& assign(int n,char c)//用n个字符c赋值给调用函数的对象
		
		string s1;
		char s2[] = "111";
		s1 = s2;
		cout << s1 << endl;
		string s3("222");
		s1 = s3;
		cout << s1 << endl;
		s1 = 'a';
		cout << s1 << endl;
		s1.assign(s2);
		cout << s1 << endl;
		s1.assign(s2, 2);
		cout << s1 << endl;
		s1.assign(s3);
		cout << s1 << endl;
		s1.assign(3, '3');
		cout << s1 << endl;

		cout << &("a") << endl;
	}

	//字符串拼接
	void fun3()
	{
		cout << "\n\nTest_fun3" << endl;

		//函数原型：
		// string& operator+=(const char* s);//char*类型字符串拼接
		// string& operator+=(const string& s);//string类型字符串拼接
		// string& operator+=(char s);//char类型字符拼接
		// string& append(const char* s)//将字符串拼接到调用函数的对象结尾
		// string& append(const char* s,int n)//将字符串s的前n个字符，拼接到调用函数的对象结尾
		// string& append(const string& s)//将字符串拼接到调用函数的对象结尾
		// string& append(const string& s,int pos,int n)//将字符串s从pos开始的n个字符，拼接到调用函数的对象结尾

		string s1;
		string s2;
		s1 += "111";
		s2 = s1 + "111";
		cout << s1 << endl;
		cout << s2 << endl;
		s1 += s1;
		s2 = s1 + s1;
		cout << s1 << endl;
		cout << s2 << endl;
		s1 += 'a';
		s2 = s1 + 'a';
		cout << s1 << endl;
		cout << s2 << endl;

		cout << endl;
		string s3;
		s3.append("222");
		cout << s3 << endl;
		s3.append("333", 2);
		cout << s3 << endl;
		s3.append(s3);
		cout << s3 << endl;
		s3.append(s3, 1, 3);
		cout << s3 << endl;
	}

	//string查找和替换
	void fun4()
	{
		cout << "\n\nTest_fun4" << endl;
		//查找：查找指定字符串是否存在
		//替换：在指定的位置替换字符串
		// 
		// 函数原型：
		// //find从0位置查到最后一个字符结束，没找到返回-1
		// int find(const string& str,int pos =0) const //查找str第一次出现位置，从pos开始查找
		// int find(const char* s,int pos =0) const //查找s第一次出现位置，从pos开始查找
		// int find(const char* s,int pos ,int n) const //从pos位置查找s的前n个字符第一次出现位置
		// int find(char c,int pos = 0) const //查找字符c第一次出现位置，从pos开始查找
		// //rfind从最后一个字符查到0结束，没找到返回-1
		// int rfind(const string& str,int pos =npos) const //查找str最后一次出现位置，从pos开始查找//默认从最后开始查找
		// int rfind(const char* s,int pos =npos) const //查找s最后一次出现位置，从pos开始查找//默认从最后开始查找
		// int rfind(const char* s,int pos,int n) const //从pos位置查找s的前n个字符最后一次出现位置
		// int rfind(char c,int pos = npos) const //查找字符c最后一次出现位置，从pos开始查找
		// //replace可以理解为，将从pos开始的n个字符删除,再从pos位置插入字符串
		// string& replace(int pos, int n, const string& str) //替换从pos开始n个字符为字符串str
		// string& replace(int pos, int n, const char* s) //替换从pos开始n个字符为字符串s

		string s1("123456aabbccddaabbccdd");
		int pos = 0;
		string s2 = "aa";
		pos = s1.find(s2);
		cout << pos << endl;
		pos = s1.find("bb");
		cout << pos << endl;
		pos = s1.find("ccc", 0, 2);
		cout << pos << endl;
		pos = s1.find('d');
		cout << pos << endl;

		cout << endl;
		pos = s1.rfind(s2);
		cout << pos << endl;
		pos = s1.rfind("bb");
		cout << pos << endl;
		//pos = s1.rfind("ccc", 0, 2);//相当于没有查找，直接结束了，会返回-1
		pos = s1.rfind("ccc", s1.length(), 2);
		cout << pos << endl;
		pos = s1.rfind('d');
		cout << pos << endl;

		cout << endl;
		cout << s1 << endl;
		s1.replace(0, 2, s2);
		cout << s1 << endl;
		s1.replace(2, 2, "bb");
		cout << s1 << endl;
		//可以理解为，将从pos开始的n个字符删除,再从pos位置插入str字符串
		s1.replace(0, 2, "1111");//替换的字符串比字符数量多，整个字符串会全部替换进去
		cout << s1 << endl;
		s1.replace(0, 4, "12");//替换的字符串比字符数量少，也只会把整个字符串全部替换进去，不会重复
		cout << s1 << endl;
	}

	//string字符串比较
	void fun5()
	{
		cout << "\n\nTest_fun5" << endl;
		//字符串比较compare，主要用于判断两个字符串是否相同
		// 按字符的ASCII码进行比较
		// ==返回0 >返回1 <返回-1
		// 函数原型：
		// int compare(const string& str) const //string类型字符串比较
		// int compare(const char* s) const //char*类型字符串比较

		string str = "abc";
		string str2;
		str2 = "abc";
		cout << str.compare(str2) << endl;
		cout << str.compare("abc") << endl;
		cout << str.compare("ABC") << endl;
		cout << str.compare("123") << endl;
		cout << str.compare("bbc") << endl;
		cout << str.compare("acd") << endl;

	}

	//string字符单个存取
	void fun6()
	{
		cout << "\n\nTest_fun6" << endl;
		//函数原型：
		//char& opreator[](int n) //通过[]方式取字符//不会进行边界的判断
		//char& at(int n) //通过at方法获取字符//会进行边界的判断
		string s1 = "123abc";
		for (int i = 0;i < s1.length();i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
		for (int i = 0;i < s1.length();i++)
		{
			cout << s1.at(i) << " ";
		}
		cout << endl;

		cout << s1 << endl;
		s1[0] = '2';
		cout << s1 << endl;
		s1.at(2) = '2';
		cout << s1 << endl;
		//cout << s1[100] << endl;//运行后报错
		//cout << s1.at(100) << endl;//运行后报错，但程序不会崩溃

		char s2[10] ;
		strcpy_s(s2, "123abc");
		char s3[10] = "123abc";
		for (int i = 0;i < sizeof(s2);i++)
		{
			cout << i << "s2 : " << (int)(s2[i]) << endl;
			cout << i << "s3 : " << (int)(s3[i]) << endl;
		}
		for (int i = 0;i < strlen(s2);i++)
		{
			cout << i << " : " << s2[i] << endl;
		}
	}

	//string插入和删除
	void fun7()
	{
		cout << "\n\nTest_fun7" << endl;
		//对字符串进行插入和删除字符串操作
		// 函数原型:
		// string& insert(int pos,const char* s) //在pos位置插入字符串
		// string& insert(int pos,const string& s) //在pos位置插入字符串
		// string& insert(int pos,int n,char c) //在pos位置插入n个字符c
		// string& erase(int pos, int n = npos) //删除从pos位置开始的n个字符

		string s1 = "123abc";
		string s2 = "dd";
		cout << s1 << endl;
		s1.insert(0, "a");
		cout << s1 << endl;
		s1.insert(1, s2);
		cout << s1 << endl;
		s1.insert(2, 3, 'e');
		cout << s1 << endl;
		s1.erase(4,2);
		cout << s1 << endl;
		s1.erase(2);
		cout << s1 << endl;
	}

	//string子串
	void fun8()
	{
		cout << "\n\nTest_fun8" << endl;
		//string子串
		//从字符串中获取想要的子串
		//函数原型：
		//string substr(int pos =0 ,int n = npos)const //返回从pos开始的n个字符组成的字符串
		string s1 = "123123abc";
		string s2;
		s2 = s1.substr(0, 6);
		cout << s2 << endl;

		string s3 = "zhangsan@sina.com";
		string s4 = s3.substr(0, s3.find('@'));
		cout << s4 << endl;
	}
}

void testString()
{
	//string容器
	// string和char*的区别：
	// char*是一个指针(C风格的字符串)
	// string是一个类，类内部封装了char*，对字符串进行管理
	// string提供了很多成员方法，提供了丰富的字符串操作功能
	// 
	// 构造函数：
	// string() 默认构造空字符串
	//	示例：std::string s1;
	// string(const char*) 从C风格字符串构造
	//	示例：std::string s2("hello");
	// string(const string&) 拷贝构造
	//	示例：std::string s3(s2);
	// string(size_t, char) 重复字符构造
	//	示例：std::string s4(5, 'a'); // "aaaaa"
	// string(InputIt first, InputIt last) 从迭代器范围构造
	//	示例：std::string s5(s2.begin(), s2.end());
	// string(string&&) 移动构造 (C++11)
	//	示例：std::string s6(std::move(s5));
	// string(const string& str, size_t pos = 0, size_t count = npos) 子串构造函数
	//	参数：str：源字符串（必须是 std::string 类型）
	//		  pos：起始位置（默认为 0）
	//		  count：要复制的字符数量（默认为 npos，即复制到字符串末尾）
	//	示例：std::string s7(s2, 1);//"ello"
	// string(const char* s, size_t count); 指针+长度构造函数
	//	参数：s：源字符数组（const char* 类型）
	//		  count：要复制的字符数量
	//	示例：char s8[] = "444555";
	//		  string s9(s8, 2);//"44"
	// 
	// 成员函数：
	//	容量相关：
	//	size()/length()	返回字符数量	s.size()
	//	capacity()	返回存储容量	s.capacity()
	//	empty()	检查是否为空	if(s.empty())
	//	reserve(size_t)	预留存储空间	s.reserve(100)
	//	shrink_to_fit()	减少容量以适应大小 (C++11)	s.shrink_to_fit()
	//	元素访问：
	//	operator[]	无检查访问	char c = s[0]
	//	at(size_t)	有边界检查的访问	char c = s.at(0)
	//	front()	访问首字符 (C++11)	char c = s.front()
	//	back()	访问末字符 (C++11)	char c = s.back()
	//  data()	返回底层字符数组 (C++11 起保证以空字符结尾)	const char* p = s.data()
	//  c_str()	返回 C 风格字符串	const char* p = s.c_str()
	//  修改操作：
	//	operator=	赋值操作	s = "new"
	//  assign()	多种重载的赋值	s.assign(3, 'x')
	//  append()	追加内容	s.append(" world")
	//  push_back(char)	追加单个字符	s.push_back('!')
	//  pop_back()	删除末尾字符 (C++11)	s.pop_back()
	//  insert()	插入内容	s.insert(0, "Hello ")
	//  erase()	删除内容	s.erase(0, 5)
	//  replace()	替换内容	s.replace(0, 5, "Hi")
	//  clear()	清空内容	s.clear()
	//  resize()	调整大小	s.resize(10, ' ')
	//  swap(string&)	交换内容	s1.swap(s2)
	//  字符串操作：
	//	find()	查找子串/字符	s.find("lo")
	//  rfind()	反向查找	s.rfind('l')
	//  find_first_of()	查找字符集中任一字符首次出现	s.find_first_of("abc")
	//  find_last_of()	查找字符集中任一字符最后出现	s.find_last_of("abc")
	//  find_first_not_of()	查找不在字符集中的字符首次出现	s.find_first_not_of(" ")
	//  find_last_not_of()	查找不在字符集中的字符最后出现	s.find_last_not_of(" ")
	//  substr()	获取子串	s.substr(1, 3)
	//  compare()	比较字符串	s.compare("hello")
	//  非成员函数：
	//  operator+	字符串连接	s = s1 + s2
	//  operator== 等	比较运算符	if(s1 == s2)
	//  std::getline()	从流中读取一行	std::getline(std::cin, s)
	//  std::stoi() 等	字符串转换	int i = std::stoi("42")
	//  std::to_string()	数值转字符串	std::string s = std::to_string(3.14)
	//  迭代器支持：
	//	std::string 支持所有标准迭代器操作
	// 
	//

	fun1();

	//赋值操作
	fun2();

	//字符串拼接
	fun3();

	//string查找和替换
	fun4();

	//string字符串比较
	fun5();

	//string字符单个存取
	fun6();

	//string插入和删除
	fun7();

	//string子串
	fun8();
}
