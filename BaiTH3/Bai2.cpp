//Chu vi, Dien tich tam giac 
#include<stdio.h>
#include<math.h>

int a,b,c;

void nhap(char filename[50], int &a, int &b, int &c);
int ktra(int a, int b, int c);
float Chuvi(int a, int b, int c);
float Dientich(int a, int b, int c);
void Hienthi();

int main()
{
	char filename[50] = "Bai2.inp";
	nhap("Bai2.inp", a,b,c);
	Hienthi();
	return 0;
}
//*****************

void nhap(char filename[50], int &a, int &b, int &c)
{
	FILE *fi = fopen(filename, "r");
	fscanf(fi,"%d%d%d",&a,&b,&c);
	fclose(fi);
}

int ktra(int a, int b, int c)
{
	if(a>0 & b>0 & c>0)
		return ((a+b>c & a+c>b & b+c>a) ? 1:0);
	else
		return 0;
}

float Chuvi(int a, int b, int c)
{
	return (a+b+c);
}

float Dientich(int a, int b, int c)
{
	float p= (float)(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

void Hienthi()
{
	FILE *fo = fopen("Bai2.out", "w");
	if(ktra(a,b,c)==1)
		fprintf(fo,"Chu vi = %.3f\nDien tich = %.3f", Chuvi(a,b,c), Dientich(a,b,c));
	else
		fprintf(fo, "Ko tao thanh tam giac");
	fclose(fo);
}
