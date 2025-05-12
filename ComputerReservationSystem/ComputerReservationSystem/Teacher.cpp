#include"Teacher.h"



namespace teacher
{


	ostream& operator<<(ostream& ostr, const Teacher& c)
	{
		return cout << "±àºÅ:" << c.teacherID << "  ÓÃ»§Ãû:" << c.userName << "  ÃÜÂë£º" << c.password /*<< endl*/;
	}

	Teacher::Teacher() {}
	Teacher::Teacher(int id, string name, string psw)
	{
		teacherID = id;
		userName = name;
		password = psw;
	}
}