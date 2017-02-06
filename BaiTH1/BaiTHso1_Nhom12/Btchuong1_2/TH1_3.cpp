#include<stdio.h>
#include<math.h>

float a,b,c;
FILE *fi,*fo;

void Nhap()
{
	fi = fopen("TH1_3.inp","r");
	fscanf(fi,"%f %f %f",&a,&b,&c);
	fclose(fi);
}

float ChuVi()
{
	float P;
	P = a+b+c;
	return(P);
}

float DienTich()
{
	float p;
	float S;
	p = (a+b+c)/2;
	S = sqrt(p*(p-a)*(p-b)*(p-c));
	return (S);
}

void outFile()
{
	fo = fopen("TH1_3.out","w");
	
	if(a<0||b<0||c<0||(a+b<=c)||(b+c<=a)||(a+c<=b))
	{
		fputs("Khong phai 3 canh cua tam giac",fo);
	}
	else
	{
		fprintf(fo," Chu vi = %.3f\n Dien tich = %.3f",ChuVi(),DienTich());
	}
	fclose(fo);
}

void xuly()
{
	Nhap();
	outFile();

}

int main()
{	
	xuly();
	return 0;
}

