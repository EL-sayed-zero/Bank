#pragma once
#include"Employee.h"
#include"Client.h"
#include<vector>
class DataSourceInterface
{
public:

	virtual void add_Employee(Employee person) = 0;
	virtual vector<Employee> get_all_employee() = 0;
	virtual void remove_all_employee() = 0;
	virtual void add_Client(Client person) = 0;
	virtual vector<Client> get_add_clients() = 0;
	virtual void remove_clients() = 0;
};