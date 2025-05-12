#include "Manager.h"
using namespace Control;


Control::Manager::Manager()
{
	employeeNum = 0;
	maxEmployee = 10;
	//isFileEmpty = true;
	eArr = new Employee * [maxEmployee]();
}

Control::Manager::~Manager()
{
	for (int i = 0;i < employeeNum;i++)
	{
		delete eArr[i];
		eArr[i] = nullptr;
	}
	delete[] eArr;
	eArr = nullptr;
}
//��ʾ�˵�
void Control::Manager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "************��ӭʹ��Ա������ϵͳ************" << endl;
	cout << "************	0�˳�����ϵͳ	************" << endl;
	cout << "************	1����ְ����Ϣ	************" << endl;
	cout << "************	2��ʾְ����Ϣ	************" << endl;
	cout << "************	3ɾ����ְְ��	************" << endl;
	cout << "************	4�޸�ְ����Ϣ	************" << endl;
	cout << "************	5����ְ����Ϣ	************" << endl;
	cout << "************	6���ձ������	************" << endl;
	cout << "************	7���������Ϣ	************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void Control::Manager::ExitSys()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//����ְ����Ϣ
void Control::Manager::addEmployee()
{
	int num;
	cout << "������Ҫ��ӵ�Ա������" << endl;
	cin >> num;

	for (int i = 0;i < num;i++)
	{
		int no;
		char name[64];
		int pos;
		cout << "������Ա�����" << endl;
		cin >> no;
		cout << "������Ա������" << endl;
		cin >> name;
		cout << "������Ա����λ	0�ϰ� 1���� 2��ͨԱ��" << endl;
		cin >> pos;

		switch (pos)
		{
		case 0:
			addEmployeeToArr(new Boss(no, name));
			break;
		case 1:
			addEmployeeToArr(new Emp::Manager(no, name));
			break;
		case 2:
			addEmployeeToArr(new GeneralEmployee(no, name));
			break;
		default:
			//���������쳣����ϰ��Ŀ�����쳣����
			break;
		}


	}
	
	//���ı������Ա����Ϣ
	writeData();
	//isFileEmpty = false;
	cout << "Ա����Ϣ��ӳɹ�" << endl;
	system("pause");
	system("cls");
}

void Control::Manager::addEmployeeToArr(Employee* ep)
{
	if (employeeNum == maxEmployee)//��Ҫ����
	{
		Employee** temp = new Employee * [maxEmployee + 1];
		for (int i = 0;i < maxEmployee;i++)
		{
			temp[i] = eArr[i];
		}
		delete[] eArr;

		maxEmployee++;
		temp[employeeNum] = ep;
		employeeNum++;

		eArr = temp;

	}
	else
	{
		eArr[employeeNum] = ep;
		employeeNum++;

		/*eArr[employeeNum - 1]->showInfo();
		cout << employeeNum << endl;*/
	}
}

