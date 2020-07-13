#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<set>
#include<cmath>
#include<functional>
#include <algorithm>
#include<map>
#include<unordered_map>

using namespace std;
class Base
{
public:
	virtual void show()
	{
		std::cout << "Base:....." << endl;
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
//typedef struct ListNode
//{
//	int price;
//	int run;
//}ListNode;
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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* ret(vector<int>& nums, int left, int right)
{
	if (left >= right)
		return NULL;
	int mid = (left + right) / 2;
	TreeNode* temp = new TreeNode(nums[mid]);
	temp->left=ret(nums, left, mid - 1);
	temp->right=ret(nums, mid + 1, right);
	return temp;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
	return ret(nums, 0, nums.size() - 1);
}

//int main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//		if (s == "")
//			continue;
//		for (string::iterator it = s.begin(); it != s.end(); it++)
//		{
//			for (string::iterator i = it + 1; i != s.end();)
//			{
//				if (*it == *i)
//					s.erase(i++);
//				else
//					i++;
//			}
//		}
//		cout << s << endl;
//	}
//}

int countSquares(vector<vector<int>>& matrix) {
	int ret = 0;
	for (int i = 0; i<matrix.size(); i++)
	{
		for (int j = 0; j<matrix[i].size(); j++)
		{
			if (matrix[i][j])
				++ret;
			else
				continue;
			if (i == 0 || j == 0)
				continue;
			matrix[i][j] = max(matrix[i][j], min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1]))+1);
			ret += (matrix[i][j] - 1);
		}
	}
	return ret;
}
int countSubstrings(string s) {
	vector<vector<bool>> v(s.size(), vector<bool>(s.size(), false));
	int ret = 0;
	for (int i = 0; i<s.size(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (s[i] == s[j] && (i - j<2 || v[i - 1][j + 1]))
			{
				v[i][j] = true;
				ret++;
			}
		}
	}
	return ret;
}
int findLength(vector<int>& A, vector<int>& B) {
	vector<vector<int>> v(A.size(), vector<int>(B.size(), 0));
	int ret = 0;
	for (int i = 0; i<A.size(); i++)
	{
		for (int j = 0; j<B.size(); j++)
		{
			if (A[i] == B[j])
			{
				if (i == 0 || j == 0)
					v[i][j] = 1;
				else
					v[i][j] = v[i - 1][j - 1] + 1;
				if (ret<v[i][j])
					ret = v[i][j];
			}
		}
	}
	return ret;
}
int longestCommonSubsequence(string text1, string text2) {
	vector<vector<int>> v(text1.size() + 1, vector<int>(text2.size() + 1, 0));
	for (int i = 1; i <= text1.size(); i++)
	{
		for (int j = 1; j <= text2.size(); j++)
		{
			if (text1[i - 1] == text2[j - 1])
			{
				v[i][j] = v[i - 1][j - 1]+1;
			}
			else
			{
				v[i][j] = max(v[i - 1][j], v[i][j - 1]);
			}
		}
	}
	return v[text1.size()][text2.size()];
}
bool palindrome(string s)
{
	string::iterator it1 = s.begin();
	string::iterator it2 = s.end() - 1;
	while (it1<it2)
	{
		if (*it1 != *it2)
			return false;
		it1++;
		it2--;
	}
	return true;
}
int combinationSum4(vector<int>& nums, int target) {
	vector<unsigned int> v(target + 1, 0);
	v[0] = 1;
	for (int i = 1; i<v.size(); i++)
	{
		for (int j = 0; j<nums.size(); j++)
		{
			if (i - nums[j] >= 0)
			{
				v[i] += v[i - nums[j]];
			}
		}
	}
	return v[target];
}
vector<vector<string>> ret1;
void get1(string& s, vector<string> temp, int pos)
{
	if (pos == s.size())
	{
		ret1.push_back(temp);
		return;
	}
	for (int i = pos; i < s.size(); i++)
	{
		if (!palindrome(s.substr(pos, i - pos + 1)))
			continue;
		temp.push_back(s.substr(pos, i - pos + 1));
		get1(s, temp, i + 1);
		temp.pop_back();
	}
}

vector<vector<string>> partition(string s) {
	vector<string> temp;
	get1(s, temp, 0);
	return ret1;
}


