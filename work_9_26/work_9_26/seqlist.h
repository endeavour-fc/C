#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN 1

struct seqlist
{
	void* date;
	size_t len;
    size_t size;
};

void listinit(seqlist* p);
void menu();
void listpushback(seqlist* p);
void listsort(seqlist* p);
void listpushbegin(seqlist* p);
void printlist(seqlist* p);