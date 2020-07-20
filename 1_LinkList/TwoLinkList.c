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

typedef struct LNode{
	ElemType elem;
	struct LNode *piror;
	struct LNode *next;
}LNode;

typedef LNode* LinkList;

Status InitList(LinkList *L){
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	(*L)->piror = NULL;
}
Status IsEmpty(LinkList L){
	if(L !=NULL && L->next == NULL)
		return TRUE;
	else
		return FALSE;
}
Status PrintLink(LinkList L){
	if(L==NULL)
		return OVERFLOW;
	LinkList p = L->next;
	while(p !=NULL){
		printf(YELLOW"%d\t"NONE,p->elem);
		p = p->next;
	}
	return OK;
}
Status GetLength(LinkList L){
	int i = 0;
	LinkList p=L->next;
	while(L!=NULL){
		p=p->next;
		i++;
	}
	return i;
}
Status InsertLink(LinkList L,int Location,ElemType e){
	// if(Location <0 || Location >GetLength(L))
	// return OVERFLOW;
	LinkList p = L,temp;
	InitList(&temp);
	if(Location<=0)
		return OVERFLOW;
	while(p->next!=NULL&&Location>0){
		p = p->next;
		Location--;
	}
	if (p->next == NULL && Location>1)
		return OVERFLOW;
	temp->elem = e;
	temp->next = p->next;
	p->next = temp;
	temp->piror = p;
	return OK;
}
Status DeleteElem(LinkList L,int Location,ElemType *e){
	LinkList p = L,temp;
	
	if(Location<=0)
		return OVERFLOW;
	while(p->next !=NULL&&Location >0){
		p = p->next;
		Location--;
	}
	if(p->next==NULL &&Location >1)
		return OVERFLOW;
	temp = p->piror;
	*e = p->elem;
	temp->next = p->next;
	p->next->piror = temp;
	free(p);
}

Status main(){
	LinkList L;
	int elem,length = 10;
	printf(GREEN"Init link list ...\n"NONE);
	InitList(&L);
	printf(GREEN"Insert elem...\n"NONE);
	while(length>0){
		elem = rand()/10000;
		printf(RED"%d\t",elem);
		--length;
		InsertLink(L,10-length,elem);
	}
	printf("\nLink list has:\n");
	PrintLink(L);
	printf(GREEN"\nDelete 6th elem:\n"NONE);
	DeleteElem(L,6,&elem);
	printf(RED"%d"NONE,elem);
	printf("\nLink list has:\n");
	PrintLink(L);
}
