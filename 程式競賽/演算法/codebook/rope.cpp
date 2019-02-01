#include <bits/stdc++.h>
#include <ext/rope>
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
#define RP replace
const int INF = 0x7F7F7F7F;
const double EPS = 1e-10 ;
const ll mod7 = 1e9+7;
const ll mod9 = 1e9+9;
using namespace std;
using namespace __gnu_cxx;
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
PII a[Z*4];
struct node{
    int l,r,m,size;
    node(){
        l = r = m = size =0;
    }
    node(int a,int b,int c,int d){
        l = a;
        r = b;
        m = c;
        size = d;
    }
}tree[8*Z];
int k;
rope<node> *rp[Z];
inline node merge(node a,node b){
    node f;
    f.m = max(a.m,b.m);
    if(a.l==a.size) f.l = a.l+b.l;
    else f.l = a.l;
    if(b.r==b.size) f.r = b.r+a.r;
    else f.r = a.r;

    f.size = a.size + b.size;

    f.m = max(f.m,max(f.l,f.r));
    f.m = max(f.m,a.r+b.l);
    return f;
}
inline void pull(int ii,int p,int l,int r){
    rp[ii] -> RP(p,merge(rp[ii]->at(p*2),rp[ii]->at(p*2+1)));
}
void add(int ii,int p,int l,int r,int x){
    int mid = (l+r)/2;
    if(l==r){
        node f={1,1,1,1};
        rp[ii]->RP(p,f);  
        return ; 
    }
    if(x<=mid) add(ii,p*2,l,mid,x);
    else add(ii,p*2+1,mid+1,r,x);
    pull(ii,p,l,r);
}
node query(int ii,int p,int l,int r,int ql,int qr){
    int mid = (l+r)>>1;
    if(l==ql && r==qr){
        return rp[ii]->at(p);
    }
    if(qr<=mid){
        return query(ii,p*2,l,mid,ql,qr);
    }
    else if(ql>mid){
        return query(ii,p*2+1,mid+1,r,ql,qr);
    }
    else{
        return merge(query(ii,p*2,l,mid,ql,mid),query(ii,p*2+1,mid+1,r,mid+1,qr));
    }
}
void read(){
    RI(n);
    REP2(i,1,n){
        RI(a[i].X);
        a[i].Y = i;
    }
}
void solve(){
    int l,r,w,p,q;
    sort(a+1,a+n+1,greater<PII>());
    rp[0] = new rope<node> (tree,tree+4*Z);
    REP2(i,1,n){
        if(i%1000==0)cout<<"hi "<<i<<endl;
        rp[i] = new rope<node> (*rp[i-1]);
        add(i,1,1,n,a[i].Y);
    }
    RI(k);
    // cout<<"k = "<<k<<endl;
    REP(i,k){
        // cout<<"I = "<<i<<endl;
        RIII(l,r,w);
        p = 0,q = n;
        while(q-p>1){
            int mid = (p+q)/2;
            if(query(mid,1,1,n,l,r).m>=w){
                q = mid;
            }
            else p = mid;
        }
        if(query(p,1,1,n,l,r).m>=w) cout<<a[p].X<<endl;
        else if(query(q,1,1,n,l,r).m>=w) cout<<a[q].X<<endl;
        else cout<<-1<<endl;
    }
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