#pragma once

#include<iostream>
#include<string>


using namespace std;

namespace templateFileTest {
	template<typename T1, typename T2>
	class Class1
	{
	public:
		T1 m_Val1;
		T2 m_Val2;
		Class1(T1 val1, T2 val2);
		void show();
	};

	//声明和实现写在同一个.hpp文件下
	template<typename T1, typename T2>
	class Class1_1
	{
	public:
		T1 m_Val1;
		T2 m_Val2;
		Class1_1(T1 val1, T2 val2);
		void show();
	};
	template<typename T1, typename T2>
	Class1_1<T1, T2>::Class1_1(T1 val1, T2 val2)
	{
		m_Val1 = val1;
		m_Val2 = val2;
	}
	template<typename T1, typename T2>
	void Class1_1<T1, T2>::show()
	{
		cout << m_Val1 << "\n" << m_Val2 << endl;
	}

}


#include "TemplateFileTest.tpp"









