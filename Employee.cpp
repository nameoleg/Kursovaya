#include "Employee.h"

bool Employee::isGreaterThen(Employee* p, string field)
{
	if (field == "id")
	{
		return this->getEmployeeId() > p->getEmployeeId();
	}
	else if (field == "name")
	{
		return this->getEmployeeName() > p->getEmployeeName();
	}
	else if (field == "job")
	{
		return this->getJob() > p->getJob();
	}
	else if (field == "salary")
	{
		return this->getMonthSalary() > p->getMonthSalary();
	}
	else if (field == "finalSalary")
	{
		return this->getFinalSalary() > p->getFinalSalary();
	}
	else
	{
		return false;
	}
}

bool Employee::isLessThen(Employee* p, string field)
{
	if (field == "id")
	{
		return this->getEmployeeId() < p->getEmployeeId();
	}
	else if (field == "name")
	{
		return this->getEmployeeName() < p->getEmployeeName();
	}
	else if (field == "job")
	{
		return this->getJob() < p->getJob();
	}
	else if (field == "employee")
	{
		return this->getMonthSalary() < p->getMonthSalary();
	}
	else if (field == "finalSalary")
	{
		return this->getFinalSalary() < p->getFinalSalary();
	}
	else
	{
		return false;
	}
}