#pragma once
#include "Node.h"
#include "Employee.h"
#include <iostream>
#include <sstream>
#include <fstream>

class LinkedList
{
public:
	LinkedList() : head(nullptr) {};
	void clear();
	LinkedList* find(string field, string value);
	void add(Employee* p);
	void LoadFromFile(string filename);
	void SaveToFile(string filename);
	int remove(string field, string value);
	bool isEmpty() { return head == nullptr; }
	void sort(string fiel, bool ascending);
	int getSize() const;
	Node* head;
private:
	Node* findById(int id);
	Node* findByEmployeeName(string name);
	Node* findByJob(string job);
	Node* findBySalary(int salary);
	Node* findByFinalSalary(double salary);
	void removeNode(Node* to_detele);
};

