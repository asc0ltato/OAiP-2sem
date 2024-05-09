#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;

struct Sanatorium {
	string name;
	string location;
	string profile;
	int packages;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	const int s = 3;
	Sanatorium t[s];
	int change;
	int n = 0;
	for (int i = 0; i < s; i++) {
		cout << "Введите название санатория: ";
		cin >> t[i].name;
		cout << "Введите местоположение санатория: ";
		cin >> t[i].location;
		cout << "Введите лечебный профиль санатория: ";
		cin >> t[i].profile;
		cout << "Введите количество путевок: ";
		cin >> t[i].packages;
		cout << endl;
	} while (true) {
		cout << "\n1-Вывести весь список санаториев." << endl;
		cout << "2-Поиск санатория по профилю." << endl;
		cout << "3-Выход" << endl;
		cout << "Выберите действие: ";
		cin >> change;
		switch (change) {
		case 1:
			for (int i = 0; i < s - 1; i++) {
				for (int j = 0; j < s - i - 1; j++) {
					if (t[j].packages > t[j + 1].packages) {
						swap(t[j], t[j + 1]);
					}
				}
			}
			printf("|-------------------------------------------------------------------------------|\n");
			printf("| Санаторий | Место расположения | Лечебный профиль | Количество путевок |\n");
			printf("|-------------------------------------------------------------------------------|\n");
			for (int i = 0; i < s; i++) {
				printf("| %-10s | %-18s | %-17s | %-18d |\n", t[i].name.c_str(), t[i].location.c_str(), t[i].profile.c_str(), t[i].packages);
			}
		case 2:
			char profil[100];
			cout << "Введите лечебный профиль: ";
			cin >> profil;
			for (int i = 0; i < s; i++) {
				if (t[i].profile == profil) {
					cout << "Санаторий: " << t[i].name << endl;
					cout << "Местоположение: " << t[i].location << endl;
					cout << "Количество путевок: " << t[i].packages << endl;
					n++;
				}
			}
			if (n == 0) {
				cout << "Санаторий с таким профилем не найден." << endl;
			}
			break;

		case 3:exit(0);
		default: cout << "Можете просмотреть другие профили!";
		}
	}
	return 0;
}