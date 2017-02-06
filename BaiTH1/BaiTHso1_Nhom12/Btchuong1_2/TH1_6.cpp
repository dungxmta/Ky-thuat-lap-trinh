#include<stdio.h>

char c;

FILE *fi,*fo;

void Nhap()
{
	fi = fopen("TH1_6.inp","r");
	fscanf(fi,"%c",&c);
	fclose(fi);
}

void outFile()
{
	fo = fopen("TH1_6.out","w");
	fprintf(fo,"Ma ASCII cua %c la %d\n",c,c);
	fprintf(fo,"Ky tu tiep theo cua %c la %c",c,c+1);
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
