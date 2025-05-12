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

	//������
	class MyData
	{
	public:
		map<int, Manager> mm;
		map<int, Teacher> mt;
		map<int, Student> ms;
		map<int, Order> mo;
		map<int, ComputerRoom> mc;
	};

	//�����࣬���ڶ�����ϵͳ���й���
	//��Ҫ��ϵͳ��������ʼ�����ļ���д����¼�˳�����Ա���Ƶȹ���
	class Control
	{
	public:
		MyData m_data;
		//����
		Control();
		//��ʼ��
		void init();
		//��ʾ���˵� �����û�ѡ����
		int showMainMenu();
		//��¼ϵͳ
		bool loginSystem(Identity id);
		//��ȡ����(�����ļ������һ���Զ�ȡ��)
		void ReadData();
		void ReadData_Manager();
		void ReadData_Teacher();
		void ReadData_Student();
		void ReadData_Order();
		void ReadData_ComputerRoom();
		//д������
		void WriteData(string path, string content);
		//ɾ������
		void DelData(const string& path, const string& content);//ͨ��һ�����ı�ɾ��
		void DelData(const string& path, int id);//ͨ�����ɾ��
		//��¼��֤
		template<typename T>
		bool verify(Identity id, string userName, string password, T*& c, int no = -1);//�û�����������֤
		bool logVerify_Manager(Manager*& m);//������
		bool logVerify_Teacher();//��ʦ
		bool logVerify_Student();//ѧ��
		//�˳�ϵͳ
		void exitSystem();
		//����
		~Control();
	};

	

	//�������࣬ʵ��ϵͳ�еĹ�����Ա��ݼ��书��
	//��Ҫ�� ��ɾ�Ĳ��˺�(��ʦ��ѧ��)����ɾ�Ĳ��������ɾ�Ĳ�ԤԼ��¼(����ͨ�������鿴��¼)���˳���¼�ȹ���
	class Manager
	{
		friend ostream& operator<<(ostream& ostr, const Manager& c);
	public:
		int managerID;
		string userName;
		string password;
		Manager();
		Manager(int id, string name, string psw);
		//Manager��Ĳ˵���ʾ�����ܿ���
		void managerControl(MyData& data, Control& c);
		//�˵���ʾ
		int managerShowMenu();
		//ע����¼
		void logOut();

		//�����˺�
		void accountControl(MyData& data, Control& c);
		//�˵���ʾ
		int showAccountControlMenu();
		//��
		void addAccount(MyData& data, Control& c);
		//����˺�
		template<typename T>
		void addAcc(map<int, T>& m, Control& c, Identity identity);
		//��ȡ�û��˺�������ݵ�����
		template<typename T>
		void readAccInput(const map<int, T>& m, int& id, string& name, string& password);
		//void addManager(map<int, Manager>& mm, Control& c);
		//void addTeacher(map<int, Teacher>& mt, Control& c);
		//void addStudent(map<int, Student>& ms, Control& c);
		//ɾ
		void delAccount(MyData& data, Control& c);
		//��
		template<typename T>
		void changeAcc(map<int, T>& m, Control& c, Identity id);
		void changeAccount(MyData& data, Control& c);
		//��
		template<typename T>
		void showAcc(const map<int, T>& m);
		void showAccount(MyData& data);

		//��������
		void ComputerRoomControl(MyData& data, Control& c);
		//����ԤԼ��¼
		void orderControl(MyData& data, Control& c);
	};


	//ԤԼ�� ���ڼ�¼ԤԼ��Ϣ
	class Order
	{
	public:
		int orderID;//�������
		int studentID;
		int teacherID;
		int roomID;
		TimeInfo time;
		State state;//��¼״̬
	};

	//������
	class ComputerRoom
	{
	public:
		int roomID;
		int roomCapacity;
		vector<Order> vo;//��¼����������ԤԼ��Ϣ
	};

	//ԤԼ״̬
	enum class State :uint8_t//ָ������Ϊ1�ֽ�
	{
		PROCESS,//�����
		SUCCESS,//ԤԼ�ɹ�
		FAIL,//ԤԼʧ��
		CANCEL//ȡ��ԤԼ
	};

	//�����Ϣ
	enum class Identity :uint8_t
	{
		Manager,
		Teacher,
		Student
	};

	//ʱ����Ϣ
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



