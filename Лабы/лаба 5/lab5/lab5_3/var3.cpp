//Программа должна содержать меню с пунктами : добавление элемента, удаление элемента, поиск элемента, вывод списка в консольное окно, запись списка в файл,
//считывание списка из файла. Создать список, содержащий элементы целого типа. Найти сумму положительных элементов, кратных 5, или выдать сообщение,
//что таких элементов нет. 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

//Добавляем элемент в конец списка
void addElement(vector<int>& list) {
    int value;
    cout << "Введите значение элемента: ";
    cin >> value;
    list.push_back(value);
    cout << "Элемент успешно добавлен в список." << endl;
}

//Удаляем элемент из списка
void removeElement(vector<int>& list) {
    if (list.empty()) {
        cout << "Список пуст, поиск невозможен." << endl;
        return;
    }
    int value;
    cout << "Введите значение элемента, который нужно удалить: ";
    cin >> value;
    int index;
    cout << "Введите индекс удаляемого элемента: ";
    cin >> index;
    if (index < 0 || index >= list.size()) {
        cout << "Недопустимый индекс." << endl;
        return;
    }
    list.erase(list.begin() + index);
    cout << "Элемент успешно удален из списка." << endl;
}

//Поиск элемента в списке
void searchElement(const vector<int>& list) {
    if (list.empty()) {
        cout << "Список пуст, поиск невозможен." << endl;
        return;
    }
    int value;
    cout << "Введите значение искомого элемента: ";
    cin >> value;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == value) {
            cout << "Элемент найден в позиции " << i << endl;
            return;
        }
    }
    cout << "Элемент не найден в списке." << endl;
}

//Выводим список в консольное окно
void printList(const vector<int>& list) {
    if (list.empty()) {
        cout << "Список пуст." << endl;
        return;
    }
    cout << "Список: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

//Запись списка в файл
void writeListToFile(const vector<int>& list) {
    if (list.empty()) {
        cout << "Список пуст, запись невозможна." << endl;
        return;
    }
    string fileName;
    cout << "Введите имя файла для записи: ";
    cin >> fileName;
    ofstream outFile(fileName);
    if (!outFile) {
        cout << "Не удалось открыть файл для записи." << endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        outFile << list[i] << endl;
    }
    outFile.close();
    cout << "Список успешно записан в файл." << endl;
}

//Cчитывание списка из файла
void readListFromFile(vector<int>& list) {
    string fileName;
    string line;
    cout << "Введите имя файла для чтения: ";
    cin >> fileName;
    ifstream inFile(fileName);
    if (!inFile) {
        cout << "Не удалось открыть файл для чтения." << endl;
        return;
    }
    if (inFile.is_open()) { //проверить, был ли файл открыт успешно
        while (getline(inFile, line)) { //читать строки файла по очереди
            cout << line << '\n'; //вывести текущую строку в консоль
        }
        inFile.close();
    }
}

//Находим сумму положительных элементов, кратных 5
void sum_positive_multiples_of_five(const vector<int>& list) {
    int sum = 0;
    bool has_multiples_of_five = false;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] > 0 && list[i] % 5 == 0) {
            sum += list[i];
            has_multiples_of_five = true;
        }
    }
    if (has_multiples_of_five) {
        cout << "Сумма положительных элементов, кратных 5, равна " << sum << endl;
    }
    else {
        cout << "Нет элементов, удовлетворяшим условием" << endl;
    }
}

//Меню
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    vector<int> list; //создаем пустой список
    int choice;
    string fileName;
    do { //// выводим меню
        cout << "Меню:" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Найти элемент" << endl;
        cout << "4. Вывести список" << endl;
        cout << "5. Записать список в файл" << endl;
        cout << "6. Вывести список из файла" << endl;
        cout << "7. Найти сумму положительных элементов, кратных 5" << endl;
        cout << "8. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addElement(list);
            break;
        case 2:
            removeElement(list);
            break;
        case 3:
            searchElement(list);
            break;
        case 4:
            printList(list);
            break;
        case 5:
            writeListToFile(list);
            break;
        case 6:
            readListFromFile(list);
            break;
        case 7:
            sum_positive_multiples_of_five(list);
            break;
        case 8:
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Неверный выбор." << endl;
            break;
        }
    } while (choice != 8);
    return 0;
}