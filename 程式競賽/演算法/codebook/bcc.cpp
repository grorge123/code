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
#define SREP(i,x) for(auto i:x)
#define MS0(x) memset((x),0,sizeof((x)))
#define MS1(x) memset((x),-1,sizeof((x)))
#define MSF(x) memset((x),127,sizeof(x))
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
const int Z = 400005;
int n,m;
vector<int> v[Z];
PII edge[Z];
int dfsn[Z],low[Z],r,fa[Z],nbcc,belong[Z];
stack<int> stk;
vector<int> bcc[Z];
map<PII,PII> ans;
inline int other(int i,int x){
    if(edge[x].X == i) return edge[x].Y;
    else return edge[x].X;
}
void dfs(int p){
    int tar ;
    dfsn[p] = low[p] = ++r;
    stk.push(p);
    SREP(i,v[p]){
        tar = other(p,i);
        if(dfsn[tar] == -1){
            fa[tar] = p;
            dfs(tar);
            low[p] = min(low[p],low[tar]);
//            cout<<"low "<<p<<" = "<<low[p]<<endl;
        }
        else if(tar!=fa[p]){
            low[p] = min(low[p],dfsn[tar]);
//            cout<<"low "<<p<<" = "<<low[p]<<endl;
        }
    }
    if(low[p] == dfsn[p]){
        while(1){
            int f = stk.top();
            stk.pop();
            bcc[nbcc].pb(f);
            belong[f] = nbcc;
            if(f==p) break;
        }
        nbcc++;
    }
}
void read(){
    RII(n,m);
    REP(i,m){
        RII(edge[i].X,edge[i].Y);
        v[edge[i].X].pb(i);
        v[edge[i].Y].pb(i);
    }
}
int dis[Z],num,emk[Z],tag[Z];
queue<int> q;
void dfs_bcc(int p){
    dis[p] = 0;
    for(;tag[p]<LE(v[p]);tag[p]++){
        int i = v[p][tag[p]];
        int f = other(p,i);
        if(belong[f] == num && emk[i]==0){
            emk[i] = 1;
//            cout<<p<<" -> "<<f<<endl;
            ans[ mp(min(p,f),max(p,f) ) ] = mp(p,f);
            dfs_bcc(f);
//            return ;
        }
    }
//    cout<<p<<" -> "<<bcc[num][0]<<endl;
//    ans[mp(min(bcc[num][0],p),max(bcc[num][0],p))] = mp(p,bcc[num][0]);
}
void solve(){
    int a,b;
    MS1(dfsn);
    fa[1] = 1;
    dfs(1);
    num = 0;
    REP(i,nbcc){
//        cout<<i<<": ";
//        SREP(j,bcc[i]){
//            cout<<j<<' ';
//        }
//        cout<<endl;
        if(LE(bcc[i]) > LE(bcc[num])){
            num = i;
        }
    }
//    cout<<"bcc num = ";
//    SREP(i,bcc[num]){
//        cout<<i<<' ';
//    }
//    cout<<endl;
    MSF(dis);
    dfs_bcc(bcc[num][0]);
    REP(i,LE(bcc[num])){
        a = bcc[num][i];
        dis[a] = 0;
        q.push(a);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        SREP(i,v[now]){
            int tar = other(now,i);
            if(dis[tar] > dis[now]+1){
                dis[tar] = dis[now]+1;
                ans[mp(min(now,tar),max(now,tar))] = mp(tar,now);
                q.push(tar);
            }
        }
    }
//    SREP(f,ans){
//        cout<<f.X.X<<' '<<f.X.Y<<" = "<<f.Y.X<<' '<<f.Y.Y<<endl;
//    }
    cout<<LE(bcc[num])<<endl;
    REP(i,m){
        PII f = ans[mp(min(edge[i].X,edge[i].Y),max(edge[i].X,edge[i].Y))];
        if(f.X==0 && f.Y==0) cout<<edge[i].X<<' '<<edge[i].Y<<endl;
        else cout<<f.X<<' '<<f.Y<<endl;
    }
}
int main(){
    int nn=1;
    // nn=rit();
    while(nn--){
        // while(cin>>n)
            init(),read(),solve();
    }
    return 0;
}