#include "FileTest.h"


namespace {

	//д�ı��ļ�����
	void fun1()
	{
		ofstream ofs;
		ofs.open("test.txt", ios::out);//������ִ����ɺ��ļ��е������Ѿ��������
		ofs << "test test" << endl;//������ִ����ɺ��Ѿ����ļ����������
		ofs << "test test" << endl;
		ofs.close();

		ofstream ofs2("test.txt", ios::app);
		ofs2 << "test test" << endl;
		ofs2 << "test test" << endl;
		ofs2.close();

		fstream ofs3("test.txt", ios::in | ios::out);
		ofs3 << "test1 test1" << endl;//��ɾ��ԭ���ݣ���ͷ��ʼ����д��
		ofs3 << "test1 test1" << endl;
		ofs3.close();

	}

	//���ı��ļ�����
	int fun2()
	{
		ifstream ifs1;
		ifs1.open("testRead.txt", ios::in);
		if (!ifs1.is_open())
		{
			cout << "open file fail" << endl;
			return -1;
		}
		//��ʽһ��
		//>>����������������ȡ�ļ����ݣ��������հ��ַ����ո��Ʊ�������з���
		//ÿ�ζ�ȡ���ݷŵ�buf��ʱ����ȡ���հ��ַ�ǰ������
		cout << "-------------" << ">>���������" << "-------------" << endl;
		char buf[1024] = { 0 };
		while (ifs1 >> buf)
		{
			cout << buf << endl;
		}
		ifs1.clear();
		cout << "-------------" << ifs1.tellg() << "-------------" << endl;//win��gbk�����ʽ���ļ�������ռ2���ֽڣ�Ӣ��ռ1���ֽڣ�����ռ2���ֽ�
		ifs1.seekg(0,ios::beg);
		string str;
		while (ifs1 >> str)
		{
			cout << str << endl;
		}

		//��ʽ����
		//ifstream�����getline���� ���ж�ȡ�ļ�����
		//ÿ�ζ�ȡ���ݷŵ�buf��ʱ����ȡ������ǰ������
		cout << "-------------" << "ifstream�����getline����" << "-------------" << endl;
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
		//while(ifs1.getline(str2,1024))//string���ͱ���������Ϊ�������ø÷���

		//��ʽ����
		//ȫ�ֵ�getline���� ���ж�ȡ�ļ�����
		//ÿ�ζ�ȡ���ݷŵ�buf��ʱ����ȡ������ǰ������
		//�����stringͷ�ļ�
		cout << "-------------" << "ȫ�ֵ�getline����" << "-------------" << endl;
		string str3;
		while (getline(ifs1, str3))
		{
			cout << str3 << endl;
		}
		ifs1.clear();
		cout << "-------------" << ifs1.tellg() << "-------------" << endl;
		ifs1.seekg(0, ios::beg);
		//char buf3[1024];
		//while (getline(ifs1,buf3))//char*���ͱ���������Ϊ�������ø÷���

		//��ʽ�ģ�
		//ifstream�����get���� ���ַ���ȡ�ļ�����
		//ÿ�ζ�ȡһ���ַ������е����ݶ��ᱻ��ȡ��
		cout << "-------------" << "ifstream�����get����" << "-------------" << endl;
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

		//��ʽ�壺
		//stringstream������� ������rdbuf���� ������ һ���Զ�ȡ�����ļ�
		//��Ҫ����ͷ�ļ�#include <sstream>
		cout << "-------------" << "stringstream������� ������rdbuf����" << "-------------" << endl;
		stringstream buffer;
		buffer << ifs1.rdbuf();
		string contents = buffer.str();
		cout << contents << endl;
		cout << "-------------" << ifs1.tellg() << "-------------" << endl;
		ifs1.close();


	}


	//��д�������ļ�����
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
			cout << "���ļ�ʧ��" << endl;
			return;
		}
		ifs.read((char*)&c2, sizeof(c2));
		ifs.close();
		cout << c2.m_Name << "\t" << c2.m_Age << endl;

	}

}


