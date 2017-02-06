//Giai pt bac 2
#include<stdio.h>
#include<math.h>
//#include<conio.h>
//**************
void nhap(char filename[50], float &a, float &b, float &c);
float ptb1(float b, float c);
float Denta(float a,float b, float c);
void ptb2(float a, float b, float c, float &n1, float &n2);
void Hienthi(float a, float b, float c, float n1, float n2);

int main()
{
	float a,b,c,n1,n2;
	char filename[50]="Bai3.inp";
	nhap(filename,a,b,c);
	ptb2(a,b,c,n1,n2);
	Hienthi(a,b,c,n1,n2);
	return 0;
}
//*************
void nhap(char filename[50], float &a, float &b, float &c)
{
	FILE *fi = fopen(filename,"r");
	fscanf(fi, "%f%f%f", &a, &b, &c);
	fclose(fi);
}

float ptb1(float b, float c)
{
		return (-c/b);
}

float Denta(float a,float b, float c)
{
	return (b*b - 4*a*c);
}

void ptb2(float a, float b, float c, float &n1, float &n2)
{
	float denta = Denta(a,b,c);
	if(denta==0)
		n1= n2= -b/(2*a);
	else if(denta>0)
		{
		n1= (-b+sqrt(denta))/(2*a);
		n2= (-b-sqrt(denta))/(2*a);
		}
}
void Hienthi(float a, float b, float c, float n1, float n2)
{
	FILE *fo = fopen("Bai3.out","w");
	if(a==0 & b==0 & c==0)
		fprintf(fo, "Day ko phai la pt!");
	else
	{
		if(a==0)
		{
			if(b==0) 
				fprintf(fo, "pt vo nghiem!");
			else
				fprintf(fo, "pt co nghiem x = %f", ptb1(b,c));
		}
		else
		{
			if(Denta(a,b,c)<0)
				fprintf(fo, "pt vo nghiem!");
			else
				fprintf(fo, "x1= %f\nx2= %f", n1, n2);
		}
	}
	fclose(fo);
}
