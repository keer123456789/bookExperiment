//
// Created by keer on 2020/1/13.
//

#ifndef BOOKEXPERIMENT_STACKSQ_H
#define BOOKEXPERIMENT_STACKSQ_H
extern struct StackSq {
    int *stack;
    int top;
    int MaxSize;
};
#endif //BOOKEXPERIMENT_STACKSQ_H

extern void InitStackSq(struct StackSq *s);

extern void InitStackSqByMaxsize(struct StackSq *s, int ms);

extern void Push(struct StackSq *s, int x);

extern int Pop(struct StackSq *s);

extern int Peek(struct StackSq *s);

extern int EmptyStack(struct StackSq *s);

extern void ClearStack(struct StackSq *s);

void InitStackLink(struct sNode **s);

extern void PushLink(struct sNode **s, int x);

extern int PopLink(struct sNode **s);

extern int PeekLink(struct sNode **s);

extern int EmptyStackLink(struct sNode **s);

extern void ClearStackLink(struct sNode **s);