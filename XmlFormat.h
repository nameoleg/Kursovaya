#pragma once
#include "SaveFormat.h"

class XmlFormat : public SaveFormat
{
public:
	void save(LinkedList* list, string filename) override {
		ofstream outfile(filename);
		if (!outfile) {
			cout << "Error creating file " << filename << endl;
			return;
		}
		outfile << "<?xml version=\"1.0\" encoding = \"UTF-8\"?>" << endl;
		outfile << "<Employees>" << endl;
		Node* current = list->head;
		while (current != nullptr) {
			outfile << "  <Employee>" << endl;
			outfile << "    <id>" << current->data->getEmployeeId() << "</id>" << endl;
			outfile << "    <employeeName>" << current->data->getEmployeeName() << "</employeeName>" << endl;
			outfile << "    <job>" << current->data->getJob() << "</job>" << endl;
			outfile << "    <monthSalary>" << current->data->getMonthSalary() << "</monthSalary>" << endl;
			outfile << "    <worksDayInMonth>" << current->data->getWorksDayInMonth() << "</worksDayInMonth>" << endl;
			outfile << "    <reallyWorksDayInMonth>" << current->data->getReallyWorksDayInMonth() << "</reallyWorksDayInMonth>" << endl;
			outfile << "    <finalSalary>" << current->data->getFinalSalary() << "</finalSalary>" << endl;
			outfile << "  </Employee>";
			current = current->next;
			if (current != nullptr) {
				outfile << ",";
			}
			outfile << endl;
		}
		outfile << "</Employees>" << endl;
		outfile.close();
	}
};
