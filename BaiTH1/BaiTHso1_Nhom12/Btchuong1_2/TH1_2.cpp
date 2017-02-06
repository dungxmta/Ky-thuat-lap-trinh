#include<stdio.h>
#include<iostream>
#define Pi 3.14

float r;
FILE *fi,*fo;

void nhap()
{
	fi = fopen("TH1_2.inp","r");
	fscanf(fi,"%f",&r);
	fclose(fi);
}

float chuvi()
{
	float P;
	P = 2*Pi*r;
	return(P);
}

float dtich()
{
	float S;
	S = Pi*r*r;
	return(S);
}

void outFile()
{
	fo = fopen("TH1_2.out","w");
	
	if(r<=0)
		fputs("Khong ton tai hinh tron voi ban kinh R<=0",fo);
	else
		fprintf(fo, "Chu vi = %.3f \nDien tich = %.3f",chuvi(),dtich());
		
	fclose(fo);	
}
 void xuly()
 {
 	nhap();
 	outFile();
 }

int main()
{
	xuly();
	return 0;
}

