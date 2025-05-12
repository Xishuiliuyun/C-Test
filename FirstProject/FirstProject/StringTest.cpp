#include "StringTest.h"

namespace 
{
	//string����
	void fun1()
	{
		cout << "\n\nTest_fun1" << endl;

		// ���캯������
		string s1();
		//cout << s1 << endl;
		string s2("123123");
		cout << s2 << endl;
		cout << s2.c_str() << endl;
		string s3(s2);
		cout << s3 << endl;
		string s4(3, '4');
		cout << s4 << endl;
		string s5(s2.begin(), s2.end());
		cout << s5 << endl;
		string s6(s2, 1);//��s2�ĵڼ����ַ���ʼ����
		cout << s6 << endl;
		string s7(move(s2));
		cout << s7 << endl;
		char s8[] = "444555";
		string s9(s8, 2);
		cout << s9 << endl;
	}

	//��ֵ����
	void fun2()
	{
		cout << "\n\nTest_fun2" << endl;
		//����ԭ�ͣ�
		// string& operator=(const char* s);//char*�����ַ�����ֵ
		// string& operator=(const string& s);//string�����ַ�����ֵ
		// string& operator=(char s);//char�����ַ���ֵ
		// string& assign(const char* s)//���ַ�����ֵ�����ú����Ķ���
		// string& assign(const char* s,int n)//���ַ���s��ǰn���ַ�����ֵ�����ú����Ķ���
		// string& assign(const string& s)//���ַ�����ֵ�����ú����Ķ���
		// string& assign(int n,char c)//��n���ַ�c��ֵ�����ú����Ķ���
		
		string s1;
		char s2[] = "111";
		s1 = s2;
		cout << s1 << endl;
		string s3("222");
		s1 = s3;
		cout << s1 << endl;
		s1 = 'a';
		cout << s1 << endl;
		s1.assign(s2);
		cout << s1 << endl;
		s1.assign(s2, 2);
		cout << s1 << endl;
		s1.assign(s3);
		cout << s1 << endl;
		s1.assign(3, '3');
		cout << s1 << endl;

		cout << &("a") << endl;
	}

	//�ַ���ƴ��
	void fun3()
	{
		cout << "\n\nTest_fun3" << endl;

		//����ԭ�ͣ�
		// string& operator+=(const char* s);//char*�����ַ���ƴ��
		// string& operator+=(const string& s);//string�����ַ���ƴ��
		// string& operator+=(char s);//char�����ַ�ƴ��
		// string& append(const char* s)//���ַ���ƴ�ӵ����ú����Ķ����β
		// string& append(const char* s,int n)//���ַ���s��ǰn���ַ���ƴ�ӵ����ú����Ķ����β
		// string& append(const string& s)//���ַ���ƴ�ӵ����ú����Ķ����β
		// string& append(const string& s,int pos,int n)//���ַ���s��pos��ʼ��n���ַ���ƴ�ӵ����ú����Ķ����β

		string s1;
		string s2;
		s1 += "111";
		s2 = s1 + "111";
		cout << s1 << endl;
		cout << s2 << endl;
		s1 += s1;
		s2 = s1 + s1;
		cout << s1 << endl;
		cout << s2 << endl;
		s1 += 'a';
		s2 = s1 + 'a';
		cout << s1 << endl;
		cout << s2 << endl;

		cout << endl;
		string s3;
		s3.append("222");
		cout << s3 << endl;
		s3.append("333", 2);
		cout << s3 << endl;
		s3.append(s3);
		cout << s3 << endl;
		s3.append(s3, 1, 3);
		cout << s3 << endl;
	}

