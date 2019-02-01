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
const int Z = 400005;
char s[Z];
int sa[Z],x[Z],c[Z],y[Z];
int n;
void do_sa(){
    int p;
    n*=2;
    int m = 'z'+1;
    REP(i,m) c[i] = 0;
    REP(i,n) c[x[i] = s[i]]++;
    REP1(i,1,m) c[i]+=c[i-1];
    RREP(i,n) sa[--c[x[i]]] = i;
    for(int k=1;k<=n;k<<=1){
        p = 0;
        REP1(i,n-k,n) y[p++] = i;
        REP(i,n) if(sa[i] >= k) y[p++] = sa[i]-k;

        REP(i,m) c[i] = 0;
        REP(i,n) c[x[y[i]]]++;
        REP1(i,1,m) c[i]+=c[i-1];
        RREP(i,n) sa[--c[x[y[i]]]] = y[i];

        swap(x,y);
        x[sa[0]] = 0;
        p = 1;
        REP1(i,1,n){
            x[sa[i]] = (y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k]? p-1:p++);
        }
        m = p;
        if(p>=n) break;
    }
    // REP(i,n) cout<<sa[i]<<' ';
    // cout<<endl;
    n>>=1;
    REP(i,n) sa[i] = sa[i+n];
}
int lcp[Z],rk[Z];
void do_lcp(){
    int h;
    lcp[n] = 0;
    REP(i,n) rk[sa[i]] = i;
    h = 0;
    REP(i,n){
        if(rk[i]==0){
            lcp[rk[i]] = 0;
            continue;
        }
        int f = sa[rk[i]-1];
        if(h) h--;
        for(;i+h<n && f+h<n && s[i+h] == s[f+h];h++){
        }
        lcp[rk[i]] = h;
    }
    // REP(i,n) cout<<lcp[i]<<endl;
}
void read(){
    // MS0(y);
    // MS0(x);
    scanf(" %s",s);
    n = strlen(s);
    REP2(i,n,4*n) s[i] = 0;
}
void solve(){
    ll f,f2;
    ll ans;
    do_sa();
    do_lcp();
    ans = 0;
    REP(i,n){
        // sa[i] ~ n-1;
        f = (n-sa[i]);
        f2 = lcp[i+1]+1;
        // while(f>f2){
        //     ans+=f;
        //     f--;
        // }
        // f2+1 + ~ f
        ans+=((f2)+f)*(f-f2+1)/2;
    }
    printf("%lld\n",ans);
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