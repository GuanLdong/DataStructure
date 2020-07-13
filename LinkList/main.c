
// Created by Guan on 2020-07-12.
//

Status main(){
    system("cls");
    printf(GREEN"Init linklist..."NONE);
    LinkList L=NULL;
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
    LinkList Head = NULL;
    LinkList Tail = NULL;
    printf(GREEN"\nInit Linklist Head and Tail...");
    InitLinkList(&Head);
    InitLinkList(&Tail);

    int o = 0,temp;
    while(o<10){
        temp = rand();
        printf("%d\t",&temp);
        HeadInsert(&Head,temp);
        TailInsert(Tail,temp);
        o++;
    }
    printf("Head insert : \n");
    PrintLinkList(Head);
    printf("Tail insert :\n");
    PrintLinkList(Tail);
    o = 1;
    while(o<=10){
        GetElem(Tail,i,&e);
        printf("%d  ",e);
        o++;
    }
    DestoryLink(&Head);
    DestoryLink(&Tail);
    system("pause");
}

