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

//显式实例化类模板
//template class Class1<string, int>;//该文件被.hpp文件include了，没必要显式实例化类模板
//.cpp文件因为是独立的编译单元，在编译运行过程中，是会被生成一个目标文件的，显式实例化后，可以在生成的目标文件中找到类模板的实现，所以.h文件可以不用include包含.cpp文件，使用显式实例化的方式实现类模板的分文件编写
//.tpp文件不是独立的编译单元，在编译运行过程中，是不会生成目标文件的，所以只能通过include的方式包含进.hpp文件中，这样在引用了.hpp文件的地方，才能正常的看到类模板的实现，而不是只有声明，才不会有链接错误


