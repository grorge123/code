#include<bits/stdc++.h>
using namespace std;
int change(string a){
    int now = 1,re = 0;
    for(int i = a.size() - 1; i >= 0 ; i--){
        if(a[i] == '1'){
            re += now;
        }
        now *= 2;
    }
    return re;
}
int main(){
    int n;
    while(cin >> n){
        bitset<600000> bit = 0;
        int s[105] = {};
        for(int i = 0 ; i < n ; i ++){
            string a;
            cin >> a;
            s[i] = change(a);
        }
        string a;
        cin >> a;
        int m = change(a);
        for(int i = 0 ; i < n ; i++){
            bitset<600000> tmp = bit;
            tmp[s[i]] = 1;
            bit <<= s[i];
            bit |= tmp;
        }
        if(bit[m]==1){
            cout << "YES"<<endl;
        }else{
            cout << "NO"<<endl;
        }
    }
}
