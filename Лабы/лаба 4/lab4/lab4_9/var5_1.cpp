//Скопировать из файла FILE1 в файл FILE2 строки, начиная с четвертой по порядку.Подсчитать количество символов в последнем слове FILE2.

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream input("FILE1.txt"); // открыть файл для чтения
    if (!input.is_open()) {
        cerr << "Ошибка открытия файла FILE1.txt" << endl;
        return 1;
    }

    ofstream output("FILE2.txt"); // создать файл для записи
    if (!output.is_open()) {
        cerr << "Ошибка создания файла FILE2.txt" << endl;
        return 1;
    }

    string line;
    int lineCount = 1;
    while (getline(input, line)) {
        if (lineCount >= 4) { // начиная с четвертой строки
            output << line << endl; // записать строку в FILE2
        }
        lineCount++;
    }

    input.close();
    output.close();

    // открыть FILE2 для чтения и подсчитать количество символов в последнем слове
    ifstream file2("FILE2.txt");
    if (!file2.is_open()) {
        cerr << "Ошибка открытия файла FILE2.txt" << endl;
        return 1;
    }

    string lastLine;
    while (getline(file2, line)) {
        lastLine = line; // сохранить последнюю строку
    }

    int lastWordLength = 0;
    for (int i = lastLine.length() - 1; i >= 0; i--) {
        if (lastLine[i] != ' ') {
            lastWordLength++;
        } else {
            break;
        }
    }

    cout << "Количество символов в последнем слове: " << lastWordLength << endl;

    file2.close();

    return 0;
}