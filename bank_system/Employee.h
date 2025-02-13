#pragma once

#include<iostream>
using namespace std;
#include<string>
#include "Person.h"
#include"Validation.h"
#include<utility>

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
       double temp_salary;
       string temp_pw, temp_name;

       cout << "enter id " << endl;
       in >> temp_id;
       cout << "enter name " << endl;
       in >> temp_name;
       cout << "enter salary " << endl;
       in >> temp_salary;
       cout << "enter password " << endl;
       in >> temp_pw;

       Employee  move(Employee(temp_salary, temp_id, temp_name, temp_pw));
       return in;
   }



};

