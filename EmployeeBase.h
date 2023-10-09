#pragma once
#include "SubMenu.h"
#include "MenuItem.h"
#include "LinkedList.h"
#include "Employee.h"
#include "SaveFormat.h"
#include "JsonFormat.h"
#include "XmlFormat.h"
#include <iostream>
#include <sstream>
#include <locale>
#include <regex>
#include <limits>
#include <codecvt>

class EmployeeBase
{
public:
	EmployeeBase();
	void run();
	~EmployeeBase();
private:
	LinkedList* EmployeeList;
	void addEmployee();

	void findEmployeeById();
	void findByEmployeeName();
	void findByJob();
	void findBySalary();
	void findByFinalSalary();
	void removeEmployeeById();
	void removeByEmployeeName();
	void removeByJob();
	void removeBySalary();
	void removeByFinalSalary();
	void sortEmployeeByIdAsc();
	void sortEmployeeByIdDesc();
	void sortByEmployeeNameAsc();
	void sortByEmployeeNameDesc();
	void sortByJobAsc();
	void sortByJobDesc();
	void sortBySalaryAsc();
	void sortBySalaryDesc();
	void sortByFinalSalaryAsc();
	void sortByFinalSalaryDesc();

	void exportEmployeeListToJson();
	void exportEmployeeListToXML();
	void exportEmployeeListToCSV();

	void importEmployee();
	void printResult(LinkedList* EmployeeList);
	void showEmployeeList();
	const string EmployeeBaseFile = "EmployeeData.csv";
};