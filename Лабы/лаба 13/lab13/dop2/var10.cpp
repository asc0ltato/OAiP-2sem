//Ввести массивы А и В. В массив С перенести те элементы массива А, которые больше максимального элемента массива В.Массив С отсортировать по убыванию, используя алгоритмы сортировок : «пузырек», 
//в сортировка простой вставкой.

#include <iostream>
#include <ctime>
using namespace std;
 
//Пузырьковая сортировка(по убыванию) - соседние элементы чисел сравниваются между собой. Если первый элемент больше второго, то они меняются местами. Затем сравниваются второй и третий элементы.
void BubbleSort(int arr[], int n) // a - массив, n - размер массива
{
	int i, j, t;
	for (i = 1; i < n; i++) // проходим по элементам массива от первого до предпоследнего
		for (j = n - 1; j >= i; j--) // проходим по элементам массива с конца до текущего индекса внешнего цикла
			if (arr[j - 1] < arr[j]) // если текущий элемент больше предыдущего, то меняем их местами
			{
				t = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = t;
			}
}

//Сортировка простой вставкой(по убыванию)  - есь массив в процессе сортировки делится на две части: упорядоченную и неупорядоченную. Вначале весь массив неупорядочен.На каждом шаге из неупорядоченной
//части извлекается первый элемент, который вставляется на нужное место упорядоченной части.При этом размер упорядоченной части увеличивается на единицу.
void InsertSort(int *arr, int size) 
{
	int temp, 
		item; //Индекс предыдущего элемента
	for (int i = 1; i < size; i++)
	{
		temp = arr[i]; 
		item = i - 1; // Запоминаем индекс предыдущего элемента массива
		while (item >= 0 && arr[item] < temp) // Пока индекс не равен 0 и предыдущий элемент массива меньше текущего
		{
			arr[item + 1] = arr[item]; // Перестановка элементов массива
			arr[item] = temp;
			item--;
		}
	}
}

//Поиск максимального элемента массива
int max(int arr[], int size)
{
	int max = arr[0], i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
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

	int maxB = max(B, SIZE);

	cout << "Максимальный элемент массива B: " << maxB << endl;

	for (i = 0; i < SIZE; i++)
	{
		if (A[i] > maxB)
		{
			sizeC++;
			C[sizeC] = A[i];
		}
	}

	cout << "Размер массива C: " << sizeC << endl;

	cout << "Пузырьковая сортировка(по убыванию): " << endl;
	memcpy(test_arr, B, sizeC * sizeof(int));
	t1 = clock();
	InsertSort(test_arr, sizeC);
	t2 = clock();
	cout << "Прошло " << t2 - t1 << " тактов времени" << endl;

	cout << "Сортировка простой вставкой(по убыванию)  " << endl;
	memcpy(test_arr, B, sizeC * sizeof(int));
	t1 = clock();
	BubbleSort(test_arr, sizeC);
	t2 = clock();
	cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
}
