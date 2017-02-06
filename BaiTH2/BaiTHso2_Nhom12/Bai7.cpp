#include<stdio.h>
#include<conio.h>
#include<math.h>

void Nhap(char filename[50],int &n);
void Phantich(char filename[50],int n);

int main()
{
	char filename1[50]="Bai7.inp";
	char filename2[50]="Bai7.out";
	int n;
	
	Nhap(filename1,n);
	Phantich(filename2,n);
	
	return 0;
}
//-----------------------------------------------
void Nhap(char filename[50],int &n)
{
	FILE *fi=fopen(filename,"r");
	fscanf(fi,"%d",&n);
	fclose(fi);
}

void Phantich(char filename[50],int n)
{
	FILE *fo=fopen(filename,"w");
	fprintf(fo,"%d=",n);
	for(int i=2;i<=n;i++)
    {
                     while(n%i==0)
                     {
                                  if(n==i)
                                  		fprintf(fo,"%d",i);
                                  else 
								  		fprintf(fo,"%d*",i);
                                  		n=n/i;
                      }
     
     }
    fclose(fo);
}


