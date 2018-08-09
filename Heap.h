#pragma once
#include "Array.h"
class Heap
{
	Array root;
	int size;
	int findParent(int index);
	int findLeftChild(int index);
	int findRightChild(int index);

public:
	Heap();
	Heap(Array root);
	~Heap();
	void print(std::string sp, std::string sn, int v);
	void push(int value);
	void pop();
	void deleteAt(int index);
	int searchValue(int sHeap, int value);
	void loadDataFromFile(std::string filename);
	int get(int index);
	int getSize();
};