#include<stdio.h>
#include<conio.h>

void Nhap(char filename[50],int &n,int &k);
int tinhToHop(int n,int k);
void hienthi(char filename[50],int n,int k);

int main()
{
	char filename1[50]="Bai8.inp";
	char filename2[50]="Bai8.out";
	int n,k;
	
	Nhap(filename1,n,k);
	hienthi(filename2,n,k);
	
	return 0;
}
//------------------------------------------
void Nhap(char filename[50],int &n,int &k)
{
	FILE *fi=fopen(filename,"r");
	fscanf(fi,"%d",&k);
	fscanf(fi,"%d",&n);
	fclose(fi);
}

int tinhToHop(int n,int k)
{
	if(k==0||k==n)
		return 1;
	if(k==1)
		return n;

	return tinhToHop(n-1,k)+tinhToHop(n-1,k-1);
}

void hienthi(char filename[50],int n,int k)
{
	FILE *fo=fopen(filename,"w");
	fprintf(fo,"To hop chap %d cua %d la %d",k,n,tinhToHop(n,k));
	fclose(fo);
}


