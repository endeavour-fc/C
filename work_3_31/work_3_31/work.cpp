#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<set>
#include<cmath>
#include<functional>
#include <algorithm>
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
//int min(int a, int b)
//{
//	return a > b ? b : a;
//}
//int minimumTotal(vector<vector<int>>& triangle) {
//	for (int i = 1; i<triangle.size(); i++)
//	{
//		triangle[i][0] += triangle[i - 1][0];
//		triangle[i][triangle[i].size() - 1] += triangle[i - 1][triangle[i - 1].size() - 1];
//	}
//	for (int i = 2; i<triangle.size(); i++)
//	{
//		for (int j = 1; j<triangle[i].size() - 1; j++)
//		{
//			triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
//		}
//	}
//	int min = 999999999;
//	for (int i = 0; i<triangle[triangle.size() - 1].size(); i++)
//	{
//		if (min>triangle[triangle.size() - 1][i])
//		{
//			min = triangle[triangle.size() - 1][i];
//		}
//	}
//	return min;
//}
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
int min(int a, int b)
{
	return a>b ? b : a;
}
int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.size() == 0)
		return 0;
	char max = '0';
	for (int i = 0; i<matrix.size(); i++)
	{
		for (int j = 0; j<matrix[0].size(); j++)
		{
			if (matrix[i][j] == '0')
				continue;
			if (i == 0 || j == 0)
			{

				if (matrix[i][j]>max)
					max = matrix[i][j];
				continue;
			}

			if (matrix[i - 1][j - 1] != '0'&&matrix[i - 1][j] >= matrix[i - 1][j - 1] && matrix[i - 1][j - 1] <= matrix[i][j - 1])
			{
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
				if (matrix[i][j]>max)
					max = matrix[i][j];
			}
			else if (matrix[i - 1][j - 1] != '0'&&matrix[i - 1][j] != '0'&&matrix[i][j - 1] != '0')
			{
				matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1] != '0') + 1+'0';
				if (matrix[i][j]>max)
					max = matrix[i][j];
			}
			else
			{
				if (matrix[i][j]>max)
					max = matrix[i][j];
			}
		}
	}
	return (max - '0')*(max - '0');
}
vector<int> countBits(int num) {
	vector<int> v(num + 1, 0);
	if (num == 0)
		return v;

	int i = 0;
	int n = 1;
	while (n <= num)
	{
		while (i<n&&i + n <= num)
		{
			v[i + n] = v[i] + 1;
			i++;
		}
		i = 0;
		n <<= 1;
	}
	return v;
}
bool isSubsequence(string s, string t) {
	vector<vector<int>>v(s.size(), vector<int>(t.size(), 1));
	for (int i = 0; i<s.size(); i++)
	{
		for (int j = 0; j<t.size(); j++)
		{
			if (i == 0)
			{
				if (s[i] == t[j])
				{
					v[i][j] = 0;
					break;
				}
				else
				{
					v[i][j] = 0;
				}
				continue;
			}
			if (v[i - 1][j] && s[i] == t[j])
			{
				if(i!=s.size()-1||j!=t.size()-1)
				v[i][j] = 0;
				break;
			}
			else
			{
				v[i][j] = 0;
			}
		}
	}
	return v[s.size() - 1][t.size() - 1];
}
int nthUglyNumber(int n)
{
	if (n == 0)
		return 0;
	int* arr = new int[n];
	arr[0] = 1;
	int p2 = 0;
	int p3 = 0;
	int p5 = 0;
	int i;
	for (i = 1; i<n; i++)
	{
		int ugly = min(arr[p2] * 2, min(arr[p3] * 3, arr[p5] * 5));
		arr[i] = ugly;
		if (ugly == arr[p2] * 2)
			++p2;
		if (ugly == arr[p3] * 3)
			++p3;
		if (ugly == arr[p5] * 5)
			++p5;
	}
	return arr[i - 1];
}
int robmax(vector<int>& nums, int begin, int end)
{
	int a1 = 0;
	int a2 = 0;
	int a3 = 0;
	for (int i = begin; i<end; i++)
	{
		a1 = max(a2, a3 + nums[i]);
		a3 = a2;
		a2 = a1;
	}
	return a1;
}
int rob(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	return max(robmax(nums, 0, nums.size() - 1), robmax(nums, 1, nums.size()));
}
int maxArea(vector<int>& height) {
	int max = 0;
	int it1 = 0;
	int it2 = height.size() - 1;
	while (it1<it2)
	{
		int temp = 0;
		if (height[it1]<height[it2])
		{
			temp=height[it1] * (it2 - it1);
			it1++;
		}
		else
		{
			temp = height[it2] * (it2 - it1);
				it2--;
		}
		if (temp > max)
			max = temp;
	}
	return max;
}
int searchleft(vector<int>& nums, int target, int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target && (mid - 1 < 0 || nums[mid - 1] != target))
		{
			return mid;
		}
		else if (nums[mid] >= target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}

	}
	return -1;
}
int searchright(vector<int>& nums, int target, int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target && (mid + 1 >= nums.size() || nums[mid + 1] != target))
		{
			return mid;
		}
		else if (nums[mid]>target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}

	}
	return -1;
}
vector<int> searchRange(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	vector<int> v(2, -1);
	v[0] = searchleft(nums, target, 0, nums.size() - 1);
	v[1] = searchright(nums, target, 0, nums.size() - 1);
	return v;
}
bool canJump(vector<int>& nums) {
	vector<int> v(nums.size(), 0);
	v[0] = 1;
	for (int i = 0; i<nums.size(); i++)
	{
		if (v[i])
		{
			for (int j = i + 1; j <= nums[i] + i && j<nums.size(); j++)
			{
				v[j] += 1;
			}
		}
	}
	return v[nums.size() - 1];
}
int coinChange(vector<int>& coins, int amount) {
	if (amount == 0)
		return 0;
	vector<int> v(amount + 1, INT_MAX);
	v[0] = 0;

	for (int i = 0; i<amount; i++)
	{
		if (v[i] == INT_MAX)
			continue;
		for (int j = 0; j<coins.size(); j++)
		{
			if (coins[j]== 2147483647 ||(i + coins[j])>amount)
				continue;
			if (v[i + coins[j]] > v[i])
				v[i + coins[j]] = v[i] + 1;
		}
	}
	if (v[amount] == INT_MAX)
		return -1;
	return v[amount];
}
int integerBreak(int n) {
	if (n<4)
		return n - 1;
	vector<int> v(4, 1);
	v[2] = 2;
	v[3] = 3;
	for (int i = 4; i<=n; i++)
	{
		int max1 = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			max1 = max(v[j] * v[i - j], max1);
		}
		v.push_back(max1);
	}
	return v[n];
}
int findDuplicate(vector<int>& nums) 
{
	while (1)
	{
		if (nums[0] == nums[nums[0]])
			return nums[0];
		swap(nums[0], nums[nums[0]]);
	}
}
vector<int> findDuplicates(vector<int>& nums) {
	vector<int> v;
	for (int i = 0; i<nums.size(); i++)
	{
		if (i + 1 == nums[i])
			continue;
		while (nums[i] != nums[nums[i] - 1])
			swap(nums[i], nums[nums[i] - 1]);
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (i + 1 != nums[i])
			v.push_back(nums[i]);
	}

	return v;
}
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	if (k <= 1)
		return 0;
	int pos = 1;
	int left = 0;
	int ret = 0;
	for (int right = 0; right<nums.size(); right++)
	{
		pos *= nums[right];
		while (pos >= k)
			pos /= nums[left++];
		ret += right - left + 1;
	}
	return ret;
}
int max(double a, double b)
{
	return a>b ? a : b;
}
double findMaxAverage(vector<int>& nums, int k) {
	if (nums.size() == 1)
		return nums[0];

	for (int i = 1; i<nums.size(); i++)
		nums[i] += nums[i - 1];
	double ret = nums[k-1] * 1.0 / k;
	for (int i = k; i<nums.size(); i++)
	{
		ret = max(ret, (nums[i] - nums[i - k])*1.0 / k);
	}
	return ret;
}
int numSquares(int n) {
	vector<int> v(n, 0);
	for (int i = 0; i<n; i++)
	{
		if (i + 1 == (int)sqrt(i + 1)*(int)sqrt(i + 1))
		{
			v[i] = 1;
			continue;
		}
		int min1 = INT_MAX;
		for (int j = i - 1; j >= i / 2; j--)
		{
			min1 = min(min1, v[j] + v[i - j-1]);
		}
		v[i] = min1;
	}
	return v[n - 1];
}
int lengthOfLIS(vector<int>& nums) {
	vector<int> v(nums.size(), 0);
	v[0] = 1;
	int ret = 1;
	for (int i = 1; i<nums.size(); ++i)
	{
		int temp = 0;
		for (int j = 0; j<i; ++j)
		{
			if (nums[i]>nums[j])
				temp = max(temp, v[j]);
		}
		v[i] = temp + 1;
		ret = max(ret, v[i]);
	}
	return ret;
}
bool circularArrayLoop(vector<int>& nums) {
	if (nums.size() == 0)
		return false;
	int flag = 0;
	int len = nums.size();
	if (nums[0]<0)
		flag = 1;
	int i = 0;
	while (0 != (i + nums[i] + len) % len)
	{
		if (i == (i + nums[i] + len) % len)
			return false;
		if (flag&&nums[(i + nums[i] + len) % len]>0)
			return false;
		if (flag == 0 && nums[(i + nums[i] + len) % len]<0)
			return false;
		i = (i + nums[i] + len) % len;
	}
	return true;
}
vector<int> addToArrayForm(vector<int>& A, int K) {
	int cina = 0;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		if (i == 0 && K>9)
		{
			A.insert(A.begin(), 0);
			i++;
		}
		if (K == 0 && cina == 0)
			break;
		int temp = A[i] + K % 10 + cina;
		cina = 0;
		A[i] = temp % 10;
		K /= 10;
		if (temp>9)
			cina = 1;
	}
	if (cina)
	{
		A.insert(A.begin(), 1);
	}
	return A;
}
int getnum(int num)
{
	int sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
	}
	if (sum == 15)
		return 1;
	return 0;
}
vector<vector<int>> transpose(vector<vector<int>>& A) {
	vector<vector<int>> v(A[0].size(), vector<int>(A.size(), 0));
	for (int i = 0; i<A.size(); i++)
	{
		for (int j = 0; j<A[i].size(); j++)
		{
			v[j][i] = A[i][j];
		}
	}
	return v;
}
void gameOfLife(vector<vector<int>>& board) {
	int arr[] = { 0,1,-1 };
	for (int i = 0; i<board.size(); i++)
	{
		for (int j = 0; j<board[0].size(); j++)
		{
			int sum = 0;
			for (int a = 0; a<3; a++)
			{
				for (int b = 0; b<3; b++)
				{
					if (!(a == 0 && b == 0))
					{
						int r = i + arr[a];
						int l = j + arr[b];
						if ((r<board.size() && r >= 0) && (l<board[0].size() && l >= 0) && abs(board[r][l]) == 1)
							sum++;
					}
				}
			}
			if (board[i][j] == 1 && (sum<2 || sum>3))
				board[i][j] = -1;
			if (board[i][j] == 0 && (sum == 3))
				board[i][j] = 2;
		}
	}
	for (int i = 0; i<board.size(); i++)
	{
		for (int j = 0; j<board[0].size(); j++)
		{
			if (board[i][j]>0)
				board[i][j] = 1;
			else
				board[i][j] = 0;
		}
	}
}
typedef struct ListNode
{
	int price;
	int run;
}ListNode;
//int main()
//{
//	int B, N;
//	N = 0;
//	cin >> B >> N;
//	vector<ListNode> dp(N, ListNode());//初始化N个节点空间
//	for (int i = 0; i < N; i++)
//	{
//		cin >> dp[i].price >> dp[i].run;
//	}
//	//sort(dp.begin(), dp.end());//默认升序
//							   //此时得到的向量空间就是升序的
//	int count = 0;
//	vector<ListNode>::iterator it = dp.begin();
//	//关键优惠劵给哪个牛，应该是最大优惠的那个牛即礼物临届最贵的牛
//	while (it != dp.end() && N > 0)
//	{
//		N -= ((*it).price + (*it).run);
//		count++;
//		it++;
//	}
//	if (it == dp.end())
//	{
//		cout << "最大奶牛数" << count << endl;
//	}
//	else if (N + (*it).price / 2 >= (*(it + 1)).price + (*(it + 1)).run)
//	{
//		count++;
//	}
//	cout << "最大奶牛数" << count << endl;
//	system("pause");
//	return 0;
//}
//int main()
//{
//	vector<vector<int>> v = { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
//	gameOfLife(v);
//	//for (int i = 200; i <= 300; i++)
//	//{
//	//	if (getnum(i))
//	//		printf("%d ", i);
//	//}
//	//vector<int> v = { 0 };
//	//addToArrayForm(v, 23);
//	//cout << circularArrayLoop(v) << endl;
//	//vector<int> arr=findDuplicates(v);
//	//for (int i = 0; i < arr.size(); i++)
//	//	cout << arr[i] << " ";
//	//cout << endl;
//	//vector<int> a = searchRange(v,8);
//	//for (int i = 0; i < a.size(); i++)
//	//	cout << a[i]<<" ";
//	//cout << endl;
//	//vector<vector<char>> v = { {'0', '0', '0', '1'},{'1', '1', '0', '1'},{'1', '1', '1', '1'},{'0', '1', '1', '1'},{ '0', '1', '1', '1' } };
//	//string s1 = "abc";
//	//string s2 = "ahbgdc";
//	//string s = "catsandog";
//	//vector<string> wordDict = { "cats", "dog", "sand", "and", "cat" };
//	//vector< vector< vector< int > > > vecInt(10, vector< vector< int > >(10, vector< int >(10, 10)));
//	//vector<vector<int>> v = { {2},{3, 4},{6, 5, 7},{4, 1, 8, 3} };
//	//string s = "01";
//	//cout << isSubsequence(s1,s2) << endl;
//
//	system("pause");
//
//	return 0;
//}
int findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int i = 0;
	int j = 0;
	while (i<g.size() && j<s.size())
	{
		if (s[j] >= g[i])
		{
			j++;
		}
		i++;
	}
	return j;
}
bool lemonadeChange(vector<int>& bills) {
	int five = 0;
	int ten = 0;
	for (int i = 0; i<bills.size(); i++)
	{
		if (bills[i] == 5)
		{
			five++;
		}
		else if (bills[i] == 10)
		{
			if (five == 0)
				return false;
			five--;
			ten++;
		}
		else
		{
			if (five&&ten)
			{
				five--;
				ten--;
			}
			else if (five >= 3)
			{
				five -= 3;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}
bool isMatch(string s, string p) {
	vector<vector<int>> v(s.size() + 1, vector<int>(p.size() + 1, 0));
	v[0][0] = 1;
	for (int i = 1; i <= p.size(); i++)
	{
		if (i == 1)
			continue;
		v[0][i] = v[0][i - 2] && (p[i - 1] == '*');
	}
	for (int i = 1; i <= s.size(); i++)
		for (int j = 1; j <= p.size(); j++)
		{
			if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
				v[i][j] = v[i - 1][j - 1];
			else if (p[j - 1] == '*')
			{
				if (j<2)
					continue;
				if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
				{
					v[i][j] = v[i - 1][j] || v[i][j - 1] || v[i][j - 2];
				}
				else if (p[j - 2] != '.'&&p[j - 2] != s[i - 1])
				{
					v[i][j] = v[i][j - 2];
				}
			}
		}
	return v[s.size()][p.size()];
}
//void get(vector<int>& temp, int target, int pos, vector<int> v);
//
//	vector<vector<int>> ret;
//	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//		if (candidates.size() == 0)
//			return ret;
//		vector<int> v;
//		sort(candidates.begin(), candidates.end());
//		get(candidates, target, 0, v);
//		return ret;
//
//	}
//	void get(vector<int>& temp, int target, int pos, vector<int> v)
//	{
//		if (target == 0)
//		{
//			ret.push_back(v);
//			return;
//		}
//		if (target>0)
//		{
//			for (int i = pos; i<temp.size(); i++)
//			{
//				if (!v.empty() && v.back()>temp[i])
//					continue;
//				if (i>pos&&temp[i] == temp[i - 1])
//					continue;
//				v.push_back(temp[i]);
//				get(temp, target - temp[i], i+1, v);
//				v.pop_back();
//			}
//		}
//	}
	//vector<vector<int>> ret;
	//vector<vector<int>> subsets(vector<int>& nums) {
	//	vector<int> v;
	//	get(nums, v, 0);
	//	return ret;
	//}
	//void get(vector<int>& temp, vector<int> v, int pos)
	//{
	//	if (pos <= temp.size())
	//	{
	//		ret.push_back(v);
	//		for (int i = 0; i<temp.size(); ++i)
	//		{
	//			if (!v.empty() && v.back()>temp[i])
	//				continue;
	//			if (find(v.begin(), v.end(), temp[i]) != v.end())
	//				continue;
	//			v.push_back(temp[i]);
	//			get(temp, v, pos + 1);
	//			v.pop_back();
	//		}
	//	}
	//}
//vector<vector<int>> ret;
//vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//	vector<int> v;
//	vector<bool> bl(nums.size(), false);//保存已经访问过的变量位置
//	sort(nums.begin(), nums.end());
//	get(nums, v, 0, bl);
//	return ret;
//}
//void get(vector<int>& nums, vector<int> v, int pos, vector<bool> bl)
//{
//	ret.push_back(v);
//	if (v.size() < nums.size())//当数组大小与所给的数组大小相等时，停止回溯
//	{
//		for (int i = pos; i<nums.size(); ++i)
//		{
//			if (bl[i])
//				continue;
//			if (i>0 && nums[i] == nums[i - 1] && !bl[i - 1])//bl[i-1]可以不加！
//				continue;
//			bl[i] = true;
//			v.push_back(nums[i]);
//			get(nums, v, i + 1, bl);//典型的回溯套路
//			bl[i] = false;
//			v.pop_back();
//		}
//	}
//}
vector<int> decompressRLElist(vector<int>& nums) {
	int i = 0;
	vector<int> v;
	while (i<nums.size())
	{
		int num = nums[i];
		i++;
		for (int j = 0; j<num; j++)
			v.push_back(nums[i]);
		i++;
	}
	return v;
}
int numJewelsInStones(string J, string S) {
	int ret = 0;
	for (string::iterator it = J.begin(); it<J.end(); it++)
	{
		int i = 0;
		string::iterator temp = S.begin();
		while ((temp = find(temp, S.end(), *it)) != S.end())
		{
			temp++;
			ret++;
		}
	}
	return ret;
}
int main()
{
	vector<int> v1 = { 1,2,3,4 };
	vector<int> v2 = { 5,6,7,8 };
	//decompressRLElist(v1);
	cout << numJewelsInStones("aA","aAAbbbb") << endl;
	//combinationSum2(v1, 8);
	//findContentChildren(v1, v2);
	system("pause");
	return 0;
}