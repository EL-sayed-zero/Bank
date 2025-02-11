#pragma once
#include"Employee.h"
#include"Client.h"
class DataSourceInterface
{
	virtual void add_Employee(Employee person) = 0;
	virtual void add_Client(Client person) = 0;
	//hell yeah
};