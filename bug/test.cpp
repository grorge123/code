#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
#define LL long long int
#define F first
#define S second
#define pii pair<int,int>
#define mes(x) memset(x,0,sizeof(x))
const int INF=2147483647;
struct node{
    int to,next,w;
}ve[1000005],ve2[1000005];
int head[1000005]={},head2[1000005]={};
long long int s[1000005]={},s2[1000005]={};
bool vi[1000005]={};
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>> m;
        mes(vi);memset(head,-1,sizeof(head));memset(head2,-1,sizeof(head2));
        for(int i=0;i<=m;i++){
            ve[i].to=ve[i].next=ve[i].w=0;
            ve2[i].to=ve2[i].next=ve2[i].w=0;
        }
        for(int i=1;i<=n;i++){
            s[i]=s2[i]=INF;
        }
        for(int i=0;i<m;i++){
            int a,b,c;
            cin >> a>> b>> c;
            ve[i].to=b;
            ve[i].w=c;
            ve[i].next=head[a];
            ve2[i].to=a;
            ve2[i].w=c;
            ve2[i].next=head2[b];
            head[a]=i;
            head2[b]=i;
        }
        queue<int> qu;
        qu.push(1);
        s[1]=0;
        vi[1]=1;
        while(!qu.empty()){
            int now=qu.front();qu.pop();
            vi[now]=0;
            for(int i=head[now];i>=0;i=ve[i].next){
                if(s[ve[i].to]>s[now]+ve[i].w){
                    s[ve[i].to]=s[now]+ve[i].w;
                    if(!vi[ve[i].to]){
                        qu.push(ve[i].to);
                        vi[ve[i].to]=1;
                    }
                }
            }
        }
        qu.push(1);
        s2[1]=0;
        vi[1]=1;
        while(!qu.empty()){
            int now=qu.front();qu.pop();
            vi[now]=0;
            for(int i=head2[now];i>=0;i=ve2[i].next){
                if(s2[ve2[i].to]>s2[now]+ve2[i].w){
                    s2[ve2[i].to]=s2[now]+ve2[i].w;
                    if(!vi[ve2[i].to]){
                        qu.push(ve2[i].to);
                        vi[ve2[i].to]=1;
                    }
                }
            }
        }
        LL all=0;
        for(int i=1;i<=n;i++){
            all+=s[i]+s2[i];
        }
        cout <<all<<endl;
    }
    return 0;
}
