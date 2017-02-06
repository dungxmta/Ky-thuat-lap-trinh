//nhap thang->ngay
#include<stdio.h>

void nhap(char[], int &, int &);
bool Nhuan(int);
int Ngay(int, int);
void Hienthi(int, int);

int main()
{
	int mm,yy;
	char filename[50]="Bai5.inp";
	nhap(filename,mm,yy);
	Hienthi(mm,yy);
	return 0;
}
//**********
void nhap(char filename[50], int &mm, int &yy)
{
	char c;
	FILE *fi= fopen(filename,"r");
	fscanf(fi, "%d%c%d", &mm, &c, &yy);
	fclose(fi);
}
bool Nhuan(int yy)
{
	if(yy%4==0 && yy%100==0 || yy%400==0)
		return true;
	else
		return false;
}
void Hienthi(int mm, int yy)
{
	FILE *fo= fopen("Bai5.out", "w");
	if(mm>12 || mm<1 || yy<0)
		fprintf(fo, "Nhap loi^~!!!");
	else
		switch(mm)
		{
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:
				fprintf(fo, "Thang %d/%d co 31 ngay", mm, yy);
				break;
			case 4:case 6:case 9:case 11:
				fprintf(fo, "Thang %d/%d co 30 ngay", mm, yy);
				break;
			case 2:
				if(Nhuan(yy))
					fprintf(fo, "Thang %d/%d co 29 ngay", mm, yy);
				else
					fprintf(fo, "Thang %d/%d co 28 ngay", mm, yy);
				break;
		}
	fclose(fo);
}
