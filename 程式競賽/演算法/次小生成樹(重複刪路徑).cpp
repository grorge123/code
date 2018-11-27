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
vector<int> match;
struct line{
    LL a,b,c;
    bool operator < (const line & ano) const{
        return c<ano.c;
    }
};
int fa[MAX];
line s[MAX*MAX/2];
int fi(int a){
    if(fa[a]==a)return a;
    return fa[a]=fi(fa[a]);
}
LL kurskal(int n,int m,int skip){
    LL ans=0;
    int cnt=n;
    for(int i=0;i<m;i++){
        if(skip==i) continue;//跳過這次的線段
        if(fi(s[i].a)!=fi(s[i].b)){
            ans+=s[i].c;
            fa[fi(s[i].a)]=fi(s[i].b);
            cnt--;
            if(skip==-1){
                match.push_back(i);//將最小生成樹的線段記錄起來
            }
//            cout << s[i].a<<" "<<s[i].b<<endl;
//            ve[s[i].a].push_back(pll(s[i].b,s[i].c));//創建之後DFS的圖
//            ve[s[i].b].push_back(pll(s[i].a,s[i].c));
//            s[i].c=INF;//將目前的線權重調到無限大避免之後用到
        }
    }
    if(cnt>1)return -1;
    return ans;
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
    LL ans1=kurskal(n,m,-1);
    if(ans1==-1){
        cout << "-1 -1"<<endl;
    }else{
        cout << ans1<<" ";
    }
    LL ans2=INF;
    for(int i=0;i<match.size();i++){
        for(int i=0;i<=n;i++){
            fa[i]=i;
        }
        LL a=kurskal(n,m,match[i]);
//        cout << a<<" "<<s[match[i]].a<<" "<<s[match[i]].b<<endl;
        if(a!=-1)
            ans2=min(ans2,a);
    }
    if(ans2==INF){
        cout << -1<<endl;
    }else{
        cout << ans2<<endl;
    }
    return 0;
}
