#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define D double
#define ll long long
#define REP(i,a) for(int i=0;i<a;++i)
#define REP1(i,a,b) for(int i=a;i<b;++i)
#define REP2(i,a,b) for(int i=a;i<=b;++i)
#define RREP(i,a) for(int i=a-1;i>=0;--i)
#define RREP1(i,a,b) for(int i=a;i>b;--i)
#define RREP2(i,a,b) for(int i=a;i>=b;--i)
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
const int Z = 100005;
int n;
PDD p[Z];
vector<PDD> vl;
vector<PDD> tmpl,tmpr;
D dis(PDD a,PDD b){
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y-b.Y);
}
inline int srt(PDD a,PDD b){
    return a.Y<b.Y;
}
D ask(int l,int r){
    if(l==r){
        return 40000ll*40000ll*40000ll;
    }
    int mid = (l+r)>>1;
    D q,midx;
    q = min(ask(l,mid),ask(mid+1,r));
    
    tmpl.clear();
    tmpr.clear();
    REP2(i,l,mid) {
        tmpl.pb(p[i]);
    }
    REP2(i,mid+1,r){
        tmpr.pb(p[i]);
    }
    sort(ALL(tmpl),srt);
    sort(ALL(tmpr),srt);

    midx = p[mid].X;

    vl.clear();
    SREP(f,tmpl){
        if(midx - f.X < q){
            vl.pb(f);
        }
    }
    int u=0;
    SREP(f,tmpr){
        if(f.X - midx < q){
            while(u<LE(vl) && f.Y - vl[u].Y > q) u++;
            for(int j=0;u+j<LE(vl);j++){
                if(vl[u+j].Y - f.Y > q) break;
                q = min(q,dis(vl[u+j],f));
            }
        }
    }
    // cout<<"ask "<<l<<' '<<r<<" = "<<q<<endl;
    return q;
}
void read(){
    REP(i,n){
        cin>>p[i].X>>p[i].Y;
    }
    sort(p,p+n);
}
void solve(){
    D ans = ask(0,n-1);
    // cout<<"ans = "<<ans<<endl;
    if(ans >= 100000000.0) printf("INFINITY\n");
    else printf("%.04f\n",sqrt((D)(ans)+EPS) );
}
int main(){
    int nn=1;
    // nn=rit();
    while(nn--){
        while(cin>>n && n!=0) 
            init(),read(),solve();
    }
    return 0;
}