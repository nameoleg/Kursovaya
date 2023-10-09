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
	cout << "Введите порядковый номер работника: ";
	cin >> EmployeeId;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Введите имя работника: ";
	getline(cin, EmployeeName);
	cout << "Введите профессию работника: ";
	getline(cin, Job);
	cout << "Введите месячный оклад работника: ";
	cin >> MonthSalary;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Введите количество предусмотренных рабочих дней: ";
	cin >> WorksDayInMonth;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Введите количество реальных отработанных дней: ";
	cin >> ReallyWorksDayInMonth;

	double FinalSalary = (double)MonthSalary * 
		((double)ReallyWorksDayInMonth / (double)WorksDayInMonth);

	Employee* Employeer = new Employee(EmployeeId, MonthSalary,
		WorksDayInMonth, ReallyWorksDayInMonth, EmployeeName, Job, FinalSalary);
	EmployeeList->add(Employeer);
}

void EmployeeBase::importEmployee() {
	string filename;
	cout << "Введите путь к файлу: ";
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
			"Месячный оклад: " << current->data->getMonthSalary() << \
			" за " << current->data->getWorksDayInMonth() << " рабочих дней." << \
			endl << "Количество отработанных дней: " << \
			current->data->getReallyWorksDayInMonth() << "." \
			<< endl << "Итого: " << current->data->getFinalSalary() << \
			" рублей." << endl << endl;
		current = current->next;
	}
}

void EmployeeBase::findEmployeeById()
{
	string id;
	cout << "Введите id работника: ";
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
			cout << "Ничего не найдено" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void EmployeeBase::findByEmployeeName()
{
	string name;
	cout << "Введите имя работника: ";
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
			cout << "Ничего не найдено" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void EmployeeBase::findByJob()
{
	string category;
	cout << "Введите профессию работника: ";
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
			cout << "Ничего не найдено" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void EmployeeBase::findBySalary()
{
	string price;
	cout << "Введите оклад работника: ";
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
			cout << "Ничего не найдено" << endl;
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void EmployeeBase::findByFinalSalary()
{
	string finalSalary;
	cout << "Введите итоговую зарплату работника: ";
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
			cout << "Ничего не найдено" << endl;
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}


void EmployeeBase::removeEmployeeById()
{
	string id;
	cout << "Введите id работника: ";
	cin >> id;
	try
	{
		cout << "Удалено " << EmployeeList->remove("id", id) << " записей" << endl;
		getchar();
		getchar();
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void EmployeeBase::removeByEmployeeName()
{
	string name;
	cout << "Введите имя работника: ";
	cin >> name;
	try
	{
		cout << "Удалено " << EmployeeList->remove("name", name) << " записей" << endl;
		getchar();
		getchar();
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void EmployeeBase::removeByJob()
{
	string job;
	cout << "Введите профессию работника: ";
	cin >> job;
	try
	{
		cout << "Удалено " << EmployeeList->remove("job", job) << " записей" << endl;
		getchar();
		getchar();
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void EmployeeBase::removeBySalary()
{
	string salary;
	cout << "Введите месячный оклад работника: ";
	cin >> salary;
	try
	{
		cout << "Удалено " << EmployeeList->remove("salary", salary) << " записей" << endl;
		getchar();
		getchar();
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void EmployeeBase::removeByFinalSalary()
{
	string finalSalary;
	cout << "Введите итоговую зарплату работника: ";
	cin >> finalSalary;
	try
	{
		cout << "Удалено " << EmployeeList->remove("finalSalary", finalSalary) << " записей" << endl;
		getchar();
		getchar();
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
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
	SubMenu mainMenu("Расчет заработной платы на производстве", false);
	SubMenu adminMenu("Администрирование каталога", true);
	SubMenu findMenu("Поиск", false);
	SubMenu removeMenu("Удаление", false);
	SubMenu userMenu("Просмотр каталога", false);
	SubMenu sortMenu("Сортировка", false);
	SubMenu sortByIdMenu("Сортировка по Id", false);
	SubMenu sortByNameMenu("Сортировка по ФИО", false);
	SubMenu sortByJobMenu("Сортировка по профессии", false);
	SubMenu sortBySalaryMenu("Сортировка по месячному окладу", false);
	SubMenu sortByFinalSalaryMenu("Сортировка по итоговой зарплате", false);
	SubMenu exportMenu("Экспортировать список", false);

	MenuItem sortByEmployeeNameAsc("По возрастанию", false, [this]() {this->sortByEmployeeNameAsc(); });
	MenuItem sortByEmployeeNameDesc("По убыванию", false, [this]() {this->sortByEmployeeNameDesc(); });
	MenuItem sortEmployeeByIdAsc("По возрастанию", false, [this]() {this->sortEmployeeByIdAsc(); });
	MenuItem sortEmployeeByIdDesc("По убыванию", false, [this]() {this->sortEmployeeByIdDesc(); });
	MenuItem sortByJobAsc("По возрастанию", false, [this]() {this->sortByJobAsc(); });
	MenuItem sortByJobDesc("По убыванию", false, [this]() {this->sortByJobDesc(); });
	MenuItem sortBySalaryAsc("По возрастанию", false, [this]() {this->sortBySalaryAsc(); });
	MenuItem sortBySalaryDesc("По убыванию", false, [this]() {this->sortBySalaryDesc(); });
	MenuItem sortByFinalSalaryAsc("По возрастанию", false, [this]() {this->sortByFinalSalaryAsc(); });
	MenuItem sortByFinalSalaryDesc("По убыванию", false, [this]() {this->sortByFinalSalaryDesc(); });

	MenuItem addEmployeeItem("Добавить нового работника", false, [this]() {this->addEmployee(); });
	MenuItem importFromCSV("Импорт из CSV", false, [this]() {this->importEmployee(); });
	MenuItem showEmployeeList("Посмотреть список работников", false, [this]() {this->showEmployeeList(); });

	MenuItem findEmployeeById("Найти работника по Id", false, [this]() {this->findEmployeeById(); });
	MenuItem findByEmployeeName("Найти работника по ФИО", false, [this]() {this->findByEmployeeName(); });
	MenuItem findByJob("Найти работника по профессии", false, [this]() {this->findByJob(); });
	MenuItem findBySalary("Найти работника по окладу", false, [this]() {this->findBySalary(); });
	MenuItem findByFinalSalary("Найти работника по итоговой зарплате", false, [this]() {this->findByFinalSalary(); });
	MenuItem removeEmployeeById("Удалить работника по Id", false, [this]() {this->removeEmployeeById(); });
	MenuItem removeByEmployeeName("Удалить работника по ФИО", false, [this]() {this->removeByEmployeeName(); });
	MenuItem removeByJob("Удалить работника по профессии", false, [this]() {this->removeByJob(); });
	MenuItem removeBySalary("Удалить работника по окладу", false, [this]() {this->removeBySalary(); });
	MenuItem removeByFinalSalary("Удалить работника по итоговой зарплате", false, [this]() {this->removeByFinalSalary(); });

	MenuItem exportEmployeeListToCSV("Экспортировать в CSV", false, [this]() {this->exportEmployeeListToCSV(); });
	MenuItem exportEmployeeListToJson("Экспортировать в Json", false, [this]() {this->exportEmployeeListToJson(); });
	MenuItem exportEmployeeListToXML("Экспортировать в Xml", false, [this]() {this->exportEmployeeListToXML(); });

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