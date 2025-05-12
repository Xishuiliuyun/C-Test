#include "InheritTest.h"

namespace {

	//�̳з�ʽ����
	class BaseClass20
	{
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_C = 100;
	public:
		void PVal()
		{
			cout << "m_A = \t" << m_A << endl;
			cout << "m_B = \t" << m_B << endl;
			cout << "m_C = \t" << m_C << endl;
			cout << "&m_A = \t" << &m_A << endl;
			cout << "&m_B = \t" << &m_B << endl;
			cout << "&m_C = \t" << &m_C << endl;
			cout << endl;
		}
	};
	class Class20 :public BaseClass20
	{
	public:
		void fun()
		{
			m_A = 100;//�̳к�ά��ԭ����Ȩ��
			m_B = 100;//�̳к�ά��ԭ����Ȩ��
			//m_C = 100;//˽��Ȩ��private�������޷�����
			PVal();
		}
	};
	class Class20_1 :protected BaseClass20
	{
	public:
		void fun()
		{
			m_A = 200;//�̳к�����Ϊ����Ȩ��protected
			m_B = 200;//�̳к�����Ϊ����Ȩ��protected
			//m_C = 200;//˽��Ȩ��private�������޷�����
			PVal();
		}
	};
	class Class20_2 :private BaseClass20
	{
	public:
		void fun()
		{
			m_A = 300;//�̳к�����Ϊ˽��Ȩ��private
			m_B = 300;//�̳к�����Ϊ˽��Ȩ��private
			//m_C = 300;//˽��Ȩ��private�������޷�����
			PVal();
		}
	};
	class Class20_3 :public Class20_2
	{
	public:
		void fun()
		{
			//m_A = 400;//˽��Ȩ��private�������޷�����
			//m_B = 400;//˽��Ȩ��private�������޷�����
			//m_C = 400;//˽��Ȩ��private�������޷�����
			//PVal();//˽��Ȩ��private�������޷�����
		}
	};
	void fun20()
	{
		cout << "\n\nTest_fun20" << endl;
		Class20 c1;
		c1.m_A = 110;
		//c1.m_B = 110;//protectedȨ�ޣ������޷�����
		//c1.m_C = 110;//�޷�����

		Class20_1 c2;
		//c2.m_A = 220;//protectedȨ�ޣ������޷�����
		//c2.m_B = 220;//protectedȨ�ޣ������޷�����
		//c2.m_C = 220;//�޷�����

		Class20_2 c3;
		//c3.m_A = 330;//˽��Ȩ��private�������޷�����
		//c3.m_B = 330;//˽��Ȩ��private�������޷�����
		//c3.m_C = 330;//�޷�����

		Class20_3 c4;
		//c4.m_A = 440;//�޷�����
		//c4.m_B = 440;//�޷�����
		//c4.m_C = 440;//�޷�����
		c1.PVal();
		//c2.PVal();//protectedȨ�ޣ������޷�����
		//c3.PVal();//˽��Ȩ��private�������޷�����
		//c4.PVal();//�޷�����

		c1.fun();
		c2.fun();
		c3.fun();
		c4.fun();

	}

	// �̳��й����������˳��
	class BaseClass21
	{
	public:
		BaseClass21()
		{
			cout << "���๹��" << endl;
		}
		~BaseClass21()
		{
			cout << "��������" << endl;
		}
	};
	class Class21 :public BaseClass21
	{
	public:
		Class21()
		{
			cout << "���๹��" << endl;
		}
		~Class21()
		{
			cout << "��������" << endl;
		}
	};
	void fun21()
	{
		cout << "\n\nTest_fun21" << endl;
		Class21 c1;
	}


