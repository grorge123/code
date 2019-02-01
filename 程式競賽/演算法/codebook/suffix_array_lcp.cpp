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
#define SREP(i,x) for(auto i=x.begin();i!=x.end();i++)
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
const int Z = 10005;
string s,sb;
int Rank[Z],sa[Z],tmp[Z],lcp[Z],k,n;
int srt_sa(int a,int b){
    if(Rank[a] != Rank[b]) return Rank[a] < Rank[b];
    int fa,fb;
    fa = (a+k <= n? Rank[a+k]:-1);
    fb = (b+k <= n? Rank[b+k]:-1);
    if(fa==fb) return a>b;
    return fa<fb;
}

int srt_sa2(int a,int b){
    if(Rank[a] != Rank[b]) return Rank[a] < Rank[b];
    int fa,fb;
    fa = (a+k <= n? Rank[a+k]:-1);
    fb = (b+k <= n? Rank[b+k]:-1);
    return fa<fb;
}
void build_SA(){
    n = LE(s);
    REP(i,n){
        sa[i] = i;
        Rank[i] = s[i];
    }
    for(k=1;k<=n;k<<=1){
        sort(sa,sa+n,srt_sa);
        tmp[sa[0]] = 0;
        REP1(i,1,n){
            tmp[sa[i]] = tmp[sa[i-1]] + (srt_sa2(sa[i-1],sa[i])?1:0);
        }
        REP(i,n+1) Rank[i] = tmp[i];
    }
}
void build_LCP(){
    int h = 0,f;
    REP(i,n) Rank[sa[i]] = i;
    REP(i,n){
        if(Rank[i]==0){
            // lcp[Rank[i]] = 0;
            continue;
        }
        if(h) --h;
        f = sa[Rank[i]-1];
        for(;f+h<n && i+h<n;h++){
            if(s[i+h] != s[f+h]) break;
        }
        lcp[Rank[i]] = h;
    }
}
void read(){
    getline(cin,s);
    // getline(cin,sb);
}
void solve(){
    // s += "\0";
    // s += sb;
    build_SA();
    cout<<"sa : ";
    REP(i,n) cout<<sa[i]<<' ';
    cout<<endl;
    // cout<<"rank : ";
    // REP(i,n+1) cout<<Rank[i]<<' ';
    cout<<endl;
    build_LCP();
    REP(i,n){
        REP1(j,sa[i],n) cout<<s[j];
        cout<<endl;
    }
    cout<<"lcp : ";
    REP(i,n) cout<<lcp[i]<<' ';
    cout<<endl;
}
int main(){
    int nn=1;
    nn=rit();
    // getline(cin,sa);
    while(nn--){
        // while(cin>>n) 
            init(),read(),solve();
    }
    return 0;
}