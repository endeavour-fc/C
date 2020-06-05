#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
using namespace std;
#define DataType int
//struct ListNode
//{
//	int val;
//	ListNode* next;
//};
//
//ListNode* InitNode()
//{
//	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
//	temp->next = NULL;
//	temp->val = 0;
//	return temp;
//
//}
//ListNode* CreatNode(int x)
//{
//	//int num = 0;
//	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
//	temp->next = NULL;
//	//printf("please input num\n");
//	//scanf("%d", &num);
//	temp->val = x;
//	return temp;
//
//}
//void InsertNode(ListNode** head, ListNode* Node)
//{
//	if (head == NULL || Node == NULL)
//		return;
//	ListNode* temp = (*head)->next;
//	(*head)->next = Node;
//	Node->next = temp;
//}
//void FreeNode(ListNode* head)
//{
//	while (head != NULL)
//	{
//		ListNode* temp = head->next;
//		free(head);
//		head = temp;
//	}
//}
//#define P 13
//struct HashNode
//{
//	DataType data;
//	HashNode* Next;
//};
//
//typedef HashNode* HashTable[P];
//
//void HashTableInsert(HashTable HS, DataType x)
//{
//	int index = x % P;
//	HashNode* temp = (HashNode*)malloc(sizeof(HashNode));
//	temp->data = x;
//	temp->Next = HS[index];
//	HS[index] = temp;
//}
//void Print(HashTable HS)
//{
//	HashNode* temp = NULL;
//	for (int i = 0; i < P; i++)
//	{
//		temp = HS[i];
//		while (temp != NULL)
//		{
//			printf("%d->", temp->data);
//			temp = temp->Next;
//		}
//		printf("NULL\n");
//	}
//}
//HashNode* FindNode(HashTable HS, DataType x)
//{
//	HashNode* temp = HS[x % P];
//	while (temp != NULL && temp->data != x)
//		temp = temp->Next;
//	return temp;
//}
//void RemoveNode(HashTable HS, DataType x)
//{
//	HashNode* temp = FindNode(HS, x);
//	if (temp == NULL)
//		return;
//	int index = x % P;
//	if (HS[index] == temp)
//	{
//		HashNode* pPre = HS[index]->Next;
//		free(HS[index]);
//		HS[index] = pPre;
//	}
//	else
//	{
//		HashNode* pPre = HS[index];
//		while (pPre->Next != temp && pPre)
//			pPre = pPre->Next;
//		pPre->Next = temp->Next;
//		free(temp);
//	}
//
//}
//void FreeHash(HashTable HS)
//{
//	for (int i = 0; i < P; i++)
//	{
//		while (HS[i] != NULL)
//		{
//			HashNode* temp = HS[i]->Next;
//			free(HS[i]);
//			HS[i] = temp;
//		}
//	}
//}
//
//int main()
//{
//	//ListNode* head = InitNode();
//	HashTable HS = { NULL };
//	int arr[] = { 49,38,65,97,76,13,27 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < len; i++)
//	{
//		HashTableInsert(HS, arr[i]);
//	}
//	Print(HS);
//	RemoveNode(HS, 651);
//	printf("============================================================\n");
//	printf("============================================================\n");
//	Print(HS);
//	FreeHash(HS);
//	//FreeNode(head);
//	system("pause");
//	return 0;
//}

#define P 7

#define NULL_DATA -1

struct bucket_node
{

	int data[3];

	struct bucket_node *next;

};

struct bucket_node* hash_table[P];

struct bucket_node hash_table1[P];

//现在假设hash_table已经初始化好了，

//insert_new_element()函数目的是把一个新的值插入hash_table中，

//元素插入成功时，函数返回0，否则返回-1，完成函数。

int flag[8] = {0};

void InitArr(int* arr)
{
	for (int i = 0; i < 3; i++)
		arr[i] = -1;
}

int insert_new_element(int new_element)

{

	//int len=flag/3;
	int in = flag[new_element%P] % 3;
	if (in == 0)
	{
		bucket_node* temp = (bucket_node*)malloc(sizeof(bucket_node));
		InitArr(temp->data);
		//插入
		temp->next = hash_table[new_element%P];
		hash_table[new_element%P] = temp;
		temp->data[in] = new_element;
		flag[new_element%P]++;

	}
	else
	{
		hash_table[new_element%P]->data[in] = new_element;
		flag[new_element%P]++;
	}


	return 0;
}
/////////////////////////////////////////////////
int Hash(int key)

{

	return key % P;

}



void Init_bucket_node()

{

	for (int i = 0; i<P; ++i)

	{

		for (int j = 0; j<3; ++j)

		{

			hash_table1[i].data[j] = NULL_DATA;

		}

		hash_table1[i].next = NULL;

	}

}



int insert_new_element(int new_element)

{

	int index = Hash(new_element);

	for (int i = 0; i<3; ++i)

	{

		if (hash_table1[index].data[i] == NULL_DATA)

		{

			hash_table1[index].data[i] = new_element;

			return 0;

		}

	}



	struct bucket_node *p = &hash_table1[index];

	while (p->next != NULL)

	{

		p = p->next;

		for (int i = 0; i<3; ++i)

		{

			if (p->data[i] == NULL_DATA)

			{

				p->data[i] = new_element;

				return 0;

			}

		}

	}



	struct bucket_node *s = (struct bucket_node*)malloc(sizeof(struct bucket_node));

	for (int i = 0; i<3; ++i)

	{

		s->data[i] = NULL_DATA;

	}

	s->next = NULL;

	s->data[0] = new_element;



	p->next = s;



	return 0;

}

////////////////////////////////////////////////



int main()
{
	string str;
	string ori;
	size_t count = 0;
	while (cin >> str >> ori)
	{
		auto it = str.begin();
		auto it1 = ori.begin();
		while (it != str.end())
		{
			if (*it == *it1)
			{
				it1++;
				it++;
			}
			else
			{
				it++;
				it1 = ori.begin();
			}
			if (it1 == ori.end())
			{
				count++;
				it1 = ori.begin();
			}
		}
		cout << count << endl;
	}
	return 0;
}
//int main()
//
//{
//
//	hash_table[P] = { NULL }; //
//
//	int array[] = { 1,8,15,22,29,36,43,50,58,66,63,16,103,77,5,153,145,356,51,68,705,453 };
//
//	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
//
//	{
//
//		insert_new_element(array[i]);
//
//	}
//
//	return 0;
//
//}