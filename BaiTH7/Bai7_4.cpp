//Dao ngc 1 Danh sach Sinh vien
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//----------------------------------------
const int M = 30;//do dai max cua chuoi nhap vao
char filein[] = "Bai7_4.inp", fileout[] = "Bai7_4.out";
//----------------------------------------
typedef struct nodeStack
{
	char data[M];
	nodeStack *next;
};
typedef struct nodeStack *node;
//Cac thao tac co ban cua Stack------------
int initStack(node &);
node new_node();
int isEmpty(node &);
int push_str(node &top, char value[]);
int pop_str(node &top, char *out);
int makeEmpty(node &);
//-----------------------------------------
void nhap(FILE *fi,int &n, char str[][M]);
void daoDS(int n, char str[][M], char str_out[][M]);
void Hienthi(FILE *fo, int n,char str[][M], char str_out[][M]);
//-----------------------------------------
//MAIN-------------------------------------
int main()
{
    FILE *fi, *fo;
    int n;//so chuoi~ trong DS
	char str[10][M], str_out[10][M];
   		nhap(fi, n, str);
		daoDS(n, str, str_out);
    	Hienthi(fo, n, str, str_out);
return 0;
}
//-----------------------------------------
//Dao xau ky tu
void daoDS(int n, char str[][M], char str_out[][M])
{
	node top = new_node();
    initStack(top);
	
	for(int i= 0; i<n; i++)
	{
		push_str(top, str[i]);
	}
	for(int i=0; i<n; i++)
	{
		pop_str(top, str_out[i]);
	}	
	
makeEmpty(top);
}
//Nhap tu file
void nhap(FILE *fi,int &n, char str[][M])
{
	fi = fopen(filein, "r");
	
	fscanf(fi, "%d", &n);//so chuoi~ trong DS
		char enter[2];//luu ky tu "\n" sau khi nhap n = ham' fscanf va cac chuoi str ta nhap = ham' fgets
		fgets(enter, 2, fi);
	
	int i=0;
	while(!feof(fi))
	{
		fgets(str[i], M, fi);//fgets nhap tu dau chuoi~den 'het' M ky tu or 'het' ky tu "\n" hay 'gap' ky tu EOF
		i++;
	}
fclose(fi);
}
//Hien thi
void Hienthi(FILE *fo, int n,char str[][M], char str_out[][M])
{
    fo = fopen(fileout, "w");

    fputs("DS ban dau:\n", fo);
    for(int i=0; i<n; i++)
    {
    	fputs(str[i], fo);
	}
	fputs("\nDS sau khi dao nguoc:\n", fo);
    for(int i=0; i<n; i++)
    {
    	fputs(str_out[i], fo);
	}
fclose(fo);
}
//khoi tao Stack
int initStack(node &top)
{
	top = NULL;
}
//khai bao new node
node new_node()
{
	node p = (node)malloc(sizeof(nodeStack));
	return p;
}
//-1 = empty
int isEmpty(node &top)
{
	if(top == NULL)
		return -1;
	return 1;
}
//push = them node dau
int push_str(node &top, char value[])
{
	node p = new_node();
	strcpy(p->data, value);
	p->next = top;
	top = p;
return 1;
}
//pop = lay node dau
int pop_str(node &top, char *out)
{
	if(top == NULL)
		return -1;
	strcpy(out, top->data);
//	out = top->data;
	node temp = new_node();
	temp = top;
	top = top->next;
	free(temp);
return 1;
}
//xoa Stack
int makeEmpty(node &top)
{
	node temp = new_node();
	while(top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
return 1;
}
