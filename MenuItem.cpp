#include "MenuItem.h"
#include <iostream>

void MenuItem::run()
{
	if (getProtected() && !getAccessGranted())
	{
		if (!this->checkPassword())
			return;
	}
	system("cls");
	cout << "|------------------------------------------------------|" << endl;
	cout << "\t\t" << title << endl;
	cout << "|------------------------------------------------------|" << endl;
	(action)();
}