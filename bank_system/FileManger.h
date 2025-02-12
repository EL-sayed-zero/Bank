#pragma once
#include "DataSourceInterface.h"
#include<fstream>
class FileManger :
    public DataSourceInterface

{
    // i make static func to use the class without obj 
public:

    bool static fileexist(string filename) {  // you dont need this  fucntion                                                               
        ifstream file(filename);               // you can only use the  (.good() )  for cheack if the file is found or not  
        return file.good();                     // look at to the end of page and see my method ;;;;            
    }
    void static add_Employee(Employee person) {
        if (!fileexist("Employee.txt")) {
            ofstream employeefile("Employee.txt");
            employeefile << person.getId() << " " << person.getName() << " " << person.getPassword() << endl;
            employeefile.close();
            return;
        }
        ofstream employeefile("Employee.txt", ios::app);
        employeefile << person.getId() << " " << person.getName() << " " << person.getPassword() << endl;
        employeefile.close();

    }

    void static remove_all_employee() {
        if (!fileexist("employee.txt")) {
            return;
        }

        ofstream file("Employee.txt", ios::trunc);

    }



    //add client to text file

    void static add_Client(Client person) {

        fstream file("client.txt", ios::app);
        if (!file.good()) {
            cout << "There was an error with the file." << endl;
            exit(1);
      }
        file << person.getName()<< ",";
        file << person.getId() << ",";
        file << person.getBalance() << ",";
        file << person.getPassword() << "\n";
        file.close();

   }
};

