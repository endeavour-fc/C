#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
int main()
{
	
	
	system("pause");
	return 0;
}