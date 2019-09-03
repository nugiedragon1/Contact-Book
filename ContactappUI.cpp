#include <iostream>
#include <string>

#include"ContactappUI.h"
using namespace std;




void ContactappUI::run()

{
	optionUI();
}
void ContactappUI::headerUI()
{
		cout<<"\t\t\t------------"<<endl;
		cout<<"\t\t\tCONTACT BOOK"<<endl;
		cout<<"\t\t\t------------"<<endl;
}
void ContactappUI::optionUI()
{
	int option,x=1;
while(x==1)
{

		
		headerUI();
		cout<<"What operation do you want to do?"<<endl;
		cout<<"Choose the following option"<<endl;
		cout<<"1.Add."<<endl;
		cout<<"2.Edit."<<endl;
		cout<<"3.Search."<<endl;
		cout<<"4.View/list sorted."<<endl;
		cout<<"5.View/list unsorted."<<endl;
		cout<<"6.Delete/Remove Contact."<<endl;
		cout<<"7.Exit."<<endl;
		cin>>option;
		if (option == 1)
		{
			Contact c = addUI();
			contactbook.addContact(c);
		}
		else if(option==2)
		{
			editUI();
		}
		else if(option==3)
		{
			searchUI();
		}
		else if(option==4)
		{
			listSortedUI();
		}
		else if (option==5)
		{
			listUnsortedUI();
		}
		else if(option==6)
		{
			delUI();
		}
		else if(option == 7)
		{
			x=0;
			cout <<endl;
		}
}
}
Contact ContactappUI::addUI()
{
	string name,address,phone,email;
	bool cMail=false;
	
	cin.ignore();
	cout<<"ENTER NAME"<<endl;
	getline(cin,name);
	
	cout<<"ENTER ADDRESS"<<endl;
	getline(cin,address);
	
	cout<<"ENTER PERSONAL NUMBER"<<endl;
	cin>>phone;
	
	while(cMail == false)
	{
		cout<<"ENTER EMAIL"<<endl;
		cin>>email;
		cMail= itEmail(email);
	}
	Contact c(name,address,phone,email);
	
	cout<<"//////////Informations\\\\\\\\\\"<<endl;
	cout<<"Name : "<<c.getName()<<endl;
	cout<<"Address : "<<c.getAddress()<<endl;
	cout<<"Contact Person : "<<c.getPhone()<<endl;
	cout<<"Email Address : "<<c.getEmail()<<endl;
	return c;
}
void ContactappUI::editUI()
{
	string name;
	int choice;
	
	cout<<"Who do you want to change?"<<endl;
	cin>>name;
	cout<<"What do you want to change?"<<endl;
	cout<<"1.Name"<<endl;
	cout<<"2.Address"<<endl;
	cout<<"3.Contact Person"<<endl;
	cout<<"4.Email Address"<<endl;
	cin>>choice;
	
	bool y = contactbook.editContact(name,choice);
	
	if(y==true)
	{
		cout<<"Contact edited."<<endl;
	}
	else if(y==false)
	{
		cout<<"Contact cannot be found."<<endl;
	}
}
void ContactappUI::delUI()
{
	string name;
	bool outcome;
	cout<<"Name the contact you would like to delete."<<endl;
	cin>>name;
	
	outcome = contactbook.delContact(name);
	
	if (outcome==true)
	{
		cout<<"Deleted."<<endl;
	}
	else if(outcome == false)
	{
		cout<<"Can not found that contact."<<endl;
	}
}
void ContactappUI::searchUI()
{
	string name;
	
	cout<<"Search here: "<<endl;
	cin>>name;
	
	Contact c = contactbook.search(name);
	cout<<"//////////Informations\\\\\\\\\\"<<endl;
	cout<<"Name : "<<c.getName()<<endl;
	cout<<"Address : "<<c.getAddress()<<endl;
	cout<<"Contact Person : "<<c.getPhone()<<endl;
	cout<<"Email Address : "<<c.getEmail()<<endl;
	
}
void ContactappUI::listSortedUI()
{
	contactbook.printSortedList();
}
void ContactappUI::listUnsortedUI()
{
	contactbook.printUnsortedList();
}
bool ContactappUI::itEmail(string email)
{
	if ((email.begin()=find(email.begin(), email.end(), '@')) != email.end() && find(email.begin(), email.end(), '.') != email.end() )
	{
		cout<<"Email can be used"<<endl<<endl;
		return true;
	}
	else
	{
		cout<<"Email cannot be used"<<endl<<endl;
		return false;
	}
}
