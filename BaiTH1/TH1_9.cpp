#include<stdio.h>
#include<conio.h>
//------------------------------------------------------------
int ngay, thang, nam, i=0;
FILE *fo;
//---------------------------
char fileout[] = "TH1_9.out";
//------------------------------------------------------------
void nhap();
int ktra();
void hienthi();
//------------------------------------------------------------
//MAIN--------------------------------------------------------
int main()
{
	nhap();
	fo = fopen(fileout, "w");
	ktra();
	if(i==0)
		{ hienthi();}
	fclose(fo);
	getch();
return 0;
}
//------------------------------------------------------------
void nhap()
{
	printf("Nhap ngay / thag / nam (vd: 25/12/1995) - ");
//	scanf("%d%d%d", &ngay, &thang, &nam);
	scanf("%d", &ngay);getchar();
	scanf("%d", &thang);getchar();
	scanf("%d", &nam);
}

int ktra()
{
	if(ngay>0 && thang>0 && nam>=0)
		switch(thang){
			case 2:
				if(nam%4==0&& nam%100==0|| nam%400==0)
					{if(ngay>29) { printf("Thang 2 nam nay co 29 ngay"); i++; fprintf(fo,"Thang 2 nam nay co 29 ngay");}}
				else
					{if(ngay>28) { printf("Thang 2 nam nay co 28 ngay"); i++; fprintf(fo,"Thang 2 nam nay co 28 ngay");}}
				break;
			case 4: case 6: case 9:	case 11:
				if(ngay>30) { printf("Thang nay chi co 30 ngay"); i++; 		  fprintf(fo,"Thang nay chi co 30 ngay");}
				break;
			case 1: case 3: case 5: case 7:	case 8: case 10: case 12:
				if(ngay>31) { printf("Thang nay chi co 31 ngay"); i++;		  fprintf(fo,"Thang nay chi co 31 ngay");}
				break;
			default :
				printf("loi~"); 
				fprintf(fo,"loi~");
				i++; 
				break; 
		}
	else 
	{
		printf("ko ton tai ngay/thang/nam am");
		fprintf(fo,"ko ton tai ngay/thang/nam am");
		i++;
	}
}

void hienthi()
{
//hien thi len mh
	printf("=> %02d/%02d/%d", ngay, thang, nam);
//hien thi ra file
	fprintf(fo, "=> %02d/%02d/%d", ngay, thang, nam);
}

