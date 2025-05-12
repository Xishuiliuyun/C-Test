#pragma once
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

#define CONTESTANTNUM 12//比赛选手人数
#define JUDGESNUM 10//评委人数
#define GROUPNUM 2//分组数量
#define MINCONTESTANTNUM 4//分组时每组最小人数


//感觉选手类的构建思路上有点问题
// 选手类就不应该包含往届的成绩相关的内容
// 只包含本届的内容即可
// 需要输出选手信息时的情况，遍历每届的的比赛，查找选手后输出信息即可
// 这样的话可以把ScoreData SD类中的内容直接放选手类下 选手类会精简很多
//

namespace contestant
{
	//尝试用宏控制选手数量
	//尝试实现循环比赛，直到出现前三名

	//成绩类(记录该选手一轮的比赛记录)
	class Score
	{
	public:
		set<float, less<float>> m_ScoreSet;//单轮所有成绩
		set<float, less<float>> m_SS;//单轮有效成绩
		float m_TotalScore;//单轮总分
		float m_AverageScore;//单轮平均分
		Score():m_TotalScore(0), m_AverageScore(0){}
	};

	//成绩数据类(记录该选手一整届的比赛记录)
	class ScoreData
	{
	public:
		int m_ID;//比赛人员ID以 10001~10099(第一届)  20001~20099(第二届)方式命名
		int roundNum;//参与的比赛轮数
		vector<Score> ScoreV;//每轮的得分记录
		ScoreData(){}
		ScoreData(int ID):m_ID(ID), roundNum(0){}
	};

	//选手类
	class Contestant
	{
	public:
		string m_Name;//比赛人员以每届重复的 选手1~选手99 方式命名
		ScoreData SD;//本届的得分记录
		int sessionNum;//参与的比赛届数
		vector<ScoreData> ScoreDataV;//每届的得分记录
		Contestant() {};
		Contestant(string name , int ID):m_Name(name), SD(ID){}
	};

	//开始演讲比赛 参数 sessionNum比赛届数 cm放置所有选手及其所有比赛记录
	void startContest(const int& sessionNum,map<int, Contestant>& cm);
	void buildContestant(const int& sessionNum, vector<Contestant>& vc);//生成选手
	void randGrouping(const int& sessionNum, vector<Contestant>& vc);//随机分组
	void matchScoring(vector<Contestant>& vc);//比赛评分
	void showContestantScore(const int& sessionNum, vector<Contestant>& vc, vector<vector<Contestant>>& vvc);//显示每轮选手成绩
	void contestantSort(vector<Contestant>& vc, vector<vector<Contestant>>& vvc);//选手分组排序处理
	void showContestant(Contestant c, int flag = 0);//打印选手信息 0打印当前轮得分信息 1打印选手所有的参赛成绩
	void eliminateContestant(vector<Contestant>& vc,vector<vector<Contestant>>&vvc);//淘汰选手	
	void showPromotedContestant(const int& sessionNum, vector<Contestant>& vc);//打印晋级人员信息
	//淘汰选手后再进行分组-比赛-淘汰循环，直到出现前三名
}




