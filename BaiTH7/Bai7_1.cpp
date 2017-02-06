//Cac thao tac co ban cua Stack-----------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//----------------------------------------
char filein[] = "Bai7_1.inp", fileout[] = "Bai7_1.out";
//----------------------------------------
typedef struct nodeStack
{
	int data;
	nodeStack *next;
};
typedef struct nodeStack *node;
//-----------------------------------------
int initStack(node &);
node new_node();
int isEmpty(node &);
int push(node &, int );
int pop(node &, int &);
int makeEmpty(node &);
//-----------------------------------------
int nhap(FILE *, node &);
int Hienthi(FILE *, node );
//-----------------------------------------
//MAIN-------------------------------------
int main()
{
    FILE *fi, *fo;
    node top = new_node();
    initStack(top);
    nhap(fi, top);
    Hienthi(fo, top);
    return 0;
}
//-----------------------------------------
//Nhap tu file
int nhap(FILE *fi, node &top)
{
	fi = fopen(filein, "r");
	int a = 0, n;//n = so ptu cua stack
	fscanf(fi, "%d", &n);
	for(int i=0; i<n; i++)
    {
        fscanf(fi, "%d", &a);
        push(top, a);
    }
fclose(fi);
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
	// if(top == NULL)
	// 	return -1;
	node temp = new_node();
	while(top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
return 1;
}
//Hien thi
int Hienthi(FILE *fo, node top)
{
    fo = fopen(fileout, "w");
    //pop
    fprintf(fo, "Ngan xep:\n");
    node p = top;
    while(p != NULL)
    {
        fprintf(fo, "%d\n", p->data);
        p = p->next;
    }
    //pop
    int a = 0;
    pop(top, a);
    fprintf(fo, "NX sau khi lay ptu %d\n", a);
    node q = top;
    while(q != NULL)
    {
        fprintf(fo, "%d\n", q->data);
        q = q->next;
    }
    //makeEmpty
    fprintf(fo, "Lam rong~ NX...\n");
    makeEmpty(top);
    if(isEmpty(top) == -1)
        fprintf(fo, "\t\t\tNX rong~");
fclose(fo);
}
