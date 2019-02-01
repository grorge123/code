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
void init(){
}
const int Z = 500005;
int rt[Z],val[Z];
int n,k;
int findroot(int x){
    if(x==rt[x]) return x;
    int f = rt[x];
    rt[x] = findroot(rt[x]);
    val[x] = (val[x]+val[f])%3;
    return rt[x];
}
void Union(int a,int b,int f){
    int fa,fb;
    fa = findroot(a);
    fb = findroot(b);
    rt[fb]= fa;
    val[fb] = (val[a]-val[b]+3+(f-1))%3;
}
void read(){
    REP2(i,1,n){
        rt[i] = i;
        val[i] = 0;
    }
}
void solve(){
    int key,a,b,ans;
    ans = 0;
    REP(i,k){
        RIII(key,a,b);
        if(a>n || b>n ){
            ans++;
            continue;
        }
        if(findroot(a) == findroot(b)){
            if(key==1 && val[a] != val[b]) ans++;
            if(key==2 && (val[a]+1)%3 != val[b]) ans++;
        }
        else Union(a,b,key);
    }
    cout<<ans<<endl;
}
int main(){
    int nn=1;
    // nn=rit();
    while(nn--){
        while(scanf("%d%d",&n,&k)==2)
            init(),read(),solve();
    }
    return 0;
}