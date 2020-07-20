#include <stdlib.h>
#include <stdio.h>
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

typedef struct Queue{
	ElemType data[MAXSIZE];
	int font;
	int rear;
}Queue;

Status InitQueue(Queue *L){
	L->font = -1;
	L->rear = -1;
	return OK;
}
Status IsEmpty(Queue L){
	if (L.font == L.rear)
		return TRUE;
	else
		return FALSE;
}
Status EnQueue(Queue *L,ElemType e){
	++L->rear;
	L->data[L->rear] = e;
	return OK;
}
Status DeQueue(Queue *L,ElemType *e){
	++L->font ;
	*e = L->data[L->font];
	return OK;
}
Status PrintQueue(Queue L){
	int length,i=1;
	length = L.rear-L.font;
	while(i<=length){
		printf(YELLOW"%d\t"NONE,L.data[L.font+i]);
		i++;
	}
}
Status GetLocationElem(Queue L,int Location,ElemType *e){
	if(Location>L.rear||Location<L.font)
		return OVERFLOW;
	*e = L.data[Location-1];
}

Status main(){
	Queue L;
	int length,i=0;
	length = 8;
	ElemType e;
	printf(GREEN"Init queue...\n"NONE);
	InitQueue(&L);
	printf("The queue is empty ? ");
	IsEmpty(L)?printf(YELLOW"Yes\n"NONE):printf(RED"No\n"NONE);
	printf(GREEN"En queue...\n"NONE);
	while(i<length){
		e= rand()/10000;
		EnQueue(&L,e);
		printf("%d\t",e);
		i++;
	}
	printf("\nNow queue has:\n");
	PrintQueue(L);
	printf("\nDe queue:");
	DeQueue(&L,&e);
	printf(RED"%d\n"NONE,e);
	printf("After Dequeue, queue has :\n");
	PrintQueue(L);
	printf("\nGet 6th elem:");
	GetLocationElem(L,6,&e);
	printf("%d\n",e);
}

