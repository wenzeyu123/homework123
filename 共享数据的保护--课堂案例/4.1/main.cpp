//example 4_5.cpp������Ա�����볣�����ʹ��
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
	} //���캯��
	~Person();
	void Print();        		//���غ�������������ĳ���Ա������const��������

	void Print() const;        		//���غ�������������ĳ���Ա������const��������
	void ModifyAge();
};

//Person::Person(int n, const char *na)     //���캯���Ķ���
//{
//	age = n;
//	name = new char[strlen(na) + 1];
//	strcpy(name, na);
//}
Person::~Person()             		       //���������Ķ���
{
	delete[]name;
}

void Person::Print()   		 //����Ա����Print()�Ķ��壬const����ʡ�� 
{
	cout << "age:" << age << " name: " << name << endl;
	cout << "This is const Print()." << endl;
}

void Person::Print() const       		 //����Ա����Print()�Ķ��壬const����ʡ�� 
{
	cout << "age:" << age << " name: " << name << endl;
	cout << "This is const Print()." << endl;
}
void Person::ModifyAge()     		    //�����޸��������ͨ��Ա����
{
	age++;
}

/*---------------------------------------------------------*
������
*---------------------------------------------------------*/

int main()
{
	Person p1(17, "wu");  		//���峣��������ʼ��
	const Person p2(17, "wu");  		//���峣��������ʼ��

	const double xx = 3;

	cout << "Output const object p1" << endl;
	//   p1.ModifyAge();         		//����������ݳ�Ա���ܱ��޸ģ���������
	p1.Print();

	p2.Print();


	//��������ó���Ա����




	system("pause");
	return 0;
}
