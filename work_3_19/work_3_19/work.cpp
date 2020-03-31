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

//int main()
//{
//	string s1;
//	string s2;
//
//	while (getline(cin, s1) && getline(cin, s2))
//	{
//		int flag = 0;
//		string::iterator it1 = s1.begin();
//		string::iterator it2 = s2.begin();
//		while (it1 != s1.end() && it2 != s2.end())
//		{
//			if (*it1 == *it2 || *it1 == '?')
//			{
//				it1++;
//				it2++;
//			}
//			else if (*it1 == '*')
//			{
//				while (*it1++ == '*')
//					;
//				if (*it1 == '?')
//				{
//					if (s1.end() - it1 == 1)
//					{
//						flag = 0;
//						break;
//					}
//					else
//					{
//						*it1++;
//						while (it2 != s2.end() && *it1 != *it2)
//						{
//							it2++;
//						}
//						if (it2 != s2.end())
//						{
//							it1++;
//							it2++;
//						}
//					}
//				}
//				while (it2 != s2.end() && *it1 != *it2)
//				{
//					it2++;
//				}
//			}
//			else
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if (flag)
//			cout << "false" << endl;
//		else if (flag == 0)
//			cout << "true" << endl;
//
//	}
//
//	return 0;
//}

int* GetNext1(string& str)
{
	int* next = (int*)malloc(sizeof(int)*str.size());
	int j = 0;
	*next = { 0 };
	for (int i = 2; i < str.size(); i++)
	{
		while (j&&str[j] != str[i - 1])
		{
			j = next[j];
		}
		if (str[j] == str[i - 1])
			j++;
		next[i] = j;
	}
	return next;
}
bool KMP1(string& str1, string& str2)
{
	int* next = GetNext1(str2);
	int j = 0;
	for (int i = 0; i < str1.size(); i++)
	{
		while (j > 0 && str1[i] != str2[j])
		{
			j = next[j];
		}
		if (j>0&&str1[i] == str2[j])
		{
			j++;
		}
		if (j == str2.size())
			return true;
	}
	return false;
}
bool Brute_Force(string Long_String, string Short_String)
{
	string::iterator p1 = Long_String.begin();
	string::iterator p2 = Long_String.begin();
	string::iterator pPre = p1;
	string::iterator pCur = p2;

	while (p1!= Long_String.end())
	{
		while (pCur!= Short_String.end())
		{
			if (*pPre == *pCur)
			{
				pPre++;
				pCur++;
			}
			else
			{
				break;
			}
		}
		if (pCur != Short_String.end())
			break;
		p1++;
		pPre = p1;
		pCur = p2;
	}
	if (pCur!= Short_String.end())
		return true;
	else
		return false;
}
int* getNexts(string pattern)
{
	int* next = new int[pattern.length()];
	int j = 0;
	for (int i = 2; i < pattern.length(); i++) {
		while (j != 0 && pattern[j] != pattern[i - 1]) {
			//从next[i+1]的求解回溯到 next[j]
			j = next[j];
		}
		if (pattern[j] == pattern[i - 1]) {
			j++;
		}
		next[i] = j;
	}
	return next;
}
bool kmp(string str, string pattern) {
	//预处理，生成next数组
	int* next = getNexts(pattern);
	int j = 0;
	//主循环，遍历主串字符
	for (int i = 0; i < str.length(); i++) {
		while (j > 0 && str[i] != pattern[j]) {
			//遇到坏字符时，查询next数组并改变模式串的起点
			j = next[j];
		}
		if (str[i] == pattern[j]) {
			j++;
		}
		if (j == pattern.length()) {
			//匹配成功，返回下标
			return true;
		}
	}
	return false;
}


//int main()
//{
//	string s1;
//	string s2;
//	while (cin >> s2 >> s1)
//	{
//		string ret;
//		int i = 0;
//		string::iterator it2 = s2.begin();
//		string temp;
//		while (it2 != s2.end())
//		{
//			temp.push_back(*it2);
//			if (kmp(s1, temp))
//			{
//				if (temp.size()>ret.size())
//				{
//					ret = temp;
//				}
//			}
//			else
//			{
//				temp.erase(temp.begin());
//			}
//
//			it2++;
//		}
//		cout << ret << endl;
//
//	}
//
//	return 0;
//}

