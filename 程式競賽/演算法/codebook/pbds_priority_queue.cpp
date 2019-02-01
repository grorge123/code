#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <cstdio>  
#include <cstring>  
#include <ext/pb_ds/priority_queue.hpp>    /*****/  
#define LL long long  
#define pa pair<LL,int>  
#define inf 10000000000000000LL  
using namespace std;  
using namespace __gnu_pbds;    /*****/  
typedef __gnu_pbds::priority_queue<pa,greater<pa>,pairing_heap_tag> heap;   /*****/  
int n,m,tot,h[1000005];  
int T,rxa,rxc,rya,ryc,rp;  
heap::point_iterator id[1000005];  
struct edge  {  
    int y,ne,v;  
}e[10000005];  
LL d[1000005];  
void Addedge(int x,int y,int v)  {  
    e[++tot].y=y;  
    e[tot].v=v;  
    e[tot].ne=h[x];  
    h[x]=tot;  
}  
void dijkstra()  
{  
    heap q;  
    for (int i=1;i<=n;i++)   d[i]=inf;  
    d[1]=0,id[1]=q.push(make_pair(0,1));  
    while (!q.empty())  
    {  
        int x=q.top().second;  
        q.pop();  
        for (int i=h[x];i;i=e[i].ne)  {
            if (e[i].v+d[x]<d[e[i].y])  {  
                int y=e[i].y;  
                d[y]=d[x]+e[i].v;  
                if (id[y]!=0)  
                    q.modify(id[y],make_pair(d[y],y));   /*****/  
                else id[y]=q.push(make_pair(d[y],y));  
            }  
        }
    }  
    cout<<d[n]<<endl;  
}  
int main(){  
    scanf("%d%d",&n,&m);  
    scanf("%d%d%d%d%d%d",&T,&rxa,&rxc,&rya,&ryc,&rp);  
    int x,y,z,a,b;  
    x=y=z=0;  
    for (int i=1;i<=T;i++)  {  
        x=((LL)x*rxa+rxc)%rp;  
        y=((LL)y*rya+ryc)%rp;  
        a=min(x%n+1,y%n+1);  
        b=max(y%n+1,y%n+1);  
        Addedge(a,b,1e8-100*a);  
    }  
    for (int i=T+1;i<=m;i++)  
        scanf("%d%d%d",&x,&y,&z),Addedge(x,y,z);  
    dijkstra();  
    return 0;  
} 