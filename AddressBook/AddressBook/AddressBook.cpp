#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define MAX 1000


//��ϵ�˽ṹ��
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
int CheckAddressBook(int ctaNum);//���ͨѶ¼�Ƿ�Ϊ�ղ���ʾ
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
		case 1://�����ϵ��
			AddContact(&addressBook, &contactNum);
			break;
		case 2://��ʾ��ϵ��
			if (!CheckAddressBook(contactNum)) break;
			ShowContact(addressBook, &contactNum);
			break;
		case 3://ɾ����ϵ��
			if (!CheckAddressBook(contactNum)) break;
			DelContact(&addressBook, &contactNum);
			break;
		case 4://������ϵ��
			if (!CheckAddressBook(contactNum)) break;
			FindContact(addressBook, &contactNum);
			break;
		case 5://�޸���ϵ��
			if (!CheckAddressBook(contactNum)) break;
			EditContact(&addressBook, &contactNum);
			break;
		case 6://�����ϵ��
			CleanAddressBook(&addressBook, &contactNum);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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


//��ʾ�˵�
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
						cout << "1�������ϵ��";
						break;
					case 2:
						cout << "2����ʾ��ϵ��";
						break;
					case 3:
						cout << "3��ɾ����ϵ��";
						break;
					case 4:
						cout << "4��������ϵ��";
						break;
					case 5:
						cout << "5���޸���ϵ��";
						break;
					case 6:
						cout << "6�������ϵ��";
						break;
					case 7:
						cout << "0���˳�ͨѶ¼";
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



//�����ϵ�� ctaͨѶ¼���飬�谴ctaNum �������ϵ��������̬�����ڴ� ctaNum(��ǰͨѶ¼ӵ����ϵ������)��0��ʼ����
int AddContact(Contact ** addressBook,int * ctaNum)
{
	int ret = 1;//�������н�� 0 ʧ�� 1�ɹ�

	string name = "";
	string gender = "";
	int age = 0;
	int tel = 0;
	string address = "";

	if ((*ctaNum) > MAX)
	{
		cout << "ͨѶ¼�������޷����!" << endl;
		return 0;
	}

	cout << "��������ϵ��������" << endl;
	if (!(cin >> name)) {
		ret = 0;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		cout << "��������ϵ���Ա�" << endl;
		if (!(cin >> gender)) {
			ret = 0;
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			cout << "��������ϵ�����䣺" << endl;
			if (!(cin >> age)) {
				ret = 0;
				cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				cout << "��������ϵ�˵绰���룺" << endl;
				if (!(cin >> tel)) {
					ret = 0;
					cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else
				{
					cout << "��������ϵ�˼�ͥסַ��" << endl;
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
		//�����ӳɹ��������ڴ棬�洢��ϵ��
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
		cout << "�ɹ������ϵ��" << name << endl;
		system("pause");
		system("cls");
		//ShowContact(*addressBook, ctaNum);
	}
	else
	{
		//cin.clear();
		int input = 0;
		cout << "������ϵ��������������1����������ϵ�����ݣ�����0�ص����˵�" << endl;
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

//��ʾ��ϵ�� showCtaNOĬ��-1����ӡ��������Ϣ �� ����ʱ���ӡ���±��˵���Ϣ
void ShowContact(Contact* addressBook, int* ctaNum, int showCtaNO)
{

	cout << "������\t" << "�Ա�\t" << "���䣺\t" << "�绰��\t" << "סַ��\t" << endl << endl;
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

//������ϵ�� ���ز��ҵ�����ϵ�˵��±� flag�Ƿ���ʾ��������� Ĭ��true��ʾ false ����ʾ
int FindContact(Contact* addressBook, int* ctaNum,bool flag)
{

	string name = "";
	cout << "��������ϵ������" << endl;
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
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
		return ret;
	}
	
	return ret;
}

//ɾ����ϵ��
void DelContact(Contact** addressBook, int* ctaNum)
{
	int showCtaNO = -1;
	int input = 0;

	showCtaNO = FindContact(*addressBook, ctaNum, false);
	if (showCtaNO != -1)//���ҵ���ϵ��
	{
		cout << "�Ƿ�ɾ������ϵ�� 0ȡ��ɾ�� 1ȷ��ɾ��" << endl;
		cin >> input;
		if (input == 0)//ȡ��ɾ��
		{
			system("pause");
			system("cls");
			return;
		}
		else//ȷ��ɾ��
		{
			//��Ҫע��߽�i < *ctaNum -1�����ֻ�ܷ��ʵ�*ctaNum��Ԫ�أ�����ط�����-1��Ҫ��Ȼ����ʵ�*ctaNum+1�����쳣����
			for (int i = showCtaNO ;i < *ctaNum -1;i++)
			{
				(*addressBook)[i] = (*addressBook)[i + 1];//����Χ�ᱨ��
			}
			Contact cat;
			(*addressBook)[*ctaNum-1] = cat;
			(*ctaNum)--;
			cout << "ɾ���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	//δ���ҵ���ϵ��ֱ�ӷ��ؼ���
	return;

}

//���ͨѶ¼�Ƿ�Ϊ�ղ���ʾ
int CheckAddressBook(int ctaNum)
{

	if (ctaNum == 0)
	{
		cout << "ͨѶ¼��û����ϵ��" << endl;
		system("pause");
		system("cls");
		return 0;
	}
	return 1;
}

//�޸���ϵ��
void EditContact(Contact** addressBook, int* ctaNum) 
{
	int showCtaNO = -1;
	int input = 0;

	showCtaNO = FindContact(*addressBook, ctaNum, false);
	if (showCtaNO != -1)//���ҵ���ϵ��
	{
		cout << "�Ƿ�ȷ��Ҫ�޸ĸ���ϵ����Ϣ 0ȡ���޸� 1ȷ���޸�" << endl;
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

			cout << "��������ϵ��������" << endl;
			if (!(cin >> name)) {
				ret = 0;
				cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				cout << "��������ϵ���Ա�" << endl;
				if (!(cin >> gender)) {
					ret = 0;
					cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else
				{
					cout << "��������ϵ�����䣺" << endl;
					if (!(cin >> age)) {
						ret = 0;
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					else
					{
						cout << "��������ϵ�˵绰���룺" << endl;
						if (!(cin >> tel)) {
							ret = 0;
							cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else
						{
							cout << "��������ϵ�˼�ͥסַ��" << endl;
							if (!(cin >> address)) {
								ret = 0;
								cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							}
						}
					}
				}
			}

			if (ret)//������Ϣ����
			{
				(*addressBook)[showCtaNO].name = name;
				(*addressBook)[showCtaNO].gender = gender;
				(*addressBook)[showCtaNO].age = age;
				(*addressBook)[showCtaNO].tel = tel;
				(*addressBook)[showCtaNO].address = address;
				cout << "�޸ĳɹ�" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				//cin.clear();
				int input = 0;
				cout << "������ϵ��������������1����������ϵ�����ݣ�����0�ص����˵�" << endl;
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

//�����ϵ��
void CleanAddressBook(Contact** addressBook, int* ctaNum)
{
	int input = 0;

	cout << "ȷ�����ͨѶ¼�� 0ȡ�� 1ȷ��" << endl;
	cin >> input;

	if (input == 1)//ȷ��
	{
		delete[] *addressBook;
		*addressBook = new Contact[1];
		*ctaNum = 0;
		cout << "ͨѶ¼�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	else//ȡ��
	{
		system("pause");
		system("cls");
		return;
	}
}




