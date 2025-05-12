#include"Contestant.h"

int roundNum = 0;//��ǰ��������
int conNum = CONTESTANTNUM;;//��ǰ��ʣ��Ĳ���ѡ��
int curGNum = GROUPNUM;//��ǰ������
bool isFinish = false;//��������


namespace contestant
{
	//��ʼ�ݽ������� ����ѡ�� �ٽ��з���-����-��̭ѭ����ֱ������ǰ����

	//��ʼ�ݽ�����
	void startContest(const int& sessionNum, map<int, Contestant>& cm)
	{
		roundNum = 0;
		isFinish = false;
		vector<Contestant> vc;//�������ѡ��
		vector<vector<Contestant>> vvc;//�������ʱ����
		

		buildContestant(sessionNum, vc);//����ѡ�� //������ѡ��������0������Ĭ��ѡ������

		while (!isFinish)
		{
			randGrouping(sessionNum, vc);//�������

			matchScoring(vc);//��������

			showContestantScore(sessionNum, vc, vvc);//���ѡ�ֳɼ�

			eliminateContestant(vc, vvc);//��̭ѡ��	

			if (isFinish) break;//�����������ٴ�ӡ������Ա��Ϣ��

			showPromotedContestant(sessionNum,vc);//��ӡ������Ա��Ϣ
		}

	}


	//����ѡ��
	void buildContestant(const int& sessionNum, vector<Contestant>& vc)
	{
		cout << "�������"<< sessionNum+1 <<"������Ĳμ�������  ����0��ʾĬ������ " << CONTESTANTNUM << endl;
		int num = CONTESTANTNUM;
		cin >> num;
		if(num == 0) num = CONTESTANTNUM;
		conNum = num;

		cout << "�������" << sessionNum + 1 << "������ķ�������  ����0��ʾĬ�Ϸ� " << GROUPNUM<<"��" << endl;
		cin >> num;
		if (num == 0) num = GROUPNUM;
		curGNum = num;

		vc.reserve(conNum);
		for (int i = 0;i < conNum;i++)
		{
			string name = "ѡ��";
			name += to_string(i+1);
			int ID = (sessionNum + 1) * 10000 + i + 1;
			vc.push_back(Contestant(name,ID));
		}
	}

	//�������
	void randGrouping(const int& sessionNum, vector<Contestant>& vc)
	{
		cout << "\n��" << sessionNum+1 << "�� ��" << roundNum + 1 << "�ֱ���ѡ�ֳ�ǩ" << endl;
		cout << "---------------------------------------------" << endl;
		random_shuffle(vc.begin(), vc.end());
		cout << "��ǩ���ݽ�˳�����£�" << endl;
		for (int i =0;i < vc.size();i++)
		{
			cout << vc.at(i).SD.m_ID << " ";
		}
		cout << endl;
		cout << "---------------------------------------------" << endl;
		system("pause");
	}

	//��������
	void matchScoring(vector<Contestant>& vc)
	{
		int num = JUDGESNUM;
		for (int i = 0;i < vc.size();i++)//��ί��ּ����ݼ�¼
		{
			vc.at(i).SD.ScoreV.push_back(Score());
			Score& s = vc.at(i).SD.ScoreV.at(roundNum);
			set<float, less<float>>& ss1 = s.m_ScoreSet;
			set<float, less<float>>& ss2 = s.m_SS;

			for (int j = 0;j < num;j++)//ȫ����ί���
			{
				int score = rand() % 41 + 60;
				ss1.insert(score);//�������гɼ�
			}

			vc.at(i).SD.roundNum++;
			copy(++ss1.begin(), --ss1.end(), inserter(ss2, ss2.begin()));//��¼������Ч�ɼ�
			float sSum = 0;
			for_each(ss2.begin(), ss2.end(), [&sSum](float score) {
				sSum += score;
			});
			s.m_TotalScore = sSum;
			s.m_AverageScore = sSum / (JUDGESNUM - 2);
		}
		
		
	}

