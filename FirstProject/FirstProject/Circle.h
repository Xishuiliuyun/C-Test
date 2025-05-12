#pragma once
#include<iostream>
#include"Point.h"

using namespace std;

//类的分文件编写

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
