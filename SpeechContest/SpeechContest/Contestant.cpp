#include"Contestant.h"

int roundNum = 0;//当前比赛轮数
int conNum = CONTESTANTNUM;;//当前轮剩余的参赛选手
int curGNum = GROUPNUM;//当前分组数
bool isFinish = false;//比赛结束


namespace contestant
{
	//开始演讲比赛后 生成选手 再进行分组-比赛-淘汰循环，直到出现前三名

	//开始演讲比赛
	void startContest(const int& sessionNum, map<int, Contestant>& cm)
	{
		roundNum = 0;
		isFinish = false;
		vector<Contestant> vc;//本届比赛选手
		vector<vector<Contestant>> vvc;//排序后临时容器
		

		buildContestant(sessionNum, vc);//生成选手 //可输入选手数量，0则生成默认选手数量

		while (!isFinish)
		{
			randGrouping(sessionNum, vc);//随机分组

			matchScoring(vc);//比赛评分

			showContestantScore(sessionNum, vc, vvc);//输出选手成绩

			eliminateContestant(vc, vvc);//淘汰选手	

			if (isFinish) break;//比赛结束后不再打印晋级人员信息，

			showPromotedContestant(sessionNum,vc);//打印晋级人员信息
		}

	}


	//生成选手
	void buildContestant(const int& sessionNum, vector<Contestant>& vc)
	{
		cout << "请输入第"<< sessionNum+1 <<"届比赛的参加人数：  输入0表示默认人数 " << CONTESTANTNUM << endl;
		int num = CONTESTANTNUM;
		cin >> num;
		if(num == 0) num = CONTESTANTNUM;
		conNum = num;

		cout << "请输入第" << sessionNum + 1 << "届比赛的分组数：  输入0表示默认分 " << GROUPNUM<<"组" << endl;
		cin >> num;
		if (num == 0) num = GROUPNUM;
		curGNum = num;

		vc.reserve(conNum);
		for (int i = 0;i < conNum;i++)
		{
			string name = "选手";
			name += to_string(i+1);
			int ID = (sessionNum + 1) * 10000 + i + 1;
			vc.push_back(Contestant(name,ID));
		}
	}

	//随机分组
	void randGrouping(const int& sessionNum, vector<Contestant>& vc)
	{
		cout << "\n第" << sessionNum+1 << "届 第" << roundNum + 1 << "轮比赛选手抽签" << endl;
		cout << "---------------------------------------------" << endl;
		random_shuffle(vc.begin(), vc.end());
		cout << "抽签后演讲顺序如下：" << endl;
		for (int i =0;i < vc.size();i++)
		{
			cout << vc.at(i).SD.m_ID << " ";
		}
		cout << endl;
		cout << "---------------------------------------------" << endl;
		system("pause");
	}

	//比赛评分
	void matchScoring(vector<Contestant>& vc)
	{
		int num = JUDGESNUM;
		for (int i = 0;i < vc.size();i++)//评委打分及数据记录
		{
			vc.at(i).SD.ScoreV.push_back(Score());
			Score& s = vc.at(i).SD.ScoreV.at(roundNum);
			set<float, less<float>>& ss1 = s.m_ScoreSet;
			set<float, less<float>>& ss2 = s.m_SS;

			for (int j = 0;j < num;j++)//全部评委打分
			{
				int score = rand() % 41 + 60;
				ss1.insert(score);//单轮所有成绩
			}

			vc.at(i).SD.roundNum++;
			copy(++ss1.begin(), --ss1.end(), inserter(ss2, ss2.begin()));//记录单轮有效成绩
			float sSum = 0;
			for_each(ss2.begin(), ss2.end(), [&sSum](float score) {
				sSum += score;
			});
			s.m_TotalScore = sSum;
			s.m_AverageScore = sSum / (JUDGESNUM - 2);
		}
		
		
	}

