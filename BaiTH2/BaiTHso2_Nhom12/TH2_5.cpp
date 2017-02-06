//tam giac Pascal
#include<stdio.h>
#include<conio.h>

void nhap(int &n);
int toHop(int k, int n);
void Pascal(int n);

int main()
{
	int n;
	
	nhap(n);
	Pascal(n);
	
	getch();
	return 0;
}
//-----------------------------------------
void nhap(int &n)
{
	printf("Nhap so hang cho tam giac Pascal: ");
	scanf("%d", &n);
}

int giaiThua(int k)
{
	if(k==0)
		return 1;
	return k*giaiThua(k-1);
}

int toHop(int k, int n)
{
	return ( giaiThua(n) / ( giaiThua(k)*giaiThua(n-k) ));
}

void Pascal(int n)
{
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<=i; k++)
		{
			printf("%d\t", toHop(k,i));
		}
		printf("\n");
	}
}

