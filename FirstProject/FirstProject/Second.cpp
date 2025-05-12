#include "Second.h"


//在函数体外的变量为全局变量
int g_a = 10;
//const修饰的全局变量为全局常量
const int c_g_a = 10;


int* Fun()
{
	int a = 10;
	return &a;
}

int* Fun2()
{
	int* p = new int(10);
	return p;
}


//内存模型相关测试
void TestMemory()
{
	//C++程序在执行时，将内存大方向上划分为4个区域
	//代码区：存放函数体的二进制代码，由操作系统进行管理(所有写的代码在此区域)
	//全局区：存放全局变量和静态变量及常量
	//栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
	//堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收

	//意义：主要是不同区域存放的数据，会赋予不同的生命周期，让编程更灵活

	//程序运行前
	//程序编译后，生成exe可执行程序，未运行程序前，已经有两个区域的数据
	//代码区 存放CPU执行的机器指令
	//特点：共享，代码区是共享的，对于频繁被执行的程序，读的是相同的代码，不会复制一份再读
	//		只读，代码区是只读的，防止程序被意外修改

	//全局区
	//存放了全局变量、静态变量、字符串常量、全局常量
	//该区域的数据在程序结束后由操作系统释放

	//在函数体内的变量为局部变量
	int l_a = 10;
	//const修饰的局部变量为局部常量
	const int c_l_a = 10;

	//static修饰的变量为静态变量
	static int s_a = 10;
	//双引号引起来的为字符串常量
	
	//非全局区
	cout << "局部变量的地址" << &l_a << endl;
	cout << "局部常量的地址" << &c_l_a << endl << endl;
	//全局区
	cout << "全局变量的地址" << &g_a << endl;
	cout << "静态变量的地址" << &s_a << endl;
	cout << "全局常量的地址" << &c_g_a << endl;
	cout << "字符串常量的地址" << &"c_str" << endl;


	//程序运行后
	//程序运行后内存有两个区域，栈区、堆区

	//栈区
	//由编译器自动分配释放，存放函数的参数值，局部变量等
	//注意不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
	//感觉应该说是不要返回栈区变量的地址，后续地址被自动释放后引用会导致异常

	int* p = Fun();
	cout << *p << endl;//64位模式下，两次均返回10
	cout << *p << endl;//32位模式下，第二次返回乱数据

	cout << "栈区变量的地址" << p << endl;

	//堆区
	//由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收
	//C++中主要利用new在堆区开辟内存

	int* p2 = Fun2();
	cout << *p2 << endl;
	cout << *p2 << endl;

	cout << "堆区变量的地址" << p2 << endl;

	//释放内存用delete
	delete p2;
	//cout << *p2 << endl;//释放后再访问，会报错 读取访问权限冲突
	
	//在内存开辟数组
	int* p3 = new int[10];
	cout << "堆区变量的地址" << p3 << endl;
	//释放数组
	//注意，数组、变量内存的释放 一个是delete[]，一个是delete，用错可能会导致异常
	//注意，不要重复释放内存，会报错
	//delete p3;//错误
	delete[] p3;//正确
	//delete[] p3;//重复释放，报错
	
	
	
	

}


