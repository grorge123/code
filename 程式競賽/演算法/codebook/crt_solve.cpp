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
ll a[10],n[10],k,k2;
int cs;
vector<PLL> v[100];
int srt(PLL a,PLL b){
    return a.Y>b.Y;
}
PLL extgcd(ll a,ll b){
    if(b==0) return mp(1,0);
    ll p;
    PLL q;
    p = a/b;
    q = extgcd(b,a%b);
    return mp(q.Y,q.X-q.Y*p);
}
ll crt (){
    ll i,alln,mf,ans,mi,ci;
    PII f;
    alln = 1;
    ans = 0;
    for(i=0;i<k;i++) alln *= n[i];
    for(i=0;i<k;i++){
        mi = alln/n[i];
        mf = extgcd(mi,n[i]).X; // m[i]*mf % n[i] = 1
        ci = mi*(mf % n[i]); // m[i] * (mf % n[i])
        ans= ( (ans + (a[i]*ci))%alln + alln)%alln;
    }
    return (ans==0?alln:ans);
}
int chg(){
    ll f,mi,xa,xm;
    ll c;
    REP(i,k){
        f = n[i];
        // cout<<"n "<<i<<" = "<<n[i]<<endl;
        REP1(j,2,f+1){
            c = 0;
            mi = 1;
            // cout<<"f = "<<f<<endl;
            while(f%j == 0){
                f/=j;
                c++;
                mi*=j;
            }
            if(c){
                // cout<<"push "<<j<<": "<<a[i]<<' '<<a[i]%mi<<' '<<mi<<endl;
                v[j].pb(mp(a[i]%mi,mi));
            }
        }
    }
    // REP(i,100){
    //     if(LE(v[i])){
    //         cout<<i<<": "<<endl;
    //         REP(j,LE(v[i])) cout<<v[i][j].X<<' '<<v[i][j].Y<<endl;
    //     }
    // }
    k = 0;
    REP(i,100){
        if(LE(v[i])){
            sort(ALL(v[i]),srt);
            REP(j,LE(v[i])){
                xa = v[i][j].X;
                xm = v[i][j].Y;
                if(v[i][0].X % xm != xa % xm)
                    return 0;
            }
            a[k] = v[i][0].X;
            n[k] = v[i][0].Y;
            k++;
        }
    }
    return 1;
}
void read(){
    REP(i,100) v[i].clear();
    RI(k);
    REP(i,k) RI(n[i]);
    REP(i,k) RI(a[i]);
}
void solve(){
    cout<<"Case "<<cs<<": ";
    if(chg()) cout<<crt()<<endl;
    else cout<<-1<<endl;
}
int main(){
    int nn=1;
    nn=rit();
    init();
    cs = 1;
    while(nn--){
        // while(cin>>n) 
            read(),solve();
        cs++;
    }
    return 0;
}

