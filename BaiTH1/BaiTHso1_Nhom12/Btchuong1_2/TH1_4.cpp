#include<stdio.h>
#include<math.h>
#include<conio.h>

float a,x;
FILE *fi,*fo;

void Nhap()
{
	fi= fopen("TH1_4.inp", "r");
//	printf("Nhap co so a>0 va a#1, so x > 0: "); 
	fscanf(fi,"%f%f",&a,&x);
	fclose(fi);
}

float tinhLoga()
{
	float loga;
	loga = log(x)/log(a);
	return(loga);
}

void outFile()
{
	fo = fopen("TH1_4.out","w");
	if(x<0||a<0||a==1)
		fputs("Phep loga sai",fo);
	else
		fprintf(fo,"Loga co so %.3f cua %.3f la %.3f",a,x,tinhLoga());
		
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

