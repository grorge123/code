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
const int Z = 13;
int n,m;
int mk[Z][Z],rr;
ll dp[Z][Z][1<<Z];
void read(){
    RII(n,m);
    REP2(i,1,n) REP2(j,1,m) RI(mk[i][j]);

}
void solve(){
    int x,y;
    MS0(dp);
    dp[0][m][0] = 1;
    REP2(i,1,n){
        REP(j,1<<(Z-1)) dp[i][0][(j<<1)] = dp[i-1][m][j];
        REP2(j,1,m){
            x = 1<<(j-1);
            y = 1<<j;
            REP(k,1<<Z){
                if(mk[i][j]){
                    if((k&x) && (k&y)){
                        dp[i][j][k] = dp[i][j-1][k-x-y];
                    }
                    else if((!(k&x)) && (!(k&y))){
                        dp[i][j][k] = dp[i][j-1][k+x+y];
                    }
                    else{
                        dp[i][j][k] = (dp[i][j-1][k]+dp[i][j-1][k^x^y]);
                    }
                }
                else{
                    if( (!(k&x)) && (!(k&y))){
                        dp[i][j][k] = dp[i][j-1][k];
                    }
                    else dp[i][j][k] = 0;
                }
            }
        }
    }
    rr++;
    cout<<"Case "<<rr<<": "<<dp[n][m][0]%mod7<<endl;
}
int main(){
    int nn=1;
    nn=rit();
    while(nn--){
        // while(cin>>n) 
            init(),read(),solve();
    }
    return 0;
}



