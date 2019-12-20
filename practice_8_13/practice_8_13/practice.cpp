#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<Windows.h>
//int main()
//{
//	int i, j, a = 0;
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (j % 2)
//				break;
//			a++;
//		}
//		a++;
//	}
//	printf("%d\n", a);
//	system("pause");
//	return 0;
//}

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

	struct ListNode* pPre = head;
	struct ListNode* temp = NULL;
	struct ListNode* pCur = head;
	if (head == NULL || n <= 0 || head->next == NULL)
		return NULL;
	while (n-->0 && pPre != NULL)
		pPre = pPre->next;
	if (pPre == NULL)
		return head->next;
	while (pPre->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	temp = pCur->next;
	pCur->next = pCur->next->next;
	free(temp);
	return head;

}
int repeatedNTimes(int* A, int ASize) {

	for (int i = 1; i<4; i++)
	{
		for (int j = 0; j<ASize - i; j++)
		{
			if (A[j] == A[j + i])
				return A[j];
		}
	}
	return A[0];
}
void reverseString(char* s, int sSize)
{
	char* p1 = s;
	char* p2 = s + sSize - 1;
	while (p1<p2)
	{
		if (*p1 != *p2)
		{
			char temp = *p1;
			*p1 = *p2;
			*p2 = temp;
		}
		p1++;
		p2--;
	}
}
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	*returnSize = 0;
	int* arr = (int*)malloc(sizeof(int)*numsSize);
	for (int i = 0; i<numsSize - 1; i++)
	{
		for (int j = i + 1; j<numsSize; j++)
		{
			if ((nums[i] + nums[j]) == target)
			{
				arr[0] = i;
				arr[1] = j;
				*returnSize = 2;
				return arr;
			}
		}
	}
	return arr;
}
//int lengthOfLastWord(const char * s) {
//	if (s == NULL)
//		return 0;
//	int count = 0;
//	const char* p = s;
//	if (s == " ")
//		return 0;
//	while ((*p) != '\0')
//	{
//		
//		if ((*p) == ' ')
//		{
//			const char* temp = p;
//			while (*temp == ' ')
//				temp++;
//			if (*temp != '\0')
//				count = 0;
//			else
//				break;
//		}
//		count++;
//		p++;
//	}
//	return count;
//
//}
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	if (headB == NULL || headA == NULL)
		return NULL;
	struct ListNode* p1 = headA;
	struct ListNode* p2 = headB;
	while (p1 != p2)
	{
		if (p1 == NULL)
		{
			p1 = headB;
		}
		else if (p2 == NULL)
		{
			p2 = headA;
		}
		else
		{
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	return p1;
}

ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	ListNode* pre = (ListNode*)malloc(sizeof(ListNode));
	pre->next = pHead;

	ListNode* p = pre, *q = pHead;//p永远指向前一个正确，q为新接入的节点，并未判断
	while (q != NULL)
	{
		int flag = 0;
		while (q->val == q->next->val && q->next != NULL)
		{
			q = q->next;
			flag++;
		}
		if (flag)
			p->next = q->next;//如果重复，直接跳掉q值相同的一排
		else
			p = q;
		q = q->next;
	}
	return pre->next;
}

int* sortArrayByParity(int* A, int ASize, int* returnSize) {
	int end = ASize - 1;
	int begin = 0;
	returnSize = (int*)malloc(sizeof(int)*ASize);
	for (int i = 0; i<ASize; i++)
	{
		if (A[i] % 2 == 0)
		{
			returnSize[begin] = A[i];
			begin++;
		}
		else
		{
			returnSize[end] = A[i];
			end--;
		}
	}
	return returnSize;
}


int searchInsert(int* nums, int numsSize, int target) {

	if (nums == NULL)
		return 0;
	int start = 0;
	int end = numsSize;
	int flag = 0;
//	int temp = target;
	while (end>start)
	{
		int middle = (start + end) / 2;
		if (nums[middle] == target)
		{
			return middle;
		}
		else if (middle>target)
			end = middle - 1;
		else
			start = middle + 1;
	}
	//nums[numsSize] = target;
	for (int i = numsSize - 1; i >= 0; i--)
	{
		if (nums[i]>target)
		{
			int temp = nums[i];
			nums[i] = temp;
			temp = temp;
			flag = i;
		}
	}

	return flag;
}


bool checkPerfectNumber(int num) {

	if (num == 0||num==6)
		return true;
	int flag = 0;
	int temp = num;
	int sum = 1;
	while (temp % 2 == 0 && temp != 0)
	{
		temp /= 2;
		sum += temp;
		flag++;
	}
	if (flag&&temp != 0)
		sum += 2;
	sum = sum + flag * 2;

	temp = num;
	flag = 0;

	while (temp % 3 == 0)
	{
		temp /= 3;
		sum += temp;
		flag++;
	}
	if (flag&&temp != 0)
		sum += 3;
	sum = sum + flag * 3;
	if (sum == num)
		return true;
	else
		return false;
}
void sort(int* p, int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for (i = 1; i<len; i++)
	{
		temp = p[i];
		if (p[i - 1]>p[i])
		{
			for (j = i - 1; j<len&&p[j]>temp; j--)
			{
				p[j + 1] = p[j];
			}
			p[j + 1] = temp;
		}
	}
}


void sort2(int* p, int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int srt = 0;
	for (srt = len / 2; srt>0; srt /= 2)
	{
		for (i = srt; i<len; i++)
		{
			temp = p[i];
			for (j = i - srt; j<len&&p[j]>temp; j -= srt)
				p[j + srt] = p[j];
			p[j + srt] = temp;
		}
	}

}