	//��ʾÿ��ѡ�ֳɼ�
	void showContestantScore(const int& sessionNum, vector<Contestant>& vc, vector<vector<Contestant>>& vvc)
	{
		if (curGNum == 1)//�Ѿ����ɾ������
		{
			cout << "\n---------------------------------------------" << endl;
			cout << "��" << sessionNum + 1 << "�� ������ʼ��" << endl;

			//����
			sort(vc.begin(), vc.end(), [](Contestant c1, Contestant c2) {
				return c1.SD.ScoreV.at(roundNum).m_AverageScore > c2.SD.ScoreV.at(roundNum).m_AverageScore;
				});

			//����ɼ�
			for (int i = 0;i < vc.size();i++)
			{
				showContestant(vc.at(i));
			}
			cout << "\n��" << sessionNum + 1 << "�� ����������"  << endl;
			cout << "---------------------------------------------\n" << endl;
			system("pause");
			system("cls");

			//���ǰ����
			cout << "\n��" << sessionNum + 1 << "�� ǰ����ѡ�֣�" << endl;
			for (int i = 0;i < 3;i++)
			{
				if (i == 0) cout << "�ھ���" << endl;
				if (i == 1) cout << "�Ǿ���" << endl;
				if (i == 2) cout << "������" << endl;
				showContestant(vc.at(i));
			}
			isFinish = true;
			return;
		}

		cout << "\n---------------------------------------------" << endl;
		cout << "��" << sessionNum+1 << "�� ��" << roundNum + 1 << "�ֱ���ѡ�ֿ�ʼ��" << endl;

		//������ʾѡ�ֳɼ�����
		// ����ͽ������򣺰��趨��GROUPNUM�����������з��飬ÿ��ÿ���һ��ѡ�ֽ���������Ϊ����ʱ��������-1
		// ��ÿ�������޷�����ʱ�����µ��˷ֵ�ǰ�������
		// ��ÿ������������4��ʱ�����������룬����Ϊ����ʱ����-1
		// ������ʣ��С�ڵ���2ʱ����һ��Ϊ����
		// ����
		//	100�˲�������ʼ������Ϊ10
		//	��һ�� ����100 ����10 ÿ��10��
		//	�ڶ��� ����50 ����10 ÿ��5��
		//	������ ����20 ����5 ÿ��4��
		//	������ ����10 ����2 ÿ��5��
		//	������ ����4 ����1 ÿ��4��
		//			100		9		8-11  1-12
		//			51      9       3-5   6-6
		//			24		4		4-6
		//			12		2		2-6
		//			6		1
		// 

		
		//ѡ�ַ���������
		vvc.clear();
		contestantSort(vc, vvc);


		int remainder = conNum % curGNum;//���µ�����
		int gNum = 0;//��ǰ���������
		vector<Contestant> v;//��ʱ�������
		int index = 0;//��ʱ��������±�
		int endI = 0;//��һ�η�������λ��

		for (int i = 0;i < conNum;i++)
		{
			if (i == 0)
			{
				cout << "��" << gNum + 1 << "С��������Σ�" << endl;
				v = vvc.at(gNum);
				index = 0;//ÿ�η�����ʱ�������ʱ�������±�
				gNum++;
			}
			if (remainder != 0)//�����µ�����
			{
				if (i == (conNum / curGNum) + endI + 1)
				{
					cout << "��" << gNum + 1 << "С��������Σ�" << endl;
					v = vvc.at(gNum);
					index = 0;//ÿ�η�����ʱ�������ʱ�������±�
					remainder--;
					gNum++;
					endI = i;
				}
			}
			else
			{
				if (i == (conNum / curGNum) + endI)
				{
					cout << "��" << gNum + 1 << "С��������Σ�" << endl;
					v = vvc.at(gNum);
					index = 0;//ÿ�η�����ʱ�������ʱ�������±�
					gNum++;
					endI = i;
				}
			}

			showContestant(v.at(index));
			index++;
		}

		cout << "\n��" << sessionNum+1 << "�� ��" << roundNum + 1 << "�ֱ�������" << endl;
		cout << "---------------------------------------------\n" << endl;
		system("pause");

	}

