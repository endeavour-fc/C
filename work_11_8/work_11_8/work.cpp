#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;
typedef struct ListNode
{
	struct TreeNode* Node;
	struct ListNode* next;
}ListNode;
ListNode* Init_List()
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->next = NULL;
	return temp;
}
void Push_Stack(ListNode* head, struct TreeNode* Node)
{
	ListNode* pPre = head->next;
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->Node = Node;
	head->next = temp;
	temp->next = pPre;
}
bool empty_stack(ListNode* head)
{
	return head->next == NULL ? true : false;
}
 TreeNode* Pop_stack(ListNode* head)
{
	if (empty_stack(head))
		return NULL;
	struct TreeNode* pPre = head->next->Node;
	head->next = head->next->next;
	return pPre;
}


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	if (root == NULL)
		return NULL;
	ListNode*temp = Init_List();
	struct TreeNode* p = NULL;
	Push_Stack(temp, root);
	while (!empty_stack(temp))
	{
		p = Pop_stack(temp);
		scanf("%d", p->val);
		if (p->left != NULL)
			Push_Stack(temp, p->left);
		if (p->right != NULL)
			Push_Stack(temp, p->right);
	}

}
int main()
{
	
	
	system("pause");
	return 0;
}