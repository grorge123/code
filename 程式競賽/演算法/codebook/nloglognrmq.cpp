#include <bits/stdc++.h>
#include "lib1965.h"
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define D double
#define ll uint64_t
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
// #define uint64_t ll
const int INF = 0x7F7F7F7F;
const double EPS = 1e-10 ;
const ll mod7 = 1e9+7;
const ll mod9 = 1e9+9;
using namespace std;
inline ll rit(){
    ll f=0;
    char c;
    do{
        c=getchar();
    }while(c<'0' || c>'9');
    do{
        f=f*10+c-'0';
        c=getchar();
    }while(c>='0' && c<='9');
    return f;
}
inline void fprt(D f){
    printf("%.08lf",f);
}
ll n,q,k,bn;
// ll a[Z];
// ll b[450000];
// int lg[Z];
// ll dp[5][Z],dp2[25][450000];

vector<ll> dp[5];
vector<int> dp2[20]; // a = n, dp = n*5 , dp2 = lg[n]*20
vector<char> lg; // lg = n
inline void sttt(int l,int r){
    dp2[0][bn] = l;
    REP2(i,l,r){
        if(dp[0][i] > dp[0][dp2[0][bn]]) dp2[0][bn] = i;
    }
    REP2(j,1,4) {
        REP2(i,l,r){
            if(i+(1<<(j-1)) >= n) {
                dp[j][i] = dp[j-1][i];
            }
            else{
                dp[j][i] = max(dp[j-1][i],dp[j-1][i+(1<<(j-1))]);
            }
        }
    }
    bn++;
}
inline void do_st(){
    k = lg[n];
    for(int l=0;l<n;l+=k){
        sttt(l,min(n,l+k-1));
    }
    REP2(j,1,lg[bn]){
        REP(i,bn){
            if(i+(1<<(j-1)) >= bn){
                dp2[j][i] = dp2[j-1][i];
            }
            else{
                if(dp[0][dp2[j-1][i]] > dp[0][dp2[j-1][i+(1<<(j-1))]]) {
                    dp2[j][i] = dp2[j-1][i];
                }
                else dp2[j][i] = dp2[j-1][i+(1<<j-1)];
            }
        }
    }
}
inline ll ask3(int l,int r){
    int f = lg[r-l];
    return max(dp[0][dp2[f][l]],dp[0][dp2[f][r-(1<<f)+1]]);
}
inline ll ask2(int l,int r){
    int f = lg[r-l];
    return max(dp[f][l],dp[f][r-(1<<f)+1]);
}
inline uint64_t RMQ(int l,int r){
    int d,e;
    r--;
    d = l/k;
    e = r/k;
    if(d+1<e){
        return max(ask2(l,d*k+k-1),max(ask2(e*k,r),ask3(d+1,e-1)));
    }
    else if(d<e){
        return max(ask2(l,d*k+k-1),ask2(e*k,r));
    }
    else return ask2(l,r);
}
void init(int _n,uint64_t c[]){
    n = _n;
    /*
    vector<ll> a,b,dp[5],dp2[25];
    vector<int> lg;
    */
    lg.resize(n+2);
    lg[1] = 0;
    REP2(i,2,n+1) lg[i] = lg[i>>1]+1;
    REP(i,5) dp[i].resize(n+1);
    REP(i,20) dp2[i].resize(n/lg[n]+1);
    bn = 0;
    REP(i,n) dp[0][i] = c[i];
    do_st();
}
// uint64_t fa[Z];
// void read(){
//     RI(n);
//     REP(i,n) RI(fa[i]);
//     init(n,fa);
// }
// void solve(){
//     int l,r;
//     RI(q);
//     REP(i,q){
//         RII(l,r);
//         l--;
//         r--;
//         if(l>r) swap(l,r);
//         printf("%llu\n",RMQ(l,r));
//     }
// }
// int main(){
//     int nn=1;
//     // nn=rit();
//     // lg[1] = 0;
//     // REP1(i,2,Z) lg[i] = lg[i>>1]+1;
//     while(nn--){
//         // while(cin>>n) 
//             // init();
//             read();
//             solve();
//     }
//     return 0;
// }