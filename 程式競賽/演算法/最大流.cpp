#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
const int INF=0x7f7f7f7f;
void update(int now,int en,int s[][105],int li[][105],int n,vector<int> ve,int *ans){
    if(now==en){
//            cout << "ve:";
//        for(int i=0;i<ve.size();i++){
//            cout << ve[i]<<" ";
//        }
//        cout << endl;
        int Min=INF;
        for(int i=0;i<ve.size()-1;i++){
            Min=min(s[ve[i]][ve[i+1]],Min);
        }
        *ans+=Min;
        for(int i=0;i<ve.size()-1;i++){
            s[ve[i]][ve[i+1]]-=Min;
//            cout <<ve[i]<<" "<<ve[i+1]<<" "<< s[ve[i]][ve[i+1]]<<endl;
            s[ve[i+1]][ve[i]]+=Min;
        }
        return;
    }
}
bool dfs(int used[],int now,int en,int s[][105],int li[][105],int n,vector<int> ve,int *ans){
    if(now==en){
        update(now,en,s,li,n,ve,ans);
        return true;
    }
    for(int i=1;i<=n;i++){
        if(s[now][i]>0&&used[i]==0){
//            cout << now<<" "<<i<<endl;
//            cout <<"now:"<< now<<" "<<i<<" "<<s[now][i]<<endl;
            ve.push_back(i);
            used[i]=1;
            if(dfs(used,i,en,s,li,n,ve,ans))return true;
            ve.pop_back();
        }
    }
    return false;
}
int main(){
    int n,st,en,m,t=1;
    while(cin >> n){
        if(n==0)return 0;
        cin >>st>>en>>m;
        int ans=0;
        int s[105][105]={},li[105][105]={};
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            s[a][b]+=c;
            s[b][a]+=c;
            li[a][b]+=c;
            li[b][a]+=c;
        }
        int used[105]={};
        vector<int> ve;
        ve.push_back(st);
        used[st]=1;
        while(dfs(used,st,en,s,li,n,ve,&ans)){
            memset(used,0,sizeof(used));
            used[st]=1;
            ve.clear();
            ve.push_back(st);
        }
            cout <<"Network "<<t<<endl;
        cout <<"The bandwidth is "<<ans<<"."<<endl<<endl;
        t++;
    }
}
