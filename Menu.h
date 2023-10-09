#pragma once
#include <string>
#include <vector>

using namespace std;

class Menu
{
public:
	Menu(string Title, bool IsProtected) :
		title(Title), isProtected(IsProtected) {}
	string getTitle();
	virtual void run() = 0;
	bool getProtected() { return isProtected; }
	bool getAccessGranted() { return isAccessGranted; }
	virtual ~Menu() {}
protected:
	string title;
	string password = "123";
	bool isProtected;
	bool isAccessGranted = false;
	bool checkPassword();
};

