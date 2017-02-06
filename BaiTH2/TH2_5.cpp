//tam giac Pascal
#include<stdio.h>
#include<conio.h>

int n, c, k=0;

void nhap()
{
	printf("Nhap so hang cho tam giac Pascal: ");
	scanf("%d", &n);
}
int P(int n)
{
	if(n==0)
		return 1;
	return n*P(n-1);
}
int C(int k, int n)
{
	return ( P(n) / ( P(k)*P(n-k) ));
}
void Pascal()
{
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<=i; k++)
		{
			printf("%d\t", C(k,i));
		}
		printf("\n");
	}
}
void xuly()
{
	nhap();
	Pascal();
}

int main()
{
	xuly();
	getch();
	return 0;
}
