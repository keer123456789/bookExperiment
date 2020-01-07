//
// Created by keer on 2020/1/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List {
    int *list;
    int size;
    int MaxSize;
};

/**
 * ��ʼ�����Ա�
 * @param L ˳�����Ա��ṹ��
 * @param ms ���Ա�����󳤶�
 */
void InitList(struct List *L, int ms) {
    printf("��ʼ��ʼ�����Ա���\n");
    /* ���ms�����Ƿ�Ƿ�*/
    if (ms <= 0) {
        printf("msֵ������󣡣�\n");
        printf("��ʼ�����Ա�ʧ�ܣ�\n");
        exit(1);
    }

    /* �������Ա���СΪms*/
    L->MaxSize = ms;

    /*��̬����洢�ռ�*/
    L->list = malloc(ms * sizeof(int));
    if (!L->list) {
        printf("��̬�����ڴ�ʧ��\n");
        printf("��ʼ�����Ա�ʧ�ܣ�\n");
        exit(1);
    }

    /* �������Ա�Ϊ��*/
    L->size = 0;
    printf("��ʼ�����Ա��ɹ���\n");
}

/**
 * ������Ա����ݣ��ͷſռ�
 * @param L
 */
void ClearList(struct List *L) {
    if (L->list != NULL) {
        free(L->list);  /*�ͷŴ洢�ռ䣡��*/
        L->list = 0;
        L->size = L->MaxSize = 0;
    }
}

/**
 * �������Ա�����
 * @param L
 * @return �������Ա�����
 */
int SizeList(struct List *L) {
    return L->size;
}

/**
 * �ж����Ա��Ƿ�Ϊ��
 * @param L
 * @return ����1����ʾ���Ա�Ϊ�գ�����0����ʾ���Ա���Ϊ��
 */
