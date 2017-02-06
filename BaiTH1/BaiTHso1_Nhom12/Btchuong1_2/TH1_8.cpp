#include<stdio.h>

float toan, ly, hoa;
FILE *fi, *fo;

void Nhap()
{
	fi = fopen("TH1_8.inp","r");
	fscanf(fi,"%f%f%f",&toan,&ly,&hoa);
	fclose(fi);
}

float diemTrungBinh()
{
	float tb;
	tb = (toan + ly + hoa)/3;
	return(tb);
}

void outFile()
{
	fo = fopen("TH1_8.out","w");
	if(toan<0||ly<0||hoa<0)
		fputs("Khong co diem am, nhap lai diem",fo);
	else
		fprintf(fo,"Diem trung binh 3 mon toan, ly va hoa la %.2f",diemTrungBinh());
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
