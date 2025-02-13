#include <iostream>
using namespace std;
#include <string>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include"FileManger.h"


int main() {

  Client c;
    cin>>c;
    FileManger::add_Client(c);
 //FileManger::remove_all_Clients();



    vector <Client>clients = FileManger::get_all_clients();

    for (Client x : clients) {
        cout << x << endl;
    }
   

  

}

