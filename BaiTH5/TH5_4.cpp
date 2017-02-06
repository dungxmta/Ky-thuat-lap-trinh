#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

FILE *fi, *fo;
char filein[] = "TH5_4.inp";
char fileout[] = "TH5_4.out";
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
void xoaLe(Nut &dau);//xoa cac ptu le trong DS
void Hienthi(FILE *fo, Nut dau);//Hien thi DS

//MAIN----------------------------------------------------------------------
int main()
{
	docDS(fi);
	xoaLe(dau);
	Hienthi(fo, dau);
return 1;
}

//--------------------------------------------------------------------------
//Bai 4---xoa cac so nguyen le khoi DS
void xoaLe(Nut &dau)
{
	Nut p, q;
	while(dau != NULL && dau->Giatri % 2 != 0)//lap den khi 'dau' la so chan
	{
		p = dau;
		dau = dau->Tiep;
		free(p);	
	}
	q = dau;
	while(q != NULL && q->Tiep)
	{
		if(q->Tiep->Giatri %2 != 0)
		{
			p = q->Tiep;
			q->Tiep = p->Tiep;
			free(p);
		}
		else
			q = q->Tiep;
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
		fprintf(fo, "DS sau khi xoa cac phan tu le:\n");
		while(p != NULL)
		{
			fprintf(fo, "%d ", p->Giatri);
			p = p->Tiep;
		}
	}
	fclose(fo);
}
