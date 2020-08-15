#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*int add(int num = 10)//err
{
	return num;
}
int add(int num)
{
	return num;
}*/
class UnionFindSet
{
public:

	UnionFindSet(size_t size)
		: _ufs(size, -1)
	{}
	int FindRoot(int index)
	{
		while (_ufs[index] >= 0)
		{
			index = _ufs[index];
		}

		return index;
	}
	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 == root2)
			return false;
		_ufs[root1] += _ufs[root2];

		_ufs[root2] = root1;
		return true;
	}

	size_t Count()const
	{
		size_t count = 0;
		for (auto e : _ufs)
		{
			if (e < 0)
				++count;
		}

		return count;
	}
	vector<vector<int>> get()
	{
		vector<vector<int>> v(Count(), vector<int>());
		for (int i = 0; i<_ufs.size(); ++i)
		{
			int index = i;
			while (_ufs[index] >= 0)
			{
				index = _ufs[index];
			}
			v[index].push_back(_ufs[i]);
		}
		return v;
	}

private:
	vector<int> _ufs;
};

string fun(string s)
{
	int begin = 0;
	int end = s.size() - 1;
	while (begin<end)
	{
		swap(s[begin++], s[end--]);
	}
	return s;
}
class Solution_arrangeCoins {
public:
	int arrangeCoins1(int n) {
		if (n == 0)
			return 0;
		int ret = 0;
		long long sum = 0;
		int i = 1;
		while (sum <= n)
		{
			++ret;
			sum += i++;
		}
		return ret - 1;
	}
	int arrangeCoins2(int n) {
		int left = 0;
		int right = n;

		while (left <= right)
		{
			long mid = (right - left) / 2 + left;
			if (mid*(mid + 1) / 2 == n)
				return mid;
			else if (mid*(mid + 1) / 2>n)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return right;
	}
};
int fun2()
{
	int n = 0;
	cin >> n;
	int count = 0;
	vector<pair<int,int>> v;
	for (int i = n; i >= 2000; --i)
	{
		if (i % 4 == 0)
		{
			if (fun( to_string(i / 4) ) == to_string(i))
			{
				++count;
				v.push_back({i/4,i});
			}
		}
	}
	cout << count << endl;
	for (int i = 0; i < v.size(); ++i)
		cout << v[i].first<<" "<<v[i].second << endl;
	system("pause");
	return 0;
}


struct ListNode {
    int val;
	ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


ListNode* deleteDuplicates(ListNode* head) {
	ListNode* phead = new ListNode(-1);
	phead->next = head;
	ListNode* temp = phead;
	while (phead&&phead->next)
	{
		ListNode* pPre = phead->next;
		if (!pPre->next || pPre->val != pPre->next->val)
			phead = pPre;
		else
		{
			while (pPre->next&&pPre->val == pPre->next->val)
				pPre = pPre->next;
			phead->next = pPre->next;
		}
	}

	return temp->next;
}


