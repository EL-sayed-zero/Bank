#pragma once
#include "DataSourceInterface.h"
#include<fstream>
class FileManger :
    public DataSourceInterface
{
public:
    bool fileexist(string filename) {
        ifstream file(filename);
        return file.good();
    }

    void add_Employee(Employee person) {
        if (!fileexist("Employee.txt")) {
            ofstream employeefile("Employee.txt");
            employeefile << person.getId() << " " << person.getName() << " " << person.getPassword() << endl;
            employeefile.close();
            return;
        }
        ofstream employeefile("Employee.txt", ios::app);
        employeefile << person.getId() << " " << person.getName() << " " << person.getPassword() << endl;
        employeefile.close();

    }

    void remove_all_employee() {
        if (!fileexist("employee.txt")) {
            return;
        }

        ofstream file("Employee.txt", ios::trunc);

    }


};

