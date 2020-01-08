#include <stdio.h>
#include <stdlib.h>
#include "LinerList/OrderStore.h"
#include "LinerList/UnOrderstore.h"
int main() {
    printf("****************************\n");
    printf("线性表输入：1，链表输入：2\n");
    printf("****************************\n");
    int b;
    scanf("%d",&b);
    switch (b) {
        case 1: {
            int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
            int i;
            struct List L;
            InitList(&L, 5);
            for (int i = 0; i < 10; i++)
                InsertEndList(&L, a[i]);
            InserPosList(&L, 11, 48);
            InserPosList(&L, 1, 64);
            printf("%d\n", GetElem(&L, 4));
            TraverseList(&L);
            printf("%d\n", FindListOfInt(&L, 10));
            UpdataPosList(&L, 3, 20);
            DeleteFirstList(&L);
            DeleteFirstList(&L);
            DeleteLastList(&L);
            DeleteLastList(&L);
            DeletePosList(&L, 5);
            DeletePosList(&L, 7);
            printf("%d\n", SizeList(&L));
            printf("%d\n", EmptyList(&L));
            TraverseList(&L);
            ClearList(&L);
        }
            break;
        case 2:{
            int a[12];
            int i;
            struct sNode *p,*h,*s;
            InitNodeList(&p);
            for(i=0;i<12;i++) {
                a[i] = rand() % 20;
            }
            printf("随机数列：");
            for(i=0;i<12;i++){
                printf("%5d",a[i]);
            }
            printf("\n");
            printf("随机数逆序");
            for(i=0;i<12;i++){
                InsertFirstNodeList(&p,a[i]);
            }
            TraverseNodeList(p);
            printf("单链表长度：%d\n",SizeNodeList(p));
            for(h=p;h!=NULL;h=h->next){
                while (DeleteValueNodeList(&(h->next),h->data));
            }

            printf("除去重复数：");
            TraverseNodeList(p);
            printf("单链表长度：%d\n",SizeNodeList(p));
            h=NULL;
            for(s=p;s!=NULL;s=s->next){
                InsertOrderNodeList(&h,s->data);
            }
            printf("有序数列：");
            TraverseNodeList(h);
            ClearNodeList(&p);
        }
            break;

    }
}