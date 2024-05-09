#pragma once
struct Stack
{
	int data; //информационный элемент
	Stack* next; //указатель на следующий элемент
}; 

void push(Stack*& top, int data); // Добавление элемента
int pop(Stack*& top); // Извлечение элемента
void print(Stack* top); //
void createStack(Stack*& top, int n);
void createStacks(Stack*& top, Stack*& top1, Stack*& top2); //
void clear(Stack*& top); // Очистка стека 
void writeToFile(Stack* top, const char* fileName); // Cохранение в файл
void readFromFile(Stack*& top, const char* fileName); // Считывание из файла