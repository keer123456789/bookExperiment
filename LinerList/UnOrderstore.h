//
// Created by keer on 2020/1/8.
//

#ifndef BOOKEXPERIMENT_UNORDERSTORE_H
#define BOOKEXPERIMENT_UNORDERSTORE_H
extern struct sNode {
    int data;
    struct sNode *next;
};
#endif //BOOKEXPERIMENT_UNORDERSTORE_H

extern void InitNodeList(struct sNode **HL);

extern void ClearNodeList(struct sNode **HL);

extern int SizeNodeList(struct sNode *HL);

extern int EmptyNodeList(struct sNode *HL);

extern int GetElemNodeList(struct sNode *HL, int pos);

extern void TraverseNodeList(struct sNode *L);

extern int *FindNodeListOfInt(struct sNode *L, int x);

extern int FindNodeListOfChar(struct sNode *L, int x);

extern int UpdataPosNodeList(struct sNode *L, int pos, int elementType);

extern void InsertFirstNodeList(struct sNode **L, int elementType);

extern void InsertEndNodeList(struct sNode **L, int elementType);

extern int InserPosNodeList(struct sNode **L, int pos, int elementType);

extern void InsertOrderNodeList(struct sNode **L, int elementType) ;

extern int DeleteFirstNodeList(struct sNode **L);

extern int DeleteLastNodeList(struct sNode **L);

extern int DeletePosNodeList(struct sNode **L, int pos) ;

extern int DeleteValueNodeList(struct sNode **L, int elementType);

