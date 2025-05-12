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

#define Day 7//#define宏定义的常量

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

    const int month = 12;//const修饰的方式定义常量
}

//数据类型相关
int DataType()
{
	//整型
	//短整型short
	short num1 = 10;
	//整型int
	int num2 = 20;
	//长整型long
	long num3 = 30;
	//长长整型long long(long可以是数据类型，也可以是修饰符,此处第一个long是修饰符，第二个是数据类型)
	long long num4 = 40;
	//此处long为修饰符，表示长整型
	long int num5 = 50;
	//修饰符还有signed表示有正负符号类型
	//unsigned表示无符号类型，只有正数
	//short表示短整型
	//long表示长整型
	//const表示常量，值不能修改
	//volatile表示变量可能被意外修改，禁止编译器优化
	//mutable表示类成员可以在 const 对象中修改

    //浮点型
    //float单精度4字节
    float f1 = 3.14f;
    //double双精度8字节
    double d1 = 3.14;

    //字符型
    //char占用1字节，在内存中存的是字符对应的ASCII码
    char ch = 'a';//只能放一个字符，且只能用单引号

    //字符串
    //C语言的字符串
    char str1[] = "hello world";
    //C++的字符串
    string str2 = "hello world";

    //布尔值bool
    bool flag1 = true;
    bool flag2 = false;
    
    //输出测试
    cout << "type: \t\t" << "************size**************" << endl;
    cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
    cout << "\t最大值：" << (numeric_limits<bool>::max)();
    cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;
    cout << "char: \t\t" << "所占字节数：" << sizeof(char);
    cout << "\t最大值：" << (numeric_limits<char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;
    cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);
    cout << "\t最大值：" << (numeric_limits<signed char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;
    cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);
    cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;
    cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);
    cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
    cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;
    cout << "short: \t\t" << "所占字节数：" << sizeof(short);
    cout << "\t最大值：" << (numeric_limits<short>::max)();
    cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;
    cout << "int: \t\t" << "所占字节数：" << sizeof(int);
    cout << "\t最大值：" << (numeric_limits<int>::max)();
    cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;
    cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);
    cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
    cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;
    cout << "long: \t\t" << "所占字节数：" << sizeof(long);
    cout << "\t最大值：" << (numeric_limits<long>::max)();
    cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;
    cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);
    cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
    cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;
    cout << "double: \t" << "所占字节数：" << sizeof(double);
    cout << "\t最大值：" << (numeric_limits<double>::max)();
    cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;
    cout << "long double: \t" << "所占字节数：" << sizeof(long double);
    cout << "\t最大值：" << (numeric_limits<long double>::max)();
    cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;
    cout << "float: \t\t" << "所占字节数：" << sizeof(float);
    cout << "\t最大值：" << (numeric_limits<float>::max)();
    cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;
    cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);
    cout << "\t最大值：" << (numeric_limits<size_t>::max)();
    cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;
    cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;
    // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;  
    cout << "type: \t\t" << "************size**************" << endl;
    return 0;

}

//转义字符
void EscapeCharacter()
{
    //换行 \n
    cout << "\n换行测试\n";

    //反斜杠 \\

    cout<<"\\反斜杠测试\n";

    //制表符 \t
    cout << "\t制表符测试\t111\n";

    //字符串结束标志 \0
    cout << "字符串结束\0测试\n";

}

//Cin,数据输入测试
void TestCin()
{
    int num = 0;
    float f = 3.14f;
    char ch = 'a';
    string str = "123";
    bool flag = true;

    cout << "数据输入测试 int" << endl;
    cin >> num;
    cout << "数据输入测试 int当前值为"<<num << endl;

    cout << "数据输入测试 float" << endl;
    cin >> f;
    cout << "数据输入测试 float当前值为" << f << endl;

    cout << "数据输入测试 char" << endl;
    cin >> ch;
    cout << "数据输入测试 char当前值为" << ch << endl;

    cout << "数据输入测试 string" << endl;
    cin >> str;
    cout << "数据输入测试 string当前值为" << str << endl;

    cout << "数据输入测试 bool" << endl;
    cin >> flag;
    cout << "数据输入测试 bool当前值为" << flag << endl;

}

