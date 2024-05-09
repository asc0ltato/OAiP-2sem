#include <iostream>
#include "heap.h"
using namespace std;
using namespace heap;

heap::CMP cmpAAA(void* a1, void* a2)
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP
        rc = heap::EQUAL;
    if (A1->x > A2->x)
        rc = heap::GREAT;
    else if (A2->x > A1->x)
        rc = heap::LESS;
    return rc;
#undef A2
#undef A1
}

int main()
{
    setlocale(LC_ALL, "rus");
    int k, choice, i;
    heap::Heap h1 = heap::create(30, cmpAAA);
    heap::Heap h2 = heap::create(30, cmpAAA);
    do
    {
        cout << "1 - вывод кучи 1 на экран\n";  //вывод кучи на экран
        cout << "2 - добавить элемент\n";
        cout << "3 - удалить максимальный элемент\n";
        cout << "4 - удалить минимальный элемент\n";
        cout << "5 - удалить i-ый элемент\n";
        cout << "6 - добавить элемент в кучу 2\n";
        cout << "7 - вывод кучи 2 на экран\n";
        cout << "8 - перенести элементы из 2 кучи в 1ую\n";
        cout << "0 - выход\n";
        cout << "сделайте выбор: "; cin >> choice;
        switch (choice)
        {
        case 0: break;
        case 1: h1.scan(0); break;
        case 2: {
            cout << "Отрицательное число - конец ввода" << endl;
            do {
                AAA* a = new AAA;
                cout << "Введите ключ" << endl;
                cin >> k;
                if (k <= 0)break;
                a->x = k;
                h1.insert(a);
            } while (k >= 0);
        }
              break;
        case 3: h1.extractMax(); break;
        case 4: h1.extractMin(); break;
        case 5: int i; cout << "Введите номер элемента: "; cin >> i; cout << endl; h1.extractI(i); break;
        case 6: {
            cout << "Отрицательное число - конец ввода" << endl;
            do {
                AAA* a = new AAA;
                cout << "Введите ключ" << endl;
                cin >> k;
                if (k <= 0)break;
                a->x = k;
                h2.insert(a);
            } while (k >= 0);
        }
              break;
        case 7: h2.scan(0); break;
        case 8: unionHeap(&h1, &h2); break;
        default: cout << endl << "Введена неверная команда!" << endl;
        }
    } while (choice != 0);
}
