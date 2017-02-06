#include<stdio.h>
#include<conio.h>
int main()
{
	FILE *fi,*fo;
	int c;
	if((fi=fopen("Bai1.inp","r"))==NULL)
		printf("Ko mo duoc file");
	if((fo=fopen("Bai1.out","w"))==NULL)
		printf("ko the mo tep");
	while((c=fgetc(fi))!=EOF)
	{
		fputc(c,fo);
		printf("%c",c);
	}
	fclose(fi);
	fclose(fo);
	getch();
	return 0;
}
