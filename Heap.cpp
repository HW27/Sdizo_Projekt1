#include <iostream>
#include <fstream>
#include <string>
#include "Heap.h"

using namespace std;
Heap::Heap()
{
	this->size = 0;
}
Heap::Heap(Array root)
{
	this->root = root;
	size = 0;
}
int Heap::findParent(int index)
{
	if (index > 0)
	{
		return (index - 1) / 2;
	}
	return 0;
}
int Heap::findLeftChild(int index)
{
		return 2 * index + 1;
}
int Heap::findRightChild(int index)
{
		return 2 * index + 2;
}
Heap::~Heap()
{

}
void Heap::print(std::string sp, std::string sn, int v)
{
	std::string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	std::string s;

	if (v < size)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		print(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << root.get(v) << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		print(s + cp, cl, 2 * v + 1);
	}
}
void Heap::push(int value)
{
	size++;
	root.push_back(value);
	int index = root.getSize() - 1;

	while (findParent(index) != -1  && root.get(findParent(index)) < value)
	{
		root.get(index) = root.get(findParent(index));
		root.get(findParent(index)) = value;
		index = findParent(index);
	}
}
void Heap::pop() //Usuwa korzeñ
{
	if (size == 0)
		return;
	int tmp = root.get(size - 1);
	int newIndex = 0;
	root.pop_back();
	this->size--;
	int Iterator = 1;
	while (Iterator < size)
	{
		if (Iterator + 1 < size && root.get(Iterator + 1) > root.get(Iterator))
			Iterator++;
		if (tmp > root.get(Iterator))
			break;

		root.get(newIndex) = root.get(Iterator);
		newIndex = Iterator;
		Iterator = 2 * Iterator + 1;
	}
	root.get(newIndex) = tmp;
	
}
void Heap::deleteAt(int index)
{
	if (size == 0)
		return;
	int tmp = root.get(size - 1);
	int newIndex = index;
	root.pop_back();
	this->size--;
	int leftChildValue = findLeftChild(index);
	while (leftChildValue < size)
	{
		if (leftChildValue + 1 < size && root.get(leftChildValue + 1) > root.get(leftChildValue))
			leftChildValue++;
		if (tmp > root.get(leftChildValue))
			break;

		root.get(newIndex) = root.get(leftChildValue);
		newIndex = leftChildValue;
		leftChildValue = 2 * leftChildValue + 1;
	}
	root.get(newIndex) = tmp;
}
int Heap::searchValue(int sHeap, int value)
{
	if (sHeap >= this->size || sHeap < 0)
		return -1;
	if (root.get(sHeap) == value)
		return sHeap;
	int childL = 2 * sHeap + 1;
	int childR = childL + 1;
	int x = -1;
	x = searchValue(childL, value);
	if (x == -1)
		x = searchValue(childR, value);
	return x;
}

void Heap::loadDataFromFile(std::string filename)
{
	int tmpSize = 0,tmpValue=0;
	ifstream file(filename);
	if (file.is_open())
	{
		file >> tmpSize;
		//this->size = tmpSize;
		for (int i = 0; i < tmpSize; i++)
		{
			if (file >> tmpValue)
			{
				this->push(tmpValue);
			}
		}
	}
}
int Heap::get(int index)
{
	return root.get(index);
}
int Heap::getSize()
{
	return this->size;
}
