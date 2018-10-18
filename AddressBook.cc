#include "Addressbook.h"
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

 

   
        // Use a Person Array
		//Person Persons[];
    //public:
       // int count(); //count all the people in the address book

      //  void addPerson(string firstname, string lastname, string phone, string street, string city, string zip); // add a new person to the address book
    
       // void editPerson(string firstname, string lastname, string phone, string street, string city, string zip);

     //   bool removePerson(string firstname); // remove Person by matching firstName
      //  bool removePerson(string firstname, string lastname); // remove Person by matching first and last name

      //  void sortByLastName(); //sort alphabetically by last name and print
        
//

 int AddressBook::count() {

	// int pernsonnumber;
	//  pernsonnumber = sizeof(Persons); //Persons.size();//
	//  cout << "size of arry" << pernsonnumber << endl;
	//  return pernsonnumber;

	  int counter = 0;
	 int togetverifysignal=0 ;

	 do {

		  togetverifysignal = Persons[counter].getverifysignal();
		 
	 	 if (togetverifysignal==0) { break; }
	 	counter++;

	  } while (1 == 1);
	 
	  // cout << "count..." << counter << endl;
 	 return counter;
 }

int AddressBook::listall() {
	int counter;
	int idnum=0; //display SN

	sortByLastName(); ///sort alphabetically by last name and print
	counter = count();
	 cout << "Array size" << counter << endl;
//	cout << "Total*---" << counter << endl;

	for (int i = 0; i <= counter; i++) {

		
		if ((Persons[i].getverifysignal() == 0) || (Persons[i].getverifysignal() == -1)) { // skip unassigned or removed contacts
		}
		else
		{
			idnum++;
			cout << setw(4) << left << i << '\t';
			cout << setw(10) << left << Persons[i].getfirstname().c_str() << '\t';
			cout << setw(8) << left << Persons[i].getlastname().c_str() << '\t';
			cout << setw(13) << left << Persons[i].getphone().c_str() << '\t';
			cout << setw(20) << left << Persons[i].getstreet().c_str() << '\t';
			cout << setw(10) << left << Persons[i].getcity().c_str() << '\t';
			cout << setw(10) << right << Persons[i].getzip().c_str() << '\t';
			cout << setw(3) << left << " " << endl;
		}
	}
	return idnum;
}


bool AddressBook::findPerson(char findinfo[]) {
	bool foudpersons = false;
	int counter;
	int idnum = 0; //display SN
	counter = count();


	for (int i = 0; i <= counter; i++) {

		if ((Persons[counter].getverifysignal() == -1)) {// skip removed contact
		}
		else
		{
			if (strstr(Persons[i].getfirstname().c_str(), findinfo) != 0 ||
				strstr(Persons[i].getlastname().c_str(), findinfo) != 0 ||
				strstr(Persons[i].getphone().c_str(), findinfo) != 0 ||
				strstr(Persons[i].getphone().c_str(), findinfo) != 0 ||
				strstr(Persons[i].getstreet().c_str(), findinfo) != 0 ||
				strstr(Persons[i].getcity().c_str(), findinfo) != 0 ||
				strstr(Persons[i].getzip().c_str(), findinfo) != 0
				)
			{
				//idnum++;
				cout << setw(4) << left << i << '\t';
				cout << setw(10) << left << Persons[i].getfirstname().c_str() << '\t';
				cout << setw(8) << left << Persons[i].getlastname().c_str() << '\t';
				cout << setw(13) << left << Persons[i].getphone().c_str() << '\t';
				cout << setw(20) << left << Persons[i].getstreet().c_str() << '\t';
				cout << setw(10) << left << Persons[i].getcity().c_str() << '\t';
				cout << setw(10) << right << Persons[i].getzip().c_str() << '\t';
				cout << setw(3) << left << " " << endl;
				foudpersons = true;
			}//   comparsion if end
		}//   empty contact if
	}// end loop
	return foudpersons;
}

 
int AddressBook::findPerson(int amiNum) {
	bool foudpersons = false;
	int counter;
	int idnum = 0; //display SN
	counter = count();

	if (amiNum <= counter) {
		if ((Persons[amiNum].getverifysignal() == 0) || (Persons[amiNum].getverifysignal() == -1)) {
			return -1;//contact un existed
		}
		else
		{
			return amiNum; //contact exits
		}
	}
	else
	{
		return -1;//contact un existed
	}
}


void  AddressBook::editPerson(string firstname, string lastname, string phone, string street, string city, string zip, int counter) {
	
	
	Persons[counter].setfirstname(firstname);
	Persons[counter].setlastname(lastname);
	Persons[counter].setphone(phone);
	Persons[counter].setstreet(street);
	Persons[counter].setcity(city);
	Persons[counter].setzip(zip);
	
}


