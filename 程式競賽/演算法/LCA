#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> ve[500004] = {};
int dep[500004] = {};
int pa[500005][25] = {};
int lg2;
void dfs(int now,int p){
    pa[now][0] = p;
    for(int i = 1 ; i < lg2 ; i++){
        pa[now][i] = pa[pa[now][i-1]][i-1];
    }
    for(int i = 0 ; i < int(ve[now].size()) ; i++){
        if(ve[now][i]==p){
            continue;
        }
        dep[ve[now][i]] = dep[now] + 1;
        dfs(ve[now][i], now);
    }
}
int lca(int a,int b){
    if(dep[a]>dep[b]){
        swap(a,b);
    }
    int s = dep[b]-dep[a];
    for(int i = 0 ; i <= lg2 ; i++){
        if(s&(1<<i))
            b = pa[b][i];
    }
    if(a==b)return a;
    for(int i = lg2 ; i >= 0 ; i--){
        if(pa[b][i]!=pa[a][i]){
            b = pa[b][i];
            a = pa[a][i];
        }
    }
    return pa[a][0];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,s;
    cin >> n >> m >> s;
    lg2 = int(log2(n))+1;
    for(int i = 0 ; i < n - 1 ; i++){
        int a,b;
        cin >> a >> b;
        ve[a].push_back(b);
        ve[b].push_back(a);
    }
    dep[s] = 1;
    dfs(s,0);
    for(int i = 0 ; i < m ; i++){
        int a,b;
        cin >> a >> b;
        cout << lca(a,b)<<endl;
    }
    return 0;
}
