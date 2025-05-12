#include <iostream>
#include <cstdio>
#include <ctime>
#include "TestFile.h"
#include "Second.h"
#include "ClassAndObject.h"
#include "InheritTest.h"
#include "PolymorphismTest.h"
#include "FileTest.h"
#include "TemplateTest.h"
#include "STLTest.h"
#include "StringTest.h"
#include"VectorTest.h"
#include"DequeTest.h"
#include"Stack_Queue_Test.h"
#include"LeetCodeTest.h"
#include"ListTest.h"
#include"LeftProjectTest.h"
using namespace std;

#define Day 7//#define�궨��ĳ���

void Test();
void HelloWorld();
int DataType();
void EscapeCharacter();
void TestCin();
void TestIncremental();
void Practice1();
void TestPointer();
void TestMalloc();
void TestStruct();
void TestStructArr();

int main()
{
    //testLeetCode();

    //Test();

    //HelloWorld();

    //DataType();

    //EscapeCharacter();

    //TestCin();

    //TestIncremental();

    //Practice1();

    //TestPointer();

    //TestMalloc();

    //TestStruct();

    //TestStructArr();

    //TestMemory();

    //TestQuote();

    //TestFunction();

    //TestClass();

    //testInherit();

    //testPolymorphism();

    //testFile();

    //testTemplate();

    //testSTL();

    //testString();

    //testVector();

    //testDeque();

    //testStackQueue();

    //testList();

    testLeftProject();

	system("pause");
	return 0;
}

//hello world
void HelloWorld()
{
    cout << "hello world" << endl;

    int a = 1;
    cout << "a = " << a << endl;

    const int month = 12;//const���εķ�ʽ���峣��
}

//�����������
int DataType()
{
	//����
	//������short
	short num1 = 10;
	//����int
	int num2 = 20;
	//������long
	long num3 = 30;
	//��������long long(long�������������ͣ�Ҳ���������η�,�˴���һ��long�����η����ڶ�������������)
	long long num4 = 40;
	//�˴�longΪ���η�����ʾ������
	long int num5 = 50;
	//���η�����signed��ʾ��������������
	//unsigned��ʾ�޷������ͣ�ֻ������
	//short��ʾ������
	//long��ʾ������
	//const��ʾ������ֵ�����޸�
	//volatile��ʾ�������ܱ������޸ģ���ֹ�������Ż�
	//mutable��ʾ���Ա������ const �������޸�

    //������
    //float������4�ֽ�
    float f1 = 3.14f;
    //double˫����8�ֽ�
    double d1 = 3.14;

    //�ַ���
    //charռ��1�ֽڣ����ڴ��д�����ַ���Ӧ��ASCII��
    char ch = 'a';//ֻ�ܷ�һ���ַ�����ֻ���õ�����

    //�ַ���
    //C���Ե��ַ���
    char str1[] = "hello world";
    //C++���ַ���
    string str2 = "hello world";

    //����ֵbool
    bool flag1 = true;
    bool flag2 = false;
    
    //�������
    cout << "type: \t\t" << "************size**************" << endl;
    cout << "bool: \t\t" << "��ռ�ֽ�����" << sizeof(bool);
    cout << "\t���ֵ��" << (numeric_limits<bool>::max)();
    cout << "\t\t��Сֵ��" << (numeric_limits<bool>::min)() << endl;
    cout << "char: \t\t" << "��ռ�ֽ�����" << sizeof(char);
    cout << "\t���ֵ��" << (numeric_limits<char>::max)();
    cout << "\t\t��Сֵ��" << (numeric_limits<char>::min)() << endl;
    cout << "signed char: \t" << "��ռ�ֽ�����" << sizeof(signed char);
    cout << "\t���ֵ��" << (numeric_limits<signed char>::max)();
    cout << "\t\t��Сֵ��" << (numeric_limits<signed char>::min)() << endl;
    cout << "unsigned char: \t" << "��ռ�ֽ�����" << sizeof(unsigned char);
    cout << "\t���ֵ��" << (numeric_limits<unsigned char>::max)();
    cout << "\t\t��Сֵ��" << (numeric_limits<unsigned char>::min)() << endl;
    cout << "wchar_t: \t" << "��ռ�ֽ�����" << sizeof(wchar_t);
    cout << "\t���ֵ��" << (numeric_limits<wchar_t>::max)();
    cout << "\t\t��Сֵ��" << (numeric_limits<wchar_t>::min)() << endl;
    cout << "short: \t\t" << "��ռ�ֽ�����" << sizeof(short);
    cout << "\t���ֵ��" << (numeric_limits<short>::max)();
    cout << "\t\t��Сֵ��" << (numeric_limits<short>::min)() << endl;
    cout << "int: \t\t" << "��ռ�ֽ�����" << sizeof(int);
    cout << "\t���ֵ��" << (numeric_limits<int>::max)();
    cout << "\t��Сֵ��" << (numeric_limits<int>::min)() << endl;
    cout << "unsigned: \t" << "��ռ�ֽ�����" << sizeof(unsigned);
    cout << "\t���ֵ��" << (numeric_limits<unsigned>::max)();
    cout << "\t��Сֵ��" << (numeric_limits<unsigned>::min)() << endl;
    cout << "long: \t\t" << "��ռ�ֽ�����" << sizeof(long);
    cout << "\t���ֵ��" << (numeric_limits<long>::max)();
    cout << "\t��Сֵ��" << (numeric_limits<long>::min)() << endl;
    cout << "unsigned long: \t" << "��ռ�ֽ�����" << sizeof(unsigned long);
    cout << "\t���ֵ��" << (numeric_limits<unsigned long>::max)();
    cout << "\t��Сֵ��" << (numeric_limits<unsigned long>::min)() << endl;
    cout << "double: \t" << "��ռ�ֽ�����" << sizeof(double);
    cout << "\t���ֵ��" << (numeric_limits<double>::max)();
    cout << "\t��Сֵ��" << (numeric_limits<double>::min)() << endl;
    cout << "long double: \t" << "��ռ�ֽ�����" << sizeof(long double);
    cout << "\t���ֵ��" << (numeric_limits<long double>::max)();
    cout << "\t��Сֵ��" << (numeric_limits<long double>::min)() << endl;
    cout << "float: \t\t" << "��ռ�ֽ�����" << sizeof(float);
    cout << "\t���ֵ��" << (numeric_limits<float>::max)();
    cout << "\t��Сֵ��" << (numeric_limits<float>::min)() << endl;
    cout << "size_t: \t" << "��ռ�ֽ�����" << sizeof(size_t);
    cout << "\t���ֵ��" << (numeric_limits<size_t>::max)();
    cout << "\t��Сֵ��" << (numeric_limits<size_t>::min)() << endl;
    cout << "string: \t" << "��ռ�ֽ�����" << sizeof(string) << endl;
    // << "\t���ֵ��" << (numeric_limits<string>::max)() << "\t��Сֵ��" << (numeric_limits<string>::min)() << endl;  
    cout << "type: \t\t" << "************size**************" << endl;
    return 0;

}

