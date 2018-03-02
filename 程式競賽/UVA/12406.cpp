#include<bits/stdc++.h>
using namespace std;
#define LL long long
char s[25];
LL int pwn(int a,int b){
    LL int ans=1,base=a;
    while(b){
        if(b%2!=0)
            ans*=base;
        base*=base;
        b/=2;
    }
    return ans;
}
LL int fi=0,ma=0,mi=1e9;
void dfs(int li,int p,int deep){
    for(int i=1;i<=2;i++){
        s[deep]=i+'0';
        if(deep==p-1){
            LL int all=0,d=1;
            for(int q=0;q<=deep;q++){
                all=all*d+(s[q]-'0');
                d=10;
            }
            if(all%li==0){
                fi=1;
                ma=max(ma,all);
                mi=min(mi,all);
            }
        }else{
            dfs(li,p,deep+1);
        }
    }
}
int main(){
    int n,n2;
    memset(s,0,sizeof(s));
    cin >> n;
    n2=n;
    while(n--){
    fi=0;
    ma=0,mi=1e18;
    int p,q;
    cin >> p>>q;
    cout << "Case "<<n2-n<<":";
    dfs(pwn(2,q),p,0);
    if(fi==0){
        cout <<" impossible";
    }else if(mi==ma){
        cout << " "<<ma;
    }else{
        cout << " "<<mi<<" "<<ma;
    }
    cout << endl;
    }
}
