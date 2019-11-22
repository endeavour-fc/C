#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct BitTreeNode
{
	char data;
	struct BitTreeNode *lchild, *rchild;
}*BitTree; 
struct QNode
{
	BitTree data;
	QNode *next;
}; 
struct LinkQueue
{    
	QNode *front;
	QNode *rear;
};
void Init_Link(LinkQueue* q)
{
	q->front = q->rear = NULL;
}
void EnQueue(LinkQueue* q, BitTree tree)
{
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	if (q->front == NULL)
	{
		q->front = q->rear = temp;
		temp->data = tree;
		temp->next = NULL;
		return;
	}
	temp->data = tree;
	temp->next = NULL;
	q->rear->next = temp;
	q->rear = temp;
}
bool Empty_Queue(LinkQueue* q)
{
	return q->front == NULL ? true : false;
}
BitTreeNode* DeQueue(LinkQueue* q)
{
	if (Empty_Queue(q))
		return NULL;
	QNode* temp = q->front;
	q->front = q->front->next;
	//free(temp);
	return temp->data;
}
char Get_char(LinkQueue* q)
{
	return q->front->data->data;
}

BitTreeNode* createTree(char* arr)
{
	//char c = 0;
	//fflush(stdin);
	//scanf("%c",&c);
	static int i = 0;
	//char arr[] = "abc##de##f##g#h##";
	if (*(arr + i) == '#' || *(arr + i) == '\0')
	{
		if (*(arr + i) == '\0')
			return NULL;
		i++;
		return NULL;
	}
	BitTreeNode* root = (BitTreeNode*)malloc(sizeof(BitTreeNode));
	root->data = *(arr + i);
	i++;
	root->lchild = createTree(arr);
	root->rchild = createTree(arr);

	return root;
}
void Recursion(BitTreeNode* root)
{
	if (root == NULL)
		return;
	printf("%c", root->data);
	Recursion(root->lchild);
	Recursion(root->rchild);

}
void Free_BinaryNode(BitTreeNode* root)
{
	if (root == NULL)
		return;
	Free_BinaryNode(root->lchild);
	Free_BinaryNode(root->rchild);
	free(root);
}


void levelOrder(BitTree tree, LinkQueue* queue)
{ 
	BitTree p = NULL;
	Init_Link(queue);
	EnQueue(queue, tree);
	while (queue->front != NULL)
	{ 
		p=DeQueue(queue);
		printf("%c", p->data);
		if (p->lchild != NULL)
		{ 
			EnQueue(queue, p->lchild); 
		}       
		if (p->rchild != NULL)
		{
			EnQueue(queue,p->rchild); 
		}
	}
}


int main()
{
	LinkQueue *q=(LinkQueue*)malloc(sizeof(LinkQueue));
	char arr[] = "abc##de##f##g#h##";
	BitTreeNode* root = createTree(arr);
	Recursion(root);
	printf("\n");
	levelOrder(root, q);
	Free_BinaryNode(root);
	
	system("pause");
	return 0;
}