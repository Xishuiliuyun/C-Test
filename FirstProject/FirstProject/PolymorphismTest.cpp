#include "PolymorphismTest.h"


namespace {
	//��̬ʵ�ֺ͵���
	class BaseClass1
	{
	public:
		virtual void print()
		{
			cout << "BaseClass1" << endl;
		}
	};
	class Class1 :public BaseClass1
	{
	public:
		void print()//��д������麯�� ��д(�����ķ���ֵ���͡��������������б� ��ȫ��ͬ )
		{
			cout << "Class1" << endl;
		}
	};
	class Class1_1 :public BaseClass1
	{
	public:
		void print()
		{
			cout << "Class2" << endl;
		}
	};
	void fun1_1(BaseClass1& c)
	{
		c.print();
	}
	void fun1()
	{
		cout << "\n\nTest_fun1" << endl;
		BaseClass1* c1 = new Class1();
		BaseClass1* c2 = new Class1_1();
		
		c1->print();
		c2->print();
		Class1 c3;
		Class1_1 c4;
		fun1_1(c3);
		fun1_1(c4);

		BaseClass1& c5 = c3;
		c5.print();


		delete c1;
		delete c2;
	}


	//һЩ�麯��ʵ����صĲ���
	class BaseClass2
	{
	public:
		virtual void PFun()
		{
			cout << "BaseClass2" << endl;
		}
	};
	class Class2 :public BaseClass2
	{

	};
	void fun2()
	{
		cout << "\n\nTest_fun2" << endl;
		Class2 c1;
		c1.PFun();
	}
	class BaseClass3
	{
	public:
		virtual void PFun()
		{
			cout << "BaseClass3" << endl;
		}
	};
	class Class3:public BaseClass3 {};
	void fun3_1(BaseClass3& c)
	{
		c.PFun();
	}
	void fun3()
	{
		cout << "\n\nTest_fun3" << endl;
		Class3 c1;
		fun3_1(c1);
	}


	//��������̬ʵ�ּ������
	class AbstractCalculator
	{
	public:
		int m_Num1;
		int m_Num2;

		virtual int getResult() { return -1; }
	};
	class SumCalculator:public AbstractCalculator
	{
	public:
		int getResult()
		{
			return m_Num1 + m_Num2;
		}
	};
	class SubCalculator :public AbstractCalculator
	{
	public:
		int getResult()
		{
			return m_Num1 - m_Num2;
		}
	};
	class MulCalculator :public AbstractCalculator
	{
	public:
		int getResult()
		{
			return m_Num1 * m_Num2;
		}
	};
	void fun4()
	{
		cout << "\n\nTest_fun4" << endl;
		AbstractCalculator* pCal = new SumCalculator();
		pCal->m_Num1 = 10;
		pCal->m_Num2 = 10;
		cout << pCal->getResult() << endl;

		delete pCal;
		pCal = new SubCalculator();
		pCal->m_Num1 = 10;
		pCal->m_Num2 = 10;
		cout << pCal->getResult() << endl;

		delete pCal;
		pCal = new MulCalculator();
		pCal->m_Num1 = 10;
		pCal->m_Num2 = 10;
		cout << pCal->getResult() << endl;

		delete pCal;
	}


	//���麯���ͳ�����
	class BaseClass5
	{
	public:
		virtual void fun() = 0;//���崿�麯��
	};
	class Class5 :public BaseClass5
	{

	};
	class Class5_1 :public BaseClass5
	{
	public:
		void fun()
		{
			cout << "Class5_1" << endl;
		}
	};
	void fun5()
	{
		cout << "\n\nTest_fun5" << endl;
		//BaseClass5 c1;//����//���а������麯�������಻��ֱ��ʵ��������
		//BaseClass5* c2 = new BaseClass5();//����//���а������麯�������಻��ֱ��ʵ��������
		//Class5 c1;//����//δ��д���ി�麯����Ҳ�ǳ����࣬�޷�ʵ��������
		//Class5* c2 = new Class5();//����//δ��д���ി�麯����Ҳ�ǳ����࣬�޷�ʵ��������
		Class5_1 c1;
		c1.fun();//��̬����
		BaseClass5* c2 = &c1;
		c2->fun();//��̬����
	}


