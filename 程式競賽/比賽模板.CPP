#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define FAR(i,j,k,l) for(int i=j;i>k;i-=l)
#define FOR1(i,j,k,l) for(int i=j;i<=k;i+=l)
#define FAR1(i,j,k,l) for(int i=j;i>=k;i-=l)
#define rep(i,j,k) FOR(i,j,k,1)
#define rap(i,j,k) FAR(i,j,k,1)
#define rep1(i,j,k) FOR1(i,j,k,1)
#define rap1(i,j,k) FAR1(i,j,k,1)
#define rip(i,k) FOR(i,0,k,1)
#define rip1(i,k) FOR1(i,0,k,1)
#define rtp(i,k) FAR(i,k,0,1)
#define rtp1(i,k) FAR1(i,k,0,1)
#define pb push_back
#define F first
#define S second
#define LL long long int
#define be(a) a.begin
#define itr iterator
#define p_q priority_queue
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define D double
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#ifdef grorge
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#else
#define debug(...)
#define pary(...)
#endif
#define endl '\n'
#define IOS ios_base::sync_with_stdio();cin.tie(0);
#define MS0(x) memset((x),0,sizeof((x)))
#define MS1(x) memset((x),-1,sizeof((x)))
#define RI(x) x=rit()
#define RII(a,b) a=rit(),b=rit()
#define RIII(a,b,c) a=rit(),b=rit(),c=rit()
const int INF = 2147483647;
const int mod = 1e9+7;
const LL seed = 0xdefaced;
inline LL rit(){
    LL f=0,key=1;
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
int main(){
    IOS
    cout << min(INF,8);
    return 0;
}
