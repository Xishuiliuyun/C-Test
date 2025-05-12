#pragma once

#include<iostream>
#include<string>


using namespace std;



namespace teacher
{
	class Teacher
	{
		friend ostream& operator<<(ostream& ostr, const Teacher& c);
	public:
		int teacherID;
		string userName;
		string password;
		Teacher();
		Teacher(int id,string name,string psw);
	};

	
}