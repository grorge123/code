#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pii pair<int,int>
int s[1000005] = {};
bool visit[1000005] = {};
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
    }
    vector<pair<int,pii> > ve;
    while(true){
        int a,p;
        cin >> a ;
        if(a == 0){
            break;
        }
        cin >> p;
        if(a == 1){
            for(int i = 0 ; i < ve.size() && !visit[p]; i++){
                if(p % ve[i].F==0){
                    if(ve[i].S.F == 2){
                        s[p]&=ve[i].S.S;
                    }else if(ve[i].S.F == 3){
                        s[p]|=ve[i].S.S;
                    }else if(ve[i].S.F == 4){
                        s[p]^=ve[i].S.S;
                    }
                }
            }
            visit[p] = 1;
            cout << s[p] << endl;
            continue;
        }
        int q;
        cin >> q;
        ve.push_back(pair<int,pii>(p,pii(a,q)));
    }
    return 0;
}
