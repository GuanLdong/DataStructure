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
    ElemType data;
    struct LNode *next;
}LNode;

typedef LNode *LinkList;

Status InitLinkList(LinkList* L){
    (*L) = (LinkList)malloc(sizeof(LNode));
    if(*L == NULL) {
        printf(RED"Malloc Memory fault!"NONE);
        return OVERFLOW;
    }
    (*L)->next = NULL;
    return OK;
}

Status LinkListLength(LinkList L){
    int i;
    if(L == NULL || L->next == NULL)
        return 0;
    LinkList P = L->next;
    for (i = 1;P->next!=NULL;i++)
        P = P->next;
    return i;
}

Status LinkListInsert(LinkList L,int l,ElemType e){
    if (L==NULL)
        return ERROR;
    LinkList s,p;
    p = L;
    int j = 0;
    while(p->next != NULL && j<l-1){
        p = p->next;
        j++;
    }
    if(p == NULL || j>l-1){
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(LNode));
    if (s == NULL)
        return OVERFLOW;
    s->data = e;
    s->next = p->next;
    p->next = s;
}

Status IsEmpty(LinkList L){
    if(L!=NULL && L->next == NULL)
        return TRUE;
    else
        return FALSE;
}

Status ClearList(LinkList *L){
    LinkList pre,p;
    if((*L)==NULL)
        return OVERFLOW;
    p = *L;
    while(p!=NULL){
        pre= p;
        p = p->next;
        free(pre);
    }
    (*L)->next=NULL;
}

Status GetElem(LinkList L,int i,ElemType *e){
    if(L == NULL)
        return ERROR;
    LinkList p = L;
    int j = 0;
    while(p->next!= NULL && j<i-1){
        p = p->next;
        ++j;
    }
    if(p ==NULL || j>i-1)
        return ERROR;
    *e = p->next->data;
}

Status NextElem(LinkList L,ElemType tar,ElemType *e){
    if(L==NULL || L->next == NULL)
        return OVERFLOW;
    LinkList pre,p;
    p = L->next;
    while(p !=NULL && p->data !=tar){
        p = p->next;
    }
    if(p==NULL) return ERROR;
    *e = p->next->data;
    return OK;
}

Status PriorElem(LinkList L,ElemType tar,ElemType *e){
    if(L==NULL ||L->next ==NULL) return OVERFLOW;
    LinkList p,pre;
    pre = L->next;
    if(pre->data == tar)
        return OVERFLOW;
    p= pre->next;
    while(p!=NULL && p->data !=tar){
        pre= p;
        p = p->next;
    }
    if(p==NULL) return ERROR;
    *e = pre->data;
    return OK;

}

Status DestoryLink(LinkList *L){
    LinkList pre,p;
    p = *L;
    if (*L==NULL ) return OVERFLOW;
    while (p!=NULL){
        pre = p;
        p = p->next;
        free(p);
    }
    *L = NULL;
}

Status DeleteElem(LinkList L,int i,ElemType *e){
    if(L == NULL || L->next == NULL)
        return OVERFLOW;
    int j = 0;
    LinkList temp,p;
    p= L;
    while(j<i-1 && p!=NULL){
        p = p->next;
        ++j;
    }
    if (p==NULL || j>i-1 )
        return ERROR;
    temp = p->next;
    p->next = temp->next;
    *e = temp->data;
    free(temp);
    temp = NULL;
}

Status PrintLinkList(LinkList L){
    LinkList p = L->next;
    while(p!=NULL){
        printf("%d\t",p->data);
        p = p->next;
    }
}

Status TailInsert(LinkList L,ElemType e){
    LinkList p=L,temp;
    temp = (LinkList)malloc(sizeof(LNode));
    if (temp ==NULL) return OVERFLOW;
    while(p->next!=NULL){
        p = p->next;
    }
    temp->data = e;
    temp->next = p->next;
    p->next = temp;
    return OK;
}

Status HeadInsert(LinkList *L,ElemType e){
    LinkList p,temp;
    temp = (LinkList)malloc(sizeof(LNode));
    if (temp == NULL) return OVERFLOW;
    p = (*L)->next;
    temp->data = e;
    temp->next = p;
    (*L)->next = temp;
    return OK;
}

Status main(){
    system("cls");

    printf(GREEN"Init linklist..."NONE);
    LinkList L=NULL,Head=NULL,Tail=NULL;
    InitLinkList(&L);
    printf("\nLink list is null ?");
    IsEmpty(L)?printf(RED"is NULL!"NONE):printf(YELLOW"not NULL."NONE);
    int i,n =10;
    ElemType e;
    i=1;
    printf(GREEN"\nInsert elem into list..."NONE);
    while(i<=n){
        LinkListInsert(L,i,i*3);
        i++;
    }
    printf("\nAfter insert list's elem has: \n");
    PrintLinkList(L);
    printf("\nNow link list is null ? ");
    IsEmpty(L)?printf(RED"is NULL! "NONE):printf(YELLOW"not NULL."NONE);
    printf("\nAnd link List's Length is : %d",LinkListLength(L));
    ElemType e2,e3,e4;
    DeleteElem(L,5,&e2);
    printf(GREEN"\nDelete the %d'th elem %d"NONE,5,e2);
    printf("\nAfter Delete List's elem has :\n");
    PrintLinkList(L);
    //Find next elem
    NextElem(L,21,&e3);
    printf("\nFind %d next Elem is %d",21,e3);
    //Find prior elem
    PriorElem(L,21,&e4);
    printf("\nFind %d prior Elem is %d",21,e4);

    //Clear LinkList
    printf(GREEN"\nClear the Linklist..."NONE);
    ClearList(&L);
    printf("\nNow link list is null ?");
    IsEmpty(L)?printf(RED"is NULL! "NONE):printf(YELLOW"not NULL."NONE);
    printf("\nAnd link list's Length is : %d",LinkListLength(L));
    printf(GREEN"\nRecycle memeory..."NONE);

    DestoryLink(&L);
    printf(GREEN"\nHead insert and tail insert:\n"NONE);
    printf(GREEN"Initing...\n"NONE);
    InitLinkList(&Head);
    InitLinkList(&Tail);
    int o=0,temp;
    while(o<10){
        temp = rand()/10000;
        printf("%d\t",temp);
        HeadInsert(&Head,temp);
        TailInsert(Tail,temp);
        o++;
    }
    printf("\nHead insert : \n");
    PrintLinkList(Head);
    printf("\nTail insert :\n");
    PrintLinkList(Tail);
    DestoryLink(&Head);
    DestoryLink(&Tail);
    system("pause");
}