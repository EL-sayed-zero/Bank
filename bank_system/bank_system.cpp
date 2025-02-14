#include <iostream>
using namespace std;
#include <string>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include"Admin.h"
#include"FileManger.h"

template<typename ty>
void displayFiles(vector<ty>&item) {
    for (auto x : item) {
        cout << x;
    }

}
int main() {

  Client c;
    cin>>c;
    FileManger::add_Client(c);




    vector <Client>clients = FileManger::get_all_clients();

    for (Client x : clients) {
        cout << x << endl;
    }
   
   Admin a;
    cin >> a;
    FileManger::add_admin(a);
    vector<Admin>admins = FileManger::get_all_admin();
 
    displayFiles(admins);

}

