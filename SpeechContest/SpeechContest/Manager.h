#pragma once
#include<iostream>
#include<string>
#include"Contestant.h"
#include<map>

using namespace std;


namespace manager
{
	int showMenu();//显示菜单
	void exitSystem();//退出系统
	//开始演讲比赛 参数 sessionNum比赛届数 cm放置所有选手及其所有比赛记录
	void startContest(const int& sessionNum, map<int, contestant::Contestant>& cm);
	//读取过往比赛记录 参数 sessionNum比赛届数 cm放置所有选手及其所有比赛记录 flag读取方式 0仅读取比赛届数 1读取届数和选手比赛记录
	void readContestData(int &sessionNum,map<int, contestant::Contestant>& cm, int flag = 0); 
	void writeContestData(int& sessionNum, map<int, contestant::Contestant>& cm);//记录比赛数据
	void showContestData();//查看比赛记录 查看往届所有前三名
	void findContestData();//查找比赛记录 0通过比赛第几届显示 1通过选手ID查找 2通过选手姓名查找
	void clearContestDocumeny();//清空比赛记录

}