	//显示每轮选手成绩
	void showContestantScore(const int& sessionNum, vector<Contestant>& vc, vector<vector<Contestant>>& vvc)
	{
		if (curGNum == 1)//已经生成决赛结果
		{
			cout << "\n---------------------------------------------" << endl;
			cout << "第" << sessionNum + 1 << "届 决赛开始：" << endl;

			//排序
			sort(vc.begin(), vc.end(), [](Contestant c1, Contestant c2) {
				return c1.SD.ScoreV.at(roundNum).m_AverageScore > c2.SD.ScoreV.at(roundNum).m_AverageScore;
				});

			//输出成绩
			for (int i = 0;i < vc.size();i++)
			{
				showContestant(vc.at(i));
			}
			cout << "\n第" << sessionNum + 1 << "届 决赛结束："  << endl;
			cout << "---------------------------------------------\n" << endl;
			system("pause");
			system("cls");

			//输出前三名
			cout << "\n第" << sessionNum + 1 << "届 前三名选手：" << endl;
			for (int i = 0;i < 3;i++)
			{
				if (i == 0) cout << "冠军：" << endl;
				if (i == 1) cout << "亚军：" << endl;
				if (i == 2) cout << "季军：" << endl;
				showContestant(vc.at(i));
			}
			isFinish = true;
			return;
		}

		cout << "\n---------------------------------------------" << endl;
		cout << "第" << sessionNum+1 << "届 第" << roundNum + 1 << "轮比赛选手开始：" << endl;

		//分组显示选手成绩规则
		// 分组和晋级规则：按设定的GROUPNUM分组数量进行分组，每轮每组的一半选手晋级，人数为单数时晋级人数-1
		// 当每组人数无法均分时，余下的人分到前面的组里
		// 当每组人数会少于4人时，分组数减半，组数为单数时组数-1
		// 当组数剩余小于等于2时，下一轮为决赛
		// 例：
		//	100人参赛，初始组数设为10
		//	第一轮 人数100 组数10 每组10人
		//	第二轮 人数50 组数10 每组5人
		//	第三轮 人数20 组数5 每组4人
		//	第四轮 人数10 组数2 每组5人
		//	第五轮 人数4 组数1 每组4人
		//			100		9		8-11  1-12
		//			51      9       3-5   6-6
		//			24		4		4-6
		//			12		2		2-6
		//			6		1
		// 

		
		//选手分组排序处理
		vvc.clear();
		contestantSort(vc, vvc);


		int remainder = conNum % curGNum;//余下的人数
		int gNum = 0;//当前输出的组数
		vector<Contestant> v;//临时输出容器
		int index = 0;//临时输出容器下标
		int endI = 0;//上一次分组的最后位置

		for (int i = 0;i < conNum;i++)
		{
			if (i == 0)
			{
				cout << "第" << gNum + 1 << "小组比赛名次：" << endl;
				v = vvc.at(gNum);
				index = 0;//每次分配临时输出容器时，重置下标
				gNum++;
			}
			if (remainder != 0)//有余下的人数
			{
				if (i == (conNum / curGNum) + endI + 1)
				{
					cout << "第" << gNum + 1 << "小组比赛名次：" << endl;
					v = vvc.at(gNum);
					index = 0;//每次分配临时输出容器时，重置下标
					remainder--;
					gNum++;
					endI = i;
				}
			}
			else
			{
				if (i == (conNum / curGNum) + endI)
				{
					cout << "第" << gNum + 1 << "小组比赛名次：" << endl;
					v = vvc.at(gNum);
					index = 0;//每次分配临时输出容器时，重置下标
					gNum++;
					endI = i;
				}
			}

			showContestant(v.at(index));
			index++;
		}

		cout << "\n第" << sessionNum+1 << "届 第" << roundNum + 1 << "轮比赛结束" << endl;
		cout << "---------------------------------------------\n" << endl;
		system("pause");

	}

