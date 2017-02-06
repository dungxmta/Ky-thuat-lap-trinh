#include<stdio.h>

int x,y;
FILE *fi,*fo;

void Nhap()
{
	fi = fopen("TH1_11.inp","r");
	fscanf(fi,"%d%d",&x,&y);
	fclose(fi);
}

void outFile()
{
	fo=fopen("TH1_11.out","w");
	fprintf(fo,"Ket qua %d&%d la: %d\n",x,y,x&y);
	fprintf(fo,"Ket qua %d&%d la: %d\n",x,x,x&x);
	fprintf(fo,"Ket qua !%d&%d la: %d\n",x,y,!x&y);
	fprintf(fo,"Ket qua %d^%d^%d la: %d",x,y,y,x^y^y);
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
