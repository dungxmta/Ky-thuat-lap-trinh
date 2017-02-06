#include<conio.h>
#include<stdio.h>
int a,b;
void nhap()
{
	FILE *fi;
	if((fi=fopen("Bai10.inp","r"))==NULL)
			printf("Ko mo duoc file");
	fscanf(fi,"%d",&a);
	fclose(fi);
}
void daoSo()
{
	b=a/100;
	b=b+(a%10)*100+((a/10)%10)*10;
}
void hienThi()
{
	FILE *fo;
	if((fo=fopen("Bai10.out","w"))==NULL)
		printf("Ko mo duoc file");
	fputs("So dao nguoc la ",fo);
	fprintf(fo,"%d",b);
	fclose(fo);
}
int main()
{
	nhap();
	daoSo();
	hienThi();
	return 0;
}
