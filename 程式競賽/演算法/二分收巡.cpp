#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s[1000];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    sort(s,s+n);
    int k;
    while(cin >> k){
        int l=0,r=n-1,fi=0;
        while(l<=r){
            int m=(l+r)/2;
            if(s[m]>k){
                r=m-1;
            }else if(s[m]<k){
                l=m+1;
            }else if(s[m]==k){
                fi=1;
                cout << m+1<<endl;
                break;
            }
        }
        if(fi)
            continue;
        if(s[l]!=k){
            cout << "not find"<<endl;
        }else{
            cout << s[l]<<endl;
        }
    }
}
