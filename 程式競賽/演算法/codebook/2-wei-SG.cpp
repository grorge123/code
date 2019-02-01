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
void init(){
}
const int Z = 505;
int tree[4*Z][4*Z];
int n,m,a[Z][Z];
void updatey(int px,int p,int l,int r,int y,int val){
    int mid = (l+r)/2;
    if(l==r){
        tree[px][p] = max(tree[px][p],val);
        return ;
    }
    if(y<=mid) updatey(px,p*2,l,mid,y,val);
    else updatey(px,p*2+1,mid+1,r,y,val);
    tree[px][p] = max(tree[px][p*2],tree[px][p*2+1]);
}
void updatex(int p,int l,int r,int x,int y,int val){
    int mid = (l+r)/2;
    updatey(p,1,1,m,y,val);
    if(l==r) return ;
    if(x<=mid) updatex(p*2,l,mid,x,y,val);
    else updatex(p*2+1,mid+1,r,x,y,val);
}
int queryy(int px,int p,int l,int r,int y1,int y2){
    int mid = (l+r)/2;
    // cout<<"    y = "<<l<<" ~ "<<r<<endl;
    if(l==y1 && r==y2){
        // cout<<"tree "<<px<<' '<<p<<" = "<<tree[px][p]<<endl;
        return tree[px][p];
    }
    if(y2<=mid){
        return queryy(px,p*2,l,mid,y1,y2);
    }
    else if(y1>mid){
        return queryy(px,p*2+1,mid+1,r,y1,y2);
    }
    else{
        return max(queryy(px,p*2,l,mid,y1,mid),queryy(px,p*2+1,mid+1,r,mid+1,y2));
    }
}
int queryx(int p,int l,int r,int x1,int x2,int y1,int y2){
    int mid = (l+r)/2;
    // cout<<"x = "<<l<<" ~ "<<r<<endl;
    if(l==x1 && r==x2){
        return queryy(p,1,1,m,y1,y2);
    }
    if(x2<=mid){
        return queryx(p*2,l,mid,x1,x2,y1,y2);
    }
    else if(x1>mid){
        return queryx(p*2+1,mid+1,r,x1,x2,y1,y2);
    }
    else{
        return max(queryx(p*2,l,mid,x1,mid,y1,y2),queryx(p*2+1,mid+1,r,mid+1,x2,y1,y2));
    }
}
void read(){
    RII(n,m);
    REP2(i,1,n){
        REP2(j,1,m){
            RI(a[i][j]);
            updatex(1,1,n,i,j,a[i][j]);
        }
    }
}
void solve(){
    int Q,x1,y1,x2,y2;
    // cout<<"--"<<endl;
    // REP2(i,1,n){
    //     REP2(j,1,m) cout<<queryx(1,1,n,i,i,j,j)<<' ';
    //     cout<<endl;
    // }
    // cout<<"--"<<endl;
    RI(Q);
    while(Q--){
        RII(x1,y1); RII(x2,y2);
        cout<<queryx(1,1,n,x1,x2,y1,y2)<<endl;
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
