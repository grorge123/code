#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
#define bloop(i,n,j) for(int (i)=(j);(i)<(n);(i)++)
#define bloop1(i,n,j) for(int (i)=(j);(i)<=(n);(i)++)
#define sloop(i,n,j) for(int i=n;i>j;i--)
#define sloop1(i,n,j) for(int i=n;i>=j;i--)
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
#define MS0(x) memset((x),0,sizeof((x)))
#define MS1(x) memset((x),-1,sizeof((x)))
#define RI(x) x=rit()
#define RII(a,b) a=rit(),b=rit()
#define RIII(a,b,c) a=rit(),b=rit(),c=rit()
const int INF = 0x7f7f7f7f;
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
    return 0;
}
