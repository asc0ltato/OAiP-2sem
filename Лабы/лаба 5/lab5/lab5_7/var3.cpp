//Программа должна содержать меню с пунктами : добавление элемента, удаление элемента, поиск элемента, вывод списка в консольное окно, запись списка в файл,
//считывание списка из файла. Создать список, содержащий элементы целого типа. Найти сумму положительных элементов, кратных 5, или выдать сообщение,
//что таких элементов нет. 

#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

struct list
{
	int  number; //данные
	list* next; //указатель на следующий элемент
};

void insert(list*&, int); //функция добавления элемента, передается адрес спис-ка и символ, который добавляется 
int del(list*&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void searchList(list* p, int value);
void toFile(list*& p);         //Запись в файл
void fromFile(list*& p);       //Считывание из файла
void menu(void);     //функция, показывающая меню
void sum(list*);  //функция подсчета суммы чисел, больших 7  

int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list* first = NULL;
	int choice;
	int value;
	menu();    // вывести меню 
	cout << "Ваш выбор: ";
	cin >> choice;
	while (choice != 8)
	{
		switch (choice)
		{
		case 1:  	cout << "Введите число "; // добавить число в список
			cin >> value;
			insert(first, value);
			break;
		case 2:   if (!IsEmpty(first)) // удалить число из списка
		{
			cout << "Введите удаляемое число ";
			cin >> value;
			if (del(first, value))
			{
				cout << "Удалено число " << value << endl;
				printList(first);
			}
			else
				cout << "Число не найдено" << endl;
		}
			  else
			cout << "Список пуст" << endl;
			break;
		case 3: printList(first);
			break;
		case 4:
			int searchValue;
			cout << "Введите элемент, который нужно найти: " << endl;
			cin >> searchValue;
			searchList(first, searchValue);
			break;
		case 5:   toFile(first);
			break;
		case 6:  fromFile(first);
			break;
		case 7:   sum(first);	// вычисление суммы	
			break;
		default:  cout << "Неправильный выбор" << endl;
			menu();
			break;
		}
		cout << "Ваш выбор: ";
		cin >> choice;
	}
	cout << "Конец" << endl;
	return 0;
}

void menu(void)  //Вывод меню 
{
	cout << "Меню:" << endl;
	cout << " 1. Ввод элемента" << endl;
	cout << " 2. Удаление элемента" << endl;
	cout << " 3. Вывод cписка " << endl;
	cout << " 4. Поиск элемента" << endl;
	cout << " 5. Запись списка в файл" << endl;
	cout << " 6. Чтение списка из файла" << endl;
	cout << " 7. Найти сумму положительных элементов, кратных 5" << endl;
	cout << " 8. Выход" << endl;
}

void insert(list*& p, int value) //Добавление числа value в список 
{
	list* newP = new list;
	if (newP != NULL)     //есть ли место?  
	{
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}
int del(list*& p, int value)  // Удаление числа 
{
	list* previous, * current, * temp;
	if (value == p->number)
	{
		temp = p;
		p = p->next;    // отсоединить узел 
		delete temp;      //освободить отсоединенный узел 
		return value;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != value)
		{
			previous = current;
			current = current->next; // перейти к следующему 
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			free(temp);
			return value;
		}
	}
	return 0;
}

int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
	return p == NULL;
}

void printList(list* p)  //Вывод списка 
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void searchList(list* p, int value) {
	list* current = p;
	while (current != nullptr) {
		if (current->number == value) {
			cout << "Элемент найден " << endl;
			return;
		}
		current = current->next;
	}
	cout << "Элемент не найден " << endl;
}

void toFile(list*& p)
{
	list* temp = p;
	list buf;
	ofstream frm("List.txt");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл List.txt\n";
}

void fromFile(list*& p)          //Считывание из файла
{
	list buf, * first = nullptr;
	ifstream frm("List.txt");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char*)&buf, sizeof(list));
	while (!frm.eof())
	{
		insert(first, buf.number);
		cout << "-->" << buf.number;
		frm.read((char*)&buf, sizeof(list));
	}
	cout << "-->NULL" << endl;
	frm.close();
	p = first;
	cout << "\nСписок считан из файла List.txt\n";
}

void sum(list* p)
{
	int sm = 0;
	if (p == NULL) {
		cout << "Список пуст" << endl;
	}
	else
	{
		while (p != NULL)
		{
			if (p->number > 0 && p->number % 5 == 0)
				sm = sm + (p->number);
			p = p->next;
		}
		if (sm != 0) {
			cout << "Сумма положительных элементов, кратных 5: " << sm << endl;
		}
		else {
			cout << "Сумма положительных элементов, кратных 5, не найдена (таких элементов нет) " << endl;
		}
	}
}