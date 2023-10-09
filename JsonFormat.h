#pragma once
#include "SaveFormat.h"

class JsonFormat : public SaveFormat
{
public:
	void save(LinkedList* list, string filename) override {
		ofstream outfile(filename);
		if (!outfile) {
			cout << "Error creating file " << filename << endl;
			return;
		}
		outfile << "{" << endl;
		outfile << " \"Employees\": [" << endl;
		Node* current = list->head;
		while (current != nullptr) {
			outfile << "    {" << endl;
			outfile << "        \"id\": " << current->data->getEmployeeId() << "," << endl;
			outfile << "        \"employeeName\": \"" << current->data->getEmployeeName() << "\"," << endl;
			outfile << "        \"job\": \"" << current->data->getJob() << "\"," << endl;
			outfile << "        \"MonthSalary\": " << current->data->getMonthSalary() << "," << endl;
			outfile << "        \"worksDayInMonth\": " << current->data->getWorksDayInMonth() << "," << endl;
			outfile << "        \"reallyWorksDayInMonth\": " << current->data->getReallyWorksDayInMonth() << "," << endl;
			outfile << "        \"finalSalary\": " << current->data->getFinalSalary() << endl;
			outfile << "    }";
			current = current->next;
			if (current != nullptr) {
				outfile << ",";
			}
			outfile << endl;
		}
		outfile << "  }" << endl;
		outfile << "}" << endl;
		outfile.close();
	}
};
