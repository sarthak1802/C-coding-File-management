#include <iostream>
#include<cstdlib>
#include<fstream>
#include<cstdio>
using namespace std;
//text file project without using oops//

char en[20];
int ec;
float es;
void insert()
{
	ofstream fout("emp.txt",ios::app);
	
	cout<<"enter employee code"<<endl;
	cin>>ec;
	fflush(stdin);
	
	cout<<"enter employee name"<<endl;
	cin>>en;
	fflush(stdin);
	
	cout<<"enter salary"<<endl;
	cin>>es;
	fflush(stdin);
	
	fout<<ec<<"\t"<<en<<"\t"<<es<<endl;
	fout.close();
}
void display()
{
	ifstream fin("emp.txt");
	while(fin>>ec>>en>>es)
	{
		cout<<ec<<endl;
		cout<<en<<endl;
		cout<<es<<endl;
	}
	fin.close();
}
void search()
{
	ifstream fin("emp.txt");
	int x=0;
	int code;
	cout<<"enter search code"<<endl;
	cin>>code;
	while(fin>>ec>>en>>es)
	{
		if(ec==code)
		{
			cout<<ec<<endl;
		    cout<<en<<endl;
		    cout<<es<<endl;
			x=1;
			break;
		}
	}
	if(x==1)
	{
		cout<<"record found"<<endl;
	}
	else
	{
		cout<<"record not found"<<endl;
	}
	fin.close();
}
void delete1()
{
	ifstream fin("emp.txt");
	ofstream fout("temp.txt",ios::app);
	int code;
	int x=0;
	cout<<"enter deleted code"<<endl;
	cin>>code;
	
	while(fin>>ec>>en>>es)
	{
		if(ec==code)
		{
			x=1;
			continue;
		}
		else
		{
			fout<<ec<<"\t"<<en<<"\t"<<es<<endl;
		}
	}
	fin.close();
	fout.close();
	remove("emp.txt");
	rename("temp.txt","emp.txt");
	
	if(x==1)
	{
		cout<<"record deleted"<<endl;
	}
	else
	{
		cout<<"record not found"<<endl;
	}
}
void modify()
{
	int x;
	int code;
	char name[20];
	float sal;
	
	ifstream fin("emp.txt",ios::in);
	ofstream fout("temp.txt",ios::app);
	
	cout<<"enter update code"<<endl;
	cin>>code;
	
	while(fin>>ec>>en>>es)
	{
		if(ec==code)
		{
	 
	        cout<<"enter employee name"<<endl;
	        cin>>name;
	        fflush(stdin);
	
	        cout<<"enter salary"<<endl;
	        cin>>sal;
	        fflush(stdin);
	
	        fout<<ec<<"\t"<<name<<"\t"<<sal<<endl;
			
			x=1;
		}
		else
		{
			  fout<<ec<<"\t"<<en<<"\t"<<es<<endl;
		}
	}
	fin.close();
	fout.close();
	remove("emp.txt");
	rename("temp.txt","emp.txt");
}
int main()
{
	int ch;
	system("cls");
	
	do
	{
		cout<<"1:add new records \n";
		cout<<"2:display all records \n";
		cout<<"3:search any records \n";
		cout<<"4:delete any records \n";
		cout<<"5:update any records \n";
		cout<<"6:exit\n";
		
		cout<<"enter your choice \n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
			{
				insert();
				break;
			}
			case 2:
			{
				display();
				break;
			}
			case 3:
			{
				search();
				break;
			}
			case 4:
			{
				delete1();
				break;
			}
			case 5:
			{
				modify();
				break;
			}
			case 6:
			{
				break;
			}
			default:
			{
				cout<<"wrong choice \n";
				break;
			}
		}
		
	}while(ch!=6);
	
	return 0;
	
}