#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define F first
#define S second
#define PB pust_back
#define PI pair<int,int>
#define sloop(i,n,j) for(int i=j;i<n;i++)
#define sloop1(i,n,j) for(int i=j;i<=n;i++)
#define bloop(i,n,j) for(int i=n;i>j;i--)
#define bloop1(i,n,j) for(int i=n;i>=j;i--)
int main(){
    int n,d[400000];
    cin >> n;
    sloop(i,n,0){
        int a;
        cin >>a;
        if(a==0)d[i]=0;
        if(a>0)d[i]=1;
        if(a<0)d[i]=-1;
    }
    int max=0,now=0;
    sloop(i,n-1,0){
        if(abs(d[i]-d[i+1])!=0){
            now++;
        }else{
            now=0;
        }
        if(now>max){
            max=now;
        }
    }
    if(max<=1){
        cout<<"Talking Forever!";
        return 0;
    }
    cout<< max+1;
    return 0;
}
