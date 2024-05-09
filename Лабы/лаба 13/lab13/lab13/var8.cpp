//Ввести массивы А и В.В массив С перенести элементы массива А с нечетным значением и элементы массива В с нечетным значением.Массив С отсортировать по возрастанию, используя алгоритмы сортировок : 
//сортировка выбором, сортировка Шелла.

#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

//Сортировка выбором(по возрастанию) 
void selectSort(int A[], int size)
{
    int k, i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1, k = i; j < size; j++)
            if (A[j] < A[k])
                k = j;
        int c = A[k];
        A[k] = A[i];
        A[i] = c;
    }
}


//Сортировка Шелла(по возрастанию) 
void ShellSort(int A[], int n)
{
    int buf;
    bool sort;
    for (int g = n / 2; g > 0; g /= 2)
        do
        {
            sort = false;
            for (int i = 0, j = g; j < n; i++, j++)
                if (A[i] > A[j]) 
                {
                    sort = true;
                    buf = A[i];
                    A[i] = A[j];
                    A[j] = buf;
                }
        } while (sort);
}

//Генерация случайных чисел
int getRandKey(int reg = 0)
{
    if (reg > 0)
        srand((unsigned)time(NULL));
    int rmin = 0;
    int rmax = 100000;
    return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
}

int main() {
    setlocale(LC_ALL, "rus");
    const int SIZE = 1000; // Размеры массивов
    int  test_arr[SIZE]; // Будет использоваться для проверки выполнения сортировок
    clock_t t1, t2;
    int A[SIZE];
    int B[SIZE];
    int sizeC = 0, i;
    int* C = new int[SIZE];

    for (i = 0; i < SIZE; i++)
    {
        A[i] = getRandKey();
    }

    for (i = 0; i < SIZE; i++)
    {
        B[i] = getRandKey();
    }

    for (int i = 0; i < SIZE; i++) {
        if (A[i] % 2 == 1) {
            C[sizeC] = A[i];
            sizeC++;
        }
        else if (B[i] % 2 == 1) 
        {
            C[sizeC] = B[i];
            sizeC++;
        }
    }

    cout << "Размер массива C: " << sizeC << endl;

    cout << "Сортировка выбором(по возрастанию): " << endl;
    memcpy(test_arr, C, sizeC * sizeof(int));
    t1 = clock();
    selectSort(C, sizeC);
    t2 = clock();
    cout << "Прошло " << t2 - t1 << " тактов времени" << endl;

    cout << "Сортировка Шелла(по возрастанию) " << endl;
    memcpy(test_arr, C, sizeC * sizeof(int));
    t2 = clock();
    ShellSort(C, sizeC);
    t2 = clock();
    cout << "Прошло " << t2 - t1 << " тактов времени" << endl;

    return 0;
}