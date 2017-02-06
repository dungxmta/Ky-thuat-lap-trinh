#include<conio.h>
#include<stdio.h>
#include<math.h>
float a,b,c,P,S;
void nhap()
{
	FILE *fi;
	if((fi=fopen("Bai3.inp","r"))==NULL)
		printf("Kong mo duoc file");
	fscanf(fi,"%f",&a);
	fscanf(fi,"%f",&b);
	fscanf(fi,"%f",&c);
	fclose(fi);
}
int kTra(){
	if(a+b<=c||a+c<=b||b+c<=a)
		return 1;
	else 
		return 0;
}
void tinhChuVi()
{
	P=a+b+c;
}
void tinhDienTich()
{
	float p;
	p=(a+b+c)/2;
	S=sqrt(p*(p-a)*(p-b)*(p-c));
}
void hienThi()
{
	FILE *fo;
	if((fo=fopen("Bai3.out","w"))==NULL)
		printf("Kong mo duoc file");
	if(kTra()==1)
		fputs("Khong phai tam giac",fo);
	else
		{
			fputs("dien tich tam giac la: ",fo);
			fprintf(fo,"%f",S);
			fputs("\nChu vi tam giac la: ",fo);
			fprintf(fo,"%.2f",P);
		}
	fclose(fo);
	printf("dien tich tam giac la %.2f",S);
	printf("\nChu vi tam giac la %.2f",P);
}
int main()
{
	nhap();
	kTra();
	tinhChuVi();
	tinhDienTich();
	hienThi();
	return 0;
}

