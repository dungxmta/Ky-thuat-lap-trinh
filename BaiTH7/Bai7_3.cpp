//Dao ngc 1 xau ky tu
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//----------------------------------------
const int M = 100;//do dai max cua chuoi nhap vao
char filein[] = "Bai7_3.inp", fileout[] = "Bai7_3.out";
//----------------------------------------
typedef struct nodeStack
{
	char data;
	nodeStack *next;
};
typedef struct nodeStack *node;
//Cac thao tac co ban cua Stack------------
int initStack(node &);
node new_node();
int isEmpty(node &);
int push(node &, char );
int pop(node &, char &);
int makeEmpty(node &);
//-----------------------------------------
void nhap(FILE *, char *);
void daoXau(char *, char *);
void Hienthi(FILE *, char *);
//-----------------------------------------
//MAIN-------------------------------------
int main()
{
    FILE *fi, *fo;
    char str[M], str_out[M];
   
    nhap(fi, str);
    daoXau(str, str_out);
    Hienthi(fo, str_out);
return 0;
}
//-----------------------------------------
//Dao xau ky tu
void daoXau(char *str, char *str_out)
{
	node top = new_node();
    initStack(top);
    
	int n = strlen(str);
	char out;
	
	for(int i= 0; i<n; i++)
	{
		push(top, str[i]);
	}
	for(int i=0; i<n; i++)
	{
		pop(top, out);
		str_out[i] = out;
	}
	
makeEmpty(top);
}
//Nhap tu file
void nhap(FILE *fi, char *str)
{
	fi = fopen(filein, "r");
	fgets(str, M, fi);
fclose(fi);
}
//Hien thi
void Hienthi(FILE *fo, char *str_out)
{
    fo = fopen(fileout, "w");
    int n = strlen(str_out);
    fputs("Xau dao nguoc la: ", fo);
    fputs(str_out, fo);
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
int push(node &top, char value)
{
	node p = new_node();
	p->data = value;
	p->next = top;
	top = p;
return 1;
}
//pop = lay node dau
int pop(node &top, char &out)
{
	if(top == NULL)
		return -1;
	out = top->data;
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
