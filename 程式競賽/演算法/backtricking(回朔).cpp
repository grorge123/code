#include<bits/stdc++.h>
using namespace std;
int s[50]={};
int output[50]={};
void bt(int n,int d){
    for(int i=1;i<=n;i++){
//        cout<< i;
        if(s[i]==0){
            s[i]=1;
            output[d]=i;
            if(d==n-1){
                for(int q=0;q<n;q++){
                    cout<< output[q];
                }
                cout<<endl;
            }else{
                bt(n,d+1);
            }
            s[i]=0;
        }
    }
}
int main(){
    int n;
    cin >> n;
    bt(n,0);
}
