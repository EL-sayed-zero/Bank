#pragma once

#include<iostream>
using namespace std;
#include<string>
#include"Validation.h"
class Person

{

protected:
	int id;
	string name;
	string password;

public:

	Person() {
		id = 0;
		name = "unKnowen";
		password = "unknown";

	}

	Person(int id, string name, string password) {

	
		
		 while (!Validation::isValId(id)){
			cout << "invalid id \n";
			cout << "enter the valid id \n";
			cin >> id;
		}
		this->id = id;
		//name validation 

		while (!Validation::isValidName(name)) {

			cout << "invalid name , must has min 5 to 20 char   " << endl;
			cout << "###############################\n";
			cout << "enter the valid Name \n";
			cin >> name;
		}
		this->name = name;


		while (!Validation::isValidPassword(password)) {

			cout << "invalid password try again " << endl;
			cout << " enter valid password  " << endl;
			cin >> password;

		}
		this->password = password;

	}

	



	//setters
	void setID(int id) {
		this->id = id;
	}


	void setName(string name) {

		while (!Validation::isValidName(name)) {

			cout << "invalid name , must has min 5 to 20 char  " << endl;
			cout << "enter the valid Name \n";
			cin >> name;
		}
		this->name = name;


	}

	void setPW(string password) {

		while (!Validation::isValidPassword(password)) {

			cout << "invalid password try again " << endl;
			cout << " enter valid password  " << endl;
			cin >> password;

		}
		this->password = password;

		
	}

	//getter 

	int getId() {
		return id;
	}
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}

	virtual void display() {

		cout << "name: " << name <<" \n" << "id: " << id <<"\n" ;


	};


	  

};

