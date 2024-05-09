#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

class Heap {
    static const int SIZE = 100; 
    int* h;         // указатель на массив кучи
    int HeapSize; 
public:
    Heap();  
    void addelem(int);  
    void outHeap();  
    int getmax();  
    void heapify(int);  
};

//Выделение динамической памятм для массива размером SIZE
Heap::Heap() {
    h = new int[SIZE];
    HeapSize = 0;
}

//Добавление элемента кучи
void Heap::addelem(int n) {
    int i, parent;
    i = HeapSize;
    h[i] = n;
    parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
        if (h[i] > h[parent]) {
            int temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
        }
        i = parent;
        parent = (i - 1) / 2;
    }
    HeapSize++;
}

//Вывод элементов кучи 
void Heap::outHeap(void) {
    int i = 0; //текущий элемент кучи
    int k = 1; //колво элементов на каждом уровне
    while (i < HeapSize) {
        while ((i < k) && (i < HeapSize)) {
            cout << h[i] << " ";
            i++;
        }
        cout << endl;
        k = k * 2 + 1;
    }
}

//Упорядочение кучи
void Heap::heapify(int i) {
    int left, right;
    int temp;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < HeapSize) {
        if (h[i] < h[left]) {
            temp = h[i];    
            h[i] = h[left];
            h[left] = temp;
            heapify(left);
        }
    }
    if (right < HeapSize) {
        if (h[i] < h[right]) {
            temp = h[i];
            h[i] = h[right];
            h[right] = temp;
            heapify(right);
        }
    }
}

//Удаление вершины (максимального элемента)
int Heap::getmax(void) {
    int x;
    x = h[0];
    h[0] = h[HeapSize - 1];
    HeapSize--;
    heapify(0); //для упорядочивания кучи
    return(x);
}

int main() {
    Heap heap;
    int k;
    srand(time(NULL));
    system("chcp 1251");
    system("cls");
    for (int i = 0; i < 16; i++) {
        k = rand() % 100 - 50;
        heap.addelem(k);
    }
    heap.outHeap();
    cout << endl;
    cout << endl << "Максимальный элемент: " << heap.getmax();
    cout << endl << "Новая куча: " << endl;
    heap.outHeap();
    cout << endl;
    cout << endl << "Максимальный элемент: " << heap.getmax();
    cout << endl << "Новая куча: " << endl;
    heap.outHeap();
    cout << endl;
    cin.get(); cin.get();
    return 0;
}