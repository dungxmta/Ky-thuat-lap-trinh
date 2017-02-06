//Tong cac chu so cua 1 so nguyen
#include<stdio.h>

int n, tong=0;
FILE *fi,*fo;

void nhap()
{
	fi= fopen("TH2_3.inp", "r");
	fscanf(fi, "%d", &n);
	fclose(fi);
}
//void Tong(int n)
//{
//	tong= tong+ n%10;
//	if(n!=0)
//	{
//		Tong(n/10);
//	}
//}
int Tong(int n)
{
	if(n==0)
		return 0;
	return (tong+ n%10+ Tong(n/10));
}


void hienthi()
{
	fo= fopen("TH2_3.out", "w");
	fprintf(fo, "Tong cac chu so cua %d la %d", n, tong);
	fclose(fo);
}
void xuly()
{
	nhap();
	tong= Tong(n);
	if(n<0) 
		tong= (-tong);
	hienthi();
}

int main()
{
	xuly();
	return 0;
}
