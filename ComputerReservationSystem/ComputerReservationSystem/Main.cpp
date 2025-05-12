#include<iostream>
#include<string>
#include"Manager.h"

using namespace std;
using namespace manager;


//大致流程及功能
//	进入系统
//		读取文件
//			显示菜单
//				学生
//					登录
//						显示菜单
//							修改账号
//							申请预约
//							查看我的预约
//							查看所有预约
//							取消预约
//							注销登录
//				老师
//					登录
//						显示菜单
//							查看所有预约
//							审核预约
//							注销登录
//				管理员
//					登录
//						显示菜单
//							操作账号
//								显示菜单
//									添加账号
//									查看账号
//									修改账号
//									删除账号
//									返回
//							操作机房
//								显示菜单
//									添加机房
//									查看机房
//									修改机房
//									删除机房
//									返回
//							操作预约记录
//								显示菜单
//									添加预约记录
//									查看预约记录
//									修改预约记录
//									删除预约记录
//									清空预约记录
//									返回
//							注销登录
//				退出
//					退出系统
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
		int select = -1;//获取用户选择项
		bool logRet = false;//登录结果
		
		select = c.showMainMenu();

		switch (select)
		{
		case 0://退出
			c.exitSystem();
			break;
		case 1://学生登录
			logRet = c.loginSystem(Identity::Student);
			if (!logRet) system("pause");
			break;
		case 2://老师登录
			logRet = c.loginSystem(Identity::Teacher);
			if (!logRet) system("pause");
			break;
		case 3://管理者登录
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


