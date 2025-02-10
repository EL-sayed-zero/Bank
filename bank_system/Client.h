#pragma once
#include<iostream>
using namespace std;
#include<string>
#include "Person.h"
#include"Validation.h"

class Client :
    public Person
{
private:
    double balance;

public:

    Client(double balance, int id, string name, string password) :Person(id, name, password) {

       while (!Validation::isMinBalance(balance)) {
            cout << "min balance  must have greater than or equal 1500"<<endl;
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

    //getters 
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

};

