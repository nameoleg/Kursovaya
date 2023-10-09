#include <iostream>
#include <Windows.h>
#include "EmployeeBase.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    EmployeeBase* eb = new EmployeeBase();
    eb->run();
}
