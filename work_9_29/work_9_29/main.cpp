#include"work.h"

int main()
{
	/*Nodelist* head = (Nodelist*)malloc(sizeof(Nodelist));
	InitNode(&head);
	CreatNode_start(&head);
	PrintNode(head);
	DeleNode(&head, 1);
	PrintNode(head);
	InsertNode(&head, 2);
	PrintNode(head);
	SortNode(&head);
	PrintNode(head);*/
	Node* head = (Node*)malloc(sizeof(Node));
	InitNode_list(&head);
	CreatNode_start_list(&head);
	sort(&head);
	PrintNode_list_end(head);



	system("pause");
	return 0;
}