//int main()
//{
//	string s1;
//	string s2;
//	while (cin >> s2 >> s1)
//	{
//		string ret;
//		int i = 0;
//		string::iterator it2 = s2.begin();
//		string::iterator it1 = s1.begin();
//
//		while (it1 != s1.end())
//		{
//			string temp;
//			while (it2 != s2.end() && *it1 != *it2)
//			{
//				++it2;
//			}
//			if (it2 == s2.end())
//			{
//				it1++;
//				it2 = s2.begin();
//				continue;
//			}
//			while (it1 != s1.end() && it2 != s2.end() && *it1 == *it2)
//			{
//				temp.push_back(*it1);
//				it1++;
//				it2++;
//			}
//			if (temp.size()>ret.size())
//			{
//				ret = temp;
//			}
//			if (it1 == s1.end())
//				break;
//			i++;
//			it1 = s1.begin() + i;
//			it2 = s2.begin();
//		}
//		cout << ret << endl;
//
//	}
//
//	return 0;
//}

bool fun(int n)
{
	int sum = 0;
	for (int i = 1; sum < n; i += 2)
		sum += i;
	return n == sum;
}

//int main()
//{
//
//	cout << fun(484) << endl;
//	system("pause");
//	return 0;
//}
string FindSameString(string& s1, string& s2)
{
	vector<vector<int>> arr(s1.size(), vector<int>(s2.size(),0));
	int pos = 0;
	int len = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j])
			{
				if (i == 0 || j == 0)
					arr[i][j] = 1;
				else
					arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = 0;
			}
			if (arr[i][j] > len)
			{
				len = arr[i][j];
				pos = i - len+1;
			}
		}
	}
	return s1.substr(pos, len);
}

