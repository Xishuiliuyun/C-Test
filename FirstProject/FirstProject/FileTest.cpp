#include "FileTest.h"


namespace {

	//写文本文件测试
	void fun1()
	{
		ofstream ofs;
		ofs.open("test.txt", ios::out);//该命令执行完成后，文件中的内容已经被清空了
		ofs << "test test" << endl;//该命令执行完成后，已经向文件添加了内容
		ofs << "test test" << endl;
		ofs.close();

		ofstream ofs2("test.txt", ios::app);
		ofs2 << "test test" << endl;
		ofs2 << "test test" << endl;
		ofs2.close();

		fstream ofs3("test.txt", ios::in | ios::out);
		ofs3 << "test1 test1" << endl;//不删除原数据，从头开始覆盖写入
		ofs3 << "test1 test1" << endl;
		ofs3.close();

	}

	//读文本文件测试
	int fun2()
	{
		ifstream ifs1;
		ifs1.open("testRead.txt", ios::in);
		if (!ifs1.is_open())
		{
			cout << "open file fail" << endl;
			return -1;
		}
		//方式一：
		//>>右移运算符按词语读取文件内容，会跳过空白字符（空格、制表符、换行符）
		//每次读取数据放到buf中时，读取到空白字符前的内容
		cout << "-------------" << ">>右移运算符" << "-------------" << endl;
		char buf[1024] = { 0 };
		while (ifs1 >> buf)
		{
			cout << buf << endl;
		}
		ifs1.clear();
		cout << "-------------" << ifs1.tellg() << "-------------" << endl;//win下gbk编码格式的文件，中文占2个字节，英文占1个字节，换行占2个字节
		ifs1.seekg(0,ios::beg);
		string str;
		while (ifs1 >> str)
		{
			cout << str << endl;
		}

		//方式二：
		//ifstream对象的getline函数 按行读取文件内容
		//每次读取数据放到buf中时，读取到换行前的内容
		cout << "-------------" << "ifstream对象的getline函数" << "-------------" << endl;
		ifs1.clear();
		ifs1.seekg(0, ios::beg);
		char buf2[1024];
		while (ifs1.getline(buf2, sizeof(buf2)))
		{
			cout << buf2 << endl;
		}
		ifs1.clear();
		cout << "-------------" << ifs1.tellg() << "-------------" << endl;
		ifs1.seekg(0, ios::beg);
		//string str2;
		//while(ifs1.getline(str2,1024))//string类型变量不能作为参数调用该方法

		//方式三：
		//全局的getline函数 按行读取文件内容
		//每次读取数据放到buf中时，读取到换行前的内容
		//需包含string头文件
		cout << "-------------" << "全局的getline函数" << "-------------" << endl;
		string str3;
		while (getline(ifs1, str3))
		{
			cout << str3 << endl;
		}
		ifs1.clear();
		cout << "-------------" << ifs1.tellg() << "-------------" << endl;
		ifs1.seekg(0, ios::beg);
		//char buf3[1024];
		//while (getline(ifs1,buf3))//char*类型变量不能作为参数调用该方法

		//方式四：
		//ifstream对象的get函数 按字符读取文件内容
		//每次读取一个字符，所有的内容都会被读取到
		cout << "-------------" << "ifstream对象的get函数" << "-------------" << endl;
		char ch;
		while (ifs1.get(ch))
		{
			cout << ch;
		}
		cout << endl;
		ifs1.clear();
		cout << "-------------" << ifs1.tellg() << "-------------" << endl;
		ifs1.seekg(0, ios::beg);
		char ch2;
		while ((ch2 = ifs1.get()) != EOF)
		{
			cout << ch2;
		}
		cout << endl;
		ifs1.clear();
		cout << "-------------" << ifs1.tellg() << "-------------" << endl;
		ifs1.seekg(0, ios::beg);

		//方式五：
		//stringstream对象接收 流对象rdbuf方法 的数据 一次性读取整个文件
		//需要包含头文件#include <sstream>
		cout << "-------------" << "stringstream对象接收 流对象rdbuf方法" << "-------------" << endl;
		stringstream buffer;
		buffer << ifs1.rdbuf();
		string contents = buffer.str();
		cout << contents << endl;
		cout << "-------------" << ifs1.tellg() << "-------------" << endl;
		ifs1.close();


	}


