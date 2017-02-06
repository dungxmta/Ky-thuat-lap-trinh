#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	char c;
	fflush(stdin);
	printf("Nhap vao 1 ky tu : ");
	c=getchar();
	printf("Ma ASCII : %d", c);
	printf("\nKy tu tiep theo : %c",c+1);
	getch();
	return 0;
}
