#include<iostream>
#include<algorithm>


#ifndef CONTACTUI_H
#define CONTACTUI_H
#include"Contact.h"
#include"ContactBook.h"

class ContactappUI
{
	public:
		void run();
	private:
		void headerUI();
		void optionUI();
		Contact addUI();
		void editUI();
		void searchUI();
		void listSortedUI();
		void listUnsortedUI();
		void delUI();
		
		bool itEmail(string e);
		ContactBook contactbook;
};
#endif
