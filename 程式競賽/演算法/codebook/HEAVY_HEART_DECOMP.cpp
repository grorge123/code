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
#define RI(x) x=rit()
#define RII(a,b) a=rit(),b=rit()
#define RIII(a,b,c) a=rit(),b=rit(),c=rit()
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
#define PIL pair<int,ll>
void init(){
}
const int Z = 100005;
int n,m,k,tn,ttt;
vector<PIL > v[Z];
vector<int> v2[Z]; // v2 is for new graph <333
int size[Z],fa[Z],tfa[Z],rt; // fa is for new graph <333;
int dmk[Z],tag[Z],zdep[Z];
int tofac[Z];
ll tofas[Z],fadis[Z][20],dep[Z];
void dfs1(int p,int pre,ll dd,int zd){
    int f;
    // cout<<"dfs1 "<<p<<' '<<pre<<endl;
    tn++;
    size[p] = 1;
    tag[p] = ttt;
    dep[p] = dd;
    tfa[p] = pre;
    // ddmp[mp(p,last)] = dep[p];
    fadis[p][zd] = dep[p];
    REP(i,LE(v[p])){
        f = v[p][i].X;
        if(f==pre || dmk[f]==1) continue;
        dfs1(f,p,dd+v[p][i].Y,zd);
        size[p] += size[f];
    }
    // cout<<"size "<<p<<" = "<<size[p]<<endl;
}
inline int mv(int &p){
    int f;
    // cout<<"mv "<<p<<" -> ";
    REP(i,LE(v[p])){
        f = v[p][i].X;
        if(dmk[f]==1 || tag[f] != ttt) continue;
        else if(f==tfa[p]){
            // cout<<f<<" anc "<<tn-size[p]<<endl;
            if((tn-size[p])>tn/2){
                // cout<<f<<" dadada "<<endl;
                // cout<<f<<' '<<size[f]<<" ( "<<tn<<" - "<<size[p]<<" )"<<endl;
                p = f;
                return 1;
            }
        }
        else if(size[f] > tn/2){
            // cout<<f<<" dada "<<size[f]<<endl;
            p = f;
            // cout<<p<<' '<<size[p]<<endl;
            return 1;
        }
    }
    // cout<<p<<' '<<size[p]<<endl;
    return 0;
}
void dfs2(int st,int pre,ll dd,int d2){
    int nowc,f;
    int ftt;
    // cout<<"dfs2 "<<st<<' '<<pre<<endl;
    ttt++;
    ftt = ttt;
    tn = 0;
    dfs1(st,pre,dd,d2-1);
    nowc = st;
    while(mv(nowc)){ }
    fa[nowc] = pre;
    // fadis[nowc] = dep[nowc];
    dmk[nowc] = 1;
    zdep[nowc] = d2;
    // cout<<"v2 "<<pre<<" pb "<<nowc<<endl;
    if(pre!=-1) v2[pre].pb(nowc);
    else rt = nowc;
    REP(i,LE(v[nowc])){
        f = v[nowc][i].X;
        // cout<<"a edge between "<<nowc<<" and "<<f<<endl;
        if( dmk[f] == 1 || tag[f] != ftt) continue;
        dfs2(f,nowc,v[nowc][i].Y,d2+1);
    }
    // cout<<"byebye2 "<<st<<' '<<pre<<endl;
}
void build_centroid(){
    // MS1(fa);
    dfs2(1,-1,0,1);
}
int cnt[Z];
ll sum[Z];
inline void add(int p,int h){
    int f;
    cnt[p]+=h;
    // tofac[p]++;
    f = p;
    while(f!=-1){
        // dis+=fadis[p];
        if(fa[f]!=-1){
            tofac[f]+=h;
            tofas[f]+=h*fadis[p][zdep[fa[f]]];//  ddmp[mp(p,fa[f])];
            cnt[fa[f]]+=h;
            sum[fa[f]]+=h*fadis[p][zdep[fa[f]]]; //ddmp[mp(p,fa[f])];
        }
        f = fa[f];
        // cnt[f]++;
        // sum[f]+=ddmp[mp(p,f)];
        // cout<<"cnt sum p = "<<cnt[f]<<' '<<sum[f]<<" ( "<<f<<endl;
    }
}
inline ll ask(int p){
    ll tmp = sum[p];
    int f;
    f = p;
    while(f!=-1){
        // cout<<"tmp p "<<tmp<<' '<<f<<endl;
        if(fa[f]!=-1){
            tmp+=sum[fa[f]];
            tmp-=tofas[f];
            tmp+=(fadis[p][zdep[fa[f]]])*(cnt[fa[f]]-tofac[f]);
            // tmp+=(ddmp[mp(p,fa[f])]*(cnt[fa[f]]-cnt[f]))+(sum[fa[f]]-(sum[f]+ddmp[mp(f,fa[f])]*cnt[f]));
            // tmp+=(sum[fa[p]]+cnt[fa[p]]*(dis+fadis[p]))-tmp;
        }
        f = fa[f];
    }
    return tmp;
}
int yongguole[Z],tuanyuan[Z];
void read(){
    int a,b,f;
    RIII(n,m,k);
    REP2(i,0,max(n,m)) {
        v[i].clear();
        v2[i].clear();
        tofac[i] = tofas[i] = 0;
        sum[i] = cnt[i] = yongguole[i] = dmk[i] = tag[i] = 0;
        tuanyuan[i] = 1;
    }
    ttt = 1;
    REP(i,n-1){
        RIII(a,b,f);
        v[a].pb(mp(b,f));
        v[b].pb(mp(a,f));
    }
}
void solve(){
    int key,p,me;
    build_centroid();
    // REP(i,n){
    //     cout<<"v2 "<<i<<" : ";
    //     SREP(f,v2[i]) cout<<f<<' ';
    //     cout<<endl;
    // }
    me = 1;
    REP2(i,2,m){
        add(1,1);
    }
    REP(i,k){
        RII(key,p);
        if(key==1){
            me = p;
        }
        else{
            add(tuanyuan[key],-1);
            tuanyuan[key] = p;
            add(tuanyuan[key],1);
        }
        // if(key==1){
        //     if(yongguole[p]==0){
        //         add(p);
        //         yongguole[p] = 1;
        //     }
        // }
        // else{
        //     printf("%lld\n",ask(p));
        // }
        printf("%lld\n",ask(me));
    }
}
int main(){
    int nn=1;
    nn=rit();
    while(nn--){
        // while(scanf("%d%d",&n,&m)==2) 
            init(),read(),solve();
    }
    return 0;
}