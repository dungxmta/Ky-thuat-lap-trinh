#include<stdio.h>
#include<conio.h>

void nhap(int &a, int &b, int &c);
int Max(int a,int b, int c);
void Hienthi(int m);

int main()
{
	int a,b,c;
	nhap(a,b,c);
	int m = Max(a,b,c);
	Hienthi(m);
	getch();
	return 0;	
}

void nhap(int &a, int &b, int &c)
{
	printf("Nhap 3 so: ");
	scanf("%d%d%d", &a, &b, &c);
}
int Max(int a,int b, int c)
{
	if(a>b)
		return (a>c ? a:c);
	else 
		return (b>c ? b:c);
}
void Hienthi(int m)
{
	printf("Max = %d", m);
}
