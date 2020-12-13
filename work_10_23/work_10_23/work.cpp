#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


 struct ListNode 
 {
     int val;
     struct ListNode *next;
};



bool isPalindrome(struct ListNode* head) {

	if (head == NULL)
		return true;
	if (head->next == NULL)
		return true;
	int flag = 0;
	struct ListNode* p1 = NULL;
	struct ListNode* p2 = head;
	struct ListNode* p3 = head->next;
	struct ListNode* pCur = head;
	struct ListNode* pPre = head;
	while (pPre != NULL && pPre->next != NULL)
	{
		pCur = pCur->next;
		pPre = pPre->next->next;
	}
	if (pPre == NULL)
		flag = 1;
	else
		flag = 0;

	//struct ListNode *prep, *nextp;
	//prep = nextp = NULL;
	while (p2 != pCur)
	{
		p3 = p2->next;
		//nextp = head->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	if (flag == 0)
	{
		pCur = pCur->next;
	}
	while (p2 != NULL && pCur != NULL)
	{
		if (p1->val != pCur->val)
			return false;
		p1 = p1->next;
		pCur = pCur->next;
	}
	return true;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int maxSumDivThree(vector<int>& nums) {
	vector<vector<int>> v(nums.size() + 1, vector<int>(3, 0));
	v[0][1] = v[0][2] = INT_MIN;
	for (int i = 1; i <= nums.size(); ++i)
	{
		if (nums[i - 1] % 3 == 0)
		{
			v[i][0] = max(v[i - 1][0] + nums[i - 1], v[i - 1][0]);
			v[i][1] = max(v[i - 1][1] + nums[i - 1], v[i - 1][1]);
			v[i][2] = max(v[i - 1][2] + nums[i - 1], v[i - 1][2]);
		}
		else if (nums[i - 1] % 3 == 1)
		{
			v[i][0] = max(v[i - 1][2] + nums[i - 1], v[i - 1][0]);
			v[i][1] = max(v[i - 1][0] + nums[i - 1], v[i - 1][1]);
			v[i][2] = max(v[i - 1][1] + nums[i - 1], v[i - 1][2]);
		}
		else
		{
			v[i][0] = max(v[i - 1][1] + nums[i - 1], v[i - 1][0]);
			v[i][1] = max(v[i - 1][2] + nums[i - 1], v[i - 1][1]);
			v[i][2] = max(v[i - 1][0] + nums[i - 1], v[i - 1][2]);
		}
	}
	return v[nums.size()][0];
}

int main()
{
	vector<int> v = { 3,6,5,1,8 };
	cout << maxSumDivThree(v) << endl;

	system("pause");
	return 0;
}