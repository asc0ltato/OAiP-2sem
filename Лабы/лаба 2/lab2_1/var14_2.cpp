//Список клиентов гостиницы. Паспортные данные, даты приезда и отъезда, номер, тип размещения (люкс, одноместный, двухместный, трехместный, апартаменты). Поиск гостя по фамилии.

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Перечисление типов размещения
enum AccommodationType {
    LUXURY = 1,
    SINGLE,
    TWO,
    TRIPLE,
    APARTMENT
};

union AccommodationDetails {
    int roomNumber;
    int suiteNumber;
};

//Сам гость
struct HotelGuest {
    string firstName;
    string lastName;
    string passportNumber;
    string checkInDate;
    string checkOutDate;
    AccommodationType accommodationType;
    AccommodationDetails accommodationDetails;
};

// Ввод гостя
void inputGuest(HotelGuest& guest) {
    cout << "Введите фамилию: ";
    cin >> guest.lastName;
    cout << "Введите имя: ";
    cin >> guest.firstName;
    cout << "Введите номер паспорта: ";
    cin >> guest.passportNumber;
    cout << "Введите дату приезда(дд.мм.гг): ";
    cin >> guest.checkInDate;
    cout << "Введите дату отъезда(дд.мм.гг): ";
    cin >> guest.checkOutDate;
    cout << "Введите тип размещения (1 - Люкс, 2 - Одноместный, 3 - Двухместный, 4 - Трехместный, 5 - Апартаменты): ";
    int accommodationType;
    cin >> accommodationType;
    guest.accommodationType = static_cast<AccommodationType>(accommodationType);
    cout << "Введите номер комнаты: ";
    cin >> guest.accommodationDetails.suiteNumber;
}

// Вывод гостя
void outputGuest(const HotelGuest& guest) {
    cout << "Фамилия: " << guest.lastName << endl;
    cout << "Имя: " << guest.firstName << endl;
    cout << "Номер паспорта: " << guest.passportNumber << endl;
    cout << "Дата приезда: " << guest.checkInDate << endl;
    cout << "Дата отъезда: " << guest.checkOutDate << endl;
    cout << "Тип размещения: ";
    switch (guest.accommodationType) {
    case LUXURY:
        cout << "Люкс" << endl;
        break;
    case SINGLE:
        cout << "Одноместный" << endl;
        break;
    case TWO:
        cout << "Двухместный" << endl;
        break;
    case TRIPLE:
        cout << "Трехместный" << endl;
        break;
    case APARTMENT:
        cout << "Апартаменты" << endl;
        break;
    }
}

// Поиск по фамилии
void searchGuest(const HotelGuest guests[], int numGuests, const string& lastName) {
    for (int i = 0; i < numGuests; i++) {
        if (guests[i].lastName == lastName) {
            cout << "Гость найден:" << endl;
            outputGuest(guests[i]);
            return;
        }
    }
    cout << "Гость не найден." << endl;
}

//Главное меню
int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX_GUESTS = 10;
    HotelGuest guests[MAX_GUESTS];
    int numGuests = 0;
    bool done = false;

    while (!done) {
        cout << "Меню:" << endl;
        cout << "1. Добавить гостя" << endl;
        cout << "2. Найти гостя по фамилии" << endl;
        cout << "3. Выход из программы" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            if (numGuests < MAX_GUESTS) {
                inputGuest(guests[numGuests]);
                numGuests++;
            } else {
                cout << "Не удается добавить больше гостей. Достигнуто максимальное количество гостей." << endl;
            }
            break;
        case 2:
            if (numGuests > 0) {
                string lastName;
                cout << "Введите фамилию для поиска: ";
                cin >> lastName;
                searchGuest(guests, numGuests, lastName);
            } else {
                cout << "Таких гостей пока не добавлено." << endl;
            }
            break;
        case 3:
            done = true;
            break;
        default:
            cout << "Неверный выбор." << endl;
            break;
        }
    }
    return 0;
}