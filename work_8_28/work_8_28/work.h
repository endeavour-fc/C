#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<Windows.h>

enum Option
{
	EXIT=0,
	ADD,
	DELE,
	SEARCH,
	MOD,
	SHOW,
	SORT,

};

typedef struct PeoInfo
{
	char name[20];
	char sex[10];
	int tele;
	char addr[30];
	short age;
}P;

typedef struct pcon
{
	P* date;
	int num;
	int sz;
}pcon;

void menu();
void init(pcon* p);
void add(pcon* p);
void show(pcon* p);
void dele(pcon* p);
void search(pcon* p);
void sort(pcon* p);
void mod(pcon* p);