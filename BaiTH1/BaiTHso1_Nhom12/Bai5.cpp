#include<conio.h>
#include<stdio.h>
#include<math.h>
float a1,a2,b1,b2,k,d;
void nhap()
{
	FILE *fi;
	if((fi=fopen("Bai5.inp","r"))==NULL)
		printf("Ko mo duoc file");
	fscanf(fi,"%f",&a1);
	fscanf(fi,"%f",&a2);
	fscanf(fi,"%f",&b1);
	fscanf(fi,"%f",&b2);
	fclose(fi);
}
void heSoGoc()
{
	k=(b2-b1)/(a2-a1);
}
void kCach()
{
	d=sqrt((b2-b1)*(b2-b1)+(a2-a1)*(a2-a1));
}
void hienThi()
{
	FILE *fo;
	if((fo=fopen("Bai5.out","w"))==NULL)
		printf("Ko mo duoc file");
	fputs("He so goc cau duong thang di qua 2 diem do la ",fo);
	fprintf(fo,"%.2f",k);
	fputs("\nkhoang cach giua hai diem do la ",fo);
	fprintf(fo,"%.2f",d);
	fclose(fo);
}
int main()
{
	nhap();
	heSoGoc();
	kCach();
	hienThi();
	return 0;
}
