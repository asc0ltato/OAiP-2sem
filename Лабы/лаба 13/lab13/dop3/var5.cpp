//Ввести массивы А и В. В массив С перенести элементы массива А с четным значением и элементы массива В с нечетным значением.Массив С отсортировать по возрастанию, используя алгоритмы сортировок :
// «пузырек», сортировка выбором.

#include <iostream>
#include <ctime>
using namespace std;

//Пузырьковая сортировка(по возрастанию) - соседние элементы чисел сравниваются между собой. Если первый элемент больше второго, то они меняются местами. Затем сравниваются второй и третий элементы.
void BubbleSort(int arr[], int n) // a - массив, n - размер массива
{
	int i, j, t;
	for (i = 1; i < n; i++) // проходим по элементам массива от первого до предпоследнего
		for (j = n - 1; j >= i; j--) // проходим по элементам массива с конца до текущего индекса внешнего цикла
			if (arr[j - 1] > arr[j]) // если текущий элемент больше предыдущего, то меняем их местами
			{
				t = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = t;
			}
}


//Сортировка выбором(по возрастанию) - начиная с первой записи, осуществляется поиск элемента, имеющего наименьшее значение. После того, как этот элемент найден, он меняется местами с первым элементом.
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

//Генерация случайных чисел
int getRandKey(int reg = 0)
{
	if (reg > 0)
	srand((unsigned)time(NULL));
	int rmin = 0;
	int rmax = 100000;
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

	for (i = 0; i < SIZE; i++)	
	{
		if (A[i] % 2 == 0)
		{
			sizeC = sizeC + 1;
			C[sizeC] = A[i];
		}
		else if (B[i] % 2 == 1)
		{
			sizeC = sizeC + 1;
			C[sizeC] = B[i];
		}
	}
	cout << "Размер массива C: " << sizeC << endl;

	cout << "Пузырьковая сортировка(по возрастанию): " << endl;
	memcpy(test_arr, C, sizeC * sizeof(int));
	t1 = clock();
	selectSort(test_arr, sizeC);
	t2 = clock();
	cout << "Прошло " << t2 - t1 << " тактов времени" << endl;

	cout << "Сортировка выбором(по возрастанию): " << endl;
	memcpy(test_arr, C, sizeC * sizeof(int));
	t1 = clock();
	BubbleSort(test_arr, sizeC);
	t2 = clock();
	cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
	return 0;
}