void Control::Manager::writeData()
{
	ofstream ofs(FILEPATH, ios::out);
	ofs << employeeNum;
	ofs << endl;
	for (int i = 0;i < employeeNum;i++)
	{
		ofs << eArr[i]->m_No;
		ofs << " ";
		ofs << eArr[i]->m_Name;
		ofs << " ";
		ofs << (int)eArr[i]->m_Pos;
		ofs << endl;
	}
	ofs.close();
}
void Control::Manager::readData()
{
	//char buf[64];
	ifstream ifs(FILEPATH, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	if (ifs.peek() == EOF)
	{
		//cout << "�ļ�Ϊ��" << endl;
		ifs.close();
		return;
	}
	ifs >> employeeNum;
	//������Ĭ���������
	if (employeeNum > maxEmployee)
	{
		delete[] eArr;
		eArr = new Employee * [employeeNum]();
		maxEmployee = employeeNum;
	}
	for (int i = 0;i < employeeNum;i++)
	{
		int no;
		char name[64];
		int pos;
		ifs >> no;
		ifs >> name;
		ifs >> pos;
		switch (pos)
		{
		case 0:
			eArr[i] = new Boss(no, name);
			break;
		case 1:
			eArr[i] = new Emp::Manager(no, name);
			break;
		case 2:
			eArr[i] = new GeneralEmployee(no, name);
			break;
		default:
			//���������쳣����ϰ��Ŀ�����쳣����
			break;
		}
	}
	ifs.close();
}

void Control::Manager::showEmployee()
{
	if (isFileEmpty() == -1)
	{
		return;
	}
	for (int i = 0;i < employeeNum ;i++)
	{
		eArr[i]->showInfo();
	}
	system("pause");
	system("cls");
	return;
}

void Control::Manager::delEmployee()
{
	if (isFileEmpty() == -1)
	{
		return;
	}
	int index;
	index = findEmployee();
	if (index == -1)//������
	{
		//cout << "δ���ҵ��ñ�ŵ�Ա��" << endl;
	}
	else
	{
		delete eArr[index];
		for (int i = index;i < employeeNum;i++)
		{
			if (i == employeeNum - 1)
			{
				eArr[i] = nullptr;
			}
			else
			{
				eArr[i] = eArr[i + 1];
			}
		}
		employeeNum--;
		writeData();
		cout << "Ա��ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

int Control::Manager::checkEmployee(int no)
{
	int iRet = -1;
	for (int i = 0;i < employeeNum;i++)
	{
		if (eArr[i]->m_No == no)
		{
			iRet = i;
			return iRet;
		}
	}
	return iRet;
}

int Control::Manager::checkEmployee(const char* name)
{
	int iRet = -1;
	for (int i = 0;i < employeeNum;i++)
	{
		if (strcmp(eArr[i]->m_Name, name) == 0)//�ַ����Ա����޸�
		{
			iRet = i;
			return iRet;
		}
	}
	return iRet;
}

int Control::Manager::isFileEmpty()
{
	if (employeeNum <= 0)
	{
		cout << "Ա���б�Ϊ��" << endl;
		system("pause");
		system("cls");
		return -1;
	}
	return 1;
}

int Control::Manager::findEmployee()
{
	if (isFileEmpty() == -1)
	{
		return -1;
	}
	int input;
	int index = -1;
	cout << "���������Ա����Ϣ�ķ�ʽ 0��Ա����Ų���Ա�� 1��Ա����������Ա��" << endl;
	cin >> input;
	if (input == 0)
	{
		int no;
		cout << "������Ա�����" << endl;
		cin >> no;
		index = checkEmployee(no);

	}
	else
	{
		char name[64];
		cout << "������Ա������" << endl;
		cin >> name;
		index = checkEmployee(name);
	}
	if (index == -1)
	{
		cout << "δ���ҵ���������Ա��" << endl;
	}
	else
	{
		cout << "���ҵ���Ա����Ϣ��" << endl;
		eArr[index]->showInfo();
	}


	return index;
}

void Control::Manager::changeEmployeeInfo()
{
	if (isFileEmpty() == -1)
	{
		return;
	}
	int input;
	int index;
	index = findEmployee();
	/*cout << "�������޸�Ա����Ϣ�ķ�ʽ 0��Ա����Ų���Ա�� 1��Ա����������Ա��" << endl;
	cin >> input;
	if (input == 0)
	{
		int no;
		cout << "������Ա�����" << endl;
		cin >> no;
		index = checkEmployee(no);
		
	}
	else
	{
		char name[64];
		cout << "������Ա������" << endl;
		cin >> name;
		index = checkEmployee(name);
	}*/
	if (index == -1)
	{
		//cout << "δ���ҵ���������Ա��" << endl;
	}
	else
	{
		int no;
		char name[64];
		int pos;
		cout << "�������µ�Ա�����" << endl;
		cin >> no;
		cout << "�������µ�Ա������" << endl;
		cin >> name;
		cout << "�������µ�Ա����λ	0�ϰ� 1���� 2��ͨԱ��" << endl;
		cin >> pos;

		delete eArr[index];
		switch (pos)
		{
		case 0:
			eArr[index] = new Boss(no, name);
			break;
		case 1:
			eArr[index] = new Emp::Manager(no, name);
			break;
		case 2:
			eArr[index] = new GeneralEmployee(no, name);
			break;
		default:
			//���������쳣����ϰ��Ŀ�����쳣����
			break;
		}

		cout << "Ա����Ϣ�޸ĳɹ�" << endl;

		writeData();
	}
	system("pause");
	system("cls");
}

void Control::Manager::sortEmployee()
{
	if (isFileEmpty() == -1)
	{
		return;
	}
	int input;
	cout << "����������ʽ" << endl;
	cout << "0������������� 1����Ž�������" << endl;
	cin >> input;
	//ð������
	/*if (input == 0)
	{
		for (int i = 0;i < employeeNum - 1;i++)
		{
			for (int j = 0;j < employeeNum - 1 - i;j++)
			{
				if (eArr[j]->m_No > eArr[j + 1]->m_No)
				{
					Employee* temp = eArr[j];
					eArr[j] = eArr[j + 1];
					eArr[j + 1] = temp;
				}
			}
		}
		
	}
	else
	{
		for (int i = 0;i < employeeNum - 1;i++)
		{
			for (int j = 0;j < employeeNum - 1 - i;j++)
			{
				if (eArr[j]->m_No < eArr[j + 1]->m_No)
				{
					Employee* temp = eArr[j];
					eArr[j] = eArr[j + 1];
					eArr[j + 1] = temp;
				}
			}
		}
	}*/
	//ѡ������
	for (int i = 0;i < employeeNum;i++)
	{
		int minOrMaxIndex = i;
		for (int j = i + 1;j < employeeNum;j++)
		{
			if (input == 0)
			{
				if (eArr[minOrMaxIndex]->m_No > eArr[j]->m_No)
				{
					minOrMaxIndex = j;
				}
			}
			else
			{
				if (eArr[minOrMaxIndex]->m_No < eArr[j]->m_No)
				{
					minOrMaxIndex = j;
				}
			}
		}

		if (minOrMaxIndex != i)
		{
			Employee* temp = eArr[i];
			eArr[i] = eArr[minOrMaxIndex];
			eArr[minOrMaxIndex] = temp;
		}
	}


	writeData();
	cout << "�������" << endl;
	system("pause");
	system("cls");
}

void Control::Manager::clearEmployee()
{
	int input;
	cout << "ȷ�����������Ϣ��" << endl;
	cout << "0ȷ�� 1ȡ��" << endl;
	cin >> input;
	if (input == 0)
	{
		for (int i = 0;i < employeeNum;i++)
		{
			delete eArr[i];
			eArr[i] = nullptr;
		}

		employeeNum = 0;
		maxEmployee = 10;
		delete[] eArr;
		eArr = new Employee * [maxEmployee]();
		writeData();
		cout << "���������Ϣ�ɹ�" << endl;
	}
	else
	{
		cout << "������ȡ��" << endl;
	}
	system("pause");
	system("cls");
}

//��ʾ�˵�
//int showMenu()
//{
//	int iret = -1;
//
//	cout << "********************************************" << endl;
//	cout << "************��ӭʹ��Ա������ϵͳ************" << endl;
//	cout << "************	0�˳�����ϵͳ	************" << endl;
//	cout << "************	1����ְ����Ϣ	************" << endl;
//	cout << "************	2��ʾְ����Ϣ	************" << endl;
//	cout << "************	3ɾ����ְְ��	************" << endl;
//	cout << "************	4�޸�ְ����Ϣ	************" << endl;
//	cout << "************	5����ְ����Ϣ	************" << endl;
//	cout << "************	6���ձ������	************" << endl;
//	cout << "************	7���������Ϣ	************" << endl;
//	cout << "********************************************" << endl;
//	cin >> iret;
//	//cout << iret << endl;
//	return iret;
//}

