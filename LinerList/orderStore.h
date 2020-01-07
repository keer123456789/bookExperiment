//
// Created by keer on 2020/1/7.
//



#ifndef BOOKEXPERIMENT_ORDERSTORE_H
#define BOOKEXPERIMENT_ORDERSTORE_H
extern struct List {
    int *list;
    int size;
    int MaxSize;
};
#endif //BOOKEXPERIMENT_ORDERSTORE_H



extern void InitList(struct List *L, int ms);

extern void ClearList(struct List *L);

extern int SizeList(struct List *L);

extern int EmptyList(struct List *L);

extern int GetElem(struct List *L, int pos);

extern void TraverseList(struct List *L);

extern int FindListOfInt(struct List *L, int x);

extern int FindListOfChar(struct List *L, int x);

extern int UpdataPosList(struct List *L, int pos, int elementType);

extern void InsertFirstList(struct List *L, int elementType);

extern void InsertEndList(struct List *L, int elementType);

extern int InserPosList(struct List *L, int pos, int elementType) ;

extern void InsertOrderList(struct List *L,int elementType);

extern int DeleteFirstList(struct List *L);

extern int DeleteLastList(struct List *L);

int DeletePosList(struct List *L,int pos);

int DeleteValueList(struct List *L,int elementType);
