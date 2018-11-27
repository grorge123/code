#include<bits/stdc++.h>
using namespace std;
vector<int> s[100005];
bool visit[100005];
vector<int> ap;
vector<pair<int,int> > edgebridge;
int D[100005]={},L[100005]={},parant[100005]={};
void tarjan(int id,int deep){
    visit[id]=true;
    bool isap=false;
    int child=0;
    D[id]=L[id]=deep;
    for(int i=0;i<s[id].size();i++){
        if(!visit[s[id][i]]){
            parant[s[id][i]]=id;
            child++;
            tarjan(s[id][i],deep+1);
            if(D[id]<=L[s[id][i]])isap=true;
            if(D[id]<L[s[id][i]]) edgebridge.push_back(pair<int,int>(id,s[id][i]));
            L[id]=min(L[id],L[s[id][i]]);
        }else if(s[id][i]!=parant[id]&&D[s[id][i]]<D[id]){
            L[id]=min(L[id],D[s[id][i]]);
        }
    }
//    cout << id<<" "<<parant[id]<<" "<<D[id]<<" "<<L[id]<<" "<<child<<endl;
    if((parant[id]==0&&child>=2)||(parant[id]!=0&&isap)){
        ap.push_back(id);
    }
    return;
}
int main(){
    int n,m;
    cin >> n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a>>b;
        s[a].push_back(b);
        s[b].push_back(a);
    }
    tarjan(1,1);
    cout << "size:"<<ap.size()<<endl;
    for(auto i:ap){
        cout << i<<endl;
    }
//    for(auto i:edgebridge){
//        cout <<i.first<<" "<<i.second<<endl;
//    }
    return 0;
}
