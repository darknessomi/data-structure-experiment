/*
* @Author: omi
* @Date:   2014-12-03 20:10:03
* @Last Modified by:   omi
* @Last Modified time: 2014-12-03 20:10:28
*/

#include "stdio.h"
#define M 50
#define N 4
void init(int b[][N])  /*初始化图*/
{
    int i, j, k;
    for (i = 0; i < N; i++) /*弧的尾结点*/
        for (j = 0; j < N; j++) /*弧的头结点*/
        {
            printf("%d,%d(%d)", i + 1, j + 1, M);
            scanf("%d", &b[i][j]); /*输入权值*/
        }
}

void fz(int b[][N], int d[][N]) /*复制一个图*/
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            d[i][j] = b[j][i];
}

void sc(int b[][N])/*显示图*/
{
    int i, j;
    for (i = 0; i < N; i++) /*显示图或最小生成树的数组*/
    {
        for (j = 0; j < N; j++)
            printf("%d  ", b[i][j]);
        printf("\n");
    }

}
main()
{
    int a[N][N], c[N][N];
    printf("\nshuruhu:\n\n");
    init(a);/*初始化图*/
    printf("\nxianshitu\n\n");
    sc(a);/*显示图*/

    fz(a, c); /*图转置*/
    printf("\nxianshizhuanzhitu\n\n");
    sc(c);/*显示图*/
}
