#include<conio.h>
#include<stdio.h>
float dtoan,dly,dhoa,TB;
void nhap()
{
	FILE *fi;
	if((fi=fopen("Bai8.inp","r"))==NULL)
		printf("Ko mo duoc file");
	fscanf(fi,"%f",&dtoan);
	fscanf(fi,"%f",&dly);
	fscanf(fi,"%f",&dhoa);
	fclose(fi);
}
void tinhDiemTB()
{
	TB=(dtoan+dly+dhoa)/3;
}
void hienThi()
{
	FILE *fo;
	if((fo=fopen("Bai8.out","w"))==NULL)
		printf("Ko mo duoc file");
	fputs("Diem trung binh cua hoc sinh la: ",fo);
	fprintf(fo,"%.2f",TB);
	fclose(fo);
}
int main()
{
	nhap();
	tinhDiemTB();
	hienThi();
	return 0;
}

