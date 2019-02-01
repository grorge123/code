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
const int Z = 505;
int n;
int w[Z][Z],lx[Z],ly[Z],slack[Z],lft[Z],vsx[Z],vsy[Z];
int match(int i){
    vsx[i] = 1;
    REP2(j,1,n){
        if(vsy[j]) continue;
        if(lx[i] + ly[j] == w[i][j]){
            vsy[j] = 1;
            if(!lft[j] || match(lft[j])){
                lft[j] = i;
                return 1;
            }
        }
        else{
            slack[j] = min(slack[j],lx[i]+ly[j] - w[i][j]);
        }
    }
    return 0;
}
void update(){
    int a = INF;
    REP2(i,1,n){
        if(vsy[i]) a = min(a,slack[i]);
    }
    REP2(i,1,n){
        if(vsx[i]) lx[i]-=a;
        if(vsy[i]) ly[i]+=a;
    }
}
void read(){
    REP2(i,1,n){
        REP2(j,1,n){
            RI(w[i][j]);
        }
    }
}
void solve(){
    int sum;
    REP2(i,1,n){
        slack[i] = INF;
        lx[i] = ly[i] = lft[i] = 0;
        REP2(j,1,n) lx[i] = max(lx[i],w[i][j]);
    }
    REP2(i,1,n){
        REP2(j,1,n) vsx[i] = vsy[i] = 0;
        while(1){
            if(match(i)) break;
            else update();
        }
    }
    sum = 0;
    REP2(i,1,n){
        if(i>1) printf(" ");
        printf("%d",lx[i]);
        // cout<<lx[i]<<' ';
        sum+=lx[i];
    }
    puts("");
    REP2(i,1,n){
        if(i>1) printf(" ");
        printf("%d",ly[i]);
        // cout<<ly[i]<<' ';
        sum+=ly[i];
    }
    puts("");
    printf("%d\n",sum);
}
int main(){
    int nn=1;
    // nn=rit();
    while(nn--){
        while(cin>>n) 
            init(),read(),solve();
    }
    return 0;
}


