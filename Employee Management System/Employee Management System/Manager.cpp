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
//显示菜单
void Control::Manager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "************欢迎使用员工管理系统************" << endl;
	cout << "************	0退出管理系统	************" << endl;
	cout << "************	1增加职工信息	************" << endl;
	cout << "************	2显示职工信息	************" << endl;
	cout << "************	3删除离职职工	************" << endl;
	cout << "************	4修改职工信息	************" << endl;
	cout << "************	5查找职工信息	************" << endl;
	cout << "************	6按照编号排序	************" << endl;
	cout << "************	7清空所有信息	************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void Control::Manager::ExitSys()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//增加职工信息
void Control::Manager::addEmployee()
{
	int num;
	cout << "请输入要添加的员工数量" << endl;
	cin >> num;

	for (int i = 0;i < num;i++)
	{
		int no;
		char name[64];
		int pos;
		cout << "请输入员工编号" << endl;
		cin >> no;
		cout << "请输入员工姓名" << endl;
		cin >> name;
		cout << "请输入员工岗位	0老板 1经理 2普通员工" << endl;
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
			//输入数据异常，练习项目不做异常处理
			break;
		}


	}
	
	//向文本中添加员工信息
	writeData();
	//isFileEmpty = false;
	cout << "员工信息添加成功" << endl;
	system("pause");
	system("cls");
}

void Control::Manager::addEmployeeToArr(Employee* ep)
{
	if (employeeNum == maxEmployee)//需要扩列
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
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	if (ifs.peek() == EOF)
	{
		//cout << "文件为空" << endl;
		ifs.close();
		return;
	}
	ifs >> employeeNum;
	//处理超过默认最大数量
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
			//输入数据异常，练习项目不做异常处理
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
	if (index == -1)//不存在
	{
		//cout << "未查找到该编号的员工" << endl;
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
		cout << "员工删除成功" << endl;
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
		if (strcmp(eArr[i]->m_Name, name) == 0)//字符串对比需修改
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
		cout << "员工列表为空" << endl;
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
	cout << "请输入查找员工信息的方式 0按员工编号查找员工 1按员工姓名查找员工" << endl;
	cin >> input;
	if (input == 0)
	{
		int no;
		cout << "请输入员工编号" << endl;
		cin >> no;
		index = checkEmployee(no);

	}
	else
	{
		char name[64];
		cout << "请输入员工姓名" << endl;
		cin >> name;
		index = checkEmployee(name);
	}
	if (index == -1)
	{
		cout << "未查找到该姓名的员工" << endl;
	}
	else
	{
		cout << "查找到了员工信息：" << endl;
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
	/*cout << "请输入修改员工信息的方式 0按员工编号查找员工 1按员工姓名查找员工" << endl;
	cin >> input;
	if (input == 0)
	{
		int no;
		cout << "请输入员工编号" << endl;
		cin >> no;
		index = checkEmployee(no);
		
	}
	else
	{
		char name[64];
		cout << "请输入员工姓名" << endl;
		cin >> name;
		index = checkEmployee(name);
	}*/
	if (index == -1)
	{
		//cout << "未查找到该姓名的员工" << endl;
	}
	else
	{
		int no;
		char name[64];
		int pos;
		cout << "请输入新的员工编号" << endl;
		cin >> no;
		cout << "请输入新的员工姓名" << endl;
		cin >> name;
		cout << "请输入新的员工岗位	0老板 1经理 2普通员工" << endl;
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
			//输入数据异常，练习项目不做异常处理
			break;
		}

		cout << "员工信息修改成功" << endl;

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
	cout << "请输入排序方式" << endl;
	cout << "0按编号升序排序 1按编号降序排序" << endl;
	cin >> input;
	//冒泡排序
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
	//选择排序
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
	cout << "排序完成" << endl;
	system("pause");
	system("cls");
}

void Control::Manager::clearEmployee()
{
	int input;
	cout << "确认清空所有信息吗？" << endl;
	cout << "0确认 1取消" << endl;
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
		cout << "清空所有信息成功" << endl;
	}
	else
	{
		cout << "操作已取消" << endl;
	}
	system("pause");
	system("cls");
}

//显示菜单
//int showMenu()
//{
//	int iret = -1;
//
//	cout << "********************************************" << endl;
//	cout << "************欢迎使用员工管理系统************" << endl;
//	cout << "************	0退出管理系统	************" << endl;
//	cout << "************	1增加职工信息	************" << endl;
//	cout << "************	2显示职工信息	************" << endl;
//	cout << "************	3删除离职职工	************" << endl;
//	cout << "************	4修改职工信息	************" << endl;
//	cout << "************	5查找职工信息	************" << endl;
//	cout << "************	6按照编号排序	************" << endl;
//	cout << "************	7清空所有信息	************" << endl;
//	cout << "********************************************" << endl;
//	cin >> iret;
//	//cout << iret << endl;
//	return iret;
//}

