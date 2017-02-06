#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

FILE *fi, *fo;
char filein[] = "TH5_5.inp";
char fileout[] = "TH5_5.out";
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
void tachDS(Nut &dau, Nut &dau_chan, Nut &dau_le);//tach thanh 2 DS chan/le
void Hienthi(FILE *fo, Nut dau_chan, Nut dau_le);//Hien thi DS

//MAIN----------------------------------------------------------------------
int main()
{
Nut dau_chan = NULL, dau_le = NULL;
	docDS(fi);
	tachDS(dau, dau_chan, dau_le);
	Hienthi(fo, dau_chan, dau_le);
return 1;
}

//--------------------------------------------------------------------------
//Bai5---tach DS thanh 2 DS chan/le
void tachDS(Nut &dau, Nut &dau_chan, Nut &dau_le)
{
	Nut cuoi_chan = NULL, cuoi_le = NULL;
	Nut q = dau;
	
	while(q != NULL)
	{
		if(q->Giatri % 2 == 0)
			themCuoi(dau_chan, cuoi_chan, q->Giatri);
		else
			themCuoi(dau_le, cuoi_le, q->Giatri);
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
void Hienthi(FILE *fo, Nut dau_chan, Nut dau_le)
{
	fo = fopen(fileout, "w");
	Nut p = dau_chan, q = dau_le;
	
	if(p == NULL)
		fprintf(fo, "\nDS rong~~");
	else
	{
		fprintf(fo, "DS sau cac phan tu chan:\n");
		while(p != NULL)
		{
			fprintf(fo, "%d ", p->Giatri);
			p = p->Tiep;
		}
		
		fprintf(fo, "\nDS sau cac phan tu le:\n");
		while(q != NULL)
		{
			fprintf(fo, "%d ", q->Giatri);
			q = q->Tiep;
		}
	}
	fclose(fo);
}