//ת���ַ�
void EscapeCharacter()
{
    //���� \n
    cout << "\n���в���\n";

    //��б�� \\

    cout<<"\\��б�ܲ���\n";

    //�Ʊ�� \t
    cout << "\t�Ʊ������\t111\n";

    //�ַ���������־ \0
    cout << "�ַ�������\0����\n";

}

//Cin,�����������
void TestCin()
{
    int num = 0;
    float f = 3.14f;
    char ch = 'a';
    string str = "123";
    bool flag = true;

    cout << "����������� int" << endl;
    cin >> num;
    cout << "����������� int��ǰֵΪ"<<num << endl;

    cout << "����������� float" << endl;
    cin >> f;
    cout << "����������� float��ǰֵΪ" << f << endl;

    cout << "����������� char" << endl;
    cin >> ch;
    cout << "����������� char��ǰֵΪ" << ch << endl;

    cout << "����������� string" << endl;
    cin >> str;
    cout << "����������� string��ǰֵΪ" << str << endl;

    cout << "����������� bool" << endl;
    cin >> flag;
    cout << "����������� bool��ǰֵΪ" << flag << endl;

}

//++ --����
void TestIncremental()
{
    int num1 = 10;
    int num2 = 10;

    int num3 = ++num1 * 10;
    int num4 = num2++ * 10;

    cout << "++numTest" << num3 << endl;
    cout << "num++Test" << num4 << endl;

    int num11 = 10;
    int num22 = 10;

    int num33 = --num11 * 10;
    int num44 = num22-- * 10;

    cout << "--numTest" << num33 << endl;
    cout << "num--Test" << num44 << endl;

}

