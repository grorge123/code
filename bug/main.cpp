#include<iostream>
using namespace std;
int color=2,cont=0;
int ans=1;
//int ss[10000][10000]={};
//        int d[10000]={};
void dfs(int n,int index,int *ss,int *d){
    if(d[index]==0){
        d[index]=color;
        color==2?color=1:color=2;
    }
//        for(int i=0;i<n;i++){
//            for(int q=0;q<n;q++){
//                cout << *(ss+i*n+q);
//            }
//            cout << endl;
//        }
    for(int i=0;i<n;i++){
        if(*(ss+index*n+i)==1){
                cout << d[i]<<" "<<color << " "<<d[index]<< " "<<index<<" "<<i<<" "<<endl;
            if(d[index]!=d[i]){
                if (d[i]==0){
                    dfs(n,i,ss,d);
                    }
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
            break;
        else
            cin >> m;
        color=2;
        ans=1;
        int ss[100][100]={};
        int d[10000]={};
        for(int i=0;i<m;i++){
            int x,y;
            cin >> x>>y;
            ss[x][y]=1;
        }
        for(int i=0;i<n;i++){
            for(int q=0;q<n;q++){
                cout << ss[i][q];
            }
            cout << endl;
        }
        dfs(n,0,&ss[0][0],&d[0]);
        if(ans==1){
            cout << "BICOLORABLE."<<endl;
        }else{
            cout << "NOT BICOLORABLE."<<endl;
        }
    }
}
