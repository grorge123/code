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
struct node{
    vector<short> v;
    node *ch[26],*fail;
    node *last;
    node(){
        REP(i,26) ch[i] = NULL;
        fail = NULL;
        last = NULL;
    }
}*root,pool[100005];
int n_mem;
inline node* get_node(){
    pool[n_mem] = node();
    return &pool[n_mem++];
}
char bs[1000005],s[55];
int ans[1005],L;
void insert(node *p,int r,int ii){
    if(r==L){
        p->v.pb(ii);
        return ;
    }
    char fc = s[r] - 'a';
    if(!p->ch[fc]) p->ch[fc] = get_node();
    insert(p->ch[fc],r+1,ii);
}
queue<node*> q;
void get_fail(){
    node *now,*f;
    root->fail = NULL;
    q.push(root);
    while(!q.empty()){
        now = q.front();
        q.pop();
        REP(i,26){
            if(now->ch[i]){
                f = now->fail;   // f = fail[i-1]
                while(f && !f->ch[i]) f = f->fail;
                if(!f) now->ch[i]->fail = root;
                else{ 
                    now->ch[i]->fail = f->ch[i];
                    if(!f->ch[i]->v.empty()) {
                        now->ch[i]->last = f->ch[i];
                    }
                    else{
                        now->ch[i]->last = f->ch[i]->last;
                    }
                }
                q.push(now->ch[i]);
            }
        }
    }
}
void okok(node *x){
    REP(i,LE(x->v)){
        ans[x->v[i]] = 1;
    }
    if(x->last) okok(x->last);
}
void boom(){
    int now;
    node *p;
    p = root;
    REP(i,L){
        now = bs[i]-'a';
        while(!p->ch[now] && p!=root) p = p->fail;
        if(p->ch[now]) p = p->ch[now];
        else p = root; // p = now
        okok(p);
    }
}
int n;
void init(){
    n_mem = 0;
    root = get_node();   
}
void read(){
    init();
    scanf(" %s",bs);
    RI(n);
    REP(i,n){
        scanf(" %s",s);
        L = strlen(s);
        ans[i] = 0;
        insert(root,0,i);
    }
}
void solve(){
    get_fail();
    L = strlen(bs);
    boom();
    REP(i,n){
        if(ans[i]) puts("y");
        else puts("n");
    }
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