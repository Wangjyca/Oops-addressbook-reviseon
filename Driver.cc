#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include "Addressbook.cc"
 
using namespace std;


int main() {
	//cin.ignore();
	//int a;
	//cout << "test";
	//cin >> a;
	AddressBook myContactBook;

	// Using Menu to perform all the operations on myContactBook

	cout << "Please choose one of the options below: " << endl;
	cout << "******************************************************************" << endl;
	cout << "1. Add contact to address book." << endl;
	cout << "2. Update existing contact." << endl;
	cout << "3/4. Delete contact from address book" << endl;
	cout << "5. Search for contact in address book." << endl;
	cout << "6. List all" << endl;
	cout << "7. Quit the program" << endl;
	cout << "******************************************************************" << endl;

	do {
		int menuChoice;

		cout << "Add(1)/Update(2)/Delete by First Name(3)/Delete by First & Last Name(4)/Search(5)/List all(6)/Quit(7):";
		 cin >> menuChoice;
	  	cin.ignore();
		char findinfo[21];
		char firstnamestring[81], lastnamestring[81], phonestring[81], streetstring[81], citystring[81], zipstring[81];
		 
		string Firstnamestring, Lastnamestring;

		switch (menuChoice) {

		case 1: //Function to add contact to address book.
			
						myContactBook.addPerson();

						cout << endl << endl;
			 

			break;
		case 2: //Function to update contact in address book.
			//cin.ignore();
									cout << endl << "Update model: Any information for searching (20 characters):";
									cin.getline(findinfo, 20);
									  //cin.ignore();

									if (myContactBook.findPerson(findinfo) == true) {//found the aim contacts
										int aimNum = 0; // chose sequence number to locate the update contact

										do {
											cout << endl << "Choose a sequence number from above / list all (-2) /Return (-1): ";
											cin >> aimNum;
											if (aimNum == -1) {
												break;
											}
											else if (aimNum == -2) {///display all
												cout << "Loading... " << endl;
												
												cout << "Total: " << myContactBook.listall() << " contacts" << endl << endl << endl;
											}
											else {
												
												if (myContactBook.findPerson(aimNum) != -1) {
													cin.ignore();
													myContactBook.editPerson(aimNum);
													cout << endl << endl; //Update the contact 

												}
											}//end of second menu choose if

										} while (1 == 1); //do loop end
									}


			break;
		case 3: //Function to delete contact from address book by first name.
			 
			cout << endl << "Delete model: Enter first name for searching:";
			cin.getline(findinfo, 20);
			Firstnamestring = findinfo;
			if (myContactBook.removePerson(Firstnamestring) == true) {

				cout << "Deleted Sucessful!" << endl;
			}
			else
			{
				cout << "No match first name!" << endl;
			}
			

			break;
		case 4:  //Function to delete contact from address book by first name.
			 
			cout << endl << "Delete model: Enter first name for searching:";
			cin.getline(findinfo, 20);
			Firstnamestring = findinfo;
			//cin.ignore();
			cout << endl << "Delete model: Enter last name for searching:";
			cin.getline(findinfo, 20);
			Lastnamestring= findinfo;
			if (myContactBook.removePerson(Firstnamestring, Lastnamestring) == true) {

				cout << "Deleted Sucessful!" << endl;
			}
			else
			{
				
				cout << "No match first name and last name!" << endl;
			}

			break;
		case 5: //Function to search for contact in address book
		     	// cin.ignore();
				cout << endl << "Search model: Any information for searching (20 characters):";
				cin.getline(findinfo, 20);
				//cin.ignore();
				if (myContactBook.findPerson(findinfo)==true) {

					cout << "found  contact(s)!" << endl;
				}

		
			break;


		case 6:  //list all
			 
			myContactBook.listall();
			 
			break;
		case 7:  //Functiont to quit the program.
			return 0;
		default:
			 cin.ignore();
			//break;

		}//end of the switch case


	} while (1 == 1);
 

 return 0;
}
