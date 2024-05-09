#include <iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct Train {
    string destination;
    int number;
    int departure_time;
};

bool compareTrains(Train a, Train b) {
    return a.destination < b.destination;
}

int main() {
    setlocale(LC_ALL, "rus");
    Train trains[3];
    for (int i = 0; i < 3; i++) {
        cout << "Введите пункт назначения для поезда " << i + 1 << ": ";
        cin >> trains[i].destination;
        cout << "Введите номер поезда " << i + 1 << ": ";
        cin >> trains[i].number;
        cout << "Введите время отправления поезда " << i + 1 << ": ";
        cin >> trains[i].departure_time;
    }

    sort(trains, trains + 3, compareTrains); /*algorithm, нач. и кон. аргумент(итератор), функция - критерий сравнения */

    int input_time;
    cout << "Введите время для проверки поездов, отправляющихся после: ";
    cin >> input_time;

    bool has_departing_trains = false;
    for (int i = 0; i < 3; i++) {
        if (trains[i].departure_time > input_time) {
            has_departing_trains = true;
            cout << "Номер поезда " << trains[i].number << " " << trains[i].destination << " отправляется в " << trains[i].departure_time << endl;
        }
    }
        
    if (!has_departing_trains) {
        cout << "Поезда не отправляются позже указанного времени." << endl;
    }

    return 0;
}
