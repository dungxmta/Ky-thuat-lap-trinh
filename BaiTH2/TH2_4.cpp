//ktra so chia het cho 3 (tong cac chu so chia het cho 3)
#include<stdio.h>

int n, tong=0;
FILE *fi,*fo;

void nhap()
{
	fi= fopen("TH2_4.inp", "r");
	fscanf(fi, "%d", &n);
	fclose(fi);
}
void Tong(int n)
{
	tong = tong + n%10;
	if(n!=0)
		Tong(n/10);
}
int ktra()
{
	return (tong%3==0 ? 1:0);
}
void hienthi()
{
	fo= fopen("TH2_4.out", "w");
	if(ktra()==1)
		fprintf(fo, "%d chia het cho 3", n);
	else
		fprintf(fo, "%d ko chia het cho 3", n);
	fclose(fo);
}
void xuly()
{
	nhap();
	Tong(n);
	hienthi();
}

int main()
{
	xuly();
	return 0;
}

