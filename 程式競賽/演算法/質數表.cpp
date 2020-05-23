#include<bits/stdc++.h>
using namespace std;
int MAX = 0;
bool s[100000000] = {};
vector<int> ve;
int prime(){
    for(int i = 2 ; i <= MAX ; i++){
        if(s[i])continue;
        int tmp = 2;
        ve.push_back(i);
        while(tmp * i <= MAX){
            s[tmp * i] = 1;
            tmp++;
        }
    }
}
int main(){
    cin >> MAX;
    prime();
    for(auto i : ve){
        cout << i << ' ' ;
    }
    return 0;
}
