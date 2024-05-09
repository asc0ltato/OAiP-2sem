#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "myStack.h"

using namespace std;

void push(Stack*& top, int data) // Добавление элемента
{
	Stack* temp = new Stack; //выделение памяти для нового элемента
	temp->data = data; // значение помещается в стек   
	temp->next = top;
	top = temp;
}

int pop(Stack*& top) // Извлечение элемента
{
	int data = top->data;
	Stack* temp = top;
	top = top->next; // вершиной становится предшествующий элемент
	delete temp; // освобождается память 
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
		if (top->data > 50)
		{
			push(top1, pop(top));
		}
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