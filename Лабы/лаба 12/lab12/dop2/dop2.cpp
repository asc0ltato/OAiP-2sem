//Реализуйте алгоритм сортировки слиянием и бинарной кучи и сравните производительность.
//Для этого сгенерируйте случайный набор чисел и отсортируйте его обоими алгоритмами.
//Замерьте время выполнения каждого алгоритма и сравните их между собой.

#include <iostream>
#include <vector>
#include <ctime>

#include <algorithm>

using namespace std;

// Сортировка слиянием
void merge(vector<int>& a, int l, int m, int r) {
	int i = l, j = m + 1, k = 0;
	vector<int> b(r - l + 1);
	while (i <= m && j <= r) {
		if (a[i] <= a[j]) {
			b[k] = a[i];
			i++;
		}
		else {
			b[k] = a[j];
			j++;
		}
		k++;
	}
	while (i <= m) {
		b[k] = a[i];
		i++;
		k++;
	}
	while (j <= r) {
		b[k] = a[j];
		j++;
		k++;
	}
	for (i = l; i <= r; i++) {
		a[i] = b[i - l];
	}
}

void mergeSort(vector<int>& a, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

// Бинарная куча
void siftDown(vector<int>& a, int i, int n) {
	int j = 2 * i + 1;
	if (j >= n) return;
	if (j + 1 < n && a[j + 1] > a[j]) j++;
	if (a[i] >= a[j]) return;
	swap(a[i], a[j]);
	siftDown(a, j, n);
}

void heapSort(vector<int>& a) {
	int n = a.size();
	for (int i = n / 2 - 1; i >= 0; i--) {
		siftDown(a, i, n);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		siftDown(a, 0, i);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
	cout << "Исходный массив: ";	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	clock_t start = clock();
	mergeSort(a, 0, n - 1);
	clock_t end = clock();
	cout << endl;
	cout << "Время сортировки слиянием: " << (end - start) << endl;
	start = clock();
	heapSort(a);
	end = clock();
	cout << endl;
	cout << "Время сортировки кучей: " << (end - start) << endl;
	system("pause");
	return 0;
}