#include<conio.h>
#include<stdio.h>
#include<math.h>
char A,a,Z,z;
int b=2,c=8;
FILE *fo;
void nhap()
{
	FILE *fi;
	if((fi=fopen("Bai13.inp","r"))==NULL)
		printf("Kong mo duoc file");
	fscanf(fi,"%c",&A);
	fscanf(fi,"%c",&a);
	fscanf(fi,"%c",&Z);
	fscanf(fi,"%c",&Z);
	fclose(fi);
}
	
void doiCoSo(int n,int coso)
{
	int arr[100];
	int i=0;
		while(n>0)
	{
		arr[i]=n%coso;
		n=n/coso;
		i++;
	}
		for(int k=i-1;k>=0;k--)
		{
			fprintf(fo,"%d",arr[k]);
		}
	
}
void thucThi()
{
	fo=fopen("Bai13.out","w");
	doiCoSo(A,b);
	fputs("\n",fo);
	doiCoSo(A,c);
	fputs("\n",fo);
	doiCoSo(Z,b);
	fputs("\n",fo);
	doiCoSo(Z,c);
	fputs("\n",fo);
	fclose(fo);
}
int main()
{
	nhap();
	thucThi();
	return 0;
}
