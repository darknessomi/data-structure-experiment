/*
* @Author: omi
* @Date:   2014-12-03 20:16:30
* @Last Modified by:   omi
* @Last Modified time: 2014-12-03 20:16:42
*/

typedef struct
{
    int elem[20];
    int len;
} Sqlist;
int locateelem_sq(Sqlist *l, int x)
{
    int i;
    i = 1;
    printf("len%d--%d", l->len, x);
    for (i = 1; i <= l->len; ++i)
        if (x == l->elem[i])
        {
            printf("%d--%d", i, l->elem[i]);
            return i;
        }
    printf("i=%d", i);
    return 0;
}

int Insert_sq(Sqlist *l, int i, int x)
{
    int j;
    if (i < 1 || i > l->len + 1)return 0;
    if (l->len == 19)return -1;
    for (j = l->len; j >= i; --j)
        l->elem[j + 1] = l->elem[j];
    l->elem[i] = x;
    ++l->len; return 1;
}

int Delete_Sq(Sqlist *l, int i)
{
    int j;
    if (i < 1 || i > l->len) return 0;
    if (l->len == 0) return -1;
    for (j = i; j <= l->len; j++)
        l->elem[j] = l->elem[j + 1];
    --l->len;
    return 1 ;
}

main()
{
    Sqlist s, *l;
    int i, x, j, n, y;
    l = &s;
    printf("\nn=");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%3d", &l->elem[i]);
    l->len = n;
    for (i = 1; i <= l->len ; i++)
        printf("%3d", l->elem[i]);
    printf("\ncharu:\ni=?");
    scanf("%3d", &i);
    printf("x=?");
    scanf("%d", &x);
    Insert_sq(l, i, x);
    for (i = 1; i <= l->len; i++)
        printf("%3d", l->elem[i]);
    printf("\nlen=\n%d", l->len);
    printf("\nshanchu:\ni=?");
    scanf("%d", &i);
    Delete_Sq(l, i);
    for (i = 1; i <= l->len; i++)
        printf("%3d", l->elem[i]);
    printf("\nlen=\n%3d", l->len);
    printf("\nloc:x=");
    scanf("%d", &x);
    y = locateelem_sq(l, x);
    printf("end%d", y);
}