//int guessNumber(int n) {
//	int left = 1;
//	int right = n;
//
//	while (left <= right)
//	{
//		unsigned int mid = left + (right - left) / 2;
//		if (guess(mid) == 1)
//		{
//			left = mid + 1;
//		}
//		else if (guess(mid) == -1)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return 0;
//}
int longestPalindromeSubseq(string s) {
	vector<vector<int>> v(s.size(), vector<int>(s.size(), 0));
	for (int i = 0; i<s.size(); i++)
	{
		v[i][i] = 1;
	}
	for (int i = s.size() - 1; i >= 0; i--)
	{
		for (int j = i + 1; j<s.size(); j++)
		{
			if (s[i] == s[j])
			{
				v[i][j] = v[i + 1][j - 1] + 2;
			}
			else
			{
				v[i][j] = max(v[i + 1][j], v[i][j - 1]);
			}
		}
	}
	return v[0][s.size() - 1];
}
int* GetNext(string s)
{
	int i = 0;
	int j = -1;
	int* next = new int[s.size()];
	next[0] = -1;
	while (i < s.size())
	{
		if (j == -1 || s[i] == s[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
	return next;
}
int KMP1(string s1, string s2)
{
	int i = 0;
	int j = 0;
	int* next = GetNext(s2);
	while (i < s1.size() && j < s2.size())
	{
		if (j == -1 || s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == s2.size())
		return i - j;
	return -1;
}
int minFallingPathSum(vector<vector<int>>& A) {
	int ret = INT_MAX;
	if (A.size() == 1)
	{
		for (int i = 0; i<A[0].size(); i++)
			ret = min(ret, A[0][i]);
		return ret;
	}
	for (int i = 1; i<A.size(); i++)
	{
		for (int j = 0; j<A[0].size(); j++)
		{
			if (j == 0)
			{
				A[i][j] += min(A[i - 1][j], A[i - 1][j + 1]);
			}
			else if (j == A[0].size() - 1)
			{
				A[i][j] += min(A[i - 1][j], A[i - 1][j - 1]);
			}
			else
			{
				A[i][j] += min(A[i - 1][j], min(A[i - 1][j - 1], A[i - 1][j + 1]));
			}
			if (i == A.size() - 1)
			{
				ret = min(ret, A[i][j]);
			}
		}
	}
	return ret;
}
template <typename T>
class AVLNode
{
public:
	AVLNode(T val)
	{
		this->val = val;
		this->lchild = nullptr;
		this->rchild = nullptr;
		this->height = 1;
	}
	T val;
	size_t height;
	AVLNode* lchild;
	AVLNode* rchild;
};

template <typename T>
class AVLTree
{
public:
	AVLNode<T>* root;
	size_t size;

public:
	AVLTree()
	{
		root = nullptr;
		size = 0;
	}
	int GetSize()
	{
		return size;
	}
	bool isEmpty(AVLNode<T>*& root)
	{
		return root == nullptr;
	}
	void AddNode(T val)
	{
		root=add(root, val);
	}
	int GetMIN()
	{
		if (root == nullptr)
			return INT_MIN;
		return Min(root)->val;
	}
	int GetMAX()
	{
		if (root == nullptr)
			return INT_MAX;
		return MAX(root)->val;
	}
	void RemoveMIN()
	{
		RemoveMin(root);
	}
	void RemoveMAX()
	{
		RemoveMax(root);
	}
	void Remove(T value)
	{
		root=Remove(root, value);
	}
private:
	AVLNode<T>* Remove(AVLNode<T>*& node, T value)
	{
		if (node == nullptr)
			return nullptr;
		AVLNode<T>* retnode;
		if (node->val > value)
		{
			node->lchild = Remove(node->lchild, value);
			retnode = node;
		}
		else if (node->val < value)
		{
			node->rchild = Remove(node->rchild, value);
			retnode = node;
		}
		else
		{
			if (node->lchild == nullptr)
			{
				AVLNode<T>* right = node->rchild;
				delete node->rchild;
				node->rchild = nullptr;
				size--;
				retnode = right;
			}
			else if (node->rchild == nullptr)
			{
				AVLNode<T>* left = node->lchild;
				delete node->lchild;
				node->lchild = nullptr;
				size--;
				retnode = left;
			}
			else
			{
				AVLNode<T>* removenode = MIN(node->rchild);
				removenode->rchild = Remove(node->rchild, removenode->val);
				removenode->lchild = node->lchild;
				node->lchild = node->rchild = nullptr;
				retnode = removenode;
			}
			if (retNode == null)
				return null;
			//维护平衡
			//更新height
			retnode->height = 1 + max(GetHeight(retnode->lchild), GetHeight(retnode->rchild));
			//计算平衡因子
			int balanceFactor = GetBalanceFactor(retnode);
			if (balanceFactor > 1 && GetBalanceFactor(retnode->lchild) > 0) {
				//右旋LL
				return rightRotate(retNode);
			}
			if (balanceFactor < -1 && GetBalanceFactor(retnode->rchild) < 0) {
				//左旋RR
				return leftRotate(retNode);
			}
			//LR
			if (balanceFactor > 1 && GetBalanceFactor(retnode->lchild) < 0) {
				node.left = leftRotate(retnode->lchild);
				return rightRotate(retnode);
			}
			//RL
			if (balanceFactor < -1 && GetBalanceFactor(retnode->rchild) > 0) {
				node.right = rightRotate(retnode->rchild);
				return leftRotate(retnode);
			}
			return retnode;
		}
	}
	AVLNode<T>*& RemoveMin(AVLNode<T>*& node)
	{
		if (node->lchild==nullptr)
		{
			node = node->rchild;
			this->size--;
			return node;
		}
		node->lchild = RemoveMin(node->lchild);
		return node;
	}
	AVLNode<T>*& RemoveMax(AVLNode<T>*& node)
	{
		if (node->rchild == nullptr)
		{
			node = node->lchild;
			this->size--;
			return node;
		}
		node->rchild = RemoveMin(node->rchild);
		return node;
	}
	AVLNode<T>*& Min(AVLNode<T>*& node)
	{
		if (node->lchild == nullptr)
			return node;
		return Min(node->lchild);
	}
	AVLNode<T>*& MAX(AVLNode<T>*& node)
	{
		if (node->rchild == nullptr)
			return node;
		return MAX(node->rchild);
	}
	AVLNode<T>* add(AVLNode<T>*& node, T val)
	{
		if (node == nullptr) {
			size++;
			return new AVLNode<T>(val);
		}
		if (val < node->val)
			node->lchild = add(node->lchild, val);
		else if (val > node->val)
			node->rchild = add(node->rchild, val);
		//更新height
		node->height = 1 + max(GetHeight(node->lchild), GetHeight(node->rchild));
		//计算平衡因子
		int balanceFactor = GetBalanceFactor(node);
		if (balanceFactor > 1 && GetBalanceFactor(node->lchild)>0) {
			//右旋LL
			return rightRotate(node);
		}
		if (balanceFactor < -1 && GetBalanceFactor(node->rchild)<0) {
			//左旋RR
			return leftRotate(node);
		}
		//LR
		if (balanceFactor > 1 && GetBalanceFactor(node->lchild) < 0) {
			node->lchild = leftRotate(node->lchild);
			return rightRotate(node);
		}
		//RL
		if (balanceFactor < -1 && GetBalanceFactor(node->rchild) > 0) {
			node->rchild = rightRotate(node->rchild);
			return leftRotate(node);
		}
		return node;
	}
	AVLNode<T> * leftRotate(AVLNode<T>*& node)
	{
		AVLNode<T>* t1 = node->rchild;
		AVLNode<T>* t2 = t1->lchild;
		t1->lchild = node;
		node->rchild = t2;
		node->height = max(GetHeight(node->lchild), GetHeight(node->rchild)) + 1;
		t1->height = max(GetHeight(t1->lchild), GetHeight(t1->rchild)) + 1;
		return t1;
	}
	AVLNode<T>* rightRotate(AVLNode<T>*& node)
	{
		AVLNode<T>* x = node->lchild;
		AVLNode<T>* t3 = x->rchild;
		x->rchild = node;
		node->lchild = t3;
		//更新height
		node->height = max(GetHeight(node->lchild), GetHeight(node->rchild)) + 1;
		x->height = max(GetHeight(x->lchild), GetHeight(x->rchild)) + 1;
		return x;
	}

	bool isBalance(AVLNode<T>*& node)
	{
		if (node == nullptr)
			return true;
		if (GetBalanceFactor(node) > 1 || GetBalanceFactor(node) < -1)
			return false;
		return isBalance(node->lchild) && isBalance(node->rchild);
	}
	int GetBalanceFactor(AVLNode<T>*& node)
	{
		if (node == nullptr)
			return 0;
		return GetHeight(node->lchild) - GetHeight(node->rchild);
		//return node->lchild->height - node->rchild->height;
	}
	int GetHeight(AVLNode<T>*& node)
	{
		if (node == nullptr)
			return 0;
		return node->height;
	}

};

int maxScore(vector<int>& cardPoints, int k) {
	int sum = 0;
	int sum1 = 0;
	int max1 = INT_MIN;
	for (int i = 0; i<cardPoints.size(); i++)
	{
		if (i >= cardPoints.size() - k)
		{
			sum += cardPoints[i];
			sum1 += cardPoints[i];
		}
		else
		{
			sum += cardPoints[i];
		}
	}
	max1 = sum1;
	for (int i = cardPoints.size() - k; i<cardPoints.size(); i++)
	{
		sum1 += cardPoints[i - cardPoints.size() + k] - cardPoints[i];
		max1 = max(sum1, max1);
	}
	return max1;
}
class Solution_letterCombinations {
public:
	vector<string> ret;
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return ret;
		vector<string> dic = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		string str;
		get(digits, dic, 0, str);
		return ret;
	}
	void get(string digits, vector<string> dic, int pos, string str)
	{
		if (str.size() == digits.size())
		{
			ret.push_back(str);
			return;
		}
		for (int i = 0; i<dic[digits[pos] - '0' - 2].size(); i++)
		{
			str += dic[digits[pos] - '0' - 2][i];
			get(digits, dic, pos + 1, str);
			str.pop_back();
		}
	}
};
class Solution_findRepeatNumber {
public:
	int findRepeatNumber(vector<int>& nums) {
		for (int i = 0; i<nums.size(); i++)
		{
			while (i != nums[i])
			{
				if (nums[i] == nums[nums[i]])
					return nums[i];
				swap(nums[i], nums[nums[i]]);
			}
		}
		return 0;
	}
};
class Solution_generateParenthesis {
public:
	vector<string> ret;
	vector<string> generateParenthesis(int n) {
		string str;
		get(str, n, 0, 0);
		return ret;
	}
	void get(string str, int n, int left, int right)
	{
		if (str.size() == n * 2)
		{
			ret.push_back(str);
			return;
		}
		if (left<n)
		{
			str += '(';
			get(str, n, left + 1, right);
			str.pop_back();
		}
		if (right<left)
		{
			str += ')';
			get(str, n, left, right + 1);
			str.pop_back();
		}
	}
};
class Solution_checkSubarraySum {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		if (nums.size()<2)
			return false;
		for (int i = 1; i<nums.size(); i++)
		{
			nums[i] += nums[i - 1];
		}

		for (int i = 1; i<nums.size(); i++)
		{
			if (k == 0)
			{
				if (nums[i] == 0)
					return true;
				if (i>1 && nums[i] == nums[i - 2])
					return true;
			}
			else
			{
				if (nums[i] % k == 0)
				{
					return true;
				}
				else
				{
					for (int j = i - 2; j >= 0; j--)
					{
						if ((nums[i] - nums[j]) % k == 0)
							return true;
					}
				}
			}
		}
		return false;
	}
};
class Solution_topKFrequent {
public:
	static bool cmp(pair<string, int> s1, pair<string, int> s2)
	{
		if (s1.second == s2.second)
			return s1.first<s2.first;
		return s1.second>s2.second;
	}
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> mp;
		vector<string> ret;
		vector<pair<string, int>> temp;
		for (const auto& e : words)
			++(mp[e]);
		for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
			temp.push_back(pair<string, int>(it->first, it->second));
		sort(temp.begin(), temp.end(), cmp);
		if (words.size()>k)
			temp.erase(temp.begin() + k, temp.end());
		for (const auto& e : temp)
			ret.push_back(e.first);
		return ret;
	}
};
class Solution_permutation {
public:
	vector<string> ret;
	vector<string> permutation(string S) {
		vector<bool> bl(S.size(), false);
		string temp;
		get(S, bl, temp);
		return ret;
	}
	void get(string S, vector<bool> bl, string temp)
	{
		if (temp.size() == S.size())
		{
			ret.push_back(temp);
			return;
		}
		for (int i = 0; i<S.size(); i++)
		{
			if (bl[i])
				continue;
			bl[i] = true;
			temp += S[i];
			get(S, bl, temp);
			temp.pop_back();
			bl[i] = false;
		}
	}
};
class Solution_constructMaximumBinaryTree {
public:
	int getMax(vector<int>& nums, int left, int right)
	{
		int max = left;
		for (int i = left; i <= right; i++)
		{
			if (nums[max]<nums[i])
				max = i;
		}
		return max;
	}
	TreeNode* GetTree(vector<int>& nums, int left, int right)
	{
		if (left>right)
			return NULL;
		int n = getMax(nums, left, right);
		TreeNode* root = new TreeNode(nums[n]);
		root->left = GetTree(nums, left, n - 1);
		root->right = GetTree(nums, n + 1, right);
		return root;
	}
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return GetTree(nums, 0, nums.size() - 1);
	}
};
int findMaxLength(vector<int>& nums) {
	map<int, int> mp{ { 0,-1 } };
	int retlen = 0;
	int count1 = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		count1 += (nums[i] ? 1 : -1);
		if (mp.count(count1))
		{
			retlen = max(retlen, i - mp[count1]);
		}
		else
		{
			mp[count1] = i;
		}
	}
	return retlen;
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> ret;
	if (nums.size()<4)
		return ret;
	sort(nums.begin(), nums.end());
	vector<int> v;
	for (int i = 0; i <= nums.size() - 4; ++i)
	{
		if (i>0 && nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j <= nums.size() - 3; ++j)
		{
			if (j>i + 1 && nums[j] == nums[j - 1])
			{
				continue;
			}
			int left = j + 1;
			int right = nums.size() - 1;
			while (left<right)
			{
				if (nums[i] + nums[j] + nums[left] + nums[right]<target)
				{
					++left;
				}
				else if (nums[i] + nums[j] + nums[left] + nums[right]>target)
				{
					--right;
				}
				else
				{
					v.push_back(nums[i]);
					v.push_back(nums[j]);
					v.push_back(nums[left]);
					v.push_back(nums[right]);
					ret.push_back(v);
					v.clear();
					while (left<right&&nums[left] == nums[left + 1])
						++left;
					while (left<right&&nums[right] == nums[right - 1])
						--right;
					++left;
					--right;
				}
			}
		}
	}
	return ret;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	map<string, vector<string>> mp;
	vector<vector<string>> ret;
	for (int i = 0; i<strs.size(); i++)
	{
		string temp = strs[i];
		sort(temp.begin(), temp.end());
		mp[temp].push_back(strs[i]);
	}
	for (pair<string, vector<string>> e : mp)
	{
		ret.push_back(e.second);
	}
	return ret;
}
class Solution_pairSums {
public:
	vector<vector<int>> pairSums(vector<int>& nums, int target) {
		map<int, int> mp;
		vector<vector<int>> ret;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (mp[target - nums[i]])
			{
				--mp[target - nums[i]];
				ret.push_back({ target - nums[i],nums[i] });
			}
			else
				++mp[nums[i]];
		}
		return ret;
	}
};
class Solution_findFrequentTreeSum {
public:
	vector<int> ret;
	int flag;
	map<int, int> mp;
	vector<int> findFrequentTreeSum(TreeNode* root) {
		flag = 0;
		get(root);
		for (auto& x : mp)
		{
			if (x.second == flag)
				ret.push_back(x.first);
		}
		return ret;
	}
	int get(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		root->val += get(root->left) + get(root->right);
		++mp[root->val];
		if (mp[root->val]>flag)
			flag = mp[root->val];
		return root->val;
	}
};
class Solution_findDuplicates {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> v;
		for (int i = 0; i<nums.size(); i++)
		{
			int num = abs(nums[i]);
			if (nums[num - 1]>0)
				nums[num - 1] = -nums[num - 1];
			else
				v.push_back(num);
		}
		return v;
	}
};
int lengthOfLongestSubstring(string s) {
	map<char, int> mp;
	int ret = 0;
	int temp = 0;
	int j = 0;
	for (int i = 0; i<s.size(); ++i)
	{
		if (mp.count(s[i]))
			j = mp[s[i]];
		else
			j = -1;
		mp[s[i]] = i;
		temp = temp<i - j ? temp + 1 : i - j;
		ret = max(ret, temp);
	}
	return ret;
}
class Solution_firstUniqChar {
public:
	char firstUniqChar(string s) {
		map<char, int> mp;
		for (int i = 0; i<s.size(); ++i)
			++mp[s[i]];
		for (int i = 0; i<s.size(); ++i)
			if (mp[s[i]] == 1)
				return s[i];
		return ' ';
	}
};
class Solution_cuttingRope {
public:
	int cuttingRope(int n) {
		vector<int> v(n + 1, 1);
		for (int i = 2; i <= n; ++i)
		{
			for (int j = i - 1; j >= i / 2; --j)
			{
				v[i] = max(v[i], max(j, v[j])*max(i - j, v[i - j]));
			}
		}
		return v[n];
	}
};
class Solution_twoSum {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int right = nums.size() - 1;
		int left = 0;
		vector<int> ret;
		while (left<right)
		{
			if (nums[right] + nums[left]<target)
				++left;
			else if (nums[right] + nums[left]>target)
				--right;
			else
			{
				ret.push_back(nums[right]);
				ret.push_back(nums[left]);
				return ret;
			}
		}
		return ret;

	}
};

 struct ListNode
 {
    int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_getIntersectionNode {
public:
	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		ListNode* temp1 = headA;
		ListNode* temp2 = headB;
		int flag = 0;
		while (temp1 != temp2)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
			if (temp2 == NULL)
			{
				temp2 = headA;
				++flag;
			}
			if (temp1 == NULL)
				temp1 = headB;
			if (flag>1)
				return NULL;
		}
		return temp1;
	}
};
class Solution_lowestCommonAncestor {
public:
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return NULL;
		TreeNode* t1 = lowestCommonAncestor(root->left, p, q);
		TreeNode* t2 = lowestCommonAncestor(root->right, p, q);
		if (root == p || root == q)
			return root;

