#pragma once

#include<iostream>
using namespace std;
#include<string>
#include "Person.h"
#include"Validation.h"

class Employee :
    public Person
{
protected:
    double salary;

public:
    Employee(double salary, int id, string name, string password) :Person(id, name, password) {

           while (!Validation::isValidSalary(salary)) {  
            cout << "Salary must be 5000 or more. Please enter a valid salary: \n ";
            cin >> salary;
        }

        this->salary = salary;  
    }


    //setter 

    void setSalary(double salary) {
        while (!Validation::isValidSalary(salary)) {

            cout << "Salary must be 5000 or more. Please enter a valid salary: \n ";
            cin >> salary;
        }

        this->salary = salary;
    }

    double getSalary() {
        return salary;
    }
    

   virtual void display() {
        Person::display();
        cout << salary << endl;
        cout << "##################\n";
    }



   friend istream& operator >>(istream& in, Employee& employee) {
       int temp_id;
       double temp_balnce;
       string temp_pw, temp_name;

       cout << "enter id " << endl;
       in >> temp_id;
       cout << "enter name " << endl;
       in >> temp_name;
       cout << "enter balance " << endl;
       in >> temp_balnce;
       cout << "enter password " << endl;
       in >> temp_pw;

       Employee  move(Employee(temp_balnce, temp_id, temp_name, temp_pw));
       return in;
   }


};

