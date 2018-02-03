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
    int n,m,q,s[2001][2001]={};
    cin >> n>>m>>q;
    for(int i=0;i<q;i++){
        int com,c,x,y,r;
        cin >> com;
        if(com==1){
            cin >> c>>x;
            for(int i=1;i<=m;i++){
                s[x][i]=c;
                s[x+1][i]=c;
                s[x-1][i]=c;
            }
        }
        if(com==2){
            cin >> c>>y;
            for(int i=1;i<=n;i++){
                s[i][y]=c;
                s[i][y+1]=c;
                s[i][y-1]=c;
            }
        }
        if(com==3){
            cin >> c>> x>>y>>r;
            for(int i=-r;i<=r;i++){
                for(int q=-r;q<=r;q++){
                    if((x-x+i)*(x-x+i)+(y-y+q)*(y-y+q)<=r*r){
                        s[x+i][y+q]=c;
                    }
                }
            }
        }
    }
//    for(int i=1;i<=n;i++){
//        for(int d=1;d<=m;d++){
//            cout<< s[i][d];
//        }
//    cout<<endl;
//    }
    int b=0,r=0,no=0;
    for(int i=1;i<=n;i++){
        for(int d=1;d<=m;d++){
            if(s[i][d]==1)b++;
            if(s[i][d]==2)r++;
            if(s[i][d]==0)no++;
        }
    }
    cout << b<<" "<<r<<" "<<no;
    return 0;
}
