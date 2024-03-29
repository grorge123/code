//https://www.cnblogs.com/cuimama/p/9446570.html
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define IOS ios::sync_with_stdio();cin.tie(0)
#define endl '\n'
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pil pair<int,LL>
#define LL long long int
const LL INF = LLONG_MAX;
const int MAX = 1005;
struct line{
    int a,b;
    LL c;
    bool match=0;
    bool operator < (const line & ano) const {
        return c<ano.c;
    }
};
int f[MAX*MAX],dep[MAX*MAX],pos[MAX],fa[MAX],nopa[MAX];
vector<pair<int,LL> > ve[MAX];
line s[MAX*MAX];
int fifa(int a){
   if(fa[a]==a)return a;
   return a=fifa(fa[a]);
}
void DFS(int id,int deep,int *now,int pa){
    f[*now]=id;dep[*now]=deep;
    if(pos[id]==0)pos[id]=*now;
    for(int i=0;i<ve[id].size();i++){
        if(pos[ve[id][i].F]==0){
            (*now)++;
            nopa[ve[id][i].F]=id;
            DFS(ve[id][i].F,deep+1,now,id);
            (*now)++;
            f[*now]=id;dep[*now]=deep;
        }
    }
    return;
}
LL lca(int a,int b){
    int l=pos[a],r=pos[b];
    if(l>r)swap(l,r);
    int anc=INT_MAX,mindep=INT_MAX;
    LL ret=0;
    for(int i=l;i<=r;i++){
        if(dep[i]<mindep){
            mindep=dep[i];
            anc=f[i];
        }
    }
    int now=a;
    while(now!=anc){
        for(int i=0;i<ve[now].size();i++){
            if(ve[now][i].F==nopa[now]){
                ret=max(ret,ve[now][i].S);
                now=ve[now][i].F;
                break;
            }
        }
    }
    now=b;
    while(now!=anc){
        for(int i=0;i<ve[now].size();i++){
            if(ve[now][i].F==nopa[now]){
                ret=max(ret,ve[now][i].S);
                now=ve[now][i].F;
                break;
            }
        }
    }
    return ret;
}
int main(){
    int n,m;
    cin >> n>>m;
    for(int i=0;i<m;i++){
        cin >> s[i].a >> s[i].b>> s[i].c;
        if(s[i].a==s[i].b){
            i--;m--;
        }
    }
    sort(s,s+m);
    for(int i=0;i<=n;i++){
        fa[i]=i;
    }
    LL ans=0;
    int cnt=n;
    for(int i=0;i<m;i++){
        if(fifa(s[i].a)!=fifa(s[i].b)){
            fa[fifa(s[i].a)]=fifa(s[i].b);
            ans+=s[i].c;
            cnt--;
            s[i].match=1;
            ve[s[i].a].push_back(pil(s[i].b,s[i].c));
            ve[s[i].b].push_back(pil(s[i].a,s[i].c));
        }
    }
    if(cnt>1)ans=-1;
    cout <<ans <<' ';
    int now=1;
    DFS(1,1,&now,0);
    LL ans2=INF;
    for(int i=0;i<m;i++){
        if(s[i].match)continue;
        ans2=min(ans2,ans-lca(s[i].a,s[i].b)+s[i].c);
    }
    if(ans2==ans||ans2==INF){
        cout << -1<<endl;
    }else{
        cout << ans2<<endl;
    }
    return 0;
}
