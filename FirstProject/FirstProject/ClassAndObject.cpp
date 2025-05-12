#include "ClassAndObject.h"
#include "Circle.h"

const double PI = 3.14;

//��װ����
class Circle
{
	//����Ȩ��
public :

	//����
	int m_r;//�뾶

	//��Ϊ
	double CalculatePerimeter()//�����ܳ�
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


//����Ȩ�����
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
		m_Name = "����";
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


//struct �� class ������
class C1 
{
	int m_A;//Ĭ�ϵķ���Ȩ��Ϊ˽��
};
struct C2
{
	int m_A;//Ĭ�ϵķ���Ȩ��Ϊ����
	void fun1()
	{
		cout << m_A << endl;
	}
};


//class��Ա���Զ�д����
class Preson2
{
	string m_Name;//����Ϊ �ɶ���д
	int m_Age = 18;//����Ϊ ֻ��
	string m_Idol;//����Ϊ ֻд
	string m_Gender;//����Ϊ �ɶ���д������д�������

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
		if (gender == "��" || gender == "Ů")
		{
			m_Gender = gender;
		}
		else
		{
			cout << "д�������쳣��д��ʧ��" << endl;
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
	if (squareDir > squareR)//�����ƽ�����ڰ뾶ƽ��
	{
		cout << "����Բ��" << endl;
	}
	else if (squareDir == squareR)//�����ƽ�����ڰ뾶ƽ��
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}


//���캯��������������
class Class1
{
	int m_A;
public:	//��Ҫpublic����Ȩ�޲ſ��������ⴴ�����󣬲�Ȼ�������ᱨ��
		//�����protected����Ȩ�ޣ����������ഴ�����󣬲��������ⴴ������
		//�����private����Ȩ�ޣ��������ⲿ�������ഴ������ͨ�����ڵ���ģʽ������ģʽ
	Class1()
	{
		cout << "���캯������" << endl;
	}
	Class1(int a)
	{
		cout << "�вι��캯������" << endl;
		m_A = a;
	}
	~Class1()
	{
		cout << "������������" << endl;
	}
};
void fun()
{
	Class1 c1;
}

//���캯�����༰���ò���
class Class2
{
public:
	int m_A;
	int* m_Ap;//Aָ��
	string m_Str;
	//const int m_c_A;//���������ڶ��峣����Ա��Ҫ�ڳ�Ա��ʼ���б��н��г�ʼ��		:m_c_A(10), m_y_A(a)
	//int& m_y_A;//���������ڶ������ó�Ա��Ҫ�ڳ�Ա��ʼ���б��н��г�ʼ��		:m_c_A(10), m_y_A(a)
	const int m_c_B = 10;//Ҳ����ֱ�Ӹ���ʼֵ�������޷��ñ�����ֵ�ˣ�ֻ���ǹ̶���ֵ
	int& m_y_B = m_A;//Ҳ����ֱ�Ӹ���ʼֵ�������޷��ñ�����ֵ�ˣ�ֻ���ǹ̶���ֵ

public:
	//�вι��캯��
	Class2(int a,int* ap,string str) //:m_c_A(10), m_y_A(a)
	{
		cout << "�вι��캯��" << endl;
		m_A = a;
		m_Ap = ap;
		m_Str = str;
	}
	//�޲ι��캯��(Ĭ�Ϲ��캯��)
	Class2() :m_A(10), m_Ap(&m_A), m_Str("��Ա��ʼ���б�")//��Ա��ʼ���б�
	{
		cout << "�޲ι��캯��(Ĭ�Ϲ��캯��)" << endl;
		//m_A = 10;
	}
	//�������캯��(ǳ������ֻ����������ֵ���и�ֵ)
	Class2(const Class2& other)
	{
		cout << "�������캯��(ǳ������ֻ����������ֵ���и�ֵ)" << endl;
		m_A = other.m_A;//ͬһ�������������ʵ���������˽�г�Ա�������Ƶ�Ӱ��
		m_Ap = other.m_Ap;
		m_Str = other.m_Str;
	}
	//�ƶ����캯��(����ʱ�����ƶ�����Դ�������Ǹ�����Դ��)//ԭ������Դ���ÿ�
	Class2(Class2&& other) noexcept 
	{
		cout << "�ƶ����캯��(����ʱ�����ƶ�����Դ�������Ǹ�����Դ��)" << endl;
		m_A = other.m_A;
		m_Ap = other.m_Ap;
		m_Str = std::move(other.m_Str);
		other.m_Ap = nullptr;// ��ԭ���������ָ����Ϊ nullptr
		other.m_A = 0;
		other.m_Str = "";
	}
	//ί�й��캯��(��һ�����캯���е���ͬһ������������캯��)
	Class2(int a) :Class2(a, &a, "Default Text")
	{
		cout << "ί�й��캯��(��һ�����캯���е���ͬһ������������캯��)" << endl;
	}

