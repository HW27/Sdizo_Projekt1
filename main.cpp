#include <iostream>
#include <fstream>
#include <string>

#include "Array.h"
#include "MyList.h"
#include "Heap.h"
#include "RBTree.h"

int* myarray = new int;
Array tab(myarray, 0);
MyList lista;
int* myheap = new int;
Array Htab(myheap, 0);
Heap heap(Htab);
ElemRB* root = new ElemRB;
RBTree drzewo(root);

using namespace std;
void Drzewo();
void wybor();

void Tablica()
{
	system("CLS");
	int i = 0,value=0,index=0;
	string namefile;
	cout << "Tablica, dostepne operacje: " << endl;
	cout << "1. Wczytaj z pliku" << endl;
	cout << "2. Dodaj na poczatek tablicy" << endl;
	cout << "3. Dodaj na koniec tablicy" << endl;
	cout << "4. Dodaj wartosc na podanym indeksie" << endl;
	cout << "5. Usun wartosc z poczatku tablicy" << endl;
	cout << "6. Usun wartosc z konca tablicy" << endl;
	cout << "7. Usun wartosc z podanego indeksu" << endl;
	cout << "8. Wyswietl zawartosc tablicy" << endl;
	cout << "9. Wyswietl wielkosc struktury"<<endl;
	cout << "10. Sprawdz czy wartosc istnieje w tablicy" << endl;
	cout << "11. Wycofanie sie do glownego menu" << endl;
	cout << "Twoj wybor:";
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "Podaj nazwe pliku" << endl;
		cin >> namefile;
		tab.loadDataFromFile(namefile);
		Tablica();
		break;

	case 2:
		cout << "Podaj wartosc" << endl;
		cin >> value;
		tab.push_front(value);
		Tablica();
		break;

	case 3:
		cout << "Podaj wartosc" << endl;
		cin >> value;
		tab.push_back(value);
		Tablica();
		break;
		
	case 4:
		cout << "Podaj wartosc" << endl;
		cin >> value;
		cout << "Podaj index" << endl;
		cin >> index;
		if (index < tab.getSize() && index >= 0)
			tab.insertAt(index, value);
		else
		{
			cout << "Niepoprawny indeks" << endl;
			cin.ignore(2);
		}
		Tablica();
		break;

	case 5:
		if (tab.getSize() != 0)
			tab.pop_front();
		else
			cout << "Tablica jest pusta" << endl;
		cin.ignore(2);
		Tablica();
		break;

	case 6:
		if (tab.getSize() != 0)
			tab.pop_back();
		else
			cout << "Tablica jest pusta" << endl;
		cin.ignore(2);
		Tablica();
		break;

	case 7:
		if (tab.getSize() != 0)
		{
			cout << "Podaj index" << endl;
			cin >> index;
			if (index < tab.getSize() && index >= 0)
				tab.deleteAt(index);
			else
				cout << "Niepoprawny index" << endl;
		}
		else
			cout << "Tablica jest pusta" << endl;
		cin.ignore(2);
		Tablica();
		break;

	case 8:
		for (int i = 0; i < tab.getSize(); i++)
		{
			cout << "tab[" << i << "]= " << tab.get(i) << endl;
		}
		cin.ignore(2);
		Tablica();
		break;

	case 9:
		cout << "Wielkosc struktury: " << tab.getSize() << endl;
		cin.ignore(2);
		Tablica();
		break;

	case 10:
		if (tab.getSize() != 0)
		{
			cout << "Podaj wartosc:  " << endl;
			cin >> value;
			bool y=tab.searchValue(value);
			if (y)
				cout << "Wartosc istnieje" << endl;
			else
				cout << "Wartosc nie istnieje" << endl;
			cin.ignore(2);
		}
		Tablica();
	case 11:
		wybor();
		break;

	default:
		cout << "Niepoprawny wybor, sprobuj ponownie" << endl;
		cin.ignore(2);
		system("CLS");
		Tablica();
		break;
	}
}
void ListaDwukierunkowa()
{
	
	system("CLS");
	int i = 0, value = 0, index = 0;
	string namefile;
	cout << "Lista dwukierunkowa, dostepne operacje: " << endl;
	cout << "1. Wczytaj z pliku" << endl;
	cout << "2. Dodaj na poczatek listy" << endl;
	cout << "3. Dodaj na koniec listy" << endl;
	cout << "4. Dodaj wartosc na podanym indeksie" << endl;
	cout << "5. Usun wartosc z poczatku listy" << endl;
	cout << "6. Usun wartosc z konca listy" << endl;
	cout << "7. Usun wartosc z podanego indeksu listy" << endl;
	cout << "8. Wyswietl zawartosc listy" << endl;
	cout << "9. Wyswietl wielkosc struktury" << endl;
	cout << "10. Sprawdz czy wartosc istnieje w liscie" << endl;
	cout << "11. Wycofanie sie do glownego menu" << endl;
	cout << "Twoj wybor:";
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "Podaj nazwe pliku" << endl;
		cin >> namefile;
		lista.loadDataFromFile(namefile);
		ListaDwukierunkowa();
		break;

	case 2:
		cout << "Podaj wartosc" << endl;
		cin >> value;
		lista.push_front(value);
		ListaDwukierunkowa();
		break;

	case 3:
		cout << "Podaj wartosc" << endl;
		cin >> value;
		lista.push_back(value);
		ListaDwukierunkowa();
		break;

	case 4:
		cout << "Podaj wartosc" << endl;
		cin >> value;
		cout << "Podaj index" << endl;
		cin >> index;
		lista.push_inside(index, value);
		ListaDwukierunkowa();
		break;

	case 5:
		if (lista.getSize() != 0)
			lista.pop_front();
		else
		{
			cout << "lista jest pusta" << endl;
			cin.ignore(2); ///////////////////////////////////////////////////////////////////////
		}
		ListaDwukierunkowa();
		break;

	case 6:
		if(lista.getSize()!=0)
			lista.pop_back();
		else
		{
			cout << "lista jest pusta" << endl;
			cin.ignore(2);
		}
		ListaDwukierunkowa();
		break;

	case 7:
		if (lista.getSize() != 0)
		{
			cout << "Podaj index" << endl;
			cin >> index;
			if (index < lista.getSize() && index >= 0)
				lista.pop_inside(index);
			else
			{
				cout << "Niepoprawny index" << endl;
				cin.ignore(2);
			}
		}
		else
		{
			cout << "Lista jest pusta" << endl;
			cin.ignore(2);
		}
		ListaDwukierunkowa();
		break;

	case 8:
		for (int i = 0; i < lista.getSize(); i++)
		{
			cout << "list[" << i << "]= " << lista.get(i) << endl;
		}
		cin.ignore(2);
		ListaDwukierunkowa();
		break;

	case 9:
		cout << "Wielkosc struktury: " <<lista.getSize() << endl;
		cin.ignore(2);
		ListaDwukierunkowa();
		break;

	case 10:
		cout << "Podaj wartosc" << endl;
		cin >> value;
		lista.searchValue(value);
		cin.ignore(2);
		ListaDwukierunkowa();
		break;

	case 11:
		wybor();
		break;

	default:
		cout << "Niepoprawny wybor, sprobuj ponownie" << endl;
		cin.ignore(2);
		system("CLS");
		ListaDwukierunkowa();
		break;
	}
}
void Kopiec()
{
	system("CLS");
	int i = 0, value = 0, index = 0;
	std::string s[100];
	string namefile;
	cout << "Kopiec, dostepne operacje: " << endl;
	cout << "1. Wczytaj z pliku" << endl;
	cout << "2. Dodaj do kopca" << endl;
	cout << "3. Usun korzen kopca" << endl;
	cout << "4. Usun wartosc z podanego indeksu" << endl;
	cout << "5. Wyszukaj wartosc" << endl;
	cout << "6. Wyswietl zawartosc struktury" << endl;
	cout << "7. Wyswietl wielkosc struktury" << endl;
	cout << "8. Wycofanie sie do glownego menu" << endl;
	cout << "Twoj wybor:";
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "Podaj nazwe pliku" << endl;
		cin >> namefile;
		heap.loadDataFromFile(namefile);
		Kopiec();
		break;

	case 2:
		cout << "Podaj wartosc" << endl;
		cin >> value;
		heap.push(value);
		Kopiec();
		break;

	case 3:
		if(heap.getSize()!=0)
			heap.pop();
		else
		{
			cout << "Kopiec jest pusty" << endl;
			cin.ignore(2);
		}
		Kopiec();
		break;

	case 4:
		if (heap.getSize() != 0)
		{
			cout << "Podaj index" << endl;
			cin >> index;
			if (index < heap.getSize() && index >= 0)
				heap.deleteAt(index);
			else
			{
				cout << "Niepoprawny index" << endl;
				cin.ignore(2);
			}
		}
		else
		{
			cout << "Kopiec jest pusty" << endl;
			cin.ignore(2);
		}
		Kopiec();
		break;

	case 5:
		cout << "Podaj wartosc" << endl;
		cin >> value;
		index=heap.searchValue(0,value);
		if (index != -1)
			cout << "wartosc istnieje w kopcu" << endl;
		else
			cout << "wartosc nie istnieje w kopcu" << endl;
		cin.ignore(2);
		Kopiec();
		break;

	case 6:
		heap.print("","",0);
		cin.ignore(2);
		Kopiec();
		break;

	case 7:
		cout << "Wielkosc struktury: " << heap.getSize() << endl;
		cin.ignore(2);
		Kopiec();
		break;
	case 8:
		wybor();
		break;

	default:
		cout << "Niepoprawny wybor, sprobuj ponownie" << endl;
		cin.ignore(2);
		system("CLS");
		Kopiec();
		break;
	}
}
void Drzewo()
{
	system("CLS");
	int i = 0, value = 0, index = 0;
	std::string s[100];
	string namefile;
	cout << "Drzewo czerwono-czarne, dostepne operacje: " << endl;
	cout << "1. Wczytaj z pliku" << endl;
	cout << "2. Dodaj do drzewa" << endl;
	cout << "3. Usun wartosc z drzewa" << endl;
	cout << "4. Wyszukaj wartosc" << endl;
	cout << "5. Wyswietl zawartosc struktury" << endl;
	cout << "6. Wyswietl wielkosc struktury" << endl;
	cout << "7. Wycofanie sie do glownego menu" << endl;
	cout << "Twoj wybor:";
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "Podaj nazwe pliku" << endl;
		cin >> namefile;
		drzewo.loadDataFromFile(namefile);
		Drzewo();
		break;

	case 2:
		cout << "Podaj wartosc" << endl;
		cin >> value;
		drzewo.push(value);
		Drzewo();
		break;

	case 3:
		if (drzewo.getSize() != 0)
		{
			cout << "Podaj wartosc" << endl;
			cin >> value;
			drzewo.Remove(value);
		}
		else
		{
			cout << "Struktura jest pusta" << endl;
			cin.ignore(2);
		}
		Drzewo();
		break;

	case 4:
		cout << "Podaj wartosc" << endl;
		cin >> value;
		drzewo.searchValue(value);
		cin.ignore(2);
		Drzewo();
		break;

	case 5:
		drzewo.print("", "", drzewo.getRoot());
		cin.ignore(2);
		Drzewo();
		break;

	case 6:
		cout << "Wielkosc struktury: " << drzewo.getSize() << endl;
		cin.ignore(2);
		Drzewo();
		break;
	case 7:
		wybor();
		break;

	default:
		cout << "Niepoprawny wybor, sprobuj ponownie" << endl;
		cin.ignore(2);
		system("CLS");
		Drzewo();
		break;
	}
}
void wybor()
{
	system("CLS");
	int i = 0;
	cout << "---------------------------------" << endl;
	cout << "Hubert Wnukiewicz projekt SDiZO" << endl;
	cout << "---------------------------------" << endl;
	cout << "1.Stworzyc Tablice" << endl;
	cout << "2.Stworzenie listy dwukierunkowej" << endl;
	cout << "3.Stworzenie kopca" << endl;
	cout << "4.Stworzenie drzewa czerwono-czarnego" << endl;
	cout << "5.Zakonczenie pracy z programem" << endl;
	cout << "Twoj wybor: ";
	cin >> i;
	switch (i)
	{
	case 1:
		Tablica();
		break;
	case 2:
		ListaDwukierunkowa();
		break;
	case 3:
		Kopiec();
		break;
	case 4:
		Drzewo();
		break;
	case 5:
		return;
		break;
	default:
		cout << "Niepoprawny wybor, sprobuj ponownie" << endl;
		cin.ignore(2);
		system("CLS");
		wybor();
		break;
	}
}
int main()
{ 
 int i=0;
	do
	{
		wybor();
		
	} while (true);

	
	return 0;

} 


