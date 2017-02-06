#include<stdio.h>

float R[3];
FILE *fi,*fo;

void Nhap()
{
	fi = fopen("TH1_7.inp","r");
	for(int i=0;i<3;i++)
		{
			fscanf(fi,"%f",&R[i]);
		}
	fclose(fi);
}

float tongTro()
{
	float Rtong = 0;
	
	for(int i=0;i<3;i++)
		{
			if(R>0)
			Rtong = Rtong+1/R[i];
		}
	Rtong = 1/Rtong;
	return(Rtong);
}

void outFile()
{
	fo = fopen("TH1_7.out","w");
	if(R[0]<0||R[1]<0||R[2]<0)
		fputs("Khong co dien tro < 0",fo);
	else
		fprintf(fo,"Tong tro cua mach dien la %.3f",tongTro());
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
