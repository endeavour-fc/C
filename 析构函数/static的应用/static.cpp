#include<iostream>
using namespace std;

class AA
{
public:

	AA(int a, int b)
	{
		cout << "AA(int int)...." << endl;
		m_a1 = a;
		m_a2 = b;
	}
	~AA()
	{
		cout << "~AA()....." << endl;
	}
	void printAA()
	{


	}
private:
	int m_a1;
	int m_a2;
};

int main()
{

	return 0;
}