	//������������Ʒ
	class AbstractMakeDrink
	{
	public:
		virtual void fun1() = 0;//��ˮ
		virtual void fun2() = 0;//����
		virtual void fun3() = 0;//���뱭��
		virtual void fun4() = 0;//���븨��
		void fun5()//ִ�����������в���
		{
			fun1();
			fun2();
			fun3();
			fun4();
		}
	};
	class MakeCoffee:public AbstractMakeDrink
	{
	public:
		void fun1()
		{
			cout << "��ˮ" << endl;
		}
		void fun2()
		{
			cout << "���ݿ���" << endl;
		}
		void fun3()
		{
			cout << "���뱭��" << endl;
		}
		void fun4()
		{
			cout << "����ţ�̺���" << endl;
		}
	};
	class MakeTea :public AbstractMakeDrink
	{
	public:
		void fun1()
		{
			cout << "��ˮ" << endl;
		}
		void fun2()
		{
			cout << "���ݲ�Ҷ" << endl;
		}
		void fun3()
		{
			cout << "���뱭��" << endl;
		}
		void fun4()
		{
			cout << "���븨��" << endl;
		}
	};
	void fun6()
	{
		cout << "\n\nTest_fun6" << endl;
		MakeCoffee c1;
		MakeTea c2;
		AbstractMakeDrink* cP1 = &c1;
		AbstractMakeDrink* cP2 = &c2;
		cP1->fun5();
		cP2->fun5();


	}


	//�������
	class AbstractClass7
	{
	public:
		virtual void fun1() = 0;
		void fun2()
		{
			cout << this << endl;
			cout << "AbstractClass7_fun2" << endl;
			fun1();
		}
	};
	class Class7 :public AbstractClass7
	{
	public:
		void fun1()
		{
			cout << this << endl;
			cout << "fun1" << endl;
		}
		void fun2()
		{
			cout << "Class7_fun2" << endl;//���ᱻ����
		}
	};
	void fun7()
	{
		cout << "\n\nTest_fun7" << endl;
		AbstractClass7* cP = new Class7();
		cout << cP << endl;
		cP->fun2();	//����fun2ʱ��û���漰�麯������ֱ�Ӿ�̬������AbstractClass7::fun2
					//����fun1ʱ��ͨ��thisָ�룬�麯��ָ����麯�����ҵ���Ӧ�ĺ������е��ã����õ���Class7::fun1
		//��ʵʵ����û��ʵ�ֶ�̬�Ļ���ֻ����þ�̬�����ж�Ӧ�ĺ���
		//Class7�е�fun2���ᱻ���ã���ΪcP�ľ�̬������AbstractClass7*����ֱ�ӵ���AbstractClass7::fun2
		//ֻ��ͨ��ʵ�ֶ�̬�ķ�ʽ���Ż���õ�Class7�е�fun2

		delete cP;
	}


	//�������ʹ�������
	class BaseClass8
	{
	public:
		BaseClass8()
		{
			cout << "BaseClass8����" << endl;
		}
		~BaseClass8()
		{
			cout << "BaseClass8����" << endl;
		}
		virtual void fun()
		{

		}
	};
	class Class8:public BaseClass8
	{
	public:
		Class8()
		{
			cout << "Class8����" << endl;
		}
		~Class8()
		{
			cout << "Class8����" << endl;
		}
		void fun()
		{

		}
	};
	class BaseClass8_1
	{
	public:
		BaseClass8_1()
		{
			cout << "BaseClass8_1����" << endl;
		}
		//virtual ~BaseClass8_1()//������
		//{
		//	cout << "BaseClass8_1����" << endl;
		//}
		virtual void fun()
		{

		}
		virtual ~BaseClass8_1() = 0;//��������
	};
	BaseClass8_1::~BaseClass8_1()
	{
		cout << "BaseClass8_1����" << endl;
	}
	class Class8_1 :public BaseClass8_1
	{
	public:
		Class8_1()
		{
			cout << "Class8_1����" << endl;
		}
		~Class8_1()
		{
			cout << "Class8_1����" << endl;
		}
		void fun()
		{

		}
	};
	void fun8_1(BaseClass8& c)
	{
		cout << "fun8_1" << endl;
	}
	void fun8_2(BaseClass8* c)
	{
		delete c;//�ͷŸ���ָ��ʱ��������õ��������������
		cout << "fun8_2" << endl;
	}
	void fun8()
	{
		cout << "\n\nTest_fun8" << endl;
		//Class8 c1;
		//fun8_1(c1);//���÷�ʽʵ�ֶ�̬��������һ����ʼ��������ʼ�������ں����������Զ��ͷ�

		//fun8_2(new Class8());//��ʱ����һ���������󣬺�������ָ��ָ���˸ö��󣬴�ʱ��Ҫ�ں������ֶ��ͷŸ���������

		BaseClass8_1* cP = new Class8_1();
		delete cP;


	}


