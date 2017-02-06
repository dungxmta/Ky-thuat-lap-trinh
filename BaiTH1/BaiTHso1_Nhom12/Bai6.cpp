#include<conio.h>
#include<stdio.h>
char c;
void nhap()
{
	FILE *fi;
	if((fi=fopen("Bai6.inp","r"))==NULL)
		printf("Kong mo duoc file");
	fscanf(fi,"%c",&c);
	fclose(fi);
}
void hienThi()
{
	FILE *fo;
	if((fo=fopen("Bai6.out","w"))==NULL)
		printf("Kong mo duoc file");
	fputs("Ma ASCII cua ky tu ",fo);fprintf(fo,"%c",c);
	fputs(" la ",fo);fprintf(fo,"%d",c);
	fputs("\nMa ASCII cua ky tu tiep theo la ",fo);
	fprintf(fo,"%d",(c+1));
	printf("Ma ASCII cua ky tu %c la %d",c,c);
	printf("\nKy tu tiep theo la %c co ma ASCII la %d",(c+1),(c+1));
	fclose(fo);
}
int main()
{
	nhap();
	hienThi();
	return 0;
}
