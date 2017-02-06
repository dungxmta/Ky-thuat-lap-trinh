#include<iostream>
//#include<fstream>
#include<conio.h>
#include<math.h>
using namespace std;

//ifstream fi;
//ofstream fo;

float a,b,c;

void nhap()
{
	cin>>a>>b>>c;	
}

int kiemtra()
{
	return ((a>0& b>0& c>0& a+b>c& a+c>b& b+c>a) ? 1:0);
}

float chuvi()
{
	return (a+b+c);
}

float dientich()
{
	float p = chuvi()/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

void hienthi()
{
	cout<<"Chu vi = "<<chuvi()<<"\nDien tich = "<<dientich()<<endl;
}

void xuly()
{
	cout<<"Nhap do dai 3 canh tam giac : ";
	nhap();
	if(kiemtra()==1)
	{
		chuvi();
		dientich();
		hienthi();
	}
	else
		cout<<"Do dai da nhap ko tao thanh 1 tam giac";
}

int main()
{
	xuly();
	getch();
	return 0;
}
