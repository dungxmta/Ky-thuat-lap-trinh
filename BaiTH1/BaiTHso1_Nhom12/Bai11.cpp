#include<conio.h>
#include<stdio.h>
int x,y;
void nhap()
{
	FILE *fi;
	if((fi=fopen("Bai11.inp","r"))==NULL)
		printf("Ko mo duoc file");
	fscanf(fi,"%d",&x);
	fscanf(fi,"%d",&y);
	fclose(fi);
}
void hienThi()
{
	FILE *fo;
	if((fo=fopen("Bai11.out","w"))==NULL)
		printf("Ko mo duoc file");
	fputs("Ket qua x&y la ",fo);
	fprintf(fo,"%d",x&y);
	fputs("\nKet qua x&x la ",fo);
	fprintf(fo,"%d",x&x);
	fputs("\nKet qua !x&y la ",fo);
	fprintf(fo,"%d",!x&y);
	fputs("\nKet qua x^y^y la ",fo);
	fprintf(fo,"%d",x^y^y);
	fclose(fo);
}
int main()
{
	nhap();
	hienThi();
	return 0;
}
