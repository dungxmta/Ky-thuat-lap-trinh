#include<stdio.h>
#include<conio.h>

void nhap(int &x,int &n);
int TongA(int x,int n);
int TongB(int x,int n);
float TongC(int x,int n);
void hienthi(int x,int n);

int main()
{
	int x,n;
	
	nhap(x,n);
	hienthi(x,n);
	
	getch();
	return 0;
}
//------------------------------------------------------------------------
void nhap(int &x,int &n)
{
	printf("Nhap he so x: ");
	scanf("%d", &x);
	printf("Nhap so nguyen duong n: ");
	scanf("%d", &n);	
}

int TongA(int x,int n)
{
	int a=1, tg=x; //khai bao x la bien	toan cuc.nen khai bao bien trung gian = x de ko lam thay doi gia tri x
	for(int i=1; i<=n; i++)
	{
		a= a+tg;
		tg= tg*tg;
	}
	return a;
}

int TongB(int x,int n)
{
	int b=1, tg=x;
	for(int i=1; i<=n; i++)
	{
		b= b+tg;
		tg= (-1)*tg*tg;
	}
	return b;
}

float TongC(int x,int n)
{
	float c=1, tg=x;
	for(int i=1; i<=n; i++)
	{
		c= c+tg;
		tg= tg*tg/(i+1);
	}
	return c;
}
void hienthi(int x,int n)
{
	printf("1 + x + x^2 + x^3 +......+ x^n = %d\n\n", TongA(x,n));
	printf("1 - x + x^2 - x^3 +......(-1)^n*x^n = %d\n\n", TongB(x,n));
	printf("1 + x/1! + x^2/2! + x^3/3! +......+ x^n/n! = %.2f", TongC(x,n));
}


