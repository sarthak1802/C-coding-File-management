//project for login and register using file handling


#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<cstring>
using namespace std;


class emp
{
	char en[20];
	int ec;
	float es;
	
	public:
	void input();
	void print();
	void modify();
	int getec();
};
	
void emp::input()
{
    cout<<"enter employee code"<<endl;
	cin>>ec;
	fflush(stdin);
	
	cout<<"enter employee name"<<endl;
	cin>>en;
	fflush(stdin);
	
	cout<<"enter salary"<<endl;
	cin>>es;
	fflush(stdin);
	
}
void emp:: print()
{
	cout<<ec<<"\t \t"<<en<<"\t \t"<<es<<endl;
}
int emp::getec()
{
	return ec;
}
void emp::modify()
{
	cout<<"enter employee name"<<endl;
	cin>>en;
	fflush(stdin);
    cout<<"enter salary"<<endl;
	cin>>es;
	fflush(stdin);
}
void createemployee()
{
	ofstream fout;
	emp e;
	fout.open("emp1.txt",ios::app|ios::binary);
	e.input();
	fout.write((char*)&e,sizeof(e));
	fout.close();
}
void displayall()
{
	ifstream fin;
	emp e;
	fin.open("emp1.txt",ios::in|ios::binary);
	cout<<"===================================================="<<endl;
	cout<<"\t \t employee record \t \t"<<endl;
	cout<<"===================================================="<<endl;
	cout<<"employee code \t employee name \t employee salary \t"<<endl;
	cout<<"****************************************************"<<endl;
	while(fin.read((char*)&e,sizeof(e)))
	{
		e.print();
	}
	fin.close();
}
void search()
{
	ifstream fin;
	emp e;
	fin.open("emp1.txt",ios::in|ios::binary);
	int x=0;
	int code;
	cout<<"enter search code"<<endl;
	cin>>code;
	cout<<"===================================================="<<endl;
	cout<<"\t \t employee record \t \t"<<endl;
	cout<<"===================================================="<<endl;
	cout<<"employee code \t employee name \t employee salary \t"<<endl;
	cout<<"****************************************************"<<endl;
	while(fin.read((char*)&e,sizeof(e)))
	{
		if(e.getec()==code)
		{
			e.print();
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
	ifstream fin;
	ofstream fout;
	emp e;
	int x=0;
	int code;
	fin.open("emp1.txt",ios::in|ios::binary);
	fout.open("temp.txt",ios::app|ios::binary);
	cout<<"enter delete code"<<endl;
	cin>>code;
	
	while(fin.read((char*)&e,sizeof(e)))
	{
		if(e.getec()==code)
		{
			x=1;
			continue;
		}
		else
		{
			fout.write((char*)&e,sizeof(e));
		}
	}
	fin.close();
	fout.close();
	remove("emp1.txt");
	rename("temp.txt","emp1.txt");
	
	if(x==1)
	{
		cout<<"record deleted"<<endl;
	}
	else
	{
		cout<<"record not found"<<endl;
	}
}
void update(int x)
{
	int y=0;
	emp e;
	ifstream fin;
	ofstream fout;
	fin.open("emp1.txt",ios::binary);
	fout.open("temp.txt",ios::app|ios::binary);
	
	while(fin.read((char*)&e,sizeof(e)))
	{
		if(e.getec()==x)
		{
			e.modify();
			fout.write((char*)&e,sizeof(e));
			y=1;
		}
		else
		{
			fout.write((char*)&e,sizeof(e));
		}
	}
	fin.close();
	fout.close();
	remove("emp1.txt");
	rename("temp.txt","emp1.txt");
	
	if(y==1)
	{
		cout<<"record updated"<<endl;
	}
	else
	{
		cout<<"record not updated"<<endl;
	}
	
}
void intro()
{
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"welcome to my project"<<endl;
	cout<<"name is sarthak"<<endl;
	cout<<"2nd year student"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
}

void menu()
{
	int ch;
	intro();
	getche();
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
				createemployee();
				break;
			}
			case 2:
			{
				displayall();
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
				int code;
				cout<<"enter update code"<<endl;
				cin>>code;
				update(code);
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
}


void login()
{
	ifstream fin("user.txt");
	int x=0;
	char u[20],p[20];
	char un[20],ps[20];
	
	cout<<"enter username"<<endl;
	cin>>u;
	cout<<"enter password"<<endl;
	cin>>p;
	
	while(fin>>un>>ps)
	{
		if(strcmp(un,u)==0 && strcmp(ps,p)==0)
		{
			x=1;
			menu();
			break;
		}
	}
	if(x==0)
	{
		cout<<"plz create user A/c first"<<endl;
	}
	fin.close();
}



void register1()
{
	ofstream fout("user.txt",ios::app);
	
	char un[20];
	char ps[20];
	
	cout<<"enter user name"<<endl;
	cin>>un;
	
	cout<<"enter password"<<endl;
	cin>>ps;
	
	fout<<un<<"\t"<<ps<<endl;
	
	fout.close();
	
	menu();
}
	
int main()
{
	
	int ch;
	
	cout<<"1: login \n";
	cout<<"2: register \n";
	
	cout<<"enter your choice \n";
	cin>>ch;
	
	if(ch==1)
	{
		login();
	}
	else if(ch==2)
	{
		register1();
	}
	return 0;
}