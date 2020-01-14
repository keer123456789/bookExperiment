#include <stdio.h>
#include <stdlib.h>
#include "LinerList/OrderStore.h"
#include "LinerList/UnOrderstore.h"
#include "Stack/StackSq.h"

int main() {
    printf("****************************\n");
    printf("线性表输入：1，链接表输入：2\n");
    printf("顺序栈输入：3，链接栈输入：4\n");
    printf("栈的应用：检查c文件符号是否配对，输入：5\n");
    printf("栈的应用：十进制转换为其他进制，输入：6\n");
    printf("****************************\n");
    int b;
    scanf("%d", &b);
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
        case 2: {
            int a[12];
            int i;
            struct sNode *p, *h, *s;
            InitNodeList(&p);
            for (i = 0; i < 12; i++) {
                a[i] = rand() % 20;
            }
            printf("随机数列：");
            for (i = 0; i < 12; i++) {
                printf("%5d", a[i]);
            }
            printf("\n");
            printf("随机数逆序");
            for (i = 0; i < 12; i++) {
                InsertFirstNodeList(&p, a[i]);
            }
            TraverseNodeList(p);
            printf("单链表长度：%d\n", SizeNodeList(p));
            for (h = p; h != NULL; h = h->next) {
                while (DeleteValueNodeList(&(h->next), h->data));
            }

            printf("除去重复数：");
            TraverseNodeList(p);
            printf("单链表长度：%d\n", SizeNodeList(p));
            h = NULL;
            for (s = p; s != NULL; s = s->next) {
                InsertOrderNodeList(&h, s->data);
            }
            printf("有序数列：");
            TraverseNodeList(h);
            ClearNodeList(&p);
        }
            break;
        case 3: {
            struct StackSq s;
            int a[8] = {3, 8, 5, 17, 9, 30, 15, 22};
            int i;
            InitStackSqByMaxsize(&s, 5);
            for (i = 0; i < 8; i++) {
                PushLink(&s, a[i]);
            }
            printf("%d\n", Pop(&s));
            printf("%d\n", Pop(&s));
            Push(&s, 68);
            printf("%d\n", Peek(&s));
            printf("%d\n", Pop(&s));
            while (!EmptyStack(&s)) {
                printf("%d ", Pop(&s));
            }
            printf("\n");
            ClearStack(&s);

        }
            break;
        case 4: {
            struct sNode *p;
            int a[8] = {3, 8, 5, 17, 9, 30, 15, 22};
            InitStackLink(&p);
            for (int i = 0; i < 8; i++) {
                PushLink(&p, a[i]);
            }
            printf("%d\n", PopLink(&p));
            printf("%d\n", PopLink(&p));
            PushLink(&p, 68);
            printf("%d\n", PeekLink(&p));
            printf("%d\n", PopLink(&p));
            while (!EmptyStackLink(&p)) {
                printf("%d ", PopLink(&p));
            }
            printf("\n");
            ClearStackLink(&p);
        }
            break;
        case 5: {
            int checkBrackets(char *filePath);
            if (checkBrackets("E:\\code\\c\\bookExperiment\\Stack\\StackSq.c") == 1) {
                printf("\n文件格式正确\n");
            } else {
                printf("文件格式错误\n");
            }
        }
            break;
        case 6: {
            void Transform(long num, int r);
            printf("3425的八进制是：");
            Transform(3425, 8);
            printf("3425的六进制是：");
            Transform(3425, 6);
            printf("3425的四进制是：");
            Transform(3425, 4);
            printf("3425的二进制是：");
            Transform(3425, 2);
        }
            break;
        case 7: {
            char *a="12 34 + 5 2 / + 2 *";
            printf("后缀表达式：12 34 + 5 2 / + 2 *\n");
            double Compute(char *str);

            printf("结果：%f", Compute(a));

        }
    }
}

/**
 * 检查c或c++文件{}（）【】是否成对出现
 * @param filePath 文件路径
 * @return
 */
int checkBrackets(char *filePath) {
    struct StackSq a;
    char ch;
    FILE *finstr;
    finstr = fopen(filePath, "r");
    if (!finstr) {
        printf("FILE \'%s\' not found!");
        exit(1);
    }
    InitStackSq(&a);
    ch = fgetc(finstr);
    while (ch != EOF) {
        printf("%c", ch);
        switch (ch) {
            case '[':
            case '{':
            case '(': {
//                printf("入栈的字符串：%c\n", ch);
                Push(&a, ch);

            }
                break;
            case '}': {
                if (Peek(&a) == '{') {
                    Pop(&a);
                } else {
                    return 0;
                }
            }
                break;
            case ')': {
                if (Peek(&a) == '(') {
                    Pop(&a);
                } else {
                    return 0;
                }
            }
                break;
            case ']': {
                if (Peek(&a) == '[') {
                    Pop(&a);
                } else {
                    return 0;
                }
            }
                break;
        }
        ch = fgetc(finstr);
    }
    if (EmptyStack(&a))
        return 1;
    else
        return 0;
}

/**
 * 十进制数转换为其他进制
 * @param num 十进制数
 * @param r 进制
 */
void Transform(long num, int r) {
    struct StackSq a;
    InitStackSq(&a);
    while (num != 0) {
        int k = num % r;
        Push(&a, k);
        num = num / r;
    }
    while (!EmptyStack(&a)) {
        printf("%d", Pop(&a));
    }
    printf("\n");
}

/**
 * 后缀表达式的计算
 * @param str 例子：“3 5 / 6 +“=”3/5+6”
 */
double Compute(char *str) {
    struct StackSq s;
    double x, y;
    int i = 0;

    InitStackSqByMaxsize(&s, 5);
    while (str[i]) {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        switch (str[i]) {
            case '+': {
                x = Pop(&s) + Pop(&s);
                i++;
            }
                break;
            case '-': {
                x = Pop(&s);
                x = Pop(&s) - x;
                i++;
            }
                break;
            case '*': {
                x = Pop(&s) * Pop(&s);
                i++;
            }
                break;
            case '/': {
                x = Pop(&s);
                if (x != 0.0) {
                    x = Pop(&s) / x;
                } else {
                    printf("除数不能为0\n");
                    exit(1);
                }
                i++;
            }
                break;
            default: {
                x = 0;
                while (str[i] >= 48 && str[i] <=57) {
                    x = x * 10 + str[i] - 48;
                    i++;
                }
                if (str[i] == '.') {
                    double j = 10.0;
                    i++;
                    y = 0;
                    while (str[i] >= 48 && str[i] <= 57) {
                        y = y + (str[i] - 48) / j;
                        i++;
                        j = j * 10;
                    }
                    x = x + y;
                }
            }
        }
        Push(&s, x);
    }

    if (EmptyStack(&s)) {
        printf("后缀表达式错误！！\n");
        exit(1);
    }

    x = Pop(&s);
    if (EmptyStack(&s)) {
        return x;
    } else {
        printf("后缀表达式错误！！\n");
        exit(1);
    }
}