int EmptyList(struct List *L) {
    if (L->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * ��ȡ���Ա��и���λ�õ�Ԫ��ֵ
 * @param L
 * @param pos ���������Ա��е�λ��
 * @return  �������Ա��е�posλ�õ�Ԫ��ֵ
 */
int GetElem(struct List *L, int pos) {
    if (pos < 1 || pos > L->size) {
        printf("posֵԽ�磡��\n");
        exit(1);
    }
    return L->list[pos - 1];
}

/**
 * �������Ա�
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
 * �����Ա��в��Һ�ָ��ֵ��ͬ��Ԫ�أ�������Ԫ��λ�ã����û���򷵻�-1
 * �˷���ʹ�����Ա�����Ϊ����
 * @param L
 * @param x Ҫ���ҵ�ֵ��
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
 * �����Ա��в��Һ�ָ��ֵ��ͬ��Ԫ�أ�������Ԫ��λ�ã����û���򷵻�-1
 * �˷���ʹ�����Ա�����Ϊ����
 * @param L
 * @param x
 * @return ����-1��ʾ�����ں�x��ȵ�ֵ
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
 * �����Ա���ָ��λ�õ�ֵ�����滻
 * @param L
 * @param pos
 * @param elementType
 * @return ����0�滻ʧ�ܣ�����1��ʾ�ɹ�
 */
int UpdataPosList(struct List *L, int pos, int elementType) {
    if (pos < 1 || pos > L->size) {
        return 0;
    }
    L->list[pos-1] = elementType;
    return 1;
}

/**
 * �����Ա��Ĵ洢�ռ�����Ϊԭ��������
 * @param L
 */
void againMalloc(struct List *L) {
    /*�ռ���չΪԭ����������ԭ�����Զ�������ָ��p��*/
    int *p = realloc(L->list, 2 * L->MaxSize * sizeof(int));
    if (!p) {
        printf("�洢�ռ����꣡\n");
        exit(1);
    }
    L->list = p;
    L->MaxSize = 2 * L->MaxSize;

}

/**
 * �����Ա��Ľ���ͷ��
 * @param L
 * @param elementType
 */
void InsertFirstList(struct List *L, int elementType) {
    int i;
    if (L->size == L->MaxSize) {
        printf("��ʼ����洢�ռ�\n");
        againMalloc(L);
    }
    for (i = L->size - 1; i >= 0; i--) {
        L->list[i + 1] = L->list[i];
    }
    L->list[0] = elementType;
    L->size = L->size + 1;
}

/**
 * ���Ա�����β��
 * @param L
 * @param elementType
 */
void InsertEndList(struct List *L, int elementType) {
    if (L->size == L->MaxSize) {
        printf("��ʼ����洢�ռ�\n");
        againMalloc(L);
    }
    L->list[L->size] = elementType;
    L->size++;
}

/**
 * �ڸ���ֵλ�ý��в���
 * @param L
 * @param pos
 * @param elementType
 * @return ����0��ʾ����ʧ�ܣ�����1��ʾ����ɹ�
 */
int InserPosList(struct List *L, int pos, int elementType) {
    /*���POSֵ�Ƿ�Խ��*/
    if (pos < 1 || pos > L->size + 1) {
        printf("posֵԽ�磡��\n");
        return 0;
    }

    /*������Ա��ռ��Ƿ�����*/
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
 * ��˳����н��в���Ԫ�أ�ʹ������֮����Ȼ����Ϊ˳���
 * @param L
 * @param elementType
 */
void InsertOrderList(struct List *L,int elementType){
    /*������Ա��ռ��Ƿ���*/
    if(L->size==L->MaxSize){
        againMalloc(L);
    }

    /*����Ԫ��λ��*/
    int pos;
    for(pos=0;pos<L->size;pos++){
        if(elementType>=L->list[pos]){
            break;
        }
    }

    /*���в���*/
    for(int i=L->size-1;i>=pos;i--){
        L->list[i+1]=L->list[i];
    }

    L->list[pos]=elementType;
    L->size++;

}

/**
 * ɾ�����Ա��е�һ��Ԫ��
 * @param L
 * @return ɾ���̳ɹ�������ɾ����Ԫ��ֵ��ʧ���˳�����
 */
int DeleteFirstList(struct List *L){
    int temp;
    /*������Ա��ǹ�Ϊ��*/
    if(L->size==0){
        printf("���Ա�Ϊ�գ���������ɾ������\n");
        exit(1);
    }

    /*ɾ��*/
    temp=L->list[0];
    for(int i=1;i<L->size;i++){
        L->list[i-1]=L->list[i];
    }
    L->size--;
    return temp;
}

/**
 * ɾ�����Ա������һ��Ԫ��
 * @param L
 * @return ɾ���̳ɹ�������ɾ����Ԫ��ֵ��ʧ���˳�����
 */
int DeleteLastList(struct List *L){
    /*������Ա��ǹ�Ϊ��*/
    if(L->size==0){
        printf("���Ա�Ϊ�գ���������ɾ������\n");
        exit(1);
    }
    L->size--;
    return L->list[L->size];
}

/**
 * ɾ�����Ա���ָ��λ�õ�Ԫ�أ������ظ�Ԫ��
 * @param L
 * @param pos
 * @return
 */
int DeletePosList(struct List *L,int pos){
    int temp;
    /*���POSֵ�Ƿ�Խ��*/
    if (pos < 1 || pos > L->size) {
        printf("posֵԽ�磡��\n");
        exit(1);
    }

    /*ɾ��*/
    temp=L->list[pos-1];
    for(int i=pos;i<L->size;i++){
        L->list[i-1]=L->list[i];
    }
    L->size--;
    return temp;
}

/**
 * ɾ�����Ա���ֵΪx�ĵ�һ��Ԫ�أ�
 * @param L
 * @param elementType
 * @return ɾ���ɹ�������1��ɾ��ʧ�ܣ�����0
 */
int DeleteValueList(struct List *L,int elementType){
    int pos;
    /*�����Ա����ҵ���ֵ��λ��*/
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
