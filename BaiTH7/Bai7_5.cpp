//Cac thao tac co ban cua Stack-----------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//----------------------------------------
char filein[] = "Bai7_5.inp", fileout[] = "Bai7_5.out";
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
void demNode(int &n, node top);
void out_n(node top, int n, int &out);
int del_n(node &top, int n);
int Hienthi(FILE *, node );
//-----------------------------------------
//MAIN-------------------------------------
int main()
{
    FILE *fi, *fo;
    int n;//so phan tu cua stack
    node top = new_node();
    initStack(top);

    nhap(fi, top);
//    demNode(n, top);
    Hienthi(fo, top);
return 0;
}
//-----------------------------------------
//Dem so phan tu
void demNode(int &n, node top)
{
    n = 0;
	while(top != NULL)
    {
        n++;
        top = top->next;
    }
}
//Xuat noi dung phan tu thu n
void out_n(node top, int n, int &out)
{
    int i = 0;
    while(top != NULL)
    {
        if(i == n)
        {
            out = top->data;
            break;
        }
        top = top->next;
        i++;
    }
}
//Loai bo phan tu thu n
int del_n(node &top, int n)
{
    if(top == NULL)
        return -1;

    node del = new_node();

     if(n == 1)
     {
           del = top;
           top = top->next;
           free(del);
           return 0;
     }

    int i=0;
    node temp = new_node();
    temp = top;

    while(temp != NULL)
    {
        if(i == n-1)
        {
            del = temp->next;
            temp->next = del->next;
            free(del);
            break;
        }
        temp = temp->next;
        i++;
    }
}
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
    fprintf(fo, "Stack:\n");
    node p = top;
    while(p != NULL)
    {
        fprintf(fo, "%d\n", p->data);
        p = p->next;
    }
    //dem so ptu
    int a = 0;
    demNode(a, top);
    fprintf(fo, "Stack co %d  ptu\n", a);
    //xuat ptu thu n
    out_n(top, 3, a);
    fprintf(fo, "Phan tu thu 3 cua Stack la: %d\n", a);
    //loai ptu thu n
    del_n(top,3);
    fprintf(fo, "Stack sau khi xoa phan tu thu 2:\n");
    while(top != NULL)
    {
        fprintf(fo, "%d\n", top->data);
        top = top->next;
    }
    //makeEmpty
    fprintf(fo, "Lam rong~ NX...\n");
    makeEmpty(top);
fclose(fo);
}
