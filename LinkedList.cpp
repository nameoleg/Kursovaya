#include "LinkedList.h"

void LinkedList::clear()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current;
		current = current->next;
		delete temp;
	}
	head = nullptr;
}

void LinkedList::add(Employee* p) {
	Node* new_node = new Node(p);
	if (head == nullptr) {
		head = new_node;
		return;
	}
	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = new_node;
}

void LinkedList::LoadFromFile(string filename) {
	ifstream infile(filename);
	if (!infile) {
		throw runtime_error("Файл с данными не найден");
	}
	clear();
	string line;
	while (getline(infile, line)) {
		stringstream ss(line);
		string EmployeeId, EmployeeName, Job, MonthSalary, WorksDayInMonth, ReallyWorksDayInMonth, FinalSalary;
		getline(ss, EmployeeId, ';');
		getline(ss, EmployeeName, ';');
		getline(ss, Job, ';');
		getline(ss, MonthSalary, ';');
		getline(ss, WorksDayInMonth, ';');
		getline(ss, ReallyWorksDayInMonth, ';');
		getline(ss, FinalSalary);
		int id = stoi(EmployeeId);
		int ms = stoi(MonthSalary);
		int wdim = stoi(WorksDayInMonth);
		int rwdim = stoi(ReallyWorksDayInMonth);
		double fs = stod(FinalSalary);
		Employee* Employeer = new Employee(id, ms, wdim, rwdim, EmployeeName, Job, fs);
		add(Employeer);
	}
	infile.close();
}

void LinkedList::SaveToFile(string filename) {
	ofstream outfile(filename);
	if (!outfile) {
		throw runtime_error("Ошибка создания файла");
	}
	Node* current = head;

	while (current != nullptr) {
		outfile << current->data->getEmployeeId() << ";"
			<< current->data->getEmployeeName() << ";"
			<< current->data->getJob() << ";"
			<< current->data->getMonthSalary() << ";"
			<< current->data->getWorksDayInMonth() << ";"
			<< current->data->getReallyWorksDayInMonth() << ";"
			<< current->data->getFinalSalary() << endl;
		current = current->next;
	}
	outfile.close();
}

LinkedList* LinkedList::find(string field, string value) {
	LinkedList* result = new LinkedList();
	Node* current = head;
	while (current != nullptr)
	{
		if (field == "name" && current->data->getEmployeeName() == value)
		{
			result->add(current->data);
		}
		else if (field == "id" && current->data->getEmployeeId() == stoi(value))
		{
			result->add(current->data);
		}
		else if (field == "job" && current->data->getJob() == value)
		{
			result->add(current->data);
		}
		else if (field == "salary" && current->data->getMonthSalary() == stoi(value))
		{
			result->add(current->data);
		}
		else if (field == "finalSalary" && current->data->getFinalSalary() == stod(value))
		{
			result->add(current->data);
		}
		current = current->next;
	}
	if (result->isEmpty())
	{
		delete result;
		return nullptr;
	}
	return result;
}

int LinkedList::remove(string field, string value)
{
	int counter = 0;
	Node* to_delete = nullptr;
	if (field == "name")
	{
		while ((to_delete = findByEmployeeName(value)) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else if (field == "id")
	{
		while ((to_delete = findById(stoi(value))) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else if (field == "job")
	{
		while ((to_delete = findByJob((value))) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else if (field == "salary")
	{
		while ((to_delete = findBySalary(stoi(value))) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else if (field == "finalSalary")
	{
		while ((to_delete = findByFinalSalary(stod(value))) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else {
		cout << "Неверное поле: " << field << endl;
		return counter;
	}
}

void LinkedList::removeNode(Node* to_delete)
{
	if (head == to_delete)
	{
		head = head->next;
		delete to_delete;
		return;
	}
	Node* current = head;
	while (current->next != nullptr)
	{
		if (current->next == to_delete)
		{
			current->next = current->next->next;
			delete to_delete;
			return;
		}
		current = current->next;
	}
}

Node* LinkedList::findByEmployeeName(string name)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getEmployeeName() == name)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findById(int id)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getEmployeeId() == id)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findByJob(string job)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getJob() == job)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findBySalary(int salary)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getMonthSalary() == salary)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findByFinalSalary(double salary)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getFinalSalary() == salary)
			return current;
		current = current->next;
	}
	return nullptr;
}

int LinkedList::getSize() const
{
	Node* current = head;
	int result = 0;
	while (current != nullptr)
	{
		++result;
		current = current->next;
	}
	return result;
}

void LinkedList::sort(string field, bool ascending)
{
	int size = getSize();
	for (int i = 0; i < size - 1; ++i)
	{
		Node* current = head;
		for (int j = 0; j < size - 1 - i; ++j)
		{
			Node* next = current->next;
			if ((ascending && current->data->isGreaterThen(next->data, field)) || \
				(!ascending && current->data->isLessThen(next->data, field)))
			{
				Employee* temp = current->data;
				current->data = next->data;
				next->data = temp;
			}
			current = next;
		}
	}
}
