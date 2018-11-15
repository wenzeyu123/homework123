//example 4_5.cpp：常成员函数与常对象的使用
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
	int age;
	char *name;

public:
	Person(int _age, char *pname)
	{
		this->age = _age;
		strcpy(this->name, pname);
	} //构造函数
	~Person();
	void Print();        		//重载函数，用于输出的常成员函数，const参与重载

	void Print() const;        		//重载函数，用于输出的常成员函数，const参与重载
	void ModifyAge();
};

//Person::Person(int n, const char *na)     //构造函数的定义
//{
//	age = n;
//	name = new char[strlen(na) + 1];
//	strcpy(name, na);
//}
Person::~Person()             		       //析构函数的定义
{
	delete[]name;
}

void Person::Print()   		 //常成员函数Print()的定义，const不可省略 
{
	cout << "age:" << age << " name: " << name << endl;
	cout << "This is const Print()." << endl;
}

void Person::Print() const       		 //常成员函数Print()的定义，const不可省略 
{
	cout << "age:" << age << " name: " << name << endl;
	cout << "This is const Print()." << endl;
}
void Person::ModifyAge()     		    //用于修改年龄的普通成员函数
{
	age++;
}

/*---------------------------------------------------------*
主函数
*---------------------------------------------------------*/

int main()
{
	Person p1(17, "wu");  		//定义常对象必须初始化
	const Person p2(17, "wu");  		//定义常对象必须初始化

	const double xx = 3;

	cout << "Output const object p1" << endl;
	//   p1.ModifyAge();         		//常对象的数据成员不能被修改，该语句出错
	p1.Print();

	p2.Print();


	//常对象调用常成员函数




	system("pause");
	return 0;
}
