//so co 3 chu so chia het cho 3?
#include<stdio.h>
const int N=3;
void nhap(char[], int &);
bool kiemtra(int);
void Hienthi(int);

int main()
{
	int n;
	char filename[50]="Bai6.inp";
	nhap(filename,n);
	Hienthi(n);
	return 0;
}
//**********
void nhap(char filename[50], int &n)
{
	char c;
	FILE *fi= fopen(filename,"r");
	fscanf(fi, "%d", &n);
	fclose(fi);
}
bool kiemtra(int n)
{
	int Tong=0;
	for(int i=0; i<N; i++)
	{
		Tong= Tong + n%10;
		n= n/10;		
	}
	if(Tong%3==0)
		return true;
	else
		return false;
}
void Hienthi(int n)
{
	FILE *fo= fopen("Bai6.out", "w");
	if(kiemtra(n))
		fprintf(fo, "%d co chia het cho 3!", n);
	else 
		fprintf(fo, "%d ko chia het cho 3!", n);
	fclose(fo);
}
