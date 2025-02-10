#pragma once
#include "Employee.h"


class Admin :
    public Employee
{


public:
    Admin(double salary, int id, string name, string password) :Employee(salary, id, name, password) {



    }
    
    
  //a7a 



    void display() {

        cout << "admin info \n";
        Employee::display();
    }


};

