#pragma once
#include<iostream>
using namespace std;
#include<string>
#include "Person.h"
#include"Validation.h"
#include<utility>

class Client :
    public Person
{
private:
    double balance;

public:

    Client() {
        balance = 0;
    }

    Client(double balance , int id, string name, string password) :Person(id, name, password) {

       while (!Validation::isMinBalance(balance)) {
            cout << "min balance  must have greater than or equal 1500"<<endl;
            cout << "enter the balance again \n";
            cin >> balance;
            
        }
        
            this->balance = balance;
       

    }

    void setBalance(double balance) {

        while (!Validation::isMinBalance(balance)) {
            cout << "min balance  must have greater than or equal 1500\n";
            cin >> balance;

        }
  
         this->balance = balance;
      


     
    }

    double getBalance() {
        return balance;
    }


    //methods

    void deposite(double& amount) {

        balance += amount;
    }

  
    void withdrow(double amount) {
              
        if (balance < amount ) {

            cout << "you do not have enough money  for withdraw \n";
        }
        else if (amount < 0) {
            cout << "you can not wuthdraw by negative " << endl;
        }
        else {
            balance -= amount ;
        }


    }

    void transfare(double amount, Client& client) {
          
        if (balance < amount ) {

            cout << "you do not have enough money  for transaction"<<endl;
        }
        else if (amount < 0) {
            cout << "you can not negative transaction"<<endl;
        }
        else {          
            balance -= amount;
            client.deposite(amount);
        }

       
    }

    //check balance 
    void checkBalance() {
        cout << balance<<endl;
    }

    void display() {
        Person::display();
        cout << "balane:" << balance<<endl;
        cout << "######################### \n";


    }

    //overloading cin>> methods

    friend istream& operator >>(istream& in, Client &client) {
        int temp_id;
        double temp_balnce;
        string temp_pw, temp_name;
        cout << "enter balance " << endl; 
        in >> temp_balnce;
        client.setBalance(temp_balnce);
        cout << "enter id "<<endl;
        in >> temp_id;
        client.setID(temp_id);
        cout << "enter name " << endl;
        in >> temp_name;
        client.setName(temp_name);
        cout << "enter password " << endl;
        in >> temp_pw;
        client.setPW(temp_pw);


        
        return in;
    }

    //overloading cout<< methods

    friend ostream& operator <<(ostream& out, Client& client) {

        cout << "id : " << client.getId()<<endl;
        cout << "name :" << client.getName() << endl;
        cout << "balance : " << client.getBalance() << endl;
        cout << "password : " << client.getPassword()<<endl;
        out << "#################################\n";

        return out;
    }


};

