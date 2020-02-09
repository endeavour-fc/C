#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	ListNode* next;
};
ListNode* Init_Node()
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->val = 0;
	temp->next = NULL;
	return temp;
}
ListNode* CreatNode(int a)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->val = a;
	temp->next = NULL;
	return temp;
}
void Insert_Head_List(ListNode* head, ListNode* inhl)
{
	if (head == NULL || inhl == NULL)
		return;
	inhl->next = head->next;
	head->next = inhl;
}
void Print_Node(ListNode* head)
{
	if (head == NULL)
		return;
	for (ListNode* temp = head->next; temp != NULL; temp = temp->next)
		printf("%d->", temp->val);
	printf("\n");
}
void test1(int* arr1, int len1,int* arr2,int len2)
{
	ListNode* head1 = Init_Node();
	ListNode* head2 = Init_Node();
	for (int i = 0; i < len1; i++)
	{
		ListNode* temp = CreatNode(arr1[i]);
		Insert_Head_List(head1, temp);
	}
	Print_Node(head1);
	for (int i = 0; i < len2; i++)
	{
		ListNode* temp = CreatNode(arr2[i]);
		Insert_Head_List(head2, temp);
	}
	Print_Node(head2);
	head1 = head1->next;
	head2 = head2->next;
	while (head1 != NULL && head2 != NULL)
	{
		if (head1->val == head2->val)
		{
			printf("%d->", head1->val);
			head1 = head1->next;
			head2 = head2->next;
		}
		else if(head1->val<head2->val)
		{
			head2 = head2->next;
		}
		else
		{
			head1 = head1->next;
		}
	}
}
void test3(ListNode* head, int k);
void test2(int* arr,int len,int k)
{
	ListNode* head = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	test3(head, k);
	/*
	Print_Node(head);
	if (k > len)
		return;
	ListNode* pCur = head;
	ListNode* pPre = head->next;
	k = len - k;
	while (k >0)
	{
		pCur = pCur->next;
		pPre = pPre->next;
		k--;
	}
	pCur->next = pPre->next;
	free(pPre);
	pPre = NULL;
	Print_Node(head);*/
}
void test5(ListNode** head);

void test4(int* arr, int len, int* arr2, int len2)
{
	ListNode* head = Init_Node();
	ListNode* head2 = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	for (int i = 0; i < len2; i++)
	{
		ListNode* temp = CreatNode(arr2[i]);
		Insert_Head_List(head2, temp);
	}
	if (head->next == NULL)
		return;
	Print_Node(head);
	Print_Node(head2);
	test5(&head);
	test5(&head2);
	ListNode* pPre = head->next;
	ListNode* pCur = head2->next;
	int k = 0;
	while (pPre != NULL && pCur != NULL)
	{
		int temp = pPre->val + pCur->val;
		
		if (temp+k >= 10)
			k = 1;
		pCur->val=pPre->val = (temp + k) % 10;
		if (pPre->next == NULL || pCur->next == NULL)
		{
			if (k)
			{
				break;
			}
		}
		k = 0;
		pPre = pPre->next;
		pCur = pCur->next;
	}
	test5(&head);
	test5(&head2);
	if (k&&pPre->next==NULL&&pCur->next==NULL)
	{
		ListNode* temp = CreatNode(1);
		Insert_Head_List(head, temp);
	}
	else if (k&&pPre->next == NULL)
	{
		pCur->next->val++;
	}
	else if (k&&pCur->next == NULL)
	{
		pPre->next->val++;
	}

	//ListNode* pCur = head;
	//ListNode* pPre = head->next->next;
	//if (pPre == NULL)
	//{
	//	Print_Node(head);
	//	return;
	//}
	//while (pPre != NULL)
	//{
	//	if (pPre->next == NULL)
	//		break;
	//	pPre = pPre->next->next;
	//	pCur = pCur->next;

	//}
	//pCur->next = pCur->next->next;
	Print_Node(head);
	Print_Node(head2);

}
void test5(ListNode** head)
{
	if ((*head)->next == NULL || (*head)->next->next == NULL)
	{
		Print_Node(*head);
		return;
	}
	ListNode* pPre = (*head)->next;
	ListNode* pCur = (*head)->next;
	ListNode* temp = NULL;
	while (pPre != NULL)
	{
		pPre = pPre->next;
		pCur->next = temp;
		if (pPre == NULL)
			break;
		temp = pCur;
		pCur = pPre;
	}
	(*head)->next = pCur;
	Print_Node(*head);
}

