//Tong, Hieu, Max, Doi cho, UCLN cua 2 so
#include<stdio.h>

void nhap(char filename[50],int &a,int &b);
int max(int a,int b);
int Tong(int a,int b);
int Hieu(int a,int b);
void swap(int &a,int &b);
int UCLN(int a, int b);
void hienthi(char filename[50],int a,int b);

int main()
{
	char filename1[50]="TH2_1.inp";
	char filename2[50]="TH2_1.out";
	int a,b;
	nhap(filename1,a,b);
	hienthi(filename2,a,b);
	return 0;
}
//--------------------------------------------------

void nhap(char filename[50],int &a,int &b)
{
	FILE *fi;
	fi=fopen(filename,"r");
	fscanf(fi, "%d%d", &a,&b);
	fclose(fi);
}
int max(int a,int b)
{
	return (a>b? a:b);
}
int Tong(int a,int b)
{
	return a+b;
}
int Hieu(int a,int b)
{
	return a-b;
}
void swap(int &a,int &b)
{
	int i=a; a=b; b=i;
}
int UCLN(int a, int b)
{
	if(a%b==0) return b;
	else UCLN(b, a%b);
}
void hienthi(char filename[50],int a,int b)
{
	FILE *fo;
	fo= fopen(filename,"w");
	fprintf(fo, "a = %d, b = %d\n",a,b);
	fprintf(fo,"Max(%d,%d) = %d\n",a,b,max(a,b));
	fprintf(fo,"%d + %d = %d\n%d - %d = %d\n",a,b,Tong(a,b),a,b,Hieu(a,b));
	swap(a,b);
	fprintf(fo,"Sau khi doi cho: a = %d, b = %d\n",a,b);
	if(a<b) swap(a,b);
	fprintf(fo,"UCLN(a,b) = %d",a,b,UCLN(a,b));
	fclose(fo);
}

