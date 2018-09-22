
#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define F first
#define S second
#define pll pair<LL,LL>
const LL INF=LLONG_MAX;
const int MAX=1005;
vector<pll> ve[MAX];
struct line{
    LL a,b,c;
    bool operator < (const line & ano) const{
        return c<ano.c;
    }
};
int fa[MAX];
line s[MAX*MAX/2];
bool visit[MAX];
int fi(int a){
    if(fa[a]==a)return a;
    return fa[a]=fi(fa[a]);
}
LL kurskal(int n,int m){
    LL ans=0;
    int cnt=n;
    for(int i=0;i<m;i++){
        if(fi(s[i].a)!=fi(s[i].b)){
            ans+=s[i].c;
            fa[fi(s[i].a)]=fi(s[i].b);
            cnt--;
//            cout << s[i].a<<" "<<s[i].b<<endl;
            ve[s[i].a].push_back(pll(s[i].b,s[i].c));//創建之後DFS的圖
            ve[s[i].b].push_back(pll(s[i].a,s[i].c));
            s[i].c=INF;//將目前的線權重調到無限大避免之後用到
        }
    }
    if(cnt>1)return -1;
    return ans;
}
bool DFS(int now,int en,stack<LL> *st,int pa){
//    cout <<"ve:"<< now<<" "<<en<<endl;
    if(now==en&&(*st).size()>=1){
//        cout << "ASD"<<endl;
        return true;
    }
    visit[now]=1;
    int cnt=0;
    for(int i=0;i<ve[now].size();i++){
        if(cnt==0&&ve[now][i].F==pa&&ve[now][i].S==(*st).top()){
            cnt=1;
            continue;
        }
        if((!visit[ve[now][i].F])||ve[now][i].F==en){
            (*st).push(ve[now][i].S);
            if(DFS(ve[now][i].F,en,st,now))return true;
            (*st).pop();
        }
    }
    visit[now]=0;
//    cout << "pop"<<now<<" "<<(*st).size()<<endl;
    return false;
}
int main(){
    int n,m;
    cin >> n>> m;
    for(int i=0;i<=n;i++){
        fa[i]=i;
    }
    for(int i=0;i<m;i++){
        LL a,b,c;
        cin >> a>>b>>c;
        if(a==b){m--;i--;continue;}
        s[i].a=a;s[i].b=b;s[i].c=c;
    }
    sort(s,s+m);
    LL ans1=kurskal(n,m);
    if(ans1==-1){
        cout << "-1 -1"<<endl;
    }else{
        cout << ans1<<" ";
    }
    sort(s,s+m);//將之前設定的無限大線段丟到最後面
//    if(s[0].c==INF){//如果最前面是無限大就代表沒有多的線段了
//        cout << -1<<endl;
//        return 0;
//    }
    LL AllMax=INF;
    for(int i=0;s[i].c!=INF&&i<m;i++){
        memset(visit,0,sizeof(visit));
//        cout << i<<endl;
        ve[s[i].a].push_back(pll(s[i].b,s[i].c));
        ve[s[i].b].push_back(pll(s[i].a,s[i].c));//將最短非最小生成樹線段的線丟進圖
        stack<LL> sta;
        LL Max=0;
        DFS(s[i].a,s[i].a,&sta,0);//DFS找出迴圈裡的所有線段
        int fi=0;
        if(sta.empty())continue;
        while(!sta.empty()){//找出第二大縣段
            if(sta.top()==s[i].c&&fi==0){
                fi=1;
                sta.pop();
                continue;
            }
//            if(sta.top()!=s[i].c)
                Max=max(Max,sta.top());
            sta.pop();
        }
        ve[s[i].a].pop_back();
        ve[s[i].b].pop_back();
//        cout << Max<<endl;
        AllMax=min(s[i].c-Max,AllMax);
//        cout << s[i].c<<" "<<Max<<endl;
    }
//    cout << AllMax<<endl;
    if(AllMax!=INF)
        cout << ans1+AllMax<<endl;
    else
        cout << -1<<endl;
    return 0;
}