void test3(ListNode* head, int k)
{
	Print_Node(head);
	ListNode* pCur = head;
	ListNode* pPre = head;
	while (k >0)
	{
		pPre = pPre->next;
		if (pPre == NULL)
		{
			Print_Node(head);
			return;
		}
		k--;
	}
	while (pPre->next != NULL)
	{
		pCur = pCur->next;
		pPre = pPre->next;
	}
	ListNode* temp = pCur->next;
	pCur->next = pCur->next->next;
	free(temp);
	temp = NULL;
	Print_Node(head);
}
void test6(int* arr, int len, int k)
{
	ListNode* head = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	Print_Node(head);
	if (head->next == NULL)
		return;
	ListNode* pCur = head->next;
	while (pCur->next != NULL)
	{
		ListNode* pPre = pCur;
		int i = 0;
		while (pPre->next != NULL)
		{
			if (i++ == 2)
			{
				ListNode* temp = pPre->next;
				pPre->next = pPre->next->next;
				free(temp);
			}
			pPre = pPre->next;
		}
	}
	Print_Node(head);
}
void resign(ListNode* left, ListNode* start, ListNode* end, ListNode* right);

void test7(int* arr, int len, int k)
{
	ListNode* head = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	Print_Node(head);
	if (k < 2)
		return;
	ListNode* pPre = head->next;
	ListNode* pCur = NULL;
	ListNode* temp = NULL;
	ListNode* next = NULL;
	int count = 1;
	while (pPre != NULL)
	{
		next = pPre->next;
		if (count == k)
		{
			pCur = temp == NULL ? head->next : temp->next;
			head->next = temp == NULL ? pPre : head->next;
			resign(temp, pCur, pPre, next);
			temp = pCur;
			count = 0;
		}
		count++;
		pPre = next;
	}
	Print_Node(head);
}
void resign(ListNode* left, ListNode* start, ListNode* end, ListNode* right)
{
	ListNode* pPre = start;
	ListNode* pCur = start->next;
	ListNode* temp = NULL;
	while (pPre != end)
	{
		temp = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = temp;
	}
	if (left != NULL)
	{
		left->next = end;
	}
	start->next = right;
}

void test8(int* arr, int len, int k)
{
	ListNode* head = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	Print_Node(head);
	ListNode* pPre = head;
	ListNode* pCur = head->next;
	ListNode* temp = pCur->next;
	while (pPre->next != NULL)
	{
		while (temp != NULL)
		{
			if (pPre->next->val > temp->val)
			{
				pCur->next = temp->next;
				temp->next = pPre->next;
				pPre->next = temp;
				temp = pCur->next;
			}
			else
			{
				pCur = pCur->next;
				temp = temp->next;
			}
		}
		pPre = pPre->next;
		pCur = pPre;
		temp = pPre->next;
	}
	Print_Node(head);
	pPre = head->next;
	pCur = pPre->next;
	while (pCur != NULL)
	{
		if (pPre->val == pCur->val)
		{
			pPre->next = pCur->next;
			pCur = pPre->next;
		}
		else
		{
			pPre = pPre->next;
			pCur = pCur->next;
		}
	}
	Print_Node(head);
}
void test9(int* arr, int len, int k)
{
	ListNode* head = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	Print_Node(head);
	ListNode* pPre = head;
	ListNode* pCur = head->next;
	while (pCur != NULL)
	{
		if (pCur->val == k)
		{
			pPre->next = pCur->next;
			pCur = pPre->next;
		}
		else
		{
			pPre = pPre->next;
			pCur = pCur->next;
		}
	}
	Print_Node(head);

}
ListNode* GetMinNode(ListNode* head);
void test10(int* arr, int len)
{
	ListNode* head = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	Print_Node(head);
	ListNode* tail = NULL;
	ListNode* smallPre = NULL;
	ListNode* small = NULL;
	ListNode* pPre = head->next;
	while (pPre != NULL)
	{
		small = pPre;
		smallPre = GetMinNode(pPre);
		if (smallPre != NULL)
		{
			small = smallPre->next;
			smallPre->next = small->next;
		}
		pPre = pPre == small ? pPre->next : pPre;
		if (tail == NULL)
		{
			head->next = small;
		}
		else
		{
			tail->next = small;
		}
		tail = small;
	}
	Print_Node(head);
}
ListNode* GetMinNode(ListNode* head)
{
	ListNode* smallPre = NULL;
	ListNode* small = head;
	ListNode* pPre = head;
	ListNode* pCur = head->next;
	while (pCur != NULL)
	{
		if (pCur->val < small->val)
		{
			smallPre = pPre;
			small = pCur;
		}
		pPre = pCur;
		pCur = pCur->next;
	}
	return smallPre;
}

