//2. Создать текстовый файл F1 не менее, чем из 5 строк, и записать в него информацию.Скопировать в файл F2 только строки из F1, которые начинаются с цифры.

#include<stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	FILE* file1;
	fopen_s(&file1, "F1.txt", "r");
	FILE* file2;
	fopen_s(&file2, "F2.txt", "w");//Открытие файлов

	char buff[255];
	while (!feof(file1)) {
		fgets(buff, 255, file1);
		if (buff[0] >= '0' && buff[0] <= '9') {
			fwrite(buff, strlen(buff), 1, file2); //Поиск строк, начинающихся с числа
		}
	}
	cout << "Данные записаны в F2"; //Вывод в другой файл.
	fclose(file1);
	fclose(file2);
}