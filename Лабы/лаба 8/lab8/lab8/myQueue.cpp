#include <iostream>
#include "myQueue.h"

using namespace std;

// Функция для ввода очереди
void InputQueue(Queue*& first, Queue*& last, int n)
{
	for (int i = 0; i < n; i++) // по всем элементам проходим
	{
		Queue* temp = new Queue; // создаем новый эл очереди
		cout << "Введите элемент очереди: ";
		cin >> temp->data; // считывание значение элемента очереди с клавиатуры
		temp->next = NULL;	// указатель на следующий элемент в NULL
		if (first == NULL) { // если очередь пуста
			first = temp; // указатель на первый элемент на только что созданный элемент
			last = temp;// указатель на последний элемент на только что созданный элемент
		}
		else 
		{
			last->next = temp; //указатель последнего элемента на только что созданный элемент
			last = temp; //указатель на последний элемент на только что созданный элемент
		}
	}
}	

// Функция для вывода очереди
void OutputQueue(Queue* first)
{
	Queue* temp = first; // временный указатель на начало очереди
	while (temp != NULL) // пока очередь не закончится
	{
		cout << temp->data << " "; // выводим на экран значение текущего элемента очереди
		temp = temp->next; // переходим к следующему элементу
	}
	cout << endl;
}

// Функция для удаления элемента из очереди
void DeleteElement(Queue*& first, Queue*& last)
{
	Queue* temp = first;
	if (first == NULL)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		if (first == last) // если в очереди остался только один элемент
		{
			first = NULL; // указываем, что очередь теперь пуста
			last = NULL;
		}
		else
		{
			first = first->next; // переходим к следующему элементу 
		}
		delete temp; // удаляем первый элемент очереди
	}
}

// Функция для определения размера очереди
int SizeQueue(Queue* first)
{
	int size = 0;
	Queue* temp = first;
	while (temp != NULL)
	{
		size++; // подсчет текущего элемента
		temp = temp->next;
	}
	return size;
}

// Функция для удаления первого отрицательного элемента из очереди
void DeleteFirstNegativeElement(Queue*& first, Queue*& last)
{
	Queue* temp = first; //указывает на первый элемент
	Queue* prev = NULL; //указывает на предыдущий элемент
	while (temp != NULL) 
	{
		if (temp->data < 0)
		{
			if (temp == first)
			{
				DeleteElement(first, last);
				break;
			}
			else
			{
				prev->next = temp->next; // обновим следующий указатель предыдущего элемента, чтобы он указывал на следующий указатель текущего элемента
				delete temp; 
				break;
			}
		}
		prev = temp; //если данные не являются отрицательными, перейдем к следующему элементу в очереди
		temp = temp->next;
	}
}