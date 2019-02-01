#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define ALL(x) x.begin(),x.end()
#define D double
#define ll long long
#define REP(i,a) for(int i=0;i<a;i++)
#define REP1(i,a,b) for(int i=a;i<b;i++)
#define REP2(i,a,b) for(int i=a;i<=b;i++)
#define RREP(i,a) for(int i=a-1;i>=0;i--)
#define RREP1(i,a,b) for(int i=a;i>b;i--)
#define RREP2(i,a,b) for(int i=a;i>=b;i--)
#define MS0(x) memset((x),0,sizeof((x)));
#define MS1(x) memset((x),-1,sizeof((x)));
#define MSF(x) memset((x),127,sizeof(x));
#define pb push_back
#define LE(x) (int)((x).length())
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
const ll mod7 = 10007;
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
inline int mul(int a,int b){
    return (a*b)%mod7;
}
inline int add(int a,int b){
    return (a+b)%mod7;
}
void mat_mul(int ans[3][3],int a[3][3],int b[3][3]){
    int c[3][3];
    MS0(c);
    REP(i,3) REP(j,3) REP(k,3)
        c[i][j] = add(c[i][j],mul(a[i][k],b[k][j]));

    REP(i,3) REP(j,3)
        ans[i][j] = c[i][j];
}
void mat_mul2(int ans[3],int a[3],int b[3][3]){
    int c[3];
    MS0(c);
    REP(i,3) REP(j,3)
        c[i] = add(c[i],mul(a[j],b[i][j]));
    REP(i,3) ans[i] = c[i];
}
int mei[32][3][3];
void init(){
    mei[0][0][1] = mei[0][1][2] = mei[0][2][0] = mei[0][2][1] = mei[0][2][2] = 1;
    REP1(i,1,32){
        mat_mul(mei[i],mei[i-1],mei[i-1]);
    }
}
int n;
int a[3];
void read(){
    n = rit()-1;
    a[0] = a[1] = a[2] = 1;
}
void solve(){
    int i=0;
    while(n){
        if(n%2) mat_mul2(a,a,mei[i]);
        n>>=1;
        i++;
    }
    cout<<a[0]<<endl;
}
int main(){
    int nn=1;
    // nn=rit();
    init();
    while(nn--){
        read();
        solve();
    }
    return 0;
}