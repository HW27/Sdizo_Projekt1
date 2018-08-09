#pragma once
#include <iostream>
class Array
{
	int* head;
	int size;
public:
	Array(int *head, int size);
	Array();
	~Array();
	void push_front(int value);
	void push_back(int value);
	void insertAt(int index, int value);
	void pop_front();
	void pop_back();
	void loadDataFromFile(std::string filename);
	bool searchValue(int value);
	void deleteAt(int index);
	void repleaceAt(int index, int value);
	int& get(int where);
	int getSize();
};