#include"Manager.h"


namespace manager
{
	//��ʾ�˵�
	int showMenu()
	{
		cout << "********************************************" << endl;
		cout << "************��ӭʹ���ݽ�����ϵͳ************" << endl;
		cout << "************	0�˳�����ϵͳ	************" << endl;
		cout << "************	1��ʼ�ݽ�����	************" << endl;
		cout << "************	2�鿴������¼	************" << endl;
		cout << "************	3��ձ�����¼	************" << endl;
		cout << "********************************************" << endl;
		cout << "��ѡ����" << endl;
		cout << endl;

		int select;
		cin >> select;

		return select;
	}

	//�˳�ϵͳ
	void exitSystem()
	{
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		exit(0);
	}

	//��ʼ�ݽ����� ���� sessionNum�������� cm��������ѡ�ּ������б�����¼
	void startContest(const int& sessionNum, map<int, contestant::Contestant>& cm)
	{
		contestant::startContest(sessionNum,cm);
	}


	//��ȡ����������¼ ���� sessionNum�������� cm��������ѡ�ּ������б�����¼ flag��ȡ��ʽ 0����ȡ�������� 1��ȡ������ѡ�ֱ�����¼
	void readContestData(int& sessionNum, map<int, contestant::Contestant>& cm ,int flag)
	{


	}

	//��¼��������
	void writeContestData(int& sessionNum, map<int, contestant::Contestant>& cm)
	{



	}




	//void showContestData();//�鿴������¼
	//void clearContestDocumeny();//��ձ�����¼





















}





