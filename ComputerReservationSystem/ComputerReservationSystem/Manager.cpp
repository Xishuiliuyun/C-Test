#include"Manager.h"



namespace manager
{
	//�����࣬���ڶ�����ϵͳ���й���
	//��Ҫ��ϵͳ��������ʼ�����ļ���д����¼�˳�����Ա���Ƶȹ���

	//����
	Control::Control()
	{
		init();
	}

	//��ʼ��
	void Control::init()
	{
		//��ȡ����
		ReadData();
	}

	//��ʾ���˵�  �����û�ѡ����
	int Control::showMainMenu()
	{
		cout << "============��ӭʹ�û���ԤԼϵͳ============\n" << endl;
		cout << "�������������" << endl;
		cout << "               ---------------------------------------" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              1ѧ������              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              2��    ʦ              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              3�� �� Ա              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              0��    ��              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               ---------------------------------------" << endl;
		cout << "����������ѡ��" << endl;
		cout << endl;

		int select;
		cin >> select;

		return select;
	}

	//��¼ϵͳ
	bool Control::loginSystem(Identity id)
	{
		//��¼ǰ����
		

		bool logRet = false;
		Manager* mp = nullptr;//ͨ��ָ��ķ�ʽ����ȡ�����еĶ��������
		switch (id)
		{
		case manager::Identity::Manager:
			logRet = logVerify_Manager(mp);
			if (logRet)//��¼�ɹ�
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				mp->managerControl(m_data,*this);
				//cout << mp->password << endl;
				//mp->password = 100;
				//cout << m_data.mm[0].password << endl;
			}
			else cout << "��¼ʧ��" << endl;//��¼ʧ��
			break;
		case manager::Identity::Teacher:
			logRet = logVerify_Teacher();
			break;
		case manager::Identity::Student:
			logRet = logVerify_Student();
			break;
		default:
			break;
		}

