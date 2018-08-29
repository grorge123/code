#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define F first
#define S second
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(); cin.tie(0);
const int INF=2147483647;
int n,m,st,en,k,s[100005]={};
bool visit[100005]={};
vector<pii> ve[100005],ve2[100005];
int main(){
    IOS
    cin >> n>> m;
    for(int i=0;i<=n;i++){
        s[i]=INF;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a>>b>> c;
        ve[a].push_back(pii(c,b));
    }
    cin >> st>>en;
    priority_queue<pii> pq;
    s[st]=0;
    pq.push(pii(s[st],st));
    while(!pq.empty()){
        pii now=pq.top();
        pq.pop();
        if(now.S==en)break;
        visit[now.S]=1;
        if (s[now.S] < now.F) continue;
        for(int i=0;i<ve[now.S].size();i++){
            if(s[ve[now.S][i].S]>s[now.S]+ve[now.S][i].F){
                s[ve[now.S][i].S]=s[now.S]+ve[now.S][i].F;
                pq.push(pii(s[ve[now.S][i].S],ve[now.S][i].S));
            }
        }
    }
    cout << s[en]<<endl;
}
