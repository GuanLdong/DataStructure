/*  */#include <stdio.h>

/* 状态码 */
#define TRUE        1   // 真/是
#define FALSE       0   // 假/否
#define OK          1   // 通过/成功
#define ERROR       0   // 错误/失败

#define OVERFLOW    -2  //堆栈上溢
#define LIST_INIT_SIZE 100
#define LISTINCEREMENT 10 
/* 状态码类型 */
typedef int Status;
typedef int ElemType;

typedef struct SList{
    ElemType *elem;
    int length;
    int listsize;
}SList;

Status Init_SList(SList *L){
    (*L).elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    if ((*L).elem ==NULL) exit(OVERFLOW);
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
}

Status Insert_SList(SList *L,int n,ElemType e){
    ElemType *newbase;
    ElemType *p,*q;
    if(n<1||n>(*L).length+1) return ERROR;
    if((*L).length>=(*L).listsize){
        newbase = (ElemType *)realloc((*L).elem,((*L).listsize+LISTINCEREMENT)*sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        (*L).elem = newbase;
        (*L).listsize += LISTINCEREMENT;
    }
    q = &(*L).elem[n-1];
    for(p=&(*L).elem[(*L).length-1];p>=q;--p)
        *(p+1)=*p;
    *q=e;
    (*L).length++;
    return OK;
}

Status Delete_SList(SList *L,int n,ElemType e){
    ElemType *p,*q;
    if(n<1||n>(*L).length+1) return ERROR;
    p = &(*L).elem[n-1];
    e = *p;
    q = (*L).elem+(*L).length-1;
    for(++p;p<=q;++p){
        *(p-1)=*p;
    }
    --(*L).length;
    return OK;
}

ElemType GetElem(SList L,int i){
    ElemType e;
    e = L.elem[i-1];
    return e;
}

Status LocateElem(SList L,ElemType e,Status(*compare)(ElemType,ElemType)){
    int i = 1;
    ElemType *p;
    p = L.elem;
    while(i<=L.length && !(*compare)(*p++,e)) ++i;
    if(i<=L.length) return i;
    else return 0;
}

Status compare(ElemType data,ElemType e){
    return data == e ? TRUE:FALSE;
}

Status MergeList(SList La,SList Lb,SList *Lc){
    ElemType *pa,*pb,*pc,*La_last,*Lb_last;
    pa = La.elem;
    pb = Lb.elem;
    (*Lc).listsize =(*Lc).length= La.length+Lb.length;
    (*Lc).elem = (ElemType *)malloc((*Lc).listsize*sizeof(ElemType));
    if(!(*Lc).elem) exit(OVERFLOW);
    pc = (*Lc).elem;
    La_last = La.elem+La.length-1;
    Lb_last = Lb.elem+Lb.length-1;

    while(pa<=La_last && pb<=Lb_last){
        if(*pa<=*pb) *pc++=*pa++;
        else *pc++=*pb++;
    }
    while(pa<=La_last) *pc++ = *pa++;
    while(pb<=Lb_last) *pc++ = *pb++;
}

int main(){
    int n = 10;
    int i;
    printf("Init Static Link,list size = %d\n",n);
    SList L;
    Init_SList(&L);
    for(i =1;i<10;i++){
        Insert_SList(&L,i,i*3);
    }
    printf("List has :");
    for(i=1;i<L.length+1;i++){
        printf("%d\t",GetElem(L,i));
    }
    printf("\n");
    int m =5;
    int e;
    printf("delete %d\n",m);
    Delete_SList(&L,m,e);

    printf("List has :");
    for(i=1;i<L.length+1;i++){
        printf("%d\t",GetElem(L,i));
    }
    printf("\n");

    int o = 21;
    printf("Search %d\t",o);
    printf("Locate is %d",LocateElem(L,o,compare));


    printf("Init Static Link Lb,list size = %d\n",n);
    SList Lb,M;
    Init_SList(&Lb);
    for(i =1;i<=n;i++){
        Insert_SList(&Lb,i,i*2);
    }
    printf("List Lb has :");
    for(i=1;i<Lb.length+1;i++){
        printf("%d\t",GetElem(Lb,i));
    }
    printf("\n");
    Init_SList(&M);
    MergeList(L,Lb,&M);
    printf("M has :");
    for(i=1;i<M.length+1;i++){
        printf("%d\t",GetElem(M,i));
    }
    printf("\n");
	return 0;
}
