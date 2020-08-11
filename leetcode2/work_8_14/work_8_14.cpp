#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};
int main01()
{
	int m = 0;
	srand((unsigned)time(NULL));
	int key = rand() % 100;
	while (1)
	{
		printf("请输入你所猜的数\n");
		scanf("%d", &m);
		if (m > key)
			printf("猜大了\n");
		else if(m<key)
			printf("猜小了\n");
		else
		{
			printf("猜对了\n");
			break;
		}

	}
	
	system("pause");
	return 0;
}


int main02()
{
	int key = 0;
	int a[20] = { 0 };
	int right = 19;
	int left = 0;
	int mid = 0;
	printf("请输入一个要查找的数\n");
	scanf("%d", &key);
	for (int i = 0; i<20; i++)
		a[i] = i;
	while (right >= left)
	{
		mid = (right + left) / 2;
		if (a[mid] > key)
			right = mid - 1;
		else if (a[mid] < key)
			left = mid + 1;
		else if(a[mid]==key)
		{
			printf("找到了%d\n", mid);
			break;
		}
	}
	if (left > right)
		printf("没找到\n");

	system("pause");
	return 0;
}


int main03()
{
	char a[] = "asdfg";
	char b[20] = { 0 };
	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		printf("请输入密码\n");
		scanf("%s", b);
		if (strcmp(b, a) == 0)
		{
			printf("输入正确\n");
			break;
		}
		printf("输入错误");
		j++;
	}
	if (j == 3)
		printf("关闭程序\n");

	system("pause");
	return 0;
}


int main04()
{
	char ms = 0;
	for (int i = 0; i < 50; i++)
	{
		ms = getchar();
		if (ms >= 65 && ms <= 90)
		{
			ms = ms + 32;
			printf("%c", ms);
		}
		else if (ms >= 97 && ms <= 122)
		{
			ms = ms - 32;
			printf("%c", ms);
		}
	}

	system("pause");
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
int cuttingRope(int n) {
	if (n<3)
		return 1;
	if (n == 3)
		return 2;
	vector<int> v(n + 1, 0);
	v[1] = 1;
	v[2] = 2;
	v[3] = 3;
	for (int i = 4; i<=n; ++i)
	{
		for (int j = i / 2; j > 0; --j)
		{
			v[i] = max(v[i - j] * v[j], v[i]);
		}
	}
	return v[n];
}
int cuttingRope2(int n) {
	if (n<3)
		return 1;
	if (n == 3)
		return 2;
	long ret = 1;
	while (n>4)
	{
		ret *= 3;
		ret %= 1000000007;
		n -= 3;
	}
	return ret * n % 1000000007;
}
class Solution_isBalanced {
public:
	int get(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int num1 = get(root->left);
		int num2 = get(root->right);
		return num1>num2 ? num1 + 1 : num2 + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		if (abs(get(root->left) - get(root->right))>1)
		{
			return false;
		}
		return isBalanced(root->left) && isBalanced(root->right);
	}
};
class Solution_shortestPathBinaryMatrix {
public:
	int next[8][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 },{ 1,1 },{ -1,1 },{ 1,-1 },{ -1,-1 } };
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		if (grid[0][0] || grid[grid.size() - 1][grid[0].size() - 1])
			return -1;
		queue<pair<int, int>> que;
		int ret = 1;
		que.push({ 0,0 });
		while (!que.empty())
		{
			int size = que.size();
			while (size--)
			{
				auto e = que.front();
				int i = e.first;
				int j = e.second;
				que.pop();
				if (i == grid.size() - 1 && j == grid[0].size() - 1)
					return ret;
				for (int k = 0; k<8; ++k)
				{
					int m_i = i + next[k][0];
					int m_j = j + next[k][1];
					if (m_i >= 0 && m_i<grid.size() && m_j >= 0 && m_j<grid[0].size() && grid[m_i][m_j] == 0)
					{
						que.push({ m_i,m_j });
						grid[m_i][m_j] = 3;
					}
				}
			}
			++ret;
		}
		return -1;
	}
};
class Solution_uniqueOccurrences {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		map<int, int> mp;
		set<int> st;
		for (int i = 0; i<arr.size(); ++i)
		{
			++mp[arr[i]];
		}
		for (auto& e : mp)
		{
			if (st.count(e.second))
				return false;
			else
				st.insert(e.second);
		}
		return true;
	}
};
class Solution_solve {
public:
	void dfs(vector<vector<char>>& board, int i, int j)
	{
		if (i<0 || j<0 || i >= board.size() || j >= board[0].size())
			return;
		if (board[i][j] == 'O')
			board[i][j] = '#';
		else
			return;
		dfs(board, i + 1, j);
		dfs(board, i, j + 1);
		dfs(board, i - 1, j);
		dfs(board, i, j - 1);
	}
	void solve(vector<vector<char>>& board) {

		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				if ((i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1) && board[i][j] == 'O')
					dfs(board, i, j);
			}
		}
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				if (board[i][j] == '#')
					board[i][j] = 'O';
				else if (board[i][j] == 'O')
					board[i][j] = 'X';

			}
		}
	}
};
class Solution_flatten {
public:
	void flatten(TreeNode* root) {
		if (root == NULL)
			return;
		TreeNode* head = new TreeNode;
		TreeNode* temp = head;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			head->right = st.top();
			head->left = NULL;
			st.pop();
			head = head->right;
			if (head->right)
				st.push(head->right);
			if (head->left)
				st.push(head->left);
		}
		head->left = NULL;
		delete temp;
	}
};
class Solution_findPaths {
public:
	int arr[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
	int findPaths(int m, int n, int N, int i, int j) {
		vector<vector<vector<int>>> v(N + 1, (vector<vector<int>>(m, vector<int>(n, 0))));
		for (int k = 1; k <= N; ++k)
		{
			for (int ki = 0; ki<m; ++ki)
			{
				for (int kj = 0; kj<n; ++kj)
				{
					for (int c = 0; c<4; ++c)
					{
						int m_i = ki + arr[c][0];
						int m_j = kj + arr[c][1];
						if (m_i<0 || m_j<0 || m_j >= n || m_i >= m)
							++v[k][ki][kj];
						else
							v[k][ki][kj] = (v[k - 1][m_i][m_j] + v[k][ki][kj]) % 1000000007;
					}
				}
			}
		}
		return v[N][i][j];
	}
};

class Solution_minCut {
public:
	int minCut(string s) {
		vector<int> v;
		for (int i = 0; i<s.size() + 1; ++i)
		{
			v.push_back(i - 1);
		}
		for (int i = 1; i<s.size() + 1; ++i)
		{
			for (int j = 0; j<i; ++j)
			{
				if (get(s, j, i - 1))
				{
					v[i] = min(v[i], v[j] + 1);
				}
			}
		}
		return v[s.size()];
	}
	bool get(string& s, int start, int end)
	{
		while (start<end)
		{
			if (s[start++] != s[end--])
				return false;
		}
		return true;
	}
};


class Solution_maxDistance {
public:
	int arr[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
	int maxDistance(vector<vector<int>>& grid) {
		queue<pair<int, int>> que;
		for (int i = 0; i<grid.size(); ++i)
		{
			for (int j = 0; j<grid[0].size(); ++j)
			{
				if (grid[i][j] == 1)
					que.push({ i,j });
			}
		}
		int ret = 0;
		int flag = 0;
		pair<int, int> temp;
		while (!que.empty())
		{
			temp = que.front();
			que.pop();
			//auto[i, j] = temp;
			int i = temp.first;
			int j = temp.second;
			for (int k = 0; k<4; ++k)
			{
				int _i = i + arr[k][0];
				int _j = j + arr[k][1];
				if (_i<0 || _i >= grid.size() || _j<0 || _j >= grid[0].size() || grid[_i][_j])
					continue;
				grid[_i][_j] = grid[i][j] + 1;
				que.push({ _i,_j });
				flag = 1;
			}
		}
		if (flag == 0)
			return -1;
		return grid[temp.first][temp.second];
	}
};
class Solution_minDistance {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> v(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i <= word1.size(); ++i)
			v[i][0] = i;
		for (int i = 0; i <= word2.size(); ++i)
			v[0][i] = i;

