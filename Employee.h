#pragma once
#include <string>

using namespace std;

class Employee
{
public:
	Employee(int EmployeeId, int MonthSalary, int WorksDayInMonth,
		int ReallyWorksDayInMonth, string EmployeeName,
		string Job, double FinalSalary) \
		: employeeId(EmployeeId), monthSalary(MonthSalary),
		worksDayInMonth(WorksDayInMonth), reallyWorksDayInMonth(ReallyWorksDayInMonth),
		employeeName(EmployeeName), job(Job), finalSalary(FinalSalary){};
	int getEmployeeId() const { return employeeId; }
	string getEmployeeName() const { return employeeName; }
	string getJob() const { return job; }
	int getMonthSalary() const { return monthSalary; }
	int getWorksDayInMonth() const { return worksDayInMonth; }
	int getReallyWorksDayInMonth() const { return reallyWorksDayInMonth; }
	double getFinalSalary() const { return finalSalary; }
	bool isGreaterThen(Employee* p, string field);
	bool isLessThen(Employee* p, string field);
private:
	int employeeId;
	string employeeName;
	string job;
	int monthSalary;
	int worksDayInMonth;
	int reallyWorksDayInMonth;
	double finalSalary;
};
