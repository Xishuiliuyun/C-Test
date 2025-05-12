#pragma once
#include<iostream>
#include<string>
#include"Contestant.h"
#include<map>

using namespace std;


namespace manager
{
	int showMenu();//��ʾ�˵�
	void exitSystem();//�˳�ϵͳ
	//��ʼ�ݽ����� ���� sessionNum�������� cm��������ѡ�ּ������б�����¼
	void startContest(const int& sessionNum, map<int, contestant::Contestant>& cm);
	//��ȡ����������¼ ���� sessionNum�������� cm��������ѡ�ּ������б�����¼ flag��ȡ��ʽ 0����ȡ�������� 1��ȡ������ѡ�ֱ�����¼
	void readContestData(int &sessionNum,map<int, contestant::Contestant>& cm, int flag = 0); 
	void writeContestData(int& sessionNum, map<int, contestant::Contestant>& cm);//��¼��������
	void showContestData();//�鿴������¼ �鿴��������ǰ����
	void findContestData();//���ұ�����¼ 0ͨ�������ڼ�����ʾ 1ͨ��ѡ��ID���� 2ͨ��ѡ����������
	void clearContestDocumeny();//��ձ�����¼

}






