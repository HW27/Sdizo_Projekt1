#include "ElemList2.h"

ElemList2::ElemList2()
{
	this->value = 0;
	this->prev = nullptr;
	this->next = nullptr;
}
ElemList2::ElemList2(ElemList2* prev, ElemList2* next, int value)
{
	this->prev = prev;
	this->next = next;
	this->value = value;
	if (next)
	{
		next->prev = this;
	}
	if (prev)
	{
		prev->next = this;
	}
	
}