	//选手分组排序处理
	void contestantSort(vector<Contestant>& vc, vector<vector<Contestant>>& vvc)
	{
		int remainder = conNum % curGNum;//余下的人数
		int gNum = 0;//当前的组数
		int endI = 0;//上一次分组的最后位置

		//分组
		for (int i = 0;i < conNum;i++)
		{
			//剩下的人都在一组
			if (gNum == curGNum - 1)
			{
				vector<Contestant> v(vc.begin()+ endI, vc.end());
				vvc.push_back(v);
				break;
			}

			//有超过一组的人数需要分组
			if (remainder != 0)//有余下的人数
			{
				if (i == (conNum / curGNum) + endI +1)
				{
					vector<Contestant> v(vc.begin() + endI, vc.begin() + i);
					vvc.push_back(v);
					remainder--;
					gNum++;
					endI = i;
				}
			}
			else
			{
				if (i == (conNum / curGNum) + endI)
				{
					vector<Contestant> v(vc.begin() + endI, vc.begin() + i);
					vvc.push_back(v);
					gNum++;
					endI = i;
				}
			}
		}

		//排序
		for (int i = 0;i < curGNum;i++)
		{
			vector<Contestant>& v = vvc.at(i);
			sort(v.begin(), v.end(), [](Contestant c1, Contestant c2) {
				return c1.SD.ScoreV.at(roundNum).m_AverageScore > c2.SD.ScoreV.at(roundNum).m_AverageScore;
			});
		}

	}

	//打印选手信息 0打印当前轮得分信息 1打印选手所有的参赛成绩
	void showContestant(Contestant c, int flag)
	{
		if (flag == 0)
		{
			cout << "编号： " << c.SD.m_ID << " 姓名：" << c.m_Name << "\t成绩： " << c.SD.ScoreV.at(roundNum).m_AverageScore << endl;
		}
		else if (flag == 1)
		{

		}
		else;
	}

	//淘汰选手
	void eliminateContestant(vector<Contestant>& vc, vector<vector<Contestant>>& vvc)
	{
		//分组显示选手成绩规则
		// 分组和晋级规则：按设定的GROUPNUM分组数量进行分组，每轮每组的一半选手晋级，人数为单数时晋级人数-1
		// 当每组人数无法均分时，余下的人分到前面的组里
		// 当每组人数会少于4人时，分组数减半，组数为单数时组数-1
		// 组数为1时，此轮为决赛，需决出前三
		// 例：
		//	100人参赛，初始组数设为10
		//	第一轮 人数100 组数10 每组10人
		//	第二轮 人数50 组数10 每组5人
		//	第三轮 人数20 组数5 每组4人
		//	第四轮 人数10 组数2 每组5人
		//	第五轮 人数4 组数1 每组4人
		//			100		9		8-11  1-12
		//			51      9       3-5   6-6
		//			24		4		4-6
		//			12		2		2-6
		//			6		1
		// 

		//计算晋级人数和下一轮分组数
		int count = 0;

		for (int i = 0;i < vvc.size();i++)
		{
			count += vvc.at(i).size() / 2;
		}
		conNum = count;//当前轮剩余的参赛选手

		while ((conNum / curGNum) < MINCONTESTANTNUM && curGNum !=1)
		{
			curGNum /= 2;
			if (curGNum == 0) curGNum = 1;
		}

		//cout << "下一轮人数：" << conNum << "下一轮组数：" << curGNum << endl;


		//记录比赛//暂不处理
		//将所有选手数据存放至map<int, Contestant>& cm


		//淘汰人员
		vc.clear();
		for (int i = 0;i < vvc.size();i++)
		{
			for (int j = 0;j < vvc.at(i).size();j++)
			{
				if (j < (vvc.at(i).size() / 2))//晋级
				{
					vc.push_back(vvc.at(i).at(j));
				}
				else break;//剩余人员晋级失败
			}
		}

	}

	//打印晋级人员信息
	void showPromotedContestant(const int& sessionNum,vector<Contestant>& vc)
	{
		cout << "\n第" << sessionNum + 1 << "届 第" << roundNum + 1 << "轮比赛晋级选手共"<< vc.size() <<"名：" << endl;
		for (int i = 0;i < vc.size();i++)
		{
			showContestant(vc.at(i));
		}

		roundNum++;
		system("pause");
		system("cls");
	}
	
}



