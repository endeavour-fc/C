#include<iostream>
#include<vector>
using namespace std;
void adjustment(vector<int>& v,int pos, int count)
{
	while (count--)
	{
		pos = (pos + v.size()) % v.size();
		++v[pos++];
	}
}
int main()
{
	int n, k = 0;
	while (cin >> n >> k)
	{
		vector<int> v(n, k);
		int i = 1;
		int count = v[i];
		while (v[i] != 0)
		{
			int count = v[i];
			v[i] = 0;
			adjustment(v, (i + 1)%v.size(), count);
			i = (i + count+1) % v.size();
		}
		for (auto& e : v)
			cout << e << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}