		for (int i = 1; i <= word1.size(); ++i)
		{
			for (int j = 1; j <= word2.size(); ++j)
			{
				v[i][j] = min(v[i - 1][j - 1], min(v[i][j - 1], v[i - 1][j])) + 1;
				if (word1[i - 1] == word2[j - 1])
					v[i][j] = min(v[i][j], v[i - 1][j - 1]);
			}
		}
		return v[word1.size()][word2.size()];
	}
};
class Solution_numIslands {
public:
	int arr[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

	int get(vector<vector<char>>& grid, int i, int j)
	{
		++grid[i][j];
		for (int k = 0; k<4; ++k)
		{
			int m_i = i + arr[k][0];
			int m_j = j + arr[k][1];
			if (m_i<0 || m_j<0 || m_i >= grid.size() || m_j >= grid[0].size() || grid[m_i][m_j] != '1')
				continue;

			get(grid, m_i, m_j);
		}
		return 1;
	}

	int numIslands(vector<vector<char>>& grid) {
		//stack<pair<int,int>> sta;
		int ret = 0;
		for (int i = 0; i<grid.size(); ++i)
		{
			for (int j = 0; j<grid[0].size(); ++j)
			{
				if (grid[i][j] == '1')
					ret += get(grid, i, j);
				//sta.push({i,j});

			}
		}
		/*   int ret=0;
		while(!sta.empty())
		{
		auto[i,j]=sta.top();
		sta.pop();
		if(grid[i][j]!='1')
		continue;
		ret+=get(grid,i,j);

		}*/
		return ret;
	}
};
class Solution_spiralOrder {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
		{
			vector<int> v;
			return v;
		}
		vector<int> v(matrix.size()*matrix[0].size(), 0);
		int index = 0;
		int right = matrix[0].size() - 1;
		int left = 0;
		int front = 0;
		int back = matrix.size() - 1;

		while (left <= right && front <= back)
		{
			for (int col = left; col <= right; ++col)
				v[index++] = matrix[front][col];
			for (int row = front + 1; row <= back; ++row)
				v[index++] = matrix[row][right];

			if (left<right&&front<back)
			{
				for (int col = right - 1; col >= left; --col)
					v[index++] = matrix[back][col];
				for (int row = back - 1; row>front; --row)
					v[index++] = matrix[row][left];
			}
			++left;
			--right;
			++front;
			--back;
		}
		return v;

	}
};
class Solution_rotate {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size() - 1;
		for (int i = 0; i <= n / 2; ++i)
		{
			for (int j = i; j<n - i; ++j)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[n - j][i];
				matrix[n - j][i] = matrix[n - i][n - j];
				matrix[n - i][n - j] = matrix[j][n - i];
				matrix[j][n - i] = temp;
			}
		}
	}
};

int main()
{
	vector<vector<int>> v = { {1, 0, 1},{0, 0, 0},{1, 0, 1 } };
	//cout << Solution_maxDistance::maxDistance(v) << endl;

	system("pause");
	return 0;
}