#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


#include "Contact.h"
using namespace std;

class ContactBook
{
	public:
		ContactBook();
		void addContact(Contact C);
		bool editContact(string name,int choice);
		bool delContact(string name);
		Contact search(string name);
		void printSortedList();
		void printUnsortedList();
		
	private:
		vector<Contact>contactbook;
};
#endif
