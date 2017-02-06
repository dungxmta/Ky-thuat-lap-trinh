#include<conio.h>
#include<stdio.h>
float R1,R2,R3,R;
void nhap()
{
	printf("Nhap cac gia tri dien tro R1 R2 R3 lan luot: ");
	scanf("%f %f %f",&R1,&R2,&R3);
}
void tongTro()
{
	R=(R1*R2*R3)/(R1+R2+R3);
}
void hienThi()
{
	FILE *fo;
	if((fo=fopen("Bai7.out","w"))==NULL)
		printf("Ko mo duoc file");
	fputs("Tong tro toan mach la ",fo);
	fprintf(fo,"%.2f",R);
	fclose(fo);
	printf("Tong tro toan mach la %.2f",R);
}
int main()
{
	nhap();
	tongTro();
	hienThi();
	getch();
	return 0;
}