	//string���Һ��滻
	void fun4()
	{
		cout << "\n\nTest_fun4" << endl;
		//���ң�����ָ���ַ����Ƿ����
		//�滻����ָ����λ���滻�ַ���
		// 
		// ����ԭ�ͣ�
		// //find��0λ�ò鵽���һ���ַ�������û�ҵ�����-1
		// int find(const string& str,int pos =0) const //����str��һ�γ���λ�ã���pos��ʼ����
		// int find(const char* s,int pos =0) const //����s��һ�γ���λ�ã���pos��ʼ����
		// int find(const char* s,int pos ,int n) const //��posλ�ò���s��ǰn���ַ���һ�γ���λ��
		// int find(char c,int pos = 0) const //�����ַ�c��һ�γ���λ�ã���pos��ʼ����
		// //rfind�����һ���ַ��鵽0������û�ҵ�����-1
		// int rfind(const string& str,int pos =npos) const //����str���һ�γ���λ�ã���pos��ʼ����//Ĭ�ϴ����ʼ����
		// int rfind(const char* s,int pos =npos) const //����s���һ�γ���λ�ã���pos��ʼ����//Ĭ�ϴ����ʼ����
		// int rfind(const char* s,int pos,int n) const //��posλ�ò���s��ǰn���ַ����һ�γ���λ��
		// int rfind(char c,int pos = npos) const //�����ַ�c���һ�γ���λ�ã���pos��ʼ����
		// //replace�������Ϊ������pos��ʼ��n���ַ�ɾ��,�ٴ�posλ�ò����ַ���
		// string& replace(int pos, int n, const string& str) //�滻��pos��ʼn���ַ�Ϊ�ַ���str
		// string& replace(int pos, int n, const char* s) //�滻��pos��ʼn���ַ�Ϊ�ַ���s

		string s1("123456aabbccddaabbccdd");
		int pos = 0;
		string s2 = "aa";
		pos = s1.find(s2);
		cout << pos << endl;
		pos = s1.find("bb");
		cout << pos << endl;
		pos = s1.find("ccc", 0, 2);
		cout << pos << endl;
		pos = s1.find('d');
		cout << pos << endl;

		cout << endl;
		pos = s1.rfind(s2);
		cout << pos << endl;
		pos = s1.rfind("bb");
		cout << pos << endl;
		//pos = s1.rfind("ccc", 0, 2);//�൱��û�в��ң�ֱ�ӽ����ˣ��᷵��-1
		pos = s1.rfind("ccc", s1.length(), 2);
		cout << pos << endl;
		pos = s1.rfind('d');
		cout << pos << endl;

		cout << endl;
		cout << s1 << endl;
		s1.replace(0, 2, s2);
		cout << s1 << endl;
		s1.replace(2, 2, "bb");
		cout << s1 << endl;
		//�������Ϊ������pos��ʼ��n���ַ�ɾ��,�ٴ�posλ�ò���str�ַ���
		s1.replace(0, 2, "1111");//�滻���ַ������ַ������࣬�����ַ�����ȫ���滻��ȥ
		cout << s1 << endl;
		s1.replace(0, 4, "12");//�滻���ַ������ַ������٣�Ҳֻ��������ַ���ȫ���滻��ȥ�������ظ�
		cout << s1 << endl;
	}

	//string�ַ����Ƚ�
	void fun5()
	{
		cout << "\n\nTest_fun5" << endl;
		//�ַ����Ƚ�compare����Ҫ�����ж������ַ����Ƿ���ͬ
		// ���ַ���ASCII����бȽ�
		// ==����0 >����1 <����-1
		// ����ԭ�ͣ�
		// int compare(const string& str) const //string�����ַ����Ƚ�
		// int compare(const char* s) const //char*�����ַ����Ƚ�

		string str = "abc";
		string str2;
		str2 = "abc";
		cout << str.compare(str2) << endl;
		cout << str.compare("abc") << endl;
		cout << str.compare("ABC") << endl;
		cout << str.compare("123") << endl;
		cout << str.compare("bbc") << endl;
		cout << str.compare("acd") << endl;

	}

