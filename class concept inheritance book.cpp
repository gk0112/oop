#include<iostream>
using namespace std;
class publication
{
	public:
		string title;
		float prize;
		public:
			void getdata()
			{
				cout<<"enter title of publication:";
				cin>>title;
				cout<<"enter the prize of publication:";
				cin>>prize;	
			}
			void putdata()
			{
				cout<<"publication title:"<<title<<endl;
				cout<<"publication prize:"<<prize<<endl;	
			}
		};
class book:public publication{
	public:
		int pagecount;
		public:
			void getdata()
			{
				publication::getdata();
				cout<<"enter book page count:";
				cin>>pagecount;
			}
			void putdata()
			{
				publication::putdata();
				cout<<"book page count:"<<pagecount<<endl;	
			}
};
class tape:public publication{
	private:
		float ptime;
		public:
			void getdata()
			{
				publication::getdata();
				cout<<"enter tape s playing time(in min):";
				cin>>ptime;
			}
			void putdata()
			{
				publication::putdata();
				cout<<"tapes playing time:"<<ptime<<endl;	
			}
};
int main()
{
	book b;
	tape t;
	b.getdata();
	t.getdata();
	b.putdata();
	t.putdata();
	return 0;
}