void MySwap(int &a,int&b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

//测试返回局部变量(栈区变量)的引用
int& Fun3()
{
	int a = 10;
	return a;
}

int& Fun4()
{
	static int a = 10;
	return a;
}

void PrintVal(const int& val)
{
	cout << val << endl;
	//val = 1000;//非法 const修饰形参后，防止误操作，不能在函数中修改传入的实参
}

//引用传参相关测试
void fun10_6(const int& a)
{
	cout << a << endl;
}
int fun10_6_1()
{
	int a = 10;
	return a;
}
void fun10_6_2(int& a)
{
	cout << a << endl;
}
void fun10_6_3()
{
	fun10_6(fun10_6_1());
	//fun10_6_2(fun10_6_1());//报错，引用参数不能接收非const修饰的右值(没有明确内存地址的临时对象或变量)
}

//引用相关测试
void TestQuote()
{
	//引用的作用 ：给变量起别名
	//语法：数据类型 &别名 = 原名
	// 引用本质在C++内部实现是一个指针常量
	//使用场景，主要是简化函数参数传递、返回值优化、链式调用等

	/*int a = 10;
	int& b = a;

	cout << a << endl;
	cout << b << endl;

	b = 20;
	cout << a << endl;
	cout << b << endl;*/

	//注意事项
	//1、引用必须要初始化
	//2、引用不可重新绑定
	//int& b1;//错误

	//引用方式传递参数
	/*int a1 = 10;
	int b1 = 20;
	MySwap(a1, b1);
	cout << a1 << endl;
	cout << b1 << endl;*/

	//引用做函数的返回值
	//注意事项，不要返回局部变量(栈区变量)的引用
	//int& b2 = Fun3();//情况同返回栈区变量的地址
	//cout << b2 << endl;//64位下两次输出相同
	//cout << b2 << endl;//32位下第二次返回乱数据

	//函数的调用作为左值
	//如果函数的返回值是引用，这个函数调用可以作为左值
	/*int& b3 = Fun4();
	cout << b3 << endl;
	cout << Fun4() << endl;
	Fun4() = 1000;
	cout << b3 << endl;
	cout << Fun4() << endl;*/


	//常量引用
	//使用场景：用来修饰形参，防止误操作
	int a4 = 100;
	PrintVal(a4);


	//int& ref = 10;//非法操作，引用必须引用一块合法的内存空间
	const int& ref = 10;//合法操作，实际上编译器执行了 int temp = 10; const int& ref = temp;
	//ref = 20;//非法操作，const修饰后，引用的值不可修改

	fun10_6_3();
}

//测试占位参数
int TestFun(int a, int)
{
	cout << "here" << endl;
	return 0;
}

//测试函数重载
void Fun11()
{
	cout << "Fun11()" << endl;
}
void Fun11(int a)//个数不同
{
	cout << "Fun11(int a)" << endl;
}
void Fun11(double a)//类型不同
{
	cout << "Fun11(double a)" << endl;
}
void Fun11(int a, double b)//顺序不同
{
	cout << "Fun11(int a, double b" << endl;
}
void Fun11(double b, int a)//顺序不同
{
	cout << "Fun11(double b, int a)" << endl;
}
//int Fun11()//非法 函数的返回值不可以作为函数重载的条件
//{
//
//}

//引用作为重载条件
void Fun22(int& a)//实际上该函数无法接收 10 或者const int b这种常量，因为int& a实际上是非常量，可修改
{
	cout << "Fun22(int& a)" << endl;
}
void Fun22(const int& a)//直接传入10这种常量时，实际上编译器执行了 int temp = 10; const int& a = temp;
{
	cout << "Fun22(const int& a)" << endl;
}
//函数重载中有默认参数
void Fun33(int a,int b = 10)//编译时不会报错，但调用时可能会有二义，导致问题
{
	cout << "Fun33(int a,int b = 10)" << endl;
}
void Fun33(int a)
{
	cout << "Fun33(int a)" << endl;
}

//函数相关测试
void TestFunction()
{
	//函数默认参数
	// 语法：返回值类型 函数名(参数1,参数2,参数3 = 默认值){}
	//注意事项
	//1、参数列表中，某个位置参数有默认值了，后面的所有参数都必须有默认值
	//2、如果函数的声明和定义分开写，只能在声明或者定义其中一个地方写上默认参数


	//函数占位参数
	//C++中，函数的形参列表可以有占位参数，用来占位，调用函数的时候必须填补该位置
	//语法：返回值类型 函数名(数据类型){}
	//注：占位参数也可以有默认参数
	//TestFun(10,20);


	//函数重载
	//函数名相同，提高复用性
	//条件
	//1、函数要在同一个作用域下
	//2、函数名称相同、函数返回值必须相同(函数的返回值不可以作为函数重载的条件)
	//3、函数参数的类型不同 或者 个数不同 或者顺序不同
	/*Fun11();
	Fun11(10);
	Fun11(3.14);
	Fun11(10,3.14);
	Fun11(3.14,10);*/

	//函数重载注意事项
	//引用作为重载条件
	int a = 10;
	const int b = 20;
	Fun22(a);//调用int& a
	Fun22(10);//调用const int& a
	Fun22(b);//调用const int& a
	//函数重载中有默认参数(要避免有可能产生二义的情况发生)
	//Fun33(10);//有二义，报错，无法通过编译
	Fun33(10, 20);
}
