#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main(){
    int n,m,pic[100][100]={},vis[100]={},po[100]={};//pic �s���|vis�s�O�_�w�g�O���T�Fpo�I���ثe�j�p
    cin >> n>>m;//n�O���X���Im�O�X����
    for(int i=0;i<=n;i++)
        po[i]=1e9;
//    for(int i=0;i<n;i++){         //�p�G�䪺�Ʀr�S��0�i�H���Ϊ�l1e9�u�n31�榳�[������0�N�n
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
    int st,en;//�_�I���I
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
