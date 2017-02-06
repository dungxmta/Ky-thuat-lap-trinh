//Doi 1 so nguyen ko am sang so nhi phan--
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//----------------------------------------
char filein[] = "Bai7_2.inp", fileout[] = "Bai7_2.out";
//----------------------------------------
typedef struct nodeStack
{
	int data;
	nodeStack *next;
};
typedef struct nodeStack *node;
//Cac thao tac co ban cua Stack------------
int initStack(node &);
node new_node();
int isEmpty(node &);
int push(node &, int );
int pop(node &, int &);
int makeEmpty(node &);
//-----------------------------------------
int nhap(FILE *, int &);
int doiCoso(int , node &);
int Hienthi(FILE *, node , int );
//-----------------------------------------
//MAIN-------------------------------------
int main()
{
    FILE *fi, *fo;
    int n;
    node top = new_node();
    initStack(top);
    nhap(fi, n);
    doiCoso(n, top);
    Hienthi(fo, top, n);
    makeEmpty(top);
    return 0;
}
//-----------------------------------------
//Nhap tu file
int nhap(FILE *fi, int &n)
{
	fi = fopen(filein, "r");
	fscanf(fi, "%d", &n);
fclose(fi);
}
//Hien thi
int Hienthi(FILE *fo, node top, int n)
{
    fo = fopen(fileout, "w");
    if(n>0)
    {
    	int out;
    	fprintf(fo, "%d co dang nhi phan la: ", n);
    	while(top != NULL)
    	{
    		pop(top, out);
    		fprintf(fo, "%d", out);
		}
	}
	else
		fprintf(fo, "So nhap vao phai la so nguyen duong!");
fclose(fo);
}
//Doi co so sang he 2
int doiCoso(int n, node &top)
{
	while(n>0)
	{
		push(top, n%2);
		n = n/2;
	}
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
int push(node &top, int value)
{
	node p = new_node();
	p->data = value;
	p->next = top;
	top = p;
return 1;
}
//pop = lay node dau
int pop(node &top, int &out)
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
