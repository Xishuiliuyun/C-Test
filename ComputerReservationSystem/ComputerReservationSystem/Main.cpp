#include<iostream>
#include<string>
#include"Manager.h"

using namespace std;
using namespace manager;


//�������̼�����
//	����ϵͳ
//		��ȡ�ļ�
//			��ʾ�˵�
//				ѧ��
//					��¼
//						��ʾ�˵�
//							�޸��˺�
//							����ԤԼ
//							�鿴�ҵ�ԤԼ
//							�鿴����ԤԼ
//							ȡ��ԤԼ
//							ע����¼
//				��ʦ
//					��¼
//						��ʾ�˵�
//							�鿴����ԤԼ
//							���ԤԼ
//							ע����¼
//				����Ա
//					��¼
//						��ʾ�˵�
//							�����˺�
//								��ʾ�˵�
//									����˺�
//									�鿴�˺�
//									�޸��˺�
//									ɾ���˺�
//									����
//							��������
//								��ʾ�˵�
//									��ӻ���
//									�鿴����
//									�޸Ļ���
//									ɾ������
//									����
//							����ԤԼ��¼
//								��ʾ�˵�
//									���ԤԼ��¼
//									�鿴ԤԼ��¼
//									�޸�ԤԼ��¼
//									ɾ��ԤԼ��¼
//									���ԤԼ��¼
//									����
//							ע����¼
//				�˳�
//					�˳�ϵͳ
// 
// 
// 
// 
//



int main()
{
	Control c;


	while (1)
	{
		int select = -1;//��ȡ�û�ѡ����
		bool logRet = false;//��¼���
		
		select = c.showMainMenu();

		switch (select)
		{
		case 0://�˳�
			c.exitSystem();
			break;
		case 1://ѧ����¼
			logRet = c.loginSystem(Identity::Student);
			if (!logRet) system("pause");
			break;
		case 2://��ʦ��¼
			logRet = c.loginSystem(Identity::Teacher);
			if (!logRet) system("pause");
			break;
		case 3://�����ߵ�¼
			logRet = c.loginSystem(Identity::Manager);
			if(!logRet) system("pause");
			break;
		default:
			system("cls");
			break;
		}

		system("cls");




	}
	





	system("pause");
}


