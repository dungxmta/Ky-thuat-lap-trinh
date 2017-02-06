#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//----------------------------------------
const int M = 20;//do dai max cua chuoi nhap vao
char filein[] = "NhapXuatFile.inp", fileout[] = "NhapXuatFile.out";

//Nhap tu file
void nhap(FILE *fi,int &n, char str[][M])
{
	fi = fopen(filein, "r");
	int i=0;//so chuoi~ trong DS

		fscanf(fi, "%d", &n);

		//fscanf(fi, "%s", str[0]); //str[0] = "Duong"
//			fgets(str[0], 20, fi);// str[0] = "\n"
//			fgets(str[1], 20, fi);// str[1] = "Duong..."
//			fgets(str[2], 20, fi);// str[2] = "Bui..."

	char temp[M];
		fgets(temp, M, fi);
	int j=0;
	while(!feof(fi))
	{
		fgets(str[j], M, fi);
		j++;
	}
fclose(fi);
}

//MAIN-------------------------------------
int main()
{
    FILE *fi, *fo;
    char str[5][20];
    int n;
    nhap(fi,n, str);

 printf("n = %d\n", n);

printf("str[0] = %s",str[0]);
printf("str[1] = %s",str[1]);
printf("str[2] = %s",str[2]);
 puts(str[0]);
 puts(str[1]);
 puts(str[2]);
 printf("n = %d", n);

return 0;
}
