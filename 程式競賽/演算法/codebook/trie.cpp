#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define ALL(x) x.begin(),x.end()
#define D double
#define ll long long
#define REP(i,a) for(int i=0;i<a;i++)
#define REP1(i,a,b) for(int i=a;i<b;i++)
#define REP2(i,a,b) for(int i=a;i<=b;i++)
#define RREP(i,a) for(int i=a-1;i>=0;i--)
#define RREP1(i,a,b) for(int i=a;i>b;i--)
#define RREP2(i,a,b) for(int i=a;i>=b;i--)
#define MS0(x) memset((x),0,sizeof((x)));
#define MS1(x) memset((x),-1,sizeof((x)));
#define MSF(x) memset((x),127,sizeof(x));
#define pb push_back
#define LE(x) (int)((x).length())
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
const int Z = 35;
const ll K = 123457;
void init(){
}
inline int cg(char c){ // char -> int
    if(c>='a' && c<='z') return c-'a'+10;
    else return c-'0';
}
inline char rcg(int x){ // int -> char
    if(x<10) return x+'0';
    else return x-10+'a';
}
struct node{ // trie node
    node *kid[36]; // 0~25 = a~z , 26~35 = 0~9
    node(){
        REP(i,36) kid[i] = NULL;
    }
}*root;
int rrr; // rrr = case counter
string sa,sb,sp; 
int lcs[Z][Z],ans,cnt; //ans = lcs length, cnt = lcs counter
set<int> mk[Z][Z];
void go(node *p,int x,int y,ll key){
    int f;
    if(mk[x][y].find(key)!=mk[x][y].end()) return ;
    mk[x][y].insert(key);
    if(lcs[x][y]==0){
        //end
        return ;
    }
    if(sa[x-1]==sb[y-1]){
        // cout<<"I go "<<sa[x-1]<<' '<<x<<" "<<y<<' '<<lcs[x][y]<<endl;
        f = cg(sa[x-1]);
        if(p->kid[f]==NULL){
            p->kid[f] = new node();
            if(lcs[x][y]==1) cnt++;
        }
        key = (key*K+sa[x-1])%mod7;
        go(p->kid[f],x-1,y-1,key);
    }
    else{
        if(lcs[x-1][y]==lcs[x][y])
            go(p,x-1,y,key);
        if(lcs[x][y-1]==lcs[x][y]){
            go(p,x,y-1,key);
        }
    }
}
void prt(node *p,int r){
    // if(p->c!=0) cout<<p->c<<' '<<r<<endl;
    if(r==ans) cout<<sp<<endl;
    REP(i,36){
        if(p->kid[i]){
            sp.pb(rcg(i));
            prt(p->kid[i],r+1);
            sp.resize(LE(sp)-1);
        }
    }
}
void del(node *p){
    REP(i,36){
        if(p->kid[i]){
            del(p->kid[i]);
        }
    }
    delete(p);
}
void read(){
    cin>>sa>>sb;
}
void solve(){
    MS0(lcs); //reset
    cnt = 0;
    //reverse the string for the lexicographic order
    for(int i=0,j=LE(sa)-1;i<j;i++,j--) swap(sa[i],sa[j]); 
    for(int i=0,j=LE(sb)-1;i<j;i++,j--) swap(sb[i],sb[j]);
    REP(i,LE(sa)){
        REP(j,LE(sb)){
            if(sa[i]==sb[j])
                lcs[i+1][j+1] = lcs[i][j]+1;
            else lcs[i+1][j+1] = max(lcs[i][j+1],lcs[i+1][j]);
            mk[i+1][j+1].clear();
        }
    }
    ans = lcs[LE(sa)][LE(sb)];
    root = new node();
    REP2(i,1,LE(sa))
        REP2(j,1,LE(sb))
            if(lcs[i][j]==ans)
                go(root,i,j,0);

    cout<<"Case #"<<rrr<<": "<<max(1,cnt)<<endl;
    prt(root,0);
    del(root);
}
int main(){
    int nn=1;
    nn=rit();
    init();
    rrr++;
    while(nn--){
        read();
        solve();
        rrr++;
    }
    return 0;
}
// http://zerojudge.tw/ShowProblem?problemid=b397