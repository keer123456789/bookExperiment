//
// Created by keer on 2020/1/13.
//
#include <stdlib.h>
#include <stdio.h>
//typedef double ElemType;
//typedef int ElemType;
struct StackSq {
    double *stack;
    int top;
    int MaxSize;
};

/**
 * 初始化栈，栈的容量为默认值：10
 * @param s
 */
void InitStackSq(struct StackSq *s) {
    s->MaxSize = 10;
    s->stack = malloc(10 * sizeof(double));
    s->top = -1;
}

/**
 * 给定栈的最大容量
 * @param s
 * @param ms 栈的最大容量
 */
void InitStackSqByMaxsize(struct StackSq *s, int ms) {
    if (ms < 1) {
        printf("ms的值输入非法！！程序退出！！\n");
        exit(1);
    }
    s->stack = malloc(ms * sizeof(double));
    if (!s->stack) {
        printf("空间不足！！程序退出！！\n");
        exit(1);
    }
    s->MaxSize = ms;
    s->top = -1;
}

/**
 * 将线性表的存储空间扩大为原来的两倍
 * @param L
 */
void againMallocforStackSq(struct StackSq *L) {
    /*空间扩展为原来的两倍，原内容自动拷贝到指针p中*/
    double *p = realloc(L->stack, 2 * L->MaxSize * sizeof(double));
    if (!p) {
        printf("存储空间用完！程序退出！！\n");
        exit(1);
    }
    L->stack = p;
    L->MaxSize = 2 * L->MaxSize;

}

/**
 * 入栈
 * @param s
 * @param x
 */
void Push(struct StackSq *s, double x) {
    if (s->top == s->MaxSize - 1) {
        againMallocforStackSq(s);
    }
    s->top++;
    s->stack[s->top] = x;
}

/**
 * 出栈
 * @param s
 * @return
 */
double Pop(struct StackSq *s) {
    if (s->top == -1) {
        printf("栈空！！无元素！！退出程序！！");
        exit(1);
    }
    s->top--;
    return s->stack[(s->top )+ 1];
}

/**
 * 读取栈顶元素
 * @param s
 * @return
 */
double Peek(struct StackSq *s) {
    if (s->top == -1) {
        printf("栈空！！无元素！！退出程序！！");
        exit(1);
    }
    return s->stack[s->top];
}

/**
 * 判断栈是否为空，为空返回1，不为空返回0
 * @param s
 * @return
 */
int EmptyStack(struct StackSq *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

/**
 * 清空栈内元素
 * @param s
 */
void ClearStack(struct StackSq *s) {
    if (s->stack) {
        free(s->stack);
        s->stack = 0;
        s->top = -1;
        s->MaxSize = 0;
    }
}