#include <stdio.h>
#include "LinerList/OrderStore.h"
int main() {
    int a[10]={2,4,6,8,10,12,14,16,18,20};
    int i;
    struct List L;
    InitList(&L,5);
    for(int i=0;i<10;i++)
        InsertEndList(&L,a[i]);
    InserPosList(&L,11,48);
    InserPosList(&L,1,64);
    printf("%d\n",GetElem(&L,4));
    TraverseList(&L);
    printf("%d\n",FindListOfInt(&L,10));
    UpdataPosList(&L,3,20);
    DeleteFirstList(&L);
    DeleteFirstList(&L);
    DeleteLastList(&L);
    DeleteLastList(&L);
    DeletePosList(&L,5);
    DeletePosList(&L,7);
    printf("%d\n",SizeList(&L));
    printf("%d\n",EmptyList(&L));
    TraverseList(&L);
    ClearList(&L);


}