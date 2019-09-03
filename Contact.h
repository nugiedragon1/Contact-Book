#include<iostream>
#ifndef CONTACT_H
#define	CONTACT_H
#include<string>
using namespace std;

class Contact
{
	public:
		Contact(string name,string address,string phone,string email);
		void setName(string name);
		string getName() const;
		
		void setPhone(string phone);
		string getPhone() const;
		
		void setEmail(string email);
		string getEmail() const;
		
		void setAddress(string address);
		string getAddress() const;
		
	private:
		string name;
		string phone;
		string email;
		string address;
};
#endif
