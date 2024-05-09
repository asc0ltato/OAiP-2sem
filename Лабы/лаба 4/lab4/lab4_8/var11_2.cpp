//Во второй программе ввод информации с клавиатуры и вывод в консольное окно должно осуществляться в главной функции, а запись в файл и чтение из файла - в функциях пользователя.
//Встроенные функции для работы со строками не использовать.
//2. Ввести с клавиатуры строку символов, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл. Прочитать из файла данные и вывести нечетные числа строки. 

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void writeToFile(string str, string fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        file << str;
        file.close();
        cout << "Данные успешно записаны в файл." << endl;
    } else {
        cout << "Не удается открыть файл." << endl;
    }
}

void readFromFile(string fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string str;
        getline(file, str);
        file.close();
        cout << "Данные, считанные из файла: " << str << endl;

        // выводим нечетные числа строки
        string currentNum = "";
        for (char c : str) {
            if (c >= '0' && c <= '9') {
                currentNum += c;
            } else {
                if (currentNum != "") {
                    int num = stoi(currentNum);
                    if (num % 2 != 0) {
                        cout << num << endl;
                    }
                    currentNum = "";
                }
            }
        }
        // проверяем последнее число, если оно не было обработано
        if (currentNum != "") {
            int num = stoi(currentNum);
            if (num % 2 != 0) {
                cout << num << endl;
            }
        }
    } else {
        cout << "Не удается открыть файл." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string input;
    cout << "Введите строку цифр и слов, разделенных пробелами: " << endl;
    getline(cin, input);
    writeToFile(input, "FILE.txt");
    readFromFile("FILE.txt");

    return 0;
}