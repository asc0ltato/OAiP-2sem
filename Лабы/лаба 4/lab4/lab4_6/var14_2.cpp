//Во второй программе ввод информации с клавиатуры и вывод в консольное окно должно осуществляться в главной функции, а запись в файл и чтение из файла - в функциях пользователя.
//Встроенные функции для работы со строками не использовать.
//2. Ввести с клавиатуры строку символов, состоящую из слов, разделенных пробелами, и записать ее в файл.Прочитать из файла данные.
//Разбить строку на две подстроки, причем первая длиной k символов.Если на k - ю позицию попадает слово, то его следует отнести ко второй строке.
//мама папа я
#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>

using namespace std;

void writeToFile(const char* fileName, const char* str) {
    ofstream out(fileName);
    if (!out.is_open()) {
        cout << "Ошибка при открытии файла " << fileName << endl;
        return;
    }
    out << str;
    out.close();
}

char* readFromFile(const char* fileName) {
    ifstream in(fileName);
    if (!in.is_open()) {
        cout << "Ошибка при открытии файла " << fileName << endl;
        return NULL;
    }
    in.seekg(0, ios::end);
    int length = in.tellg();
    char* buffer = new char[length + 1];
    in.seekg(0, ios::beg);
    in.read(buffer, length);
    buffer[length] = '\0';
    in.close();
    return buffer;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);
    writeToFile("file.txt", str);
    char* fileData = readFromFile("file.txt");
    if (fileData == NULL) {
        return 1;
    }
    int k = 10;
    char first[100] = "";
    char second[100] = "";
    int i = 0;
    int j = 0;
    int wordLength = 0;
    bool isWord = false;
    while (fileData[i] != '\0') {
        if (fileData[i] == ' ') {
            if (!isWord) {
                first[j] = ' ';
            } else if (j < k) {
                first[j] = fileData[i];
            } else {
                second[j - k] = fileData[i];
            }
            isWord = false;
            wordLength = 0;
            j++;
        } else {
            if (j < k) {
                first[j] = fileData[i];
            } else {
                second[j - k] = fileData[i];
            }
            isWord = true;
            wordLength++;
            j++;
        }
        i++;
    }
    first[j] = '\0';
    second[j - k] = '\0';
    cout << "Первая подстрока: " << first << endl;
    cout << "Вторая подстрока: " << second << endl;
    delete[] fileData;
    return 0;
}