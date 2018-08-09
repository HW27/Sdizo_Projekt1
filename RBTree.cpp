#include "RBTree.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
RBTree::RBTree()
{
	this->size = 0;
	this->root = nullptr;
	this->guardian.color = 'B';
	this->guardian.parent = &guardian;
	this->guardian.left = &guardian;
	this->guardian.right = &guardian;
	this->root = &guardian;
}
RBTree::RBTree(ElemRB* root)
{
	this->size = 0;
	this->root = root;
	this->guardian.color = 'B';
	this->guardian.parent = &guardian;
	this->guardian.left = &guardian;
	this->guardian.right = &guardian;
	this->root = &guardian;
}
RBTree::~RBTree()
{
	RemoveTree(this->root);
}
void RBTree::rotate_left(ElemRB* rotator)
{
	ElemRB * B, *p;
	B = rotator->right;
	if (B != &guardian)
	{
		p = rotator->parent;
		rotator->right = B->left;
		if (rotator->right != &guardian) 
			rotator->right->parent = rotator;

		B->left = rotator;
		B->parent = p;
		rotator->parent = B;

		if (p != &guardian)
		{
			if (p->left == rotator) 
				p->left = B; 
			else p->right = B;
		}
		else root = B;
	}
}
void RBTree::rotate_right(ElemRB* rotator)
{
	ElemRB * B, *p;

	B = rotator->left;
	if (B != &guardian)
	{
		p = rotator->parent;
		rotator->left = B->right;
		if (rotator->left != &guardian) 
			rotator->left->parent = rotator;

		B->right = rotator;
		B->parent = p;
		rotator->parent = B;

		if (p != &guardian)
		{
			if (p->left == rotator) 
				p->left = B; 
			else 
				p->right = B;
		}
		else root = B;
	}
}
ElemRB* RBTree::findValue(int value) //zwraca wskaznik na szukana wartosc
{
	ElemRB* unknown;

	unknown = this->root;
	while ((unknown != &guardian) && (unknown->value != value))
	{
		if (value < unknown->value)
			unknown = unknown->left;
		else
			unknown = unknown->right;
	}
	if (unknown == &guardian)
		return NULL;
	return unknown;
} 
ElemRB* RBTree::findParent(int value)
{
	ElemRB* unknown = findValue(value);
	if (!unknown->parent)
		return unknown->parent;
	return NULL;
	
}
ElemRB* RBTree::getRoot()
{
	return root;
}
ElemRB* RBTree::minRBT(ElemRB * p)
{
  if(p != &guardian)
    while(p->left != &guardian) p = p->left;
  return p;
}
ElemRB* RBTree::findSuccesor(ElemRB* node) 
{
	ElemRB* unknown;
	if (node != &guardian)
	{
		if (node->right != &guardian)
		{
			return minRBT(node->right);
		}
		else
		{
			unknown = node->parent;
			while ((unknown != &guardian) && (node == unknown->right))
			{
				unknown = unknown->parent;
			}
			return unknown;
		}
	}
	return &guardian;
}
void RBTree::Remove(int value)
{
	ElemRB* unknown = findValue(value);
	if (unknown == NULL)
	{
		cout << "Taka wartosc nie istnieje" << endl;
		return;
	}
	ElemRB * W, *Y, *Z;
	//Przypisanie wskaznika Y
	if ((unknown->left == &guardian) || (unknown->right == &guardian)) 
			Y = unknown;
	else                                    
		Y = findSuccesor(unknown);
	//Przypisanie wskaznika Z
	if (Y->left != &guardian) 
		Z = Y->left;
	else              
		Z = Y->right;

	Z->parent = Y->parent;

	if (Y->parent == &guardian) 
		root = Z;
	else if (Y == Y->parent->left) 
		Y->parent->left = Z;
	else                      
		Y->parent->right = Z;

	if (Y != unknown)
		unknown->value = Y->value;

	if (Y->color == 'B')   
		while ((Z != root) && (Z->color == 'B'))
			if (Z == Z->parent->left)
			{
				W = Z->parent->right;

				if (W->color == 'R')
				{              
					W->color = 'B';
					Z->parent->color = 'R';
					rotate_left(Z->parent);
					W = Z->parent->right;
				}

				if ((W->left->color == 'B') && (W->right->color == 'B'))
				{             
					W->color = 'R';
					Z = Z->parent;
					continue;
				}

				if (W->right->color == 'B')
				{             
					W->left->color = 'B';
					W->color = 'R';
					rotate_right(W);
					W = Z->parent->right;
				}

				W->color = Z->parent->color; 
				Z->parent->color = 'B';
				W->right->color = 'B';
				rotate_left(Z->parent);
				Z = root;    //koniec petli    
			}
			else
			{              
				W = Z->parent->left;

				if (W->color == 'R')
				{              
					W->color = 'B';
					Z->parent->color = 'R';
					rotate_right(Z->parent);
					W = Z->parent->left;
				}

				if ((W->left->color == 'B') && (W->right->color == 'B'))
				{             
					W->color = 'R';
					Z = Z->parent;
					continue;
				}

				if (W->left->color == 'B')
				{             
					W->right->color = 'B';
					W->color = 'R';
					rotate_left(W);
					W = Z->parent->left;
				}

				W->color = Z->parent->color;  
				Z->parent->color = 'B';
				W->left->color = 'B';
				rotate_right(Z->parent);
				Z = root;   //koniec petli
			}

	Z->color = 'B';

	delete Y;
}
bool RBTree::searchValue(int value) //sprawdza czy wartosc istnieje
{
	ElemRB* unknown = findValue(value);
	if (unknown == NULL)
	{
		cout << "Taki element nie istnieje" << endl;
		return false;
	}
	else
	{
		cout << "Taki element istnieje" << endl;
		return true;
	}
}
void RBTree::push(int value)
{
	ElemRB * X, *Y;
	X = new ElemRB;

	X->left = &guardian;          
	X->right = &guardian;
	X->parent = root;
	X->value = value;

	if (X->parent == &guardian) 
		root = X;
	else
		while (true)             
		{
			if (value < X->parent->value)
			{
				if (X->parent->left == &guardian)
				{
					X->parent->left = X; 
					break;
				}
				X->parent = X->parent->left;
			}
			else
			{
				if (X->parent->right == &guardian)
				{
					X->parent->right = X; 
					break;
				}
				X->parent = X->parent->right;
			}
		}

	X->color = 'R';

	while ((X != root) && (X->parent->color == 'R'))
	{
		if (X->parent == X->parent->parent->left)
		{
			Y = X->parent->parent->right; 

			if (Y->color == 'R') 
			{
				X->parent->color = 'B';
				Y->color = 'B';
				X->parent->parent->color = 'R';
				X = X->parent->parent;
				continue;
			}

			if (X == X->parent->right) 
			{
				X = X->parent;
				rotate_left(X);
			}

			X->parent->color = 'B';
			X->parent->parent->color = 'R';
			rotate_right(X->parent->parent);
			break;
		}
		else
		{                
			Y = X->parent->parent->left;
			if (Y->color == 'R')
			{
				X->parent->color = 'B';
				Y->color = 'B';
				X->parent->parent->color = 'R';
				X = X->parent->parent;
				continue;
			}
			if (X == X->parent->left) 
			{
				X = X->parent;
				rotate_right(X);
			}
			X->parent->color = 'B';
			X->parent->parent->color = 'R';
			rotate_left(X->parent->parent);
			break;
		}
	}
	root->color = 'B';
	this->size++;
}
void RBTree::print(std::string sp, std::string sn, ElemRB * p)
{
	std::string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	std::string t;

	if (p != &guardian)
	{
		t = sp;
		if (sn == cr) t[t.length() - 2] = ' ';
		print(t + cp, cr, p->right);

		t = t.substr(0, sp.length() - 2);
		std::cout << t << sn << p->color << ":" << p->value << std::endl;

		t = sp;
		if (sn == cl) t[t.length() - 2] = ' ';
		print(t + cp, cl, p->left);
	}
}
int RBTree::getSize()
{
	return this->size;
}
void RBTree::loadDataFromFile(std::string filename) 
{
	this->RemoveTree(root);
	this->root = &guardian;
	int tmpSize=0, tmpValue = 0;
	ifstream file(filename);
	if (file.is_open())
	{
		file >> tmpSize;

		for (int i = 0; i < tmpSize; i++)
		{
			if (file >> tmpValue)
			{
				this->push(tmpValue);
			}
		}
	}
	file.close();
}
void RBTree::RemoveTree(ElemRB* node)
{
	if (node !=&guardian)
	{
		RemoveTree(node->left);
		RemoveTree(node->right);
		delete node;
	}
}