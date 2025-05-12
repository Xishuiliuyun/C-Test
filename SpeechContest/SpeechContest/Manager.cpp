#include"Manager.h"


namespace manager
{
	//显示菜单
	int showMenu()
	{
		cout << "********************************************" << endl;
		cout << "************欢迎使用演讲比赛系统************" << endl;
		cout << "************	0退出比赛系统	************" << endl;
		cout << "************	1开始演讲比赛	************" << endl;
		cout << "************	2查看比赛记录	************" << endl;
		cout << "************	3清空比赛记录	************" << endl;
		cout << "********************************************" << endl;
		cout << "请选择功能" << endl;
		cout << endl;

		int select;
		cin >> select;

		return select;
	}

	//退出系统
	void exitSystem()
	{
		cout << "欢迎下次使用" << endl;
		system("pause");
		exit(0);
	}

	//开始演讲比赛 参数 sessionNum比赛届数 cm放置所有选手及其所有比赛记录
	void startContest(const int& sessionNum, map<int, contestant::Contestant>& cm)
	{
		contestant::startContest(sessionNum,cm);
	}


	//读取过往比赛记录 参数 sessionNum比赛届数 cm放置所有选手及其所有比赛记录 flag读取方式 0仅读取比赛届数 1读取届数和选手比赛记录
	void readContestData(int& sessionNum, map<int, contestant::Contestant>& cm ,int flag)
	{


	}

	//记录比赛数据
	void writeContestData(int& sessionNum, map<int, contestant::Contestant>& cm)
	{



	}




	//void showContestData();//查看比赛记录
	//void clearContestDocumeny();//清空比赛记录





















}





