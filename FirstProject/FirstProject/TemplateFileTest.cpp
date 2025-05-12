#include "TemplateFileTest.h"



template<typename T1, typename T2>
Class12<T1, T2>::Class12(T1 val1, T2 val2)
{
	m_Val1 = val1;
	m_Val2 = val2;
}
template<typename T1, typename T2>
void Class12<T1, T2>::show()
{
	cout << m_Val1 << "\n" << m_Val2 << endl;
}

//显式实例化类模板测试
template class Class12<string, int>;


//直接包含.cpp源文件测试
template<typename T1, typename T2>
Class12_1<T1, T2>::Class12_1(T1 val1, T2 val2)
{
	m_Val1 = val1;
	m_Val2 = val2;
}
template<typename T1, typename T2>
void Class12_1<T1, T2>::show()
{
	cout << m_Val1 << "\n" << m_Val2 << endl;
}


//普通类测试
//Class12_2::Class12_2(string val1, int val2)
//{
//	m_Val1 = val1;
//	m_Val2 = val2;
//}
//void Class12_2::show()
//{
//	cout << m_Val1 << "\n" << m_Val2 << endl;
//}