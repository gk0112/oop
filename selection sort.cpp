#include<iostream>
using namespace std;
#define size 10
int n;
template<class T>
void selection(T A[size])
{
	int i,j,Min;
	T temp;
	for (i=0;i<=n-2;i++)
	{
		Min=i;
		for(j=i+1;j<=n-1;j++)
		{
			if (A[j]<A[Min])
			Min=j;
		}
		temp=A[i];
		A[i]=A[Min];
		A[Min]=temp;
	}
	cout<<"\nThe sorted list is:"<<endl;
	for (i=0;i<n;i++)
	cout<<"  "<<A[i];
}
int main()
{
	int i,A[size];
	float B[size];
	cout<<"\nSelection sort\n";
	cout<<"\n\nHandling integer elements"<<endl;
	cout<<"how many elements are there ?"<<endl;
	cin>>n;
	cout<<"enter the integer elements"<<endl;
	for(i=0;i<n;i++)
	cin>>A[i];
	selection(A);
	cout<<"\n\nhandling float elements:"<<endl;
	cout<<"how many elements are there?"<<endl;
	cin>>n;
	cout<<"enter the float elements:"<<endl;
	for(i=0;i<n;i++)
	cin>>B[i]; 
	selection(B);
	cout<<endl;
	return 0;
}