		if (t1 == NULL && t2 == NULL)
			return NULL;
		else if (t1&&t2)
			return root;
		else
			return t1 ? t1 : t2;
	}
};
class Solution_getSum {
public:
	int getSum(int a, int b) {
		while (b)
		{
			int temp = a ^ b;
			b = (unsigned int)(a&b) << 1;
			a = temp;
		}
		return a;
	}
};
class Solution_largestDivisibleSubset {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		vector<int> v(nums.size(), 0);
		if (nums.size() == 0)
		{
			v.clear();
			return v;
		}
		sort(nums.begin(), nums.end());
		int Max = 0;
		int index = 0;
		for (int i = 1; i<nums.size(); ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (nums[i] % nums[j] == 0)
					v[i] = max(v[i], v[j] + 1);
				if (v[i]>Max)
				{
					Max = v[i];
					index = i;
				}
			}
		}
		vector<int> ret;
		for (int i = index; i >= 0; --i)
		{
			if (nums[index] % nums[i] == 0 && v[i] == Max)
			{
				ret.push_back(nums[i]);
				index = i;
				--Max;
			}
		}
		return ret;
	}
};
class Solution_maxProduct {
public:
	int maxProduct(vector<int>& nums) {
		make_heap(nums.begin(), nums.end());
		int a = nums.front();
		pop_heap(nums.begin(), nums.end());
		int b = nums.front();
		return (a - 1)*(b - 1);
	}
};
int findNumberOfLIS(vector<int>& nums) {
	vector<int> v(nums.size(), 1);
	vector<int> ret(nums.size(), 1);
	int Max = 1;
	for (int i = 1; i<nums.size(); ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (nums[i]>nums[j])
			{
				if (v[i]<v[j] + 1)
				{
					v[i] = v[j] + 1;
					ret[i] = ret[j];
				}
				else if (v[i] == v[j] + 1)
				{
					ret[i] += ret[j];
				}
			}
		}
		Max = max(Max, v[i]);
	}
	int res = 0;
	for (int i = 0; i<nums.size(); ++i)
	{
		if (v[i] == Max)
			res += ret[i];
	}
	return res;
}
class Solution_alphabetBoardPath {
public:
	string alphabetBoardPath(string target) {
		string ret;
		int startx = 0;
		int starty = 0;
		int x = 0;
		int y = 0;
		for (int i = 0; i<target.size(); ++i)
		{
			x = (target[i] - 'a') % 5;
			y = (target[i] - 'a') / 5;
			int posx = x - startx;
			int posy = y - starty;
			if (y == 5)
			{
				while (posx<0)
				{
					ret += 'L';
					++posx;
				}
				while (posy>0)
				{
					ret += 'D';
					--posy;
				}
			}
			else
			{
				while (posy)
				{
					if (posy>0)
					{
						--posy;
						ret += 'D';
					}
					else
					{
						++posy;
						ret += 'U';
					}
				}
				while (posx)
				{
					if (posx>0)
					{
						--posx;
						ret += 'R';
					}
					else
					{
						++posx;
						ret += 'L';
					}
				}
			}
			ret += '!';
			startx = x;
			starty = y;
		}
		return ret;
	}
};
class Solution {
public:
	int subarraysDivByK(vector<int>& A, int K) {
		int sum = 0;
		unordered_map<int, int> mp = { { 0,1 } };
		int ret = 0;
		int num = 0;
		for (int i = 0; i<A.size(); ++i)
		{
			sum += A[i];
			num = (sum%K + K) % K;
			if (mp.count(num))
			{
				ret += mp[num];
			}
			++mp[num];
		}
		return ret;
	}
};
int longestStrChain(vector<string>& words) {
	vector<int> v(words.size(), 1);
	int Max = 1;
	map<string, int> mp;
	for (int i = 0; i<words.size(); ++i)
	{
		sort(words[i].begin(), words[i].end());
		mp[words[i]] = 1;
	}
	for (int i = 0; i<words.size(); ++i)
	{
		map<string, int>::iterator it = mp.find(words[i].substr(0, words[i].size()-1));
		if (it != mp.end())
		{
			mp[words[i]] = max(mp[words[i]], (*it).second + 1);
			Max = max(Max, mp[words[i]]);
		}
	}
	return Max;
}
class Solution_getFolderNames {
public:
	vector<string> getFolderNames(vector<string>& names) {
		map<string, int> mp;
		for (int i = 0; i<names.size(); ++i)
		{
			if (mp.count(names[i]))
			{
				int flag = ++mp[names[i]];
				string temp = names[i];
				while (mp.count(temp))
				{
					temp = names[i] + "(" + to_string(flag++) + ")";
				}
				names[i] = temp;
			}
			++mp[names[i]];
		}
		return names;
	}
};
class Solution_topKFrequent {
public:
	static bool cmp(pair<int, int>& p1, pair<int, int>& p2)
	{
		return p1.second>p2.second;
	}
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> mp;
		for (int i = 0; i<nums.size(); ++i)
		{
			++mp[nums[i]];
		}
		vector<pair<int, int>> res(mp.begin(), mp.end());
		sort(res.begin(), res.end(), cmp);
		vector<int> ret;
		for (int i = 0; i<k; ++i)
		{
			ret.push_back(res[i].first);
		}
		return ret;
	}
};
int main()
{
	vector<string> v = { "a", "b", "ba", "bca", "bda", "bdca" };
	string s = "z";
	cout << longestStrChain(v) << endl;
	//cout << alphabetBoardPath(s) << endl;
	//cout << findNumberOfLIS(v) << endl;
	//cout << lengthOfLongestSubstring("abccdefa") << endl;
	//vector<int> v = { 1,0,-1,0,-2,2 };
	//fourSum(v, 0);
	//cout << findMaxLength(v) << endl;
	//AVLTree<int> A;
	//for (int i = 0; i < 3; i++)
	//{
	//	A.AddNode(i);
	//}
	////cout << A.GetMAX() << endl;
	//cout << A.GetMAX() << endl;
	//A.RemoveMAX();
	//cout << A.GetMAX() << endl;
	
	//vector<vector<int>> A = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
	//cout<<minFallingPathSum(A)<<endl;
	//cout << KMP1("abcdabcdfabcdeabcd", "abcdfabcde") << endl;
	//cout << longestCommonSubsequence("abcde", "ace");
	//countSubstrings("aaa");
	//vector<int> v1 = { 1,2,3,4 };
	//vector<int> v2 = { 5,6,7,8 };
	//vector<vector<int>> v = { {0,1,1,1},{1,1,1,1},{0,1,1,1 } };
	//countSquares(v);
	//decompressRLElist(v1);
	//cout << numJewelsInStones("aA","aAAbbbb") << endl;
	//combinationSum2(v1, 8);
	//findContentChildren(v1, v2);
	system("pause");
	return 0;
}