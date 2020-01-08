//
// Created by keer on 2020/1/7.
//
/**
 * 线性表的相关操作
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List {
    int *list;
    int size;
    int MaxSize;
};

/**
 * 初始化线性表
 * @param L 顺序线性表结构体
 * @param ms 线性表的最大长度
 */
void InitList(struct List *L, int ms) {
    printf("开始初始化线性表！\n");
    /* 检查ms输入是否非法*/
    if (ms <= 0) {
        printf("ms值输入错误！！\n");
        printf("初始化线性表失败！\n");
        exit(1);
    }

    /* 设置线性表大小为ms*/
    L->MaxSize = ms;

    /*动态分配存储空间*/
    L->list = malloc(ms * sizeof(int));
    if (!L->list) {
        printf("动态分配内存失败\n");
        printf("初始化线性表失败！\n");
        exit(1);
    }

    /* 设置线性表为空*/
    L->size = 0;
    printf("初始化线性表成功！\n");
}

/**
 * 清除线性表内容，释放空间
 * @param L
 */
void ClearList(struct List *L) {
    if (L->list != NULL) {
        free(L->list);  /*释放存储空间！！*/
        L->list = 0;
        L->size = L->MaxSize = 0;
    }
}

/**
 * 返回线性表长度
 * @param L
 * @return 返回线性表长度
 */
int SizeList(struct List *L) {
    return L->size;
}

/**
 * 判断线性表是否为空
 * @param L
 * @return 返回1，表示线性表为空；返回0，表示线性表不为空
 */
