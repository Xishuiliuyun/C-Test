#pragma once

#include<iostream>
#include<fstream>
#include<sstream>
#include<filesystem>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include"Teacher.h"
#include"Student.h"

#define FILE_PATH R"(E:\Language\C++\ComputerReservationSystem\x64\Debug\)"
#define MANAGER_FILE  "Manager.txt"
#define TEACHER_FILE "Teacher.txt"
#define STUDENT_FILE "Student.txt"
#define ORDER_FILE "Order.txt"
#define COMPUTERROOM_FILE "ComputerRoom.txt"

using namespace std;
using namespace teacher;
using namespace student;
namespace fs = std::filesystem;

namespace manager
{
	class Manager;
	class MyData;
	class Control;
	class Order;
	class ComputerRoom;
	enum class State :uint8_t;
	enum class Identity :uint8_t;
	enum class TimeInfo :uint8_t;

	//数据类
	class MyData
	{
	public:
		map<int, Manager> mm;
		map<int, Teacher> mt;
		map<int, Student> ms;
		map<int, Order> mo;
		map<int, ComputerRoom> mc;
	};

	//控制类，用于对整个系统进行管理
	//主要是系统进出、初始化、文件读写、登录退出、人员控制等功能
	class Control
	{
	public:
		MyData m_data;
		//构造
		Control();
		//初始化
		void init();
		//显示主菜单 返回用户选择项
		int showMainMenu();
		//登录系统
		bool loginSystem(Identity id);
		//读取数据(案例文件不多就一次性读取了)
		void ReadData();
		void ReadData_Manager();
		void ReadData_Teacher();
		void ReadData_Student();
		void ReadData_Order();
		void ReadData_ComputerRoom();
		//写入数据
		void WriteData(string path, string content);
		//删除数据
		void DelData(const string& path, const string& content);//通过一整行文本删除
		void DelData(const string& path, int id);//通过编号删除
		//登录验证
		template<typename T>
		bool verify(Identity id, string userName, string password, T*& c, int no = -1);//用户名、密码验证
		bool logVerify_Manager(Manager*& m);//管理者
		bool logVerify_Teacher();//老师
		bool logVerify_Student();//学生
		//退出系统
		void exitSystem();
		//析构
		~Control();
	};

	

	//管理者类，实现系统中的管理者员身份及其功能
	//主要是 增删改查账号(老师、学生)、增删改查机房、增删改查预约记录(可以通过机房查看记录)、退出登录等功能
	class Manager
	{
		friend ostream& operator<<(ostream& ostr, const Manager& c);
	public:
		int managerID;
		string userName;
		string password;
		Manager();
		Manager(int id, string name, string psw);
		//Manager类的菜单显示及功能控制
		void managerControl(MyData& data, Control& c);
		//菜单显示
		int managerShowMenu();
		//注销登录
		void logOut();

		//操作账号
		void accountControl(MyData& data, Control& c);
		//菜单显示
		int showAccountControlMenu();
		//增
		void addAccount(MyData& data, Control& c);
		//添加账号
		template<typename T>
		void addAcc(map<int, T>& m, Control& c, Identity identity);
		//读取用户账号相关数据的输入
		template<typename T>
		void readAccInput(const map<int, T>& m, int& id, string& name, string& password);
		//void addManager(map<int, Manager>& mm, Control& c);
		//void addTeacher(map<int, Teacher>& mt, Control& c);
		//void addStudent(map<int, Student>& ms, Control& c);
		//删
		void delAccount(MyData& data, Control& c);
		//改
		template<typename T>
		void changeAcc(map<int, T>& m, Control& c, Identity id);
		void changeAccount(MyData& data, Control& c);
		//查
		template<typename T>
		void showAcc(const map<int, T>& m);
		void showAccount(MyData& data);

		//操作机房
		void ComputerRoomControl(MyData& data, Control& c);
		//操作预约记录
		void orderControl(MyData& data, Control& c);
	};


	//预约类 用于记录预约信息
	class Order
	{
	public:
		int orderID;//订单编号
		int studentID;
		int teacherID;
		int roomID;
		TimeInfo time;
		State state;//记录状态
	};

	//机房类
	class ComputerRoom
	{
	public:
		int roomID;
		int roomCapacity;
		vector<Order> vo;//记录机房的所有预约信息
	};

	//预约状态
	enum class State :uint8_t//指定类型为1字节
	{
		PROCESS,//审核中
		SUCCESS,//预约成功
		FAIL,//预约失败
		CANCEL//取消预约
	};

	//身份信息
	enum class Identity :uint8_t
	{
		Manager,
		Teacher,
		Student
	};

	//时间信息
	enum class TimeInfo :uint8_t
	{
		MonAm,
		TueAm,
		WedAm,
		ThuAm,
		FriAm,
		SatAm,
		SunAm,
		MonPm,
		TuePm,
		WedPm,
		ThuPm,
		FriPm,
		SatPm,
		SunPm,
	};


}



