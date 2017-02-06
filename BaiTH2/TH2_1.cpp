//Tong, Hieu, Max, Doi cho, UCLN cua 2 so
#include<stdio.h>
//#define swap(p, q) v = p; p = q; q = v;
int a, b;
FILE *fi,*fo;

void nhap()
{
	fi=fopen("TH2_1.inp","r");
	fscanf(fi, "%d%d", &a,&b);
	fclose(fi);
}
int max()
{
	return (a>b? a:b);
}
int Tong()
{
	return a+b;
}
int Hieu()
{
	return a-b;
}
void swap()
{
	int i=a; a=b; b=i;
}
int UCLN(int a, int b)
{
	if(a%b==0) return b;
	else UCLN(b, a%b);
}
void hienthi()
{
	fo= fopen("TH2_1.out","w");
	fprintf(fo, "a = %d, b = %d\n",a,b);
	fprintf(fo,"Max(%d,%d) = %d\n",a,b,max());
	fprintf(fo,"%d + %d = %d\n%d - %d = %d\n",a,b,Tong(),a,b,Hieu());
	swap();
	fprintf(fo,"Sau khi doi cho: a = %d, b = %d\n",a,b);
	if(a<b) swap();
	fprintf(fo,"UCLN(%d,%d) = %d",a,b,UCLN(a,b));
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
