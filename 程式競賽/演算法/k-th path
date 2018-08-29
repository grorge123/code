#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define F first
#define S second
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(); cin.tie(0);
const int INF=2147483647;
struct astar{
    int len,h,id;
    bool operator < (const astar &b)const{
        if(len+h==b.len+b.h)return len>b.len;
        return len+h>b.len+b.h;
    }

};
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
        ve[b].push_back(pii(c,a));
        ve2[a].push_back(pii(c,b));
    }
    cin >> st>>en>>k;
    priority_queue<pii> pq;
    s[en]=0;
    pq.push(pii(s[en],en));
    while(!pq.empty()){
        pii now=pq.top();
        pq.pop();
        visit[now.S]=1;
        if (s[now.S] < now.F) continue;
        for(int i=0;i<ve[now.S].size();i++){
            if(s[ve[now.S][i].S]>s[now.S]+ve[now.S][i].F){
                s[ve[now.S][i].S]=s[now.S]+ve[now.S][i].F;
                pq.push(pii(s[ve[now.S][i].S],ve[now.S][i].S));
            }
        }
    }
    if(s[st]==INF){
        cout <<-1<<endl;
        return 0;
    }
    if(st==en)k++;
    priority_queue<astar> paq;
    astar now;
    int cnt[100005] = {0};
    now.id=st;now.len=0;now.h=s[st];
    paq.push(now);
    while(!paq.empty()){
        astar now=paq.top();paq.pop();
        cnt[now.id]++;
        if(cnt[en]==k){
            cout << now.len<<endl;
            return 0;
        }
        if(cnt[now.id] > k) continue;

        for(int i=0;i<ve2[now.id].size();i++){
            astar will;
            will.id=ve2[now.id][i].S;will.h=s[ve2[now.id][i].S];will.len=now.len+ve2[now.id][i].F;
            paq.push(will);
        }
    }
    cout << -1 <<endl;
    return 0;
}
