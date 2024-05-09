//Во второй программе ввод информации с клавиатуры и вывод в консольное окно должно осуществляться в главной функции, а запись в файл и чтение из файла - в функциях пользователя.
//Встроенные функции для работы со строками не использовать.
//2. Ввести с клавиатуры две строки символов, состоящих из слов, разделенных пробелами, и записать их в файл. Прочитать из файла данные.
//Найти самое короткое слово в первой строке и самое длинное во вто-рой строке. Посчитать количество гласных букв в этих словах. 

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void writeToFile(const string& str1, const string& str2, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << str1 << endl;
        file << str2 << endl;
        file.close();
        cout << "Данные записаны в файл " << filename << endl;
    } else {
        cerr << "Ошибка записи в файл" << endl;
    }
}

void readFromFile(const string& filename, string& str1, string& str2) {
    ifstream file(filename);
    if (file.is_open()) {
        getline(file, str1);
        getline(file, str2);
        file.close();
        cout << "Данные прочитаны из файла " << filename << endl;
    } else {
        cerr << "Ошибка чтения из файла" << endl;
    }
}

string findShortestWord(const string& str) {
    string shortest = "";
    string current = "";
    for (char c : str) {
        if (c == ' ') {
            if (shortest.empty() || current.length() < shortest.length()) {
                shortest = current;
            }
            current = "";
        } else {
            current += c;
        }
    }
    if (!current.empty() && (shortest.empty() || current.length() < shortest.length())) {
        shortest = current;
    }
    return shortest;
}

string findLongestWord(const string& str) {
    string longest = "";
    string current = "";
    for (char c : str) {
        if (c == ' ') {
            if (current.length() > longest.length()) {
                longest = current;
            }
            current = "";
        } else {
            current += c;
        }
    }
    if (!current.empty() && current.length() > longest.length()) {
        longest = current;
    }
    return longest;
}

int countVowels(const string& str) {
    int count = 0;
    for (char c : str) {
        if (c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' || c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я') {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str1, str2;
    cout << "Введите первую строку: ";
    getline(cin, str1);
    cout << "Введите вторую строку: ";
    getline(cin, str2);

    writeToFile(str1, str2, "file.txt");

    string readStr1, readStr2;
    readFromFile("file.txt", readStr1, readStr2);

    string shortestWord = findShortestWord(readStr1);
    string longestWord = findLongestWord(readStr2);

    cout << "Самое короткое слово в первой строке: " << shortestWord << endl;
    cout << "Самое длинное слово во второй строке: " << longestWord << endl;
    cout << "Количество гласных букв в самом коротком слове первой строки: " << countVowels(shortestWord) << endl;
    cout << "Количество гласных букв в самом длинном слове второй строки: " << countVowels(longestWord) << endl;
    return 0;
}