#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    string a;
    cin >> a;
    vector<string> ve;
    int l=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==';'){
            ve.push_back(string(a.begin()+l,a.begin()+i));
            l=i+1;
        }
    }
    ve.push_back(string(a.begin()+l,a.end()));
    cin >> a;
    l=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==','){
            ve.push_back(string(a.begin()+l,a.begin()+i));
            l=i+1;
        }
    }
    ve.push_back(string(a.begin()+l,a.end()));
    sort(ve.begin(),ve.end(),less<string>());
    for(int i=0;i<ve.size();i++){
        if(i!=0&&ve[i]==ve[i-1]){

        }else{
            cout << ve[i]<<' ';
        }
    }
    return 0;
}
