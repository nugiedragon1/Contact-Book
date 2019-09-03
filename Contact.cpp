#include <iostream>
#include <string>
#include "contact.h"
using namespace std;

Contact::Contact(string name,string address,string phone,string email)
{
	this->name = name;
	this->address= address;
	this->phone=phone;
	this->email=email;
}

void Contact::setName(string name)
{
	this->name = name;
}
void Contact::setAddress(string address)
{
	this->address = address;
}
void Contact::setPhone(string phone)
{
	this->phone= phone;
}
void Contact::setEmail(string email)
{
	this->email=email;
}

string Contact::getName()const
{
	return this->name;
}
string Contact::getAddress()const
{
	return this->address;
}
string Contact::getPhone()const
{
	return this->phone;
}
string Contact::getEmail()const
{
	return this->email;
}
