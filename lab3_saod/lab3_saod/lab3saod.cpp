// lab3saod.cpp: РѕРїСЂРµРґРµР»СЏРµС‚ С‚РѕС‡РєСѓ РІС…РѕРґР° РґР»СЏ РєРѕРЅСЃРѕР»СЊРЅРѕРіРѕ РїСЂРёР»РѕР¶РµРЅРёСЏ.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
struct card {
	int nym_bus, nym_rout;
	bool condit;
	string name_driv;
	card *next;
};
//-------------------------------------------------------------------------
void my_cin(int &z) {
	while (!(cin >> z) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода, попробуйте еще раз!" << endl;
	}
}
//-------------------------------------------------------------------------
void add_card(card *&bus_park) {
	card *ptr = new card;
	cout << "Введите фамилию водителя: ";
	cin >> ptr->name_driv;
	cout << "Введите номер автобуса: ";
	my_cin(ptr->nym_bus);
	ptr->nym_rout = ptr->condit = 0;
	ptr->next = nullptr;
	if (bus_park) {
		for (auto ptr2 = bus_park;; ptr2 = ptr2->next)
			if (!ptr2->next) {
				ptr2->next = ptr;
				break;
			}
	}
	else
		bus_park = ptr;
}
//-------------------------------------------------------------------------
void send_ret(card &bus_park, int x) {
	int y;
	cout << "Введите номер автобуса: "; my_cin(y);
	auto *time_ptr = &bus_park;
	for (; time_ptr; time_ptr = time_ptr->next)
		if (time_ptr->nym_bus == y)
			break;
		else if (!time_ptr->next) {
			cout << "Автобус под № " << y << " не обнаружен\n";
			return;
		}
		/*if (x == 2 && time_ptr->condit || x == 3 && !time_ptr->condit) {
			if (x == 2)
				cout << "(error) The bus is on the route.\n";
			else
				cout << "(error) The bus is in park.\n";
			return;
		}
		else*/
			if (x == 2) {
				time_ptr->condit = 0;
				cout << "Автобус на маршруте.\n";
			}
			else if (x ==3) {
				time_ptr->condit = 1;
				time_ptr->nym_rout = rand() % 100;
				cout << "Автобус в парке.\n";
			}
}
//-------------------------------------------------------------------------
void show_bus_card(card *&bus_card) {
	int c;
	cout << "1 - автобусы, находящиеся в парке \n2 - автобусы, находящиеся на маршруте\n ";
	my_cin(c);
	for (auto time_ptr(bus_card); time_ptr; time_ptr = time_ptr->next)
		if (c == 1 && time_ptr->condit)
			cout << "\n№ автобуса: " << time_ptr->nym_bus <<
			"\nВодитель: " << time_ptr->name_driv <<
			"\n№ маршрута " << time_ptr->nym_rout << endl;
		else if (c == 2 && !time_ptr->condit)
			cout << "\n№ автобуса: " << time_ptr->nym_bus <<
			"\nВодитель:" << time_ptr->name_driv << endl;
}
//-------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "Rus");
	card *bus_park(nullptr);
	int x(1);
	while (x) {
		cout << "//-----------------------------------------------------------------------\n";
		cout << "1. Заполнить список водителей и автобусов.\n";
		cout << "2. Автобусы, выезжающие из парка.\n";
		cout << "3. Автобусы, въезжающие в парк.\n";
		cout << "4. Местоположение автобусов.\n";
		cout << "0. Выход\n";
		my_cin(x);
		cout << "//-----------------------------------------------------------------------\n";
		switch (x) {
		case 1:
			add_card(bus_park);
			break;
		case 2:
			if (bus_park) send_ret(*bus_park, x);
			else cout << "Чтобы начать, заполните список!\n";
			break;
		case 3:
			if (bus_park) send_ret(*bus_park, x);
			else cout << "Чтобы начать, заполните список!\n";
			break;
		case 4:
			if (bus_park) show_bus_card(bus_park);
			else cout << "Чтобы начать, заполните список!\n";
			break;
		default:
			if (x)
				cout << "Введите номер от 0 до 4\n";
		}
	}
	return 0;
}