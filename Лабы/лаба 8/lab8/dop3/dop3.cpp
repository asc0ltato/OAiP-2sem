/*3. Содержимое текстового файла f, разделенное на строки, переписать в текстовый файл g, перенося при этом в конец каждой строки все входящие в нее цифры
(с сохранением исходного взаимного порядка, как среди цифр, так и среди остальных литер строки). Использовать очереди.*/

#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

struct Queue
{
    int size;
    Node* first;
    Node* last;
};

//Создание очереди
void creation(Queue* Q)
{
    Q->first = new Node;
    Q->first->next = NULL;
    Q->last = Q->first;
    Q->size = 0;
}

//Функция возвращает размер очереди
int size(Queue* Q)
{
    return Q->size;
}

//Функция проверяет, пуста ли очередь
bool isempty(Queue* Q)
{
    {	   return (Q->first->next == NULL);
    }
}

//Функция удаления первого элемента очереди
void clear_first(Queue* Q)
{
    if (isempty(Q)) // проверка, пуста ли очередь
        cout << "Очередь пуста" << endl;
    else
    {
        Node* temp = Q->first->next; // временный указатель на следующий узел первого узла
        Q->first->next = Q->first->next->next;
        delete temp;
    }
}

//Функция вывода элементов очереди и символов из буфера в файл
void print(Queue* Q, char buff[])
{
    ofstream fout("g.txt", ios::app); // открытие файла для записи (добавление в конец файла)
    for (int i = 0; i < strlen(buff); i++) // цикл по символам в буфере
    {
        if (buff[i] < '0' ||
            buff[i] > '9')
            fout << buff[i]; // запись символа в файл, если он не является цифрой
    }
    fout << ' ';
    if (isempty(Q) == true) // проверка, что очередь пуста
    {
        fout << '_';
        return;
    }
    else
    {
        Node* temp;
        temp = Q->first->next; // временный указатель на первый элемент в очереди
        for (int i = 0; i < size(Q); i++)
        {
            fout << temp->data;  // запись значения элемента в файл
            temp = temp->next; // переход к следующему элементу
        }
    }
    fout << '\n';
    fout.close();
}

//Добавляет элемент в конец очереди 
void add(Queue* Q, char value)
{
    Q->last->next = new Node;
    Q->last = Q->last->next;
    Q->last->data = value;
    Q->last->next = NULL;
    Q->size++;
}

//Удаляет все элементы очереди Q
void clear(Queue* Q)
{
    while (!isempty(Q)) clear_first(Q);
}


void main()
{
    setlocale(0, "");
    Queue Q;
    creation(&Q);
    char buff[50];
    ifstream fin("f.txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        while (fin.getline(buff, 50))
        {
            for (int i = 0; i < strlen(buff); i++)
            {
                if (buff[i] >= '0' &&
                    buff[i] <= '9')
                    add(&Q, buff[i]);
            }
            print(&Q, buff);
            clear(&Q);
            creation(&Q);
        }
        fin.close();

    }
}