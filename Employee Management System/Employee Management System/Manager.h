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
		int employeeNum;//记录数组中的元素个数，从0开始
		int maxEmployee;//记录数组最大元素数量
		//bool isFileEmpty;
		Employee** eArr;


		Manager();
		~Manager();
		void Show_Menu();
		void ExitSys();//退出
		void addEmployee();//添加员工
		void addEmployeeToArr(Employee* ep);//向数组中添加数据
		void writeData();//将数组的数据写入文件
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





