#include<stdio.h>
#include<conio.h>

FILE *fo, *fi;

void ghi()
{
	fi = fopen("TH1_1.inp","r");
	fo = fopen("TH1_1.out","w");
	char c = fgetc(fi);
	while(!feof(fi))
		{
			fputc(c,fo);
//			fprintf(fo,"%c",c);
			c = fgetc(fi);
		}
	fclose(fi);
	fclose(fo);
}
int main()
{
	ghi();
	return 0;
} 
