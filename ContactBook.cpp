#include "ContactBook.h"

ContactBook::ContactBook()
{
	vector<Contact>contactbook;
}
void ContactBook::addContact(Contact c)
{
	contactbook.insert(contactbook.end(),c);
	cout<<contactbook[0].getName()<<" added to contact."<<endl;
}
bool ContactBook::editContact(string name,int choice)
{
	string newdata;
	int found = 0;
	bool clear = false;
	
	for(int i = 0;i<contactbook.size();i++)
	{
		string z = contactbook[i].getName();
		if(transform(name.begin(),name.end(),name.begin(),::tolower)==transform(z.begin(),z.end(),z.begin(),::tolower));
		{
			found = 1;
			if(choice==1)
			{
				cout<<"Input new name: "<<endl;
				cin>>newdata;
				contactbook[i].setName(newdata);
				clear = true;
			}
			else if (choice == 2)
			{
				cout<<"Input new address: "<<endl;
				cin>>newdata;
				contactbook[i].setAddress(newdata);
				clear = true;
			}
			else if(choice==3)
			{
				cout<<"Input new phone number: "<<endl;
				cin>>newdata;
				contactbook[i].setPhone(newdata);
				clear = true;
				
			}
			else if(choice==4)
			{
				bool cMail = false;
				while(cMail == false)
				{
					cout<<"Input New Email: "<<endl;
					cin>>newdata;
					if((newdata.begin()=find(newdata.begin(),newdata.end(), '@')) != newdata.end() && find(newdata.begin(), newdata.end(), '.') != newdata.end())
					{
						cout<<"Email valid"<<endl;
						cMail = true;
					}
					else 
					{
						cout<<endl<<"Invalid"<<endl;
					}
				}
				contactbook[i].setEmail(newdata);
				clear = true;
			}
			else
			{
				cout<<"Invalid!"<<endl;
			}
			if(clear == true)
			{
				cout<<"*****NEW*****"<<endl;
				cout<<"//////////Informations\\\\\\\\\\"<<endl;
				cout<<"Name : "<<contactbook[i].getName()<<endl;
				cout<<"Address : "<<contactbook[i].getAddress()<<endl;
				cout<<"Contact Person : "<<contactbook[i].getPhone()<<endl;
				cout<<"Email Address : "<<contactbook[i].getEmail()<<endl;
				return true;
			}
		}
	}
		if (found == 0)
		{
			return false;
		}
	
}
bool ContactBook::delContact(string name)
{
	int found = 0;
	for(int i = 0;i<contactbook.size();i++)
	{
		string z = contactbook[i].getName();
		if (transform(name.begin(),name.end(),name.begin(),::tolower) == transform(z.begin(),z.end(),z.begin(),::tolower))
		{
			found = 1;
			contactbook.erase(contactbook.begin()+i);
			return true;
		}
	}
	if(found == 0)
	{
		return false;
	}
}
Contact ContactBook::search(string name)
{
	int found = 0;
	for (int i=0;i<contactbook.size();i++)
	{
		string z = contactbook[i].getName();
		if (transform(name.begin(),name.end(),name.begin(),::tolower) == transform(z.begin(),z.end(),z.begin(),::tolower));
		{
			found = 1;
			return contactbook[i];
		}
	}
	if (found==0)
	{
		cout<<"Not found!"<<endl;
		
	}
}
void ContactBook::printUnsortedList()
{
	cout<<endl<<"//////////Informations\\\\\\\\\\"<<endl;
	for(int i = 0; i<contactbook.size();i++)
	{
		cout << contactbook[i].getName() << endl;
	}
}
void ContactBook::printSortedList()
{
	vector<string>nameList;
	
	for (int i = 0; i <contactbook.size(); i++)
	{
		nameList.insert(nameList.end(),contactbook[i].getName());
		sort(nameList.begin(),nameList.end());
	}
	cout << "=======Sorted Contact List=======" << endl << endl;
	for (int i = 0; i <nameList.size();i++)
	{
		cout << nameList[i] << endl;
	}
}

