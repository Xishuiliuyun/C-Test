#include <iostream>
#include <string>
#include "Manager.h"
#include"Employee.h"

using namespace std;

//实现职工管理系统
//
// 职工分类：2普通员工、1经理、0老板
// 职工信息：1职工编号、2职工姓名、3职工岗位、4职工职责
// 
// 管理系统需要实现的功能：
// 1、退出管理系统
// 2、增加职工信息 编号、姓名、岗位
// 3、显示职工信息
// 4、删除离职职工
// 5、修改职工信息
// 6、查找职工信息
// 7、按照编号排序
// 8、清空所有信息

//文本中每行记录一个人员信息，程序中以Employee类数组进行存储访问



void test()
{
	GeneralEmployee p1(1,"张三");
	Manager p2(2,"李四");
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

	//读取文本获取所有员工信息
	m.readData();

	while (true)
	{
		int input = -1;
		m.Show_Menu();
		cin >> input;

		switch (input)
		{
		case 0://退出管理系统
			m.ExitSys();
			break;
		case 1://增加职工信息
			m.addEmployee();
			break;
		case 2://显示职工信息
			m.showEmployee();
			break;
		case 3://删除离职职工
			m.delEmployee();
			break;
		case 4://修改职工信息
			m.changeEmployeeInfo();
			break;
		case 5://查找职工信息
			if (m.findEmployee() != -1)
			{
				system("pause");
				system("cls");
			}
			break;
		case 6://按照编号排序
			m.sortEmployee();
			break;
		case 7://清空所有信息
			m.clearEmployee();
			break;
		default:
			system("cls");
			break;
		}

	}

	
}





