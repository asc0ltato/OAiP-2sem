//N человек  располагаются  по кругу.Начав отсчет от первого, удаляют каждого k - го, смыкая круг после удаления.
//Определить порядок удаления людей из круга.Использовать линейный список.

#include <iostream>
#include <Windows.h>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

// Функция вывода списка
void printList(Node* head)
{
	Node* current = head;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

// Функция удаления элемента из списка
void deleteNode(Node* head, int k)
{
	Node* current = head;
	Node* previous = NULL;
	while (current != NULL)
	{
		if (current->data == k)
		{
			if (previous == NULL)
			{
				head = current->next;
				delete current;
				current = head;
			}
			else
			{
				previous->next = current->next;
				delete current;
				current = previous->next;
			}
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N, k;
	cout << "Введите количество людей: ";
	cin >> N;
	cout << "Введите k: ";
	cin >> k;

	Node* head = NULL;
	Node* current = NULL;
	Node* previous = NULL;

	// Создание списка
	for (int i = 1; i <= N; i++)
	{
		current = new Node;
		current->data = i;
		current->next = NULL;
		if (head == NULL)
		{
			head = current;
		}
		else
		{
			previous->next = current;
		}
		previous = current;
	}
	current->next = head;

	// Удаление элементов из списка и вывод удаленных элементов
	cout << "Порядок удаления людей из круга: ";
	while (head != head->next)
	{
		for (int i = 1; i < k; i++)
		{
			previous = head;
			head = head->next;
		}
		cout << head->data << " ";
		previous->next = head->next;
		delete head;
		head = previous->next;
	}
	cout << endl;

	// Вывод оставшегося элемента
	cout << "Оставшийся человек: " << head->data << endl;

	return 0;
}