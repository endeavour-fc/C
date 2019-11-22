#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Nodelist
{
	Nodelist* next;
	Nodelist* back;
	int num;
};
struct Node
{
	Nodelist* last;
	Nodelist* first;
	size_t size;
};

void InitNode(Nodelist** head);
void CreatNode_start(Nodelist** head);
void PrintNode(Nodelist* head);
void DeleNode(Nodelist** head, int num);
void InsertNode(Nodelist** head, int num);
void SortNode(Nodelist** head);



//********************************************
//********************************************
void InitNode_list(Node** head);
void CreatNode_start_list(Node** head);
void PrintNode_list(Node* head);
void PrintNode_list_end(Node* head);
void sort(Node** head);