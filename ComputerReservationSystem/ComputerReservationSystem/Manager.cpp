#include"Manager.h"



namespace manager
{
	//控制类，用于对整个系统进行管理
	//主要是系统进出、初始化、文件读写、登录退出、人员控制等功能

	//构造
	Control::Control()
	{
		init();
	}

	//初始化
	void Control::init()
	{
		//读取数据
		ReadData();
	}

	//显示主菜单  返回用户选择项
	int Control::showMainMenu()
	{
		cout << "============欢迎使用机房预约系统============\n" << endl;
		cout << "请输入您的身份" << endl;
		cout << "               ---------------------------------------" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              1学生代表              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              2老    师              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              3管 理 员              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              0退    出              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               ---------------------------------------" << endl;
		cout << "请输入您的选择：" << endl;
		cout << endl;

		int select;
		cin >> select;

		return select;
	}

	//登录系统
	bool Control::loginSystem(Identity id)
	{
		//登录前操作
		

		bool logRet = false;
		Manager* mp = nullptr;//通过指针的方式，获取容器中的对象的引用
		switch (id)
		{
		case manager::Identity::Manager:
			logRet = logVerify_Manager(mp);
			if (logRet)//登录成功
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				mp->managerControl(m_data,*this);
				//cout << mp->password << endl;
				//mp->password = 100;
				//cout << m_data.mm[0].password << endl;
			}
			else cout << "登录失败" << endl;//登录失败
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

	//登录验证
	//用户名、密码验证
	//c通过指针引用的方式传入，在函数内修改指针的指向，指向容器中的对象
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
				if (it != mm.end())//找到用户
				{
					if (it->second.userName == userName && it->second.password == password)//验证通过
					{
						verifyRet = true;
						c = &(it->second);
					}
				}
				else verifyRet = false;
			}
			else//遍历mm中的userName
			{
				//Lambda表达式[&](pair<const int,Manager>& p)
				//[&]表示自动引用方式 捕获所有使用的参数
				//(pair<const int,Manager>& p)//必要要用&引用的方式将容器中的对象传入，否则是拷贝临时变量
				//且pair<>中，必须用const 修饰int，否则类型不一致，会导致报错
				for_each(mm.begin(), mm.end(), [&](pair<const int,Manager>& p) {
					if (p.second.userName == userName && p.second.password == password)//验证通过
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
	//管理者
	bool Control::logVerify_Manager(Manager*& m)
	{
		bool logRet = false;
		string userName;
		string password;
		cout << "请输入用户名：" << endl;
		cin >> userName;
		cout << "请输入密码：" << endl;
		cin >> password;

		logRet = verify(Identity::Manager,userName,password, m);
		//logRet = verify(Identity::Manager,userName,password, m,0);

		return logRet;
	}
	//老师
	bool Control::logVerify_Teacher()
	{
		bool logRet = false;


		return logRet;
	}
	//学生
	bool Control::logVerify_Student()
	{
		bool logRet = false;


		return logRet;
	}

	//读取数据(案例文件不多就一次性读取了)
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

		if (!ifs.is_open())//文件不存在
		{
			//cout << "文件不存在" << endl;
			//设置初始管理员账号
			ofs.open(path, ios::out);
			ofs << "1 admin 123456" << endl;
			ofs.close();
			m_data.mm.insert(pair<int, Manager>(1, Manager(1, "admin", "123456")));
			return;
		}

		if (ifs.peek() == ifstream::traits_type::eof())//文件为空
		{
			//cout << "文件为空" << endl;
			//设置初始管理员账号
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

		if (!ifs.is_open())//文件不存在
		{
			//cout << "文件不存在" << endl;
			return;
		}

		if (ifs.peek() == ifstream::traits_type::eof())//文件为空
		{
			//cout << "文件为空" << endl;
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

		if (!ifs.is_open())//文件不存在
		{
			//cout << "文件不存在" << endl;
			return;
		}

		if (ifs.peek() == ifstream::traits_type::eof())//文件为空
		{
			//cout << "文件为空" << endl;
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

	//写入数据 写入时因为没有文件也会创建文件 不进行失败判断
	void Control::WriteData(string path, string content)
	{
		ofstream ofs;
		ofs.open(path, ios::app);
		ofs << content << endl;
		ofs.close();
	}

	//删除数据
	void Control::DelData(const string& path, const string& content)//通过一整行文本删除
	{
		string oPath = string(FILE_PATH) + "temp.txt";
		ifstream ifs(path);
		ofstream ofs(oPath);
		string line;

		if (!ifs.is_open())
		{
			cout << "文件打开失败" << endl;
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
	void Control::DelData(const string& path, int id)//通过编号删除
	{

	}

	//退出系统
	void Control::exitSystem()
	{
		cout << "欢迎下次使用" << endl;
		system("pause");
		exit(0);
	}

	//析构
	Control::~Control()
	{

	}






	//管理者类，实现系统中的管理者员身份及其功能
	//主要是 增删改查账号(老师、学生)、增删改查机房、增删改查预约记录(可以通过机房查看记录)、退出登录等功能
	ostream& operator<<(ostream& ostr, const Manager& c)
	{
		return cout << "编号:" << c.managerID << "  用户名:" << c.userName << "  密码：" << c.password /*<< endl*/;
	}
	
	Manager::Manager() {}

	Manager::Manager(int id,string name,string psw)
	{
		this->managerID = id;
		this->userName = name;
		this->password = psw;
	}

	//Manager类的菜单显示及功能控制
	void Manager::managerControl(MyData& data, Control& c)
	{
		
		while (1)
		{
			int select = -1;
			select = managerShowMenu();
			switch (select)
			{
			case 0://注销登录
				logOut();
				return;
				break;
			case 1://操作账号
				system("cls");
				accountControl(data,c);
				break;
			case 2://操作机房
				system("cls");
				ComputerRoomControl(data, c);
				break;
			case 3://操作预约记录
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

	//菜单显示
	int Manager::managerShowMenu()
	{
		cout << "欢迎管理员："<<userName<<"登录" << endl;
		cout << "               ---------------------------------------" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              1操作账号              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              2操作机房              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              3操作预约记录          |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              0注销登录              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               ---------------------------------------" << endl;
		cout << "请输入您的选择：" << endl;
		cout << endl;

		int select;
		cin >> select;

		return select;
	}

	//注销登录
	void Manager::logOut()
	{
		cout << "注销成功" << endl;
		system("pause");
	}
	//操作账号
	void Manager::accountControl(MyData& data, Control& c)
	{

		while (1)
		{
			int select = -1;
			select = showAccountControlMenu();
			switch (select)
			{
			case 0://返回
				return;
				break;
			case 1://添加账号
				addAccount(data, c);
				break;
			case 2://查看账号
				showAccount(data);
				break;
			case 3://修改账号
				changeAccount(data, c);
				break;
			case 4://删除账号
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
		cout << "欢迎管理员：" << userName << "登录" << endl;
		cout << "               ---------------------------------------" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              1添加账号              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              2查看账号              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              3修改账号              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              4删除账号              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               |              0返    回              |" << endl;
		cout << "               |                                     |" << endl;
		cout << "               ---------------------------------------" << endl;
		cout << "请输入您的选择：" << endl;
		cout << endl;

		int select;
		cin >> select;

		return select;
	}
	//增加账号
	void Manager::addAccount(MyData& data, Control& c)
	{
		cout << "请输入添加账号的类型 0管理员 1老师 2学生" << endl;
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
		default://异常情况不做处理，清屏操作在control中已处理
			break;
		}
	}
	//添加账号
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

		//写入数据
		content = to_string(id) + " " + name + " " + password;
		m.insert(pair<int, T>(id, T(id, name, password)));
		c.WriteData(path, content);

		cout << "账号添加成功" << endl;
		
	}
	//读取用户账号相关数据的输入
	template<typename T>
	void Manager::readAccInput(const map<int, T>& m, int& id, string& name, string& password)
	{
		bool flag = true;

		while (flag)
		{
			flag = false;
			cout << "请输入编号" << endl;
			cin >> id;
			if (id <= 0)
			{
				cout << "编号设置要大于0" << endl;
				flag = true;
				continue;
			}
			//检测账号是否重名
			for_each(m.begin(), m.end(), [id, &flag](pair<int, T> p) {
				if (p.first == id)//编号重复
				{
					cout << "该编号已存在，请重新输入" << endl;
					flag = true;
					return;
				}
				});
		}
		cout << "请输入用户名" << endl;
		cin >> name;
		cout << "请输入密码" << endl;
		cin >> password;
	}

	//统一了不同账号的添加逻辑，管理者账号不按视频方式，还是按编号进行唯一性判断，和老师、学生账号设置一致
	//用模板方式处理，此些代码已弃用
	//void Manager::addManager(map<int, Manager>& mm, Control& c)
	//{
	//	string name;
	//	string password;
	//	bool flag = true;

	//	while (flag)
	//	{
	//		flag = false;
	//		cout << "请输入用户名" << endl;
	//		cin >> name;
	//		//检测账号是否重名
	//		for_each(mm.begin(), mm.end(), [name,&flag](pair<int, Manager> p) {
	//			if (p.second.userName == name)//重名
	//			{
	//				cout << "该用户名已存在，请重新输入" << endl;
	//				flag = true;
	//				return;
	//			}
	//		});
	//	}

	//	cout << "请输入密码" << endl;
	//	cin >> password;

	//	string path = string(FILE_PATH) + MANAGER_FILE;
	//	string content = to_string(mm.size()+1) + " " + name + " " + password;
	//	mm.insert(pair<int, Manager>(mm.size()+1, Manager(mm.size()+1, name, password)));
	//	c.WriteData(path, content);

	//	cout << "账号添加成功" << endl;
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
	//		cout << "请输入编号" << endl;
	//		cin >> id;
	//		if (id == 0)
	//		{
	//			cout << "编号不可以设置为0" << endl;
	//			flag = true;
	//			continue;
	//		}
	//		//检测账号是否重名
	//		for_each(mt.begin(), mt.end(), [id, &flag](pair<int, Teacher> p) {
	//			if (p.first == id)//编号重复
	//			{
	//				cout << "该用户已存在，请重新输入" << endl;
	//				flag = true;
	//				return;
	//			}
	//		});
	//	}
	//	cout << "请输入用户名" << endl;
	//	cin >> name;
	//	cout << "请输入密码" << endl;
	//	cin >> password;

	//	string path = string(FILE_PATH) + TEACHER_FILE;
	//	string content = to_string(id) + " " + name + " " + password;
	//	mt.insert(pair<int, Teacher>(id, Teacher(id, name, password)));
	//	c.WriteData(path, content);

	//	cout << "账号添加成功" << endl;
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
	//		cout << "请输入编号" << endl;
	//		cin >> id;
	//		if (id == 0)
	//		{
	//			cout << "编号不可以设置为0" << endl;
	//			flag = true;
	//			continue;
	//		}
	//		//检测账号是否重名
	//		for_each(ms.begin(), ms.end(), [id, &flag](pair<int, Student> p) {
	//			if (p.first == id)//编号重复
	//			{
	//				cout << "该用户已存在，请重新输入" << endl;
	//				flag = true;
	//				return;
	//			}
	//		});
	//	}
	//	cout << "请输入用户名" << endl;
	//	cin >> name;
	//	cout << "请输入密码" << endl;
	//	cin >> password;

	//	string path = string(FILE_PATH) + STUDENT_FILE;
	//	string content = to_string(id) + " " + name + " " + password;
	//	ms.insert(pair<int, Student>(id, Student(id, name, password)));
	//	c.WriteData(path, content);

	//	cout << "账号添加成功" << endl;
	//	system("pause");
	//}
	//删除账号
	void Manager::delAccount(MyData& data, Control& c)
	{

	}
	//修改账号
	template<typename T>
	void Manager::changeAcc(map<int, T>& m, Control& c, Identity identity)
	{
		if (m.size() == 0)
		{
			cout << "记录为空" << endl;
			return;
		}
		//显示可修改的账号
		showAcc(m);

		int oID = 0;
		int input = 0;
		cout << "请输入要修改的编号，0代表取消操作" << endl;
		cin >> input;
		if (input == 0)
		{
			cout << "操作已取消" << endl;
			return;
		}
		oID = input;

		//查找修改账号
		pair<int, T> temp;
		int id;
		string name;
		string password;
		string path;
		string content;
		auto it = m.find(input);
		if (it != m.end())//找到账号
		{
			//移除m容器中的被选择元素，否则无法重新输入相同的编号
			temp = *it;
			m.erase(it);
			//读取用户账号相关数据的输入
			readAccInput(m, id, name, password);

			cout << "确定修改该账号吗？ 0取消 1确认" << endl;
			cin >> input;

			if (input == 1)//确认修改
			{
				//修改m容器中的数据
				m.insert(pair<int, T>(id, T(id, name, password)));

				//修改文件中的数据
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

				//删除原数据
				c.DelData(path, content);

				//重新写入数据
				content = to_string(id) + " " + name + " " + password;
				c.WriteData(path, content);

				cout << "账号修改成功" << endl;
			}
			else//放弃修改
			{
				m.insert(temp);
				cout << "操作已取消" << endl;
				return;
			}
		}
		else
		{
			cout << "输入有误，请重新操作" << endl;
		}
		
	}
	void Manager::changeAccount(MyData& data, Control& c)
	{
		cout << "请输入要修改账号的类型 0管理员 1老师 2学生" << endl;
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
		default://异常情况不做处理，清屏操作在control中已处理
			break;
		}
	}
	//遍历输出账号信息
	template<typename T>
	void Manager::showAcc(const map<int,T>& m)
	{
		if (m.size() == 0)
		{
			cout << "记录为空" << endl;
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
	//查看账号
	void Manager::showAccount(MyData& data)
	{
		cout << "请输入查看账号的类型 0管理员 1老师 2学生" << endl;
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
		default://异常情况不做处理，清屏操作在control中已处理
			break;
		}
	}

	//操作机房
	void Manager::ComputerRoomControl(MyData& data, Control& c)
	{

	}
	//操作预约记录
	void Manager::orderControl(MyData& data, Control& c)
	{

	}






}






//switch (select)
//{
//case 0://注销登录
//	break;
//case 1://添加账号
//	break;
//case 2://查看账号
//	break;
//case 3://修改账号
//	break;
//case 4://删除账号
//	break;
//case 5://添加机房
//	break;
//case 6://查看机房
//	break;
//case 7://修改机房
//	break;
//case 8://删除机房
//	break;
//default:
//	break;
//}



//测试用
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



