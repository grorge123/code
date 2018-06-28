#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define LL long long int
#define Max 100005
#define pi pair<LL,LL>
const LL INF=10000000000000;
LL n,m,q;
vector<pair<LL,LL> > ve[Max],ve2[Max];
LL num[Max]={},num2[Max]={};
int main(){
    cin >> n>>m>>q;
    for(int i=1;i<=n;i++){
        num[i]=INF;
        num2[i]=INF;
    }
    for(int i=0;i<m;i++){
        LL a,b,c;
        cin >>a>>b>>c;
        ve[a].push_back(pi(b,c));
        ve2[b].push_back(pi(a,c));
    }
    priority_queue<pair<LL,LL>,vector<pair<LL,LL> >,greater<pair<LL,LL> > > pq;
    num[1]=0;
    int visit[Max]={};
    pq.push(pi(0,1));
    while(pq.size()){
        LL now=pq.top().S;
        pq.pop();
        visit[now]=1;
        if(now==n)break;
        for(int i=0;i<ve[now].size();i++){
            if(num[ve[now][i].F]>num[now]+ve[now][i].S&&visit[ve[now][i].F]==0){
                num[ve[now][i].F]=num[now]+ve[now][i].S;
                pq.push(pi(num[ve[now][i].F],ve[now][i].F));
            }
        }
    }
    while(pq.size())pq.pop();
    num2[n]=0;
    int visit2[Max]={};
    pq.push(pi(0,n));
    while(pq.size()){
        LL now=pq.top().S;
        pq.pop();
        visit2[now]=1;
        if(now==1)break;
        for(int i=0;i<ve2[now].size();i++){
            if(num2[ve2[now][i].F]>num2[now]+ve2[now][i].S&&visit2[ve2[now][i].F]==0){
                num2[ve2[now][i].F]=num2[now]+ve2[now][i].S;
                pq.push(pi(num2[ve2[now][i].F],ve2[now][i].F));
            }
        }
    }
//    for(int i=1;i<=n;i++){
//        cout << num[i]<<" ";
//    }
//    cout << endl;
//    for(int i=1;i<=n;i++){
//        cout << num2[i]<<" ";
//    }
//    cout << endl;
    for(int i=0;i<q;i++){
        LL a,b;
        cin >> a>>b;
        cout << min(num[n],num[a]+1+num2[b])<<endl;
    }
}
