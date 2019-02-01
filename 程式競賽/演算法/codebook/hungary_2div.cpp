#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

/* **************************************************************************
//二分图匹配（匈牙利算法的DFS实现）
//初始化：g[][]两边顶点的划分情况
//建立g[i][j]表示i->j的有向边就可以了，是左边向右边的匹配
//g没有边相连则初始化为0
//L是匹配左边的顶点数，R是匹配右边的顶点数
//调用：res=hungary();输出最大匹配数
//优点：适用于稠密图，DFS找增广路，实现简洁易于理解
//时间复杂度:O(VE)
//***************************************************************************/
//顶点编号从1开始的
#define MAXN 317
int LN,RN;//L,R数目
int g[MAXN][MAXN], linker[MAXN];
bool used[MAXN];
int dfs(int L)//从左边开始找增广路径
{
    int R;
    for(R = 1; R <= RN; R++)
    {
        if(g[L][R]!=0 && !used[R])
        {
            //找增广路，反向
            used[R]=true;
            if(linker[R] == -1 || dfs(linker[R]))
            {
                linker[R]=L;
                return 1;
            }
        }
    }
    return 0;//这个不要忘了，经常忘记这句
}
int hungary()
{
    int res = 0 ;
    int L;
    memset(linker,-1,sizeof(linker));
    for( L = 1; L <= LN; L++)
    {
        memset(used,0,sizeof(used));
        if(dfs(L) != 0)
            res++;
    }
    return res;
}
int main()
{
    int t;
    int p, n;
    int k, L, R;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&p,&n);
        memset(g,0,sizeof(g));
        for(int i = 1; i <= p; i++)
        {
            scanf("%d",&k);
            for(int j = 1; j <= k; j++)
            {
                scanf("%d",&R);
                L = i;
                g[L][R] = 1;
            }
        }
        LN = p;
        RN = n;
        int res = hungary();//最大匹配数
        //printf("%d\n",res);
        if(res == p)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0 ;
}
/*
题意：
一共有 p 门课，每门课都有若干的学生，现在要为每个课程选一名课代表，
每个学生只能担任一门课的课代表，如果每个课都能找到课代表，则输出"YES"，否则"NO"。

PS：
二分图最大匹配，对课程—学生关系建立一个图，进行二分图的最大匹配，
如果最大匹配数==课程数，说明能够满足要求，否则不能。
*/