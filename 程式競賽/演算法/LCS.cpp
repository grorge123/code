#include<bits/stdc++.h>
using namespace std;
int all[1000][1000];
int main(){
    int n,m;
    char a[10000]={},b[10000]={};
    cin >> n>>m;
    cin >> a>>b;
    for(int i=1;i<=n;i++){
        for(int q=1;q<=m;q++){
            if(a[i-1]==b[q-1]){
                all[i][q]=all[i-1][q-1]+1;
            }else{
                all[i][q]=max(all[i-1][q],all[i][q-1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int q=1;q<=m;q++){
//                cout<< i<<" "<<q;
            cout<< all[i][q]<<" ";
        }
        cout<<endl;
    }
    cout<<all[n][m];
}
