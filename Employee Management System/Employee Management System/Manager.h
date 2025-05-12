#pragma once
#include<iostream>
#include "Employee.h"
#include<fstream>
using namespace std;
using namespace Emp;

#define FILEPATH "Data.txt"

namespace Control {
	class Manager
	{
	public:
		int employeeNum;//��¼�����е�Ԫ�ظ�������0��ʼ
		int maxEmployee;//��¼�������Ԫ������
		//bool isFileEmpty;
		Employee** eArr;


		Manager();
		~Manager();
		void Show_Menu();
		void ExitSys();//�˳�
		void addEmployee();//���Ա��
		void addEmployeeToArr(Employee* ep);//���������������
		void writeData();//�����������д���ļ�
		void readData();
		void showEmployee();
		void delEmployee();
		int checkEmployee(int no);
		int checkEmployee(const char* name);
		void changeEmployeeInfo();
		int isFileEmpty();
		int findEmployee();
		void sortEmployee();
		void clearEmployee();
	};
}





