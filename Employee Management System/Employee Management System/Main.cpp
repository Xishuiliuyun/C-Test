#include <iostream>
#include <string>
#include "Manager.h"
#include"Employee.h"

using namespace std;

//ʵ��ְ������ϵͳ
//
// ְ�����ࣺ2��ͨԱ����1����0�ϰ�
// ְ����Ϣ��1ְ����š�2ְ��������3ְ����λ��4ְ��ְ��
// 
// ����ϵͳ��Ҫʵ�ֵĹ��ܣ�
// 1���˳�����ϵͳ
// 2������ְ����Ϣ ��š���������λ
// 3����ʾְ����Ϣ
// 4��ɾ����ְְ��
// 5���޸�ְ����Ϣ
// 6������ְ����Ϣ
// 7�����ձ������
// 8�����������Ϣ

//�ı���ÿ�м�¼һ����Ա��Ϣ����������Employee��������д洢����



void test()
{
	GeneralEmployee p1(1,"����");
	Manager p2(2,"����");
	Boss p3(3,"bob");

	/*p1.showInfo();
	p2.showInfo();
	p3.showInfo();*/

	Employee* pp = &p1;
	pp->showInfo();
	pp = &p2;
	pp->showInfo();
	pp = &p3;
	pp->showInfo();


	system("pause");
	exit(0);
}


int main()
{
	//test();
	Control::Manager m;

	//��ȡ�ı���ȡ����Ա����Ϣ
	m.readData();

	while (true)
	{
		int input = -1;
		m.Show_Menu();
		cin >> input;

		switch (input)
		{
		case 0://�˳�����ϵͳ
			m.ExitSys();
			break;
		case 1://����ְ����Ϣ
			m.addEmployee();
			break;
		case 2://��ʾְ����Ϣ
			m.showEmployee();
			break;
		case 3://ɾ����ְְ��
			m.delEmployee();
			break;
		case 4://�޸�ְ����Ϣ
			m.changeEmployeeInfo();
			break;
		case 5://����ְ����Ϣ
			if (m.findEmployee() != -1)
			{
				system("pause");
				system("cls");
			}
			break;
		case 6://���ձ������
			m.sortEmployee();
			break;
		case 7://���������Ϣ
			m.clearEmployee();
			break;
		default:
			system("cls");
			break;
		}

	}

	
}





