#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define MAX 1000


//联系人结构体
struct Contact
{
	string name;
	string gender;
	int age;
	int tel;
	string address;
};
//struct Contact;

int ShowMenu();
int AddContact(Contact** addressBook, int* ctaNum);
void ShowContact(Contact* addressBook, int* ctaNum, int showCtaNO = -1);
void DelContact(Contact** addressBook, int* ctaNum);
int FindContact(Contact* addressBook, int* ctaNum ,bool flag = true);
int CheckAddressBook(int ctaNum);//检查通讯录是否为空并提示
void EditContact(Contact** addressBook, int* ctaNum);
void CleanAddressBook(Contact** addressBook, int* ctaNum);

int main()
{
	int input = 0;
	int contactNum = 0;
	Contact* addressBook = new Contact[1];

	while (1)
	{
		input = ShowMenu();

		switch (input)
		{
		case 1://添加联系人
			AddContact(&addressBook, &contactNum);
			break;
		case 2://显示联系人
			if (!CheckAddressBook(contactNum)) break;
			ShowContact(addressBook, &contactNum);
			break;
		case 3://删除联系人
			if (!CheckAddressBook(contactNum)) break;
			DelContact(&addressBook, &contactNum);
			break;
		case 4://查找联系人
			if (!CheckAddressBook(contactNum)) break;
			FindContact(addressBook, &contactNum);
			break;
		case 5://修改联系人
			if (!CheckAddressBook(contactNum)) break;
			EditContact(&addressBook, &contactNum);
			break;
		case 6://清空联系人
			CleanAddressBook(&addressBook, &contactNum);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}


//显示菜单
int ShowMenu()
{
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 29;j++)
		{
			if (i > 0 && i < 8)
			{
				if (j < 5)
				{
					cout << "*";
				}
				else if (j == 5)
				{
					cout << "\t";
					switch (i)
					{
					case 1:
						cout << "1、添加联系人";
						break;
					case 2:
						cout << "2、显示联系人";
						break;
					case 3:
						cout << "3、删除联系人";
						break;
					case 4:
						cout << "4、查找联系人";
						break;
					case 5:
						cout << "5、修改联系人";
						break;
					case 6:
						cout << "6、清空联系人";
						break;
					case 7:
						cout << "0、退出通讯录";
						break;
					}
					cout << "\t";
					j = 24;
				}
				if (j > 23)
				{
					cout << "*";
				}
			}
			else
			{
				cout << "*";
			}

		}
		cout << endl;
		
	}

	int input = 0;
	std::cin >> input;

	return input;
}



