#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include"Manager.h"

using namespace std;
using namespace manager;

//ʣ�๦�ܲ���Ҫ�Ҳ��Ǻ���ʵ�֣���ǰ���ټ�������
//δ��ɵĹ�����
// ��ȡ����������¼
// ÿ�����ʱ��¼ѡ�ֵ�������Ϣ�洢��CMap��ͨ�����ҵ���Ӧ��ѡ�֣���ѡ�ֵ�ÿ��ĵ÷ּ�¼���������
// ÿ�����������д��ÿ�����������
// �鿴������¼(Ĭ����ʾ���������ǰ����)������ѡ��鿴ĳһ������б�����¼
// ���ұ�����¼������ѡ�����ĳ�˺���ʾ��ѡ�ֵ����б�����¼
// ��ձ�����¼
// һЩ������ʱû��ʹ���ϣ���int sessionNum;//����ı���������int roundNum;//����ı�����������ʵ����Ҳ���ԣ���������size���Կɻ�ȡ����Щ����
// 
//


//��ʱ�Ȳ�����ѡ�����ݶ�ȡ��ص�����
//�Ȱ�vector����ÿ�������ѡ�ֵı�����¼  map����һ��� ����ѡ�ּ������б�����¼ �ķ�ʽ�������ݴ洢
//��Ŀ��ɺ��ٿ����Ƿ����Ż��ռ�

//Ӧ�ý���ͬ�������ò�ͬ���������д洢��(����û��Ҫ�������ֵ���������÷�ʽ�洢�Ļ���ʵ��Ӧ��ֻ��һ������)
// ѡ�ֱ�--map��������-ѡ��ΨһID ֵ-��ѡ�����б�����¼ ��¼ѡ�ֵı�����¼
// ÿ�������--vector������ ��¼���в�����ѡ��
//

int main()
{
	int sessionNum = 0;//���ڼ�¼���������˶��ٽ�
	map<int, contestant::Contestant> CMap;//���ڷ���һ��� ����ѡ�ּ������б�����¼
	vector<map<int, contestant::Contestant>> sessionV;//���ڷ���ÿ��� ����ѡ�ּ������б�����¼

	//��ȡ����������¼
	readContestData(sessionNum,CMap);

	//�������������
	//srand((unsigned int)time(NULL));

	while (1)
	{
		//��ʾ�˵�
		int select = showMenu();

		switch (select)
		{
		case 0://�˳�ϵͳ
			exitSystem();
			break;
		case 1://��ʼ�ݽ�����
			manager::startContest(sessionNum,CMap);
			sessionNum++;
			writeContestData(sessionNum, CMap);
			system("pause");
			system("cls");
			break;
		case 2://�鿴������¼
			system("pause");
			system("cls");
			break;
		case 3://���ұ�����¼
			system("pause");
			system("cls");
			break;
		case 4://��ձ�����¼
			system("pause");
			system("cls");
			break;
		default://���������������
			system("cls");
			break;
		}
		
	}










}





