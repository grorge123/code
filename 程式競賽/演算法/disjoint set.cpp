#include<bits/stdc++.h>
using namespace std;
int dj[500];
int size[500];
int unio(int a,int b){
    if(dj[a]!=dj[b]){
        size[a]==max(size[a],size[b])?dj[b]=dj[a]:dj[b]=dj[a];
        size[a]=size[b]=size[a]+size[b];
    }
}
void print(int n){
    for(int i=1;i<n;i++){
        for(int q=1;q<=n;q++){
            if(dj[q]==i){
                cout<<q<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"請輸入人數";
    cin >> n;
    for(int i=1;i<=n;i++){dj[i]=i+1;size[i]=1;}
    while(true){
        cout<< "輸入合併團體";
        int a,b;
        cin >> a>>b;
        unio(a,b);
        print(n);
    }
}