void RemoveNodeWire(ListNode* Node)
{
	if (Node == NULL&&Node->next==NULL)
		return;
	Node->val = Node->next->val;
	Node->next = Node->next->next;
}
void test11(int* arr1, int len1, int* arr2, int len2)
{
	ListNode* head1 = Init_Node();
	ListNode* head2 = Init_Node();
	for (int i = 0; i < len1; i++)
	{
		ListNode* temp = CreatNode(arr1[i]);
		Insert_Head_List(head1, temp);
	}
	Print_Node(head1);
	for (int i = 0; i < len2; i++)
	{
		ListNode* temp = CreatNode(arr2[i]);
		Insert_Head_List(head2, temp);
	}
	Print_Node(head2);
	ListNode* head = Init_Node();
	ListNode* pPre = head1->next;
	ListNode* pCur = head2->next;
	ListNode* next = head;
	while (pPre != NULL && pCur != NULL)
	{
		if (pPre->val < pCur->val)
		{
			next->next = pCur;
			pCur = pCur->next;
		}
		else
		{
			next->next = pPre;
			pPre = pPre->next;
		}
		next = next->next;
	}
	while (pPre)
	{
		next->next = pPre;
		pPre = pPre->next;
	}
	while (pCur)
	{
		next->next = pCur;
		pCur = pCur->next;
	}
	Print_Node(head);
}
void test12(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int begin, end = 0;
	for (int i = 0; i < len-1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			begin = i;
			break;
		}
	}
	for (int i = begin; i < len - 1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			end = i;
			break;
		}
	}
	while (begin < end)
	{
		int temp = arr[begin];
		arr[begin] = arr[end];
		arr[end] = temp;
		end--;
		begin++;
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}
void rotate(int* nums, int numsSize, int k) {
	if (nums == NULL)
		return;
	for (int i = 0; i<k; i++)
	{
		int temp = nums[numsSize - 1];
		for (int j = numsSize - 1; j>0; j--)
		{
			nums[j] = nums[j - 1];
		}
		nums[0] = temp;
	}

}
int searchInsert(int* nums, int numsSize, int target)
{

	if (nums[numsSize - 1]<target)
		return numsSize;
	if (nums[0]>target)
		return 0;
	int right = numsSize - 1;
	int left = 0;
	int mid = 0;
	while (right >= left)
	{
		mid = (right + left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid]>target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	for (int i = 0; i<numsSize; i++)
		if (nums[i]>target)
			return i - 1;
}
int lengthOfLastWord(char * s) {
	if (*s == '\0')
		return 0;
	char* pPre = s;
	int j = 0;
	while (*pPre != '\0')
	{
		j++;
		pPre++;
	}
	pPre--;
	while (*pPre == ' ')
	{
		if (j <= 1)
			return 0;
		pPre--;
		j--;
	}
	int i = 0;
	while (*pPre != ' ')
	{
		pPre--;
		i++;
	}
	return i;
}
void sort(int* arr, int len)
{
	int* temp = (int*)malloc(sizeof(int)*len);
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < len; i++)
	{
		if (arr[i] >= 0)
			break;
	}
	if (i != 0)
	{
		j = i - 1;
		while (i < len || j >= 0)
		{
			if (arr[i] > -arr[j])
			{
				temp[k++] = arr[j--];
			}
			else
			{
				temp[k++] = arr[i++];
			}
		}
		for (i = 0; i < len; i++)
		{
			arr[i] = temp[i];
		}
	}
	for (i = 0; i < len; i++)
	{
		arr[i] = arr[i] * arr[i];
	}
	
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

	int* temp = (int*)malloc(sizeof(int)*(m + n));
	int n1 = 0;
	int n2 = 0;
	int i = 0;
	while (n1<m&&n2<n)
	{
		if (nums1[n1]<nums2[n2])
		{
			temp[i++] = nums1[n1++];
		}
		else
		{
			temp[i++] = nums2[n2++];
		}
	}
	while (n1<m)
		temp[i++] = nums1[n1++];
	while (n2<n)
		temp[i++] = nums2[n2++];
	for (int i = 0; i<m + n; i++)
		nums1[i] = temp[i];
}
int main()
{
	char str[] = " ";
	printf("%d", lengthOfLastWord(str));
	//int arr1[] = {1,2,5,4,3,6,7,8,9};
	//int len1 = sizeof(arr1) / sizeof(arr1[0]);

	//int arr2[] = { 1,2,3,4,5,6,7 };
	//int len2 = sizeof(arr2) / sizeof(arr2[0]);
	//rotate(arr2, len2, 3);
	//for (int i = 0; i < len2; i++)
	//{
	//	printf("%d ", arr2[i]);
	//}
	//test12(arr1, len1);
	//test11(arr1, len1,arr2,len2);
	//int arr2[] = {9};
	//int len2 = sizeof(arr2) / sizeof(arr2[0]);
	//test1(arr1, len1,arr2,len2);
	//test10(arr1, len1);
	
	system("pause");
	return 0;
}