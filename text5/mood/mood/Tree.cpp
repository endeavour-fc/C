#include "Tree.h"



void Tree::grow(int year)
{
	age = age + year;

}

void Tree::setage(int a)
{
	age = a;
}

int Tree::getage()
{
	return age;
}