	//ѡ�ַ���������
	void contestantSort(vector<Contestant>& vc, vector<vector<Contestant>>& vvc)
	{
		int remainder = conNum % curGNum;//���µ�����
		int gNum = 0;//��ǰ������
		int endI = 0;//��һ�η�������λ��

		//����
		for (int i = 0;i < conNum;i++)
		{
			//ʣ�µ��˶���һ��
			if (gNum == curGNum - 1)
			{
				vector<Contestant> v(vc.begin()+ endI, vc.end());
				vvc.push_back(v);
				break;
			}

			//�г���һ���������Ҫ����
			if (remainder != 0)//�����µ�����
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

		//����
		for (int i = 0;i < curGNum;i++)
		{
			vector<Contestant>& v = vvc.at(i);
			sort(v.begin(), v.end(), [](Contestant c1, Contestant c2) {
				return c1.SD.ScoreV.at(roundNum).m_AverageScore > c2.SD.ScoreV.at(roundNum).m_AverageScore;
			});
		}

	}

	//��ӡѡ����Ϣ 0��ӡ��ǰ�ֵ÷���Ϣ 1��ӡѡ�����еĲ����ɼ�
	void showContestant(Contestant c, int flag)
	{
		if (flag == 0)
		{
			cout << "��ţ� " << c.SD.m_ID << " ������" << c.m_Name << "\t�ɼ��� " << c.SD.ScoreV.at(roundNum).m_AverageScore << endl;
		}
		else if (flag == 1)
		{

		}
		else;
	}

	//��̭ѡ��
	void eliminateContestant(vector<Contestant>& vc, vector<vector<Contestant>>& vvc)
	{
		//������ʾѡ�ֳɼ�����
		// ����ͽ������򣺰��趨��GROUPNUM�����������з��飬ÿ��ÿ���һ��ѡ�ֽ���������Ϊ����ʱ��������-1
		// ��ÿ�������޷�����ʱ�����µ��˷ֵ�ǰ�������
		// ��ÿ������������4��ʱ�����������룬����Ϊ����ʱ����-1
		// ����Ϊ1ʱ������Ϊ�����������ǰ��
		// ����
		//	100�˲�������ʼ������Ϊ10
		//	��һ�� ����100 ����10 ÿ��10��
		//	�ڶ��� ����50 ����10 ÿ��5��
		//	������ ����20 ����5 ÿ��4��
		//	������ ����10 ����2 ÿ��5��
		//	������ ����4 ����1 ÿ��4��
		//			100		9		8-11  1-12
		//			51      9       3-5   6-6
		//			24		4		4-6
		//			12		2		2-6
		//			6		1
		// 

		//���������������һ�ַ�����
		int count = 0;

		for (int i = 0;i < vvc.size();i++)
		{
			count += vvc.at(i).size() / 2;
		}
		conNum = count;//��ǰ��ʣ��Ĳ���ѡ��

		while ((conNum / curGNum) < MINCONTESTANTNUM && curGNum !=1)
		{
			curGNum /= 2;
			if (curGNum == 0) curGNum = 1;
		}

		//cout << "��һ��������" << conNum << "��һ��������" << curGNum << endl;


		//��¼����//�ݲ�����
		//������ѡ�����ݴ����map<int, Contestant>& cm


		//��̭��Ա
		vc.clear();
		for (int i = 0;i < vvc.size();i++)
		{
			for (int j = 0;j < vvc.at(i).size();j++)
			{
				if (j < (vvc.at(i).size() / 2))//����
				{
					vc.push_back(vvc.at(i).at(j));
				}
				else break;//ʣ����Ա����ʧ��
			}
		}

	}

	//��ӡ������Ա��Ϣ
	void showPromotedContestant(const int& sessionNum,vector<Contestant>& vc)
	{
		cout << "\n��" << sessionNum + 1 << "�� ��" << roundNum + 1 << "�ֱ�������ѡ�ֹ�"<< vc.size() <<"����" << endl;
		for (int i = 0;i < vc.size();i++)
		{
			showContestant(vc.at(i));
		}

		roundNum++;
		system("pause");
		system("cls");
	}
	
}



