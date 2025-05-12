#include"Employee.h"

using namespace Emp;

GeneralEmployee::GeneralEmployee() {}
GeneralEmployee::GeneralEmployee(int no, const char* name/*, int pos*/)
{
	m_No = no;
	memcpy(m_Name, name, strlen(name) + 1);
	m_Pos = Position::General;
	/*switch (pos)
	{
	case 0:
		m_Pos = Position::Boss;
		break;
	case 1:
		m_Pos = Position::Manager;
		break;
	case 2:
		m_Pos = Position::General;
		break;
	}*/
}
void GeneralEmployee::work()
{

}
void GeneralEmployee::showInfo()
{
	cout << "��ţ�" << m_No << "\t" << "������" << m_Name << "\t" << "ְλ��" << getPosName() << "\t" << "��λְ��2" << endl;
}
const char* GeneralEmployee::getPosName()
{
	return "��ͨԱ��";
}

Manager::Manager() {}
Manager::Manager(int no, const char* name/*, int pos*/)
{
	m_No = no;
	memcpy(m_Name, name, strlen(name) + 1);
	m_Pos = Position::Manager;
	/*switch (pos)
	{
	case 0:
		m_Pos = Position::Boss;
		break;
	case 1:
		m_Pos = Position::Manager;
		break;
	case 2:
		m_Pos = Position::General;
		break;
	}*/
}
void Manager::work()
{

}
void Manager::showInfo()
{
	cout << "��ţ�" << m_No << "\t" << "������" << m_Name << "\t" << "ְλ��" << getPosName() << "\t" << "��λְ��1" << endl;
}
const char* Manager::getPosName()
{
	return "����";
}

Boss::Boss() {}
Boss::Boss(int no, const char* name/*, int pos*/)
{
	m_No = no;
	memcpy(m_Name, name, strlen(name) + 1);
	m_Pos = Position::Boss;
	/*switch (pos)
	{
	case 0:
		m_Pos = Position::Boss;
		break;
	case 1:
		m_Pos = Position::Manager;
		break;
	case 2:
		m_Pos = Position::General;
		break;
	}*/
}
void Boss::work()
{

}
void Boss::showInfo()
{
	cout << "��ţ�" << m_No << "\t" << "������" << m_Name << "\t" << "ְλ��" << getPosName() << "\t" << "��λְ��0" << endl;
}
const char* Boss::getPosName()
{
	return "�ϰ�";
}

