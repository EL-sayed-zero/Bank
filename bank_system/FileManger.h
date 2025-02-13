#pragma once
#include "DataSourceInterface.h"
#include<fstream>
#include <string>
#include <sstream>
using namespace std;
class FileManger :
    public DataSourceInterface

{
    // i make static func to use the class without obj 
public:

    static bool  fileexist(string filename) { // you dont need this  fucntion                                                               
        ifstream file(filename);               // you can only use the  (.good() )  for cheack if the file is found or not  
        return file.good();                     // look at to the end of page and see my method ;;;;            
    }
    static void  add_Employee(Employee person) {
        if (!fileexist("Employee.txt")) {
            ofstream employeefile("Employee.txt");
            employeefile << person.getId() << "|" << person.getName() << "|" << person.getPassword() << "\n";
            employeefile.close();
            return;
        }
        ofstream employeefile("Employee.txt", ios::app);
        employeefile << person.getId() << "|" << person.getName() << "|" << person.getPassword() << "\n";
        employeefile.close();

    }

   static void  remove_all_employee() {  //edit this method ??? 
        if (!fileexist("Employee.txt")) {
            return;
        }

   }





     
       

   




  


  



    //add client to text file

   static void  add_Client(Client person) {

        ofstream file("client.txt", ios::app);
        if (!file.good()) {
            cout << "There was an error with the file." << endl;
            exit(1);
      }
        file << person.getName()<< "|";
        file << person.getId() << "|";
        file << person.getBalance() << "|";
        file << person.getPassword() << "\n";
        file.close();

   }


   static void  remove_all_Clients() {
         ofstream file("client.txt",  ios::trunc);
         if (!file) {
             cout<<"There was an error with the file.";
             exit(1);
         }

         file.close();
       
        
    }

   static vector<Client> get_all_clients() {

        ifstream file("client.txt",ios::in);
        if (!file) {
            cout << "there was an erroe with file ";
            exit(0);
        }
        vector<Client>clients;
        string line;


        while (getline(file, line)) {

           
                //split the lines use obj from stringstream
                stringstream strs(line);
          
                string id,balnce,name,password;

                getline(strs, name, '|');
                getline(strs, id, '|');
                getline(strs, balnce, '|');
                getline(strs, password, '\n');
            
                //convert 
                int clientid = stoi(id);
                double clientbalanc =stod(balnce);


                Client c(clientbalanc, clientid, name, password);
                clients.push_back(c);


            }
        file.close();
        return clients;

             
    }
  

        //ADD admin files 


   static void add_admin(Admin admin) {

       ofstream file("admin.txt", ios::app);

       if (!file) {
           cout << "file not exist ";
           exit(0);
       }
       file << admin.getName() << "|";
       file << admin.getId() << "|";
       file << admin.getSalary() << "|";
       file << admin.getPassword() << "\n";
       file.close();
   }
  

   static void delete_Admin() {

       ofstream file("admin.txt", ios::trunc);
       if (!file) {
           cout<<"there was an erroe with file ";
           return;

       }
       file.close();
   }



   static vector<Admin> get_all_admin() {

       ifstream file("admin.txt", ios::in);
       if (!file) {
           cout << " can not find file";
           exit(0);
       }
       vector<Admin>admins;
       string line;
       while (getline(file, line)) {

           stringstream strs(line);
           string id, salary, name, password;

           getline(strs, name, '|');
           getline(strs, id, '|');
           getline(strs, salary, '|');
           getline(strs, password, '\n');


           int temp_id = stoi(id);
           int temp_salary = stod(salary);

           Admin admin(temp_salary, temp_id, name, password);
           admins.push_back(admin);

       }

       file.close();
       return admins;

   }

};

