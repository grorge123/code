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
        if(c=='%') return -100;
        if(c=='-') key=-1;
    }while(c<'0' || c>'9');
    do{
        f=f*10+c-'0';
        c=getchar();
        if(c=='%') return -100;
    }while(c>='0' && c<='9');
    return f*key;
}
inline void fprt(D f){
    printf("%.08lf",f);
}
void init(){
}
const int Z = 305; //??
int n;
vector<int> v[Z];
int g[Z][Z],instk[Z];
vector<int> path,tmp;
int mk[Z];
void read(){
    int a,b;
    MS0(g);
    path.clear();
    REP(i,Z){
        instk[i] = 0;
        v[i].clear();
        mk[i] = 0;
    }
    while(1){
        RI(a);
        if(a==-100) break;
        RI(b);
        v[a].pb(b);
        v[b].pb(a);
        g[a][b] = g[b][a] = 1;
    }
}
void dfs(int p){
    mk[p] = 1;
    instk[p] = 1;
    path.pb(p);
    SREP(f,v[p]){
        if(mk[f] == 0){
            dfs(f);
        }
    }

}
void solve(){
    int key;
    dfs(1);
    while(1){
        // cout<<"path = ";
        // SREP(f,path) cout<<f<<' ';
        // cout<<endl;
        if(path[0] == path.back() && LE(path) == n+1) break;
        if(path[0] == path.back()){
            key = 0;
            REP(i,LE(path)){
                SREP(f,v[path[i]]){
                    if(!instk[f]){
                        instk[f] = 1;
                        key = 1;
                        tmp.clear();
                        tmp.pb(f);
                        RREP2(j,i,0) tmp.pb(path[j]);
                        RREP2(j,LE(path)-1,i+1) tmp.pb(path[j]);

                        path.clear();
                        SREP(f,tmp) path.pb(f);

                        break;
                    }
                }
                if(key) break;
            }
            if(key==0) {
                cout<<'N'<<endl;
                return ;
            }
        }  
        else{
            key = 0;
            REP(i,LE(path)-1){
                if(g[path[i]][path.back()] && g[path[i+1]][path[0]]){
                    key = 1;
                    tmp.clear();
                    REP(j,i+1) tmp.pb(path[j]);
                    RREP2(j,LE(path)-1,i+1) tmp.pb(path[j]);
                    tmp.pb(path[0]);

                    path.clear();
                    SREP(f,tmp) path.pb(f);
                    break;
                }
            }
            if(key == 0){
                cout<<'N'<<endl;
                return ;
            }
        }
    }
    REP(i,LE(path)-1) cout<<path[i]<<' ';
    cout<<path.back()<<endl;
    // SREP(f,path) cout<<f<<' ';
    // cout<<endl;
}
int main(){
    int nn=1;
    // nn=rit();
    while(nn--){
        while(cin>>n) 
            init(),read(),solve();
    }
    return 0;
}