bool isValid(char * s) {
	if (s == NULL)
		return false;
	if (*s == '\0')
		return true;
	int len = 0;
	len = strlen(s);
	char* p = (char*)malloc(sizeof(char)*len);
	int top = 0;
	while (*s != '\0')
	{
		if (*s == '[' || *s == '(' || *s == '{')
		{
			p[top++] = *s;
		}
		else
		{
			if (top == 0)
				return false;
			if (p[top - 1] == '['&&*s == ']' || p[top - 1] == '{'&&*s == '}' || p[top - 1] == '('&&*s == ')')
				top--;
			else
				return false;
		}
		s++;
	}

	if (top == 0)
		return true;
	return false;
}

bool hasCycle(struct ListNode *head) {
	struct ListNode* pCur = head;
	struct ListNode* pPre = head;

	while (pPre != NULL)
	{
		pCur = pCur->next;
		if (pCur == NULL || pPre->next == NULL)
			return false;
		pPre = pPre->next->next;
		if (pCur == pPre)
			return true;
	}
	return false;
}
int taddOK(int, int);


//void main() {
//	int x, y;
//
//
//	printf("Input two integers:\n");
//	scanf("%d %d", &x, &y);
//
//
//	printf("%d\n", taddOK(x, y));
//
//}


/*Determine whether arguments can be added without overflow */
int taddOK(int x, int y) {
	int sum = x + y;


	if (x < 0 && y < 0 && sum >= 0)
		printf("负溢出");
	else if (x >= 0 && y >= 0 && sum <= 0)
		printf("正溢出");
	else 
		printf("没有溢出\n");
	return sum;
}



//int main()
//{
//
//
//	/*int arr[] = { 1,3,5,6 };
//	int len = 4;*/
////	printf("%d\n", checkPerfectNumber(6));
//	/*int a = 10;
//	a += a *= a -= a / 3;
//	printf("%d", a);*/
//	/*char a[20];
//	char *p1 = (char*)a;
//	char *p2 = (char*)(a + 5);
//	int n = p2 - p1;
//	printf("%d", n);*/
//	///*printf("%d\n", lengthOfLastWord("adds           "));*/
//	//int arr[4] = { 2,1,3,4 };
//	//int *p = NULL;
//	//int *temp = sortArrayByParity(arr, 4, p);
//	//for (int i = 0; i < 4; i++)
//	//	printf("%d", temp[i]);
//
//	//free(p);
//	//p = NULL;
//
//	/*	int i = 0;
//		char baf[101] = { 0 };
//		char* p = &baf[100];
//		memset(baf, '0', 100);
//		for (i = 1; i <= 100; i++)
//		{
//			printf("[%-10s ] %d\r", p, i);
//			fflush(stdout);
//			Sleep(1);
//			p--;
//		}
//*/
//	/*int i = 0;
//	int arr[] = { 2,4,1,3,5,6,8,7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	sort2(arr, len);
//	for (i = 0; i<len; i++)
//	{
//		printf("%d ", arr[i]);
//	}*/
//	//char p[] = "(])";
//	//printf("%d", isValid(p));
//	char arr[3] = { 0 };
//	while (1)
//	{
//		arr[1]++;
//		if (arr[2] || arr[0])
//			break;
//	}
//
//	system("pause");
//	return 0;
//}



//ListNode* partition(ListNode* pHead, int x)
//{
//	// write code here
//	if (pHead == NULL)
//		return NULL;
//	ListNode* pPre = pHead;
//	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* pCur = p;
//	p->val = x;
//	p->next = NULL;
//	while (pPre != NULL)
//	{
//		ListNode*p2 = pPre;
//		if (p->val>pPre->val)
//		{
//			ListNode* temp = p->next;
//			p->next = p2;
//			p2->next = temp;
//		}
//		else
//		{
//			p->next = pCur;
//			pCur = pPre;
//		}
//		pPre = pPre->next;
//	}
//	if (pCur == p)
//		return pCur->next;
//	ListNode* temp = pCur;
//	while (temp->next != p)
//		temp = temp->next;
//	temp->next = temp->next->next;
//	return pCur;
//}
#include<iostream>
#include<string.h>
using namespace std;
class MyString
{
 public:
  MyString()
       {
            this->str = NULL;
            this->len = 0;
        }
        MyString(const char* str)
         {
           this->len = strlen(str);
           this->str = new char[len + 1];
            strcpy(this->str, str);
         }
         MyString operator+(MyString& another)
       {
			 MyString temp;
            temp.len = another.len + this->len;
			temp.str = new char[another.len + this->len + 1];
		strcpy(temp.str, this->str);
		strcat(temp.str, another.str);
            return temp;
         }
		 MyString& operator=(const MyString& another)
		 {
			 if (strcmp(this->str, another.str) == 0)
			 {
				 return *this;
			 }
			 if (this->str == NULL)
			 {
				 this->len = another.len;
				 this->str = new char[this->len + 1];
				 strcpy(this->str, another.str);
				 return *this;
			 }
			 else
             {
                 delete[]this->str;
                 this->str = new char[another.len + 1];
                 this->len = another.len;
                 strcpy(this->str, another.str);
                 return *this;

             }

         }
		 char* GetString()
         {
             return this->str;
         }
     private:
         char* str;
         int len;
 };
//int main()
//{
//     MyString s1("hhhhhh");
//     MyString s2("mmmmmm");
//     MyString s3;
//     s1 = (s1 + s2);
//     cout << s1.GetString() << endl;
//     return 0;
// }
