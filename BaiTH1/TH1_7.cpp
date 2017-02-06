#include<iostream>
#include<conio.h>
using namespace std;

float r,r1,r2,r3;

void nhap()
{
	cout<<"Nhap 3 gia tri dien tro R1, R2, R3 : ";
	cin>>r1>>r2>>r3;
}

void tongtro()
{
	r = 1/(1/r1 + 1/r2 + 1/r3);
}

void hienthi()
{
	cout<<"Tong tro R =  "<<r;
}

void xuly()
{
	nhap();
	if(r1>0 &r2>0 &r3>0)
	{
		tongtro();
		hienthi();
	}
	else
		cout<<"gia tri R phai >0";
}

int main()
{
	xuly();
	getch();
	return 0;
}
