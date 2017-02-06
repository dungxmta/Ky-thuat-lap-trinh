#include<conio.h>
#include<stdio.h>
float r,P,S,pi=3.14;
void nhap()
{
	FILE *fi;
	if((fi=fopen("Bai2.inp","r"))==NULL)
		printf("Ko mo duoc file");
	fscanf(fi,"%f",&r);
	fclose(fi);
}
void tinhChuVi()
{
	P=2*pi*r;
}
void tinhDienTich()
{
	S=pi*r*r;
}
void hienThi()
{
	FILE *fo;
	if((fo=fopen("Bai2.out","w"))==NULL)
		printf("Ko mo duoc file");
	fputs("Chu vi hin tron la:",fo);
	fprintf(fo,"%.2f",P);
	fputs("\nDien tich hinh tron la:",fo);
	fprintf(fo,"%.2f",S);
	fclose(fo);
	printf("Chu vi hin tron la: %.2f",S);
	printf("\nDien tich hinh tron la: %.2f",S);
}
int main()
{
	nhap();
	tinhChuVi();
	tinhDienTich();
	hienThi();
	getch();
	return 0;
}

