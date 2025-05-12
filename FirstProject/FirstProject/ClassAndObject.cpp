#include "ClassAndObject.h"
#include "Circle.h"

const double PI = 3.14;

//封装测试
class Circle
{
	//访问权限
public :

	//属性
	int m_r;//半径

	//行为
	double CalculatePerimeter()//计算周长
	{
		return 2 * PI * m_r;
	}

};

class Student
{
public:

	string name;
	int NO;

	void writeData(string name,int NO)
	{
		this->name = name;
		this->NO = NO;
	}
	void readData()
	{
		cout << name << endl;
		cout << NO << endl;
	}
};


//访问权限相关
class Person
{
public :
	string m_Name;

protected:
	string m_Car;

private:
	int m_Password;

private:
	void fun1()
	{
		m_Name = "张三";
		m_Car = "BEN";
		m_Password = 123456;
	}

public:
	void fun2()
	{
		cout << m_Name << endl;
		cout << m_Car << endl;
	}

};


//struct 和 class 的区别
class C1 
{
	int m_A;//默认的访问权限为私有
};
struct C2
{
	int m_A;//默认的访问权限为公共
	void fun1()
	{
		cout << m_A << endl;
	}
};


//class成员属性读写测试
class Preson2
{
	string m_Name;//设置为 可读可写
	int m_Age = 18;//设置为 只读
	string m_Idol;//设置为 只写
	string m_Gender;//设置为 可读可写，检验写入的数据

public:
	string getName()
	{
		return m_Name;
	}
	void setName(string name)
	{
		m_Name = name;
	}
	int getAge()
	{
		return m_Age;
	}
	void setIdol(string idol)
	{
		m_Idol = idol;
	}
	string getGender()
	{
		return m_Gender;
	}
	void setGender(string gender)
	{
		if (gender == "男" || gender == "女")
		{
			m_Gender = gender;
		}
		else
		{
			cout << "写入数据异常，写入失败" << endl;
			return;
		}
	}
};

struct Info
{
	int m_Length;
	int m_Width;
	int m_Heigth;
};
class Cube
{
	Info info;
	
public :
	void setInfo(int length,int width,int heigth)
	{
		info.m_Length = length;
		info.m_Width = width;
		info.m_Heigth = heigth;
	}
	Info getInfo()
	{
		return info;
	}
	int calculateArea()
	{
		return 2 * (info.m_Length * info.m_Width + info.m_Length * info.m_Heigth + info.m_Width * info.m_Heigth);
	}
	int calculateVolume()
	{
		return info.m_Length * info.m_Width * info.m_Heigth;
	}
	bool contrastCube(Info cubeInfo)
	{
		if (cubeInfo.m_Heigth == info.m_Heigth && cubeInfo.m_Length == info.m_Length && cubeInfo.m_Width == info.m_Width)
		{
			return true;
		}
		else return false;
	}
};

bool contrastCube(Info cubeInfo1, Info cubeInfo2)
{
	if (cubeInfo1.m_Heigth == cubeInfo2.m_Heigth && cubeInfo1.m_Length == cubeInfo2.m_Length && cubeInfo1.m_Width == cubeInfo2.m_Width)
	{
		return true;
	}
	else return false;
}

//class Point
//{
//	int m_X;
//	int m_Y;
//
//public :
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	int getX()
//	{
//		return m_X;
//	}
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	int getY()
//	{
//		return m_Y;
//	}
//};

//class Circle2
//{
//	Point m_Center;
//	int m_R;
//
//public:
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	int getR()
//	{
//		return m_R;
//	}
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//	Point getCenter()
//	{
//		return m_Center;
//	}
//};

