//Cac thao tac co ban cua Queue
#include<stdio.h>
#include<stdlib.h>
//-----------------------------------------------------------------------
char filein[] = "Bai7_7.inp", fileout[] = "Bai7_7.out";
//-----------------------------------------------------------------------
typedef struct nodeQueue
{
    int data;
    nodeQueue *next;
};
typedef struct nodeQueue *node;
//-----------------------------------------------------------------------
void initQueue(node &first, node &last);
node new_node();
int put(node &first, node &last, int value);
int get(node &first, node &last, int &out);
bool isEmpty(node &first);
//----------------------------------------------
void nhap(FILE *fi, node &first, node &last);
void inQueue(FILE *fo, node first);
void Hienthi(FILE *fo, node first, node last);
//-----------------------------------------------------------------------
//MAIN----------------------------------------------------------------
int main()
{
    FILE *fi, *fo;
    node first = new_node();
    node last = new_node();
    initQueue(first, last);

    nhap(fi, first, last);
    Hienthi(fo, first, last);
return 0;
}
//-----------------------------------------------------------------------
void nhap(FILE *fi, node &first, node &last)
{
    fi = fopen(filein, "r");
    int n,a = 0;
    fscanf(fi, "%d", &n);
    for(int i=0; i<n; i++)
    {
        fscanf(fi, "%d", &a);
        put(first, last, a);
    }
fclose(fi);
}
void Hienthi(FILE *fo, node first, node last)
{
    fo = fopen(fileout, "w");

   if(isEmpty(first))
        fprintf(fo, "Queue rong~");

    fprintf(fo, "Queue_Hang doi:\n");
    node p1 = first;
    inQueue(fo, p1);
//    while(first != NULL)
//    {
//        fprintf(fo,"%d\n", first->data);
//        first = first->next;
//    }
    int out;
    get(first, last, out);
    fprintf(fo, "\nQueue sau khi lay ptu %d\n", out);
    node p2 = first;
    inQueue(fo, p2);
}
void inQueue(FILE *fo, node first)
{
    while(first != NULL)
    {
        fprintf(fo, "%d\n", first->data);
        first = first->next;
    }
}
//----------------------------------------------
//khoi tao hang doi
void initQueue(node &first, node &last)
{
    first = NULL;
    last = NULL;
}
//khoi tao 1 node moi
node new_node()
{
    node p = (node)malloc(sizeof(nodeQueue));
return p;
}
bool isEmpty(node &first)
{
    if(first == NULL)
        return true;
    else
        return false;
}
//them node vao cuoi hang doi
int put(node &first, node &last, int value)
{
    node p = new_node();
    p->data = value;
    p->next = NULL;

    if(first == NULL)
    {
        first = p;
        last = p;
    }
    last->next = p;
    last = p;
return 0;
}
//lay node dau tien ra (-1: ko lay dc)
int get(node &first, node &last, int &out)
{
    node p;
    if(first == NULL)//ktra queue rong~
        return -1;

    out = first->data;
    p = first;
    first = first->next;
    if(first == NULL)//ktra neu co 1 phan tu
        last == NULL;
    free(p);
return 0;
}
