#include"Teacher.h"



namespace teacher
{


	ostream& operator<<(ostream& ostr, const Teacher& c)
	{
		return cout << "���:" << c.teacherID << "  �û���:" << c.userName << "  ���룺" << c.password /*<< endl*/;
	}

	Teacher::Teacher() {}
	Teacher::Teacher(int id, string name, string psw)
	{
		teacherID = id;
		userName = name;
		password = psw;
	}
}