//�ļ���д����
void testFile()
{
	//�ļ�����
	//C++�ж��ļ�������Ҫ����ͷ�ļ�<fstream>
	// �ļ����ͣ�
	// 1���ı��ļ�
	//	�ļ������ǿɶ����ַ����ݡ�
	//	ͨ���� ASCII �� UTF-8 ����洢��
	//	ÿ���Ի��з���\n���ָ���
	//	������չ����.txt��.csv��.json��.xml��.html��.cpp��.h
	// 2���������ļ�
	//	�ļ����������ֽ�Ϊ��λ�洢��ԭʼ���ݡ�
	//	���ݲ���ֱ���Ķ���ͨ����Ҫ�ض����������
	//	�����ڴ洢�ṹ�����ݣ����������ȣ���
	// �ļ�ģʽ��
	// 1���ı�ģʽ
	//	Ĭ��ģʽ�������ڴ����ı��ļ���
	//	�Զ������з����� Windows ƽ̨�ϵ� \r\n ת��Ϊ \n����
	// 2��������ģʽ
	//	��ȷָ�� ios::binary ģʽ�������ڴ���������ļ���
	//	�ļ�������ԭʼ�ֽ���ʽ�����������κ�ת����
	// 
	// �����ļ�����������
	// 1��ofstream:д����
	// 2��ifstream:������
	// 3��fstream:��д����
	// 
	// д�ļ���
	// 1������ͷ�ļ���	#include<fstream>
	// 2������������	ofstream ������;
	// 3�����ļ���	������.open("�ļ�·��",��ģʽ);
	//					�����ڴ���������ʱ�����ļ�·��ֱ�Ӵ� ofstream ������("�ļ�·��",��ģʽ);//��д��ģʽ������Ĭ�ϴ򿪷�ʽΪios::out
	// 4��д���ݣ�		������<<"д�������";//ʹ��<<�������ʹ�÷�ʽ��cout����
	// 5���ر��ļ���	������.close();
	// 
	// ���ļ���
	// 1������ͷ�ļ���			#include<fstream>
	// 2������������			ifstream ������;
	// 3�����ļ���			������.open("�ļ�·��",��ģʽ);
	//							�����ڴ���������ʱ�����ļ�·��ֱ�Ӵ� ifstream ������("�ļ�·��",��ģʽ);//��д��ģʽ������Ĭ�ϴ򿪷�ʽΪios::in
	// 4���ж��ļ��Ƿ�򿪳ɹ���������.is_open()//�����ļ��Ƿ�ɹ���
	// 5�������ݣ�				�и��ַ�ʽ�������ݶ�ȡ
	// 6���ر��ļ���			������.close();
	// 
	// �����ݵ�ʵ�ַ�ʽ��
	// 1��
	//	>>����������������ȡ�ļ����ݣ��������հ��ַ����ո��Ʊ�������з���
	//	ÿ�ζ�ȡ���ݷŵ�buf��ʱ����ȡ���հ��ַ�ǰ������
	// 2��
	//	ifstream�����getline���� ���ж�ȡ�ļ�����
	//	ÿ�ζ�ȡ���ݷŵ�buf��ʱ����ȡ������ǰ������
	// 3��
	//	ȫ�ֵ�getline���� ���ж�ȡ�ļ�����
	//	ÿ�ζ�ȡ���ݷŵ�buf��ʱ����ȡ������ǰ������
	//	�����stringͷ�ļ�
	// 4��
	//	ifstream�����get���� ���ַ���ȡ�ļ�����
	//	ÿ�ζ�ȡһ���ַ������е����ݶ��ᱻ��ȡ��
	// 5��
	//	stringstream������� ������rdbuf���� ������ һ���Զ�ȡ�����ļ�
	//	��Ҫ����ͷ�ļ�#include <sstream>
	//	stringstream������յ�����������str����תΪstring���ͺ�ʹ��
	// 
	// 
	// 
	// 
	// �ļ���ģʽ��
	// ios::in��
	//	���ļ����ڶ�ȡ��
	//	Ĭ��Ϊ ifstream �Ĵ�ģʽ��
	//	����ļ������ڣ���ʧ�ܡ�
	// ios::out��
	//	���ļ�����д�롣
	//	Ĭ��Ϊ ofstream �Ĵ�ģʽ��
	//	����ļ��Ѵ��ڣ���������ݣ�����ļ������ڣ��򴴽����ļ���
	// ios::binary��
	//	�Զ�����ģʽ���ļ���
	//	ͨ��������ģʽ���ʹ�ã��� ios::in | ios::binary����
	// ios::app��
	//	���ļ�����׷�ӡ�
	//	д������ݻᱻ��ӵ��ļ�ĩβ���������ԭ�����ݡ�
	//	ǿ������������������ļ�ĩβ����
	// ios::ate��
	//	���ļ���λ���ļ�ĩβ��
	//	�� ios::app ��ͬ���ǣ�ios::ate �������ļ�������λ�ý��ж�д��
	//	ֻ���ڴ��ļ�ʱ���ļ�ָ�������ļ�ĩβ��֮����������ɵ��ƶ��ļ�ָ�뵽�κ�λ�ý��ж�д������
	// ios::trunc��
	//	����ļ��Ѵ��ڣ�������ļ����ݡ�
	//	Ĭ������£�ios::out ���� ios::trunc��
	// 
	// 



	fun1();


	fun2();

	fun3();
}