#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
////
char filein[] = "Bai5_1.inp";
char fileout[] = "Bai5_1.out";
//DSLK
typedef struct DS
{
	int Giatri;
	struct DS *Tiep;
}Nut;
Nut *dau, *cuoi;
//them ptu vao dau DS
void themDau(Nut *(&dau), Nut *(&cuoi), int giatri)//<<-----------
	Nut *p = (Nut*)malloc(sizeof(Nut));
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
void themCuoi(Nut *dau, Nut *cuoi, int giatri)//truyen ts sai
{
	Nut *p = (Nut*)malloc(sizeof(Nut));
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
	Nut *dau1 = NULL,*dau2 = NULL, *dau3 = NULL,*dau4 = NULL, *dau5 = NULL,
		*cuoi1 = NULL, *cuoi2 = NULL, *cuoi3 = NULL, *cuoi4 = NULL, *cuoi5 = NULL;
	int n, giatri, new_giatri;
	fi = fopen("Bai5.inp", "r");
	
	fscanf(fi, "%d", &n);//so ptu cua DS
	fscanf(fi, "%d", &giatri_them);//ptu them vao
	
	for(int i=0; i<n; i++)//doc gia tri vao cho 5 DS
	{
		fscanf(fi, "%d", &giatri);
		themCuoi(&dau1, &cuoi1, giatri), themCuoi(&dau2, &cuoi2, giatri), themCuoi(&dau3, &cuoi3, giatri), themCuoi(&dau4, &cuoi4, giatri), themCuoi(&dau5, &cuoi5, giatri);
	}
	fclose(fi);
}
//Hien thi DS
void Hienthi(FILE *fo, Nut *dau)
{
	Nut *p;	p = dau;
	
	if(p == NULL)
		fprintf(fo, "\nDS rong~~");
	else
		while(p != NULL)
		{
			fprintf(fo, "%d ", p->Giatri)
			p = p->Tiep;
		}
	fclose(fo);
}
//---------------------------------------------------------
//Bai1---them 1 ptu vao DS co thu tu 'tang dan' sao cho thu tu ko doi 
void themNut(Nut *dau, int giatri_them)
{
	Nut *p = (Nut*)malloc(sizeof(Nut));
	p->Giatri = giatri_them;
	
	if(dau == NULL || dau != NULL && dau->Giatri > giatri_them)
	{
		p->Tiep = dau;
		dau = p;
	}
	else
	{
		Nut *q;	q = dau;
		while(q->Tiep != NULL && q->Tiep->Giatri < giatri_them)
			q = q->Tiep;
		p->Tiep = q->Tiep;//gan p vao trc phan tu co gia tri lon hon (q->tiep)
		q->Tiep = p;//cap nhat lai con tro q (sau q se la p)
	} 
}
//Bai2---tim kiem va xoa 1 ptu trong DS co thu tu 'tang dan'
void xoaNut(Nut *dau, int giatri_xoa)
{
	Nut *p, *q;
	
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
//Bai3---dao nguoc DS
void daoDS(Nut *dau)
{
	if(dau != NULL)//ds khac rong~
	{
		Nut *p, *q;
		p = dau;
		q = dau->Tiep;
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
//Bai 4---xoa cac so nguyen le khoi DS
void xoaLe(Nut *dau)
{
	Nut *p, *q;
	while(dau != NULL && dau->Giatri % 2 != 0)//lap den khi 'dau' la so chan
	{
		p = dau;
		dau = dau->Tiep;
		free(p);	
	}
	q = dau;
	while(q != NULL)
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
//Bai5---tach DS thanh 2 DS chan~ va le?
void tachDS(Nut *dau, Nut *dau_chan, Nut *dau_le)
{
	Nut *cuoi_chan = NULL, *cuoi_le = NULL;
	Nut *q;	q = dau;
	while(q != NULL)
	{
		if(q->Giatri % 2 == 0)
			themCuoi(&dau_chan, &cuoi_chan, q->Giatri);
		else
			themCuoi(&dau_le, &cuoi_le, q->Giatri);
		q = q->Tiep;
	}
}         
