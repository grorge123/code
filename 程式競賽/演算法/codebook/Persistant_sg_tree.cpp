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
const int Z = 100005;
struct node{
    node *lc,*rc;
    int l,r,m,size;
    node(){
        l = r = m = size = 0;
        lc = rc = NULL;
    }
}*root[Z],pool[3000000],kong,ttt;
void init(){
    kong = node();
}
inline node* copy(node *p){
    ttt++;
    pool[ttt] = node();

    // node *f;
    // f = new node;
    // if(p){
    //     f->lc = p->lc;
    //     f->rc = p->rc;
    //     f->l = p->l;
    //     f->r = p->r;
    //     f->m = p->m;
    //     f->size = p->size;
    // }
    return &pool[ttt];
}
#define mid (l+r)/2
inline int size(node *p){
    return p?p->size:0;
}
inline int askl(node *p){
    return p?p->l:0;
}
inline int askr(node *p){
    return p?p->r:0;
}
inline int askm(node *p){
    return p?p->m:0;
}
// void merge(node *p,node *a,node *b){
//     p->size = size(a) + size(b);
//     p->l = askl(a) + (askl(a)==size(a)?askl(b):0);
//     p->r = askr(b) + (askr(b)==size(b)?askr(a):0);
//     p->m = max(p->l,p->r);
//     p->m = max(p->m,max(askm(a),askm(b)));
//     p->m = max(p->m,askr(a)+askl(b));
// }
node merge2(node a,node b){
    node p;
    p.size = a.size + b.size;
    p.l = a.l + (a.l == a.size?b.l:0);
    p.r = b.r + (b.r == b.size?a.r:0);
    p.m = max(p.l,p.r);
    p.m = max(p.m,max(a.m,b.m));
    p.m = max(p.m,a.r+b.l);    
    return p;
}
void pull(node *p,int l,int r){
    p->l = 0 ;
    if(p->lc){
        p->l = p->lc->l;
        if(p->lc->l == p->lc->size && p->rc){
            p->l += p->rc->l;
        }
    }
    p->r = 0;
    if(p->rc){
        p->r = p->rc->r;
        if(p->rc->r == p->rc->size && p->lc){
            p->r += p->lc->r;
        }
    }
    p->m = max(p->l,p->r);
    p->m = max(p->m,max(askm(p->lc),askm(p->rc)));
    p->m = max(p->m,askr(p->lc) + askl(p->rc));
}
void modify(node *p,int l,int r,int x){
    p->size = r-l+1;
    if(l==r){
        p->l = p->r = p->m = 1;
        return ;
    }
    if(x<=mid){
        p->lc = copy(p->lc);
        modify(p->lc,l,mid,x);
    }
    else{
        p->rc = copy(p->rc);
        modify(p->rc,mid+1,r,x);
    }
    pull(p,l,r);
}
node query(node *p,int l,int r,int ql,int qr){
    // cout<<"I query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<(p?1:0)<<endl;
    if(!p){
        node f;
        f.l = f.r = f.m = 0;
        f.size = (r-l)+1;
        return f;
    }
    if(l==ql && r==qr){
        return *p;
    }
    if(qr<=mid) return query(p->lc,l,mid,ql,qr);
    else if(ql>mid) return query(p->rc,mid+1,r,ql,qr);
    else return merge2(query(p->lc,l,mid,ql,mid),query(p->rc,mid+1,r,mid+1,qr));
}
int n,m;
PII a[Z];
void read(){
    int x;
    RI(n);
    REP2(i,1,n){
        RI(x);
        a[i] = mp(x,i);
    }
    sort(a+1,a+n+1,greater<PII>());
}
void solve(){
    int l,r,w,p,q;
    root[0] = new node();
    REP2(i,1,n){
        root[i] = copy(root[i-1]);
        modify(root[i],1,n,a[i].Y);
    }
    RI(m);
    REP(i,m){
        RIII(l,r,w);
        p = 0;
        q = n;
        while(q-p>1){
            int mm = (p+q)/2;
            // cout<<"mm = "<<mm<<endl;
            if(query(root[mm],1,n,l,r).m>=w)
                q = mm;
            else p = mm;
        }
        cout<<a[q].X<<endl;
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