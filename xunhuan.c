#include <stdio.h>

#include <stdlib.h>

#define STACK_INIT_SIZE 100

#define STACK_INCREMENT 10

struct Stack                    //定义栈
{
    char *base;
    char *top;
    int stacksize;
};
void InitStack(struct Stack &s) //构造栈
{
    s.base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
}
void Push(struct Stack &s, char e) //往栈中压入元素
{
    if (s.top - s.base >= STACK_INIT_SIZE)
    {
        s.base = (char *)realloc(s.base, (s.stacksize + STACK_INCREMENT) * sizeof(char));
        s.top = s.base + s.stacksize;
        s.stacksize += STACK_INCREMENT;
    }
    *(s.top) = e;
    s.top++;
}
void Pop(struct Stack &s, char &e) //取出栈中的元素
{
    e = *--s.top;
}
int StackEmpty(struct Stack s)     //判断栈是否为空
{
    if (s.top == s.base) return 1;
    else return 0;
}
void ClearStack(struct Stack &s)     //清空栈
{
    s.top = s.base;
}
struct Queue                         //定义队列
{
    char data;
    struct Queue *next;
};
struct LinkQueue
{
    struct Queue *front;
    struct Queue *rear;
};
void InitQueue(struct LinkQueue &q)       //构造队列
{
    q.front = q.rear = (struct Queue *)malloc(sizeof(struct Queue));
    q.front->next = NULL;
}
void EnQueue(struct LinkQueue &q, char e)   //元素入队
{
    struct Queue *p;
    p = (struct Queue *)malloc(sizeof(struct Queue));
    p->data = e;
    p->next = NULL;      q.rear->next = p;
    q.rear = p;
}
void DeQueue(struct LinkQueue &q, char &e)  //元素出队
{
    struct Queue *p;
    p = q.front->next;
    e = p->data;
    q.front->next = p->next;
    if (q.rear == p) q.rear = q.front;
    free(p);
}
int QueueEmpty(struct LinkQueue q)   //判断队列是否为空，如果对为空，返回1，否则返回0
{
    if (q.front == q.rear)  return 1;
    else    return 0;
}
void InStack(char *ch, struct Stack &s) //把字符数组从右至左压入栈中
{
    int i, L = 0;
    while (ch[L] != '\0') L++;
    for (i = L - 1; i >= 0; i--) Push(s, ch[i]);
}
int main()                      //主函数从此开始进行
{
	{    
		printf("**************************************************************\n");
	    printf("*               *   欢迎光临山东理工大学   *                 *\n");
	    printf("*               ****************************                 *\n");
	    printf("*               *     魔王语言解释系统     *                 *\n");
	    printf("*               ****************************                 *\n");
	    printf("*             班级：计算机科学与技术学院信应1301             *\n");
	    printf("*               姓名: 张睿提  学号: 13310542008               *\n");
	    printf("**************************************************************\n"); int xunhuan = 1;
	    printf("请输入你想要解释的魔王语言：\n");
	    while (xunhuan == 1)      //一个总循环控制整个程序的重复进行
	    {
	        int i = 0;                //i作为计数器
	        char A[] = "sae";         //大写字母作为字符数组名存放小写字母
	        char B[] = "tsaedsae";
	        char flag = '0';          //flag用来标记处理括号
	        char e1, key, e2, e;
	        int mark = 1;             //标记输入的魔王语言是否在允许的范围之内
	        int f = 1;                // 判断括号是否匹配
	        char MoWang[100] = "\0";  //定义一个魔王变量，存放待解释的语言字符
	        struct Stack S;           //作为栈存储元素，为后续操作和输出做准备
	        struct Stack temp;        //用来处理括号外的元素
	        InitStack(S);
	        InitStack(temp);
	        struct LinkQueue Q;
	        InitQueue(Q);
	        gets(MoWang);                       //变量MoWang存储输入的语言
	        InStack(MoWang, S);                 //把要解释的魔王语言压入栈中
	        while (!StackEmpty(S))              //把魔王语言进行出栈，不符合语言的进行提示
	        {
	            Pop(S, e1);
	            if (e1 == '(')
	            {
	                if (StackEmpty(S))
	                {
	                    printf("魔王语言错误!\n");
	                    mark = 0; f = 0;
	                    break;
	                }
	                while (!StackEmpty(S))
	                {
	                    Pop(S, e1);
	                    if (e1 == ')')
	                    {
	                        f = 1;
	                        break;
	                    }
	                    else if (!(e1 >= 'a' && e1 <= 'z') && !(e1 >= 'A' && e1 <= 'Z'))
	                    {
	                        printf("魔王语言错误！\n");
	                        mark = 0;
	                        break;
	                    }
	                }
	                if (mark == 0)
	                    break;
	                if (f != 1)
	                {
	                    printf("魔王语言错误！\n");
	                    break;
	                }
	            }
	            else if (e1 == ')')
	            {
	                printf("魔王语言错误！\n");
	                mark = 0;
	                break;
	            }
	            else if (!(e1 >= 'a' && e1 <= 'z') && !(e1 >= 'A' && e1 <= 'Z'))
	            {
	                printf("魔王语言错误！\n");
	                mark = 0;
	                break;
	            }
	        }
	        if (mark == 1 && f == 1)               //对符合语言规则的魔王语言进行规则处理
	        {
	            ClearStack(S);
	            InStack(MoWang, S);           //把魔王语言从右至左压栈存放
	            while (!StackEmpty(S))        //栈不空时，用栈temp进行存储             {
	                Pop(S, e1);
	            if (e1 == 'B' || e1 == 'A') Push(temp, e1);
	            else if (e1 == '(')           //用队存储括号中的元素
	            {
	                Push(temp, flag);      //有括号的话就用flag标记
	                Pop(S, e1);
	                while (e1 != ')')     //把括号中的元素存入队列中
	                {
	                    EnQueue(Q, e1);
	                    Pop(S, e1);

	                }
	                if (!QueueEmpty(Q)) DeQueue(Q, key); //将队头的元素赋值给key
	            }
	            else
	            {
	                Push(temp, e1);
	                f = 0;
	            }
	        }
	        while (!StackEmpty(temp))           //将魔王说的语言规则地压入栈s中
	        {
	            Pop(temp, e1);
	            if (e1 != flag)   Push(S, e1); //把括号外的元素压入中
	            else
	            {
	                while (!QueueEmpty(Q)) //处理括号中的元素进栈
	                {
	                    DeQueue(Q, e2);
	                    Push(S, key);
	                    Push(S, e2);
	                }
	                if (f != 0)   Push(S, key); //最后还要压一个key
	            }
	        }
	        printf("解释后的语言为：\n");
	        while (!StackEmpty(S))         //依次出栈输出处理后的元素
	        {
	            Pop(S, e);
	            EnQueue(Q, e);          //元素进队是为了输出对应汉字
	            if (e == 'B') printf("%s", B);
	            else if (e == 'A') printf("%s", A);
	            else printf("%c", e);
	        }
	        printf("\n");
	        while (!QueueEmpty(Q))           //翻译成对应的汉字
	        {
	            DeQueue(Q, e);
	            switch (e)                //对应不同的解释输出相应的汉字
	            {
	            case 't': printf("天"); break;
	            case 'd' : printf("地"); break;
	            case 's' : printf("上"); break;
	            case 'a' : printf("一只"); break;
	            case 'e' : printf("鹅"); break;
	            case 'z' : printf("追"); break;
	            case 'g' : printf("赶"); break;
	            case 'x' : printf("下"); break;
	            case 'n' : printf("蛋"); break;
	            case 'h' : printf("恨"); break;
	            case 'B' : printf("天上一只鹅地上一只鹅"); break;
	            case 'A' : printf("上一只鹅"); break;
	            default : printf("*"); break;
	            }
	        }
	        printf("\n");
	    }
	    printf("再次输入魔王语言（退出按0键）：\n");
	    scanf("%d", &xunhuan);
	}
return 0;
}
