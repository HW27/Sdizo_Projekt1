#include <iostream>
#include <fstream>
#include "MyList.h"
#include "ElemList2.h"
using namespace std;
MyList::MyList() //Konstruktor domyœlny
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}
MyList::~MyList() //Destruktor
{
	while (head != tail) {
		head = head->next;
		delete head->prev;
	}
	delete tail;
}

void MyList::push_front(int value) //dodaje wartoœæ na pocz¹tek listy
{
	head = new ElemList2(nullptr, head, value);
	if (!tail)						
		tail = head;
	size++;
}
void MyList::push_back(int value) //dodaje wartoœæ na koniec listy
{
	tail = new ElemList2(tail, nullptr, value);
	if (!head)						
		head = tail;
	size++;
}
void MyList::push_inside(int index,int value) //dodaje element za wskazanym jako parametr funkcji
{
	if (index == 0)
		push_front(value);
	if (index == this->size)
		push_back(value);

	ElemList2* unknown;
	if (index <= this->size / 2)
	{
		unknown = this->head;
		for (int i = 0; i != index; i++)
		{
			if (index-1 == i)
			{
				unknown = unknown->next;
			}
			new ElemList2(unknown, unknown->next, value);
		}
	}
	else
	{
		unknown = this->tail;
		for (int i = this->size - 1; i != index; i--)
		{
			if(index ==i)
				unknown = unknown->prev;
		}
		new ElemList2(unknown->prev, unknown, value);
	}
	this->size++;
}

void MyList::pop_front() //usuwa wartoœæ z pocz¹tku listy
{
	ElemList2* tmp = this->head;
	this->head = this->head->next;
	delete tmp;
	if (this->head)
		this->head->prev = NULL;
	else
		this->tail = NULL;
	this->size--;
	
}
void MyList::pop_back() //usuwa wartoœæ z koñca listy
{
	ElemList2* tmp = this->tail;
	this->tail = this->tail->prev;
	delete tmp;
	if (this->tail)
		this->tail->next = NULL;
	else
		this->head = NULL;
	this->size--;

}
void MyList::pop_inside(int index)  // usuwa wartoœæ z wskazanego indeksu
{
	ElemList2* found;
	if (index < size / 2)
	{
		found = head;
		int i = 0;
		while (i != index)
		{
			found = found->next;
			i++;
		}
	}
	else
	{
		found = tail;
		int i = size - 1;
		while (i != index)
		{
			found = found->prev;
			i--;
		}
	}

	if (found->prev)
	{
		found->prev->next = found->next;
	}
	else
	{
		head = head->next;
	}

	if (found->next)
	{
		found->next->prev = found->prev;
	}
	else
	{
		tail = tail->prev;
	}
	size--;
}

int MyList::getSize()
{
	return this->size;
}
int MyList::get(int index) //zwraca wartoœæ na podanym indeksie
{
	ElemList2* found;
	if (index < size / 2)
	{
		found = head;
		int i = 0;
		while (i != index)
		{
			found = found->next;
			i++;
		}
	}
	else
	{
		found = tail;
		int i = size - 1;
		while (i != index)
		{
			found = found->prev;
			i--;
		}
	}
	return found->value;
}
void MyList::searchValue(int value) //funkcja typu bool przrobiona specjalnie do menu
{
	ElemList2* found = head;
	for (int i = 0; i < this->getSize(); i++)
	{
		if (found->value == value)
		{
			cout << "Taka wartosc istnieje w tej liscie."<<endl;
				return;
		}
		else
		{
			if (found->next!=NULL)
			{
				found = found->next;
			}
			else
			{
				cout << "Taka wartosc nie istnieje w tej liscie." << endl;
				return;
			}
		}

	}
}
void MyList::loadDataFromFile(std::string filename)
{
	int tmpSize, tmpValue = 0;
	ifstream file(filename);
	if (file.is_open())
	{
		file >> tmpSize;
		//this->size = tmpSize;
		for (int i = 0; i < tmpSize; i++)
		{
			if (file >> tmpValue)
			{
				this->push_front(tmpValue);
			}
		}
	}
	file.close();
}
