#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<functional>
using namespace std;

int lengthOfLongestSubstring(string s) {
	string::iterator it1 = s.begin();

	int len = 0;
	int flag = 0;

	string temp;
	while (it1 != s.end())
	{
		if (temp.empty())
		{
			temp += *it1;
			if (temp.size()>len)
			{
				len = temp.size();
			}
		}
		else
		{
			for (string::iterator it = temp.begin(); it != temp.end(); it++)
			{
				if (*it == *it1)
				{
					if (temp.size()>len)
					{
						len = temp.size();
					}
					temp.erase(temp.begin(), it + 1);
					break;
				}

			}
			temp += *it1;
		}
		it1++;
	}
	if (temp.size() > len)
		len = temp.size();
	return len;

}
//int main()
//{
//	cout << lengthOfLongestSubstring("au") << endl;
//	
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		if (n == 0 || n == 1 || n == 2)
//		{
//			cout << -1 << endl;
//		}
//		vector<int> k(n * 2 + 1, 0);
//		k[n - 1] = k[n] = k[n + 1] = 1;
//		int len = 3;
//		while (len <= n)
//		{
//			vector<int> temp(n * 2 + 1, 0);
//			for (int i = n - len + 1; i<n + len; i++)
//			{
//				temp[i] = k[i - 1] + k[i] + k[i + 1];
//			}
//			k = temp;
//			len++;
//
//		}
//	}
//
//	return 0;
//}
int sum_string()
{
	string s1, s2;
	while (getline(cin, s1) && getline(cin, s2))
	{
		//for (string::iterator it = s1.begin(); it != s1.end(); it++)
		//{
		//	*it += '0';
		//}
		//for (string::iterator it = s2.begin(); it != s2.end(); it++)
		//{
		//	*it += '0';
		//}
		string::reverse_iterator it1 = s1.rbegin();
		string::reverse_iterator it2 = s2.rbegin();
		int cn = 0;
		while (it1 != s1.rend() && it2 != s2.rend())
		{
			char temp = *it1 + *it2 + cn - '0';
			cn = 0;
			if (temp>'9')
				cn = 1;
			int num = temp - '0';
			*it1 = num % 10 + '0';
			*it2 = num % 10 + '0';
			it1++;
			it2++;
		}
		while (it1 != s1.rend())
		{
			char temp = *it1 + cn;
			cn = 0;
			if (temp>'9')
				cn = 1;
			int num = temp - '0';
			*it1 = num % 10 + '0';
			it1++;
		}
		while (it2 != s2.rend())
		{
			char temp = *it2 + cn;
			cn = 0;
			if (temp>'9')
				cn = 1;
			int num = temp - '0';
			*it2 = num % 10 + '0';
			it2++;
		}
		if (cn)
		{
			if (s1.size()>s2.size())
			{
				s1.insert(s1.begin(), '1');
			}
			else
			{
				s2.insert(s2.begin(), '1');
			}
		}
		if (s1.size()>s2.size())
		{
			cout << s1 << endl;
		}
		else
		{
			cout << s2 << endl;
		}

	}

	return 0;
}
int removeDuplicates(vector<int>& nums) {
	vector<int> temp;
	vector<int>::iterator it = nums.begin();
	int i = 0;
	while (it != nums.end())
	{
		if (temp.size() == 0)
		{
			temp.push_back(*it);
			it++;
		}
		else if (temp.size() == 1)
		{
			if (temp[0] == *it)
			{
				temp.push_back(*it);
			}
			else
			{
				temp.clear();
			}
			it++;
		}
		else
		{
			if (temp[0] == *it)
			{
				
				it=nums.erase(it);
				//it = a;
			}
			else
			{
				temp.clear();
				temp.push_back(*it);
				it++;
			}
		}
	}
	return nums.size();
}
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.size() == 0)
		return NULL;
	int mid = nums.size() / 2;
	vector<int> temp1(nums.begin(), nums.begin() + mid);
	vector<int> temp2(nums.begin() + mid, nums.end());
	TreeNode* root = new TreeNode(nums[mid]);
	if (temp1.size()>0)
		root->left = sortedArrayToBST(temp1);
	if (temp2.size()>0)
		root->right = sortedArrayToBST(temp2);

	return root;
}
//int main()
//{
//	vector<int> nums = { 0,0,1,1,1,1,2,3,3 };
//	cout << removeDuplicates(nums) << endl;
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int old = 1;
//		int young1 = 0;
//		int young2 = 0;
//		//int young3 = 0;
//		int sum = 0;
//		int day = 0;
//		while (day<n)
//		{
//			int newre = old;
//			old += young2;
//			//young3 = young2;
//			young2 = young1;
//			young1 = newre;
//			sum = old + young1 + young2 ;
//			day++;
//
//		}
//		cout << sum << endl;
//
//	}
//
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int n1 = 0;
//		int n2 = 1;
//		int n3 = 1;
//		if (n == 1 || n == 2)
//		{
//			cout << 1 << endl;
//			continue;
//		}
//		if (n == 3)
//		{
//			cout << 2 << endl;
//			continue;
//		}
//		for (int i = 2; i<n; i++)
//		{
//			n1 = n2;
//			n2 = n3;
//			n3 = n1 + n2;
//		}
//		cout << n3 << endl;
//	}
//
//	return 0;
//}
int trailingZeroes(int n) {
	if (n<5)
		return 0;
	int count = 0;
	while (n>0)
	{
		count += n / 5;
		n /= 5;
	}
	return count;

}
int max(int a, int b)
{
	return a > b ? a : b;
}
int maxProfit(vector<int>& prices)
{
	if (prices.size() == 0)
		return 0;
	int m1 = 0;
	int m2 = INT_MIN;
	for (int i = 0; i<prices.size(); i++)
	{
		m1 = max(m1, m2 + prices[i]);
		m2 = max(m2, -prices[i]);
	}
	return m1;
}

int main()
{
	string s1;
	string s2;

	while (getline(cin, s1) && getline(cin, s2))
	{
		int flag = 0;
		string::iterator it1 = s1.begin();
		string::iterator it2 = s2.begin();
		while (it1 != s1.end() && it2 != s2.end())
		{
			if (*it1 == *it2 || *it1 == '?')
			{
				it1++;
				it2++;
			}
			else if (*it1 == '*')
			{
				while (*it1++ == '*')
					;
				if (*it1 == '?')
				{
					if (s1.end() - it1 == 1)
					{
						flag = 0;
						break;
					}
					else
					{
						*it1++;
						while (it2 != s2.end() && *it1 != *it2)
						{
							it2++;
						}
						if (it2 != s2.end())
						{
							it1++;
							it2++;
						}
					}
				}
				while (it2 != s2.end() && *it1 != *it2)
				{
					it2++;
				}
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			cout << "false" << endl;
		else if (flag == 0)
			cout << "true" << endl;

	}

	return 0;
}