int EmptyList(struct List *L) {
    if (L->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 获取线性表中给定位置的元素值
 * @param L
 * @param pos 给定的线性表中的位置
 * @return  返回线性表中的pos位置的元素值
 */
int GetElem(struct List *L, int pos) {
    if (pos < 1 || pos > L->size) {
        printf("pos值越界！！\n");
        exit(1);
    }
    return L->list[pos - 1];
}

/**
 * 遍历线性表
 * @param L
 */
void TraverseList(struct List *L) {
    int i;
    for (i = 0; i < L->size; i++) {
        printf("%d ", L->list[i]);
    }
    printf("\n");
}

/**
 * 在线性表中查找和指定值相同的元素，并返回元素位置，如果没有则返回-1
 * 此方法使用线性表类型为整形
 * @param L
 * @param x 要查找的值；
 * @return
 */
int FindListOfInt(struct List *L, int x) {
    int i;
    for (int i = 0; i < L->size; i++) {
        if (L->list[i] == x) {
            return i;
        }
    }
    return -1;
}

/**
 * 在线性表中查找和指定值相同的元素，并返回元素位置，如果没有则返回-1
 * 此方法使用线性表类型为整形
 * @param L
 * @param x
 * @return 返回-1表示不存在和x相等的值
 */
int FindListOfChar(struct List *L, int x) {
    int i;
    for (int i = 0; i < L->size; i++) {
        if (strcmp(L->list[i], x)) {
            return i;
        }
    }
    return -1;
}

/**
 * 把线性表中指定位置的值进行替换
 * @param L
 * @param pos
 * @param elementType
 * @return 返回0替换失败，返回1表示成功
 */
int UpdataPosList(struct List *L, int pos, int elementType) {
    if (pos < 1 || pos > L->size) {
        return 0;
    }
    L->list[pos-1] = elementType;
    return 1;
}

/**
 * 将线性表的存储空间扩大为原来的两倍
 * @param L
 */
void againMalloc(struct List *L) {
    /*空间扩展为原来的两倍，原内容自动拷贝到指针p中*/
    int *p = realloc(L->list, 2 * L->MaxSize * sizeof(int));
    if (!p) {
        printf("存储空间用完！\n");
        exit(1);
    }
    L->list = p;
    L->MaxSize = 2 * L->MaxSize;

}

/**
 * 在线性表的进行头插
 * @param L
 * @param elementType
 */
void InsertFirstList(struct List *L, int elementType) {
    int i;
    if (L->size == L->MaxSize) {
        printf("开始扩大存储空间\n");
        againMalloc(L);
    }
    for (i = L->size - 1; i >= 0; i--) {
        L->list[i + 1] = L->list[i];
    }
    L->list[0] = elementType;
    L->size = L->size + 1;
}

/**
 * 线性表进行尾插
 * @param L
 * @param elementType
 */
void InsertEndList(struct List *L, int elementType) {
    if (L->size == L->MaxSize) {
        printf("开始扩大存储空间\n");
        againMalloc(L);
    }
    L->list[L->size] = elementType;
    L->size++;
}

/**
 * 在给定值位置进行插入
 * @param L
 * @param pos
 * @param elementType
 * @return 返回0表示插入失败，返回1表示插入成功
 */
int InserPosList(struct List *L, int pos, int elementType) {
    /*检查POS值是否越界*/
    if (pos < 1 || pos > L->size + 1) {
        printf("pos值越界！！\n");
        return 0;
    }

    /*检查线性表空间是否已满*/
    if(L->size==L->MaxSize){
        againMalloc(L);
    }

    for(int i=L->size-1;i>=(pos-1);i--){
        L->list[i+1]=L->list[i];
    }
    L->list[pos-1]=elementType;
    L->size++;
    return 1;
}
/**
 * 在顺序表中进行插入元素，使插入完之后依然保持为顺序表
 * @param L
 * @param elementType
 */
void InsertOrderList(struct List *L,int elementType){
    /*检查线性表空间是否够用*/
    if(L->size==L->MaxSize){
        againMalloc(L);
    }

    /*查找元素位置*/
    int pos;
    for(pos=0;pos<L->size;pos++){
        if(elementType>=L->list[pos]){
            break;
        }
    }

    /*进行插入*/
    for(int i=L->size-1;i>=pos;i--){
        L->list[i+1]=L->list[i];
    }

    L->list[pos]=elementType;
    L->size++;

}

/**
 * 删除线性表中第一个元素
 * @param L
 * @return 删除程成功返回所删除的元素值，失败退出程序
 */
int DeleteFirstList(struct List *L){
    int temp;
    /*检查线性表是够为空*/
    if(L->size==0){
        printf("线性表为空！！，不能删除！！\n");
        exit(1);
    }

    /*删除*/
    temp=L->list[0];
    for(int i=1;i<L->size;i++){
        L->list[i-1]=L->list[i];
    }
    L->size--;
    return temp;
}

/**
 * 删除线性表中最后一个元素
 * @param L
 * @return 删除程成功返回所删除的元素值，失败退出程序
 */
int DeleteLastList(struct List *L){
    /*检查线性表是够为空*/
    if(L->size==0){
        printf("线性表为空！！，不能删除！！\n");
        exit(1);
    }
    L->size--;
    return L->list[L->size];
}

/**
 * 删除线性表中指定位置的元素，并返回该元素
 * @param L
 * @param pos
 * @return
 */
int DeletePosList(struct List *L,int pos){
    int temp;
    /*检查POS值是否越界*/
    if (pos < 1 || pos > L->size) {
        printf("pos值越界！！\n");
        exit(1);
    }

    /*删除*/
    temp=L->list[pos-1];
    for(int i=pos;i<L->size;i++){
        L->list[i-1]=L->list[i];
    }
    L->size--;
    return temp;
}

/**
 * 删除线性表中值为x的第一个元素，
 * @param L
 * @param elementType
 * @return 删除成功，返回1；删除失败，返回0
 */
int DeleteValueList(struct List *L,int elementType){
    int pos;
    /*在线性表中找到该值的位置*/
    for(pos=0;pos<L->size;pos++){
        if(L->list[pos]==elementType){
            break;
        }
    }

    if(pos==L->size)
        return 0;

    for(int i=pos;i<L->size;i++){
        L->list[i]=L->list[i+1];
    }
    L->size--;
    return 1;
}

