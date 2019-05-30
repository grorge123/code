#include<bits/stdc++.h>
using namespace std;
vector<int> ve[1000006] = {};
int ans = 0;
void dfs(int now ,int en){
    if(now == en){
        ans++;
        return;
    }
    for(int i = 0 ; i < ve[now].size() ; i++){
        dfs(ve[now][i],en);
    }
    return;
}
int main(){
    int n,e;
    cin >> n >> e;
    for(int i = 0 ; i < e ; i++){
        int a,b;
        cin >> a >> b;
        ve[a].push_back(b);
    }
    dfs(0,n-1);
    cout << ans ;
    return 0;
}
