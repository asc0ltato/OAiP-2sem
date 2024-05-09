//2. Создать текстовый файл F1 не менее, чем из 6 строк, и записать в него информацию.Скопировать в файл F2 только четные строки из F1.

#include <iostream>
#include <stdio.h>

using namespace std;

#pragma warning(disable: 4996)

int main() {
	setlocale(LC_ALL, "Russian");
	FILE* F1, * F2;
	char s[100];
	int i = 0;
	F1 = fopen("F1.txt", "r");
	F2 = fopen("F2.txt", "w");
	while (!feof(F1)) {
		fgets(s, 100, F1);
		if (i % 2 != 0) {
			fputs(s, F2);
		}
		i++;
	}
	fclose(F1);
	fclose(F2);
	cout << "Данные записаны в F2.txt " << endl;
	return 0;
}