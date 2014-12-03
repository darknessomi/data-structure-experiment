/*
* @Author: omi
* @Date:   2014-12-03 19:33:35
* @Last Modified by:   omi
* @Last Modified time: 2014-12-03 19:44:34
*/

#include <stdio.h>
#include <conio.h>
#include <alloc.h>
typedef int dataType;
typedef struct node
{
    dataType data;
    struct node *next;
} *LinkList;

void main()
{
    LinkList head, p, u, pre;
    int num, m, k = 0;
    head = malloc(sizeof(struct node));
    head->data = -1;
    head->next = head;
    printf("\n\n---000head=%d,000data=%d---\n", head, head->data);
    printf("\n\n Input integer(ending with -1):\n");
    scanf("%d", &num);
    while (num != -1)
    {
        p = (LinkList)malloc(sizeof(struct node));
        p->data = num;
        p->next = head->next;
        head->next = p;
        scanf("%d", &num);
    }
    p = head->next;
    printf("---111head=%d:111data=%d---\n", p, p->data);
    while (p != head)
    {
        printf("data:");
        printf("%d\n", p->data);
        p = p->next;
    }
    p = head;
    printf("\n\n Count Number m==?");
    scanf("%d", &m);
    printf("\n\n\n\n%40s\n\n", "select");
    while (p->next != p)
    {
        pre = p;
        p = p->next;
        if (p == head)
        {
            pre = p;
            p = p->next;
        }
        ++k;
        if (k == m)
        {
            printf("%5d", p->data);
            pre->next = p->next;
            u = p;
            free(u);
            p = pre;
            k = 0;
        }
    }
    printf("\n\n%40s", "select out!\n");
    printf("\n\n%40s", "Good Bye!(0)");
    scanf("%d", &m);
    if (m == 0)
        return 0;
}




