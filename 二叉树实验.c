/*
* @Author: omi
* @Date:   2014-12-03 20:01:45
* @Last Modified by:   omi
* @Last Modified time: 2014-12-03 20:02:23
*/

#define  Null 0
typedef struct node
{
    int  data;
    struct node *lchild, *rchild;
} bitree, *bt;
#define  maxsize  64;
typedef  struct
{
    bt  data[64];
    int top;
} seqstack;
seqstack  *s;
bitree  *creat()
{
    bitree  *t;
    int x;
    scanf("%d", &x);
    if (x == 0)
        t = Null;
    else
    {
        t = (bitree *)malloc(sizeof(bitree));
        t->data = x;
        t->lchild = creat();
        t->rchild = creat();
    }
    return  t;
}

void  inorder(t)
bitree  *t;
{
    if (t != Null)
    {
        inorder(t->lchild);
        printf("%4d", t->data);
        inorder(t->rchild);
    }
}

void exchange(t)
bitree *t;
{
    seqstack  a;
    bitree *p;
    seqstack *s;
    s = &a;
    if (t)
    {
        s->top = 1;
        s->data[s->top] = t;
        do
        {
            t = s->data[s->top];
            s->top--;
            if ((t->lchild != Null) || (t->rchild != Null))
            {
                p = t->lchild;
                t->lchild = t->rchild;
                t->rchild = p;
            }
            if (t->lchild != Null)
            {
                s->top++;
                s->data[s->top] = t->lchild;
            }
            if (t->rchild != Null)
            {
                s->top++;
                s->data[s->top] = t->rchild;
            }
        }
        while (s->top == 0);
    }
}

main()
{
    bitree  *root;
    printf("\n");
    root = creat();
    inorder(root);
    exchange(root);
    printf("\n");
    inorder(root);
}
