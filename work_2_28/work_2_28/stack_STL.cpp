#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<functional>
using namespace std;

int main()
{
	stack<int> st;
	queue<int> Q;
	deque<int> dq;
	st.push(2);
	cout << st.empty() << endl;
	cout << st.size() << endl;
	cout << st.top << endl;
	

	system("pause");
	return 0;
}