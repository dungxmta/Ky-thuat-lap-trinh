#include<stdio.h>
#include<conio.h>

float toan,ly,hoa,TB;

void nhap()
{
	printf("Nhap diem 3 mon Toan, Ly, Hoa : ");
	scanf("%f%f%f", &toan,&ly,&hoa);
}

void trungbinh()
{
	TB=(toan+ly+hoa)/3;
}

void hienthi()
{
	printf("Diem so Trung binh = %.2f",TB);
}

void xuly()
{
	nhap();
	if(10>=toan &toan>=0 &10>=ly &ly>=0 &10>=hoa &hoa>=0)
	{
		trungbinh();
		hienthi();
	}else
		printf("Diem cac mon chi nam trog [0,10]");
}

int main()
{
	xuly();
	getch();
	return 0;
}