		return logRet;
	}

	//��¼��֤
	//�û�����������֤
	//cͨ��ָ�����õķ�ʽ���룬�ں������޸�ָ���ָ��ָ�������еĶ���
	template<typename T>
	bool Control::verify(Identity id,string userName,string password, T*& c, int no)
	{
		bool verifyRet = false;
		map<int, Manager>& mm = m_data.mm;

		switch (id)
		{
		case manager::Identity::Manager:
			if (no != -1)
			{
				map<int, Manager>::iterator it = mm.find(no);
				if (it != mm.end())//�ҵ��û�
				{
					if (it->second.userName == userName && it->second.password == password)//��֤ͨ��
					{
						verifyRet = true;
						c = &(it->second);
					}
				}
				else verifyRet = false;
			}
			else//����mm�е�userName
			{
				//Lambda���ʽ[&](pair<const int,Manager>& p)
				//[&]��ʾ�Զ����÷�ʽ ��������ʹ�õĲ���
				//(pair<const int,Manager>& p)//��ҪҪ��&���õķ�ʽ�������еĶ����룬�����ǿ�����ʱ����
				//��pair<>�У�������const ����int���������Ͳ�һ�£��ᵼ�±���
				for_each(mm.begin(), mm.end(), [&](pair<const int,Manager>& p) {
					if (p.second.userName == userName && p.second.password == password)//��֤ͨ��
					{
						verifyRet = true;
						c = &(p.second);
					}
				});
			}
			break;
		case manager::Identity::Teacher:

			break;
		case manager::Identity::Student:

			break;
		default:
			break;
		}


		return verifyRet;
	}
	//������
	bool Control::logVerify_Manager(Manager*& m)
	{
		bool logRet = false;
		string userName;
		string password;
		cout << "�������û�����" << endl;
		cin >> userName;
		cout << "���������룺" << endl;
		cin >> password;

		logRet = verify(Identity::Manager,userName,password, m);
		//logRet = verify(Identity::Manager,userName,password, m,0);

		return logRet;
	}
	//��ʦ
	bool Control::logVerify_Teacher()
	{
		bool logRet = false;


		return logRet;
	}
	//ѧ��
	bool Control::logVerify_Student()
	{
		bool logRet = false;


		return logRet;
	}

	//��ȡ����(�����ļ������һ���Զ�ȡ��)
	void Control::ReadData()
	{
		ReadData_Manager();
		ReadData_Teacher();
		ReadData_Student();
		ReadData_Order();
		ReadData_ComputerRoom();
	}
	void Control::ReadData_Manager()
	{
		ifstream ifs;
		ofstream ofs;
		string path;
		path = string(FILE_PATH) + MANAGER_FILE;
		//cout << path << endl;
		ifs.open(path);

		if (!ifs.is_open())//�ļ�������
		{
			//cout << "�ļ�������" << endl;
			//���ó�ʼ����Ա�˺�
			ofs.open(path, ios::out);
			ofs << "1 admin 123456" << endl;
			ofs.close();
			m_data.mm.insert(pair<int, Manager>(1, Manager(1, "admin", "123456")));
			return;
		}

		if (ifs.peek() == ifstream::traits_type::eof())//�ļ�Ϊ��
		{
			//cout << "�ļ�Ϊ��" << endl;
			//���ó�ʼ����Ա�˺�
			ofs.open(path, ios::out);
			ofs << "1 admin 123456" << endl;
			ofs.close();
			m_data.mm.insert(pair<int, Manager>(1, Manager(1, "admin", "123456")));
			return;
		}
		else
		{
			string line;
			int managerID = 0;
			string userName;
			string password;
			while (getline(ifs, line))
			{
				//cout << line << endl;
				istringstream iss(line);
				iss >> managerID >> userName >> password;
				//cout << managerID << "\n" << userName << "\n" << password << endl;
				m_data.mm.insert(pair<int, Manager>(managerID, Manager(managerID, userName, password)));
			}
		}

	}
	void Control::ReadData_Teacher()
	{
		ifstream ifs;
		ofstream ofs;
		string path;
		path = string(FILE_PATH) + TEACHER_FILE;
		//cout << path << endl;
		ifs.open(path);

		if (!ifs.is_open())//�ļ�������
		{
			//cout << "�ļ�������" << endl;
			return;
		}

		if (ifs.peek() == ifstream::traits_type::eof())//�ļ�Ϊ��
		{
			//cout << "�ļ�Ϊ��" << endl;
			return;
		}
		else
		{
			string line;
			int teacherID = 0;
			string userName;
			string password;
			while (getline(ifs, line))
			{
				//cout << line << endl;
				istringstream iss(line);
				iss >> teacherID >> userName >> password;
				//cout << managerID << "\n" << userName << "\n" << password << endl;
				m_data.mt.insert(pair<int, Teacher>(teacherID, Teacher(teacherID, userName, password)));
			}
		}
	}
	void Control::ReadData_Student()
	{
		ifstream ifs;
		ofstream ofs;
		string path;
		path = string(FILE_PATH) + STUDENT_FILE;
		//cout << path << endl;
		ifs.open(path);

		if (!ifs.is_open())//�ļ�������
		{
			//cout << "�ļ�������" << endl;
			return;
		}

		if (ifs.peek() == ifstream::traits_type::eof())//�ļ�Ϊ��
		{
			//cout << "�ļ�Ϊ��" << endl;
			return;
		}
		else
		{
			string line;
			int studentID = 0;
			string userName;
			string password;
			while (getline(ifs, line))
			{
				//cout << line << endl;
				istringstream iss(line);
				iss >> studentID >> userName >> password;
				//cout << managerID << "\n" << userName << "\n" << password << endl;
				m_data.ms.insert(pair<int, Student>(studentID, Student(studentID, userName, password)));
			}
		}
	}
	void Control::ReadData_Order()
	{

	}
	void Control::ReadData_ComputerRoom()
	{

	}

	//д������ д��ʱ��Ϊû���ļ�Ҳ�ᴴ���ļ� ������ʧ���ж�
	void Control::WriteData(string path, string content)
	{
		ofstream ofs;
		ofs.open(path, ios::app);
		ofs << content << endl;
		ofs.close();
	}

	//ɾ������
	void Control::DelData(const string& path, const string& content)//ͨ��һ�����ı�ɾ��
	{
		string oPath = string(FILE_PATH) + "temp.txt";
		ifstream ifs(path);
		ofstream ofs(oPath);
		string line;

		if (!ifs.is_open())
		{
			cout << "�ļ���ʧ��" << endl;
			return;
		}

		while (getline(ifs, line))
		{
			if (line.find(content) == string::npos)//
			{
				ofs << line << endl;
			}
		}

		ifs.close();
		ofs.close();
		fs::remove(path);
		fs::rename(oPath, path);
	}
	void Control::DelData(const string& path, int id)//ͨ�����ɾ��
	{

	}

	//�˳�ϵͳ
	void Control::exitSystem()
	{
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		exit(0);
	}

	//����
	Control::~Control()
	{

	}






	//�������࣬ʵ��ϵͳ�еĹ�����Ա��ݼ��书��
	//��Ҫ�� ��ɾ�Ĳ��˺�(��ʦ��ѧ��)����ɾ�Ĳ��������ɾ�Ĳ�ԤԼ��¼(����ͨ�������鿴��¼)���˳���¼�ȹ���
	ostream& operator<<(ostream& ostr, const Manager& c)
	{
		return cout << "���:" << c.managerID << "  �û���:" << c.userName << "  ���룺" << c.password /*<< endl*/;
	}
	
	Manager::Manager() {}

	Manager::Manager(int id,string name,string psw)
	{
		this->managerID = id;
		this->userName = name;
		this->password = psw;
	}

	//Manager��Ĳ˵���ʾ�����ܿ���
	void Manager::managerControl(MyData& data, Control& c)
	{
		
		while (1)
		{
			int select = -1;
			select = managerShowMenu();
			switch (select)
			{
			case 0://ע����¼
				logOut();
				return;
				break;
			case 1://�����˺�
				system("cls");
				accountControl(data,c);
				break;
			case 2://��������
				system("cls");
				ComputerRoomControl(data, c);
				break;
			case 3://����ԤԼ��¼
				system("cls");
				orderControl(data, c);
				break;
			default:
				system("cls");
				break;
			}

			system("cls");
		}
		
	}

	//�˵���ʾ
	int Manager::managerShowMenu()
	{
		cout << "��ӭ����Ա��"<<userName<<"��¼" << endl;
		cout << "               ---------------------------------------" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              1�����˺�              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              2��������              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              3����ԤԼ��¼          |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              0ע����¼              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               ---------------------------------------" << endl;
		cout << "����������ѡ��" << endl;
		cout << endl;

		int select;
		cin >> select;

		return select;
	}

	//ע����¼
	void Manager::logOut()
	{
		cout << "ע���ɹ�" << endl;
		system("pause");
	}
	//�����˺�
	void Manager::accountControl(MyData& data, Control& c)
	{

		while (1)
		{
			int select = -1;
			select = showAccountControlMenu();
			switch (select)
			{
			case 0://����
				return;
				break;
			case 1://����˺�
				addAccount(data, c);
				break;
			case 2://�鿴�˺�
				showAccount(data);
				break;
			case 3://�޸��˺�
				changeAccount(data, c);
				break;
			case 4://ɾ���˺�
				delAccount(data, c);
				break;
			default:
				system("cls");
				break;
			}

			system("cls");
		}
	}
	int Manager::showAccountControlMenu()
	{
		cout << "��ӭ����Ա��" << userName << "��¼" << endl;
		cout << "               ---------------------------------------" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              1����˺�              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              2�鿴�˺�              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              3�޸��˺�              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              4ɾ���˺�              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              0��    ��              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               ---------------------------------------" << endl;
		cout << "����������ѡ��" << endl;
		cout << endl;

		int select;
		cin >> select;

		return select;
	}
	//�����˺�
	void Manager::addAccount(MyData& data, Control& c)
	{
		cout << "����������˺ŵ����� 0����Ա 1��ʦ 2ѧ��" << endl;
		int select = -1;
		cin >> select;

		switch (select)
		{
		case 0:
			addAcc(data.mm, c, Identity::Manager);
			system("pause");
			break;
		case 1:
			addAcc(data.mt, c,Identity::Teacher);
			system("pause");
			break;
		case 2:
			addAcc(data.ms, c,Identity::Student);
			system("pause");
			break;
		default://�쳣���������������������control���Ѵ���
			break;
		}
	}
	//����˺�
	template<typename T>
	void Manager::addAcc(map<int,T>& m, Control& c,Identity identity)
	{
		int id;
		string name;
		string password;
		string path;
		string content;
		readAccInput(m, id, name, password);
		switch (identity)
		{
		case manager::Identity::Manager:
			path = string(FILE_PATH) + MANAGER_FILE;
			break;
		case manager::Identity::Teacher:
			path = string(FILE_PATH) + TEACHER_FILE;
			break;
		case manager::Identity::Student:
			path = string(FILE_PATH) + STUDENT_FILE;
			break;
		default:
			break;
		}

		//д������
		content = to_string(id) + " " + name + " " + password;
		m.insert(pair<int, T>(id, T(id, name, password)));
		c.WriteData(path, content);

		cout << "�˺���ӳɹ�" << endl;
		
	}
	//��ȡ�û��˺�������ݵ�����
	template<typename T>
	void Manager::readAccInput(const map<int, T>& m, int& id, string& name, string& password)
	{
		bool flag = true;

		while (flag)
		{
			flag = false;
			cout << "��������" << endl;
			cin >> id;
			if (id <= 0)
			{
				cout << "�������Ҫ����0" << endl;
				flag = true;
				continue;
			}
			//����˺��Ƿ�����
			for_each(m.begin(), m.end(), [id, &flag](pair<int, T> p) {
				if (p.first == id)//����ظ�
				{
					cout << "�ñ���Ѵ��ڣ�����������" << endl;
					flag = true;
					return;
				}
				});
		}
		cout << "�������û���" << endl;
		cin >> name;
		cout << "����������" << endl;
		cin >> password;
	}

	//ͳһ�˲�ͬ�˺ŵ�����߼����������˺Ų�����Ƶ��ʽ�����ǰ���Ž���Ψһ���жϣ�����ʦ��ѧ���˺�����һ��
	//��ģ�巽ʽ������Щ����������
	//void Manager::addManager(map<int, Manager>& mm, Control& c)
	//{
	//	string name;
	//	string password;
	//	bool flag = true;

	//	while (flag)
	//	{
	//		flag = false;
	//		cout << "�������û���" << endl;
	//		cin >> name;
	//		//����˺��Ƿ�����
	//		for_each(mm.begin(), mm.end(), [name,&flag](pair<int, Manager> p) {
	//			if (p.second.userName == name)//����
	//			{
	//				cout << "���û����Ѵ��ڣ�����������" << endl;
	//				flag = true;
	//				return;
	//			}
	//		});
	//	}

	//	cout << "����������" << endl;
	//	cin >> password;

	//	string path = string(FILE_PATH) + MANAGER_FILE;
	//	string content = to_string(mm.size()+1) + " " + name + " " + password;
	//	mm.insert(pair<int, Manager>(mm.size()+1, Manager(mm.size()+1, name, password)));
	//	c.WriteData(path, content);

	//	cout << "�˺���ӳɹ�" << endl;
	//	system("pause");

	//}
	//void Manager::addTeacher(map<int, Teacher>& mt, Control& c)
	//{
	//	int id;
	//	string name;
	//	string password;
	//	bool flag = true;

	//	while (flag)
	//	{
	//		flag = false;
	//		cout << "��������" << endl;
	//		cin >> id;
	//		if (id == 0)
	//		{
	//			cout << "��Ų���������Ϊ0" << endl;
	//			flag = true;
	//			continue;
	//		}
	//		//����˺��Ƿ�����
	//		for_each(mt.begin(), mt.end(), [id, &flag](pair<int, Teacher> p) {
	//			if (p.first == id)//����ظ�
	//			{
	//				cout << "���û��Ѵ��ڣ�����������" << endl;
	//				flag = true;
	//				return;
	//			}
	//		});
	//	}
	//	cout << "�������û���" << endl;
	//	cin >> name;
	//	cout << "����������" << endl;
	//	cin >> password;

	//	string path = string(FILE_PATH) + TEACHER_FILE;
	//	string content = to_string(id) + " " + name + " " + password;
	//	mt.insert(pair<int, Teacher>(id, Teacher(id, name, password)));
	//	c.WriteData(path, content);

	//	cout << "�˺���ӳɹ�" << endl;
	//	system("pause");
	//}
	//void Manager::addStudent(map<int, Student>& ms, Control& c)
	//{
	//	int id;
	//	string name;
	//	string password;
	//	bool flag = true;

	//	while (flag)
	//	{
	//		flag = false;
	//		cout << "��������" << endl;
	//		cin >> id;
	//		if (id == 0)
	//		{
	//			cout << "��Ų���������Ϊ0" << endl;
	//			flag = true;
	//			continue;
	//		}
	//		//����˺��Ƿ�����
	//		for_each(ms.begin(), ms.end(), [id, &flag](pair<int, Student> p) {
	//			if (p.first == id)//����ظ�
	//			{
	//				cout << "���û��Ѵ��ڣ�����������" << endl;
	//				flag = true;
	//				return;
	//			}
	//		});
	//	}
	//	cout << "�������û���" << endl;
	//	cin >> name;
	//	cout << "����������" << endl;
	//	cin >> password;

	//	string path = string(FILE_PATH) + STUDENT_FILE;
	//	string content = to_string(id) + " " + name + " " + password;
	//	ms.insert(pair<int, Student>(id, Student(id, name, password)));
	//	c.WriteData(path, content);

	//	cout << "�˺���ӳɹ�" << endl;
	//	system("pause");
	//}
	//ɾ���˺�
	void Manager::delAccount(MyData& data, Control& c)
	{

	}
	//�޸��˺�
	template<typename T>
	void Manager::changeAcc(map<int, T>& m, Control& c, Identity identity)
	{
		if (m.size() == 0)
		{
			cout << "��¼Ϊ��" << endl;
			return;
		}
		//��ʾ���޸ĵ��˺�
		showAcc(m);

		int oID = 0;
		int input = 0;
		cout << "������Ҫ�޸ĵı�ţ�0����ȡ������" << endl;
		cin >> input;
		if (input == 0)
		{
			cout << "������ȡ��" << endl;
			return;
		}
		oID = input;

		//�����޸��˺�
		pair<int, T> temp;
		int id;
		string name;
		string password;
		string path;
		string content;
		auto it = m.find(input);
		if (it != m.end())//�ҵ��˺�
		{
			//�Ƴ�m�����еı�ѡ��Ԫ�أ������޷�����������ͬ�ı��
			temp = *it;
			m.erase(it);
			//��ȡ�û��˺�������ݵ�����
			readAccInput(m, id, name, password);

			cout << "ȷ���޸ĸ��˺��� 0ȡ�� 1ȷ��" << endl;
			cin >> input;

			if (input == 1)//ȷ���޸�
			{
				//�޸�m�����е�����
				m.insert(pair<int, T>(id, T(id, name, password)));

				//�޸��ļ��е�����
				switch (identity)
				{
				case manager::Identity::Manager:
					path = string(FILE_PATH) + MANAGER_FILE;
					content = to_string(oID) + " " + temp.second.userName + " " + temp.second.password;
					break;
				case manager::Identity::Teacher:
					path = string(FILE_PATH) + TEACHER_FILE;
					content = to_string(oID) + " " + temp.second.userName + " " + temp.second.password;
					break;
				case manager::Identity::Student:
					path = string(FILE_PATH) + STUDENT_FILE;
					content = to_string(oID) + " " + temp.second.userName + " " + temp.second.password;
					break;
				default:
					break;
				}

				//ɾ��ԭ����
				c.DelData(path, content);

				//����д������
				content = to_string(id) + " " + name + " " + password;
				c.WriteData(path, content);

				cout << "�˺��޸ĳɹ�" << endl;
			}
			else//�����޸�
			{
				m.insert(temp);
				cout << "������ȡ��" << endl;
				return;
			}
		}
		else
		{
			cout << "�������������²���" << endl;
		}
		
	}
	void Manager::changeAccount(MyData& data, Control& c)
	{
		cout << "������Ҫ�޸��˺ŵ����� 0����Ա 1��ʦ 2ѧ��" << endl;
		int select = -1;
		cin >> select;

		switch (select)
		{
		case 0:
			changeAcc(data.mm,c, Identity::Manager);
			system("pause");
			break;
		case 1:
			changeAcc(data.mt, c,Identity::Teacher);
			system("pause");
			break;
		case 2:
			changeAcc(data.ms, c, Identity::Student);
			system("pause");
			break;
		default://�쳣���������������������control���Ѵ���
			break;
		}
	}
	//��������˺���Ϣ
	template<typename T>
	void Manager::showAcc(const map<int,T>& m)
	{
		if (m.size() == 0)
		{
			cout << "��¼Ϊ��" << endl;
			//system("pause");
			return;
		}
		cout << endl;
		for_each(m.begin(), m.end(), [](pair<int, T> p) {
			cout << p.second << endl;
		});
		cout << endl;
		//system("pause");
	}
	//�鿴�˺�
	void Manager::showAccount(MyData& data)
	{
		cout << "������鿴�˺ŵ����� 0����Ա 1��ʦ 2ѧ��" << endl;
		int select = -1;
		cin >> select;

		switch (select)
		{
		case 0:
			showAcc(data.mm);
			system("pause");
			break;
		case 1:
			showAcc(data.mt);
			system("pause");
			break;
		case 2:
			showAcc(data.ms);
			system("pause");
			break;
		default://�쳣���������������������control���Ѵ���
			break;
		}
	}

	//��������
	void Manager::ComputerRoomControl(MyData& data, Control& c)
	{

	}
	//����ԤԼ��¼
	void Manager::orderControl(MyData& data, Control& c)
	{

	}






}






//switch (select)
//{
//case 0://ע����¼
//	break;
//case 1://����˺�
//	break;
//case 2://�鿴�˺�
//	break;
//case 3://�޸��˺�
//	break;
//case 4://ɾ���˺�
//	break;
//case 5://��ӻ���
//	break;
//case 6://�鿴����
//	break;
//case 7://�޸Ļ���
//	break;
//case 8://ɾ������
//	break;
//default:
//	break;
//}



//������
//class Class1
//{
//public:
//	int a;
//	string str;
//	Class1() :a(1), str("str") {}
//};
//void fun(map<int, Class1>& m,Class1*& c)
//{
//	for_each(m.begin(), m.end(), [&](pair<int, Class1> p) {
//		if (p.first == 1)
//		{
//			c = &(p.second);
//		}
//		
//	});
//}
//int main()
//{
//	map<int, Class1> m;
//	m.insert(pair<int, Class1>(1, Class1()));
//	Class1* c = nullptr;
//	fun(m, c);
//
//}



