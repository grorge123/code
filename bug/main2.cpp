#include<iostream>
using namespace std;
int color=2,ans=1;
//int d[300]={},s[300][300]={};
void dfs(int n,int index,int *s,int *d){
        for(int i=0;i<n;i++){
            for(int q=0;q<n;q++){
                cout << *(s+i*n+q);
            }
            cout << endl;
        }
    if(d[index]==0){
        d[index]=color;
        color==2?color=1:color=2;
    }
    for(int i=0;i<n;i++){
        if(*(s+index*n+i)==1){
//            cout << d[index]<<" "<<d[i]<<" "<<color<<endl;
            if(d[index]!=d[i]){
                if(d[i]==0)
                    dfs(n,i,s,d);
            }else{
                ans=0;
                return;
            }
        }
    }

}
int main(){
    int n,m;
    while(cin >> n){
        if(n==0)
            return 0;
        else
            cin>>m;
        int d[300]={},s[300][300]={};
        for(int i=0;i<m;i++){
            int x,y;
            cin >> x>>y;
            s[x][y]=1;
        }
        dfs(n,0,&s[0][0],&d[0]);
        if(ans==1){
            cout << "BICOLORABLE."<<endl;
        }else{
            cout << "NOT BICOLORABLE."<<endl;
        }
//        for(int i=0;i<n;i++){
//            for(int q=0;q<n;q++){
//                cout << s[i][q];
//            }
//            cout << endl;
//        }

    }

}
