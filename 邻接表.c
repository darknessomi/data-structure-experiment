/*
* @Author: omi
* @Date:   2014-12-03 20:11:47
* @Last Modified by:   omi
* @Last Modified time: 2014-12-03 20:13:01
*/

typedef struct
{
    int dingdianxiangliang[10];
    int juzhen[10][10];
    int dingdianshu, hushu;
} Tu;
main()
{
    int i, j, k, V1, V2, w;
    Tu G;
    scanf("%d,%d", &G.dingdianshu, &G.hushu);
    for (i = 0; i < G.dingdianshu; i++)
        scanf("%d", &G.dingdianxiangliang[i]);
    for (i = 0; i < G.dingdianshu; i++)
        for (j = 0; j < G.dingdianshu; j++)
            G.juzhen[i][j] = -1;
    for (i = 0; i < G.dingdianshu; i++)
        for (j = 0; j < G.dingdianshu; j++)
        {
            printf("%d    ", G.juzhen[i][j]);
            if (j == 4)   printf("\n");
        }
    for (k = 0; k < G.hushu; k++)
    {
        scanf("%d,%d,%d", &V1, &V2, &w);
        i = 0; j = 0;
        while (G.dingdianxiangliang[i] != V1)
            i++;
        while (G.dingdianxiangliang[j] != V2)
            j++;
        G.juzhen[i][j] = w;
        G.juzhen[j][i] = G.juzhen[i][j];
    }
    for (i = 0; i < G.dingdianshu; i++)
        for (j = 0; j < G.dingdianshu; j++)
        {
            printf("%d    ", G.juzhen[i][j]);
            if (j == 4)   printf("\n");
        }

}
