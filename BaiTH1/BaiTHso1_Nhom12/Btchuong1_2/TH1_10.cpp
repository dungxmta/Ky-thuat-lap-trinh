#include<stdio.h>

int x;
FILE *fi,*fo;

void Nhap()
{
	fi = fopen("TH1_10.inp","r");
	fscanf(fi,"%d",&x);
	fclose(fi);
}

int daoNguocSo()
{
	int b;
	b = (x%10)*100 + (x/100) + (x - (x%10) - ((x/100)*100) );
	return b;
}

void outFile()
{
	fo = fopen("TH1_10.out","w");
	fprintf(fo,"So dao nguoc cua %d la %d",x,daoNguocSo());
	fclose(fo);
}

void xuly()
{
	Nhap();
	outFile();
}

int main()
{
	xuly();
	return 0;
}
