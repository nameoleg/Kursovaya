#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define BLACK "\033[1;30m"

#include "SubMenu.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void starbar(int width)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 48);
	for (int i = 0; i < width; ++i)
	{
		cout << BLACK << "*";
	}
	cout << RESET;
}

void SubMenu::run() {

	if (getProtected() && !getAccessGranted()) {
		if (!this->checkPassword())
			return;
	}

	while (true)
	{
		system("MODE CON COLS = 70 LINES=22");
		system("cls");
		system("Color F0");
		starbar(70);
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 254);
		cout << "\n";
		cout << "\t\t\t" << RED << title << BLACK << endl;
		starbar(70);
		SetConsoleTextAttribute(h, 254);
		cout << "\n";
		cout << GREEN << "Выберите действие:" << BLACK << endl;

		for (int i = 0; i < (int)items.size(); i++) {
			cout << i + 1 << ". " << items[i]->getTitle() << (items[i]->getProtected() ? " (*)" : "") << endl;
		}

		cout << "Введите номер (q для выхода): " << BLACK;

		string input;
		cin >> input;
		cin.ignore(100, '\n');
		if (input == "q")
		{
			break;
		}

		int choice = 0;
		try {
			choice = stoi(input);
		}
		catch (const invalid_argument&) {
			cout << "Неверный ввод\n";
			getchar();
			continue;
		}

		if (choice > 0 && choice <= (int)items.size()) {
			((Menu*)items[choice - 1])->run();
		}
		else {
			cout << "Неверный ввод\n";
			getchar();
		}
	}
}