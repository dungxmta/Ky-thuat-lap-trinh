#include<stdio.h>
#include<math.h>

float a, b, c, d;
FILE *fi, *fo;

void Nhap()
{
	fi = fopen("TH1_5.inp","r");
	fscanf(fi,"%f %f",&a,&b);
	fscanf(fi,"%f %f",&c,&d);
	fclose(fi);
}

float heSoGoc()
{
	float tanx;
	tanx = (d-b)/(c-a);
	return(tanx);
}

float khoangCach()
{
	float D;
	D = sqrt((d-b)*(d-b) + (c-a)*(c-a));
	return(D);
}

void outFile()
{
	fo = fopen("TH1_5.OUT","w");
	if((c-a)==0&&(d-b)==0)
	{
		fputs("Hai diem trung nhau, khong co he so goc va khoang cach",fo);
	}
	else if((c-a)==0)
	{
		fprintf(fo,"Duong thang qua hai diem vuong goc truc hoanh\nKhoang cach hai diem la d = %.3f",khoangCach());
	}
	else
	{
		fprintf(fo,"He so goc cua duong thang = %.3f\n",heSoGoc());
		fprintf(fo,"Khoang cach giua hai diem d = %.3f",khoangCach());
	}
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

