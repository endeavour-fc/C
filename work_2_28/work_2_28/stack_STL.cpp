#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<functional>
using namespace std;
int findKthLargest(vector<int>& nums, int k) {
	make_heap(nums.begin(), nums.end());
	vector<int>::iterator it = nums.end();
	for (int i = 0; i<k - 1; i++)
		pop_heap(nums.begin(), it--);
	return nums[0];
}
void Creat_Heap(vector<int>& arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		int CurrentIndex = i;
		int FatherIndex = (CurrentIndex - 1) / 2;
		while (arr[CurrentIndex] > arr[FatherIndex])
		{
			std::swap(arr[CurrentIndex], arr[FatherIndex]);
			CurrentIndex = FatherIndex;
			FatherIndex = (CurrentIndex - 1) / 2;
		}
	}
}
int main()
{
	//stack<int> st;
	//queue<int> Q;
	//deque<int> dq;
	//st.push(2);
	//cout << st.empty() << endl;
	//cout << st.size() << endl;
	//cout << st.top << endl;
	vector<int> v = { 1,3,4,5,6,7,8,9 };
	for (const auto &e : v)
		cout << e<<" ";
	cout << endl;
	//make_heap(v.begin(), v.end());
	Creat_Heap(v, v.size());
	for (const auto &e : v)
		cout << e << " ";
	cout << endl;
	/*v.push_back(6);
	push_heap(v.begin(), v.end());
	for (const auto &e : v)
		cout << e << " ";
	cout << endl;
	vector<int>::iterator it = v.end();
	for (const auto &e : v)
		pop_heap(v.begin(),it--);
	for (const auto &e : v)
		cout << e << " ";
	cout << endl;*/
	//priority_queue<int> pq;
	//for (const auto &e : v)
	//	pq.push(e);
	//cout << pq.top() << endl;
	

	system("pause");
	return 0;
}