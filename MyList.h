#include "ElemList2.h"
class MyList
{
	ElemList2 *head;
	ElemList2 *tail;
	int size;
public:
	MyList();
	~MyList();
	void loadDataFromFile(std::string filename);

	void push_front(int value);
	void push_back(int value);
	void push_inside(int index,int value);

	void pop_front();
	void pop_back();
	void pop_inside(int index);

	void searchValue(int value);
	int getSize();
	int get(int index);
};