	//����
	class AbstractCPU
	{
	public:
		virtual void work() = 0;
	};
	class AbstractGPU
	{
	public:
		virtual void work() = 0;
	};
	class AbstractMemory
	{
	public:
		virtual void work() = 0;
	};
	class IntelCPU:public AbstractCPU
	{
	public:
		void work()
		{
			cout << "IntelCPU work" << endl;
		}
	};
	class IntelGPU :public AbstractGPU
	{
	public:
		void work()
		{
			cout << "IntelGPU work" << endl;
		}
	};
	class IntelMemory :public AbstractMemory
	{
	public:
		void work()
		{
			cout << "IntelMemory work" << endl;
		}
	};
	class AMDCPU :public AbstractCPU
	{
	public:
		void work()
		{
			cout << "AMDCPU work" << endl;
		}
	};
	class AMDGPU :public AbstractGPU
	{
	public:
		void work()
		{
			cout << "AMDGPU work" << endl;
		}
	};
	class AMDMemory :public AbstractMemory
	{
	public:
		void work()
		{
			cout << "AMDMemory work" << endl;
		}
	};
	class Computer
	{
	public:
		AbstractCPU* cup;
		AbstractGPU* gup;
		AbstractMemory* memory;
		void work()
		{
			cup->work();
			gup->work();
			memory->work();
		}
	};

	void fun9()
	{
		cout << "\n\nTest_fun9" << endl;
		IntelCPU cpu1;
		IntelGPU gpu1;
		IntelMemory memory1;
		AMDCPU cpu2;
		AMDGPU gpu2;
		AMDMemory memory2;

		Computer c1;
		c1.cup = &cpu1;
		c1.gup = &gpu1;
		c1.memory = &memory1;

		Computer c2;
		c2.cup = &cpu2;
		c2.gup = &gpu2;
		c2.memory = &memory2;

		c1.work();
		c2.work();


	}
}




