#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Stu
{
public:
	Stu(int sco, char *n)
	{
		p = new char[20];
		strcpy(p, n);
		score = sco;
	}
	friend ostream& operator<<(ostream& os, Stu s1);
	friend ostream& operator>>(ostream& is, Stu s1);
	~Stu()
	{
		if (p != NULL)
		{
			cout << "~Stu()...." << endl;
			delete[]p;
			p = NULL;
		}
	}
	void printStu()
	{
		cout << "�ɼ���" << score << endl;
		 cout << "������" << p << endl;
	}
private:
	char *p;
	int score;
	int average;
};
ostream& operator<<(ostream& os, Stu s1)
{
	if (s1.p != NULL)
	{
		os << "������" << s1.p << endl;
		os << "�ɼ���" << s1.score << endl;
		os << "������" << s1.average << endl;
	}
	return os;
}
//ostream& operator>>(ostream& is, Stu s1)
//{
//
//}
int main()
{
	int a = 100;
	char q[20] = "fengchao";
	Stu s1(a,q);
	//s1.printStu();
	cout << s1 << endl;
	
	int b = 100;
	char c[20] = "xiaokk";
	Stu s2(b, c);
	cout << s1 << endl;
}