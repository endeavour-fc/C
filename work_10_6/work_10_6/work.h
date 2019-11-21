#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode
{
	ListNode* next;
};

struct LinkList
{
	ListNode Node;
	int num;
};


LinkList* Init_List();
void Creat_List(LinkList* head);
void Print_List(LinkList* head);