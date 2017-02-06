#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stackNode
{
	char item;
	stackNode *next;
};
typedef struct stack{
	stackNode* top;
};
//-----------------------------------
void Input(FILE *, char *);
void init(stack *);
int empty(stack *);
int push(stack *,char );
int pop(stack *,char *);
void daoxau(FILE *,stack *, char []);
//-----------------------------------
FILE *f;
char filein[50]="InPut.INP";
char fileout[50]="OutPut.OUT";
stack s;
//------------------------------------
int main()
{
	int i;
	char c[500];
	Input(f,c);
	init(&s);
	daoxau(f,&s,c);
//	getch();
	return 0;
}
//-----------------------------------
void Input(FILE *f, char *c){
	f=fopen(filein,"rt");
	fgets(c,100,f);
	fclose(f);
}
//implemention
void init(stack *s) 
{ s->top=NULL; }
//---------------------------
int empty(stack *s)
{
	if(s->top==NULL) {
	return 0;
	}
	else {
	return 1;
	}
}
//-----------
//-1: cant push to stack
int push(stack *s,char value) {
	stackNode *a;
	a=(stackNode*)malloc(sizeof(stackNode));
	if(a==NULL) 
	{
		return -1;
	}
	a->item=value; 
	a->next=s->top;
	s->top=a;
	return 0;
}
//-------------
//-1: pop stack
int pop(stack *s,char *out)
{
	stackNode *cur;
	if(s->top==NULL) {
		return -1;
	}
	*out=s->top->item;
	cur=s->top; s->top=s->top->next;
	free(cur);
}
void daoxau(FILE *f,stack *s, char c[]){
	char v;
	for(int i=0;i<strlen(c);i++)
	{
		push(s,c[i]);
	}
	f=fopen(fileout,"wt");
	while(empty(s)!=0)
	{
		pop(s,&v);
//		fputs(&v,f);
		fprintf(f, "%c", v);
	}
	fclose(f);
}
