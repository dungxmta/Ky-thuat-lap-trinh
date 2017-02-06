#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

FILE *fi, *fo;
char filein[] = "TH5_1.inp";
char fileout[] = "TH5_1.out";
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
void themNut(Nut &dau, int giatri_them);//them 1 ptu vao DS
void Hienthi(FILE *fo, Nut dau, int giatri_them);//Hien thi DS

//MAIN----------------------------------------------------------------------
int main()
{
int giatri_them;
	docDS(fi, giatri_them);
	themNut(dau, giatri_them);
	Hienthi(fo, dau, giatri_them);
return 0;
}

//--------------------------------------------------------------------------
//Bai1---them 1 ptu vao DS co thu tu 'tang dan' sao cho thu tu ko doi 
void themNut(Nut &dau, int giatri_them)
{
	Nut p = (Nut)malloc(sizeof(pNut));
	p->Giatri = giatri_them;
	
	if(dau == NULL || dau != NULL && dau->Giatri > giatri_them)
	{
		p->Tiep = dau;
		dau = p;
	}
	else
	{
		Nut q;	q = dau;
		while(q->Tiep != NULL && q->Tiep->Giatri < giatri_them)
			q = q->Tiep;
		p->Tiep = q->Tiep;//gan p vao trc phan tu co gia tri lon hon (q->tiep)
		q->Tiep = p;//cap nhat lai con tro q (sau q se la p)
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
void docDS(FILE *fi, int &giatri_them)
{
	int n, giatri;
	fi = fopen(filein, "r");
	
	fscanf(fi, "%d", &n);//so ptu cua DS
	fscanf(fi, "%d", &giatri_them);//ptu them vao DS
	
	for(int i=0; i<n; i++)//doc gia tri vao cho DS
	{
		fscanf(fi, "%d", &giatri);
		themCuoi(dau, cuoi, giatri);
	}
	fclose(fi);
}
//Hien thi DS
void Hienthi(FILE *fo, Nut dau, int giatri_them)
{
	fo = fopen(fileout, "w");
	Nut p;	p = dau;
	
	if(p == NULL)
		fprintf(fo, "\nDS rong~~");
	else
	{
		fprintf(fo, "DS sau khi them phan tu %d:\n", giatri_them);
		while(p != NULL)
		{
			fprintf(fo, "%d ", p->Giatri);
			p = p->Tiep;
		}
	}
	fclose(fo);
}
