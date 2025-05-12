#pragma once
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

#define CONTESTANTNUM 12//����ѡ������
#define JUDGESNUM 10//��ί����
#define GROUPNUM 2//��������
#define MINCONTESTANTNUM 4//����ʱÿ����С����


//�о�ѡ����Ĺ���˼·���е�����
// ѡ����Ͳ�Ӧ�ð�������ĳɼ���ص�����
// ֻ������������ݼ���
// ��Ҫ���ѡ����Ϣʱ�����������ÿ��ĵı���������ѡ�ֺ������Ϣ����
// �����Ļ����԰�ScoreData SD���е�����ֱ�ӷ�ѡ������ ѡ����ᾫ��ܶ�
//

namespace contestant
{
	//�����ú����ѡ������
	//����ʵ��ѭ��������ֱ������ǰ����

	//�ɼ���(��¼��ѡ��һ�ֵı�����¼)
	class Score
	{
	public:
		set<float, less<float>> m_ScoreSet;//�������гɼ�
		set<float, less<float>> m_SS;//������Ч�ɼ�
		float m_TotalScore;//�����ܷ�
		float m_AverageScore;//����ƽ����
		Score():m_TotalScore(0), m_AverageScore(0){}
	};

	//�ɼ�������(��¼��ѡ��һ����ı�����¼)
	class ScoreData
	{
	public:
		int m_ID;//������ԱID�� 10001~10099(��һ��)  20001~20099(�ڶ���)��ʽ����
		int roundNum;//����ı�������
		vector<Score> ScoreV;//ÿ�ֵĵ÷ּ�¼
		ScoreData(){}
		ScoreData(int ID):m_ID(ID), roundNum(0){}
	};

	//ѡ����
	class Contestant
	{
	public:
		string m_Name;//������Ա��ÿ���ظ��� ѡ��1~ѡ��99 ��ʽ����
		ScoreData SD;//����ĵ÷ּ�¼
		int sessionNum;//����ı�������
		vector<ScoreData> ScoreDataV;//ÿ��ĵ÷ּ�¼
		Contestant() {};
		Contestant(string name , int ID):m_Name(name), SD(ID){}
	};

	//��ʼ�ݽ����� ���� sessionNum�������� cm��������ѡ�ּ������б�����¼
	void startContest(const int& sessionNum,map<int, Contestant>& cm);
	void buildContestant(const int& sessionNum, vector<Contestant>& vc);//����ѡ��
	void randGrouping(const int& sessionNum, vector<Contestant>& vc);//�������
	void matchScoring(vector<Contestant>& vc);//��������
	void showContestantScore(const int& sessionNum, vector<Contestant>& vc, vector<vector<Contestant>>& vvc);//��ʾÿ��ѡ�ֳɼ�
	void contestantSort(vector<Contestant>& vc, vector<vector<Contestant>>& vvc);//ѡ�ַ���������
	void showContestant(Contestant c, int flag = 0);//��ӡѡ����Ϣ 0��ӡ��ǰ�ֵ÷���Ϣ 1��ӡѡ�����еĲ����ɼ�
	void eliminateContestant(vector<Contestant>& vc,vector<vector<Contestant>>&vvc);//��̭ѡ��	
	void showPromotedContestant(const int& sessionNum, vector<Contestant>& vc);//��ӡ������Ա��Ϣ
	//��̭ѡ�ֺ��ٽ��з���-����-��̭ѭ����ֱ������ǰ����
}




