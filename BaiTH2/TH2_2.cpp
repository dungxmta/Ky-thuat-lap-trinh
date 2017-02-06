//Toi gian phan so
#include<stdio.h>
int tu, mau, uoc;
FILE *fi,*fo;

void nhap()
{
	fi = fopen("TH2_2.inp", "r");
	fscanf(fi, "%d%d", &tu, &mau);
	fclose(fi);
}
int UCLN(int a, int b)
{
	if(a%b==0) return b;
	else UCLN(b, a%b);
}
void hienthi()
{
	fo= fopen("TH2_2.out", "w");
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
void xuly()
{
	nhap();
	hienthi();
}
int main()
{
	xuly();
	return 0;
}
