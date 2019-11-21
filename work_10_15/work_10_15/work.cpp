#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 struct ListNode {
	int val;
	struct ListNode *next;
	
};
 struct ListNode* removeElements(struct ListNode* head, int val)
 {
	 if (head == NULL)
		 return NULL;
	 struct ListNode* temp = head;
	 struct ListNode* pCur = temp->next;
	 while (temp != NULL)
	 {
		 if (head->val == val)
		 {
			 head = head->next;
			 temp = head;
			 if (head == NULL)
				 return NULL;
			 pCur = temp->next;
			 continue;
		 }
		 else if (pCur != NULL && pCur->val == val)
		 {
			 temp->next = pCur->next;
			 pCur = pCur->next;
			 continue;
		 }
		 if (pCur == NULL)
			 return head;
		 temp = temp->next;
		 pCur = temp->next;
	 }
	 return head;
 }

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL && l2 == NULL)
		return NULL;
	else if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;
	struct ListNode* temp = l1;
	struct ListNode* k = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = l2;
	for (temp = l1; temp->next != NULL; temp = temp->next)
	{
		for (k = temp->next; k != NULL; k = k->next)
		{
			if (temp->val>k->val)
			{
				int num = temp->val;
				temp->val = k->val;
				k->val = num;
			}
		}
	}
	return l1;
}

struct ListNode* middleNode(struct ListNode* head) {
	if (head == NULL)
		return NULL;
	struct ListNode* pCur = head;
	struct ListNode* pPre = head;
	while (pPre != NULL)
	{
		if (pPre->next == NULL)
			return pCur;
		pCur = pCur->next;

		pPre = pPre->next->next;
	}
	return pCur;
}

struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* pCur = head;
	struct ListNode* pPre = head->next;
	struct ListNode* temp = pPre->next;
	struct ListNode* k = NULL;
	int flag = 0;
	pPre->next = pCur;
	pCur->next = temp;
	head = pPre;

	if (temp == NULL)
		return head;
	temp = pCur;
	pCur = pCur->next;
	pPre = pCur->next;

	while (pPre != NULL)
	{
		k = pPre->next;
		temp->next = pPre;
		pPre->next = pCur;
		pCur->next = k;

		temp = pCur;
		if (k == NULL)
			return head;
		pCur = k;
		pPre = k->next;

	}
	return head;
}

int main()
{
	
	
	system("pause");
	return 0;
}