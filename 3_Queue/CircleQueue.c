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
#define BLUE                    "\e[0;34m"      //深蓝，暗蓝
#define L_BLUE                "\e[1;34m"        //亮蓝，偏白灰

typedef int ElemType;
typedef int Status;

typedef struct CycleQueue{
	ElemType *elem;
	int front;
	int rear;
}CycleQueue;

Status InitCycleQueue(CycleQueue *L){
	printf(GREEN"Init cycling queue...\n"NONE);
	(*L).elem = (ElemType *)malloc(sizeof(CycleQueue)*MAXSIZE);
	if ((*L).elem == NULL)
		return OVERFLOW;
	(*L).front = (*L).rear = 0;
}

Status IsEmpty(CycleQueue L){

	printf("Is empty ? ");
	(L.front == L.rear)?printf(YELLOW"YES\n"NONE):printf(YELLOW"NO\n"NONE);
}

Status EnQueue(CycleQueue *L, ElemType e){
	printf(GREEN"Enqueue %d \n"NONE,e);
	if (((*L).front+1)%MAXSIZE==(*L).rear)
		return OVERFLOW;
	(*L).elem[(*L).front] = e;
	(*L).front = ((*L).front+1)%MAXSIZE;
}
Status Dequeue(CycleQueue *L,ElemType *e){
	if((*L).rear+1>(*L).front)
		return OVERFLOW;
	*e = (*L).elem[(*L).rear];
	printf(RED"Dequeue %d\n"NONE,*e);
	(*L).rear = ((*L).rear+1)%MAXSIZE;
}
Status PrintCycleQueue(CycleQueue L){
	int length =(L.front-L.rear)%MAXSIZE;
	int i = 0;
	printf("Now the queue has: \n");
	while(i<length){
		printf("%d\t",L.elem[(L.rear+i)%MAXSIZE]);
		i++;
	}
	printf("\n");
}
Status GetLocation(CycleQueue L,int Location,ElemType *e){
	if (Location<1 || Location>(L.front - L.rear))
		return OVERFLOW;
	*e = L.elem[(L.rear+Location-1)%MAXSIZE];
	printf (BLUE"the %dth's elem is %d\n"NONE,Location,*e);
}
Status ClearCycleQueue(CycleQueue *L){
	printf(GREEN"clearing queue ...\n"NONE);
	(*L).front = (*L).rear =0;
}
Status DestoryQueue(CycleQueue *L){
	if((*L).elem)
		free((*L).elem);
	(*L).elem = NULL;
	(*L).rear = (*L).front = 0;
}

Status main(){
	CycleQueue L;
	int i =0;
	ElemType e;
	InitCycleQueue(&L);
	IsEmpty(L);
	while(i<10){
		EnQueue(&L,rand()/10000);
		i++;
	}
	IsEmpty(L);
	PrintCycleQueue(L);
	for (i=0;i<2;i++)
		Dequeue(&L,&e);
	PrintCycleQueue(L);
	GetLocation(L,8,&e);
	ClearCycleQueue(&L);
	IsEmpty(L);
}
