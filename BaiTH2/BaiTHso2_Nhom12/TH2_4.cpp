//ktra so chia het cho 3 (tong cac chu so chia het cho 3)
#include<stdio.h>

void nhap(char filename[50],int &n);
int Tong(int n);
int ktra(int tong);
void hienthi(char filename[50],int n);

int main()
{
	char filename1[50]="TH2_4.inp";
	char filename2[50]="TH2_4.out";
	int n;
	
	nhap(filename1,n);
	hienthi(filename2,n);
	
	return 0;
}
//-----------------------------------------------------------------
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

int ktra(int tong)
{
	return (tong%3==0 ? 1:0);
}

void hienthi(char filename[50],int n)
{
	FILE *fo;
	fo= fopen(filename, "w");
	if(ktra(Tong(n))==1)
		fprintf(fo, "%d chia het cho 3", n);
	else
		fprintf(fo, "%d ko chia het cho 3", n);
	fclose(fo);
}