	//�̳���ͬ����Ա�Ĵ���ʽ
	class BaseClass22
	{
	public:
		int m_A;
		static int m_B;
		BaseClass22()
		{
			m_A = 100;
		}
		void fun()
		{
			cout << "BaseClass22" << endl;
		}
		void fun(int a)
		{
			cout << "BaseClass22_fun(int a)" << endl;
		}
		static void fun1()
		{
			cout << "BaseClass22 static void fun1()" << endl;
		}
		static void fun1(int a)
		{
			cout << "BaseClass22 static void fun1(int a)" << endl;
		}
	};
	int BaseClass22::m_B = 100;
	class Class22:public BaseClass22
	{
	public:
		int m_A;
		static int m_B;
		Class22()
		{
			m_A = 200;
		}
		void fun()
		{
			cout << "Class22" << endl;
		}
		static void fun1()
		{
			cout << "Class22 static void fun1()" << endl;
		}
	};
	int Class22::m_B = 200;
	void fun22()
	{
		cout << "\n\nTest_fun22" << endl;
		//���ʳ�Ա����
		Class22 c1;
		cout << c1.m_A << endl;
		cout << c1.BaseClass22::m_A << endl;

		//���ʳ�Ա����
		c1.fun();
		c1.BaseClass22::fun();
		//c1.fun(100);//������������ͬ����Ա����ʱ�������ظ��������е�ͬ����Ա����
		c1.BaseClass22::fun(100);

		//���ʾ�̬��Ա����
		cout << "Class22_static int m_B = \t" << c1.m_B << endl;//����ʵ������
		cout << "BaseClass22_static int m_B = \t" << c1.BaseClass22::m_B << endl;//����ʵ������
		cout << "Class22_static int m_B = \t" << Class22::m_B << endl;//��������
		cout << "BaseClass22_static int m_B = \t" << Class22::BaseClass22::m_B << endl;//��������

		//���ʾ�̬��Ա����
		c1.fun1();
		c1.BaseClass22::fun1();
		Class22::fun1();
		Class22::BaseClass22::fun1();
		//c1.fun1(100);//������������ͬ����Ա����ʱ�������ظ��������е�ͬ����Ա����
		//Class22::fun1(100);//������������ͬ����Ա����ʱ�������ظ��������е�ͬ����Ա����
		c1.BaseClass22::fun1(100);
		Class22::BaseClass22::fun1(100);
	}


	//��̳�
	class BaseClass23
	{
	public:
		int m_A;
		BaseClass23()
		{
			cout << "BaseClass23���캯��" << endl;
			m_A = 100;
		}
		~BaseClass23()
		{
			cout << "BaseClass23��������" << endl;
		}
	};
	class BaseClass23_1
	{
	public:
		int m_A;
		BaseClass23_1()
		{
			cout << "BaseClass23_1���캯��" << endl;
			m_A = 200;
		}
		~BaseClass23_1()
		{
			cout << "BaseClass23_1��������" << endl;
		}
	};
	class Class23:public BaseClass23,public BaseClass23_1
	{
	public:
		int m_A;
		Class23()
		{
			cout << "Class23���캯��" << endl;
			m_A = 300;
		}
		~Class23()
		{
			cout << "Class23��������" << endl;
		}
	};

	void fun23()
	{
		cout << "\n\nTest_fun23" << endl;
		Class23 c1;
		cout << c1.m_A << endl;
		cout << c1.BaseClass23::m_A << endl;
		cout << c1.BaseClass23_1::m_A << endl;
	}


	//��̳�
	class BaseClass24
	{
	public :
		int m_A;
		BaseClass24(int a) :m_A(a) {
			cout << "BaseClass24���캯��" << endl;
		}
		~BaseClass24()
		{
			cout << "BaseClass24��������" << endl;
		}
	};
	class BaseClass24_1 :public BaseClass24//��ͨ�̳�
	{
	public:
		BaseClass24_1(int a):BaseClass24(a)
		{
			cout << "BaseClass24_1���캯��" << endl;
		}
		~BaseClass24_1()
		{
			cout << "BaseClass24_1��������" << endl;
		}
	};
	class BaseClass24_2 :public BaseClass24//��ͨ�̳�
	{
	public:
		BaseClass24_2(int a) :BaseClass24(a)
		{
			cout << "BaseClass24_2���캯��" << endl;
		}
		~BaseClass24_2()
		{
			cout << "BaseClass24_2��������" << endl;
		}
	};
	class Class24:public BaseClass24_1,public BaseClass24_2
	{
	public:
		Class24(int a):BaseClass24_1(a), BaseClass24_2(a)
		{
			cout << "Class24���캯��" << endl;
		}
		~Class24()
		{
			cout << "Class24��������" << endl;
		}
	};

	class BaseClass24_3 :virtual public BaseClass24//��̳�
	{
	public:
		BaseClass24_3(int a) :BaseClass24(a)
		{
			cout << "BaseClass24_3���캯��" << endl;
		}
		~BaseClass24_3()
		{
			cout << "BaseClass24_3��������" << endl;
		}
	};
	class BaseClass24_4 :virtual public BaseClass24//��̳�
	{
	public:
		BaseClass24_4(int a) :BaseClass24(a)
		{
			cout << "BaseClass24_4���캯��" << endl;
		}
		~BaseClass24_4()
		{
			cout << "BaseClass24_4��������" << endl;
		}
	};
	class Class24_1 :public BaseClass24_3, public BaseClass24_4
	{
	public:
		Class24_1(int a) :BaseClass24(a), BaseClass24_3(a), BaseClass24_4(a)//�����Ĺ��캯���������յ�������ֱ�ӵ���
		{
			cout << "Class24_1���캯��" << endl;
		}
		~Class24_1()
		{
			cout << "Class24_1��������" << endl;
		}
	};

