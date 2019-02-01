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
void init(){
}
unsigned ran(){
    static unsigned x = 20161113;
    return x = x*0xdefaced+1;
}
int mymul(ll a,int b,int mod){
    return a*b%mod;
}
int mypow(int a,int b,int mod){
    int p,s,m;
    s = 1;
    p = 1;
    m = a;
    while(p<=b){
        if(b&p) s=mymul(s,m,mod);
        p<<=1;
        m = mymul(m,m,mod);
    }
    return s;
}
int miller_rabin(int n,int s=10){
    if(n<2) return 0;
    if(!(n&1)) return n==2;
    int m = n-1,j=0,b;
    while(!(m&1)){
        m>>=1;
        j++;
    }
    REP(i,s){
        b = ran()%(n-1) + 1 ;
        b = mypow(b,m,n);
        if(b==1) continue;
        REP(k,j+1){
        	if(k==j) return 0;
        	if(b==n-1) break;
        	b = mymul(b,b,n);
        }
    }
    return 1;
}
int n;
void read(){
}
void solve(){
    // cout<<miller_rabin(n)<<endl;
    if(miller_rabin(n)) cout<<"質數"<<endl;
    else cout<<"非質數"<<endl;
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

// 你怎麼了
// 想休息嗎
// 怎麼了
// 快˙ˇ˙
// 那就先休息一下啊
// 可是 要段考了?

/*
0、先计算出m、j，使得n-1=m*2^j，其中m是正奇数，j是非负整数 

1、随机取一个b，2<=b  

2、计算v=b^m mod n 

3、如果v==1，通过测试，返回 

4、令i=1 

5、如果v=n-1，通过测试，返回 

6、如果i==j，非素数，结束 

7、v=v^2 mod n，i=i+1 

8、循环到5 
*/