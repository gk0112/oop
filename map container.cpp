#include<iostream>
using namespace std;
#include<map>
#include<vector>
int main()
{
	string state;
	int population;
	int ch;
	char ans='y';
	map<string,int>m;
	map<string,int>::iterator i;
	do{
		cout<<"-----MENU-----"<<endl;
		cout<<"1.add the state and its population:"<<endl;
		cout<<"2.display the details:"<<endl;
		cout<<"3.find the popuation of the state by its name:"<<endl;
		cout<<"enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"enter the name of the state:";
			        cin>>state;
			        cout<<"enter the population of the given state(in cr):";
			        cin>>population;
			        m.insert(pair<string,int>(state,population));
			    break;
		    case 2:cout<<"display the details:"<<endl;
		           for(i=m.begin();i!=m.end();i++)
		                cout<<"["<<(*i).first<<" "<<(*i).second<<"]"<<endl;
		           break;
		    case 3:cout<<"enter the name of the state:";
		           cin>>state;
		           if(m.count(state)!=0)
		           {
		           	  cout<<"the population of the "<<state<<"is:"<<m.find(state)->second<<"cr"<<endl;
				   }
				   else{
				   	  cout<<"the given state in not in the list!"<<endl;
				   }
				   break;
			default:cout<<"invalid choice!"<<endl;
		}
		cout<<"do you want to continue:";
		cin>>ans;

	}
	while(ans=='y');
	return 0;
}
