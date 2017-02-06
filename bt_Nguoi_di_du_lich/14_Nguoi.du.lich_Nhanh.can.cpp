// NguoiDuLich
#include<stdio.h>
#include<stdlib.h>//2 thu vien dung cho ham random
#include<time.h>
//#include<conio.h>
#define VC 1000
#define STP 10//so thanh pho
#define DXP 0//thanh pho xuat phat dau tien

void Input(int n, int C[][STP]);
void Output(int httu[], int gttu, int n, int C[][STP]);

void Init(int n, int C[][STP], int daxet[], int &Cmin, int &gttu, int &S, int x[]);
void Gan(int httu[], int gttu, int x[], int n);
void Try(int i, int n, int C[][STP],  int daxet[], int Cmin, int &gttu, int S, int x[], int httu[]);

int main()
{
	int C[STP][STP];
	//=  {


	/* data[3]
	{VC, 1,65,57,66,71, VC,85,88,93 },
	{VC, VC,1, 77,51, VC, VC, VC,99,115 },
	{ 82, VC, VC,1,93,114, 100,50,49, VC },
	 {69,42,90, VC,1,117,44,62,66,118 },
	{93,41,69, VC, VC, 1, VC, VC, 77,95 },
	{ 116,41,44, 64,91, VC,1,85, 63,41 },
	{ 65,46,52, VC, VC,77, VC,1,83,43 },
	{ 83,98, VC,64, 49,72,116, VC,1,99 },
	{ 99, VC, VC, 77,78,79,50, VC, VC, 1 },
	{ 1, VC,116, VC,63,41,55,88,98, VC }
	};//[4]
    */
    /* data[2]
    {VC, VC, 1, VC,59, 63, VC,55, VC,67 },
	{VC, VC, VC, VC, 4,58, 55,60,84,100 },
	{VC, 5, VC,58,68, 89, VC, 5, VC, VC },
	{100,67, VC, VC, 77, 1, 99, VC, 55, VC },
	{VC,67, VC,2, VC, VC, VC, VC, 69, VC },
	{63,117, VC, VC, VC, VC, VC, 87, 2,44 },
	{1, VC, VC,64,88, VC, VC, 1, VC,98 },
	{10, 3, VC,100, 68, VC, 79, VC, VC, VC },
	{VC, VC, 99, VC, VC, VC, VC, VC, VC, 9 },
	{VC, VC,100, VC,80,75, 5, VC, 9, VC }
	};//[3]
    */
    /* data[1]
                    {VC, 2,44, 55,VC, 36,49,VC,45, 39 },
                    {12, VC,VC,1,48,VC,23,33, VC,VC },
                    {31,36, VC, VC,6,48,VC, 8,48, VC },
                    { 43,42,2, VC,35,42,25, VC,36, 35 },
                    {11,37,23,44, VC, 5, VC,28,44, VC },
                    { 24,51,33,49, 4, VC, 8,29,29,38 },
                    { 42,11, 8, VC, 2,50, VC,1, VC,40 },
                    {40,23,30,18, VC,15,40, VC, 2,36 },
                    { 50,27, 2, 44,50, VC,51, VC,VC, 4 },
                    { 2,49,7,28, VC,17,35, VC,43, VC }
                    };//[1]
    */
	/* 6x6
        {{VC, 20, 15,VC,80,VC},{40,VC,VC,VC,10,30},{20,4,VC,VC,VC,10},{36,18,15,VC,VC,VC},{VC,VC,90,15,VC,VC},{VC,VC,45,4,10,VC}};
	*/
    /* 5x5
        { {  VC, 3, 14, 18, 15 },{  3, VC, 4, 22, 20 },{  17, 9, VC, 16, 4 },{  6, 2, 7, VC, 12 },{  9, 15, 11, 5, VC } };
    */

	int x[STP], daxet[STP], Cmin, S;
	int httu[STP], gttu;//httu: hanh trinh toi uu, gttu: gia tri toi uu f*

    srand(time(NULL));//dung cho ham random
    Input(STP, C);

	Init(STP, C, daxet, Cmin, gttu, S, x);
	Try(1, STP, C, daxet, Cmin, gttu, S, x, httu);

    Output(httu, gttu, STP, C);
//	getchar();
	return 0;
}
//--------------------------------------------------------------------------
//nhap du lieu random
void Input(int n, int C[][STP])
{
    int i, j, k, rd[n];
    //random 10 so se~ duoc gan' = VC
    for(i=0; i<n; i++)
        rd[i] = 1 + rand()%21;
    //gan' C[i][j]
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(i==j)//gan' duong cheo = VC
                C[i][j] = VC;
            else
            {
                //random[1->20], random[a->b]: a+rand()%(b-a+1)
                C[i][j] = 1 + rand()%11;
                //gan' cac phan tu co gia tri = 10 so duoc chon = VC
//                for(k=0; k<n; k++)
//                {
//                    if(C[i][j]==rd[k])
//                        C[i][j] = VC;
//                }
            }
        }
}
//khai bao
void Init(int n, int C[][STP], int daxet[], int &Cmin, int &gttu, int &S, int x[])
{
	int i, j;
	Cmin = VC;//quang duong nho nhat giua hai thanh pho

	for (i=0; i<n; i++)
	{
	    daxet[i] = 0;//cap nhat daxet[0->n]=0
		for (j=0; j<n; j++)
		{
			if (Cmin > C[i][j])
				Cmin = C[i][j];//cap nhat cho Cmin
		}
	}
	S = 0;//tong quang duong luc dau
	gttu = VC;//gia tri toi uu f*

	x[0] = DXP;//dinh? xuat phat
    daxet[DXP] = 1;
}
//cap nhat hanh trinh toi uu
void Gan(int httu[], int gttu, int x[], int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        httu[i] = x[i];
        printf("%2d ", httu[i]+1);//in ra tat ca cac hanh trinh co the
    }
    printf("- Gttu: %3d\n", gttu);
}
//thu?
void Try(int i, int n, int C[][STP],  int daxet[], int Cmin, int &gttu, int S, int x[], int httu[])
{
	int j, tong, g;
    /*
	tong = tong chi phi khi them chi phi tu n ve 0
	g = ham danh gia can = S+(n-i+1)Cmin
	*/
	for (j=1; j<n; j++)//note: neu dinh xuat phat = 0 thi chi can duyet tu j=1, neu DXP#0->j=0
	{
//	    if(j==DXP)
//                continue;
		if (!daxet[j])
		{
			x[i] = j;
			daxet[j] = 1;
			S = S + C[x[i-1]][x[i]];
			if (i==n-1)//cap nhat Hanh trinh toi uu moi
			{
				tong = S + C[x[n-1]][x[0]];// tong chi phi ca quay ve dinh dau tien
				if (tong < gttu)
				{
				    gttu = tong;//cap nhat lai f*
					Gan(httu, gttu, x, n);//cap nhat Hanh trinh toi uu
				}
			}
			else
			{
				g = S + (n-i+1)*Cmin; //danh gia lai can
				if (g < gttu)
					Try(i+1, n, C, daxet, Cmin, gttu, S, x, httu);
			}
			S = S - C[x[i-1]][x[i]];
			daxet[j] = 0;
		}
	}
}
//in kq
void Output(int httu[], int gttu, int n, int C[][STP])
{
    int i, j;

    printf("\nMa tran khoang cach ban dau:\n\t");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(C[i][j]==VC)
            {
                printf("%3c ", 'x');
                continue;
            }
            printf("%3d ", C[i][j]);
        }
        printf("\n\t");
    }

    if(gttu==VC)
    {
        printf("\nKhong tim thay duong di nao!");
    }
    else
    {
        printf("\nHanh trinh toi uu: ");
        for(i=0; i<n; i++)
        {
            printf("%d~", httu[i]+1);
            if(i==n-1)
                printf("%d", httu[0]+1);
        }
        printf("\nTong chi phi: %d\n", gttu);
    }
}
