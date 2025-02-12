#pragma once
#include "DataSourceInterface.h"
#include<fstream>
class FileManger :
    public DataSourceInterface
{
    void add_Employee(Employee person) {
        ofstream employeefile("Employee.txt");
        employeefile << person.getId() << " " << person.getName() << " " << person.getPassword() << endl;
        employeefile.close();
    }
};

