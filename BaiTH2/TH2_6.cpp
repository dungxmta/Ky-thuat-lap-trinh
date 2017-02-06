#include<stdio.h>
#include<conio.h>
int n, x;

void nhap()
{
	printf("Nhap he so x: ");
	scanf("%d", &x);
	printf("Nhap so nguyen duong n: ");
	scanf("%d", &n);	
}
int TongA()
{
	int a=1, tg=x; //khai bao x la bien	toan cuc.nen khai bao bien trung gian = x de ko lam thay doi gia tri x
	for(int i=1; i<=n; i++)
	{
		a= a+tg;
		tg= tg*x;
	}
	return a;
}
int TongB()
{
	int b=1, tg=-x;
	for(int i=1; i<=n; i++)
	{
		b= b+tg;
		tg= (-1)*tg*x;
	}
	return b;
}
float TongC()
{
	float c=1, tg=x;
	for(int i=1; i<=n; i++)
	{
		c= c+tg;
		tg= tg*x/(i+1);
	}
	return c;
}
void hienthi()
{
//	FILE *fo;
//	fo= fopen("TH2_6.out","w");
	printf("1 + x + x^2 + x^3 +......+ x^n = %d\n\n", TongA());
	printf("1 - x + x^2 - x^3 +......(-1)^n*x^n = %d\n\n", TongB());
	printf("1 + x/1! + x^2/2! + x^3/3! +......+ x^n/n! = %.2f", TongC());
}
void xuly()
{
	nhap();
	if(n<0)
		printf("Nhap n>0");
	else
		hienthi();
}

int main()
{
	xuly();
	getch();
	return 0;
}
