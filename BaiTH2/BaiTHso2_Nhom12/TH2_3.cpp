//Tong cac chu so cua 1 so nguyen
#include<stdio.h>

void nhap(char filename[50],int &n);
int Tong(int n);
void hienthi(char filename[50],int n);

int main()
{
	char filename1[50]="TH2_3.inp";
	char filename2[50]="TH2_3.out";
	int n;
	
	nhap(filename1,n);
	hienthi(filename2,n);
	
	return 0;
}
//------------------------------------------

void nhap(char filename[50],int &n)
{
	FILE *fi;
	fi= fopen(filename, "r");
	fscanf(fi, "%d", &n);
	fclose(fi);
}
int Tong(int n)
{
	int tong=0;
	while(n!=0)
	{
		tong+=n%10;
		n=n/10;
	}

	return tong;
}


void hienthi(char filename[50],int n)
{
	FILE *fo;
	fo= fopen(filename, "w");
	fprintf(fo, "Tong cac chu so cua %d la %d", n, Tong(n));
	fclose(fo);
}