	void fun24()
	{
		cout << "\n\nTest_fun24" << endl;
		Class24 c1(10);
		//c1.m_A;//���� ���壬�޷�ȷ��Ҫ�����ĸ�m_A
		cout << "\n" << c1.BaseClass24::m_A << endl;
		cout << c1.BaseClass24_1::m_A << endl;
		cout << c1.BaseClass24_2::m_A << endl;
		cout << &c1.BaseClass24::m_A << endl;
		cout << &c1.BaseClass24_1::m_A << endl;
		cout << &c1.BaseClass24_2::m_A << endl;
		cout << "sizeof Class24 = \t" << sizeof(Class24) << endl;
		cout << endl;

		Class24_1 c2(20);
		cout << endl;
		cout << c2.m_A << endl;
		cout<< c2.BaseClass24::m_A << endl;
		cout << c2.BaseClass24_3::m_A << endl;
		cout << c2.BaseClass24_4::m_A << endl;
		cout << &c2.m_A << endl;
		cout << &c2.BaseClass24::m_A << endl;
		cout << &c2.BaseClass24_3::m_A << endl;
		cout << &c2.BaseClass24_4::m_A << endl;
		cout << "sizeof Class24_1 = \t" << sizeof(Class24_1) << endl;
		cout << endl;

		cout << "sizeof BaseClass24_3 = \t" << sizeof(BaseClass24_3) << endl;
		cout << "sizeof BaseClass24_1 = \t" << sizeof(BaseClass24_1) << endl;
		cout << endl;

	}

	//��̳���������
	class Class25
	{
	public:
		int m_A;
		int m_B;
		Class25(int a) :m_A(a) {}
	};
	class Class25_1:public Class25
	{ 
	public:
		Class25_1(int a):Class25(a) {}
	};
	class Class25_2:virtual public Class25
	{ 
	public:
		Class25_2(int a) :Class25(a) {}
	};
	class Class25_3 :public Class25_2
	{
	public:
		Class25_3(int a):Class25(a), Class25_2(a){}
	};
	void fun25()
	{
		cout << "\n\nTest_fun25" << endl;
		cout << "sizeof Class25_1 " << sizeof(Class25_1) << endl;//4--int4
		cout << "sizeof Class25_2 " << sizeof(Class25_2) << endl;//16 -- ָ��8+int4�����ڴ���룬�����Ϊ16
		cout << "sizeof Class25_2::m_A " << sizeof(Class25_2::m_A) << endl;//4--int4
		cout << endl;

		Class25_2 c1(10);
		cout << c1.m_A << endl;
		cout << c1.Class25_2::m_A << endl;
		cout << c1.Class25::m_A << endl;
		cout << &c1.m_A << endl;
		cout << &c1.Class25_2::m_A << endl;
		cout << &c1.Class25::m_A << endl;
		cout << endl;

		Class25_1 c2(20);
		cout << c2.m_A << endl;
		cout << c2.Class25_1::m_A << endl;
		cout << c2.Class25::m_A << endl;
		cout << &c2.m_A << endl;
		cout << &c2.Class25_1::m_A << endl;
		cout << &c2.Class25::m_A << endl;
		cout << endl;

		Class25_3 c3(30);
		cout << c3.m_A << endl;
		cout << c3.Class25_2::m_A << endl;
		cout << c3.Class25::m_A << endl;
		cout << &c3.m_A << endl;
		cout << &c3.Class25_2::m_A << endl;
		cout << &c3.Class25::m_A << endl;
		cout << endl;

	}
}

