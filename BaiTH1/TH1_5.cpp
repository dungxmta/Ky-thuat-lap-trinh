#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

float xA,xB,yA,yB;

void nhap()
{
	cout<<"Nhap (xA,yA) = ";
	cin>>xA>>yA;
	cout<<"Nhap (xB,yB) = ";
	cin>>xB>>yB;
}

void hesogoc()
{
	if(xB-xA!=0)
		{
			cout<<"He so goc : "<<(yB-yA)/(xB-xA);
		}
	else
		cout<<"Ko tinh dc hsg";
}

void khoangcach()
{
	cout<<"\nKhoang cach : "<<sqrt((yB-yA)*(yB-yA) + (xB-xA)*(xB-xA));
}

void xuly()
{
	nhap();
	hesogoc();
	khoangcach();
}

int main()
{
	xuly();
	getch();
	return 0;
}
