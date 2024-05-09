// По заданному числу n определить символ, который стоит на n - ом месте последовательности, получившейся после шага c номером 26.
#include <iostream>
#include <windows.h>
using namespace std;

//Функция вычисляет значение, результата увеличивая его на заданный shag, пока count не станет = введенному n
int recursion(int n, int shag, int count, int result = 0) {
	if (count < n) {
		result += shag; // добавляем значение шага к рез
		count++;
		return recursion(n, shag, count, result);
	}
	if (count == n) {
		result += shag;
		return result;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, shag = 25, counter = 0, result;
	cout << "Введите N: ";
	cin >> n;
	result = recursion(n, shag, counter);
	cout << "Символ: " << (char)result;
	return 0;
}