//++ --测试
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

//三只小猪练习题
void Practice1()
{
    int weight1 = 0;
    int weight2 = 0;
    int weight3 = 0;
    cin >> weight1;
    cin >> weight2;
    cin >> weight3;
    cout << "三只小猪体重为:" << weight1 << "\t" << weight2 << "\t" << weight3 << endl;
    if (weight1 > weight2)
    {
        if (weight1 > weight3)
        {
            cout << "1猪最重" << endl;
        }
        else cout << "3猪最重\n";
    }
    else
    {
        if (weight2 > weight3)
        {
            cout << "2猪最重\n";
        }
        else cout << "3猪最重\n";
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
    /*cout << sizeof(arr) << endl;//64位下，sizeof(一个地址)得到8(8个字节)
    cout << sizeof(arr[0]) << endl;//sizeof(一个int类型变量)得到4(4个字节)
    int size = sizeof(arr) / sizeof(arr[0]);*///在数组声明外的地方sizeof(数组名)，其实只能得到一个指针占的内存空间大小
    //所以要在函数内访问数组的长度，需要在函数参数中传入数组的长度
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

//指针相关测试
void TestPointer()
{
    //声明定义指针 数据类型* 指针名 = 地址
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

    ////使用指针 *指针名 即可访问指针指向内存中的数据
    //cout << *p << endl;
    //*p3 = &b;
    //cout << *p << endl;
    //*p4 = &p2;
    //cout << **p3 << endl;

    //const修饰指针相关
    //const修饰指针 常量指针 指针指向的值不可以修改 指针指向的地址可以修改
    //int a1 = 10;
    //int b1 = 20;
    //const int* p11 = &a1;//p11常量指针
    //p11 = &b1;//合法
    ////*p11 = 20;//非法
    //
    ////const修饰常量 指针常量 指针指向的值可以修改 指针指向的地址不可以修改
    //int* const p12 = &a1;
    ////p12 = &b1;//非法
    //*p12 = 20;//合法

    ////const修饰指针和常量
    //const int* const p13 = &a1;
    ////p13 = &b1;//非法
    ////*p13 = 20;//非法


    //指针访问数组
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

    //指针和函数
    /*int arr2[5] = { 1,2,3,4,5 };
    TestPointerAndARR(arr2);
    cout << arr2[4] << endl;*/

    //测试
    /*int num1 = 10;
    const int* const p11 = &num1;
    cout << *p11 << endl;
    num1 = 50;
    cout << *p11 << endl;*/

    //实现一个 对数组使用冒泡排序 实现升序排序的函数
    int arr11[10] = { 7,6,89,21,54,3,0,78,5,6 };
    for (int i = 0;i < sizeof(arr11) / sizeof(arr11[0]);i++) cout << arr11[i] << " ";
    cout << endl;
    ArrBubbleSort(arr11, sizeof(arr11) / sizeof(arr11[0]));
    for (int i = 0;i < sizeof(arr11) / sizeof(arr11[0]);i++) cout << arr11[i] << " ";
    cout << endl;
}

//动态分配内存测试
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
    cout << "申请到了" << cnt << "00M的内存空间" << endl;
    free(p1);*/

}

//结构体相关测试
//定义结构体
struct Student
{
    //成员列表
    string name;
    int age;
    int score;
}s3;//在定义结构体的时候创建结构体变量

struct Teacher
{
    string name;
    Student stu[5];
};

void TestSturctFun(Student* stu)
{
    cout << "name" << (*stu).name << "\tage" << (*stu).age << "\tscore" << (*stu).score << endl;
    (*stu).name = "张三";
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
    //根据年龄冒泡排序，升序排序
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
    //创建结构体变量(创建实例？)
    //方式一 struct Student s1
    /*struct Student s1;
    s1.name = "张三";
    s1.age = 18;
    s1.score = 95;
    cout << "name" << s1.name << "\tage" << s1.age << "\tscore" << s1.score << endl;*/
    //方式二 struct Student s2 = { ...}
    /*struct Student s2 = { "李四",19,56 };
    cout << "name" << s2.name << "\tage" << s2.age << "\tscore" << s2.score << endl;*/
    //方式三 在定义结构体的时候创建结构体变量
    /*s3.name = "王五";
    s3.age = 20;
    s3.score = 35;
    cout << "name" << s3.name << "\tage" << s3.age << "\tscore" << s3.score << endl;*/

    //函数调用测试
    /*Student s4 = { "李四",19,56 };
    cout << "name" << s4.name << "\tage" << s4.age << "\tscore" << s4.score << endl;
    TestSturctFun(&s4);
    cout << "name" << s4.name << "\tage" << s4.age << "\tscore" << s4.score << endl;*/

    //案例一
    /*struct Teacher ter[3] =
    {
        {"教一",{
            {"张三",18,99},
            {"张三",18,99},
            {"张三",18,99},
            {"张三",78,999},
            {"张三",18,99}
    }},
        {"教二",{
            {"李四",19,56},
            {"李四",19,56},
            {"李四",49,50},
            {"李四",19,56},
            {"李四",19,56}
    }},
        {"教三",{
            {"王五",20,35},
            {"王五",20,35},
            {"王五",20,35},
            {"王五",20,35},
            {"王五",29,45}
    }}
    };
    TestCase1(ter, 3, 5);*/

    //案例二
    Student stuArr[5] = {
        {"刘备",23,1},
        {"关羽",22,1},
        {"张飞",20,1},
        {"赵云",21,1},
        {"貂蝉",19,0}
    };

    TestCase2(stuArr, 5);

}

void TestStructArr()
{
    struct Student stuArr[3];
    (*stuArr).name = "张三";
    stuArr->age = 18;
    stuArr[0].score = 95;

    stuArr[1] = { "李四",19,56 };

    Student* p = stuArr;
    (*(p + 2)).name = "王五";
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
    //使用C中的输入输出函数 需#include <cstdio>
    /*char str[20];
    scanf_s("%s", str , 20);
    printf("%s\n" , str);*/

    /*int score = 0;
    cin >> score;
    cout << "输入了" << score << "分\n";
    switch (score)
    {
    case 10:
    case 9:
        cout << "经典\n";
        break;
    case 8:
    case 7:
        cout << "非常好\n";
        break;
    case 6:
    case 5:
        cout << "一般\n";
        break;
    default:
        cout << "烂片\n";
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

    //随机数种子，让每次随机数不一样
    /*srand((unsigned int)time(NULL));
    int num = 0;
    num = rand() % 100 + 1;
    int num2 = 0;
    cin >> num2;
    while (num !=num2)
    {
        if (num > num2)
        {
            cout << "小了\n";
        }
        else if(num < num2)
        {
            cout << "大了\n";
        }
        cin >> num2;
    }
    cout << "恭喜猜对了\n";*/

    /*int num3 = 0;
    do {
        cout << num3 << endl;
        num3++;
    } while (num3 < 10);*/

    //水仙花数
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

    //乘法表
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

    //goto测试
    /*for (int i = 0;i < 10;i++)
    {
        if (i == 5) goto FLAG;
        cout << i << endl;
    }
    FLAG:
    cout << "goto_end" << endl;*/

    //数组测试
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

    //冒泡排序
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
    
    //函数分文件编写测试
    //TestFile();


    //指针测试
    int i = 0;
    //int* p = &i;表示声明了一个指针变量p ，p指向的是一个int类型的变量，并将i的地址赋值给p
    //实际上，没有int*这种类型的数据，实际上是int 了一个 *p，*p是一个int ，所以p是一个指向int的指针
    int* p = &i;
    cout << p << endl;//p变量的值是i的地址
    cout << &i << endl;

}

