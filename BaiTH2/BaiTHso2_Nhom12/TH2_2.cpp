//Toi gian phan so
#include<stdio.h>

void nhap(char filename[50],int &tu,int &mau);
int UCLN(int tu, int mau);
void hienthi(char filename[50],int tu,int mau);

int main()
{
	char filename1[50]="TH2_2.inp";
	char filename2[50]="TH2_2.out";
	int tu,mau;
	nhap(filename1,tu,mau);
	hienthi(filename2,tu,mau);
	return 0;
}
//----------------------------------------------------
void nhap(char filename[50],int &tu,int &mau)
{
	FILE *fi;
	fi = fopen(filename, "r");
	fscanf(fi, "%d%d", &tu, &mau);
	fclose(fi);
}
int UCLN(int tu, int mau)
{
	if(tu%mau==0) return mau;
	else UCLN(mau, tu%mau);
}
void hienthi(char filename[50],int tu,int mau)
{
	int uoc;
	FILE *fo;
	fo= fopen(filename, "w");
	if(mau==0)
		fprintf(fo, "Mau so phai khac 0");
	else if(tu==0) 
			fprintf(fo, "%d / %d = 0", tu, mau);
		else
		{
			uoc= (tu>mau ? UCLN(tu, mau):UCLN(mau, tu));
			fprintf(fo, "%d / %d = %d / %d", tu, mau, tu/uoc, mau/uoc);
		}
	fclose(fo);
}

