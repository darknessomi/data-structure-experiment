/*
* @Author: omi
* @Date:   2014-12-03 19:51:54
* @Last Modified by:   omi
* @Last Modified time: 2014-12-03 19:54:19
*/

#define Maxsize 20
typedef int DataType ;
typedef struct
{
    DataType data[Maxsize];
    int top;
} SeqStack;

void InitStack(SeqStack *S)
{
    S->top = 0;
}

int StackEmpty(SeqStack *S)
{
    if (S->top == 0)return 1;
    else
        return 0;
}

void Push(SeqStack *S, DataType x)
{
    if (S->top == Maxsize - 1)
        printf("Stack overflow");
    else
        S->data[(S->top)++] = x;
}

DataType Pop(SeqStack *S)
{
    if (StackEmpty(S))
        printf("Stackunderflow");
    else
        return S->data[--(S->top)];
}
void conversion(int n, int d);
void main()
{
    int n, d;
    char ch;
    printf("start-- y,exit-- n :");
    scanf("\n%c", &ch);
    while (ch == 'y')
    {
        printf("input n:");
        scanf("%d", &n);
        printf("input d:");
        scanf("%d", &d);
        conversion(n, d);
        printf("contiue-- y,exit---n");
        scanf("\n%c", &ch);
    }
}
void conversion(int n, int d)
{
    DataType k;
    SeqStack L, *S;
    S = &L;
    InitStack(S);
    while (n)
    {
        Push(S, n % d);
        n = n / d;
    }
    printf("out:\n");
    while (!StackEmpty(S))
    {
        k = Pop(S);
        switch (k)
        {
        case 10: printf("%c", 'a');
            break;
        case 11: printf("%c", 'b');
            break;
        case 12: printf("%c", 'c');
            break;
        case 13: printf("%c", 'd');
            break;
        case 14: printf("%c", 'e');
            break;
        case 15: printf("%c", 'f');
            break;
        default: printf("%d", k);
        }
    }
    printf("\n");
}



