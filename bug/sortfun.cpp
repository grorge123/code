#include<bits/stdc++.h>
using namespace std;
bool ad(int a,int b){
    if(a%2==0&&b%2==0){
        return a>b?false:true;
    }
    if(a%2==0&&b%2==0){
        return a>b?false:true;
    }
    return a%2==0?false:true;
}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    sort(a,a+10,ad);
//    for(int i=0;i<10;i++){
//        cout << a[i]<< " ";
//    }
    cout << ad(2,4);
}
