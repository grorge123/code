#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main(){
    int n,m,pic[100][100]={},vis[100]={},po[100]={};//pic 存路徑vis存是否已經是正確了po點的目前大小
    cin >> n>>m;//n是有幾個點m是幾條邊
    for(int i=0;i<=n;i++)
        po[i]=1e9;
//    for(int i=0;i<n;i++){         //如果邊的數字沒有0可以不用初始1e9只要31行有加不等於0就好
//        for(int q=0;q<n;q++){
//            pic[i][q]=1e9;
//        }
//    }
    for(int i=0;i<m;i++){
        int a,b,val;
        cin >> a>> b>> val;
        pic[a][b]=val;
        pic[b][a]=val;
    }
    int st,en;//起點終點
    cin >> st>>en;
    po[st]=0;
    map<int,int> ma;
    ma.insert(pair<int,int>(po[st],st));
    while(!ma.empty()){
        int now=ma.begin()->second;
        ma.erase(ma.begin());
        vis[now]=1;
        for(int i=0;i<n;i++){
            if(vis[i]!=1&&pic[now][i]!=0&&pic[now][i]+po[now]<po[i]){
                po[i]=pic[now][i]+po[now];
                ma.insert(pair<int,int>(po[i],i));
            }
        }
    }
//    for(int i=0;i<n;i++){
//        cout <<i<<":"<< po[i]<<endl;
//    }
    cout << po[en];

}
