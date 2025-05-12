#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include"Manager.h"

using namespace std;
using namespace manager;

//剩余功能不重要且不是很难实现，当前不再继续处理
//未完成的功能项
// 读取过往比赛记录
// 每届比赛时记录选手的所有信息存储到CMap，通过键找到对应的选手，往选手的每届的得分记录中添加数据
// 每届比赛结束后，写入每届比赛的数据
// 查看比赛记录(默认显示所有往届的前三名)，可以选择查看某一届的所有比赛记录
// 查找比赛记录，可以选择查找某人后显示该选手的所有比赛记录
// 清空比赛记录
// 一些数据暂时没有使用上，如int sessionNum;//参与的比赛届数、int roundNum;//参与的比赛轮数，其实不用也可以，用容器的size属性可获取到这些数据
// 
//


//暂时先不处理选手数据读取相关的内容
//先按vector放置每届的所有选手的比赛记录  map放置一届的 所有选手及其所有比赛记录 的方式进行数据存储
//项目完成后再考虑是否有优化空间

//应该将不同的数据用不同的容器进行存储？(好像没必要，如果数值都是以引用方式存储的话，实际应该只有一个对象)
// 选手表--map容器，键-选手唯一ID 值-该选手所有比赛记录 记录选手的比赛记录
// 每届比赛表--vector容器， 记录所有参赛的选手
//

int main()
{
	int sessionNum = 0;//用于记录比赛进行了多少届
	map<int, contestant::Contestant> CMap;//用于放置一届的 所有选手及其所有比赛记录
	vector<map<int, contestant::Contestant>> sessionV;//用于放置每届的 所有选手及其所有比赛记录

	//读取过往比赛记录
	readContestData(sessionNum,CMap);

	//生成随机数种子
	//srand((unsigned int)time(NULL));

	while (1)
	{
		//显示菜单
		int select = showMenu();

		switch (select)
		{
		case 0://退出系统
			exitSystem();
			break;
		case 1://开始演讲比赛
			manager::startContest(sessionNum,CMap);
			sessionNum++;
			writeContestData(sessionNum, CMap);
			system("pause");
			system("cls");
			break;
		case 2://查看比赛记录
			system("pause");
			system("cls");
			break;
		case 3://查找比赛记录
			system("pause");
			system("cls");
			break;
		case 4://清空比赛记录
			system("pause");
			system("cls");
			break;
		default://无意义操作，清屏
			system("cls");
			break;
		}
		
	}










}





