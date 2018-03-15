// lab3saod.cpp: определяет точку входа для консольного приложения.
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
		cout << "������ �����, ���������� ��� ���!" << endl;
	}
}
//-------------------------------------------------------------------------
void add_card(card *&bus_park) {
	card *ptr = new card;
	cout << "������� ������� ��������: ";
	cin >> ptr->name_driv;
	cout << "������� ����� ��������: ";
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
	cout << "������� ����� ��������: "; my_cin(y);
	auto *time_ptr = &bus_park;
	for (; time_ptr; time_ptr = time_ptr->next)
		if (time_ptr->nym_bus == y)
			break;
		else if (!time_ptr->next) {
			cout << "������� ��� � " << y << " �� ���������\n";
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
				cout << "������� �� ��������.\n";
			}
			else if (x ==3) {
				time_ptr->condit = 1;
				time_ptr->nym_rout = rand() % 100;
				cout << "������� � �����.\n";
			}
}
//-------------------------------------------------------------------------
void show_bus_card(card *&bus_card) {
	int c;
	cout << "1 - ��������, ����������� � ����� \n2 - ��������, ����������� �� ��������\n ";
	my_cin(c);
	for (auto time_ptr(bus_card); time_ptr; time_ptr = time_ptr->next)
		if (c == 1 && time_ptr->condit)
			cout << "\n� ��������: " << time_ptr->nym_bus <<
			"\n��������: " << time_ptr->name_driv <<
			"\n� �������� " << time_ptr->nym_rout << endl;
		else if (c == 2 && !time_ptr->condit)
			cout << "\n� ��������: " << time_ptr->nym_bus <<
			"\n��������:" << time_ptr->name_driv << endl;
}
//-------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "Rus");
	card *bus_park(nullptr);
	int x(1);
	while (x) {
		cout << "//-----------------------------------------------------------------------\n";
		cout << "1. ��������� ������ ��������� � ���������.\n";
		cout << "2. ��������, ���������� �� �����.\n";
		cout << "3. ��������, ���������� � ����.\n";
		cout << "4. �������������� ���������.\n";
		cout << "0. �����\n";
		my_cin(x);
		cout << "//-----------------------------------------------------------------------\n";
		switch (x) {
		case 1:
			add_card(bus_park);
			break;
		case 2:
			if (bus_park) send_ret(*bus_park, x);
			else cout << "����� ������, ��������� ������!\n";
			break;
		case 3:
			if (bus_park) send_ret(*bus_park, x);
			else cout << "����� ������, ��������� ������!\n";
			break;
		case 4:
			if (bus_park) show_bus_card(bus_park);
			else cout << "����� ������, ��������� ������!\n";
			break;
		default:
			if (x)
				cout << "������� ����� �� 0 �� 4\n";
		}
	}
	return 0;
}