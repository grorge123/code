#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin >> n;
    int no[100005]={},ran[100005]={};
    for(int i=1;i<=n;i++){
        no[i]=i;
        ran[i]=i;
    }
    cin >> t;
    while(t--){
        int a,b;
        cin >> a>> b;
        switch (a){
        case 0:
            ran[no[b]]=0;
            break;
        case 1:
            if(no[b]==1)break;
            int cha=no[b];
            do{
                cha--;
            }while(ran[cha]==0);
            int rancha=cha,ranb=no[b],nocha=ran[cha],nob=b;
            swap(ran[ranb],ran[rancha]);
            swap(no[nob],no[nocha]);
            break;
        }
//        for(int i=1;i<=n;i++){
//            cout << ran[i]<<" ";
//        }
    }
    int fi=0;
    for(int i=1;i<=n;i++){
        if(ran[i]==0)continue;
        if(fi)
            cout <<" "<< ran[i];
        else{
            cout << ran[i];
            fi=1;
        }
    }
    cout << endl;

}
