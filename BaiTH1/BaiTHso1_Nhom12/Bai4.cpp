#include<conio.h>
#include<stdio.h>
#include<math.h>
int a,x;
float loga;
void nhap()
{
	FILE *fi;
	if((fi=fopen("Bai4.inp","r"))==NULL)
		printf("Ko mo duoc file");
	fscanf(fi,"%d",&a);
	fscanf(fi,"%d",&x);
	fclose(fi);
}
void tinhLog()
{
	loga=log10f(x)/log10f(a);
}
void hienThi()
{
	FILE *fo;
	if((fo=fopen("Bai4.out","w"))==NULL)
		printf("Ko mo duoc file");
	fputs("loga co so ",fo);
	fprintf(fo,"%d",a);
	fputs(" cua ",fo);
	fprintf(fo,"%d",x);
	fputs(" la ",fo);
	fprintf(fo,"%.2f",loga);
	fclose(fo);
	printf("logarit co so %d cua %d la %.2f",a,x,loga);
}
int main()
{
	nhap();
	tinhLog();
	hienThi();
	getch();
	return 0;
}
