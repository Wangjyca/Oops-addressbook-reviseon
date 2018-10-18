
#ifndef PERSON_H
#define PERSON_H


#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>


using namespace std;

class Person {
private: 

   string firstname;
   string lastname;
   string phone;
   string street;
   string city;
   string zip;
   int verifysignal=0; // 0 repesents un-assigned value; -1 represents removed contact; 1 repesents valid contact
public: 

// ADD: Methods getters & setters that work on the private variables.
	 void setfirstname(string);

	 void   setverifysignal(int);

	void setlastname(string thelname)
		 {
		 lastname = thelname; 

		 }
	void setphone(string thephone)
	{
		phone = thephone;
	}

	void setstreet(string thestreet)
	{
		street = thestreet;
	}

	void setcity(string thecity)
	{
		city = thecity;
	}

	void setzip(string thezip)
	{
		zip = thezip;
	}

	string getfirstname() const
	{
		return firstname;
	}

	string getlastname()const
		 { 
		 	return lastname; 
		 }
	string getphone() const
	{
		return phone;
	}

	string getstreet() const
	{
		return street;
	}

	string getcity() const
	{
		return city;
	}

	string getzip() const

	{
		return  zip;
	}


	int getverifysignal()
	{
		//cout << "verifysignal=" << verifysignal;
		return  verifysignal;
	}

};



#endif