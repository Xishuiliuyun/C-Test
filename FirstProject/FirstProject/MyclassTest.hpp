#pragma once
#include<iostream>
#include<string>
using namespace std;

//实现一个通用类型的数组类
// 1、可以对内置数据类型以及自定义数据类型的数据进行存储
// 2、将数组中的数据存储到堆区
// 3、构造函数中可以传入数组的容量
// 4、提供对应的拷贝构造函数以及operator=防止浅拷贝问题
// 5、提供尾插法和尾删法对数组中的数据进行增加和删除
// 6、可以通过下标的方式访问数组中的元素
// 7、可以获取数组中当前元素个数和数组的容量
//
template<typename T>
class MyArr
{
public:
	MyArr(int capacity)
	{
		//cout << "构造函数" << endl;
		m_Capacity = capacity;
		m_Len = 0;
		//m_Size = 0;
		pAddress = new T[capacity];
	}
	//拷贝构造函数
	MyArr(const MyArr& other)
	{
		//cout << "拷贝构造函数" << endl;
		this->m_Capacity = other.m_Capacity;
		this->m_Len = other.m_Len;
		//this->m_Size = other.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0;i < this->m_Len;i++)
		{
			pAddress[i] = other.pAddress[i];
		}
	}
	//=运算符重载
	MyArr& operator=(const MyArr& other)
	{
		//cout << "=运算符重载" << endl;
		if (this == &other)//自赋值检查
		{
			return *this;
		}
		this->m_Capacity = other.m_Capacity;
		this->m_Len = other.m_Len;
		//this->m_Size = other.m_Size;
		if (this->pAddress != nullptr)
		{
			delete[] this->pAddress;
			this->pAddress = nullptr;
		}
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0;i < this->m_Len;i++)
		{
			pAddress[i] = other.pAddress[i];
		}
		return *this;
	}
	//尾插
	void Push_Back(const T& val)
	{
		if (this->m_Len < this->m_Capacity)
		{
			pAddress[this->m_Len] = val;
			this->m_Len++;
		}
		else cout << "数组队列已满" << endl;
		return;
	}
	//尾删
	T Del_Back()
	{
		if (this->m_Len == 0) return T{};
		T temp = pAddress[this->m_Len - 1];
		pAddress[this->m_Len - 1] = T{};
		this->m_Len--;
		return temp;
	}
	//重载[]运算符
	T& operator[](int index)
	{
		return pAddress[index];
	}
	//返回数组容量
	int getCapacity()
	{
		return m_Capacity;
	}
	//返回元素个数
	int getLen()
	{
		return m_Len;
	}
	~MyArr()
	{
		if (pAddress != nullptr)
		{
			//cout << "析构函数" << endl;
			delete[] pAddress;
			pAddress = nullptr;
		}
	}

private:
	T* pAddress;//数组首地址
	int m_Capacity;//数组容量
	int m_Len;//元素个数
	//int m_Size;//数组大小
};