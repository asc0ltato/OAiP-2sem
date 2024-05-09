#pragma once
struct Queue
{
	int data;
	Queue* next;
};

void InputQueue(Queue*& first, Queue*& last, int n); //формирование элементов очереди
void OutputQueue(Queue* first);  //функция вывода элементов очереди 
void DeleteElement(Queue*& first, Queue*& last); // удаление элемемнта
int SizeQueue(Queue* first); //вывод размера очереди
void DeleteFirstNegativeElement(Queue*& first, Queue*& last); //функция удаления 1 отрицательного элемента