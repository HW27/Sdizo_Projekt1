#pragma once

class ElemList2
{
public:
	int value;
	ElemList2 *next, *prev;

	ElemList2();
	ElemList2(ElemList2* prev, ElemList2* next, int value);
};