	//string�ַ�������ȡ
	void fun6()
	{
		cout << "\n\nTest_fun6" << endl;
		//����ԭ�ͣ�
		//char& opreator[](int n) //ͨ��[]��ʽȡ�ַ�//������б߽���ж�
		//char& at(int n) //ͨ��at������ȡ�ַ�//����б߽���ж�
		string s1 = "123abc";
		for (int i = 0;i < s1.length();i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
		for (int i = 0;i < s1.length();i++)
		{
			cout << s1.at(i) << " ";
		}
		cout << endl;

		cout << s1 << endl;
		s1[0] = '2';
		cout << s1 << endl;
		s1.at(2) = '2';
		cout << s1 << endl;
		//cout << s1[100] << endl;//���к󱨴�
		//cout << s1.at(100) << endl;//���к󱨴������򲻻����

		char s2[10] ;
		strcpy_s(s2, "123abc");
		char s3[10] = "123abc";
		for (int i = 0;i < sizeof(s2);i++)
		{
			cout << i << "s2 : " << (int)(s2[i]) << endl;
			cout << i << "s3 : " << (int)(s3[i]) << endl;
		}
		for (int i = 0;i < strlen(s2);i++)
		{
			cout << i << " : " << s2[i] << endl;
		}
	}

	//string�����ɾ��
	void fun7()
	{
		cout << "\n\nTest_fun7" << endl;
		//���ַ������в����ɾ���ַ�������
		// ����ԭ��:
		// string& insert(int pos,const char* s) //��posλ�ò����ַ���
		// string& insert(int pos,const string& s) //��posλ�ò����ַ���
		// string& insert(int pos,int n,char c) //��posλ�ò���n���ַ�c
		// string& erase(int pos, int n = npos) //ɾ����posλ�ÿ�ʼ��n���ַ�

		string s1 = "123abc";
		string s2 = "dd";
		cout << s1 << endl;
		s1.insert(0, "a");
		cout << s1 << endl;
		s1.insert(1, s2);
		cout << s1 << endl;
		s1.insert(2, 3, 'e');
		cout << s1 << endl;
		s1.erase(4,2);
		cout << s1 << endl;
		s1.erase(2);
		cout << s1 << endl;
	}

	//string�Ӵ�
	void fun8()
	{
		cout << "\n\nTest_fun8" << endl;
		//string�Ӵ�
		//���ַ����л�ȡ��Ҫ���Ӵ�
		//����ԭ�ͣ�
		//string substr(int pos =0 ,int n = npos)const //���ش�pos��ʼ��n���ַ���ɵ��ַ���
		string s1 = "123123abc";
		string s2;
		s2 = s1.substr(0, 6);
		cout << s2 << endl;

		string s3 = "zhangsan@sina.com";
		string s4 = s3.substr(0, s3.find('@'));
		cout << s4 << endl;
	}
}

void testString()
{
	//string����
	// string��char*������
	// char*��һ��ָ��(C�����ַ���)
	// string��һ���࣬���ڲ���װ��char*�����ַ������й���
	// string�ṩ�˺ܶ��Ա�������ṩ�˷ḻ���ַ�����������
	// 
	// ���캯����
	// string() Ĭ�Ϲ�����ַ���
	//	ʾ����std::string s1;
	// string(const char*) ��C����ַ�������
	//	ʾ����std::string s2("hello");
	// string(const string&) ��������
	//	ʾ����std::string s3(s2);
	// string(size_t, char) �ظ��ַ�����
	//	ʾ����std::string s4(5, 'a'); // "aaaaa"
	// string(InputIt first, InputIt last) �ӵ�������Χ����
	//	ʾ����std::string s5(s2.begin(), s2.end());
	// string(string&&) �ƶ����� (C++11)
	//	ʾ����std::string s6(std::move(s5));
	// string(const string& str, size_t pos = 0, size_t count = npos) �Ӵ����캯��
	//	������str��Դ�ַ����������� std::string ���ͣ�
	//		  pos����ʼλ�ã�Ĭ��Ϊ 0��
	//		  count��Ҫ���Ƶ��ַ�������Ĭ��Ϊ npos�������Ƶ��ַ���ĩβ��
	//	ʾ����std::string s7(s2, 1);//"ello"
	// string(const char* s, size_t count); ָ��+���ȹ��캯��
	//	������s��Դ�ַ����飨const char* ���ͣ�
	//		  count��Ҫ���Ƶ��ַ�����
	//	ʾ����char s8[] = "444555";
	//		  string s9(s8, 2);//"44"
	// 
	// ��Ա������
	//	������أ�
	//	size()/length()	�����ַ�����	s.size()
	//	capacity()	���ش洢����	s.capacity()
	//	empty()	����Ƿ�Ϊ��	if(s.empty())
	//	reserve(size_t)	Ԥ���洢�ռ�	s.reserve(100)
	//	shrink_to_fit()	������������Ӧ��С (C++11)	s.shrink_to_fit()
	//	Ԫ�ط��ʣ�
	//	operator[]	�޼�����	char c = s[0]
	//	at(size_t)	�б߽���ķ���	char c = s.at(0)
	//	front()	�������ַ� (C++11)	char c = s.front()
	//	back()	����ĩ�ַ� (C++11)	char c = s.back()
	//  data()	���صײ��ַ����� (C++11 ��֤�Կ��ַ���β)	const char* p = s.data()
	//  c_str()	���� C ����ַ���	const char* p = s.c_str()
	//  �޸Ĳ�����
	//	operator=	��ֵ����	s = "new"
	//  assign()	�������صĸ�ֵ	s.assign(3, 'x')
	//  append()	׷������	s.append(" world")
	//  push_back(char)	׷�ӵ����ַ�	s.push_back('!')
	//  pop_back()	ɾ��ĩβ�ַ� (C++11)	s.pop_back()
	//  insert()	��������	s.insert(0, "Hello ")
	//  erase()	ɾ������	s.erase(0, 5)
	//  replace()	�滻����	s.replace(0, 5, "Hi")
	//  clear()	�������	s.clear()
	//  resize()	������С	s.resize(10, ' ')
	//  swap(string&)	��������	s1.swap(s2)
	//  �ַ���������
	//	find()	�����Ӵ�/�ַ�	s.find("lo")
	//  rfind()	�������	s.rfind('l')
	//  find_first_of()	�����ַ�������һ�ַ��״γ���	s.find_first_of("abc")
	//  find_last_of()	�����ַ�������һ�ַ�������	s.find_last_of("abc")
	//  find_first_not_of()	���Ҳ����ַ����е��ַ��״γ���	s.find_first_not_of(" ")
	//  find_last_not_of()	���Ҳ����ַ����е��ַ�������	s.find_last_not_of(" ")
	//  substr()	��ȡ�Ӵ�	s.substr(1, 3)
	//  compare()	�Ƚ��ַ���	s.compare("hello")
	//  �ǳ�Ա������
	//  operator+	�ַ�������	s = s1 + s2
	//  operator== ��	�Ƚ������	if(s1 == s2)
	//  std::getline()	�����ж�ȡһ��	std::getline(std::cin, s)
	//  std::stoi() ��	�ַ���ת��	int i = std::stoi("42")
	//  std::to_string()	��ֵת�ַ���	std::string s = std::to_string(3.14)
	//  ������֧�֣�
	//	std::string ֧�����б�׼����������
	// 
	//

	fun1();

	//��ֵ����
	fun2();

	//�ַ���ƴ��
	fun3();

	//string���Һ��滻
	fun4();

	//string�ַ����Ƚ�
	fun5();

	//string�ַ�������ȡ
	fun6();

	//string�����ɾ��
	fun7();

	//string�Ӵ�
	fun8();
}
