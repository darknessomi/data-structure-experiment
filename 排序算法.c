/*
* @Author: omi
* @Date:   2014-12-03 20:24:36
* @Last Modified by:   omi
* @Last Modified time: 2014-12-03 20:24:44
*/

typedef struct
{
    int elem[20];
    int len;
} Sqlist;
void  insertsort(Sqlist r , int n)
{
    int  i, j ;
    for (i = 2; i <= n; i++)
    {
        r.elem[0] = r.elem[i]; //设置岗哨
        j = i - 1;
        while (r.elem[0] < r.elem[j])
        {
            r.elem[j + 1] = r.elem[j];
            j --;
        }
        r.elem[j + 1] = r.elem[0];
    }
}// insertsort
main()
{
    Sqlist s;
    int i, x, j, n, y;
    printf("\nn=");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%3d", &s.elem[i]);
    s.len = n;
    for (i = 1; i <= s.len ; i++)
        printf("%3d", s.elem[i]);
    printf("\nzhijie charu paixu:\n");
    insertsort  (s , s.len );
    for (i = 1; i <= s.len; i++)
        printf("%3d", s.elem[i]);
    printf("\nlen=\n%d", s.len);
    printf("\ngoodbay!\n");
}

