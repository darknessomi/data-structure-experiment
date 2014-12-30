/*
* @Author: omi
* @Date:   2014-12-18 18:09:29
* @Last Modified by:   ZHANG RT
* @Last Modified time: 2014-12-18 18:23:52
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int arrange1(int addp[][2], int count)
{
    int i, j, a, b = 0;
    for (i = 0; i < count; i++)          //消除系数为0的影响
    {
        if (addp[i][0] == 0)
        {
            for (b = i; b < count; b++)
            {
                addp[b][0] = addp[b + 1][0];
                addp[b][1] = addp[b + 1][1];
            }
            i--; count--;
        }
    }
    for (i = 1; i < count - 1; i++)             //大的沉底
    {
        for (j = 0; j < count - 1; j++)
        {
            if (addp[j][1] > addp[j + 1][1])
            {
                a = addp[j][0];
                addp[j][0] = addp[j + 1][0];
                addp[j + 1][0] = a;
                a = addp[j][1];
                addp[j][1] = addp[j + 1][1];
                addp[j + 1][1] = a;
            }
        }
    }
    print(addp, count);
}

int arrange2(int addp[][2], int count)
{
    int i, j, a, b = 0;
    for (i = 0; i < count; i++)          //消除系数为0的影响
    {
        if (addp[i][0] == 0)
        {
            for (b = i; b < count; b++)
            {
                addp[b][0] = addp[b + 1][0];
                addp[b][1] = addp[b + 1][1];
            }
            i--; count--;
        }
    }
    for (i = 1; i < count; i++)               //小的沉底
    {
        for (j = 0; j < count - 1; j++)
        {
            if (addp[j][1] < addp[j + 1][1])
            {
                a = addp[j][0];
                addp[j][0] = addp[j + 1][0];
                addp[j + 1][0] = a;
                a = addp[j][1];
                addp[j][1] = addp[j + 1][1];
                addp[j + 1][1] = a;
            }
        }
    }
    print(addp, count);
}
int print(int Am[][2], int m)
{
    int i, j;
    if (m == 0)
    {
        printf("该多项式为 Y=0\n");
        exit(-1);
    }
    printf("该多项式为 Y=");
    if (Am[0][1] != 0)           //第一项
    {
        printf("%dX^%d", Am[0][0], Am[0][1]);
    }
    if (Am[0][1] == 0)
        printf("%d", Am[0][0]);
    if (m == 1) printf("\n");
    else
    {
        for (i = 1; i < m; i++)
        {
            if (Am[i][0] > 0) printf("+");
            if (Am[i][1] != 0)
            {
                printf("%dX^%d", Am[i][0], Am[i][1]);
            }
            if (Am[i][1] == 0)
                printf("%d", Am[i][0]);
        }
        printf("\n");
    }
}

int main()
{
    int Am[MAX][2], Bn[MAX][2];
    int xuan, n, m, i, j, biaoji, count1, count2, zhongjian;
    char sign;
    biaoji = 1;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < 2; j++ )
        {
            Am[i][j] = 0;
            Bn[i][j] = 0;
        }
    }
    printf("1、创建两个一元多项式\n");
    printf("2、两多项式相加得一新多项式\n");
    printf("3、两多项式相减得一新多项式\n");
    printf("4、两多项式相乘得一新多项式\n");
    printf("5、销毁已建立的两个多项式\n");
    printf("6、退出\n");
    printf("\n");
    while (1)
    {
        printf("请选择：");
        scanf("%d", &xuan);
        switch (xuan)
        {
        case 1:
            for (i = 0; i < MAX; i++)
            {
                if (Am[i][0] != 0 || Am[i][1] != 0)
                {
                    printf("多项式已经建立，请选择其他操作");
                    biaoji = 2;
                    i = MAX;
                }
            }
            if (biaoji == 2) break;
            printf("请输入第一个多项式：\n");
            printf("要输入几项：");
            scanf("%d", &m);
            while (m == 0)
            {
                printf("m 不能为 0，请重新输入 m:");
                scanf("%d", &m);
            }
            count1 = 1;
            for (i = 0; i < m; i++)
            {
                printf("请输入第%d 项的系数和指数：", count1++);
                scanf("%d%d", &Am[i][0], &Am[i][1]);
                if (Am[i][0] == 0)
                {
                    i--;
                    m--;
                }
            }
            biaoji = 3;
            for (i = 0; i < m; i++)             //合并同类项
            {
                for (j = i + 1; j < m; j++)
                {
                    if (Am[i][1] == Am[j][1])
                    {
                        Am[i][0] = Am[i][0] + Am[j][0];
                        for (zhongjian = j; zhongjian < m; zhongjian++)
                        {
                            Am[zhongjian][0] = Am[zhongjian + 1][0];
                            Am[zhongjian][1] = Am[zhongjian + 1][1];
                        }
                        m--;
                    }
                }
            }
            printf("*************************m=%d", m);
            print(Am, m);
            printf("请输入第二个多项式：\n");
            printf("要输入几项：");
            scanf("%d", &n);
            while (n == 0)
            {
                printf("项数不能为 0，请重新输入 m:");
                scanf("%d", &n);
            }
            count2 = 1;
            for (i = 0; i < n; i++)
            {
                printf("请输入第%d 项的系数和指数：", count2++);
                scanf("%d%d", &Bn[i][0], &Bn[i][1]);
                if (Bn[i][0] == 0)
                {
                    i--;
                    n--;
                }
            }
            biaoji = 3;
            for (i = 0; i < n; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    if (Bn[i][1] == Bn[j][1])
                    {
                        Bn[i][0] = Bn[i][0] + Bn[j][0];
                        for (zhongjian = j; zhongjian < n; zhongjian++)
                        {
                            Bn[zhongjian][0] = Bn[zhongjian + 1][0];
                            Bn[zhongjian][1] = Bn[zhongjian + 1][1];
                        }
                        n--;

                    }
                }
            }
            printf("*************************n=%d", n);
            print(Bn, n);
            break;
        case 2:
            if (biaoji == 1)
            {
                printf("请先创建两个一元多项式！\n");
                break;
            }
            int addp[MAX][2];
            for (i = 0; i < m; i++)
            {
                addp[i][0] = Am[i][0];
                addp[i][1] = Am[i][1];
            }
            for (i, j = 0; i < m + n; i++)
            {
                addp[i][0] = Bn[j][0];
                addp[i][1] = Bn[j][1];
                j++;
            }
            count1 = m + n;
            for (i = 0; i < count1; i++)             //合并同类项
            {
                for (j = i + 1; j < count1; j++)
                {
                    if (addp[i][1] == addp[j][1])
                    {
                        addp[i][0] = addp[i][0] + addp[j][0];
                        for (zhongjian = j; zhongjian < count1; zhongjian++)
                        {
                            addp[zhongjian][0] = addp[zhongjian + 1][0];
                            addp[zhongjian][1] = addp[zhongjian + 1][1];
                        }
                        count1--;
                    }
                }
            }
            printf("升序 1 , 降序 2\n");
            printf("选择:");
            scanf("%d", &j);
            if (j == 1) arrange1(addp, count1);
            else arrange2(addp, count1);
            break;
        case 3:
            if (biaoji == 1)
            {
                printf("请先创建两个一元多项式！\n");
                break;
            }
            int subp[MAX][2];
            for (i = 0; i < m; i++)
            {
                subp[i][0] = Am[i][0];
                subp[i][1] = Am[i][1];
            }
            for (i, j = 0; i < m + n; i++)
            {
                subp[i][0] = -Bn[j][0];
                subp[i][1] = Bn[j][1];
                j++;
            }
            count1 = m + n;
            for (i = 0; i < count1; i++)             //合并同类项
            {
                for (j = i + 1; j < count1; j++)
                {
                    if (subp[i][1] == subp[j][1])
                    {
                        subp[i][0] = subp[i][0] + subp[j][0];
                        for (zhongjian = j; zhongjian < count1; zhongjian++)
                        {
                            subp[zhongjian][0] = subp[zhongjian + 1][0];
                            subp[zhongjian][1] = subp[zhongjian + 1][1];
                        }
                        count1--;
                    }
                }
            }
            printf("升序 1 , 降序 2\n");
            printf("选择:");
            scanf("%d", &j);
            if (j == 1) arrange1(subp, count1);
            else arrange2(subp, count1);
            break;
        case 4:
            if (biaoji == 1)
            {
                printf("请先创建两个一元多项式！\n");
                break;
            }
            int multp[MAX][2];
            count1 = 0;
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    multp[count1][0] = Am[i][0] * Bn[j][0];
                    multp[count1][1] = Am[i][1] + Bn[j][1];
                    count1++;
                }
            }
            for (i = 0; i < count1; i++)             //合并同类项
            {
                for (j = i + 1; j < count1; j++)
                {
                    if (multp[i][1] == multp[j][1])
                    {
                        multp[i][0] = multp[i][0] + multp[j][0];
                        for (zhongjian = j; zhongjian < count1; zhongjian++)
                        {
                            multp[zhongjian][0] = multp[zhongjian + 1][0];
                            multp[zhongjian][1] = multp[zhongjian + 1][1];
                        }
                        count1--;
                    }
                }
            }
            printf("升序 1 , 降序 2\n");
            printf("选择:");
            scanf("%d", &j);
            if (j == 1) arrange1(multp, count1);
            else arrange2(multp, count1);
            break;
        case 5:
            if (biaoji == 1)
            {
                printf("请先创建两个一元多项式！\n");
                break;
            }
            biaoji = 1;
            for (i = 0; i < MAX; i++)
            {
                for (j = 0; j < 2; j++ )
                {
                    Am[i][j] = 0;
                    Bn[i][j] = 0;
                }
            }
            break;
        case 6:
            exit(-1);
        }
    }
}


