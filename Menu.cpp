#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

string Menu::getTitle() {
	return title;
}

bool Menu::checkPassword() {
	system("cls");
	string nativepassword;
	cout << "Для получения доступа введите пароль : ";
	cin >> nativepassword;
	if (nativepassword != password) {
		cout << "Доступ запрещен! Введен неправильный пароль, для продолжения нажмите любую кнопку...";
		getchar();
		getchar();
	}
	isAccessGranted = (nativepassword == password);
	return isAccessGranted;
}