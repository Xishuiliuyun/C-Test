#pragma once
#include<iostream>
#include"Point.h"

using namespace std;

//��ķ��ļ���д

class Circle2
{
	Point m_Center;
	int m_R;

public:
	void setR(int r);
	int getR();
	void setCenter(Point center);
	Point getCenter();
};
