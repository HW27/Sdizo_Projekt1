#pragma once
class ElemRB
{
public:
	ElemRB *parent;
	ElemRB *left;
	ElemRB *right;
	char color;
	int value;

	ElemRB();
	ElemRB(int value, char color, ElemRB* parent);
	~ElemRB();

};