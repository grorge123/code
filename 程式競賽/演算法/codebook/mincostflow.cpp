#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
//最小费用最大流，求最大费用只需要取相反数，结果取相反数即可。
//点的总数为 N，点的编号 0~N-1
const int MAXN = 1005;
const int MAXM = 10005;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow,cost;
} edge[MAXM*4];
int head[MAXN],tol;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;//节点总个数，节点编号从0~N-1
void init(int n)
{
    N = n;
    tol = 0;
    memset(head,-1,sizeof (head));
}
void addedge (int u,int v,int cap,int cost)
{
    edge[tol].to = v;
    edge[tol].cap = cap;
    edge[tol].cost = cost;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = 0;
    edge[tol].cost = -cost;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}
bool spfa(int s,int t)
{
    queue<int>q;
    for(int i = 0; i < N; i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i !=  -1; i = edge[i]. next)
        {
            int v = edge[i]. to;
            if(edge[i].cap > edge[i].flow &&
                    dis[v] > dis[u] + edge[i]. cost )
            {
                dis[v] = dis[u] + edge[i]. cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1)return false;
    else return true;
}
//返回的是最大流，cost存的是最小费用
int minCostMaxflow(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while(spfa(s,t))
    {
        int Min = INF;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            if(Min > edge[i].cap - edge[i]. flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i]. cost * Min;
        }
        flow += Min;
    }
    return flow;
}
int main(){
   int n,m,sta;
   while(scanf("%d%d",&n,&m)!=EOF){
       memset(pre,0,sizeof(pre));
       memset(dis,0,sizeof(dis));
       memset(vis,false,sizeof(vis));
       memset(edge,0,sizeof(edge));
      init(n+2);
      int u,v,w;
      for(int i=0;i<m;i++){
          scanf("%d%d%d",&u,&v,&w);
          addedge(u,v,1,w);
         addedge(v,u,1,w);

      }
      int ans1=0;
      addedge(0,1,2,0);
      addedge(n,n+1,2,0);
      int temp=minCostMaxflow(0,n+1,ans1);
      printf("%d\n",ans1);

   }
}
/*
本体题意为有n个农场，某人·1要从一个厂子走到另一个厂子，问最短的距离是多少
可以建点，建一个超级远点，加盟一个超级会点，分别设为0.和n+1l设超级原点到1点的流量为2，n点到超级会点的流量为2，
其余个边的流量都设为1，可以从超级原点到超级会点跑最小费用最大流，各个变的费即为该变所在的；路径长度，
我用的框斌的模板，一定涛注意在村边的时候addedge的时候需要正反两条边都要存进去
别的地方不需要动
 
还有返回的flow是流量，并不是最小费用，最小费用的是传参数传过去的cost的值，所以在输出的时候应该输出cost的值
下面附上本人搓搓的代码
*/


N M Q
N*M MAP

045621


N LOGN LOGN 處理出 各個DELTA值左右連續有幾個不比他好
每次詢問L~R時
ASK(  )
1  5  2  9  1  3  4  2  1
  + 7 + 8 + 8 + 8 + 8 + 8
   5  2  9  1  3  4  2  1
      + 8 + 8 + 8 + 8 + 8
      2  9  1  3  4  2  1
        + 8 + 8 + 8 + 8 + 8
         9  1  3  4  2  1
	   8 + 8 + 8 + 8 + 8
            1  3  4  2  1
	      2+ 2+ 2+ 2
	       3  4  2  1
		1 + 2 + 2
		  4  2  1
		    2+ 2
		     2  1
			1










0~9 delta
question