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
const int Z = 200005;
int n,m;
int a[Z],ans[Z];
int bt[Z];
inline void add(int x,int k){
    for(int i=x;i<Z;i+=(i&-i)){
        bt[i]+=k;
    }
}
inline int qry(int x){
    int sum;
    sum = 0;
    for(int i=x;i>0;i-=(i&-i)){
        sum+=bt[i];
    }
    return sum;
}
struct QQ{
    int type;
    int l,r,k; // or pos , value , quantitie
    int pos;
};
vector<QQ> v;
vector<int> vp;
inline QQ mq(int _t,int _l,int _r,int _k,int _p){
    QQ q;
    q.type = _t;
    q.l = _l;
    q.r = _r;
    q.k = _k;
    q.pos = _p;
    return q;
}
void query(int l,int r,vector<QQ> &v){
    // cout<<"query "<<l<<' '<<r<<" : "<<endl;
    if(l==r){
        SREP(f,v){
            if(f.type == 1) ans[f.pos] = l;
        }
        return ;
    }
    vector<QQ> lv,rv;
    int mid = (l+r)>>1,tmp;
    QQ q;
    SREP(f,v){
        // cout<<"( "<<(f.type?"query : ":"modify : ")<<' '<<f.l<<' '<<f.r<<' '<<f.k<<" ) "<<endl;
        if(f.type==1){
            tmp = qry(f.r) - qry(f.l-1);
            // cout<<"tmp = "<<tmp<<endl;
            if(tmp >= f.k){
                // cout<<"push l"<<endl;
                lv.pb(f);
            }
            else{
                q = f;
                q.k -= tmp;
                // cout<<"push r"<<endl;
                rv.pb(q);
            }
        }
        else{
            if(f.r<=mid){
                // cout<<"push l"<<endl;
                lv.pb(f);
                add(f.l,f.k);
            }
            else{ 
                // cout<<"push r"<<endl;
                rv.pb(f);
            }
        }
    }
    SREP(f,v){
        if(f.type==0) {
            if(f.r<=mid){
                add(f.l,-f.k);
            }
        }
    }
    // cout<<"lv : "<<endl;
    // SREP(f,lv){
    //     cout<<"( "<<(f.type?"query : ":"modify : ")<<' '<<f.l<<' '<<f.r<<' '<<f.k<<" ) "<<endl;
    // }
    // cout<<"rv : "<<endl;
    // SREP(f,rv){
    //     cout<<"( "<<(f.type?"query : ":"modify : ")<<' '<<f.l<<' '<<f.r<<' '<<f.k<<" ) "<<endl;
    // }
    if(!lv.empty()) query(l,mid,lv);
    if(!rv.empty()) query(mid+1,r,rv);
}
void read(){
    QQ q;
    int l,r,k;
    char c;
    RII(n,m);
    REP2(i,1,n){
        RI(a[i]);
        q = mq(0,i,a[i],1,0);
        v.pb(q);
        vp.pb(a[i]);
    }
    REP(i,m){
        scanf(" %c",&c);
        if(c=='Q'){
            RIII(l,r,k);
            v.pb(mq(1,l,r,k,i));
        }
        else{
            RII(l,k);
            v.pb( mq(0,l,a[l],-1,0) );
            v.pb( mq(0,l,k,1,0) );
            vp.pb(k);
            a[l] = k;
        }
    }
    sort(ALL(vp));
    vp.resize(unique(ALL(vp))-vp.begin());
    REP(i,LE(v)){
        // QQ f = v[i];
        if(v[i].type==0){
            v[i].r = (lower_bound(ALL(vp),v[i].r)-vp.begin())+1;
        }
    }
}
void solve(){
    query(1,LE(vp)+5,v);
    SREP(f,v){
        if(f.type==1){
            cout<<vp[ans[f.pos]-1]<<endl;
        }
    }
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
