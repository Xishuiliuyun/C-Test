#pragma once
#include<iostream>
#include<string>
using namespace std;

//ʵ��һ��ͨ�����͵�������
// 1�����Զ��������������Լ��Զ����������͵����ݽ��д洢
// 2���������е����ݴ洢������
// 3�����캯���п��Դ������������
// 4���ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
// 5���ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
// 6������ͨ���±�ķ�ʽ���������е�Ԫ��
// 7�����Ի�ȡ�����е�ǰԪ�ظ��������������
//
template<typename T>
class MyArr
{
public:
	MyArr(int capacity)
	{
		//cout << "���캯��" << endl;
		m_Capacity = capacity;
		m_Len = 0;
		//m_Size = 0;
		pAddress = new T[capacity];
	}
	//�������캯��
	MyArr(const MyArr& other)
	{
		//cout << "�������캯��" << endl;
		this->m_Capacity = other.m_Capacity;
		this->m_Len = other.m_Len;
		//this->m_Size = other.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0;i < this->m_Len;i++)
		{
			pAddress[i] = other.pAddress[i];
		}
	}
	//=���������
	MyArr& operator=(const MyArr& other)
	{
		//cout << "=���������" << endl;
		if (this == &other)//�Ը�ֵ���
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
	//β��
	void Push_Back(const T& val)
	{
		if (this->m_Len < this->m_Capacity)
		{
			pAddress[this->m_Len] = val;
			this->m_Len++;
		}
		else cout << "�����������" << endl;
		return;
	}
	//βɾ
	T Del_Back()
	{
		if (this->m_Len == 0) return T{};
		T temp = pAddress[this->m_Len - 1];
		pAddress[this->m_Len - 1] = T{};
		this->m_Len--;
		return temp;
	}
	//����[]�����
	T& operator[](int index)
	{
		return pAddress[index];
	}
	//������������
	int getCapacity()
	{
		return m_Capacity;
	}
	//����Ԫ�ظ���
	int getLen()
	{
		return m_Len;
	}
	~MyArr()
	{
		if (pAddress != nullptr)
		{
			//cout << "��������" << endl;
			delete[] pAddress;
			pAddress = nullptr;
		}
	}

private:
	T* pAddress;//�����׵�ַ
	int m_Capacity;//��������
	int m_Len;//Ԫ�ظ���
	//int m_Size;//�����С
};