//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		if (s1.size() < s2.size())
//		{
//			swap(s1, s2);
//		}
//		cout << FindSameString(s1, s2) << endl;
//	}
//
//
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<vector<int>> v;
//		vector<int> m;
//		for (int i = 0; i<n; i++)
//		{
//			int temp = 0;
//			vector<int> k;
//			cin >> temp;
//			int p = 0;
//			cin >> p;
//			m.push_back(p);
//			for (int j = 0; j<temp * 2; j++)
//			{
//				int tmp;
//				cin >> tmp;
//				k.push_back(tmp);
//			}
//			v.push_back(k);
//		}
//		vector<vector<int>>::iterator it1 = v.begin();
//		vector<int>::iterator it2 = m.begin();
//		while (it1 != v.end() && it2 != m.end())
//		{
//			vector<int> temp;
//			*it2 = *it2%((*it1).size() / 2);
//			for (int i = *it2; i > 0; i--)
//			{
//				for (int j = 0; j < (*it1).size() / 2; j++)
//				{
//					temp.push_back((*it1)[j]);
//					temp.push_back((*it1)[j + (*it1).size() / 2]);
//				}
//				*it1 = temp;
//				temp.clear();
//			}
//			it1++;
//			it2++;
//		}
//		for (int i = 0; i < v.size(); i++)
//		{
//			for (int j = 0; j < v[i].size(); j++)
//			{
//				cout << v[i][j];
//				if (j != v[i].size - 1)
//					cout << " ";
//			}
//			cout << endl;
//		}
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	while (cin >> num)
//	{
//		string s;
//		cin >> s;
//		int start = 0;
//		int end = num<4 ? num - 1 : 3;
//		int begin = 0;
//		string::iterator it = s.begin();
//		while (it != s.end())
//		{
//			if (*it == 'U')
//			{
//				if (start == 0)
//				{
//					end = num - 1;
//					begin = num - 4<0 ? 0 : num - 4;
//				}
//				else if (start == begin)
//				{
//					begin--;
//					end--;
//				}
//				start = (start - 1 + num) % num;
//			}
//			else
//			{
//				if (start == num - 1)
//				{
//					end = num<4 ? num - 1 : 3;
//					begin = 0;
//				}
//				else if (start == end)
//				{
//					begin++;
//					end++;
//				}
//				start = (start + 1 + num) % num;
//			}
//			it++;
//		}
//
//		for (int i = begin + 1; i <= end + 1; i++)
//			cout << i << " ";
//		cout << endl;
//		cout << start+1 << endl;
//	}
//
//
//	return 0;
//}
int getMost(vector<vector<int> > board) {
	// write code here
	for (int i = 1; i<board.size(); i++)
		for (int j = 1; j<board[0].size(); j++)
		{
			board[i][j] += max(board[i][j - 1], board[i - 1][j]);
		}
	return board[board.size() - 1][board[0].size() - 1];
}
int gcd(int a, int b)
{
	int temp;
	while (b)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
//int main()
//{
//	int num = 0;
//	while (cin >> num)
//	{
//		int attack = 0;
//		cin >> attack;
//		vector<int> v;
//		for (int i = 0; i<num; i++)
//		{
//			int temp = 0;
//			cin >> temp;
//			v.push_back(temp);
//		}
//		for (int i = 0; i<num; i++)
//		{
//			if (v[i]>attack)
//			{
//				int temp = gcd(v[i], attack);
//				attack += temp;
//			}
//			else
//			{
//				attack += v[i];
//			}
//		}
//		cout << attack << endl;
//	}
//
//
//
//	return 0;
//}
int min(int a, int b)
{
	return a > b ? b : a;
}
int jumpFloorII(int number) {

	vector<int> v(number + 1, 0);
	v[0] = 1;
	for (int i = 1; i<=number; i++)
	{
		int sum = 0;
		for (int j = i; j >= 0; j--)
			sum += v[j];
		v[i] = sum;
	}
	return v[number];
}
int sum_vector(vector<double>& s1)
{
	vector<double>::reverse_iterator it1 = s1.rbegin();
	while (it1 != s1.rend())
	{
		*it1 = (*it1)*3.14*2;
		it1++;
	}


	return 0;
}
//int main()
//{
//	string s1, s2;
//	while (cin >> s2 >> s1)
//	{
//		vector<double> v;
//		vector<double> v2;
//		for (int i = 0; i<s1.size(); i++)
//		{
//			v.push_back((s1[i] - '0'));
//		}
//		for (int i = 0; i<s2.size(); i++)
//		{
//			v2.push_back((s2[i] - '0'));
//		}
//		sum_vector(v);
//		if (v.size()>v2.size())
//			cout << "YES" << endl;
//		else if (v.size()<v2.size())
//			cout << "NO" << endl;
//		else
//		{
//			int i = 0;
//			for (i = 0; i<s1.size(); i++)
//			{
//				if (v[i]<v2[i])
//				{
//					cout << "NO" << endl;
//					break;
//				}
//			}
//			if (i == s1.size())
//				cout << "YES" << endl;
//		}
//	}
//
//
//	return 0;
//}
//int main()
//{
//	cout << jumpFloorII(2) << endl;
//
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int N, M;
//	while (cin >> N >> M)
//	{
//		vector<vector<int>> arr(N, vector<int>(M, 0));
//		for (int i = 0; i<N; i++)
//			for (int j = 0; j<M; j++)
//				cin >> arr[i][j];
//		vector<vector<int>> v(N, vector<int>(M, 9999));
//		v[0][0] = 0;
//		for (int i = 0; i<N; i++)
//			for (int j = 0; j<M; j++)
//			{
//				if (arr[i][j] == 1 || (i == 0 && j == 0))
//					continue;
//				if (i == 0)
//				{
//					v[i][j] = v[i][j - 1] + 1;
//				}
//				else if (j == 0)
//				{
//					v[i][j] = v[i - 1][j] + 1;
//				}
//				else
//				{
//					v[i][j] = min(v[i][j - 1], v[i - 1][j]) + 1;
//				}
//			}
//		int temp = 0;
//		for (int i = 0; i<N; i++)
//			for (int j = 0; j<M; j++)
//			{
//				if (v[i][j] == temp)
//				{
//					cout << "(" << i << "," << j << ")" << endl;
//					temp++;
//				}
//				
//			}
//	}
//
//
//	return 0;
//}
int ADD(int num1, int num2)
{
	while (num2)
	{
		int temp = 0;
		temp = num1 ^ num2;
		num2 = (num1&num2)>>1;
		num1 = temp;
	}
	return num1;
}

int main()
{
	int num1 = 0;
	int num2 = 0;
	while (cin >> num1 >> num2)
	{
		cout << ADD(num1, num2) << endl;
	}

	return 0;
}