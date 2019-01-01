#include<iostream>
#include<algorithm>
using namespace std;
int inp(){
    string s;
    cin >> s;
    if(s[0]=='n'){
        return 0;
    }
    int re=0;
    for(int i=0;i<s.size();i++){
        re*=10;
        re+=s[i]-'0';
    }
    return re;
}
int main(){
    int s[15]={};
    for(int i=0;i<12;i++){
        s[i]=inp();
    }
    sort(s,s+12,greater<int>());
    int all=0;
    for(int i=0;i<10;i++){
        all+=s[i];
    }
    int result=(double)all/10+0.5;
    if(result>=60){
        cout <<result<<endl<< "pass";
    }else{
        cout << result<<endl<<"fail";
    }
    return 0;
}
