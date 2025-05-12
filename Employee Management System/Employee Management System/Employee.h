#pragma once
#include <iostream>
#include<string>

using namespace std;

namespace Emp {

	enum class Position
	{
		Boss,
		Manager,
		General
	};

	class Employee
	{
	public:
		int m_No;
		char m_Name[64];
		Position m_Pos;
		virtual void work() = 0;
		virtual void showInfo() = 0;
		virtual const char* getPosName() = 0;
	};

	class GeneralEmployee :public Employee
	{
	public:
		GeneralEmployee();
		GeneralEmployee(int no, const char* name/*, int pos*/);
		void work();
		void showInfo();
		const char* getPosName();
	};
	class Manager :public Employee
	{
	public:
		Manager();
		Manager(int no, const char* name/*, int pos*/);
		void work();
		void showInfo();
		const char* getPosName();
	};
	class Boss :public Employee
	{
	public:
		Boss();
		Boss(int no, const char* name/*, int pos*/);
		void work();
		void showInfo();
		const char* getPosName();
	};

}


