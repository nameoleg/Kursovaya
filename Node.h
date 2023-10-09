#pragma once
#include "Employee.h"

class Node
{
public:
	Employee* data;
	Node* next;
	Node(Employee* p) : data(p), next(nullptr) {}
	~Node();
};