#include"Student.h"


namespace student
{

	ostream& operator<<(ostream& ostr, const Student& c)
	{
		return cout << "���:" << c.studentID << "  �û���:" << c.userName<< "  ���룺" << c.password  /*<< endl*/;
	}

	Student::Student() {}
	Student::Student(int id, string name, string psw)
	{
		studentID = id;
		userName = name;
		password = psw;
	}


}