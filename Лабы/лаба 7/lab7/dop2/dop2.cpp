//Создать стек с целочисленным информационным полем.Заполнить его длинами строк, считанных из файла.
//Распечатать на экране содержимое стека.Указать номер и длину последней самой короткой строки файла.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Stack
{
	int info;
	Stack* next;
};

void push(Stack*& top, int x)
{
	Stack* p = new Stack;
	p->info = x;
	p->next = top;
	top = p;
}

int pop(Stack*& top)
{
	if (top == NULL)
	{
		cout << "Стек пуст" << endl;
		return 0;
	}
	int x = top->info;
	Stack* p = top;
	top = top->next;
	delete p;
	return x;
}

void print(Stack* top)
{
	Stack* p = top;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Stack* top = NULL;
	ifstream fin("txt.txt");
	string s;
	int i = 0;
	int min = 1000;
	int min_i = 0;
	while (!fin.eof())
	{
		getline(fin, s);
		push(top, s.length());
		if (s.length() < min)
		{
			min = s.length();
			min_i = i;
		}
		i++;
	}
	// Распечатать текст с файла
	fin.close();
	fin.open("txt.txt");
	while (!fin.eof())
	{
		getline(fin, s);
		cout << s << endl;
	}
	fin.close();
	cout << endl << "Длины строк: " << endl;
	print(top);
	cout << "\nНомер последней самой короткой строки: " << min_i + 1 << endl;
	cout << "Длина последней самой короткой строки: " << min << endl;

	return 0;
}