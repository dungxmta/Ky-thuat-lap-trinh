#include<stdio.h>
#include<stdlib.h>
typedef struct stackNode
{
	int data;
	stackNode *next;
};
typedef struct stackNode *node;
//khoi tao
int initStack(node &top)
{
	top = NULL;
}
//them dau^'
int push(node &top, int value)
{
	node p = (node)malloc(sizeof(stackNode));
	if(p == NULL)
		return 1;
	p->data = value;
	p->next = top;
	top = p;
}
//lay dau^'
int pop(node &top, int &out)
{
	if(top == NULL)
		return 0;// = 0 la rong~
	node p = (node)malloc(sizeof(stackNode));
	out = top->data;
	p = top;
	top = top->next;
	free(p);
}
//ktra rong~
int isEmpty(node &top)
{
	if(top == NULL)
		return 0;
}
//lam rong~
int makeEmpty(node &top)
{
	while(top != NULL)
	{
		node p = top;
		top = top->next;
//		p->next = NULL;
		free(p);
	}
}
//hien thi
int Hienthi(node top)
{
	while(top != NULL)
	{
		printf("\t%d\n", top->data);
		top = top->next;
	}
}
//----------------------------------------------
int main()
{
	int n, value, out[10];
	node top;
//khoi tao
	initStack(top);
	if(isEmpty(top) == 0)
		printf("DS rong~\n");
//push
	printf("Nhap so phan tu DS: ");
	scanf("%d", &n);
	printf("Nhap cac ptu DS: ");
	for(int i=0, j=0; i<n; i++)
	{
		scanf("%d", &j);
		push(top, j);
	}
	//hien thi
	printf("NganXep:\n");
	Hienthi(top);
//pop
	printf("So ptu lay ra: ");
	scanf("%d", &n);
	printf("Cac ptu lay ra:\n");
	for(int i=0; i<n; i++)
	{
		pop(top, out[i]);
		printf("\t%d\n", out[i]);
	}
	//hien thi
	printf("NganXep moi:\n");
	Hienthi(top);
//makeEmpty
	printf("Lam rong~NganXep...\n");
	makeEmpty(top);
	if(isEmpty(top) == 0)
		printf("\t\tDS rong~\n");

return 0;
}
