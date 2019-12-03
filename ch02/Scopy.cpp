/*
* 避免使用void*指针
* 避免使用register关键字
*/
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <cfloat>
using namespace std;


//getline();用法
//将一个文件的内容按行复制到另一个文件
void copyFromFile()
{
	ifstream in("copy.txt");
	ofstream out("copy2.txt");
	string s;
	while (getline(in, s))//getline 会去掉换行符
	{
		out << s << "\n";//所以要加上换行符
	}
}
//将文件内容复制到string对象中
void copyToString()
{
	ifstream in("copy.txt");
	string line;
	string result;
	while (getline(in, line))//getline 会去掉换行符
	{
		result += line + "\n";//不用担心string的内存分配 但是文件最好抽象成多行的集合而不是一大段文本 
	}
	cout << result;
}

/**********************************************/

// 查看内置类型的大小
void showTypeSize() {
	cout << "char:" << sizeof(char) << endl;//1
	cout << "int:" << sizeof(int) << endl;//4
	cout << "float:" << sizeof(float) << endl;//4
	cout << "double:" << sizeof(double) << endl;//8

	cout << "short int:" << sizeof(short int) << endl;//2
	cout << "long int:" << sizeof(long int) << endl;//4
	cout << "long double:" << sizeof(long double) << endl;//8
}
/**********************************************/

void func() {
	static int i = 0;//static是说func函数会记住变量i的值
	cout << "i:" << ++i << endl;
}


int main()
{
	for (int i = 0; i < 3; i++) {//1 2 3
		func();
	}

	cin.get();//等待读取一个换行符,不然黑窗口一闪而过 c++做法 而不是getchar()(c的做法)
	//system("pause");//或者可以这样进行等待
	return 0;
}
