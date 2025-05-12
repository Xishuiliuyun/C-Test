#pragma once
#include <iostream>
#include <string>
using namespace std;



template<typename T1, typename T2>
class Class12
{
public:
	T1 m_Val1;
	T2 m_Val2;
	Class12(T1 val1, T2 val2);
	void show();
};

template<typename T1, typename T2>
class Class12_1
{
public:
	T1 m_Val1;
	T2 m_Val2;
	Class12_1(T1 val1, T2 val2);
	void show();
};


//∆’Õ®¿‡≤‚ ‘
class Class12_2
{
public:
	string m_Val1;
	int m_Val2;
	Class12_2(string val1, int val2);
	void show();
};
