#include <iostream>
#include<string>

using namespace std;



//1. friend fucntion
class Date;

class Student
{

private:

	int id;
	char name[10];

public:
	Student(int _id, char *pname)
	{
		this->id = _id;
		strcpy(this->name, pname);


	}

	~Student()
	{

	}

	void display(Date &rabbit);


};


class  Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d)
	{
		this->year = y;
		this->month = m;
		this->day = d;
	}

	~Date()
	{

	}

	void display()
	{
		cout << "year: " << year << "month" << month << "day:" << endl;

	}

	friend bool equal(Date &r1, Date &r2);//��Ԫ����
										  //friend void Student::display(Date &rabbit);//��Ա��Ա����
	friend Student;//��Ԫ��

};




void Student::display(Date &rabbit)
{

	cout << "����display����" << endl;
	cout << id << "-" << name << endl;

	cout << rabbit.year << endl;

}
//------------------------------------------




bool equal(Date &r1, Date &r2)
{
	if (r1.year == r2.year&& r1.month == r2.month&&r1.day == r2.day)
	{
		r1.year = 2018;
		return true;
	}

	else
		return false;

}



int main()
{

	Date A(1990, 11, 11);
	Date B(1990, 11, 11);

	cout << boolalpha << equal(A, B) << endl;
	cout << noboolalpha << equal(A, B) << endl;



	system("pause");


}
