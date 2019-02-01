#include <math.h>
#include <utility>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
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
PII p[Z];
vector<PII> t;
inline PII operator-(const PII &a,const PII &b){ // POINT 減法
    return mp(a.X - b.X, a.Y-b.Y);
}
inline int operator^(const PII &a,const PII &b){ // cross 叉積
    return a.X * b.Y - a.Y * b.X;
}
inline int dis(PII &a,PII &b){ //算距離
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}
void read(){
    RI(n); //輸入
    REP(i,n){
        RII(p[i].X,p[i].Y);
    }
    sort(p,p+n); //排序
}
void solve(){
    int sz,fsz,op;
    int ans ;
    // 凸包
    sz = 0;
    REP(i,n){
        while(sz>1 && ((t[sz-1]-t[sz-2]) ^ (p[i]-t[sz-2]))<=0 ){
            t.pop_back();
            sz--;
        }
        sz++;
        t.pb(p[i]);
    }
    fsz = sz;
    RREP(i,n){
        while(sz > fsz && ((t[sz-1]-t[sz-2]) ^ (p[i]-t[sz-2]))<=0 ){
            t.pop_back();
            sz--;
        }
        sz++;
        t.pb(p[i]);
    }
    //凸包

    //卡尺
    op = 1;
    ans = dis(t[0],t[1]);
    REP(i,LE(t)-1){
        while( ((t[i+1] - t[i]) ^ (t[i+1] - t[op+1])) < ( (t[i+1] - t[i]) ^ (t[i+1] - t[op]) ) ){
            op = (op+1) % (LE(t)-1);
        }
        ans = max(ans,max(dis(t[i],t[op]),dis(t[i+1],t[op])));
    }

    //印答案
    cout<<ans<<endl;
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