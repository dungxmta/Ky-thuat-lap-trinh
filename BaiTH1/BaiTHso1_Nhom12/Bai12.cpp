#include<conio.h>
#include<stdio.h>
int arr[100];
int coso1=2,coso2=8,coso3=16;
FILE *fo;
void nhap()
{
	FILE *fi;
	if((fi=fopen("Bai12.inp","r"))==NULL)
		printf("Ko mo duoc file");
	for(int i=0;i<4;i++)
	fscanf(fi,"%d",&arr[i]);
	fclose(fi);
}
void doiCoSo(int n,int coso)
{
	int a[100];
	int i=0;
	printf("\nSo %d chuyen sang he co so %d la ",n,coso);
	while(n>0)
	{
		a[i]=n%coso;
		n=n/coso;
		i++;
	}
		for(int k=i-1;k>=0;k--)
		{
			printf("%d",a[k]);
			fprintf(fo,"%d",a[k]);
		}
}
void thucThi()
{
	fo=fopen("Bai12.out","w");
	for(int i=0;i<4;i++)
	{
			doiCoSo(arr[i],coso1);
			fputs("\n",fo);
			doiCoSo(arr[i],coso2);
			fputs("\n",fo);
			doiCoSo(arr[i],coso3);
			fputs("\n",fo);
			
	}
	fclose(fo);
}
int main()
{
	nhap();
	thucThi();
	getch();
	return 0;
}
