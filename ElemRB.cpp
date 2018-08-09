#include "ElemRB.h"


ElemRB::ElemRB()
{
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}
ElemRB::ElemRB(int value, char color, ElemRB* parent)
{
	this->value = value;
	this->parent = parent;
	this->color = color;
	this->left = nullptr;
	this->right = nullptr;
}
ElemRB::~ElemRB()
{

}