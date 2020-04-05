#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<set>
using namespace std;
class Base
{
public:
	virtual void show()
	{
		cout << "Base:....." << endl;
	}

};
class D :public Base
{
public:
	virtual void show()
	{
		cout << "D:........" << endl;
	}
};
//int main()
//{
//	Base* b = new D;
//	//b->show();
//	Base b1;
//	//b1.show();
//	D b2;
//	//b2.show();
//	system("pause");
//	return 0;
//}

int ADD(int num1, int num2)
{
	while (num2)
	{
		//int a = num1;
		//int b = num2;
		//num1 = a ^ b;
		//num2 = (a&b) << 1;
		int temp = num1 ^ num2;
		num2 = (num1&num2) << 1;
		num1 = temp;
	}
	return num1;
}
void oddInOddEvenInEven(vector<int>& arr, int len) {
	int i = 0;
	int j = 1;
	while (i<len&&j<len)
	{
		if (arr[i] % 2 == 1 && arr[j] % 2 == 0)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			//swap(arr[i],arr[j]);
			i += 2;
			j += 2;
			continue;
		}
		if (arr[i] % 2 == 0)
			i += 2;
		if (arr[j] % 2 == 1)
			j += 2;
	}
}
    string longestPalindrome(string s) {
        if(s==" ")
        return s;
        string temp(s.rbegin(),s.rend());
        vector<vector<int>> v(s.size(),vector<int>(s.size(),0));
        int MaxLen=0;
        int pos=0;
        for(int i=0;i<s.size();++i)
        {
            for(int j=0;j<s.size();++j)
            {
                if(s[i]==temp[j])
                {
                    if(i==0||j==0)
                    v[i][j]=1;
                    else
                    v[i][j]=v[i-1][j-1]+1;
                }
                if(v[i][j]>MaxLen)
                {
                    int thispos=s.size()-1-j;
                    if(thispos+v[i][j]-1==i)
                    {
                        pos=i-v[i][j]+1;
                        MaxLen=v[i][j];
                    }
                }
            }
        }
        return s.substr(pos,MaxLen);

    }
int getFirstUnFormedNum(vector<int> arr, int len) {
	int min = arr[0];
	int sum = 0;
	for (int i = 0; i<len; i++)
	{
		if (min>arr[i])
			min = arr[i];
		sum += arr[i];
	}
	int i = 0;
	arr.insert(arr.begin(), 0);
	int temp = 0;
	for (i = min + 1; i<sum; i++)
	{
		int j = 0;
		for (j = 0; j<len; j++)
		{
			int k = 0;
			for (k = j + 1; k <= len; k++)
			{
				if (i == arr[j] + arr[k])
				{
					break;
				}
			}
			if (k == len + 1)
				continue;
			if (i == arr[j] + arr[k])
				break;
		}
		if (j == len)
			return i;
	}
		return sum + 1;
}
//int main()
//{
//	int num = 0;
//	while (cin >> num)
//	{
//		vector<int> v;
//		for (int i = 2; i <= (int)sqrt(num); i++)
//		{
//			if (num == 1)
//				break;
//			if (num%i == 0)
//			{
//				while (num%i == 0)
//				{
//					v.push_back(i);
//					num /= i;
//				}
//			}
//			if (num == 1)
//				break;
//		}
//		if (num > 1)
//			v.push_back(num);
//		cout << v[v.size() - 1] << endl;
//
//	}
//
//	return 0;
//}
//int main()
//{
//	http://www.taobao.com
//	vector<int> v = { 3,1,2 ,5,6};
//	cout << getFirstUnFormedNum(v, v.size()) << endl;
//	//string s("cbbd");
//	//cout << longestPalindrome(s) << endl;
//	//vector<int> v{ 1,2,3,4 };
//	//oddInOddEvenInEven(v, v.size());
//	//int num1 = 0;
//	//int num2 = 0;
//	//while (cin >> num1 >> num2)
//	//{
//	//	cout << ADD(num1, num2) << endl;
//	//}
//	system("pause");
//	return 0;
//}

int max(int a, int b)
{
	return a>b ? a : b;
}
int largestRectangleArea(vector<int>& heights) {
	stack<int> stack;
	stack.push(-1);
	int area = 0;
	for (int i = 0; i<heights.size(); i++)
	{
		while (stack.top() != -1 && heights[i]<=heights[stack.top()])
		{
			int temp = stack.top();
			stack.pop();
			area = max(area, heights[temp] * (i - stack.top() - 1));
		}
		stack.push(i);
	}
	if (stack.top() != -1)
	{
		while (stack.top() != -1)
		{
			int temp = stack.top();
			stack.pop();
			area = max(area, heights[temp] * (heights.size()+1 - stack.top() - 1));
		}
		return area;
	}
	return area;
}
int numDecodings(string s) {
	if (s == "0")
		return 0;
	vector<int> v(s.size() + 1, 1);
	for (int i = 1; i<s.size(); i++)
	{
		if (s[i] == '0')
		{
			if (s[i - 1] == '1' || s[i - 1] == '2')
			{
				v[i + 1] = v[i - 1];
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if (s[i - 1] == '1' || (s[i - 1] == '2'&&s[i] <= '6'))
				v[i + 1] = v[i - 1] + v[i];
			else
			{
				if (i == 1 && s[i - 1] == '0')
					v[i+1] = 0;
				else
					v[i + 1] = v[i];
			}
		}
	}
	return v[v.size() - 1];
}
int min(int a, int b)
{
	return a > b ? b : a;
}
int minimumTotal(vector<vector<int>>& triangle) {
	for (int i = 1; i<triangle.size(); i++)
	{
		triangle[i][0] += triangle[i - 1][0];
		triangle[i][triangle[i].size() - 1] += triangle[i - 1][triangle[i - 1].size() - 1];
	}
	for (int i = 2; i<triangle.size(); i++)
	{
		for (int j = 1; j<triangle[i].size() - 1; j++)
		{
			triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
		}
	}
	int min = 999999999;
	for (int i = 0; i<triangle[triangle.size() - 1].size(); i++)
	{
		if (min>triangle[triangle.size() - 1][i])
		{
			min = triangle[triangle.size() - 1][i];
		}
	}
	return min;
}
bool wordBreak(string s, vector<string>& wordDict) {
	set<string> words;
	for (int i = 0; i<wordDict.size(); i++) {
		words.insert(wordDict[i]);
	}
	vector<bool> dp(s.length() + 1);
	dp[0] = true;
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 0; j < i; j++) {
			if (dp[j] && words.find(s.substr(j, i)) != words.end()) {
				dp[i] = true;
				break;
			}
		}
	}
	return dp[s.length()];
}
int main()
{
	string s = "catsandog";
	vector<string> wordDict = { "cats", "dog", "sand", "and", "cat" };
	//vector< vector< vector< int > > > vecInt(10, vector< vector< int > >(10, vector< int >(10, 10)));
	//vector<vector<int>> v = { {2},{3, 4},{6, 5, 7},{4, 1, 8, 3} };
	//string s = "01";
	cout << wordBreak(s,wordDict) << endl;

	system("pause");

	return 0;
}