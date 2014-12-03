/*
* @Author: omi
* @Date:   2014-12-03 19:14:23
* @Last Modified by:   omi
* @Last Modified time: 2014-12-03 19:44:02
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
    LinkList head, p;
    int num, n;
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
    printf("\ngoodbay!(0)");
    scanf("%d", &n);
    if (n == 0)
        return 0;
}

