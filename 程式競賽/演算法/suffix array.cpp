#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pii pair<int,int>
const int INF = 2147483647;
int SA[100005] = {},ranking[100005] = {};
bool cmp(int first[],int second[],int n){
    for(int i = 0 ; i < n ; i++){
        if(first[i] != second[i])
            return false;
    }
    return true;
}
int string_cmp(string a,string b){
    for(int i = 0 ; i < min(a.size(),b.size()) ; i++){
        if(a[i] != b[i]){
            return a[i] > b[i] ? 1 : -1;
        }
    }
    if(b.size() <= a.size())
        return 0;
    else
        return 1;
}
void suffix(string s){
    vector<int> eng[300];
    for(int i = 0 ; i < s.size() ; i++){
        eng[s[i]].push_back(i);
    }
    pii tmp[100005] = {};
    int second[100005] = {},first[100005],n = 1;
    for(int i = 0 ; i < 300 ; i++){
        if(eng[i].size()){
            for(int q = 0 ; q < eng[i].size() ; q++){
                first[eng[i][q]] = n;
            }
            n++;
        }
    }
    int now = 1;
    while(!cmp(first,second,s.size())){
        for(int i = 0 ; i < s.size() ; i++){
            if(i + now < s.size()){
                tmp[i].F = first[i] * 10 + first[i + now];
            }else{
                tmp[i].F = first[i] * 10;
            }
            tmp[i].S = i;
        }
        sort(tmp,tmp + s.size());
        second[tmp[0].S] = 1;
        for(int i = 1 ; i < s.size() ; i++){
            if(tmp[i].F == tmp[i - 1].F)
                second[tmp[i].S] = second[tmp[i - 1].S];
            else
                second[tmp[i].S] = second[tmp[i - 1].S] + 1 ;
        }
        for(int i = 0 ; i < s.size() ; i++){
            if(i + now < s.size()){
                tmp[i].F = second[i] * 10 + second[i + now];
            }else{
                tmp[i].F = second[i] * 10;
            }
            tmp[i].S = i;
        }
        sort(tmp,tmp + s.size());
        first[tmp[0].S] = 1;
        for(int i = 1 ; i < s.size() ; i++){
            if(tmp[i].F == tmp[i - 1].F)
                first[tmp[i].S] = first[tmp[i - 1].S];
            else
                first[tmp[i].S] = first[tmp[i - 1].S] + 1;
        }
    }
    for(int i = 0 ; i < s.size() ; i++){
        ranking[i] = first[i] - 1;
    }
    for(int i = 0 ; i < s.size() ; i++){
        SA[ranking[i]] = i;
    }
}
int main(){
    string s;
    int n;
    cin >> s;
    n = 1;
    suffix(s);
    for(int i = 0 ; i < s.size() ; i++){
        cout << SA[i] << ' ' ;
    }
    cout << endl;
    cout << string_cmp("nana","na") << endl;
    for(int i = 0 ; i < n ; i++){
        string a;
        cin >> a;
        int fi = INF,se = INF,l = 0,r = s.size();
        while(l <= r){
            int m = (l+r)/2;
            string sm(s.begin() + SA[m],s.end());
            int result = string_cmp(sm,a);
            if(result == 0){
                fi = m;
                r = m - 1;
            }else if(result == 1){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        l = 0, r = s.size();
        while(l <= r){
            int m = (l+r)/2;
            string sm(s.begin() + SA[m],s.end());
            int result = string_cmp(sm,a);
            if(result == 0){
                se = m;
                l = m + 1;
            }else if(result == 1){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        cout << fi << ' ' << se << endl;
        if(fi != INF)
            cout << se - fi +1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}


//banana
//2 1 3 1 3 1
//21 13 31 13 31 10
//
//3 2 4 2 4 1
//34 22 44 21 40 10
//
//4 3 6 2 5 1