//�̳���ز���
void testInherit()
{
	//�������ʱ�������һ����Ա����ӵ����һ���Ĺ��ԣ������Լ������ԣ����Կ���ʹ�ü̳У����Լ��ٴ����ظ�
	// �﷨��class �������� : �̳з�ʽ(public��protected��private) ��������
	// ����Ҳ��Ϊ����
	// ����Ҳ��Ϊ������
	// 
	// �̳з�ʽ���
	// 1�������̳�public
	//	��̳и��������з���Ȩ���µ�����
	//	ԭ���ķ���Ȩ���������в��ᷢ���ı�
	//	�޷�����Ȩ��Ϊ˽��Ȩ��private������
	// 2�������̳�protected
	//	��̳и��������з���Ȩ���µ�����
	// 	ԭ���ķ���Ȩ����������ȫ������Ϊ����Ȩ��protected
	//	�޷�����Ȩ��Ϊ˽��Ȩ��private������
	// 3��˽�м̳�private
	//	��̳и��������з���Ȩ���µ�����
	// 	ԭ���ķ���Ȩ����������ȫ������Ϊ˽��Ȩ��private
	// 	�޷�����Ȩ��Ϊ˽��Ȩ��private������
	// �����������Ȼ��̳и����е��������ݣ�������privateȨ�����޷����ʵ�����
	// 
	// ���ʡ�Լ̳з�ʽ�������ࣨclass����Ĭ���� private �̳У�
	// ���ڽṹ�壨struct����Ĭ���� public �̳С�
	// 

	fun20();



	// �̳��й����������˳��
	// �ȹ��츸�࣬��������  ����˳���෴�����������࣬����������
	// ��ʵ�����������ʱ������Ĺ��캯���ᱻ���ã���������ͷ�ʱ����������������ᱻ����
	// �ڶ��ؼ̳е�����£���������ε������и���Ĺ��캯�������ռ̳�������˳����á�
	// �Ȱ��ռ̳�������˳���츸�࣬��������  ����˳���෴
	// 
	// �� C++ �У�����ĳ�ʼ��˳�����ϸ�ģ�
	// 1�����ȵ��ø���Ĺ��캯����
	// 2��Ȼ���ʼ������ĳ�Ա������
	// 3�����ִ������Ĺ��캯���塣
	fun21();



	//�̳���ͬ����Ա�Ĵ���ʽ
	// ���̳�ʱ�����븸������ͬ���ĳ�Ա
	// �������з��������е�ͬ����Ա��ֱ�ӷ��ʼ���
	// �������з��ʸ����ͬ����Ա����Ҫ�������� (�﷨���������.��������::�����Ա)
	// ��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص����������е�ͬ����Ա����(�����е�����Ҳֻ��ͨ�����������)
	// ��ͨ��Ա�������Ա�������;�̬��Ա������̬��Ա����������͸���ͬ��ʱ���ʹ�����һ����
	//

	fun22();


	//��̳�
	// �ڶ��ؼ̳е�����£���������ε������и���Ĺ��캯�������ռ̳�������˳����á�
	// �Ȱ��ռ̳�������˳���츸�࣬��������  ����˳���෴
	fun23();


	//��̳�
	// ��̳У�Virtual Inheritance���� C++ ��һ������ļ̳з�ʽ�����ڽ�����ؼ̳��еġ����μ̳����⡱��Diamond Problem����ͨ����̳У�����ȷ����������ֻ��һ�������Ӷ��󣬴Ӷ������ظ��̳д�������������Ͷ��������⡣
	// �﷨��class ������: virtual �̳з�ʽ ������
	// ����̳е�����£�����������������������һ��ָ��������ָ�루ͨ����Ϊ������ָ��� vbptr�������ڹ���������ʵ����
	// ��ָ���ָ�����������м�¼��һ��ƫ��������ָ���λ�ü����������е�ƫ��������ָ���λ�þ���������̳л���ı�����λ��
	// ��������ʹ�������ж��·���̳���ͬһ�����࣬Ҳֻ�ᴴ��һ�������ʵ����
	// ������һ�����������ʱ�������Ĺ��캯�����������յ�������ֱ�ӵ��ã���ֻ�����һ�Σ����������м�����á�
	// ����˳��
	// ���ȵ��������Ĺ��캯����Ȼ�����ε�����������Ĺ��캯����
	// ����˳���빹��˳���෴
	// �鿴����ڴ�ṹͼ��cl /d1 reportSingleClassLayout���� "�ļ���"
	// 
	/*
	class `anonymous-namespace'::Class24_1  size(12):
			+---
	 0      | +--- (base class `anonymous-namespace'::BaseClass24_3)
	 0      | | {vbptr}//��ָ��ƫ����Ϊ8��0+8��Ϊm_A��λ��
			| +---
	 4      | +--- (base class `anonymous-namespace'::BaseClass24_4)
	 4      | | {vbptr}//��ָ��ƫ����Ϊ4��4+4��Ϊm_A��λ��
			| +---
			+---
			+--- (virtual base `anonymous-namespace'::BaseClass24)
	 8      | m_A
			+---

	`anonymous-namespace'::Class24_1::$vbtable@BaseClass24_3@:
	 0      | 0
	 1      | 8 (Class24_1d(BaseClass24_3+0)BaseClass24)

	`anonymous-namespace'::Class24_1::$vbtable@BaseClass24_4@:
	 0      | 0
	 1      | 4 (Class24_1d(BaseClass24_4+0)BaseClass24)
	*/

	//���Է��ʸ��ࡢ�м��ࡢ����ı���������Ĭ�Ϲ��캯�������Թ��������˳�򣬲��Բ鿴���ࡢ�������м����ڴ�ṹ
	fun24();
	fun25();
}

