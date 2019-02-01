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
const D INF = 1e9;
const double EPS = 1e-8 ;
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
const int Z = 105;
PII tree[Z],ant[Z];
D w[Z][Z];
D lx[Z],ly[Z],tarsh[Z];
int Left[Z],vsx[Z],vsy[Z];
int n;
int match(int i){
    vsx[i] = 1;
    REP2(j,1,n){
        if(vsy[j]) continue;
        if(fabs(-w[i][j] + lx[i] + ly[j]) <= EPS){
            vsy[j] = 1;
            if(Left[j] == 0 || match(Left[j])){
                Left[j] = i;
                return 1;
            }
        }
        else tarsh[j] = min(tarsh[j],lx[i] + ly[j] - w[i][j] );
    }
    return 0;
}
inline void update(){
    D a;
    a = INF;
    REP2(i,1,n) if(!vsy[i]) a = min(tarsh[i],a);
    REP2(i,1,n){
        if(vsx[i]) lx[i] -= a;
        if(vsy[i]) ly[i] += a;
        else tarsh[i] -= a;
    }
}
inline D dis(PII a,PII b){
    return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}
void read(){
    REP2(i,1,n){
        RII(ant[i].X,ant[i].Y);
    }
    REP2(j,1,n){
        RII(tree[j].X,tree[j].Y);
    }
    REP2(i,1,n) swap(ant[i],tree[i]);
    REP2(i,1,n)
        REP2(j,1,n) w[i][j] = -dis(ant[i],tree[j]);


}
void solve(){
    REP2(i,1,n){
        lx[i]  = -INF;
        ly[i] = 0;
        Left[i] = 0;
        REP2(j,1,n) lx[i] = max(lx[i],w[i][j]);   
    }
    REP2(i,1,n){
        REP2(j,1,n) tarsh[j] = INF;
        while(1){
            REP2(j,1,n) vsx[j] = vsy[j] = 0;
            if(match(i)) break;
            else update();
        }
    }
    REP2(i,1,n) printf("%d\n",Left[i]);
}
int main(){
    int nn=1,key=0;
    // nn=rit();
    while(nn--){
        while(scanf("%d",&n) == 1) {
            if(key) printf("\n");
            key = 1;
            init(),read(),solve();
        }
    }
    return 0;
}