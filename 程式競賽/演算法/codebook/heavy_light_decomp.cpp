#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define D double
#define ll long long
#define REP(i,a) for(int i=0;i<a;i++)
#define REP1(i,a,b) for(int i=a;i<b;i++)
#define REP2(i,a,b) for(int i=a;i<=b;i++)
#define RREP(i,a) for(int i=a-1;i>=0;i--)
#define RREP1(i,a,b) for(int i=a;i>b;i--)
#define RREP2(i,a,b) for(int i=a;i>=b;i--)
#define SREP(i,x) for(i=x.begin();i!=x.end();i++)
#define MS0(x) memset((x),0,sizeof((x)));
#define MS1(x) memset((x),-1,sizeof((x)));
#define MSF(x) memset((x),127,sizeof(x));
#define pb push_back
#define LE(x) (int)((x).size())
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<D,D>
#define im guagua
#define RI(x) x=rit();
#define RII(a,b) a=rit(),b=rit();
#define RIII(a,b,c) a=rit(),b=rit(),c=rit();
#define debug 0
const int INF = 0x7F7F7F7F;
const double EPS = 1e-10 ;
const ll mod7 = 1e9+7;
const ll mod9 = 1e9+9;
using namespace std;
inline ll rit(){
    ll f=0,key=1;
    char c;
    do{
        c=getchar();
        if(c=='-') key=-1;
    }while(c<'0' || c>'9');
    do{
        f=f*10+c-'0';
        c=getchar();
    }while(c>='0' && c<='9');
    return f*key;
}
inline void fprt(D f){
    printf("%.08lf",f);
}
void init(){
}
const int Z = 200505;
int n,m,cnt;
int size[Z],head[Z],son[Z],dep[Z],fa[20][Z],tid[Z],tdi[Z],tl[Z],tr[Z],val[Z];
vector<int> v[Z];
void dfs1(int p,int last,int d){
    int f;
    fa[0][p] = last;
    dep[p] = d;
    size[p] = 1;
    REP(i,LE(v[p])){
        f = v[p][i];
        if(f==fa[0][p]) continue;
        dfs1(f,p,d+1);
        size[p]+=size[f];
        if(son[p]==-1 || size[f]>size[son[p]]){
            son[p] = f;
        }
    }
}
void dfs2(int p,int tp){
    int f;
    head[p] = tp;
    tid[p] = tl[p] = tr[p] = cnt++;
    tdi[tid[p]] = p;
    if(son[p]==-1) return;
    dfs2(son[p],tp);
    REP(i,LE(v[p])){
        f = v[p][i];
        if(f==fa[0][p] || f==son[p]) continue;
        dfs2(f,f);
        tr[p] = tr[f];
    }
}
void beizeng(){
    REP1(i,1,20){
        REP2(j,1,n)
            fa[i][j] = fa[i-1][fa[i-1][j]];
    }
}
inline int lca(int a,int b){
    int del,i,f;
    if(a==b) return a;
    if(dep[a] > dep[b]) swap(a,b);
    del = dep[b] - dep[a];
    i = 19;
    f = 1<<19;
    while(f){
        if(f&del) b = fa[i][b];            
        i--;
        f>>=1;
    }
    if(a==b) return a;
    RREP(i,20){
        if(fa[i][a] != fa[i][b]){
            a = fa[i][a];
            b = fa[i][b];
        }
    }
    return fa[0][a];
}
int tree[4*Z];
void build(int p,int l,int r){
    int mid = (l+r)/2;
    if(l==r){
        tree[p] = val[tdi[l]];
        return ;
    }
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p] = max(tree[p*2],tree[p*2+1]);
}
void modify(int p,int l,int r,int x,int vl){
    int mid = (l+r)/2;
    if(l==r){
        val[tdi[l]] = tree[p] = vl;
        return ;
    }
    if(x<=mid) modify(p*2,l,mid,x,vl);
    else modify(p*2+1,mid+1,r,x,vl);
    tree[p] = max(tree[p*2],tree[p*2+1]);
}
int query(int p,int l,int r,int ql,int qr){
    int mid = (l+r)/2;
    if(l==ql && r==qr)
        return tree[p];
    if(qr<=mid) return query(p*2,l,mid,ql,qr);
    if(ql>mid) return query(p*2+1,mid+1,r,ql,qr);
    return max(query(p*2,l,mid,ql,mid),query(p*2+1,mid+1,r,mid+1,qr));
}

void read(){
    int a,b,f;
    RI(n);
    REP(i,n*2+1){
        v[i].clear();
        val[i] = 0;
    }
    REP2(i,1,n-1){
        RIII(a,b,f);
        v[a].pb(n+i);
        v[b].pb(n+i);
        v[n+i].pb(a);
        v[n+i].pb(b);
        val[n+i] = f;
    }
}
inline int ask(int a,int b){
    int ans = 0 ;
    while(head[a] != head[b]){
        if(dep[head[a]]>dep[head[b]]) swap(a,b);
        ans = max(ans,query(1,0,cnt,tid[head[b]],tid[b]));
        b = fa[0][head[b]];
    }
    if(dep[a] > dep[b]) swap(a,b);
    ans = max(ans,query(1,0,cnt,tid[a],tid[b]));
    return ans;
}
void solve(){
    string s;
    int a,b;
    MS1(son);
    cnt = 0;
    dfs1(1,1,1);
    dfs2(1,1);
    beizeng();
    cnt--;
    build(1,0,cnt);
    while(cin>>s && s!="DONE"){
        RII(a,b);
        if(s=="QUERY"){
            cout<<ask(a,b)<<endl;
        }
        else{
            modify(1,0,cnt,tid[a+n],b);
        }
    }
}
int main(){
    int nn=1;
    nn=rit();
    init();
    while(nn--){
        // while(cin>>n) 
            read(),solve();
    }
    return 0;
}
