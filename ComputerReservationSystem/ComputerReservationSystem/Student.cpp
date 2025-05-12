#include"Student.h"


namespace student
{

	ostream& operator<<(ostream& ostr, const Student& c)
	{
		return cout << "±àºÅ:" << c.studentID << "  ÓÃ»§Ãû:" << c.userName<< "  ÃÜÂë£º" << c.password  /*<< endl*/;
	}

	Student::Student() {}
	Student::Student(int id, string name, string psw)
	{
		studentID = id;
		userName = name;
		password = psw;
	}


}