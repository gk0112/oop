#include<iostream>
using namespace std;
class complex
{
	float real,img;
	public:
		complex()
		{
			real=0;
			img=0;
		}
		complex operator+(complex&);
		complex operator*(complex&);
		complex(float,float);
		friend istream &operator>>(istream&,complex&);
		friend ostream &operator<<(ostream&,complex&);
};
complex::complex(float x,float y)
{
	real=x;
	img=y;
}
istream &operator>>(istream&din,complex&c)
{
	cout<<"enter the real part of the complex number:";
	din>>c.real;
	cout<<"enter the imag part of the complex number:";
	din>>c.img;
	return din;
}
ostream &operator<<(ostream&dout,complex&c)
{
	dout<<c.real<<"+"<<c.img<<"i"<<endl;
	return dout;
}
complex complex::operator+(complex&c)
{
	complex temp;
	temp.real=real+c.real;
	temp.img=img+c.img;
	return temp;
}
complex complex::operator*(complex &c)
{
	complex temp;
	temp.real=(c.real*real)-(img*c.img);
	temp.img=(real*c.img)+(c.real*img);
	return temp;
}
int main()
{
	complex c1,c2,c3,c4;
	cout<<"enter the complex number 1:"<<endl;
	cin>>c1;
	cout<<"enter the complex number 2:"<<endl;
	cin>>c2;
	c3=c1+c2;
	cout<<"the additon of two complex number is:"<<c3<<endl;
	c4=c1*c2;
	cout<<"the multiplicaiton of the two number is:"<<c4<<endl;
	return 0;
}
