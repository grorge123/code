#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
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
#define SREP(i,x) for(i=x.begin();i!=x.end();i++)
#define MS0(x) memset((x),0,sizeof((x)));
#define MS1(x) memset((x),-1,sizeof((x)));
#define MSF(x) memset((x),127,sizeof(x));
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
const int Z = 100005;
int n,m,st,ed,ans[Z];
struct cmp{
    bool operator()(const int &a,const int &b){
        return ans[a]>ans[b];
    }
};
typedef __gnu_pbds::priority_queue<int,cmp,__gnu_pbds::pairing_heap_tag> heap;   /*****/  
heap::point_iterator id[Z];
vector<PII> v[Z];
void read(){
    int a,b,f;
    RII(n,m);
    RII(st,ed);
    REP(i,m){
        RIII(a,b,f);
        v[a].pb(mp(b,f));
        v[b].pb(mp(a,f));
    }
}
void solve(){
    int now,tar,len;
    heap q;
    MSF(ans);
    ans[st] = 0;
    id[st] = q.push(st);
    while(!q.empty()){
        now = q.top();
        // cout<<"now = "<<now<<endl;
        q.pop();
        REP(i,LE(v[now])){
            tar = v[now][i].X;
            len = v[now][i].Y;
            // cout<<"tar len = "<<tar<<' '<<len<<' '<<ans[now]+len<<endl;
            if(ans[tar]>ans[now]+len){
                ans[tar] = ans[now]+len;
                if(id[tar]!=0) q.modify(id[tar],tar);
                else id[tar] = q.push(tar);
            }
        }
    }
    cout<<ans[ed]<<endl;
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