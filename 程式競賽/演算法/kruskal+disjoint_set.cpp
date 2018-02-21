#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#define F first
#define S second
using namespace std;
int fa[105];
struct line{
    string a,b;
    int val;
};
vector<pair<string,string> > ans;
map<string,int> ci;
bool linesort(line a,line b){
    return a.val<b.val;
}
bool anssort(pair<string,string> a,pair<string,string> b){
    if(ci[a.F]!=ci[b.F])
        return ci[a.F]<ci[b.F];
    return ci[a.S]<ci[b.S];
}
int far(int x){
    if(fa[x]==x)return x;
    fa[x]=far(fa[x]);
    return fa[x];
}
bool checkfa(int n){
    for(int i=1;i<n;i++){
        if(far(i)!=far(i-1))
            return true;
    }
    return false;
}
bool fifa(string a,string b){
//    cout<<"fifa:"<< fa[ci[a]]<<" "<<fa[ci[b]]<<endl;
    if(far(ci[a])==far(ci[b])){
        return false;
    }
    return true;
}
void printfa(int n){
    for(int i=1;i<=n;i++){
        for(int q=0;q<=n;q++){
            if(fa[q]==i)
                cout<< q<<" ";
        }
        cout<<endl;
    }
}
void adfa(int a,int b){
    if(far(a)!=far(b)){
        fa[far(a)]=far(b);
    }
}
int main(){
    int n,m;
    line s[105];
    cin >>n>>m;
    for(int i=0;i<n;i++){
        string na;
        cin >> na;
        ci.insert(pair<string,int>(na,i+1));
    }
    for(int i=0;i<m;i++){
        cin >> s[i].a>>s[i].b>>s[i].val;
    }
    for(int i=0;i<=n;i++){
        fa[i]=i;
    }
    sort(s,s+m,linesort);
//    for(int i=0;i<m;i++){
//        cout<<s[i].a<<" "<<s[i].b<<" "<<s[i].val<<endl;
//    }
    int q=0,all=0;
        for(;q<m;q++){
            if(fifa(s[q].a,s[q].b)){
//                printfa(n);
                all+=s[q].val;
                adfa(ci[s[q].a],ci[s[q].b]);
                ans.push_back(pair<string,string>(s[q].a,s[q].b));
//                cout<<s[q].a<<" "<<s[q].b<<endl;
            }
        }
    sort(ans.begin(),ans.end(),anssort);
    for(vector<pair<string,string> >::iterator it=ans.begin();it!=ans.end();it++){
        cout<< "("<<it->F<<" "<<it->S<<")";
    }
    cout<< endl<<all;
}
