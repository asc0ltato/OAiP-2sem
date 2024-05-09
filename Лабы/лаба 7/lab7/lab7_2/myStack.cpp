#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "myStack.h"

using namespace std;

void push(Stack*& top, int data)
{
	Stack* temp = new Stack;
	temp->data = data;
	temp->next = top;
	top = temp;
}

int pop(Stack*& top)
{
	int data = top->data;
	Stack* temp = top;
	top = top->next;
	delete temp;
	return data;
}

void print(Stack* top)
{
	while (top)
	{
		cout << top->data << " ";
		top = top->next;
	}
	cout << endl;
}

void createStack(Stack*& top, int n)
{
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		push(top, data);
	}
}

void createStacks(Stack*& top, Stack*& top1, Stack*& top2)
{
	while (top)
	{
		// Если элемент положительное или 0, то поместить его в первый стек
		if (top->data >= 0)
		{
			push(top1, pop(top));
		}
		// Если элемент отрицательное, то поместить его во второй стек
		else
		{
			push(top2, pop(top));
		}
	}
	cout << "Два стека успешно созданы\n";
}

// Функция clear() - очистка стека
void clear(Stack*& top)
{
	while (top)
	{
		pop(top);
	}
	cout << "Стек успешно очищен\n";
}

// Функция записи стека в файл
void writeToFile(Stack* top, const char* fileName)
{
	// Записать данные в текстовом виде
	ofstream fout(fileName);
	if (fout.is_open())
	{
		while (top)
		{
			fout << top->data << " ";
			top = top->next;
		}
		fout.close();
		cout << "Данные успешно записаны\n";
	}
	else {
		cout << "Не удалось записать данные\n";
	}
}

// Функция чтения стека из файла
void readFromFile(Stack*& top, const char* fileName)
{
	// Чтение данных из текстового файла
	ifstream fin(fileName);
	if (fin.is_open())
	{
		int data;
		while (fin >> data)
		{
			push(top, data);
		}
		fin.close();
		cout << "Данные успешно прочитаны\n";
	}
	else {
		cout << "Не удалось прочесть данные\n";
	}
}