#include <iostream>
#include <fstream>
#include "Array.h"
using namespace std;

Array::Array(int *head, int size) //konstruktor tablicy
{
	this->head = head;
	this->size = size;
}
Array::Array()
{
	this->head = nullptr;
	this->size = 0;
}
Array::~Array() //destruktor tablicy
{
	delete[] this->head;
}
void Array::push_front(int value) //dodawanie wartoœci na pocz¹tek tablicy
{	
	if (this->size != 0)
	{
		int* newHead = new int[this->size + 1];
		for (int i = 0; i < this->size+1; i++)
		{
			*(newHead + 1 + i) = *(this->head+i);
		}
		*newHead = value;
		this->head = newHead;
		this->size++;
	}
	else if(this->size == 0)
	{
		this->size++;
		this->head = new int[1];
		*(this->head) = value;
	}
}
void Array::push_back(int value) //dodawanie wartoœci na koniec tablicy
{
	if (this->size != 0)
	{
		int* newHead = new int[this->size + 1];
		for (int i = 0; i < (this->size + 1); i++)
		{
			*(newHead + i) = *(this->head+i);
		}
		*(newHead + this->size) = value;
		this->head = newHead;
		this->size++;
	}
	else if(this->size==0)
	{
		this->size++;
		this->head = new int[1];
		*(this->head) = value;
	}
}
void Array::insertAt(int index, int value) //dodawanie wartoœci na podanym indeksie
{
	if (index == 0)
		push_front(value);
	else if (index == this->size)
		push_back(value);
	else if (this->size != 0 && index>0)
	{
		int* newHead = new  int[this->size + 1];
		for (int i = 0; i < index; i++)
		{
				*(newHead + i) = *(this->head + i);
		}
		for (int i = index; i < this->size; i++)
		{
			*(newHead + i + 1) = *(this->head + i);
		}
		*(newHead + index) = value;
		this->head = newHead;
		this->size++;
	}
}
void Array::pop_front() //usuwanie wartoœci z pocz¹tku tablicy
{
	if (this->size != 0)
	{
		int* newHead = new int[this->size - 1];
		for (int i = 0; i < this->size - 1; i++)
		{
			*(newHead + i) = *(this->head + 1+i);
		}
		this->size--;
		this->head = newHead;
	}
}
void Array::pop_back() //usuwanie wartoœci z koñca tablicy
{
	if (this->size != 0)
	{
		int* newHead = new int[this->size - 1];
		for (int i = 0; i < this->size - 1; i++)
		{
			*(newHead + i) = *(this->head + i);
		}
		this->size--;
		this->head = newHead;
	}
}
bool Array::searchValue(int value) //dodawanie wartoœci do tablicy na wybranej pozycji 
{
	for (int i = 0; i < size; i++)
	{
		if (*(head + i) == value)
		{
			return true;
		}
	}
	return false;

}
void Array::deleteAt(int index) //usuwanie wartoœci na wybranej pozycji
{
	if (index == 0)
		this->pop_front();
	if (this->size != 0 && index>0)
	{
		int* newHead = new  int[this->size -1];
		for (int i = 0;i<index; i++)
		{
				*(newHead + i) = *(this->head + i);
		}
		for (int i = index; i<this->size-1; i++)
		{
			*(newHead + i) = *(this->head + i+1);
		}
		this->head = newHead;
		this->size--;
	}
}
void Array::repleaceAt(int index, int value) //zamienia wartosc na danym indeksie
{
	if (this->size != 0 && index > 0)
	{
		*(head + index) = value;
	}
}
int& Array::get(int index) //zwraca wartoœæ podanego indesku tablicy
{
	if (!(index > this->size))
		return *(index + this->head);
}
int Array::getSize() //zwraca d³ugoœæ tablicy
{
	return this->size;
}
void Array::loadDataFromFile(std::string filename) //wczytywanie wartosci z pliku 
{
	int tmpSize=0,tmpValue=0;
	ifstream file(filename);
	if (file.is_open())
	{
		file >> tmpSize;
		this->size = tmpSize;
		this->head = new int[this->size];

		for (int i = 0; i < size; i++)
		{
			if (file >> tmpValue)
			{
				*(head + i) = tmpValue;
			}
		}
	}
	file.close();
}
