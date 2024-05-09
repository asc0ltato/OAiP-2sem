//3. Дан массив из 10 элементов.Первые 4 элемента упорядочить по возрастанию, последние 4 по убыванию.

#include <iostream>
#include <ctime>
using namespace std;

//Определение границы между двумя подмассивами, которые будут рекурсивно сортироваться в функции sortHoar
int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm]; // равна 1 элементу подмассива 
	int buf;
	while (i < j) //проходы по массиву влево и вправо, чтобы найти элементы, которые нужно поменять местами
	{
		while (A[--j] > brd);
		while (A[++i] < brd);
		if (i < j) 
		{
			buf = A[j]; //найденные элементы меняются местами, пока проходы не сойдутся в середине массива
			A[j] = A[i];
			A[i] = buf;
		};
	} 
	return j; //возвращает индекс, кот делит массив на две части: элементы < brd находятся слева от него, а элементы >= brd - справа
}

//Разделяет массив на две части и сортируя каждую из них рекурсивно (в порядке возрастания)
int* sortHoar(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	return A;
};

//Определение границы между двумя подмассивами, которые будут рекурсивно сортироваться в функции sortHoar
int getHoarBordermm(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;	
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] < brd);
		while (A[++i] > brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}

//Разделяет массив на две части и сортируя каждую из них рекурсивно (в порядке убывания)
int* sortHoarmm(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBordermm(A, sm, em);
		sortHoarmm(A, sm, hb);
		sortHoarmm(A, hb + 1, em);
	}
	return A;
};

//Заполнение массива случайными числами и вывод массива на экран
int fill(int n, int a[])
{
	int min = 100;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 50;
		if ((i == 4) || (i == n - 4)) cout << "|";
		cout << a[i] << "  ";
	}
	return min;
}

//Вывод	отсортированного массива на экран
void print(int n, int a[])
{
	cout << "\nРезультирующий массив: ";
	for (int i=0; i < n; i++)
	{
		if ((i == 4)||(i==n-4)) cout << "|";
		cout << a[i] << "  ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int n;
	int B[100];
	cout << "Введите длину массива: "; cin >> n;

	cout << "sortHoar:";
	fill(n, B);
	sortHoar(B, 0, 4);
	sortHoarmm(B, n-4, n);
	print(n, B);
	cout << endl;

	return 0;
}