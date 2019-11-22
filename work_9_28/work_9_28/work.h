#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int num;
	node *next;
};

struct list
{
	node* first;
	node* last;
	size_t size;
};


void init(node** head);
void creatlist_start(node** head);
void printlist(node* head);
void creatlist_end(node** head);
void list_sort(node** head);
void dele_list(node** head, int mx);

//*****************************************
//*****************************************

void init_list(list** head);
node* getlist(int date);
void list_start(list** head);
void print(list* head);
void list_end(list** head);
void dele_list_start(list** head, int mx);
void dele_list_end(list** head);
void sort(list** head);
node*  find_list(list* head, int mx);
void insert_sort(list*head);
node* Reverse_list(list** head);