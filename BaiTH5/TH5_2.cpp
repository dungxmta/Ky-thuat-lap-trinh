#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

FILE *fi, *fo;
char filein[] = "TH5.inp";
char fileout[] = "TH5_2.out";
//DSLK-----------------------
typedef struct DS
{
	int Giatri;
	struct DS *Tiep;
}pNut;
typedef pNut *Nut;
Nut	dau = NULL, cuoi = NULL;
//---------------------------
void docDS(FILE *fi, int &giatri_them);//doc DS tu file
void themDau(Nut &dau, Nut &cuoi, int giatri);//them ptu vao dau DS
void themCuoi(Nut &dau, Nut &cuoi, int giatri);//them ptu vao cuoi DS
void xoaNut(Nut dau, int giatri_xoa);//tim kiem va xoa 1 ptu trong DS
void Hienthi(FILE *fo, Nut dau, int giatri_xoa);//Hien thi DS

//MAIN----------------------------------------------------------------------
int main()
{
int giatri_xoa;
	docDS(fi, giatri_xoa);
	xoaNut(dau, giatri_xoa);
	Hienthi(fo, dau, giatri_xoa);
return 1;
}

//--------------------------------------------------------------------------
//Bai2---tim kiem va xoa 1 ptu trong DS co thu tu 'tang dan'
void xoaNut(Nut dau, int giatri_xoa)
{
	Nut p, q;
	
	if(dau == NULL)//ds rong~
		return;
	if(dau->Giatri == giatri_xoa)//gia tri can xoa la ptu dau tien
	{
		p = dau;
		dau = dau->Tiep;
		free(p);
	}
	else//ko phai ptu dau tien
	{
		q = dau;
		p = dau->Tiep;
		while(p != NULL && p->Giatri != giatri_xoa)
		{
			q = p;
			p = p->Tiep;
		}
		if(p != NULL)//neu tim dc 'p' tro? den gia tri can xoa
		{
			q->Tiep = p->Tiep;
			free(p);
		}	
	}
}
//them ptu vao dau DS
void themDau(Nut &dau, Nut &cuoi, int giatri)
{
	Nut p = (Nut)malloc(sizeof(pNut));
	p->Giatri = giatri;
	p->Tiep = dau;
	if(dau == NULL)
	{
		dau = p;
		cuoi = p;
	}
	else
		dau = p;
}
//them ptu vao cuoi ds
void themCuoi(Nut &dau, Nut &cuoi, int giatri)
{
	Nut p = (Nut)malloc(sizeof(pNut));
	p->Giatri = giatri;
	p->Tiep = NULL;
	if(dau == NULL)
		dau = p;
	else
		cuoi->Tiep = p;
	cuoi = p;
}
//doc DS tu file
void docDS(FILE *fi, int &giatri_xoa)
{
	int n, giatri;
	fi = fopen(filein, "r");
	
	fscanf(fi, "%d", &n);//so ptu cua DS
	fscanf(fi, "%d", &giatri_xoa);//ptu can tim va xoa khoi DS
	
	for(int i=0; i<n; i++)//doc gia tri vao cho DS
	{
		fscanf(fi, "%d", &giatri);
		themCuoi(dau, cuoi, giatri);
	}
	fclose(fi);
}
//Hien thi DS
void Hienthi(FILE *fo, Nut dau, int giatri_xoa)
{
	fo = fopen(fileout, "w");
	Nut p;	p = dau;
	
	if(p == NULL)
		fprintf(fo, "\nDS rong~~");
	else
	{
		fprintf(fo, "DS sau khi xoa phan tu %d:\n", giatri_xoa);
		while(p != NULL)
		{
			fprintf(fo, "%d ", p->Giatri);
			p = p->Tiep;
		}
	}
	fclose(fo);
}
