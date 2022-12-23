#include<bits/extc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,fma,avx2,bmi,bmi2,lzcnt,popcnt")
#define endl '\n'
typedef pair<int,int> pii;
#define pb push_back
#define F first
#define S second
#define LL long long int
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define grorge
#ifdef grorge
#define IOS
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
#define readc() getchar()
#else
#define debug(...)
#define pary(...)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define readc() readchar()
#endif

const int bufS = 1 << 20; // buffer size
static char buf[bufS], *p = buf, *q = buf, pbuf[bufS];
static int pp = -1;
const int INF = 2147483647;
const int mod = 1e9+7;
const LL seed = 0xdefaced;
inline void flush(){
    fwrite(pbuf, 1, pp + 1, stdout), pp = -1;
}
inline void print(int x, char en='\n'){
    static char sta[20];
    int top = 0;
    if(pp > 1 << 20) flush();
    if(x < 0)pbuf[++pp] = '-', x = -x;
    do {sta[top++] = x % 10 + '0';}while(x /= 10);
    while(top) pbuf[++pp] = sta[--top];
    pbuf[++pp] = en;
}
inline char readchar() {
	if(p == q && (q = (p=buf)+fread(buf,1,bufS,stdin)) == buf){
	 return EOF;
	}
	return *p++;
}
inline LL rit(){
    LL f=0,key=1;
    char c;
    do{
        c = readc();
        if(c=='-') key=-1;
    }while(c<'0' || c>'9');
    do{
        f=f*10+c-'0';
        c = readc();
    }while(c>='0' && c<='9');
    return f*key;
}

int main(){
    IOS
    auto start = std::chrono::system_clock::now();


    flush();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    cerr << "TIME:" << (diff.count()) << endl;
    return 0;
}