	void printMessage()
	{
		if (!m_Ap) cout << "m_Ap��ָ��" << endl;
		else
		{
			cout << "m_A = " << m_A << "\nm_Ap ��ַ" << m_Ap << "\n*m_Ap ��ֵ" << *m_Ap
				<< "\nm_Str = " << m_Str << endl;
		}
		
	}
};
//�������캯������
void fun1(Class2 c)
{
	cout << "�������캯������,����ֵ���ݸ�����ʱ������ÿ������캯��" << endl;
}
Class2 fun2()
{
	Class2 c;//����Ĭ�Ϲ��캯��
	cout << "�������캯������,����ֵ���ض���ʱ������ÿ������캯��" << endl;
	return c;
}
//�ƶ����캯������
Class2 fun3()
{
	int a;
	return Class2(10,&a,"�ƶ����캯������");
}


//ǳ�������������
class Class3//������Ĭ��ʵ�ֵ�ǳ����
{
	int* m_P;
public:
	Class3(int p )
	{
		m_P = new int(p);
	}
	//û��д��������ʱ����������Ĭ��ʵ�ֵ�ǳ����
	Class3(const Class3& other)
	{
		m_P = other.m_P;
	}
	~Class3()
	{
		if (m_P != nullptr)
		{
			delete m_P;//�����޸�m_Pָ��ĵ�ַ������Ѹ��ڴ���Ϊ�ɷ��䣬�ٴ��ͷŻᱨ��
			m_P = nullptr;//�޸�m_Pָ��ָ��ĵ�ַ����Ҫ�Ǳ��ں��������ж�
		}
	}
	void printMessage()
	{
		if (m_P != nullptr) cout << "��ַ��" << m_P << "\tֵ��" << *m_P << endl;
		else cout << "��ַΪ��" << endl;
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
	//ʵ�����
	Class4(const Class4& other)
	{
		m_P = new int(*other.m_P);
	}
	~Class4()
	{
		if (m_P != nullptr)
		{
			delete m_P;//�����޸�m_Pָ��ĵ�ַ������Ѹ��ڴ���Ϊ�ɷ��䣬�ٴ��ͷŻᱨ��
			m_P = nullptr;//�޸�m_Pָ��ָ��ĵ�ַ����Ҫ�Ǳ��ں��������ж�
		}
	}
	void printMessage()
	{
		if (m_P != nullptr) cout << "��ַ��" << m_P << "\tֵ��" << *m_P << endl;
		else cout << "��ַΪ��" << endl;
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


//�������Ϊ��ĳ�Աʱ�������������˳��
class Class51
{
	string m_MemberClassStr;
public:
	Class51(string str,int a)
	{
		cout << "��Ա��Ĺ��캯��" << endl;
		cout << a << endl;
		m_MemberClassStr = str;
	}
	~Class51()
	{
		cout << "��Ա�����������" << endl;
	}
};
class Class5
{
	string m_ClassStr;
	Class51 m_MemberClass;
public:
	Class5(string classStr,string memberClassStr):m_ClassStr(classStr), m_MemberClass(memberClassStr,10)
	{
		cout << "��Ĺ��캯��" << endl;
	}
	~Class5()
	{
		cout << "�����������" << endl;
	}
};
void fun50()
{
	cout << "\n\nTest_fun50" << endl;
	Class5("Class5", "Class51");
}


//��̬��Ա��ز���
class Class6//������(��¼��ǰ���ж��ٶ���ʵ��)
{
public :
	static int count;//��̬������������
	static const int constValue = 10;

	Class6()//���캯������ʱ����
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
int Class6::count = 0;//�����ʼ��
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


//C++�У����ڵĳ�Ա�����ͳ�Ա�����ֿ��洢
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
	static int m_B;//��̬��Ա���� �������������
public:
	void fun()//�Ǿ�̬��Ա���� �������������
	{
		cout << "here" << endl;
	}
	static void fun2()//��̬��Ա���� �������������
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


//thisָ��
class Class8
{
	int m_A;
public:
	Class8(int a):m_A(a)
	{
	}
	Class8& fun(int a)//��ʽ����ʱҪ��������  �ص������ã����Կ�����ָ�볣��
	{
		this->m_A += a;
		return *this;
	}
	Class8 fun1(int a)//��Ϊ�����ص���ֵ���Ƕ���ĸ�������һ���µĶ�������ֻ�е�һ�ε���ʱ�޸���ֵ����ʽ�����޸ĵ��Ǹ�����ֵ
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
	c1.fun(10).fun(10).fun(10);//Class8& c2 = c1(*this) //c2ʵ�ʾ���c1
	c1.fun2();
	c1.fun1(10).fun1(10).fun1(10);//Class8 c2 = c1(*this)//c2��һ���µĶ���
	c1.fun2();
}


//��ָ����ʳ�Ա����
class Class9
{
public :
	int m_A;
	void fun1()
	{
		cout << "��ָ����ʳ�Ա����" << endl;
	}
	void fun2()
	{
		cout << m_A << endl;//ʵ�ʷ��ʵ���this->m_A
	}
};
void fun9()
{
	cout << "\n\nTest_fun9" << endl;
	Class9 *c1 = nullptr;
	c1->fun1();
	(*c1).fun1();
	//c1->fun2();//���� ��ȡ����Ȩ�޳�ͻ
	//(*c1).fun2();//���� ��ȡ����Ȩ�޳�ͻ
}



//��������������
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
		m_A = 10;//ʵ����this->m_A = 10;
	}
	int fun2() const//ʵ��const���ε���this�� �˴�this �൱�� const Class10_1* const this
	{
		//this = nullptr;//���� this��ֵ�����޸� this��ָ�򲻿��޸�
		//m_A = 20;//���� ��ֵ�����޸�
		m_C = 20;//��̬��Ա���޸�
		m_B = 100;//mutable���εĳ�Ա�������޸�
		return m_A;//�Ǿ�̬��Ա��������Ϊ����ֵ
	}
	void fun3() const//������ֻ�ܵ���������������̬��Ա���������ܵ��÷� const ��Ա����
	{
		fun();
		//fun1();����
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
	//������
	Class10_1 c1;
	c1.fun1();
	c1.fun3();
	//c1.fun2();
	c1.PVal();
	//������
	const Class10_1 c2(30);
	//c2.m_A = 50;//�Ƿ�
	c2.m_B = 500;
	//c2.PVal();//�Ƿ� ,ֻ�ܵ��ó�����
	c2.fun2();
	c2.CPVal();
}


//��Ԫ
class Class10_2;
class Class10_2_2
{
	Class10_2* c1;
public:
	Class10_2_2();//�˴�ֻ����������Ϊ�����ڷ�����Class10_2�еĹ��캯�������캯����ʱ��û�б��������޷�������
	void PVal();
};
class Class10_2
{
	friend void fun10_2_2(Class10_2* class10_2);//��Ԫ����
	friend class Class10_2_1;//��Ԫ����
	friend void Class10_2_2::PVal();//��Ԫ���� (��Ա��������Ԫʱ�����༰���Ա����Ҫ����Ԫ����ǰ����)
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
class Class10_2_1//��Ԫ��
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
	void PVal(const Class10_2& c);//���غ���
};
void Class10_2_1::PVal(const Class10_2& c)//�����ⶨ�庯��
{
	cout << c.m_A << endl;
	cout << c.m_B << endl;
}
void fun10_2_1(Class10_2* class10_2)
{
	//cout << class10_2->m_A << endl;//����
	cout << class10_2->m_B << endl;
}
void fun10_2_2(Class10_2* class10_2)//��Ԫ����
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
	//ȫ�ֺ�������Ԫ
	Class10_2 c1;
	fun10_2_1(&c1);
	fun10_2_2(&c1);
	//������Ԫ
	Class10_2_1 c2;
	c2.PVal();
	c2.PVal(c1);
	//��Ա��������Ԫ
	Class10_2_2 c3;
	c3.PVal();
	
}



//���������
//+��������� (������������)
class Class10_3
{
public:
	int m_A;
	int m_B;
	Class10_3() :m_A(10), m_B(10) {}
	Class10_3(const Class10_3& other)
	{
		cout << "�������캯��������" << endl;
		this->m_A = other.m_A;
		this->m_B = other.m_B;
	}
	Class10_3 operator+(const Class10_3& other)//��Ա����ʵ��
	{
		cout << "��Ա����ʵ�����������" << endl;
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
Class10_3 operator+(const Class10_3& lvalue, const Class10_3& rvalue)//��Ա����ʵ��
{
	cout << "ȫ�ֺ���ʵ�����������" << endl;
	Class10_3 temp;
	temp.m_A = lvalue.m_A + rvalue.m_A;
	temp.m_B = lvalue.m_B + rvalue.m_B;
	return temp;
}
Class10_3_1 operator+(const Class10_3_1& lvalue, const Class10_3_1& rvalue)//ȫ�ֺ���ʵ��
{
	cout << "ȫ�ֺ���ʵ�����������" << endl;
	Class10_3_1 temp;
	temp.m_A = lvalue.m_A + rvalue.m_A;
	temp.m_B = lvalue.m_B + rvalue.m_B;
	return temp;
}
Class10_3_1 operator+(int num, const Class10_3_1& rvalue)//ȫ�ֺ���ʵ��
{
	cout << "ȫ�ֺ���ʵ�����������" << endl;
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
	Class10_3 c3 = c1 + c2;//���ܷ���ֵ�Ż���RVO���ˣ�û����� �������캯��������
	//Class10_3 c3 = c1.operator+(c2);//(����)
	//Class10_3 c4 = c1;
	c3.PVal();

	Class10_3_1 c11;
	Class10_3_1 c12;
	Class10_3_1 c13 = c11 + c12;
	//Class10_3_1 c13 = operator+(c11, c12);//(����)
	c13.PVal();

	Class10_3_1 c21;
	Class10_3_1 c22 = 100 + c21;
	c22.PVal();
}
//<<��������� (�������������)
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
//++��������� (�������������)
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
//=��������� (��ֵ���������)
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
		if (this == &other)//�Ը�ֵ���
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
//==��������� (��ϵ���������)
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
//()��������� (�����������������)
//�������غ��ʹ�÷�ʽ�������ĵ��ã���˱���Ϊ�º���
//�º���û�й̶���д�����ǳ����
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

//����ز���
void TestClass()
{
	//C++����������������:��װ���̳С���̬
	//C++��Ϊ���������Ϊ���󣬶������������Ժ���Ϊ
	//һ��Ѿ�����ͬ���ʵĶ��󣬳����Ϊ�࣬������������࣬�����ڳ������


	//��װ
	//��װ������
	//�����Ժ���Ϊ��Ϊһ�����壬���������е�����
	// �����Ժ���Ϊ����Ȩ�޿���
	//�﷨�� class ���� { ����Ȩ�ޣ� ���� / ��Ϊ };
	//���е����Ժ���Ϊ��һ��ͳһ��Ϊ��Ա
	//����  ��Ա����  ��Ա����
	//��Ϊ  ��Ա����  ��Ա����

	//ʵ����
	/*Circle c1;
	c1.m_r = 5;
	cout << c1.CalculatePerimeter() << endl;

	Student s1;
	s1.readData();
	s1.writeData("����", 1);
	s1.readData();*/


	//����Ȩ�����
	//���е����Ժ���Ϊ�������ò�ͬ��Ȩ�ޣ����Կ���
	//public	����Ȩ��	��Ա ���ڿ��Է��� ������Է���
	//protected	����Ȩ��	��Ա ���ڿ��Է��� ���ⲻ���Է���	//�̳�ʱ�����ӿ��Է������еĳ�Ա
	//private	˽��Ȩ��	��Ա ���ڿ��Է��� ���ⲻ���Է���	//�̳�ʱ�����Ӳ����Է������еĳ�Ա

	//Person p1;
	//p1.m_Name = "����";//����Ȩ�� ������Է���
	////p1.m_Car = "KIA";//����Ȩ�� ���ⲻ���Է���
	////p1.m_Password = 123;//˽��Ȩ�� ���ⲻ���Է���
	//p1.fun2();//����Ȩ�� ������Է���
	////p1.fun1();//˽��Ȩ�� ���ⲻ���Է���


	//struct �� class ������
	//C++��struct �� class��Ψһ������Ĭ�ϵķ���Ȩ�޲�ͬ
	//structĬ�ϵķ���Ȩ��Ϊ���� public
	//classĬ�ϵķ���Ȩ��Ϊ˽�� private

	//C1 c1;
	////c1.m_A = 100;//Ĭ�ϵķ���Ȩ��Ϊ˽�� ���ⲻ���Է���
	//C2 c2;
	//c2.m_A = 100;
	//c2.fun1();


	//����class �����г�Ա��������Ϊ˽�У��������ô�
	//�����Լ����ƶ�дȨ��
	//����дȨ�ޣ����Լ�����ݵ���Ч��

	/*Preson2 p11;
	p11.setName("����");
	cout << p11.getName() << endl;
	cout << p11.getAge() << endl;
	p11.setIdol("hanser");
	p11.setGender("��");
	cout << p11.getGender() << endl;
	p11.setGender("1");*/


	//����һ
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


	//������
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


	//����ĳ�ʼ��������
	//��ʼ��ʹ�ù��캯��
	//����ʹ����������
	//���캯�������������ᱻ�������Զ����ã�������ṩ���������������������Լ��ṩ
	//ֻ�����������ṩ�������������ǿ�ʵ��
	//���캯������Ҫ�������ڴ�������ʱΪ����ĳ�Ա���Ը�ֵ�����캯���ɱ������Զ����ã������ֶ�����
	//������������Ҫ�������ڶ�������ǰϵͳ�Զ����ã�ִ��һЩ������

	//���캯��
	//�﷨������(){}
	// 1�����캯��û�з���ֵ��Ҳ��дvoid
	// 2������������������ͬ
	// 3�����캯�������в�������˿��Է�������
	// 4��������ʵ��������ʱ���Զ����ù��캯���������ֶ����ã���ֻ�����һ��
	// 5�����캯������ʹ�ó�Ա��ʼ���б�
	// ��Ա��ʼ���б����ڹ��캯�������б�֮�󡢺�����֮ǰ�Ĳ��֣������ڽ��빹�캯����֮ǰ��������ݳ�Ա���г�ʼ��
	// �﷨������(����) :��Ա1(��ʼֵ),��Ա2(��ʼֵ) {}


	//��������
	// �﷨��~����(){}
	// 1����������û�з���ֵ��Ҳ��дvoid
	// 2������������������ͬ���ں�����ǰ����~����
	// 3�����������������в�������˲����Է�������
	// 4�������ڶ�������ǰ���Զ��������������������ֶ����ã���ֻ�����һ��

	//���캯������
	//fun();

	// ���캯���ķ��༰����
	// ���������ࣺ�вι��캯�����޲ι��캯��(Ĭ�Ϲ��캯��)
	// �����ܷ��ࣺ��ͨ���캯�����������캯�����ƶ����캯����ί�й��캯��
	// ��ͬ�Ĺ��캯����Ҫ�ǵ��õ�ʱ�������ò�ͬ
	// 
	// �޲ι��캯��(Ĭ�Ϲ��캯��)
	// �﷨������() :��Ա��ʼ���б� {}
	// ���û����ʽ���幹�캯����������������Ĭ�Ϲ��캯��
	// ���������ɵ�Ĭ�Ϲ��캯������Գ�Ա����������ʽ�ĳ�ʼ���������������ͣ��� int����
	// ���ǵĳ�ʼֵ��δ����ģ����������͵ĳ�Ա������
	// �������������Щ��Ա������Ĭ�Ϲ��캯�����г�ʼ����(����string��ᱻ��ʼ��Ϊ���ַ���)
	// 
	// �вι��캯��
	// �﷨������(����) :��Ա��ʼ���б� {}
	// �в����Ĺ��캯�������ڴ�������ʱ���ݲ�������ʼ����������ݳ�Ա��
	// 
	// �������캯��
	// �﷨������(const ����& other) :��Ա��ʼ���б� {}		(MyClass(const MyClass& other))
	// �������캯������ʹ����һ��ͬ���͵Ķ�������ʼ���¶���
	// ��Ҫʹ�ó�����
	// 1������һ�������ʼ����һ������ʱ��
	// 2����������Ϊ�������ݸ�����ʱ����ֵ���ݣ���
	// 3������������һ������ʱ����ֵ���أ���
	//
	// �ƶ����캯��
	// �﷨������(����&& other)noexcept :��Ա��ʼ���б� {}		(MyClass(MyClass&& other) noexcept)
	// noexcept��ʾ�ú��������׳��쳣
	// �ƶ����캯�������Ż���Դ�����ر����ڴ���̬�����ڴ�ʱ�����������Ǵ���ʱ�����ƶ�����Դ�������Ǹ�����Դ��
	// 
	// ί�й��캯��
	// �﷨������(����) :����() {}		//ʵ�������ڳ�Ա��ʼ���б��е�����ͬһ����Ĺ��캯����
	// ί�й��캯������һ�����캯���е���ͬһ������������캯�����Լ��ٴ����ظ���
	// 
	// ��Ա��ʼ���б�
	// �﷨������(����) :��Ա1(��ʼֵ),��Ա2(��ʼֵ) {}
	// ���캯������ͨ����Ա��ʼ���б�����ʼ�����ݳ�Ա����Ա��ʼ���б�λ�ڹ��캯���Ĳ����б�֮�󡢺�����֮ǰ��
	// �ŵ㣺
	// 1�����ڳ�����Ա�����ó�Ա�������ڳ�Ա��ʼ���б��г�ʼ����
	// 2�����������͵ĳ�Ա�������ڳ�ʼ��ʱֱ�ӵ����乹�캯�������ⲻ��Ҫ��Ĭ�Ϲ���͸�ֵ������

	//���������ɹ��캯���Ĺ���
	//Ĭ������£�c++���������ٸ�һ�������4������
	// 1��Ĭ�Ϲ��캯��(�޲�)
	// 2��Ĭ����������
	// 3��Ĭ�Ͽ������캯���������Խ���ֵ����(ǳ����)
	// 4����ֵ���������operator=��ʵ�ֶ���丳ֵ����(ǳ��ֵ)
	// 
	// ע�����
	// ����û��������вι��캯���������������ṩĬ�ϵ��޲ι��캯�������ǻ��ṩĬ�ϵĿ������캯��
	// ����û������˿������캯����������Ҳ�����ṩĬ�ϵ��޲ι��캯��
	//


	////���캯���ķ���
	//int a = 10;
	//int* ap = &a;
	//string str = "Test Text";
	////�вι��캯������
	//Class2 c20(a, ap, str);
	//c20.printMessage();
	////�޲ι��캯��(Ĭ�Ϲ��캯��)
	//Class2 c21;
	//c21.printMessage();
	//*c21.m_Ap = 20;
	//c21.printMessage();
	////�������캯��
	//Class2 c22(c21);
	//c22.printMessage();
	//*c22.m_Ap = 30;//c22��ָ��ǳ����������c21ָ���ֵ��û�����������ڴ�
	//c21.printMessage();//��Ȼ�����¸�ֵ���޸�ʱ���޸ĵ�c21��ֵ
	//fun1(c22);//����ֵ���ݻ���ÿ������캯
	//fun2();//����ֵ���ػ���ÿ������캯
	////�ƶ����캯��
	//Class2 c23 = fun3();//����ֵ�Ż���RVO��������ֱ���� c23 ���ڴ�λ���Ϲ����� Class2 ����û�е����ƶ����캯��
	//c23.printMessage();//c23��m_Apָ����Ǻ�����ֲ������ĵ�ַ��������ᱻ�������ͷţ�����*m_Ap���ʵ�ʱ�����ݻ��쳣
	//Class2 c24;
	//Class2 c25 = std::move(c24);//��ʽ����Դת�ƣ�������ƶ����캯��
	//c24.printMessage();
	//c25.printMessage();//��ǰ����m_Apָ��ĵ�ַ��ֵ���ݣ���ָ��ĵ�ַ��ԭc24��m_A�ĵ�ַһ�£�ԭc24��Դ�ÿ�ʱm_A��Ϊ0������*m_Ap���ʱΪ0
	////ί�й��캯��
	//Class2 c26(20);
	//c26.printMessage();

	//���캯���ĵ��ò���
	//1�����ŷ�
	//2����ʾ��
	//3����ʽת����

	//int a1 = 10;
	//int* ap1 = &a1;
	//string str1 = "Test Text";
	////���ŷ�
	//Class2 c220;
	//Class2 c221(a1, ap1, str1);
	//Class2 c222(c220);
	////ע������
	////����Ĭ�Ϲ��캯��ʱ����Ҫ��()
	//Class2 c223();//�ᱻ������ʶ��Ϊ����������

	////��ʾ��
	//Class2 c224;
	//Class2 c225 = Class2(a1, ap1, str1);
	//Class2 c226 = Class2(c224);
	//Class2(a1, ap1, str1);//ʵ��������������  �ص㣺û�б�������ʱ���ڵ�ǰ��ִ�н�����ϵͳ���������յ���������
	////ע������
	////��Ҫ���ÿ������캯�� ��ʼ����������
	////����������Ϊ Class2(c34) === Class2 c34 ��ʵ�����Ƕ�������
	////Class2(c34);//�ᱨ����ʾClass2 c34�ض���

	////��ʽת������ֻ�ʺ���һ����������������������Ĭ��ֵ�����
	//Class2 c227 = 10;//������������ί�й��캯�����ú���ֻ��Ҫһ��int ����
	//Class1 c11 = 10;//�ȼ��� Class1 c11 = Class1(10);
	//Class1 c12 = c11;//�ȼ��� Class1 c11 = Class1(c11);


	//ǳ���������
	// ������Ĭ�����ɵĿ������캯����������ֻ����ֵ����������Ա����ָ��ʱ��ֵ�����������������ָ��ָ��ͬһ���ڴ棬�ᵼ���쳣���
	//�����Ա�����ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯�������⵼���쳣
	//fun30();//ǳ���� ��������ʱ�ᷢ���ڴ��ظ��ͷ�
	//fun40();//��� ��ַ����ͬһ������������ʱ�����ڴ��ظ��ͷ�


	//�������Ϊ��ĳ�Աʱ�������������˳��
	//�������������Ϊ����ĳ�Ա������ʱ���ȹ�������ٹ�����������ʱ��˳���෴
	//fun50();

	//��̬��Ա
	// �ڳ�Ա�������Ա����ǰ���Ϲؼ���static����Ϊ��̬��Ա
	// ��̬��Ա�������౾����������ĳ���ض�����ĳ�Ա������ζ�ž�̬��Աֻ��һ���������ڣ����ж����������һ�ĸ���
	// ʹ�ó�������������ȫ�����á����ߺ����ȶ��Ǿ�̬��Ա�ĵ���Ӧ�ó�����
	// ��̬��Ա�����;�̬���ݳ�Ա�ڶ��̻߳�����ʹ��ʱ��Ҫע��ͬ������
	// ��̬��Ա����
	// 1�����ж�����ͬһ������
	// 2���ڱ���׶η����ڴ�(λ��ȫ����)
	// 3�����������������ʼ�� (���˾�̬��������(static const int)��Ա����������ֱ�ӳ�ʼ��)
	// 4���������ò�ͬ�ķ���Ȩ��
	// ��̬��Ա����
	// 1�����ж�����ͬһ������
	// 2����̬��Ա����ֻ�ܷ��ʾ�̬��Ա������������̬��Ա���� �� ͨ�����ݶ�����������ӷ��ʷǾ�̬��Ա
	// 3����thisָ�� ��̬��Ա����û��������thisָ�룬��˲��ܷ��ʷǾ�̬��Ա���������ݳ�Ա�ͳ�Ա����������Ϊ��Щ��Ա�������ض��Ķ���ʵ����
	// 4���������ò�ͬ�ķ���Ȩ��
	//���ʷ�ʽ��������
	// ͨ������ʵ������	����.��̬����	����.��̬����
	// ͨ����������		����::��̬����	����::��̬����
	//fun6();


	//C++�У����ڵĳ�Ա�����ͳ�Ա�����ֿ��洢
	//ֻ�зǾ�̬��Ա������������Ķ�����
	//�Ǿ�̬��Ա����ͨ��thisָ���ȡ���õ�ǰʵ������ķǾ�̬��Ա����
	//�Ǿ�̬��Ա�����ж���ʽ�ش���͵�����thisָ��
	fun7();


	//thisָ��
	// thisָ���������ڷǾ�̬��Ա�����е�һ��ָ��
	// thisָ�벻��Ҫ���壬����ֱ��ʹ��
	// thisָ��ָ�򱻵��õĳ�Ա���������Ķ���(˭���ú�������ָ��˭)
	// thisָ�벢������ʽ�洢�����ʵ���еģ������ɱ����������ɴ���ʱ�Զ������
	// thisָ�뱾����һ��ClassType* const ��ָ�볣����ָ����ú����Ķ���
	// this ָ�벢��ռ����ʵ�����ڴ�ռ䡣�����ɱ������ڵ��ó�Ա����ʱ��̬���ݵ�
	// ��;��
	// 1�����־ֲ��������Ա����
	// 2�����ص�ǰ����(֧����ʽ����)
	// 3��ʵ������ʱ��̬(���麯����ʵ���У�this ָ�����ڷ��ʶ�����麯����vtable�����Ӷ�֧�ֶ�̬�󶨡�)
	fun8();


	//��ָ����ʳ�Ա����
	fun9();


	//��������������  ��Ҫ��������ֻ֤����
	// ������
	// const���γ�Ա�������ú�����Ϊ������
	// �﷨������ ������(����) const {}      //ע����Ա��ʼ���б�ֻ�ڹ��캯����ʹ�ã������������ǹ��캯��������const�ͳ�ʼ���б����г�ͻ
	// �������ڲ������޸ķǾ�̬��Ա����
	// �������ڿ����޸ľ�̬��Ա����
	// ������ֻ�ܵ���������������̬��Ա���������ܵ��÷� const ��Ա����
	// �����Ա��������ʱ����mutable�ؼ��ֺ��ڳ������п��Ա��޸�
	// 
	// ������
	// ��������ǰ��const���ö����Ϊ������
	// ������ֻ�ܵ��ó�����
	// ����������г�Ա����������Ϊֻ��������ͨ���ö����޸���״̬
	fun10_1();



	//��Ԫ
	// ��Ԫ��friend�� ��һ������Ļ��ƣ���Ҫ����������ĳЩ�������������һ�����˽�У�private���ͱ�����protected����Ա
	// �﷨��
	//	1��friend �������� friend ����ֵ ������(����);
	//	2��friend ������ friend class ����;
	// ��Ԫ������һ����������Ϊ��Ԫ��������Ҳ������һ���ࣨ��Ϊ��Ԫ�ࣩ��
	// ��������������˽�кͱ�����Ա��Ȩ�ޣ�������ͨ�������ӿڡ�
	// ��Ԫ�����������������ڲ���������ķ��ʿ����޹أ������Է��� public��private �� protected �У�Ч����ͬ����
	// ��Ԫ��ϵ�ǵ���ģ������ A �������� B Ϊ��Ԫ����ô B ���Է��� A ��˽�г�Ա���� A ���ܷ��� B ��˽�г�Ա��
	// ��Ԫ��ϵ���ɴ��ݣ���� A �� B ����Ԫ��B �� C ����Ԫ���Ⲣ����ζ�� A �� C ����Ԫ��
	// 
	// ��Ԫ������ʵ��
	// 1��ȫ�ֺ�������Ԫ
	// 2��������Ԫ
	// 3����Ա��������Ԫ
	// 
	// ע�⣺
	//	��ͨ������Ϊ��Ԫʱ���ú�����ȫ�ֺ�������ʹ�ú�����������ʵ�ֶ�д�����ڣ��ú���Ҳ��ȫ�ֺ���
	// 

	fun10_2();


	//���������
	// ��������أ�Operator Overloading�� ��һ��ǿ������ԣ����������ԱΪ�Զ������ͣ������ṹ�壩���¶����������������Ϊ��
	// ������������������Ա����ء����磬.����Ա���ʣ���.*��ָ�뵽��Ա���ʣ���::���������������?:����Ԫ����������������ܱ����ء�
	// ���������ʱ������������һ�����������û���������͡�
	// ���ַ�ʽʵ����������أ�
	// 1�������������Ϊ��ĳ�Ա����								������
	//	�﷨������(����ֵ) operator+(������������ơ�������) (const ����& other){�����߼�}  //(���������ǵ��ø�������Ķ�����)
	//	����ʱ����Ϊ ����1.operator+(����2);
	// 2�������������Ϊȫ�ֺ���								����1,����2��(ֻ��һ�������������û���������ͣ���һ��������������������)
	//	�﷨������(����ֵ) operator+(������������ơ�������) (const ����& lvalue , const ����& rvalue){�����߼�}
	//	����ʱ����Ϊ operator+(����1,����2);
	//ʵ�����ַ�ʽʵ����������ؿ��Թ��棿��ĳ�Ա�������ȱ����ã�

	fun10_3();
	fun10_4();
	fun10_5();
	fun10_6();
	fun10_7();
	fun10_8();


}

	   