	//读写二进制文件测试
	class class3
	{
	public:
		char m_Name[64];
		int m_Age;
		class3() {};
		class3(const char* name,int age)
		{
			memcpy(m_Name, name, strlen(name) + 1);
			m_Age = age;
		}
	};
	void fun3()
	{
		class3 c1("test file", 18);
		ofstream ofs;
		ofs.open("test.txt", ios::out | ios::binary);
		ofs.write((const char*)&c1, sizeof(c1));
		ofs.close();

		class3 c2;
		ifstream ifs;
		ifs.open("test.txt", ios::in | ios::binary);
		if (!ifs.is_open())
		{
			cout << "打开文件失败" << endl;
			return;
		}
		ifs.read((char*)&c2, sizeof(c2));
		ifs.close();
		cout << c2.m_Name << "\t" << c2.m_Age << endl;

	}

}


//文件读写测试
void testFile()
{
	//文件操作
	//C++中对文件操作需要包含头文件<fstream>
	// 文件类型：
	// 1、文本文件
	//	文件内容是可读的字符数据。
	//	通常以 ASCII 或 UTF-8 编码存储。
	//	每行以换行符（\n）分隔。
	//	常见扩展名：.txt、.csv、.json、.xml、.html、.cpp、.h
	// 2、二进制文件
	//	文件内容是以字节为单位存储的原始数据。
	//	内容不可直接阅读，通常需要特定程序解析。
	//	常用于存储结构化数据（如对象、数组等）。
	// 文件模式：
	// 1、文本模式
	//	默认模式，适用于处理文本文件。
	//	自动处理换行符（如 Windows 平台上的 \r\n 转换为 \n）。
	// 2、二进制模式
	//	明确指定 ios::binary 模式，适用于处理二进制文件。
	//	文件内容以原始字节形式处理，不进行任何转换。
	// 
	// 操作文件的三个大类
	// 1、ofstream:写操作
	// 2、ifstream:读操作
	// 3、fstream:读写操作
	// 
	// 写文件：
	// 1、包含头文件：	#include<fstream>
	// 2、创建流对象：	ofstream 变量名;
	// 3、打开文件：	流对象.open("文件路径",打开模式);
	//					或者在创建流对象时传入文件路径直接打开 ofstream 变量名("文件路径",打开模式);//不写打开模式参数，默认打开方式为ios::out
	// 4、写数据：		流对象<<"写入的数据";//使用<<运算符，使用方式与cout类似
	// 5、关闭文件：	流对象.close();
	// 
	// 读文件：
	// 1、包含头文件：			#include<fstream>
	// 2、创建流对象：			ifstream 变量名;
	// 3、打开文件：			流对象.open("文件路径",打开模式);
	//							或者在创建流对象时传入文件路径直接打开 ifstream 变量名("文件路径",打开模式);//不写打开模式参数，默认打开方式为ios::in
	// 4、判断文件是否打开成功：流对象.is_open()//返回文件是否成功打开
	// 5、读数据：				有各种方式进行数据读取
	// 6、关闭文件：			流对象.close();
	// 
	// 读数据的实现方式：
	// 1、
	//	>>右移运算符按词语读取文件内容，会跳过空白字符（空格、制表符、换行符）
	//	每次读取数据放到buf中时，读取到空白字符前的内容
	// 2、
	//	ifstream对象的getline函数 按行读取文件内容
	//	每次读取数据放到buf中时，读取到换行前的内容
	// 3、
	//	全局的getline函数 按行读取文件内容
	//	每次读取数据放到buf中时，读取到换行前的内容
	//	需包含string头文件
	// 4、
	//	ifstream对象的get函数 按字符读取文件内容
	//	每次读取一个字符，所有的内容都会被读取到
	// 5、
	//	stringstream对象接收 流对象rdbuf方法 的数据 一次性读取整个文件
	//	需要包含头文件#include <sstream>
	//	stringstream对象接收到的数据需用str函数转为string类型后使用
	// 
	// 
	// 
	// 
	// 文件打开模式：
	// ios::in：
	//	打开文件用于读取。
	//	默认为 ifstream 的打开模式。
	//	如果文件不存在，打开失败。
	// ios::out：
	//	打开文件用于写入。
	//	默认为 ofstream 的打开模式。
	//	如果文件已存在，则清空内容；如果文件不存在，则创建新文件。
	// ios::binary：
	//	以二进制模式打开文件。
	//	通常与其他模式结合使用（如 ios::in | ios::binary）。
	// ios::app：
	//	打开文件用于追加。
	//	写入的内容会被添加到文件末尾，不会清空原有内容。
	//	强制所有输出操作都在文件末尾进行
	// ios::ate：
	//	打开文件后定位到文件末尾。
	//	与 ios::app 不同的是，ios::ate 允许在文件的任意位置进行读写。
	//	只是在打开文件时将文件指针置于文件末尾，之后你可以自由地移动文件指针到任何位置进行读写操作。
	// ios::trunc：
	//	如果文件已存在，则清空文件内容。
	//	默认情况下，ios::out 包含 ios::trunc。
	// 
	// 



	fun1();


	fun2();

	fun3();
}