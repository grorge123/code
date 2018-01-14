<<<<<<< HEAD
# include <stdio.h>
#include<iostream>
using namespace std;

int main() {
        int a;
        cout << (int)'#' << endl;
        while ( scanf( "%d", &a) == 1 ){
            char s[a][a];
            for(int i=0;i<a;i++){
                for(int q=0;q<a;q++){
                    cin >> s[i][q];
                }
            }
            s[1][1]=1;
            int cont =1,end=0,stop=0;
            while(true){
                for(int i=0;i<a;i++){
                    for(int q=0;q<a;q++){
                        if(s[a-2][a-2]!='.'){
                            cout << (int)s[a-2][a-2]<<endl;
                            end=1;
                            break;
                        }
                        if(s[i][q]==cont){
                            if(s[i][q+1]=='.')s[i][q+1]=cont+1;
                            if(s[i][q-1]=='.')s[i][q+1]=cont+1;
                            if(s[i+1][q]=='.')s[i+1][q]=cont+1;
                            if(s[i-1][q]=='.')s[i-1][q]=cont+1;
                            stop=1;
                        }
                    }
                    if(end==1)
                        break;
                }
                cont++;
                if(stop==0){
                    cout << "No solution!"<<endl;
                    end=1;
                }else{
                stop=0;
                }
                if(end==1)
                    break;
            }
		}
=======
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector <int> lis[10005];
int nr[10005]={},wr[10005]={},n[10005]={},maxn=0;
void dfs(int index,int deep){
//    cout << "dfs"<<lis[index].size()<<endl;
    for(int i=0;i<lis[index].size();i++){
//      cout << "dfs:"<<nr[lis[index][i]]<<" "<<index<<" "<<i<<endl;
        if(nr[lis[index][i]]==0){
//          cout <<"dfs:"<<index<<" "<<lis[index][i]<<endl;
//            cout <<"dfs:"<<nr[lis[index][i]]<<" "<<index<<" "<<i<<" "<<lis[index][i]<<" "<<deep<<endl;
//          nr[lis[index][i]]=1;
            nr[index]=1;
            deep++;
            dfs(lis[index][i],deep);
            if(deep>maxn)
                maxn=deep;
            deep--;
        }
    }
}
void adfs(int al,int maxn){
    for(int i=0;i<al;i++){
        if(wr[i]==1){
//            cout << "adfs:"<<i<<endl;
            dfs(i,0);
            memset(nr,0,sizeof(nr));
        }
    }
}
int main(){
    int al;
    while(cin >> al){
        maxn=0;
        memset(nr,0,sizeof(nr));
        memset(wr,0,sizeof(wr));
        memset(n,0,sizeof(n));
        int co=0;
        while(!lis[co].empty()){
            lis[co].clear();
            co++;
        }
        for(int i=0;i<al-1;i++){
            int x,y;
            cin >> x >> y;
            n[x]++;
            n[y]++;
            n[x]==1?wr[x]=1:wr[x]=0;
            n[y]==1?wr[y]=1:wr[y]=0;
            lis[x].push_back(y);
            lis[y].push_back(x);
        }
//        for(int i=0;i<al;i++){
//            for(int q=0;q<lis[i].size();q++){
//                cout << lis[i][q];
//            }
//            cout << endl;
//        }
//        for(int i=0;i<al;i++){
//            cout << wr[i];
//        }
//        cout << endl;
        adfs(al,maxn);
        cout << maxn<<endl;
    }
>>>>>>> 5340275359c1b86cf38b1b06bf279548eed1ee11
}
