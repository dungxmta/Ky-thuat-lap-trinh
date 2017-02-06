#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void nhap(int &, int &, char &);
void Hienthi(int ,int ,char);

int main()
{
	int a,b;
	char ch;
	nhap(a,b,ch);
	Hienthi(a,b,ch);
	getch();
	return 0;
}
//*************
void nhap(int &a, int &b, char &ch)
{
	printf("Nhap 2 so nguyen a va b: ");
	scanf("%d%d", &a,&b);
	fflush(stdin);
	printf("Nhap 1 ky tu: '+' '-' '*' '/' de thuc hien cac phep toan tuong ung\n");
	ch= getch();
}
void Hienthi(int a, int b, char ch)
{
	switch(ch)
	{
		case '+':
			printf("%d + %d = %d", a, b, a+b);
			break;
		case '-':
			printf("%d - %d = %d", a, b, a-b);
			break;
		case '*':
			printf("%d * %d = %d", a, b, a*b);
			break;
		case '/':
			if(b!=0)
				printf("%d / %d = %.3f", a, b, (float)a/(float)b);
			else
				printf("ko the chia cho 0");
//			break;
	}
}