//��ֻС����ϰ��
void Practice1()
{
    int weight1 = 0;
    int weight2 = 0;
    int weight3 = 0;
    cin >> weight1;
    cin >> weight2;
    cin >> weight3;
    cout << "��ֻС������Ϊ:" << weight1 << "\t" << weight2 << "\t" << weight3 << endl;
    if (weight1 > weight2)
    {
        if (weight1 > weight3)
        {
            cout << "1������" << endl;
        }
        else cout << "3������\n";
    }
    else
    {
        if (weight2 > weight3)
        {
            cout << "2������\n";
        }
        else cout << "3������\n";
    }
}


void TestPointerAndARR(int* p)
{
    for (int i = 0;i < 5;i++)
    {
        cout << *p << " ";
        p++;
    }
    cout << endl;
    *--p = 10;
}

void ArrBubbleSort(int arr[], int size)
{
    /*cout << sizeof(arr) << endl;//64λ�£�sizeof(һ����ַ)�õ�8(8���ֽ�)
    cout << sizeof(arr[0]) << endl;//sizeof(һ��int���ͱ���)�õ�4(4���ֽ�)
    int size = sizeof(arr) / sizeof(arr[0]);*///������������ĵط�sizeof(������)����ʵֻ�ܵõ�һ��ָ��ռ���ڴ�ռ��С
    //����Ҫ�ں����ڷ�������ĳ��ȣ���Ҫ�ں��������д�������ĳ���
    for (int i = 0;i < (size - 1);i++)
    {
        for (int j = 0;j < (size - 1 - i);j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = 0;
                temp = arr[j];
                *(arr+j) = *(arr+j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

//ָ����ز���
void TestPointer()
{
    //��������ָ�� ��������* ָ���� = ��ַ
    //int a = 10;
    //int b = 20;
    //int* p = &a;
    //int* p2 = &b;
    //int** p3 = &p;
    //int*** p4 = &p3;

    //cout << p << endl;
    //cout << &p << endl;
    //cout << p2 << endl;
    //cout << p3 << endl;

    ////ʹ��ָ�� *ָ���� ���ɷ���ָ��ָ���ڴ��е�����
    //cout << *p << endl;
    //*p3 = &b;
    //cout << *p << endl;
    //*p4 = &p2;
    //cout << **p3 << endl;

    //const����ָ�����
    //const����ָ�� ����ָ�� ָ��ָ���ֵ�������޸� ָ��ָ��ĵ�ַ�����޸�
    //int a1 = 10;
    //int b1 = 20;
    //const int* p11 = &a1;//p11����ָ��
    //p11 = &b1;//�Ϸ�
    ////*p11 = 20;//�Ƿ�
    //
    ////const���γ��� ָ�볣�� ָ��ָ���ֵ�����޸� ָ��ָ��ĵ�ַ�������޸�
    //int* const p12 = &a1;
    ////p12 = &b1;//�Ƿ�
    //*p12 = 20;//�Ϸ�

    ////const����ָ��ͳ���
    //const int* const p13 = &a1;
    ////p13 = &b1;//�Ƿ�
    ////*p13 = 20;//�Ƿ�


    //ָ���������
    /*int arr[5] = { 1,2,3,4,5 };
    int* p21 = arr;
    int* p22 = &arr[0];

    for (int i = 0;i < 5;i++)
    {
        cout << *p21 << " ";
        p21++;
    }
    cout << endl;
    for (int i = 0;i < 5;i++)
    {
        cout << *p22 << " ";
        p22++;
    }
    cout << endl;*/

    //ָ��ͺ���
    /*int arr2[5] = { 1,2,3,4,5 };
    TestPointerAndARR(arr2);
    cout << arr2[4] << endl;*/

    //����
    /*int num1 = 10;
    const int* const p11 = &num1;
    cout << *p11 << endl;
    num1 = 50;
    cout << *p11 << endl;*/

    //ʵ��һ�� ������ʹ��ð������ ʵ����������ĺ���
    int arr11[10] = { 7,6,89,21,54,3,0,78,5,6 };
    for (int i = 0;i < sizeof(arr11) / sizeof(arr11[0]);i++) cout << arr11[i] << " ";
    cout << endl;
    ArrBubbleSort(arr11, sizeof(arr11) / sizeof(arr11[0]));
    for (int i = 0;i < sizeof(arr11) / sizeof(arr11[0]);i++) cout << arr11[i] << " ";
    cout << endl;
}

//��̬�����ڴ����
void TestMalloc() {
    int* p = 0;
    int num = 30;
    p = (int*)malloc(num * sizeof(int));
    p[0] = 10;
    p[1] = 20;
    cout << *p << endl;
    cout << p[1] << endl;
    free(p);


    /*void* p1 = NULL;
    int cnt = 0;
    while ((p1 = malloc(100 * 1024 * 1024)))
    {
        cnt++;
    }
    cout << "���뵽��" << cnt << "00M���ڴ�ռ�" << endl;
    free(p1);*/

}

//�ṹ����ز���
//����ṹ��
struct Student
{
    //��Ա�б�
    string name;
    int age;
    int score;
}s3;//�ڶ���ṹ���ʱ�򴴽��ṹ�����

struct Teacher
{
    string name;
    Student stu[5];
};

void TestSturctFun(Student* stu)
{
    cout << "name" << (*stu).name << "\tage" << (*stu).age << "\tscore" << (*stu).score << endl;
    (*stu).name = "����";
    (*stu).age = 18;
    (*stu).score = 95;

}

void TestCase1(const Teacher* ter,int terLen,int stuLen)
{
    for (int i = 0;i < terLen;i++)
    {
        cout << ter[i].name << endl;
        const Student* stuP = ter[i].stu;
        for (int j = 0;j < stuLen;j++)
        {
            cout << "\t" << (*stuP).name << "\t" << (*stuP).age << "\t" << (*stuP).score << endl;
            stuP++;
        }
    }
}

void TestCase2(Student stuArr[],int len)
{
    for (int i = 0;i < len;i++)
    {
        cout << stuArr[i].name << "  " << stuArr[i].age << "  " << stuArr[i].score << endl;
    }
    cout << endl << endl;
    //��������ð��������������
    for (int i = 0;i < len - 1;i++)
    {
        for (int j = 0;j < len - i - 1;j++)
        {
            Student tempStu;
            if (stuArr[j].age > stuArr[j + 1].age)
            {
                tempStu = stuArr[j];
                stuArr [j] = stuArr[j+1];
                *(stuArr + j + 1) = tempStu;
            }
        }
    }

    for (int i = 0;i < len;i++)
    {
        cout << stuArr[i].name << "  " << stuArr[i].age << "  " << stuArr[i].score << endl;
    }

}

void TestStruct() {
    //�����ṹ�����(����ʵ����)
    //��ʽһ struct Student s1
    /*struct Student s1;
    s1.name = "����";
    s1.age = 18;
    s1.score = 95;
    cout << "name" << s1.name << "\tage" << s1.age << "\tscore" << s1.score << endl;*/
    //��ʽ�� struct Student s2 = { ...}
    /*struct Student s2 = { "����",19,56 };
    cout << "name" << s2.name << "\tage" << s2.age << "\tscore" << s2.score << endl;*/
    //��ʽ�� �ڶ���ṹ���ʱ�򴴽��ṹ�����
    /*s3.name = "����";
    s3.age = 20;
    s3.score = 35;
    cout << "name" << s3.name << "\tage" << s3.age << "\tscore" << s3.score << endl;*/

    //�������ò���
    /*Student s4 = { "����",19,56 };
    cout << "name" << s4.name << "\tage" << s4.age << "\tscore" << s4.score << endl;
    TestSturctFun(&s4);
    cout << "name" << s4.name << "\tage" << s4.age << "\tscore" << s4.score << endl;*/

    //����һ
    /*struct Teacher ter[3] =
    {
        {"��һ",{
            {"����",18,99},
            {"����",18,99},
            {"����",18,99},
            {"����",78,999},
            {"����",18,99}
    }},
        {"�̶�",{
            {"����",19,56},
            {"����",19,56},
            {"����",49,50},
            {"����",19,56},
            {"����",19,56}
    }},
        {"����",{
            {"����",20,35},
            {"����",20,35},
            {"����",20,35},
            {"����",20,35},
            {"����",29,45}
    }}
    };
    TestCase1(ter, 3, 5);*/

    //������
    Student stuArr[5] = {
        {"����",23,1},
        {"����",22,1},
        {"�ŷ�",20,1},
        {"����",21,1},
        {"����",19,0}
    };

    TestCase2(stuArr, 5);

}

void TestStructArr()
{
    struct Student stuArr[3];
    (*stuArr).name = "����";
    stuArr->age = 18;
    stuArr[0].score = 95;

    stuArr[1] = { "����",19,56 };

    Student* p = stuArr;
    (*(p + 2)).name = "����";
    (*(p + 2)).age = 20;
    (*(p + 2)).score = 35;

    for (int i = 0;i < sizeof(stuArr) / sizeof(stuArr[0]);i++)
    {
        //cout << "name" << stuArr[i].name << "\tage" << stuArr[i].age << "\tscore" << stuArr[i].score << endl;
        cout << "name" << (*p).name << "\tage" << (*p).age << "\tscore" << (*p).score << endl;
        p++;
    }

}


void Test()
{
    //ʹ��C�е������������ ��#include <cstdio>
    /*char str[20];
    scanf_s("%s", str , 20);
    printf("%s\n" , str);*/

    /*int score = 0;
    cin >> score;
    cout << "������" << score << "��\n";
    switch (score)
    {
    case 10:
    case 9:
        cout << "����\n";
        break;
    case 8:
    case 7:
        cout << "�ǳ���\n";
        break;
    case 6:
    case 5:
        cout << "һ��\n";
        break;
    default:
        cout << "��Ƭ\n";
    }*/

    /*int i = 0;
    while (i < 11)
    {
        cout << i << endl;
        i++;
    }
    while (1)
    {
        cout << i << endl;
        i++;
        if (i > 100) return;
    }*/

    //��������ӣ���ÿ���������һ��
    /*srand((unsigned int)time(NULL));
    int num = 0;
    num = rand() % 100 + 1;
    int num2 = 0;
    cin >> num2;
    while (num !=num2)
    {
        if (num > num2)
        {
            cout << "С��\n";
        }
        else if(num < num2)
        {
            cout << "����\n";
        }
        cin >> num2;
    }
    cout << "��ϲ�¶���\n";*/

    /*int num3 = 0;
    do {
        cout << num3 << endl;
        num3++;
    } while (num3 < 10);*/

    //ˮ�ɻ���
    /*int num4 = 100;
    while (num4 < 1000)
    {
        int a = num4 / 100;
        int b = (num4 / 10) % 10;
        int c = num4 % 10;
        if (a * a * a + b * b * b + c * c * c == num4)
        {
            cout << num4 << endl;
        }
        num4++;
    }*/

    //�˷���
    /*for (int i = 1;i < 10;i++)
    {
        for (int j = 1;j < 10;j++)
        {
            if (j <= i)
            {
                cout << j << "x" << i << "=" << j * i << "\t";
            }
            else break;
        }
        cout << endl;
    }*/

    //goto����
    /*for (int i = 0;i < 10;i++)
    {
        if (i == 5) goto FLAG;
        cout << i << endl;
    }
    FLAG:
    cout << "goto_end" << endl;*/

    //�������
    //int arr[5];
    /*int arr[5] = {0};
    for (int i = 0;i < 5;i++)
    {
        cout << arr[i] << endl;
    }
    cout << sizeof(arr) << endl;
    cout << &arr[0] << endl;
    cout << arr << endl;*/

    /*int weight[5] = { 300,350,200,400,150 };
    int max = 0;
    for (int i = 0;i < sizeof(weight) / sizeof(weight[0]);i++)
    {
        max < weight[i] ? max = weight[i] : max = max;
    }
    cout << max << endl;*/

    /*int arr3[9] = { 4,3,5,2,2,7,9 };
    const int length = sizeof(arr3) / sizeof(arr3[0]);
    int arr4[length];
    for (int i = 0;i < length;i++)
    {
        arr4[length -i - 1] = arr3[i];
    }
    for (int i = 0;i < length;i++) cout << arr3[i] << " ";
    cout << endl;
    for (int i = 0;i < length;i++) cout << arr4[i] << " ";
    cout << endl;*/

    //ð������
    /*int arr5[] = { 9,5,6,3,78,1,4,2,11,98,0 };
    for (int i = 0;i < 11;i++) cout << arr5[i] << " ";
    cout << endl;
    for (int j = 10;j > 0 ;j--)
    {
        for (int i = 0;i < j;i++)
        {
            int temp = 0;
            if (arr5[i] > arr5[i + 1])
            {
                temp = arr5[i];
                arr5[i] = arr5[i + 1];
                arr5[i + 1] = temp;
            }
        }
    }
    for (int i = 0;i < 11;i++) cout << arr5[i] << " ";
    cout << endl;*/
    
    //�������ļ���д����
    //TestFile();


    //ָ�����
    int i = 0;
    //int* p = &i;��ʾ������һ��ָ�����p ��pָ�����һ��int���͵ı���������i�ĵ�ַ��ֵ��p
    //ʵ���ϣ�û��int*�������͵����ݣ�ʵ������int ��һ�� *p��*p��һ��int ������p��һ��ָ��int��ָ��
    int* p = &i;
    cout << p << endl;//p������ֵ��i�ĵ�ַ
    cout << &i << endl;

}

