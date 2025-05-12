#include"Circle.h"

//类的分文件编写

void Circle2::setR(int r)
{
	m_R = r;
}
int Circle2::getR()
{
	return m_R;
}
void Circle2::setCenter(Point center)
{
	m_Center = center;
}
Point Circle2::getCenter()
{
	return m_Center;
}