//添加联系人 cta通讯录数组，需按ctaNum 传入的联系人数量动态分配内存 ctaNum(当前通讯录拥有联系人数量)从0开始计数
int AddContact(Contact ** addressBook,int * ctaNum)
{
	int ret = 1;//函数运行结果 0 失败 1成功

	string name = "";
	string gender = "";
	int age = 0;
	int tel = 0;
	string address = "";

	if ((*ctaNum) > MAX)
	{
		cout << "通讯录已满，无法添加!" << endl;
		return 0;
	}

	cout << "请输入联系人姓名：" << endl;
	if (!(cin >> name)) {
		ret = 0;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		cout << "请输入联系人性别：" << endl;
		if (!(cin >> gender)) {
			ret = 0;
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			cout << "请输入联系人年龄：" << endl;
			if (!(cin >> age)) {
				ret = 0;
				cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				cout << "请输入联系人电话号码：" << endl;
				if (!(cin >> tel)) {
					ret = 0;
					cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else
				{
					cout << "请输入联系人家庭住址：" << endl;
					if (!(cin >> address)) {
						ret = 0;
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
				}
			}
		}
	}
	

	if (ret)
	{
		//如果添加成功，申请内存，存储联系人
		/*Contact* newAddressBook = (Contact*)realloc(addressBook, sizeof(Contact) * (*ctaNum));
		addressBook = newAddressBook;*/

		Contact* newAddressBook = new Contact[(*ctaNum) + 1];
		for (int i = 0; i < *ctaNum;i++) newAddressBook[i] = (*addressBook)[i];
		newAddressBook[*ctaNum].name = name;
		newAddressBook[*ctaNum].gender = gender;
		newAddressBook[*ctaNum].age = age;
		newAddressBook[*ctaNum].tel = tel;
		newAddressBook[*ctaNum].address = address;
		delete[] *addressBook;
		*addressBook = newAddressBook;
		//delete[] newAddressBook;
		*ctaNum += 1;
		cout << "成功添加联系人" << name << endl;
		system("pause");
		system("cls");
		//ShowContact(*addressBook, ctaNum);
	}
	else
	{
		//cin.clear();
		int input = 0;
		cout << "输入联系人数据有误，输入1重新输入联系人数据，输入0回到主菜单" << endl;
		//cin >> input;
		if (!(cin >> input)) {
			ret = 0;
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("pause");
			system("cls");
			return ret;
		}
		else if (input == 1)
		{
			AddContact(addressBook, ctaNum);
		}
		else
		{
			ret = 0;
			system("pause");
			system("cls");
			return ret;
		}
	}
	return ret;
}

//显示联系人 showCtaNO默认-1，打印所有人信息 ， 其他时候打印该下标人的信息
void ShowContact(Contact* addressBook, int* ctaNum, int showCtaNO)
{

	cout << "姓名：\t" << "性别：\t" << "年龄：\t" << "电话：\t" << "住址：\t" << endl << endl;
	if (showCtaNO == -1)
	{
		for (int i = 0;i < *ctaNum;i++)
		{
			cout << addressBook[i].name << "\t" << addressBook[i].gender << "\t" << addressBook[i].age << "\t"
				<< addressBook[i].tel << "\t" << addressBook[i].address << "\t" << endl;
		}
		system("pause");
		system("cls");
	}
	else
	{
		cout << addressBook[showCtaNO].name << "\t" << addressBook[showCtaNO].gender << "\t" << addressBook[showCtaNO].age << "\t"
			<< addressBook[showCtaNO].tel << "\t" << addressBook[showCtaNO].address << "\t" << endl;
	}
}

//查找联系人 返回查找到的联系人的下标 flag是否显示任意键继续 默认true显示 false 不显示
int FindContact(Contact* addressBook, int* ctaNum,bool flag)
{

	string name = "";
	cout << "请输入联系人姓名" << endl;
	cin >> name;

	int ret = -1;
	Contact contact;
	for (int i = 0;i < *ctaNum;i++)
	{
		if (addressBook[i].name == name)
		{
			contact = addressBook[i];
			ShowContact(addressBook, ctaNum, i);
			if (flag)
			{
				system("pause");
				system("cls");
			}
			ret = i;
			return ret;
		}
	}
	if (ret == -1)
	{
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
		return ret;
	}
	
	return ret;
}

//删除联系人
void DelContact(Contact** addressBook, int* ctaNum)
{
	int showCtaNO = -1;
	int input = 0;

	showCtaNO = FindContact(*addressBook, ctaNum, false);
	if (showCtaNO != -1)//查找到联系人
	{
		cout << "是否删除该联系人 0取消删除 1确认删除" << endl;
		cin >> input;
		if (input == 0)//取消删除
		{
			system("pause");
			system("cls");
			return;
		}
		else//确认删除
		{
			//需要注意边界i < *ctaNum -1，最大只能访问到*ctaNum的元素，这个地方必须-1，要不然会访问到*ctaNum+1导致异常报错
			for (int i = showCtaNO ;i < *ctaNum -1;i++)
			{
				(*addressBook)[i] = (*addressBook)[i + 1];//超范围会报错
			}
			Contact cat;
			(*addressBook)[*ctaNum-1] = cat;
			(*ctaNum)--;
			cout << "删除成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	//未查找到联系人直接返回即可
	return;

}

//检查通讯录是否为空并提示
int CheckAddressBook(int ctaNum)
{

	if (ctaNum == 0)
	{
		cout << "通讯录还没有联系人" << endl;
		system("pause");
		system("cls");
		return 0;
	}
	return 1;
}

//修改联系人
void EditContact(Contact** addressBook, int* ctaNum) 
{
	int showCtaNO = -1;
	int input = 0;

	showCtaNO = FindContact(*addressBook, ctaNum, false);
	if (showCtaNO != -1)//查找到联系人
	{
		cout << "是否确认要修改该联系人信息 0取消修改 1确认修改" << endl;
		cin >> input;

		if (input == 0)
		{
			system("pause");
			system("cls");
			return ;
		}
		else
		{
			int ret = 1;

			string name = "";
			string gender = "";
			int age = 0;
			int tel = 0;
			string address = "";

			cout << "请输入联系人姓名：" << endl;
			if (!(cin >> name)) {
				ret = 0;
				cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				cout << "请输入联系人性别：" << endl;
				if (!(cin >> gender)) {
					ret = 0;
					cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else
				{
					cout << "请输入联系人年龄：" << endl;
					if (!(cin >> age)) {
						ret = 0;
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					else
					{
						cout << "请输入联系人电话号码：" << endl;
						if (!(cin >> tel)) {
							ret = 0;
							cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else
						{
							cout << "请输入联系人家庭住址：" << endl;
							if (!(cin >> address)) {
								ret = 0;
								cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							}
						}
					}
				}
			}

			if (ret)//输入信息无误
			{
				(*addressBook)[showCtaNO].name = name;
				(*addressBook)[showCtaNO].gender = gender;
				(*addressBook)[showCtaNO].age = age;
				(*addressBook)[showCtaNO].tel = tel;
				(*addressBook)[showCtaNO].address = address;
				cout << "修改成功" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				//cin.clear();
				int input = 0;
				cout << "输入联系人数据有误，输入1重新输入联系人数据，输入0回到主菜单" << endl;
				//cin >> input;
				if (!(cin >> input)) {
					ret = 0;
					cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					system("pause");
					system("cls");
					return ;
				}
				else if (input == 1)
				{
					EditContact(addressBook, ctaNum);
				}
				else
				{
					ret = 0;
					system("pause");
					system("cls");
					return ;
				}
			}

		}
	}

	return;

}

//清空联系人
void CleanAddressBook(Contact** addressBook, int* ctaNum)
{
	int input = 0;

	cout << "确认清空通讯录吗？ 0取消 1确认" << endl;
	cin >> input;

	if (input == 1)//确认
	{
		delete[] *addressBook;
		*addressBook = new Contact[1];
		*ctaNum = 0;
		cout << "通讯录已清空" << endl;
		system("pause");
		system("cls");
		return;
	}
	else//取消
	{
		system("pause");
		system("cls");
		return;
	}
}




