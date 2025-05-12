#pragma once

#include<iostream>
#include<string>

using namespace std;


namespace student
{
	class Student
	{
		friend ostream& operator<<(ostream& ostr, const Student& c);
	public:
		int studentID;
		string userName;
		string password;
		Student();
		Student(int id, string name, string psw);
	};

	


}


