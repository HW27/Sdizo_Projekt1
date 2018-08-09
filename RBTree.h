#pragma once
#include <iostream>
#include "ElemRb.h"

class RBTree
{
	int size;
	ElemRB guardian;
	ElemRB* root;
	void rotate_left(ElemRB* rotator);
	void rotate_right(ElemRB* rotator);
	ElemRB* findValue(int value);
	ElemRB* findParent(int value);
	ElemRB* findSuccesor(ElemRB* node);
public:
	ElemRB* getRoot();
	~RBTree();
	RBTree();
	RBTree(ElemRB* root);
	void Remove(int value);
	bool searchValue(int value); //bool
	void push(int value);
	ElemRB* RBTree::minRBT(ElemRB * p);
	void print(std::string sp, std::string sn, ElemRB * p);
	int getSize();
	void RemoveTree(ElemRB* node);

	void loadDataFromFile(std::string filename);
};