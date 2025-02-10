#pragma once
#include <iostream>
using namespace std;
#include<string>
class Validation
{
public:

	static bool isValidName(string name) {
		 
		if (name.size() < 5 || name.size() > 20) {
			return false;

		}
		for (char c:name) {
			   
			if (!isalpha(c) || c == ' ') {
				return false;
			}
		}

		return true;
	}


	static bool isValidPassword(string Password) {

		
		if (Password.size() < 8 || Password.size() > 20) {
			return false;
		}

		for (char c : Password) {
			if (c == ' ') {
				return false;
			}
		}
		
		return true;



		


	}

	static bool isMinBalance(double balance) { 

		return (balance >= 1500);
	}


	static bool isValId(int id) {
		return (id > 0);
	}


	static bool isValidSalary(double salary) {           //use every where 
		return (salary >= 500);
	}
};

