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
		cout << "成绩是" << score << endl;
		cout << "名字是" << p << endl;
	}
private:
	char *p;
	int score;
	int average;
};

int main()
{
	int a = 100;
	char q[20] = "fengchao";
	Stu s1(a,q);
	s1.printStu();
	
	int b = 100;
	char c[20] = "xiaokk";
	Stu s2(b, c);
	s2.printStu();
}