#include "TemplateFileTest.hpp"

using namespace templateFileTest;


template<typename T1, typename T2>
Class1<T1, T2>::Class1(T1 val1, T2 val2)
{
	m_Val1 = val1;
	m_Val2 = val2;
}

template<typename T1, typename T2>
void Class1<T1, T2>::show()
{
	cout << m_Val1 << "\n" << m_Val2 << endl;
}

//��ʽʵ������ģ��
//template class Class1<string, int>;//���ļ���.hpp�ļ�include�ˣ�û��Ҫ��ʽʵ������ģ��
//.cpp�ļ���Ϊ�Ƕ����ı��뵥Ԫ���ڱ������й����У��ǻᱻ����һ��Ŀ���ļ��ģ���ʽʵ�����󣬿��������ɵ�Ŀ���ļ����ҵ���ģ���ʵ�֣�����.h�ļ����Բ���include����.cpp�ļ���ʹ����ʽʵ�����ķ�ʽʵ����ģ��ķ��ļ���д
//.tpp�ļ����Ƕ����ı��뵥Ԫ���ڱ������й����У��ǲ�������Ŀ���ļ��ģ�����ֻ��ͨ��include�ķ�ʽ������.hpp�ļ��У�������������.hpp�ļ��ĵط������������Ŀ�����ģ���ʵ�֣�������ֻ���������Ų��������Ӵ���


