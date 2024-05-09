//Ввести массивы А и В. В массив С перенести те элементы массива А, которые больше минимального элемента массива В. Массив С отсортировать по убыванию, используя алгоритмы сортировок : шейкерная
//сортировка, сортировка Шелла.

#include <iostream>
#include <ctime>
using namespace std;

//Шейкерная сортировка(по убыванию) - перестановка элементов выполняется аналогично пузырьковой. При этом можно всякий последующий просмотр делать
//в противоположном направлении и фиксировать нижнюю и верхнюю границу в неупорядоченной части.Просмотр будет выполняться не до конца массива, а до последней перестановки на предыдущем просмотре.
void ShakerSort(int arr[], int n)
{
	int left = 0, right = n - 1;
    bool swapped = true;

    while (swapped) {
        swapped = false;
        // Проход слева направо
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        right--;
        // Проход справа налево
        for (int i = right; i >= left; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        left++;
    }
}

//Сортировка Шелла(по убыванию) - упорядоченный массив делится на группы элементов, каждая упорядочивается методом вставки. В процессе сортировки размеры таких групп увеличиваются до тех пор,
//пока все элементы не войдут в упорядоченную группу.
void ShellSort(int A[], int n)
{
	int buf;
	bool sort;
	for (int g = n / 2; g > 0; g /= 2)
		do
		{
			sort = false;
			for (int i = 0, j = g; j < n; i++, j++)
				if (A[i] < A[j])
				{
					sort = true;
					buf = A[i];
					A[i] = A[j];
					A[j] = buf;
				}
		} while (sort);
}

//Поиск минимального элемента массива
int min(int arr[], int size)
{
	int min = arr[0], i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

//Генерация случайных чисел 
int getRandKey(int reg = 0)
{
	if (reg > 0)
		srand((unsigned)time(NULL));
	int rmin = 0;
	int rmax = 10000;
	return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
}

int main()
{
	setlocale(LC_ALL, "Rus");
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

	int minB = min(B, SIZE);

	cout << "Минимальный элемент массива B: " << minB << endl;

	for (i = 0; i < SIZE; i++)
	{
		if (A[i] > minB)
		{
			sizeC++;
			C[sizeC] = A[i];
		}
	}

	cout << "Размер массива C: " << sizeC << endl;

	cout << "Шейкерная сортировка(по убыванию): ";
	memcpy(test_arr, C, sizeC * sizeof(int));
	t1 = clock();
	ShakerSort(test_arr, sizeC);
	t2 = clock();
	cout << "Прошло " << t2 - t1 << " тактов времени" << endl;

	cout << "Сортировка Шелла(по убыванию): ";
	memcpy(test_arr, C, sizeC * sizeof(int));
	t1 = clock();
	ShellSort(test_arr, sizeC);
	t2 = clock();
	cout << "Прошло " << t2 - t1 << " тактов времени" << endl;

	return 0;
}