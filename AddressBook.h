#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H


#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include "person.cc"
 
using namespace std;

class AddressBook {

    private:
        // Use a Person Array
		Person Persons[1000];
    public:


		int  count();  ////count all the people in the address book
  
		int listall(); /// print out all contact
        void  addPerson(string, string, string, string, string, string); // add a new person to the address book
		void  addPerson();

        void editPerson(string, string, string, string, string, string, int);
		void editPerson(int aimNum);

        bool removePerson(string); // remove Person by matching firstName
        bool removePerson(string , string); // remove Person by matching first and last name

		bool findPerson(char []); // search Person by containing in first name, last name, phone, street, city, or zip code
		int  findPerson(int); // search Person by SN
        void sortByLastName(); //sort alphabetically by last name and print
        
};

#endif
