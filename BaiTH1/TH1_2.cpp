#include<iostream>
#include<fstream>
#define pi 3.14
//#include<conio.h>
using namespace std;

ifstream fi; //doc file <=> std::cin
ofstream fo; //ghi file <=> std::cout

float r, p, s;

void nhap(){
	fi.open("TH1_2.inp");
	fi>>r;
	fi.close();
}
void chuvi(){
//	std::cout<<"Chu vi = "<<2*pi*r<<"\n";
	p= 2*pi*r;
}
void dientich(){
//	std::cout<<"Dien tich = "<<pi*r*r<<endl;
	s= pi*r*r;
}
void hienthi(){
	fo.open("TH1_2.out");
	fo<<"Voi r = "<<r<<"\nChu vi = "<<p<<"\nDien tich = "<<s<<endl;
	fo.close();
}
void xuly(){
//	std::cout<<"Nhap r = ";
	nhap();
	chuvi();
	dientich();
	hienthi();
}

int main(){
	xuly();
//	getch();
	return 0;
}
