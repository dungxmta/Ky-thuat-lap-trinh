#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

FILE *fi, *fo;
char filein[] = "TH5_3.inp";
char fileout[] = "TH5_3.out";
//DSLK-----------------------
typedef struct DS
{
	int Giatri;
	struct DS *Tiep;
}pNut;
typedef pNut *Nut;
Nut	dau = NULL, cuoi = NULL;
//---------------------------
void docDS(FILE *fi);//doc DS tu file
void themDau(Nut &dau, Nut &cuoi, int giatri);//them ptu vao dau DS
void themCuoi(Nut &dau, Nut &cuoi, int giatri);//them ptu vao cuoi DS
void daoDS(Nut &dau);//dao DS
void Hienthi(FILE *fo, Nut dau);//Hien thi DS

//MAIN----------------------------------------------------------------------
int main()
{
	docDS(fi);
	daoDS(dau);
	Hienthi(fo, dau);
return 1;
}

//--------------------------------------------------------------------------
//Bai3---dao nguoc DS
void daoDS(Nut &dau)
{
	if(dau != NULL)//ds khac rong~
	{
		Nut p,q;
		p = dau;	q = dau->Tiep;
		p->Tiep = NULL;
		while(q != NULL)//cho q chay tu dau den cuoi ds
		{
			p = q;
			q = q->Tiep;
			p->Tiep = dau;
			dau = p;
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
void docDS(FILE *fi)
{
	int n, giatri;
	fi = fopen(filein, "r");
	
	fscanf(fi, "%d", &n);//so ptu cua DS
	
	for(int i=0; i<n; i++)//doc gia tri vao cho DS
	{
		fscanf(fi, "%d", &giatri);
		themCuoi(dau, cuoi, giatri);
	}
	fclose(fi);
}
//Hien thi DS
void Hienthi(FILE *fo, Nut dau)
{
	fo = fopen(fileout, "w");
	Nut p;	p = dau;
	
	if(p == NULL)
		fprintf(fo, "\nDS rong~~");
	else
	{
		fprintf(fo, "DS sau khi dao cac phan tu:\n");
		while(p != NULL)
		{
			fprintf(fo, "%d ", p->Giatri);
			p = p->Tiep;
		}
	}
	fclose(fo);
}
