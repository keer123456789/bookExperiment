//
// Created by keer on 2020/1/8.
//
#include <stdio.h>
#include <stdlib.h>

/**
 * 链表相关操作
 */


struct sNode {
    int data;
    struct sNode *next;
};

/***
 * 初始化线性表，单链表的表头指针为空
 * @param HL
 */
void InitNodeList(struct sNode **HL) {
    *HL = NULL;
}

/**
 * 清空链表
 * @param HL
 */
void ClearNodeList(struct sNode **HL) {
    struct sNode *cp, *np;
    cp = *HL;
    /*遍历链表，释放每一个节点*/
    while (cp != NULL) {
        np = cp->next;
        free(cp);
        cp = np;
    }
    /*置单链表的表头指针为空*/
    *HL = NULL;
}

/**
 * 获得单链表的长度
 * @param HL
 * @return 返回单链表长度
 */
int SizeNodeList(struct sNode *HL) {
    int i = 0;
    while (HL != NULL) {
        i++;
        HL = HL->next;
    }
    return i;
}

/**
 * 判断单链表是否为空
 * @param L
 * @return 链表为空，返回1；链表不为空，返回0；
 */
int EmptyNodeList(struct sNode *HL) {
    if (HL == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 获得单链表的指定位置的元素值
 * @param HL
 * @param pos
 * @return
 */
int GetElemNodeList(struct sNode *HL, int pos) {
    if (pos < 1) {
        printf("pos值输入非法！！退出程序！！\n");
        exit(1);
    }
    int i = 0;
    while (HL != NULL) {
        i++;
        if (i == pos) {
            break;
        }
        HL = HL->next;
    }
    if (HL != NULL) {
        return HL->data;
    } else {
        printf("pos值输入非法！！退出程序！！\n");
        exit(1);
    }
}

/**
 * 遍历链表
 * @param L
 */
void TraverseNodeList(struct sNode *L) {
    while (L != NULL) {
        printf("%5d ", L->data);
        L = L->next;
    }

    printf("\n");
}

/**
 * 找到链表中与x相等的元素值的地址
 * @param L
 * @param x
 * @return
 */
int *FindNodeListOfInt(struct sNode *L, int x) {
    while (L != NULL) {
        if (x == L->data) {
            return &L->data;
        } else {
            L = L->next;
        }
    }
    return NULL;
}

int FindNodeListOfChar(struct sNode *L, int x) {

}


/**
 * 更新链表中第POS位置的元素为elementType
 * @param L
 * @param pos
 * @param elementType
 * @return 成功返回1，失败返回0
 */
int UpdataPosNodeList(struct sNode *L, int pos, int elementType) {
    int i = 0;
    while (L == NULL) {
        i++;
        if (i == pos) {
            L->data = elementType;
            return 1;
        }
        L = L->next;
    }
    return 0;

}

/**
 * 单链表进行头插；
 * @param L
 * @param elementType
 */
void InsertFirstNodeList(struct sNode **L, int elementType) {
    struct sNode *newNode;
    newNode = malloc(sizeof(struct sNode));
    if (newNode == NULL) {
        printf("存储空间用完！创建新节点失败！退出运行\n");
        exit(1);
    }

    newNode->data = elementType;
    newNode->next = *L;
    *L = newNode;
}

/**
 * 单链表进行尾插
 * @param L
 * @param elementType
 */
void InsertEndNodeList(struct sNode **L, int elementType) {
    struct sNode *newNode;
    newNode = malloc(sizeof(struct sNode));
    if (newNode == NULL) {
        printf("存储空间用完！创建新节点失败！退出运行\n");
        exit(1);
    }
    newNode->next = NULL;
    newNode->data = elementType;

    if (*L == NULL) {
        *L = newNode;
    } else {
        struct sNode *p = *L;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }

}

/**
 * 在指定位置插入节点
 * @param L
 * @param pos
 * @param elementType
 * @return 插入成功返回1，插入失败返回0
 */
int InserPosNodeList(struct sNode **L, int pos, int elementType) {
    if (pos < 1) {
        printf("pos值输入非法，返回0表示插入失败！！\n");
        return 0;
    }

    /*寻找POS值的节点*/
    int i = 0;
    struct sNode *cp = *L, *np = NULL;
    while (cp != NULL) {
        i++;
        if (i == pos) {
            break;
        } else {
            np = cp;
            cp = cp->next;
        }
    }

    /*新节点创建空间*/
    struct sNode *newNode;
    newNode = malloc(sizeof(struct sNode));
    if (newNode == NULL) {
        printf("存储空间不足，创建新节点失败！！\n");
        return 0;
    }
    newNode->data = elementType;

    /*如果单链表为空*/
    if (np == NULL) {
        newNode->next = *L;
        *L = newNode;
    } else {
        newNode->next = cp;
        np->next = newNode;
    }
    return 1;
}

/**
 * 在有序链表中插入元素，使插入后的单链表依然为有序链表
 * @param L
 * @param elementType
 */
void InsertOrderNodeList(struct sNode **L, int elementType) {
    /*新节点创建空间*/
    struct sNode *newNode;
    newNode = malloc(sizeof(struct sNode));
    if (newNode == NULL) {
        printf("存储空间不足，创建新节点失败！！退出程序\n");
        exit(1);
    }
    struct sNode *ap = *L, *bp = NULL;
    newNode->data = elementType;

    /*如果单链表为空*/
    if (ap == NULL || elementType < ap->data) {
        newNode->next=ap;
        *L = newNode;
        return;
    }

    /*找到相应位置的节点*/
    while (ap != NULL) {
        if (elementType < ap->data) {
            break;
        } else {
            bp = ap;
            ap = ap->next;
        }
    }
    newNode->next = ap;
    bp->next = newNode;
}

/**
 * 删除表头,并返回删除元素
 * @param L
 * @return
 */
int DeleteFirstNodeList(struct sNode **L) {
    int temp;
    struct sNode *cp = *L;
    if (cp == NULL) {
        printf("单链表为空，无法删除。退出程序\n");
        exit(1);
    }

    temp = cp->data;
    *L = (*L)->next;
    free(cp);
    return temp;

}

/**
 * 删除尾部节点
 * @param L
 * @return
 */
int DeleteLastNodeList(struct sNode **L) {
    struct sNode *p = *L, *ap = NULL;
    int temp;
    if (p == NULL) {
        printf("单链表为空，无法删除。退出程序\n");
        exit(1);
    }

    while (p != NULL) {
        ap = p;
        p = p->next;
    }
    if (ap == NULL) {
        *L = (*L)->next;
    } else {
        ap->next = NULL;
    }
    temp = p->data;
    free(p);
    return temp;
}

/**
 * 删除单链表的指定位置的值
 * @param L
 * @param pos
 * @return
 */
int DeletePosNodeList(struct sNode **L, int pos) {
    struct sNode *cp = *L, *ap = NULL;

    int temp;
    if (cp == NULL || pos < 1) {
        printf("单链表为空或POS值非法，无法删除。退出程序\n");
        exit(1);
    }
    int i = 0;
    while (cp != NULL) {
        i++;
        if (pos == i) {
            break;
        } else {
            ap = cp;
            cp = cp->next;
        }
    }

    if (cp == NULL) {
        printf("pos值非法！！退出程序\n");
        exit(1);
    }
    if (pos == 1) {
        *L = (*L)->next;
    } else {
        ap->next = cp->next;
    }
    temp = cp->data;
    free(cp);
    return temp;
}
/**
 * 删除链表第一个与elementType相同的值
 * @param L
 * @param elementType
 * @return
 */
int DeleteValueNodeList(struct sNode **L, int elementType) {
    struct sNode *cp = *L, *ap = NULL;
    while (cp != NULL) {
        if (cp->data == elementType) {
            break;
        } else {
            ap = cp;
            cp = cp->next;
        }
    }
    /*链表中不存在此元素*/
    if (cp == NULL) {
        return 0;
    }

    if (ap == NULL) {
        *L = (*L)->next;
    } else {
        ap->next = cp->next;
    }
    free(cp);

    return 1;

}