void AddressBook::editPerson(int aimNum) { // for update menu


	char firstnamestring[81], lastnamestring[81], phonestring[81], streetstring[81], citystring[81], zipstring[81];
	string editmodel;

	editmodel = "Updated model>";

	cout << editmodel + Persons[aimNum].getfirstname().c_str()  + "> First Name to:";
	cin.getline(firstnamestring, 80);

	cout << editmodel + Persons[aimNum].getlastname().c_str() + "> Last Name to:";
	cin.getline(lastnamestring, 80);

	cout << editmodel + Persons[aimNum].getphone().c_str() + "> Phone to:";
	cin.getline(phonestring, 80);

	cout << editmodel + Persons[aimNum].getstreet().c_str() + "> Street to:";
	cin.getline(streetstring, 80);

	cout << editmodel + Persons[aimNum].getcity().c_str() + "> City to:";
	cin.getline(citystring, 80);

	cout << editmodel + Persons[aimNum].getzip().c_str() + "> Zip Code to:";
	cin.getline(zipstring, 80);

	editPerson(firstnamestring, lastnamestring, phonestring, streetstring, citystring, zipstring, aimNum);

}


void  AddressBook::addPerson(string firstname, string lastname, string phone, string street, string city, string zip) { // add a new person to the address book
	int counter=0;
	counter = count();
	
	
	Persons[counter].setverifysignal(1);// set the flag to show this arry element is no null
	editPerson(firstname, lastname, phone, street, city, zip, counter);

	/// cout << "Total*-+++-" << counter << "    Persons[counter].getverifysignal() =" << Persons[counter].getverifysignal() << endl;
}

void  AddressBook::addPerson() {

	char firstnamestring[81], lastnamestring[81], phonestring[81], streetstring[81], citystring[81], zipstring[81];
	string editmodel;

	editmodel = "Add model>";

	cout << editmodel + "First Name:";
	cin.getline(firstnamestring, 80);

	cout << editmodel + "Last Name:";
	cin.getline(lastnamestring, 80);

	cout << editmodel + "Phone:";
	cin.getline(phonestring, 80);

	cout << editmodel + "Street:";
	cin.getline(streetstring, 80);

	cout << editmodel + "City:";
	cin.getline(citystring, 80);

	cout << editmodel + "Zip Code:";
	cin.getline(zipstring, 80);


	addPerson(firstnamestring, lastnamestring, phonestring, streetstring, citystring, zipstring);
}





bool AddressBook::removePerson(string firstname) { // remove Person by matching firstName
	int counter;
	bool deletedsignal=false;
	counter = count() + 1; //To get the last one of the address book 
	for (int i = 0; i <= counter; i++) {
		 
		if (strcmp(Persons[i].getfirstname().c_str(), firstname.c_str()) == 0) {
			Persons[i].setverifysignal(-1); ///set to be removed
			deletedsignal = true;
		}
	}

	return deletedsignal;
}

bool AddressBook::removePerson(string firstname, string lastname){ // remove Person by matching first and last name 
	int counter;
	bool deletedsignal = false;
	counter = count() + 1; //To get the last one of the address book 
	for (int i = 0; i <= counter; i++) {

		if ((strcmp(Persons[i].getfirstname().c_str(), firstname.c_str()) == 0) && (strcmp(Persons[i].getlastname().c_str(), lastname.c_str()) == 0) ) {
			Persons[i].setverifysignal(-1); ///Represent to be removed
			deletedsignal = true;
		}
	}
	return deletedsignal;
}


void AddressBook::sortByLastName()
{
	int counter;
	 
	counter = count();

	
	for (int i = 0; i < counter; i++) {



			for (int j = 0 ; j < counter; j++){

				if (strcmp(Persons[i].getlastname().c_str(), Persons[j].getlastname().c_str()) <0) {
					string exchengstring;
					exchengstring = Persons[i].getlastname();
					Persons[i].setlastname(Persons[j].getlastname().c_str())  ;
					Persons[j].setlastname(exchengstring);

					exchengstring = Persons[i].getfirstname();
					Persons[i].setfirstname(Persons[j].getfirstname().c_str())  ;
					Persons[j].setfirstname(exchengstring)  ;

					exchengstring = Persons[i].getphone();
					Persons[i].setphone(Persons[j].getphone().c_str())  ;
					Persons[j].setphone(exchengstring)  ;

					exchengstring = Persons[i].getstreet();
					Persons[i].setstreet(Persons[j].getstreet().c_str()) ;
					Persons[j].setstreet(exchengstring)  ;

					exchengstring = Persons[i].getcity();
					Persons[i].setcity(Persons[j].getcity().c_str()) ;
					Persons[j].setcity(exchengstring)  ;

					exchengstring = Persons[i].getzip();
					Persons[i].setzip(Persons[j].getzip().c_str())   ;
					Persons[j].setzip(exchengstring)  ;

					int exchengint=0;
					exchengint = Persons[i].getverifysignal();
					Persons[i].setverifysignal(Persons[j].getverifysignal());
					Persons[j].setverifysignal(exchengint);

 
				}



			} //for j loop
		 
	}//for i loop



	
}


