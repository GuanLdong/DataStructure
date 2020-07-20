#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define OVERFLOW 2
#define ERROR 1
#define RED "\033[0;32;31m"
#define NONE "\033[m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[0;32;32m"

typedef int ElemType;
typedef int Status;

typedef struct Stack{
	ElemType data[MAXSIZE];
	int top;
}Stack;

Status InitStack(Stack *L){
	L->top = -1;
}

Status push(Stack *L,ElemType e){
	if (++L->top>MAXSIZE)
		return OVERFLOW;
	L->data[L->top] = e;
}
Status pop(Stack *L,ElemType *e){
	if(L->top==-1)
		return OVERFLOW;
	*e = L->data[L->top--];
}
Status PrintStack(Stack L){
	int i = -1;
	while(i != L.top){
		printf(YELLOW"%d\t"NONE,L.data[++i]);
	}
}
Status main(){
	ElemType e;
	Stack L;
	int length = 10;
	printf(GREEN"Init Stack..."NONE);
	InitStack(&L);
	printf(RED"\nPush elem:\n"NONE);
	while (length > 0){
		e = random()/10000;
		printf("%d\t",e);
		push(&L,e);
		length --;
	}
	printf("\nNow stack has...\n");
	PrintStack(L);
	printf("\nPop stack:\n");
	pop(&L,&e);
	printf(RED"%d"NONE,e);

	printf("\nNow stack has...\n");
	PrintStack(L);
}

