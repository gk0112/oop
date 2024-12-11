#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct rec
{
	char name[20];
	char birthdt[20];
	char phone[11];
}node;
node temp;
vector<node>rec;
vector<node>::iterator ptr;
bool compare(node &r1,node &r2)
{
	if(strcmp(r1.name,r2.name)<0)
	{
		return true;
	}
	else{
		return false;
	}
}
void create()
{
	int n,i;
	cout<<"\nHow many elements do you want to insert:";
	cin>>n;
	cout<<"\nEnter the elements in the database:";
	for(i=0;i<n;i++)
	{
		cout<<"\nName:";
		cin>>temp.name;
		cout<<"\nBirthdt(dd-mm-yy):";
		cin>>temp.birthdt;
		cout<<"\nPhone number:";
		cin>>temp.phone;
		rec.push_back(temp);	
	}
}
void display()
{
	cout<<"\n\tThe contents of the database are:";
	cout<<"\n--------------------------------------------------\n";
	cout<<"NAME              DATE OF BIRTH         PHONE NUMBER\n";
	cout<<"------------------------------------------------------\n";
	for(ptr=rec.begin();ptr!=rec.end();ptr++)
	{
		cout<<"\n";
	    cout<<(*ptr).name<<"             "<<(*ptr).birthdt<<"                 "<<(*ptr).phone;
	}
}
void searching()
{
	char key[20];
	int flag=0;
	cout<<"\nEnter the name which you want to search:";
	cin>>key;
	for(ptr=rec.begin();ptr!=rec.end();ptr++)
	{
		if(strcmp((*ptr).name,key)==0)
		{
			flag=1;
			break;
		}
		else{
			flag=0;
		}	
	}
	if(flag==1)
	{
		cout<<"\nDesired element is present in the database:";	
	}
	else{
		cout<<"\nDesired element is not present in th database:";
	}
}
void sorting()
{
	sort(rec.begin(),rec.end(),compare);
	cout<<"\nRecord is sorted!!!"<<endl;
}
int main()
{
	char ans='y';
	int choice;
              cout<<"\t program for searching and sorting";
	do{
		cout<<"\nMain Menu";
		cout<<"\n1.create a database"<<endl;
		cout<<"2.Display the database"<<endl;
		cout<<"3.Search the element in the database"<<endl;
		cout<<"4.sort the satabase(based on name)"<<endl;
		cout<<"Enter the choice what do you want:";
		cin>>choice;
		switch(choice)
		{
			case 1:create();
			     break;
			case 2:display();
			     break;
		    case 3:searching();
		         break;
		    case 4:sorting();
		         display();
		         break;
		}
		cout<<"\n Do you want to go back to the menu:";
		cin>>ans;
	}while(ans=='y');
	return 0;
	
}

