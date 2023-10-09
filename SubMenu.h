#pragma once
#include "Menu.h"

using namespace std;

class SubMenu : public Menu
{
public:
	SubMenu(const string& title,
		bool isProtected) : Menu(title, isProtected) {}
	void add_item(Menu* menuItem) {
		items.push_back(menuItem);
	}
	void run() override;
	~SubMenu() {}
private:
	vector<Menu*> items;
};

