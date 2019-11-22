#include"work.h"

int main()
{
	//node* head = (node*)malloc(sizeof(node));
	list* head = (list*)malloc(sizeof(list));
	init_list(&head);
	//creatlist_start(&head);
	/*creatlist_end(&head);
	list_sort(&head);
	printlist(head);
	dele_list(&head, 1);
	printlist(head);*/
	
	list_start(&head);
	//list_end(&head);
	//list_sort(&head);
	//print(head);
	//dele_list_end(&head);
	sort(&head);
	sort(&head);
	//node* temp = Reverse_list(&head);
	printf("\n");
	//printlist(temp);
	print(head);
	//dele_list(&head, 1);
	//printlist(head);

	system("pause");
	return 0;
}