//uva 820
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pii pair<int,int>
const int INF=2147483647;
struct node{
    int n=0,k=0;
    node(){n=0,k=0;}
    node(int two,int three){
        n=two,k=three;
    }
};
int st,en,cnt,deep[105]={},n;
node ve[105][105];
bool bfs(void){
    memset(deep,0,sizeof(deep));
    queue<int> qu;
    deep[st]=1;
    qu.push(st);
    while(!qu.empty()){
        int now=qu.front();qu.pop();
        for(int i=0;i<=n;i++){
            if(deep[i]==0&&ve[now][i].k>0){
                deep[i]=deep[now]+1;
                qu.push(i);
            }
        }
    }
    if(deep[en]==0)
        return false;
    return true;
}
int flow(int now,int en,vector<int> qu,int used[]){
    if(now==en){
        int all=INF;
        for(int i=0;i<qu.size()-1;i++){
            all=min(all,ve[qu[i]][qu[i+1]].k);
        }
        for(int i=0;i<qu.size()-1;i++){
//            cout << qu[i]<<' '<<qu[i+1]<<endl;
            ve[qu[i]][qu[i+1]].k-=all;
            ve[qu[i+1]][qu[i]].k+=all;
        }
        return all;
    }
    for(int i=0;i<=n;i++){
        if(deep[now]<deep[i]&&ve[now][i].k>0&&used[i]==0){
            used[i]=1;
            qu.push_back(i);
            if(int re=flow(i,en,qu,used))return re;
            qu.pop_back();
            used[i]=0;
        }
    }
    return 0;
}
int dinic(){
    int ans=0;
    while(bfs()){
        vector<int> qu;
        qu.push_back(st);
        int used[105]={};
        while(int d=flow(st,en,qu,used)){
            ans+=d;
        }
    }
    return ans;
}
int main(){
    int ti=1;
    while(cin >> n){
        if(n==0)return 0;
        for(int i=0;i<=n;i++){
            for(int q=0;q<=n;q++){
                ve[i][q]=node(0,0);
            }
        }
        cin >> st>>en>>cnt;
        for(int i=0;i<cnt;i++){
            int a,b,c;
            cin >>a>>b>>c;
            ve[a][b].n+=c;ve[a][b].k+=c;
            ve[b][a].k+=c;ve[b][a].n+=c;
        }
        cout << "Network "<<ti<<endl;
        cout << "The bandwidth is "<<dinic()<<"."<<endl<<endl;
        ti++;
    }
    return 0;
}
