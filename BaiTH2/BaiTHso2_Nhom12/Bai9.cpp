#include<stdio.h>
#include<conio.h>

void Nhap(char filename[50],int &n);
int Fibonacci(int n);
void Hienthi(char filename[50],int n);

int main()
{
	char filename1[50]="Bai9.inp";
	char filename2[50]="Bai9.out";
	int n;
	
	Nhap(filename1,n);
	Hienthi(filename2,n);
	
	return 0;
}
//--------------------------------------------
void Nhap(char filename[50],int &n)
{
	FILE *fi=fopen(filename,"r");
	fscanf(fi,"%d",&n);
	fclose(fi);
}

int Fibonacci(int n)
{
	if(n<=2) 
		return 1;
    else 
		return Fibonacci(n-1) + Fibonacci(n-2);
}

void Hienthi(char filename[50],int n)
{
	FILE *fo=fopen(filename,"w");
	for(int i=1;i<=n;i++)
		fprintf(fo,"%d  ",Fibonacci(i));
	fclose(fo);
}


