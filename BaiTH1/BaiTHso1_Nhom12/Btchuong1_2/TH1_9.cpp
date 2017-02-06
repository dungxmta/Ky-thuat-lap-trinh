#include<stdio.h>

int ngay, thang, nam;
FILE *fi,*fo;

void Nhap()
{
	fi = fopen("TH1_9.inp","r");
	fscanf(fi,"%d%d%d",&ngay,&thang,&nam);
	fclose(fi);
}

void outFile()
{
	fo = fopen("TH1_9.out","w");
	fprintf(fo,"Ngay thang nhap vao la: %d/%d/%d",ngay,thang,nam);
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