void isInCircle(Circle2& c, Point& p)
{
	int squareDir = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int squareR = c.getR() * c.getR();
	if (squareDir > squareR)//距离的平方大于半径平方
	{
		cout << "点在圆外" << endl;
	}
	else if (squareDir == squareR)//距离的平方等于半径平方
	{
		cout << "点在圆上" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}


//构造函数析构函数测试
class Class1
{
	int m_A;
public:	//需要public访问权限才可以在类外创建对象，不然编译器会报错
		//如果是protected访问权限，允许派生类创建对象，不允许类外创建对象
		//如果是private访问权限，不允许外部和派生类创建对象，通常用于单例模式、工厂模式
	Class1()
	{
		cout << "构造函数调用" << endl;
	}
	Class1(int a)
	{
		cout << "有参构造函数调用" << endl;
		m_A = a;
	}
	~Class1()
	{
		cout << "析构函数调用" << endl;
	}
};
void fun()
{
	Class1 c1;
}

//构造函数分类及调用测试
class Class2
{
public:
	int m_A;
	int* m_Ap;//A指针
	string m_Str;
	//const int m_c_A;//可以在类内定义常量成员，要在成员初始化列表中进行初始化		:m_c_A(10), m_y_A(a)
	//int& m_y_A;//可以在类内定义引用成员，要在成员初始化列表中进行初始化		:m_c_A(10), m_y_A(a)
	const int m_c_B = 10;//也可以直接赋初始值，但就无法用变量赋值了，只能是固定的值
	int& m_y_B = m_A;//也可以直接赋初始值，但就无法用变量赋值了，只能是固定的值

public:
	//有参构造函数
	Class2(int a,int* ap,string str) //:m_c_A(10), m_y_A(a)
	{
		cout << "有参构造函数" << endl;
		m_A = a;
		m_Ap = ap;
		m_Str = str;
	}
	//无参构造函数(默认构造函数)
	Class2() :m_A(10), m_Ap(&m_A), m_Str("成员初始化列表")//成员初始化列表
	{
		cout << "无参构造函数(默认构造函数)" << endl;
		//m_A = 10;
	}
	//拷贝构造函数(浅拷贝，只拷贝变量的值进行赋值)
	Class2(const Class2& other)
	{
		cout << "拷贝构造函数(浅拷贝，只拷贝变量的值进行赋值)" << endl;
		m_A = other.m_A;//同一个类的其他对象实例不受类的私有成员访问限制的影响
		m_Ap = other.m_Ap;
		m_Str = other.m_Str;
	}
	//移动构造函数(从临时对象“移动”资源，而不是复制资源。)//原对象资源需置空
	Class2(Class2&& other) noexcept 
	{
		cout << "移动构造函数(从临时对象“移动”资源，而不是复制资源。)" << endl;
		m_A = other.m_A;
		m_Ap = other.m_Ap;
		m_Str = std::move(other.m_Str);
		other.m_Ap = nullptr;// 将原对象的数据指针置为 nullptr
		other.m_A = 0;
		other.m_Str = "";
	}
	//委托构造函数(在一个构造函数中调用同一个类的其他构造函数)
	Class2(int a) :Class2(a, &a, "Default Text")
	{
		cout << "委托构造函数(在一个构造函数中调用同一个类的其他构造函数)" << endl;
	}

	void printMessage()
	{
		if (!m_Ap) cout << "m_Ap空指针" << endl;
		else
		{
			cout << "m_A = " << m_A << "\nm_Ap 地址" << m_Ap << "\n*m_Ap 的值" << *m_Ap
				<< "\nm_Str = " << m_Str << endl;
		}
		
	}
};
//拷贝构造函数测试
void fun1(Class2 c)
{
	cout << "拷贝构造函数测试,对象值传递给函数时，会调用拷贝构造函数" << endl;
}
Class2 fun2()
{
	Class2 c;//调用默认构造函数
	cout << "拷贝构造函数测试,函数值返回对象时，会调用拷贝构造函数" << endl;
	return c;
}
//移动构造函数测试
Class2 fun3()
{
	int a;
	return Class2(10,&a,"移动构造函数测试");
}


//浅拷贝和深拷贝测试
class Class3//编译器默认实现的浅拷贝
{
	int* m_P;
public:
	Class3(int p )
	{
		m_P = new int(p);
	}
	//没有写拷贝函数时，编译器会默认实现的浅拷贝
	Class3(const Class3& other)
	{
		m_P = other.m_P;
	}
	~Class3()
	{
		if (m_P != nullptr)
		{
			delete m_P;//不会修改m_P指向的地址，但会把该内存标记为可分配，再此释放会报错
			m_P = nullptr;//修改m_P指针指向的地址，主要是便于后续进行判断
		}
	}
	void printMessage()
	{
		if (m_P != nullptr) cout << "地址：" << m_P << "\t值：" << *m_P << endl;
		else cout << "地址为空" << endl;
	}
};
void fun30()
{
	int a = 10;
	Class3 c30(a);
	Class3 c31(c30);
	c30.printMessage();
	c30.~Class3();
	c30.printMessage();
	c31.printMessage();
}
class Class4
{
	int* m_P;
public:
	Class4(int p)
	{
		m_P = new int(p);
	}
	//实现深拷贝
	Class4(const Class4& other)
	{
		m_P = new int(*other.m_P);
	}
	~Class4()
	{
		if (m_P != nullptr)
		{
			delete m_P;//不会修改m_P指向的地址，但会把该内存标记为可分配，再此释放会报错
			m_P = nullptr;//修改m_P指针指向的地址，主要是便于后续进行判断
		}
	}
	void printMessage()
	{
		if (m_P != nullptr) cout << "地址：" << m_P << "\t值：" << *m_P << endl;
		else cout << "地址为空" << endl;
	}
};
void fun40()
{
	int a = 10;
	Class4 c40(a);
	Class4 c41(c40);
	c40.printMessage();
	c40.~Class4();
	c40.printMessage();
	c41.printMessage();
}


//类对象作为类的成员时，构造和析构的顺序
class Class51
{
	string m_MemberClassStr;
public:
	Class51(string str,int a)
	{
		cout << "成员类的构造函数" << endl;
		cout << a << endl;
		m_MemberClassStr = str;
	}
	~Class51()
	{
		cout << "成员类的析构函数" << endl;
	}
};
class Class5
{
	string m_ClassStr;
	Class51 m_MemberClass;
public:
	Class5(string classStr,string memberClassStr):m_ClassStr(classStr), m_MemberClass(memberClassStr,10)
	{
		cout << "类的构造函数" << endl;
	}
	~Class5()
	{
		cout << "类的析构函数" << endl;
	}
};
void fun50()
{
	cout << "\n\nTest_fun50" << endl;
	Class5("Class5", "Class51");
}


//静态成员相关测试
class Class6//计数器(记录当前类有多少对象实例)
{
public :
	static int count;//静态变量类内声明
	static const int constValue = 10;

	Class6()//构造函数启用时调用
	{
		count++;
	}
	~Class6()
	{
		count--;
	}
	static void showCount()
	{
		cout << "Number of objects:" << count << endl;
	}

};
int Class6::count = 0;//类外初始化
void fun6()
{
	cout << "\n\nTest_fun60" << endl;
	Class6 c60;
	c60.showCount();
	Class6 c61;
	Class6::showCount();
	c60.count = 10;
	c61.showCount();
	Class6::count = 100;
	Class6::showCount();

}


//C++中，类内的成员变量和成员函数分开存储
class Class7
{

};
class Class71
{
	int m_A;
};
class Class72
{
	int m_A;
	int m_B;
};
class Class73
{
	int m_A;
	static int m_B;//静态成员变量 不属于类对象上
public:
	void fun()//非静态成员函数 不属于类对象上
	{
		cout << "here" << endl;
	}
	static void fun2()//静态成员函数 不属于类对象上
	{
		cout << "here" << endl;
	}
};
int Class73::m_B = 0;
void fun7()
{
	cout << "\n\nTest_fun7" << endl;
	Class7 c1;
	cout << sizeof(Class7)<<endl;
	cout << sizeof(c1)<<endl;

	Class71 c11;
	cout << sizeof(Class71) << endl;
	cout << sizeof(c11) << endl;

	Class72 c12;
	cout << sizeof(&c1) << endl;
	cout << sizeof(&c11) << endl;
	cout << sizeof(&c12) << endl;

	Class73 c13;
	cout << sizeof(c13) << endl;
	cout << sizeof(Class73) << endl;

}


//this指针
class Class8
{
	int m_A;
public:
	Class8(int a):m_A(a)
	{
	}
	Class8& fun(int a)//链式调用时要返回引用  回的是引用，可以看作是指针常量
	{
		this->m_A += a;
		return *this;
	}
	Class8 fun1(int a)//因为被返回的是值，是对象的副本，是一个新的对象，所以只有第一次调用时修改了值，链式后面修改的是副本的值
	{
		this->m_A += a;
		return *this;
	}
	void fun2()
	{
		cout << m_A << endl;
	}
};
void fun8()
{
	cout << "\n\nTest_fun8" << endl;
	Class8 c1(10);
	c1.fun2();
	c1.fun(10).fun(10).fun(10);//Class8& c2 = c1(*this) //c2实际就是c1
	c1.fun2();
	c1.fun1(10).fun1(10).fun1(10);//Class8 c2 = c1(*this)//c2是一个新的对象
	c1.fun2();
}


//空指针访问成员函数
class Class9
{
public :
	int m_A;
	void fun1()
	{
		cout << "空指针访问成员函数" << endl;
	}
	void fun2()
	{
		cout << m_A << endl;//实际访问的是this->m_A
	}
};
void fun9()
{
	cout << "\n\nTest_fun9" << endl;
	Class9 *c1 = nullptr;
	c1->fun1();
	(*c1).fun1();
	//c1->fun2();//报错 读取访问权限冲突
	//(*c1).fun2();//报错 读取访问权限冲突
}



//常函数、常对象
class Class10_1
{
public :
	int m_A;
	mutable int m_B;
	static int m_C;

	Class10_1()
	{

	}
	Class10_1(int a ):m_A(a)
	{

	}
	static void fun()
	{
		m_C = 30;
	}
	void fun1()
	{
		m_A = 10;//实际是this->m_A = 10;
	}
	int fun2() const//实际const修饰的是this， 此处this 相当于 const Class10_1* const this
	{
		//this = nullptr;//报错 this的值不可修改 this的指向不可修改
		//m_A = 20;//报错 左值不可修改
		m_C = 20;//静态成员可修改
		m_B = 100;//mutable修饰的成员变量可修改
		return m_A;//非静态成员变量可作为返回值
	}
	void fun3() const//常函数只能调用其他常函数或静态成员函数，不能调用非 const 成员函数
	{
		fun();
		//fun1();报错
		fun2();
	}
	void PVal()
	{
		cout << "int m_A\t" << m_A << endl;
		cout << "mutable int m_B\t" << m_B << endl;
		cout << "static int m_C\t" << m_C << endl;

	}
	void CPVal() const
	{
		cout << "int m_A\t" << m_A << endl;
		cout << "mutable int m_B\t" << m_B << endl;
		cout << "static int m_C\t" << m_C << endl;

	}
};
int Class10_1::m_C = 10;
void fun10_1()
{
	cout << "\n\nTest_fun10_1" << endl;
	//常函数
	Class10_1 c1;
	c1.fun1();
	c1.fun3();
	//c1.fun2();
	c1.PVal();
	//常对象
	const Class10_1 c2(30);
	//c2.m_A = 50;//非法
	c2.m_B = 500;
	//c2.PVal();//非法 ,只能调用常函数
	c2.fun2();
	c2.CPVal();
}


//友元
class Class10_2;
class Class10_2_2
{
	Class10_2* c1;
public:
	Class10_2_2();//此处只能声明，因为函数内访问了Class10_2中的构造函数，构造函数此时还没有被声明，无法被访问
	void PVal();
};
class Class10_2
{
	friend void fun10_2_2(Class10_2* class10_2);//友元声明
	friend class Class10_2_1;//友元声明
	friend void Class10_2_2::PVal();//友元声明 (成员函数做友元时，该类及其成员函数要在友元声明前声明)
private:
	int m_A;
public:
	int m_B;
	Class10_2()
	{
		m_A = 10;
		m_B = 20;
	}

};
class Class10_2_1//友元类
{
	Class10_2* c1;
public:
	Class10_2_1()
	{
		c1 = new Class10_2;
	}
	void PVal()
	{
		cout << c1->m_A << endl;
		cout << c1->m_B << endl;
	}
	void PVal(const Class10_2& c);//重载函数
};
void Class10_2_1::PVal(const Class10_2& c)//在类外定义函数
{
	cout << c.m_A << endl;
	cout << c.m_B << endl;
}
void fun10_2_1(Class10_2* class10_2)
{
	//cout << class10_2->m_A << endl;//报错
	cout << class10_2->m_B << endl;
}
void fun10_2_2(Class10_2* class10_2)//友元函数
{
	cout << class10_2->m_A << endl;
	cout << class10_2->m_B << endl;
}
Class10_2_2::Class10_2_2()
{
	c1 = new Class10_2;
}
void Class10_2_2::PVal()
{
	cout << "\n";
	cout << c1->m_A << endl;
	cout << c1->m_B << endl;
}
void fun10_2()
{
	cout << "\n\nTest_fun10_2" << endl;
	//全局函数做友元
	Class10_2 c1;
	fun10_2_1(&c1);
	fun10_2_2(&c1);
	//类做友元
	Class10_2_1 c2;
	c2.PVal();
	c2.PVal(c1);
	//成员函数做友元
	Class10_2_2 c3;
	c3.PVal();
	
}



//运算符重载
//+运算符重载 (相加运算符重载)
class Class10_3
{
public:
	int m_A;
	int m_B;
	Class10_3() :m_A(10), m_B(10) {}
	Class10_3(const Class10_3& other)
	{
		cout << "拷贝构造函数被调用" << endl;
		this->m_A = other.m_A;
		this->m_B = other.m_B;
	}
	Class10_3 operator+(const Class10_3& other)//成员函数实现
	{
		cout << "成员函数实现运算符重载" << endl;
		Class10_3 temp;
		temp.m_A = this->m_A + other.m_A;
		temp.m_B = this->m_B + other.m_B;
		return temp;
	}
	void PVal()
	{
		cout << "m_A\t" << m_A << endl;
		cout << "m_B\t" << m_B << endl;
	}
};
class Class10_3_1
{
public:
	int m_A;
	int m_B;
	Class10_3_1() :m_A(20), m_B(20) {}
	void PVal()
	{
		cout << "m_A\t" << m_A << endl;
		cout << "m_B\t" << m_B << endl;
	}
};
Class10_3 operator+(const Class10_3& lvalue, const Class10_3& rvalue)//成员函数实现
{
	cout << "全局函数实现运算符重载" << endl;
	Class10_3 temp;
	temp.m_A = lvalue.m_A + rvalue.m_A;
	temp.m_B = lvalue.m_B + rvalue.m_B;
	return temp;
}
Class10_3_1 operator+(const Class10_3_1& lvalue, const Class10_3_1& rvalue)//全局函数实现
{
	cout << "全局函数实现运算符重载" << endl;
	Class10_3_1 temp;
	temp.m_A = lvalue.m_A + rvalue.m_A;
	temp.m_B = lvalue.m_B + rvalue.m_B;
	return temp;
}
Class10_3_1 operator+(int num, const Class10_3_1& rvalue)//全局函数实现
{
	cout << "全局函数实现运算符重载" << endl;
	Class10_3_1 temp;
	temp.m_A = num + rvalue.m_A;
	temp.m_B = num + rvalue.m_B;
	return temp;
}
void fun10_3()
{
	cout << "\n\nTest_fun10_3" << endl;
	Class10_3 c1;
	Class10_3 c2;
	Class10_3 c3 = c1 + c2;//可能返回值优化（RVO）了，没有输出 拷贝构造函数被调用
	//Class10_3 c3 = c1.operator+(c2);//(本质)
	//Class10_3 c4 = c1;
	c3.PVal();

	Class10_3_1 c11;
	Class10_3_1 c12;
	Class10_3_1 c13 = c11 + c12;
	//Class10_3_1 c13 = operator+(c11, c12);//(本质)
	c13.PVal();

	Class10_3_1 c21;
	Class10_3_1 c22 = 100 + c21;
	c22.PVal();
}
//<<运算符重载 (左移运算符重载)
class Class10_4
{
	friend ostream& operator<<(ostream& cout, const Class10_4& c);
	int m_A;
	int m_B;
public:
	Class10_4() :m_A(10), m_B(20) {}
	ostream& operator<<(ostream& cout)
	{
		return cout << "m_A = \t" << m_A << "\nm_B = \t" << m_B;
	}
};
ostream& operator<<(ostream& cout, const Class10_4& c)
{
	return cout << "m_A = \t" << c.m_A << "\nm_B = \t" << c.m_B;
}
void fun10_4()
{
	cout << "\n\nTest_fun10_4" << endl;
	Class10_4 c1;
	c1 << cout << endl;
	cout << c1 << endl;
}
//++运算符重载 (递增运算符重载)
class Class10_5
{
	friend ostream& operator<<(ostream& cout, const Class10_5& c);
	int count;
public:
	Class10_5():count(0){}
	Class10_5& operator++()
	{
		count++;
		return *this;
	}
	Class10_5 operator++(int)
	{
		Class10_5 temp = *this;
		count++;
		return temp;
	}
};
ostream& operator<<(ostream& cout,const Class10_5& c)
{
	return cout << c.count;
}
void fun10_5()
{
	cout << "\n\nTest_fun10_5" << endl;
	Class10_5 c1;
	cout << ++(++c1) << endl;
	cout << c1++ << endl;
	cout << c1 << endl;
}
//=运算符重载 (赋值运算符重载)
class Class10_6
{
public:
	int* m_P;
public:
	Class10_6()
	{
		m_P = new int(10);
	}
	Class10_6& operator=(const Class10_6& other)
	{
		if (this == &other)//自赋值检查
		{
			return *this;
		}
		if (m_P != nullptr)
		{
			delete m_P;
			m_P = nullptr;
		}
		this->m_P = new int(*other.m_P);
		return *this;
	}
	~Class10_6()
	{
		if (m_P != nullptr)
		{
			delete m_P;
			m_P = nullptr;
			cout << "delete m_P" << endl;
		}
	}
};
void fun10_6()
{
	cout << "\n\nTest_fun10_6" << endl;
	Class10_6 c1;
	Class10_6 c2;
	Class10_6 c3;
	c1 = c2 = c3;
	cout << c1.m_P << "\n" << *c1.m_P << endl;
	cout << c2.m_P << "\n" << *c2.m_P << endl;
	cout << c3.m_P << "\n" << *c3.m_P << endl;
	*c3.m_P = 20;
	c1 = c2 = c3;
	cout << c1.m_P << "\n" << *c1.m_P << endl;
	cout << c2.m_P << "\n" << *c2.m_P << endl;
	cout << c3.m_P << "\n" << *c3.m_P << endl;
}
//==运算符重载 (关系运算符重载)
class Class10_7
{
	int m_A;
	int m_B;
public:
	Class10_7(int a,int b)
	{
		m_A = a;
		m_B = b;
	}
	bool operator==(const Class10_7& other)
	{
		if (m_A == other.m_A && m_B == other.m_B)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
void fun10_7()
{
	cout << "\n\nTest_fun10_7" << endl;
	Class10_7 c1(10, 20);
	Class10_7 c2(20, 20);
	cout << (c1 == c2) << endl;
	c1 = c2;
	cout << (c1 == c2) << endl;
}
//()运算符重载 (函数调用运算符重载)
//由于重载后的使用方式很像函数的调用，因此被称为仿函数
//仿函数没有固定的写法，非常灵活
class Class10_8
{
	string m_Str;
public:
	Class10_8(string str)
	{
		m_Str = str;
	}
	void operator()()
	{
		cout << m_Str << endl;
	}
};
void fun10_8()
{
	cout << "\n\nTest_fun10_8" << endl;
	Class10_8 c1("hello");
	c1();
}

//类相关测试
void TestClass()
{
	//C++面向对象的三大特性:封装、继承、多态
	//C++认为万事万物皆为对象，对象上有其属性和行为
	//一般把具有相同性质的对象，抽象称为类，人属于人这个类，车属于车这个类


	//封装
	//封装的意义
	//将属性和行为作为一个整体，表现生活中的事务
	// 将属性和行为加以权限控制
	//语法： class 类名 { 访问权限： 属性 / 行为 };
	//类中的属性和行为，一般统一称为成员
	//属性  成员属性  成员变量
	//行为  成员函数  成员方法

	//实例化
	/*Circle c1;
	c1.m_r = 5;
	cout << c1.CalculatePerimeter() << endl;

	Student s1;
	s1.readData();
	s1.writeData("张三", 1);
	s1.readData();*/


	//访问权限相关
	//类中的属性和行为可以设置不同的权限，加以控制
	//public	公共权限	成员 类内可以访问 类外可以访问
	//protected	保护权限	成员 类内可以访问 类外不可以访问	//继承时，儿子可以访问其中的成员
	//private	私有权限	成员 类内可以访问 类外不可以访问	//继承时，儿子不可以访问其中的成员

	//Person p1;
	//p1.m_Name = "李四";//公共权限 类外可以访问
	////p1.m_Car = "KIA";//保护权限 类外不可以访问
	////p1.m_Password = 123;//私有权限 类外不可以访问
	//p1.fun2();//公共权限 类外可以访问
	////p1.fun1();//私有权限 类外不可以访问


	//struct 和 class 的区别
	//C++中struct 和 class的唯一区别是默认的访问权限不同
	//struct默认的访问权限为公共 public
	//class默认的访问权限为私有 private

	//C1 c1;
	////c1.m_A = 100;//默认的访问权限为私有 类外不可以访问
	//C2 c2;
	//c2.m_A = 100;
	//c2.fun1();


	//对于class 将所有成员属性设置为私有，有两个好处
	//可以自己控制读写权限
	//对于写权限，可以检测数据的有效性

	/*Preson2 p11;
	p11.setName("张三");
	cout << p11.getName() << endl;
	cout << p11.getAge() << endl;
	p11.setIdol("hanser");
	p11.setGender("男");
	cout << p11.getGender() << endl;
	p11.setGender("1");*/


	//案例一
	/*Cube cube1;
	cube1.setInfo(5, 3, 4);
	Info info = cube1.getInfo();
	cout << cube1.calculateArea() << endl;
	cout << cube1.calculateVolume() << endl;
	info.m_Heigth = 6;
	info.m_Width = 6;
	info.m_Length = 6;
	cout << cube1.calculateArea() << endl;
	cout << cube1.calculateVolume() << endl;
	Cube cube2;
	cube2.setInfo(5, 3, 4);
	Cube cube3;
	cube3.setInfo(6, 6, 6);
	cout << cube1.contrastCube(cube2.getInfo()) << endl;
	cout << cube1.contrastCube(cube3.getInfo()) << endl;
	cout << cube3.calculateArea() << endl;
	cout << cube3.calculateVolume() << endl;
	cout << contrastCube(cube1.getInfo(), cube2.getInfo()) << endl;
	cout << contrastCube(cube2.getInfo(), cube3.getInfo()) << endl;*/


	//案例二
	/*Circle2 circle;
	Point center;
	center.setX(10);
	center.setY(0);
	circle.setR(10);
	circle.setCenter(center);
	Point p111;
	p111.setX(10);
	p111.setY(10);
	isInCircle(circle, p111);*/


	//对象的初始化和清理
	//初始化使用构造函数
	//清理使用析构函数
	//构造函数和析构函数会被编译器自动调用，如果不提供这两个函数，编译器会自己提供
	//只不过编译器提供的这两个函数是空实现
	//构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无需手动调用
	//析构函数：主要作用在于对象销毁前系统自动调用，执行一些清理工作

	//构造函数
	//语法：类名(){}
	// 1、构造函数没有返回值，也不写void
	// 2、函数名称与类名相同
	// 3、构造函数可以有参数，因此可以发生重载
	// 4、程序在实例化对象时会自动调用构造函数，无需手动调用，且只会调用一次
	// 5、构造函数可以使用成员初始化列表
	// 成员初始化列表是在构造函数参数列表之后、函数体之前的部分，用于在进入构造函数体之前对类的数据成员进行初始化
	// 语法：类名(参数) :成员1(初始值),成员2(初始值) {}


	//析构函数
	// 语法：~类名(){}
	// 1、析构函数没有返回值，也不写void
	// 2、函数名称与类名相同，在函数名前加上~符号
	// 3、析构函数不可以有参数，因此不可以发生重载
	// 4、程序在对象销毁前会自动调用析构函数，无需手动调用，且只会调用一次

	//构造函数测试
	//fun();

	// 构造函数的分类及调用
	// 按参数分类：有参构造函数、无参构造函数(默认构造函数)
	// 按功能分类：普通构造函数、拷贝构造函数、移动构造函数、委托构造函数
	// 不同的构造函数主要是调用的时机和作用不同
	// 
	// 无参构造函数(默认构造函数)
	// 语法：类名() :成员初始化列表 {}
	// 如果没有显式定义构造函数，编译器会生成默认构造函数
	// 编译器生成的默认构造函数不会对成员变量进行显式的初始化。对于内置类型（如 int），
	// 它们的初始值是未定义的；对于类类型的成员变量，
	// 编译器会调用这些成员变量的默认构造函数进行初始化。(比如string类会被初始化为空字符串)
	// 
	// 有参构造函数
	// 语法：类名(参数) :成员初始化列表 {}
	// 有参数的构造函数允许在创建对象时传递参数来初始化对象的数据成员。
	// 
	// 拷贝构造函数
	// 语法：类名(const 类名& other) :成员初始化列表 {}		(MyClass(const MyClass& other))
	// 拷贝构造函数用于使用另一个同类型的对象来初始化新对象
	// 主要使用场景：
	// 1、当用一个对象初始化另一个对象时。
	// 2、当对象作为参数传递给函数时（按值传递）。
	// 3、当函数返回一个对象时（按值返回）。
	//
	// 移动构造函数
	// 语法：类名(类名&& other)noexcept :成员初始化列表 {}		(MyClass(MyClass&& other) noexcept)
	// noexcept表示该函数不会抛出异常
	// 移动构造函数用于优化资源管理，特别是在处理动态分配内存时。它的作用是从临时对象“移动”资源，而不是复制资源。
	// 
	// 委托构造函数
	// 语法：类名(参数) :类名() {}		//实际上是在成员初始化列表中调用了同一个类的构造函数？
	// 委托构造函数是在一个构造函数中调用同一个类的其他构造函数，以减少代码重复。
	// 
	// 成员初始化列表
	// 语法：类名(参数) :成员1(初始值),成员2(初始值) {}
	// 构造函数可以通过成员初始化列表来初始化数据成员。成员初始化列表位于构造函数的参数列表之后、函数体之前。
	// 优点：
	// 1、对于常量成员和引用成员，必须在成员初始化列表中初始化。
	// 2、对于类类型的成员，可以在初始化时直接调用其构造函数，避免不必要的默认构造和赋值操作。

	//编译器生成构造函数的规则
	//默认情况下，c++编译器至少给一个类添加4个函数
	// 1、默认构造函数(无参)
	// 2、默认析构函数
	// 3、默认拷贝构造函数，对属性进行值拷贝(浅拷贝)
	// 4、赋值运算符函数operator=，实现对象间赋值操作(浅赋值)
	// 
	// 注意情况
	// 如果用户定义了有参构造函数，编译器不再提供默认的无参构造函数，但是会提供默认的拷贝构造函数
	// 如果用户定义了拷贝构造函数，编译器也不再提供默认的无参构造函数
	//


	////构造函数的分类
	//int a = 10;
	//int* ap = &a;
	//string str = "Test Text";
	////有参构造函数测试
	//Class2 c20(a, ap, str);
	//c20.printMessage();
	////无参构造函数(默认构造函数)
	//Class2 c21;
	//c21.printMessage();
	//*c21.m_Ap = 20;
	//c21.printMessage();
	////拷贝构造函数
	//Class2 c22(c21);
	//c22.printMessage();
	//*c22.m_Ap = 30;//c22的指针浅拷贝拷贝了c21指针的值，没有另外申请内存
	//c21.printMessage();//，然后重新赋值，修改时会修改到c21的值
	//fun1(c22);//函数值传递会调用拷贝构造函
	//fun2();//函数值返回会调用拷贝构造函
	////移动构造函数
	//Class2 c23 = fun3();//返回值优化（RVO）编译器直接在 c23 的内存位置上构造了 Class2 对象，没有调用移动构造函数
	//c23.printMessage();//c23的m_Ap指向的是函数里局部变量的地址，函数后会被编译器释放，所以*m_Ap访问的时候数据会异常
	//Class2 c24;
	//Class2 c25 = std::move(c24);//显式的资源转移，会调用移动构造函数
	//c24.printMessage();
	//c25.printMessage();//当前设置m_Ap指向的地址是值传递，且指向的地址和原c24的m_A的地址一致，原c24资源置空时m_A设为0，所以*m_Ap输出时为0
	////委托构造函数
	//Class2 c26(20);
	//c26.printMessage();

	//构造函数的调用测试
	//1、括号法
	//2、显示法
	//3、隐式转换法

	//int a1 = 10;
	//int* ap1 = &a1;
	//string str1 = "Test Text";
	////括号法
	//Class2 c220;
	//Class2 c221(a1, ap1, str1);
	//Class2 c222(c220);
	////注意事项
	////调用默认构造函数时，不要加()
	//Class2 c223();//会被编译器识别为函数的声明

	////显示法
	//Class2 c224;
	//Class2 c225 = Class2(a1, ap1, str1);
	//Class2 c226 = Class2(c224);
	//Class2(a1, ap1, str1);//实际上是匿名对象  特点：没有变量接收时，在当前行执行结束后，系统会立即回收掉匿名对象
	////注意事项
	////不要利用拷贝构造函数 初始化匿名对象
	////编译器会认为 Class2(c34) === Class2 c34 ，实际上是对象声明
	////Class2(c34);//会报错，提示Class2 c34重定义

	////隐式转换法，只适合有一个参数，或者其他参数有默认值的情况
	//Class2 c227 = 10;//会调用类里面的委托构造函数，该函数只需要一个int 参数
	//Class1 c11 = 10;//等价于 Class1 c11 = Class1(10);
	//Class1 c12 = c11;//等价于 Class1 c11 = Class1(c11);


	//浅拷贝和深拷贝
	// 编译器默认生成的拷贝构造函数，对属性只进行值拷贝，当成员中有指针时，值拷贝会让两个对象的指针指向同一块内存，会导致异常情况
	//如果成员中有在堆区开辟的，一定要自己提供拷贝构造函数，避免导致异常
	//fun30();//浅拷贝 析构函数时会发生内存重复释放
	//fun40();//深拷贝 地址不是同一个，析构函数时不会内存重复释放


	//类对象作为类的成员时，构造和析构的顺序
	//当其他类对象作为本类的成员，构造时，先构造对象，再构造自身，析构时，顺序相反
	//fun50();

	//静态成员
	// 在成员变量或成员函数前加上关键字static，称为静态成员
	// 静态成员是属于类本身而不是类的某个特定对象的成员，这意味着静态成员只有一个副本存在，所有对象共享这个单一的副本
	// 使用场景：计数器、全局设置、工具函数等都是静态成员的典型应用场景。
	// 静态成员函数和静态数据成员在多线程环境下使用时需要注意同步问题
	// 静态成员变量
	// 1、所有对象共享同一份数据
	// 2、在编译阶段分配内存(位于全局区)
	// 3、类内声明，类外初始化 (除了静态常量整型(static const int)成员可以在类内直接初始化)
	// 4、可以设置不同的访问权限
	// 静态成员函数
	// 1、所有对象共享同一个函数
	// 2、静态成员函数只能访问静态成员变量和其他静态成员函数 或 通过传递对象引用来间接访问非静态成员
	// 3、无this指针 静态成员函数没有隐含的this指针，因此不能访问非静态成员（包括数据成员和成员函数），因为这些成员依赖于特定的对象实例。
	// 4、可以设置不同的访问权限
	//访问方式均有两种
	// 通过对象实例访问	对象.静态变量	对象.静态函数
	// 通过类名访问		类名::静态变量	类名::静态函数
	//fun6();


	//C++中，类内的成员变量和成员函数分开存储
	//只有非静态成员变量才属于类的对象上
	//非静态成员函数通过this指针获取调用当前实例对象的非静态成员变量
	//非静态成员函数中都隐式地传入和调用了this指针
	fun7();


	//this指针
	// this指针是隐含在非静态成员函数中的一个指针
	// this指针不需要定义，可以直接使用
	// this指针指向被调用的成员函数所属的对象(谁调用函数，就指向谁)
	// this指针并不是显式存储在类的实例中的，而是由编译器在生成代码时自动处理的
	// this指针本质是一个ClassType* const 的指针常量，指向调用函数的对象
	// this 指针并不占用类实例的内存空间。它是由编译器在调用成员函数时动态传递的
	// 用途：
	// 1、区分局部变量与成员变量
	// 2、返回当前对象(支持链式调用)
	// 3、实现运行时多态(在虚函数的实现中，this 指针用于访问对象的虚函数表（vtable），从而支持动态绑定。)
	fun8();


	//空指针访问成员函数
	fun9();


	//常函数、常对象  主要是用来保证只读性
	// 常函数
	// const修饰成员函数，该函数称为常函数
	// 语法：类型 函数名(参数) const {}      //注：成员初始化列表只在构造函数中使用，常函数不会是构造函数，所以const和初始化列表不会有冲突
	// 常函数内不可以修改非静态成员属性
	// 常函数内可以修改静态成员属性
	// 常函数只能调用其他常函数或静态成员函数，不能调用非 const 成员函数
	// 如果成员属性声明时加了mutable关键字后，在常函数中可以被修改
	// 
	// 常对象
	// 声明对象前加const，该对象称为常对象
	// 常对象只能调用常函数
	// 常对象的所有成员变量都被视为只读，不能通过该对象修改其状态
	fun10_1();



	//友元
	// 友元（friend） 是一种特殊的机制，主要是用于允许某些函数或类访问另一个类的私有（private）和保护（protected）成员
	// 语法：
	//	1、friend 函数声明 friend 返回值 函数名(参数);
	//	2、friend 类声明 friend class 类名;
	// 友元可以是一个函数（称为友元函数），也可以是一个类（称为友元类）。
	// 它被授予访问类的私有和保护成员的权限，而无需通过公共接口。
	// 友元声明必须出现在类的内部，但与类的访问控制无关（即可以放在 public、private 或 protected 中，效果相同）。
	// 友元关系是单向的：如果类 A 声明了类 B 为友元，那么 B 可以访问 A 的私有成员，但 A 不能访问 B 的私有成员。
	// 友元关系不可传递：如果 A 是 B 的友元，B 是 C 的友元，这并不意味着 A 是 C 的友元。
	// 
	// 友元的三种实现
	// 1、全局函数做友元
	// 2、类做友元
	// 3、成员函数做友元
	// 
	// 注意：
	//	普通函数作为友元时，该函数是全局函数，即使该函数的声明和实现都写在类内，该函数也是全局函数
	// 

	fun10_2();


	//运算符重载
	// 运算符重载（Operator Overloading） 是一种强大的特性，它允许程序员为自定义类型（如类或结构体）重新定义内置运算符的行为。
	// 并非所有运算符都可以被重载。例如，.（成员访问）、.*（指针到成员访问）、::（作用域解析）、?:（三元条件）等运算符不能被重载。
	// 重载运算符时，必须至少有一个操作数是用户定义的类型。
	// 两种方式实现运算符重载：
	// 1、将运算符重载为类的成员函数								参数↓
	//	语法：类名(返回值) operator+(重载运算符名称、函数名) (const 类名& other){运算逻辑}  //(左侧操作数是调用该运算符的对象本身)
	//	调用时本质为 对象1.operator+(对象2);
	// 2、将运算符重载为全局函数								参数1,参数2↓(只有一个参数必须是用户定义的类型，另一个可以是内置数据类型)
	//	语法：类名(返回值) operator+(重载运算符名称、函数名) (const 类名& lvalue , const 类名& rvalue){运算逻辑}
	//	调用时本质为 operator+(对象1,对象2);
	//实测两种方式实现运算符重载可以共存？类的成员函数优先被调用？

	fun10_3();
	fun10_4();
	fun10_5();
	fun10_6();
	fun10_7();
	fun10_8();


}

	   



