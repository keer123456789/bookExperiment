#include <stdio.h>
#include <stdlib.h>

//
// Created by keer on 2020/1/13.
//
struct sNode {
    int data;
    struct sNode *next;
};

/**
 * 初始化栈
 * @param s
 */
void InitStackLink(struct sNode **s) {
    *s = NULL;
}

/**
 * 入栈
 * @param s
 * @param x
 */
void PushLink(struct sNode **s, int x) {
    struct sNode *news;
    news = malloc(sizeof(struct sNode));
    if (news == NULL) {
        printf("空间用完！！程序退出\n");
        exit(1);
    }
    news->data = x;
    news->next = *s;
    *s = news;
}

/**
 * 出栈
 * @param s
 * @return
 */
int PopLink(struct sNode **s){
    struct sNode* p;
    int temp;
    if(*s==NULL){
        printf("栈空，退出程序！！");
        exit(1);
    }
    p=*s;
    temp=p->data;
    *s=p->next;
    free(p);
    return temp;
}

/**
 * 读取栈顶元素
 * @param s
 * @return
 */
int PeekLink(struct sNode **s){
    if(*s==NULL){
        printf("栈空！！\n");
        exit(1);
    }
    return  (*s)->data;
}

int EmptyStackLink(struct sNode **s){
    if(*s==NULL){
        return 1;
    }
    else
        return 0;
}

void ClearStackLink(struct sNode **s){
    struct sNode *cp,*np;
    cp=*s;
    while(cp!=NULL){
        np=cp->next;
        free(cp);
        cp=np;
    }
    *s=NULL;
}