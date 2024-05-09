//Оператор мобильной связи организовал базу данных абонентов, содержащую сведения о телефонах, их владельцах и 
//используемых тарифах, в виде бинарного дерева. Разработать программу, которая обеспечивает начальное формирование 
//базы данных в виде бинарного дерева; производит вывод всей базы данных; поиск владельца по номеру телефона; 
//выводит наиболее востребованный тариф (по наибольшему числу абонентов).

#include <iostream>
#include <Windows.h>
using namespace std;
struct Tree
{
	int key;
	char number[20];
	char surname[20];
	char tarif[20];
	int tar;
	Tree* Left, * Right;
};
enum Tarif
{
	Безлимит = 1,
	Непоседа,
	Бизнес
} oper;
int a = 0, m = 0, l = 0;

Tree* makeTree(Tree* Root);
Tree* list(int i, char* s, char* number, char* t, int tar);
Tree* insertElem(Tree* Root, int key, char* s, char* number, char* t, int tar);
void view(Tree* t, int level);
void search(Tree* n, char* number);
string popularTarif(Tree* n);
void delAll(Tree* t);


int c = 0;
int t1 = 0, t2 = 0, t3 = 0;
Tree* Root = NULL;
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int key, choice, n, tar;
	Tree* rc; char s[20], t[20], number[20];
	string ans;
	for (;;)
	{
		cout << "Меню: \n";
		cout << "1. Создание дерева\n";
		cout << "2. Добавление элемента\n";
		cout << "3. Вывод дерева\n";
		cout << "4. Поиск по номеру \n";
		cout << "5. Популярный тариф \n";
		cout << "6. Удаление дерева \n";
		cout << "7. Выход\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1: Root = makeTree(Root); break;
		case 2: cout << "\nвведите ключ: "; cin >> key;
			cout << "введите фамилию: "; cin >> s;
			cout << "введите номер: "; cin >> number;
			cout << "Выберите тариф: 1-Безлимит, 2-Непоседа, 3-Бизнес"; cin >> tar;
			insertElem(Root, key, s, number, t, tar); break;
		case 3: if (Root->key >= 0)
		{
			cout << "дерево :" << endl;
			view(Root, 0);
		}
			  else cout << "дерево пустое\n"; break;

		case 4: cout << "\nвведите номер: ";
			cin >> number;
			cout << "абонент:";
			search(Root, number);
			break;

		case 5:
			cout << "популярный тариф: ";
			if ((m > a && a > l) || (m > l && l > a))
				cout << "Безлимит" << endl;
			if ((a > m && m > l) || (a > l && l > m))
				cout << "Непоседа" << endl;
			if ((l > m && m > a) || (l > a && a > m))
				cout << "Бизнес" << endl;
			if (m == a && a > l)
				cout << "Безлимит и Непоседа" << endl;
			if (m == l && l > a)
				cout << "Безлимит и Бизнес" << endl;
			if (a == l && l > m)
				cout << "Непоседа и Бизнес" << endl;
			if (m == a && a == l)
				cout << "Безлимит, Непоседа и Бизнес" << endl;
			break;
		case 6: delAll(Root); break;

		case 7: exit(0);
		}
	}
}

Tree* makeTree(Tree* Root)
{
	int key, tar;
	char s[20], t[20], number[20];
	cout << "Конец ввода отрицательный ключ\n\n";
	if (Root == NULL)
	{
		cout << "введите ключ корня: "; cin >> key;
		cout << "введите фамилию абонента: "; cin >> s;
		cout << "введите номер абонента: "; cin >> number;
		cout << "Выберите тариф: 1-Безлимит, 2-Непоседа, 3-Бизнес "; cin >> tar;
		Root = list(key, s, number, t, tar);
	}
	while (1)
	{
		cout << "\nвведите ключ: "; cin >> key;
		if (key < 0) break;
		cout << "введите фамилию абонента: "; cin >> s;
		cout << "введите номер абонента: "; cin >> number;
		cout << "Выберите тариф: 1-Безлимит, 2-Непоседа, 3-Бизнес "; cin >> tar;
		insertElem(Root, key, s, number, t, tar);
	}
	return Root;
}

Tree* list(int i, char* s, char* number, char* t, int tr)
{
	Tree* tmp = new Tree[sizeof(Tree)];
	tmp->key = i;
	for (i = 0; i < 20; i++)
	{
		*((tmp->surname) + i) = *(s + i);


		*((tmp->number) + i) = *(number + i);


		*((tmp->tarif) + i) = *(t + i);
	}
	if (tr == 1)
		m++;
	if (tr == 2)
		a++;
	if (tr == 3)
		l++;

	tmp->tar = tr;
	tmp->Left = tmp->Right = NULL;
	return tmp;
}

Tree* insertElem(Tree* tmp, int key, char* s, char* number, char* t, int tar)
{
	Tree* Prev = tmp;
	int find = 0;
	while (tmp && !find)
	{
		Prev = tmp;
		if (key == tmp->key)
			find = 1;
		else
			if (key < tmp->key) tmp = tmp->Left;
			else tmp = tmp->Right;
	}
	if (!find)
	{
		tmp = list(key, s, number, t, tar);
		if (key < Prev->key)
			Prev->Left = tmp;
		else
			Prev->Right = tmp;
	}
	return tmp;
}



void view(Tree* t, int level)
{
	if (t)
	{
		view(t->Right, level + 1);
		for (int i = 0; i < level; i++)
			cout << " |";
		int tm = t->key;
		cout << tm << ' ';
		cout << t->surname << endl;
		cout << t->number << endl;
		if (t->tar == 1)
			cout << "Безлимит\n\n";
		if (t->tar == 2)
			cout << "Непоседа\n\n";
		if (t->tar == 3)
			cout << "Бизнес\n\n";

		view(t->Left, level + 1);
	}
}

void search(Tree* n, char* number)
{
	if (n != NULL)
	{
		if (strcmp(number, n->number) == 0)
		{
			cout << n->key << endl;
			cout << n->surname << endl;
			cout << n->number << endl;
		}
		else
			search(n->Left, number);
		search(n->Right, number);
	}

}


void delAll(Tree* t)
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}