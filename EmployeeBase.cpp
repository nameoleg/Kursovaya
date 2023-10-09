#include "EmployeeBase.h"
#include "LinkedList.h"

EmployeeBase::EmployeeBase()
{
	EmployeeList = new LinkedList();
	try
	{
		EmployeeList->LoadFromFile(EmployeeBaseFile);
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}
EmployeeBase::~EmployeeBase()
{
	try
	{
		EmployeeList->SaveToFile(EmployeeBaseFile);
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	EmployeeList->clear();
	delete EmployeeList;
}

void EmployeeBase::addEmployee() {
	int EmployeeId, WorksDayInMonth, ReallyWorksDayInMonth, MonthSalary;
	string EmployeeName, Job;
	cout << "������� ���������� ����� ���������: ";
	cin >> EmployeeId;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "������� ��� ���������: ";
	getline(cin, EmployeeName);
	cout << "������� ��������� ���������: ";
	getline(cin, Job);
	cout << "������� �������� ����� ���������: ";
	cin >> MonthSalary;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "������� ���������� ��������������� ������� ����: ";
	cin >> WorksDayInMonth;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "������� ���������� �������� ������������ ����: ";
	cin >> ReallyWorksDayInMonth;

	double FinalSalary = (double)MonthSalary * 
		((double)ReallyWorksDayInMonth / (double)WorksDayInMonth);

	Employee* Employeer = new Employee(EmployeeId, MonthSalary,
		WorksDayInMonth, ReallyWorksDayInMonth, EmployeeName, Job, FinalSalary);
	EmployeeList->add(Employeer);
}

void EmployeeBase::importEmployee() {
	string filename;
	cout << "������� ���� � �����: ";
	cin >> filename;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	try {
		EmployeeList->LoadFromFile(filename);
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		getchar();
	}
}

void EmployeeBase::showEmployeeList()
{
	this->printResult(EmployeeList);
	getchar();
}

void EmployeeBase::printResult(LinkedList* EmployeeList)
{
	Node* current = EmployeeList->head;
	while (current != nullptr) {
		cout << current->data->getEmployeeId() << ". " << \
			current->data->getEmployeeName() << ", " << \
			current->data->getJob() << endl << \
			"�������� �����: " << current->data->getMonthSalary() << \
			" �� " << current->data->getWorksDayInMonth() << " ������� ����." << \
			endl << "���������� ������������ ����: " << \
			current->data->getReallyWorksDayInMonth() << "." \
			<< endl << "�����: " << current->data->getFinalSalary() << \
			" ������." << endl << endl;
		current = current->next;
	}
}

void EmployeeBase::findEmployeeById()
{
	string id;
	cout << "������� id ���������: ";
	cin >> id;
	try
	{
		LinkedList* findList = EmployeeList->find("id", id);
		if (findList != nullptr)
		{
			printResult(findList);
			getchar();
			getchar();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void EmployeeBase::findByEmployeeName()
{
	string name;
	cout << "������� ��� ���������: ";
	cin >> name;
	try
	{
		LinkedList* findList = EmployeeList->find("name", name);
		if (findList != nullptr)
		{
			printResult(findList);
			getchar();
			getchar();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void EmployeeBase::findByJob()
{
	string category;
	cout << "������� ��������� ���������: ";
	cin >> category;
	try
	{
		LinkedList* findList = EmployeeList->find("job", category);
		if (findList != nullptr)
		{
			printResult(findList);
			getchar();
			getchar();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void EmployeeBase::findBySalary()
{
	string price;
	cout << "������� ����� ���������: ";
	cin >> price;
	try
	{
		LinkedList* findList = EmployeeList->find("salary", price);
		if (findList != nullptr)
		{
			printResult(findList);
			getchar();
			getchar();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void EmployeeBase::findByFinalSalary()
{
	string finalSalary;
	cout << "������� �������� �������� ���������: ";
	cin >> finalSalary;
	try
	{
		LinkedList* findList = EmployeeList->find("finalSalary", finalSalary);
		if (findList != nullptr)
		{
			printResult(findList);
			getchar();
			getchar();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}


void EmployeeBase::removeEmployeeById()
{
	string id;
	cout << "������� id ���������: ";
	cin >> id;
	try
	{
		cout << "������� " << EmployeeList->remove("id", id) << " �������" << endl;
		getchar();
		getchar();
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void EmployeeBase::removeByEmployeeName()
{
	string name;
	cout << "������� ��� ���������: ";
	cin >> name;
	try
	{
		cout << "������� " << EmployeeList->remove("name", name) << " �������" << endl;
		getchar();
		getchar();
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void EmployeeBase::removeByJob()
{
	string job;
	cout << "������� ��������� ���������: ";
	cin >> job;
	try
	{
		cout << "������� " << EmployeeList->remove("job", job) << " �������" << endl;
		getchar();
		getchar();
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void EmployeeBase::removeBySalary()
{
	string salary;
	cout << "������� �������� ����� ���������: ";
	cin >> salary;
	try
	{
		cout << "������� " << EmployeeList->remove("salary", salary) << " �������" << endl;
		getchar();
		getchar();
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void EmployeeBase::removeByFinalSalary()
{
	string finalSalary;
	cout << "������� �������� �������� ���������: ";
	cin >> finalSalary;
	try
	{
		cout << "������� " << EmployeeList->remove("finalSalary", finalSalary) << " �������" << endl;
		getchar();
		getchar();
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void EmployeeBase::sortEmployeeByIdAsc()
{
	EmployeeList->sort("id", true);
	this->showEmployeeList();
}

void EmployeeBase::sortEmployeeByIdDesc()
{
	EmployeeList->sort("id", false);
	this->showEmployeeList();
}

void EmployeeBase::sortByEmployeeNameAsc()
{
	EmployeeList->sort("name", true);
	this->showEmployeeList();
}

void EmployeeBase::sortByEmployeeNameDesc()
{
	EmployeeList->sort("name", false);
	this->showEmployeeList();
}

void EmployeeBase::sortByJobAsc()
{
	EmployeeList->sort("job", true);
	this->showEmployeeList();
}

void EmployeeBase::sortByJobDesc()
{
	EmployeeList->sort("job", false);
	this->showEmployeeList();
}

void EmployeeBase::sortBySalaryAsc()
{
	EmployeeList->sort("salary", true);
	this->showEmployeeList();
}

void EmployeeBase::sortBySalaryDesc()
{
	EmployeeList->sort("salary", false);
	this->showEmployeeList();
}

void EmployeeBase::sortByFinalSalaryAsc()
{
	EmployeeList->sort("finalSalary", true);
	this->showEmployeeList();
}

void EmployeeBase::sortByFinalSalaryDesc()
{
	EmployeeList->sort("finalSalary", false);
	this->showEmployeeList();
}

void EmployeeBase::exportEmployeeListToJson()
{
	SaveFormat* format = new JsonFormat();
	format->save(EmployeeList, "Employees.json");
	delete format;
}
void EmployeeBase::exportEmployeeListToXML()
{
	SaveFormat* format = new XmlFormat();
	format->save(EmployeeList, "Employees.xml");
	delete format;
}
void EmployeeBase::exportEmployeeListToCSV()
{
	EmployeeList->SaveToFile("EmployeeData.csv");
}

void EmployeeBase::run() {
	SubMenu mainMenu("������ ���������� ����� �� ������������", false);
	SubMenu adminMenu("����������������� ��������", true);
	SubMenu findMenu("�����", false);
	SubMenu removeMenu("��������", false);
	SubMenu userMenu("�������� ��������", false);
	SubMenu sortMenu("����������", false);
	SubMenu sortByIdMenu("���������� �� Id", false);
	SubMenu sortByNameMenu("���������� �� ���", false);
	SubMenu sortByJobMenu("���������� �� ���������", false);
	SubMenu sortBySalaryMenu("���������� �� ��������� ������", false);
	SubMenu sortByFinalSalaryMenu("���������� �� �������� ��������", false);
	SubMenu exportMenu("�������������� ������", false);

	MenuItem sortByEmployeeNameAsc("�� �����������", false, [this]() {this->sortByEmployeeNameAsc(); });
	MenuItem sortByEmployeeNameDesc("�� ��������", false, [this]() {this->sortByEmployeeNameDesc(); });
	MenuItem sortEmployeeByIdAsc("�� �����������", false, [this]() {this->sortEmployeeByIdAsc(); });
	MenuItem sortEmployeeByIdDesc("�� ��������", false, [this]() {this->sortEmployeeByIdDesc(); });
	MenuItem sortByJobAsc("�� �����������", false, [this]() {this->sortByJobAsc(); });
	MenuItem sortByJobDesc("�� ��������", false, [this]() {this->sortByJobDesc(); });
	MenuItem sortBySalaryAsc("�� �����������", false, [this]() {this->sortBySalaryAsc(); });
	MenuItem sortBySalaryDesc("�� ��������", false, [this]() {this->sortBySalaryDesc(); });
	MenuItem sortByFinalSalaryAsc("�� �����������", false, [this]() {this->sortByFinalSalaryAsc(); });
	MenuItem sortByFinalSalaryDesc("�� ��������", false, [this]() {this->sortByFinalSalaryDesc(); });

	MenuItem addEmployeeItem("�������� ������ ���������", false, [this]() {this->addEmployee(); });
	MenuItem importFromCSV("������ �� CSV", false, [this]() {this->importEmployee(); });
	MenuItem showEmployeeList("���������� ������ ����������", false, [this]() {this->showEmployeeList(); });

	MenuItem findEmployeeById("����� ��������� �� Id", false, [this]() {this->findEmployeeById(); });
	MenuItem findByEmployeeName("����� ��������� �� ���", false, [this]() {this->findByEmployeeName(); });
	MenuItem findByJob("����� ��������� �� ���������", false, [this]() {this->findByJob(); });
	MenuItem findBySalary("����� ��������� �� ������", false, [this]() {this->findBySalary(); });
	MenuItem findByFinalSalary("����� ��������� �� �������� ��������", false, [this]() {this->findByFinalSalary(); });
	MenuItem removeEmployeeById("������� ��������� �� Id", false, [this]() {this->removeEmployeeById(); });
	MenuItem removeByEmployeeName("������� ��������� �� ���", false, [this]() {this->removeByEmployeeName(); });
	MenuItem removeByJob("������� ��������� �� ���������", false, [this]() {this->removeByJob(); });
	MenuItem removeBySalary("������� ��������� �� ������", false, [this]() {this->removeBySalary(); });
	MenuItem removeByFinalSalary("������� ��������� �� �������� ��������", false, [this]() {this->removeByFinalSalary(); });

	MenuItem exportEmployeeListToCSV("�������������� � CSV", false, [this]() {this->exportEmployeeListToCSV(); });
	MenuItem exportEmployeeListToJson("�������������� � Json", false, [this]() {this->exportEmployeeListToJson(); });
	MenuItem exportEmployeeListToXML("�������������� � Xml", false, [this]() {this->exportEmployeeListToXML(); });

	exportMenu.add_item(&exportEmployeeListToCSV);
	exportMenu.add_item(&exportEmployeeListToJson);
	exportMenu.add_item(&exportEmployeeListToXML);

	sortByIdMenu.add_item(&sortEmployeeByIdAsc);
	sortByIdMenu.add_item(&sortEmployeeByIdDesc);
	sortByNameMenu.add_item(&sortByEmployeeNameAsc);
	sortByNameMenu.add_item(&sortByEmployeeNameDesc);
	sortByJobMenu.add_item(&sortByJobAsc);
	sortByJobMenu.add_item(&sortByJobDesc);
	sortBySalaryMenu.add_item(&sortBySalaryAsc);
	sortBySalaryMenu.add_item(&sortBySalaryDesc);
	sortByFinalSalaryMenu.add_item(&sortByFinalSalaryAsc);
	sortByFinalSalaryMenu.add_item(&sortByFinalSalaryDesc);
	sortMenu.add_item(&sortByIdMenu);
	sortMenu.add_item(&sortByNameMenu);
	sortMenu.add_item(&sortByJobMenu);
	sortMenu.add_item(&sortBySalaryMenu);
	sortMenu.add_item(&sortByFinalSalaryMenu);
	findMenu.add_item(&findEmployeeById);
	findMenu.add_item(&findByEmployeeName);
	findMenu.add_item(&findByJob);
	findMenu.add_item(&findBySalary);
	findMenu.add_item(&findByFinalSalary);
	removeMenu.add_item(&removeEmployeeById);
	removeMenu.add_item(&removeByEmployeeName);
	removeMenu.add_item(&removeByJob);
	removeMenu.add_item(&removeBySalary);
	removeMenu.add_item(&removeByFinalSalary);

	adminMenu.add_item(&addEmployeeItem);
	adminMenu.add_item(&importFromCSV);
	adminMenu.add_item(&findMenu);
	adminMenu.add_item(&sortMenu);
	adminMenu.add_item(&exportMenu);
	adminMenu.add_item(&removeMenu);
	adminMenu.add_item(&showEmployeeList);

	userMenu.add_item(&findMenu);
	userMenu.add_item(&sortMenu);
	userMenu.add_item(&exportMenu);
	userMenu.add_item(&showEmployeeList);

	mainMenu.add_item(&adminMenu);
	mainMenu.add_item(&userMenu);

	mainMenu.run();
}