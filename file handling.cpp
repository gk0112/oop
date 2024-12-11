#include<iostream>
#include<fstream>
using namespace std;
class employee{
	char name[20];
	int ID;
	double salary;
	public:
		void accept()
		{
			cout<<"name:";
			cin>>name;
			cout<<"ID:";
			cin>>ID;
			cout<<"salary:";
			cin>>salary;
			
		}
		void display()
		{
		     cout<<name<<" "<<ID<<" "<<salary<<endl;		
		}
};
int main()
{
	employee o[5];
	fstream f;
	int i,n;
	f.open("gaurav.txt");
	cout<<"\nHow many employee information do you need to store:";
	cin>>n;
	cout<<"\n Enter information of employee in this format(name/id/salary)";
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter inforamtion of Employee:"<<endl;
		o[i].accept();
		f.write((char*)&o[i],sizeof o[i]);
	}
	f.close();
	f.open("gaurav.txt");
	cout<<"\n information of employee is as follows:"<<endl;
	cout<<"name"<<"   "<<"ID"<<"  "<<"salary"<<endl;
	for(i=0;i<n;i++)
	{
		f.write((char*)&o[i],sizeof o[i]);
		o[i].display();
		
	}
	f.close();
	return 0;
}