void testPolymorphism()
{
	//��̬
	// �� C++ �У���̬��Polymorphism�� ����������̵ĺ�������֮һ�������������ݶ����ʵ�����͵�����Ӧ�ķ������Ӷ�ʵ�ָ����Ϳ���չ�Ĵ�����ơ�
	// ���ࣺ
	// ��̬��̬���������غ����������
	// ��̬��̬����������麯��ʵ������ʱ��̬
	// ����
	// ��̬��̬�ĺ�����ַ���--����׶�ȷ��������ַ
	// ��̬��̬�ĺ�����ַ���--���н׶�ȷ��������ַ
	// 
	// ��̬��̬����������
	// 1���м̳й�ϵ
	// 2��������д������麯�� (��д�������ķ���ֵ���͡��������������б� ��ȫ��ͬ)
	// 
	// ��̬��̬��ʹ��
	// �����ָ������� ָ��������� 
	// 
	// ��̬�ĺô���
	// 1����֯�ṹ����
	// 2���ɶ���ǿ
	// 3������ǰ�ںͺ�����չ�Լ�ά���Ը�
	// 
	// ��̬��ϸʵ��ԭ��
	// ��̬�󶨣� ��ͨ��������ͨ��Ա�����ڱ���ʱ���Ѿ�ȷ���˺������õ�Ŀ���ַ
	// ��̬�󶨣� ������ʱ���ݶ����ʵ������ȷ���������õ�Ŀ���ַ
	// ��Ҫ��ͨ�����ඨ���麯����������д�麯������ͨ������ָ������õ����麯������ʱ�����˶�̬����������ʱ���ݶ����ʵ������ȷ���������õ�Ŀ���ַ
	// �麯��ָ�루vfptr����
	//	���壺ÿ�������麯���Ķ����ж�����һ�����صĳ�Ա��������Ϊ�麯��ָ�루vptr����
	//	���ã��麯��ָ��ָ��ö�����������麯����
	//	��ʼ�����ڶ�����ʱ���������Ὣ vptr ��ʼ��Ϊָ��ö�����������麯����(ͬһ����Ĳ�ͬʵ�������ɲ�ͬ���麯��ָ�룬��ָ�����ͬһ���麯����)
	// �麯����vftable����
	//	���壺ÿ�������麯�����඼��һ���麯����vtable��������һ����̬���飬�洢�˸��༰�丸��������麯���ĵ�ַ��
	//	����ʱ�����������ڱ���ʱΪÿ�������麯����������һ���麯����
	//	���ݣ�
	//	�����������д��ĳ���麯��������������麯�����ж�Ӧλ�õĺ�����ַ�ᱻ�滻Ϊ�������ʵ�֡�
	//	���������û����дĳ���麯������̳л�����麯����ַ��
	// ��fun1��ʵ�ֵĶ�̬Ϊ����
	//	BaseClass1�����ж����麯������ʱ�����л���ʽ����һ��vfptr����ָ��ָ��vftable���麯�����м�¼���麯���ĵ�ַ &BaseClass1::print
	//	Class1��̳���BaseClass1�࣬������Ҳ����һ��vfptr��ָ���Լ���vftable(ע���븸����麯������ͬһ��)��
	//	ͬʱ���麯�����м̳���һ���麯���ĵ�ַ &BaseClass1::print������Class1������д�˸�����麯�����麯�����е��麯���ĵ�ַ�ᱻ��д�ĺ������ǵ���
	//	���滻�� &Class1::print����ʹ�ø����ָ�������ָ���������ķ�ʽ�����麯��ʱ�������ʵ���е��麯��ָ���ҵ��麯�������ö�Ӧ�ĺ�������ʱʵ���˺����Ķ�̬���ã�ʵ���˶�̬
	// 
	// 
	// 
	// ��̬���ͺͶ�̬����
	// ��̬���ͣ�
	//	����
	//	��̬���� ��ָ��������ʽ�ڱ���ʱȷ�������͡�
	//	���Ǳ��������ݴ����������������Ƶ������ġ�
	//	�ص�
	//	��̬�����ɱ���������������������ʱ�Ķ����޹ء�
	//	�������ڱ���׶ξ��Ѿ�֪��ÿ�������ľ�̬���͡�
	//	��̬���;�������Щ�����Ͳ��������ڸñ�����ִ�С�
	//	ʾ����Base* b = new Derived(); 
	//	b �ľ�̬������ Base*����Ϊ��������Ϊ Base* ���͵�ָ�롣
	//	����������� Base ��Ķ�������� b �ϵĲ����Ƿ�Ϸ���
	// ��̬���ͣ�
	//	����
	//	��̬���� ��ָ��������ʽ������ʱʵ��ָ��Ķ�������͡�
	//	�����ɳ���������ʱ�����Ķ����ʵ�����;����ġ�
	//	�ص�
	//	��̬����ֻ��������ʱ����ȷ����
	//	��̬���;�����ͨ������ָ������õ����麯��ʱ��ʵ�ʵ��õ����ĸ�����ʵ�֡�
	//	��̬����ͨ���������漰��̬�Եĳ����С�
	//	ʾ����	Base* b = new Derived();	
	//			b->show(); 
	//	b �ľ�̬������ Base*
	//	b �Ķ�̬������ Derived*����Ϊ b ʵ��ָ�����һ�� Derived ����
	//	���� b->show() ʱ��ʵ�ʵ��õ��� Derived::show()����Ϊ��̬���;����˵��õľ���ʵ�֡�
	// 
	// ��ʹ���������麯��������̳и���ʱ�̳����麯��ָ�룬ָ�����麯���������������ʹ�ø���ָ�������ָ���������ķ�ʽ��
	// ���ж�̬�󶨣�ֱ�ӵ����麯��������̬�󶨵ķ�ʽ���е��ã�ʵ���ϲ�����ͨ���麯��ָ����麯����ȥ���Һ͵��ú�����
	// ���ǻ�ֱ�ӵ��ö�Ӧ���������µĶ�Ӧ����������fun2ʾ����c1.PFun();��ʵ����ֱ�ӵ�����c1.BaseClass2::PFun();
	// ����fun3��fun3_1����ͨ����������ָ���������ķ�ʽ�����麯���ĵ��ã���ͨ���麯��ָ����麯����ʵ�ֺ����ĵ���
	// 
	// 

	fun1();
	fun2();
	fun3();


	fun4();



	//���麯���ͳ�����
	// ���麯��
	// ���壺���麯�� ��һ��������麯������û�о����ʵ�֣����ڻ�����������(��Ҫ���ڶ���ӿ�)
	// �﷨��virtual ����ֵ���� ������ (�����б�) = 0;  ����virtual void fun() = 0;
	// �ص㣺
	//	1����ʵ�֣����麯��û�к����壬ֻ��������
	//	2��ǿ���ԣ����һ����������麯��������಻��ֱ��ʵ��������
	//	3������������Σ����������ʵ�ִ��麯�������������౾��Ҳ�ǳ����ࣩ��
	// ���������˴��麯��������౻��Ϊ������
	// 
	// ������
	// ���壺
	//	������ �ǰ�������һ�����麯�����ࡣ
	//	���������ҪĿ���Ƕ���һ��ͨ�õĽӿڣ���������ʵ�֡�
	// �ص㣺
	//	1������ʵ�����������಻��ֱ�Ӵ�������
	//	2����Ϊ���ࣺ������ͨ���������࣬������ͨ��ʵ�ִ��麯������ɾ���Ĺ��ܡ�
	//	3������ʵ�֣���������԰�����ͨ��Ա���������ݳ�Ա����Щ��Ա����ֱ��ʹ�û�̳С�
	// 
	// ����������ã�
	// 1������ͨ�ýӿ�
	//	�����ඨ����һ��ͨ�õĽӿڣ�Ҫ������������ʵ����Щ�ӿڡ�
	//	���ַ�ʽ�ǳ��ʺ�������ƿ�ܻ�⣬�û����Ը�����Ҫ��չ���ܡ�
	// 2����̬��֧��
	//	��������ʵ������ʱ��̬�ԵĻ�����
	//	ͨ������ָ������õ��ô��麯�����������������ʱ����ʵ�ʶ�������͵��ö�Ӧ��ʵ�֡�
	// 
	//

	fun5();



	fun6();


	fun7();


	//�������ʹ�������
	// �ͷŸ���ָ��ʱ���ǲ�����õ���������������ģ������ͨ������ָ��ָ������ķ�ʽʵ�ֶ�̬
	// ����������������Կ��ٵ���������ʹ�����������ᵼ���ڴ�й¶
	// �������ʹ�������ȷ��ͨ������ָ��ɾ�����������ʱ���ܹ���ȷ����������������������Ӷ�������Դй©��
	//
	// ��������
	// �﷨��virutal ~����(){}
	// 
	// ����������
	// �﷨��virutal ~����() = 0;//��������
	//		����::~����(){}//���ⶨ��
	// ��������д����������������ڳ����࣬�ǲ���ʵ���������
	// һ�������������ʹ�������ֻ����һ��
	// 
	//��֤һ�����÷�ʽʵ�ֶ�̬�������ʱ������

	fun8();




	fun9();

}



