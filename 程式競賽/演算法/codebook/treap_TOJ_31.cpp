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
unsigned ran(){
    static unsigned x=20150118;
    return x=x*0xdefaced+1;
}
struct treap{
    treap *l,*r;
    int rtag,sz,pri,vtag;
    int sum, la, ra, ma, val;
    treap(int _val){
        val = la = ra = ma = sum = _val;
        sz = 1;
        pri = ran();
        rtag =0 ;
        vtag = INF;
        l = r = NULL;
    }
}*t;
inline int size(treap *t){
    return t?t->sz:0;
}
inline int ssum(treap *t){
    return t?t->sum:0;
}
inline int lla(treap *t){
    return t?t->la:0;
}
inline int rra(treap *t){
    return t?t->ra:0;
}
inline int mma(treap *t){
    return t?t->ma:0;
}
inline int vval(treap *t){
    return t?t->val:0;
}
inline void rev(treap *&t){
    if(!t) return;
    treap *ft;
    swap(t->la,t->ra);
    ft = t->l;
    t->l = t->r;
    t->r = ft;
    t->rtag^=1;
}
void mo(treap *&t,int val){
    if(!t) return;
    t->val = t->vtag = val;
    if(val>=0){
        t->sum = t->la = t->ra = t->ma = size(t) * val;
    }
    else{
        t->sum = size(t) * val;
        t->la = t->ra = t->ma = val;
    }
}
void pull(treap *&t){
    int f;
    assert(t);
    // cout<<"pull "<<t->val<<' '<<size(t->l)<<endl;
    // cout<<"l "<<size(t->l)<<' '<<lla(t->l)<<' '<<rra(t->l)<<' '<<mma(t->l)<<endl;
    // cout<<"r "<<size(t->r)<<' '<<lla(t->r)<<' '<<rra(t->r)<<' '<<mma(t->r)<<endl;
    t->sz = size(t->l) + size(t->r) + 1;
    t->sum = ssum(t->l) + ssum(t->r) + t->val;

    if(t->l){
        t->la = lla(t->l);
        f = max(0,max(t->val,t->val+lla(t->r)));
        t->la = max(t->la,ssum(t->l)+f);
    }
    else{
        t->la = t->val + max(0,lla(t->r));
    }
    if(t->r){
        t->ra = rra(t->r);
        f = max(0,max(t->val,t->val+rra(t->l)));
        t->ra = max(t->ra,ssum(t->r)+f);
    }
    else{
        t->ra = t->val + max(0,rra(t->l));
    }

    t->ma = max(0,rra(t->l))+t->val+max(0,lla(t->r));
    t->ma = max(t->ma,max(t->la,t->ra));
    if(t->l){
        t->ma = max(t->ma,mma(t->l));
    }
    if(t->r){
        t->ma = max(t->ma,mma(t->r));
    }
    // cout<<"=> "<<size(t)<<' '<<lla(t)<<' '<<rra(t)<<' '<<mma(t)<<endl;
}
void push(treap *&t){
    assert(t);
    if(t->rtag){
        rev(t->l);
        rev(t->r);
        t->rtag = 0;
    }
    if(t->vtag!=INF){
        mo(t->l,t->vtag);
        mo(t->r,t->vtag);
        t->vtag = INF;
    }
}
treap* merge(treap *a,treap *b){
    if(!a || !b) return a?a:b;
    if(a->pri>b->pri){
        push(a);
        a->r = merge(a->r,b);
        pull(a);
        return a;
    }
    else{
        push(b);
        b->l = merge(a,b->l);
        pull(b);
        return b;
    }
}
void split(treap *t,treap *&a,treap *&b,int k){
    if(!t){
        a = b = NULL;
        return ;
    }
    push(t);
    if(size(t->l)+1<=k){
        a=t;
        split(t->r,a->r,b,k-size(t->l)-1);
        pull(a);
    }
    else{
        b = t;
        split(t->l,a,b->l,k);
        pull(b);
    }
}
void reverse(treap *&t){
    if(!t) return ;
    rev(t);
    push(t);
    pull(t);
}
void modify(treap *&t,int val){
    if(!t) return ;
    mo(t,val);
    push(t);
    pull(t);
}
void prt(treap *t){
    if(!t) return ;
    push(t);
    prt(t->l);
    // cout<<t->val<<' ';
    prt(t->r);
    pull(t);
}
// void pprt(treap *t,string s){
    // cout<<s<<" = ";
    // prt(t);
    // cout<<endl;
// }
int n,m;
void read(){
    RII(n,m);
    treap *ft;
    t = new treap(rit());
    REP1(i,1,n){
        ft = new treap(rit());
        t = merge(t,ft);
    }
}
void solve(){
    treap *t1,*t2,*t3,*ft;
    string s;
    int p,k,f;
    REP(i,m){
        cin>>s;
        // cout<<"s == "<<s<<endl;
        if(s=="INSERT"){
            RII(p,k);
            RI(f);
            ft = new treap(f);
            REP1(j,1,k){
                t1 = new treap(rit());
                ft = merge(ft,t1);
            }
            split(t,t1,t2,p);
            t = merge(t1,merge(ft,t2));
        }
        else if(s=="DELETE"){
            RII(p,k);
            split(t,t1,t2,p-1);
            split(t2,t2,t3,k);
            t = merge(t1,t3);
        }
        else if(s=="MAKE-SAME"){
            RIII(p,k,f);
            split(t,t1,t2,p-1);
            split(t2,t2,t3,k);
            modify(t2,f);
            t = merge(t1,merge(t2,t3));
        }
        else if(s=="REVERSE"){
            RII(p,k);
            split(t,t1,t2,p-1);
            split(t2,t2,t3,k);
            reverse(t2);
            t = merge(t1,merge(t2,t3));
        }
        else if(s=="GET-SUM"){
            RII(p,k);
            split(t,t1,t2,p-1);
            split(t2,t2,t3,k);
            cout<<ssum(t2)<<endl;
            t = merge(t1,merge(t2,t3));
        }
        else if(s=="MAX-SUM"){
            cout<<t->ma<<endl;
        }
        else assert(0);
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