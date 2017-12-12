# include <stdio.h>
#include<iostream>
using namespace std;

int main() {
        int a;
        while ( scanf( "%d", &a) == 1 ){
            char s[a][a];
            int d[a][a]={};
            for(int i=0;i<a;i++){
                for(int q=0;q<a;q++){
                    cin >> s[i][q];
                    if(s[i][q]=='#'){
                        d[i][q]=-1;
                    }else if(s[i][q]=='.'){
                    s[i][q]==999999999;
                    }
                }
            }
            d[1][1]=1;
            int cont =1,end=0,stop=0;
            while(true){
                for(int i=0;i<a;i++){
                    for(int q=0;q<a;q++){
                        if(d[a-2][a-2]!=0){
                            cout << d[a-2][a-2]<<endl;
                            end=1;
                            break;
                        }
                        if(d[i][q]==cont){
                            if(d[i][q+1]==0)d[i][q+1]=cont+1;
                            if(d[i][q-1]==0)d[i][q+1]=cont+1;
                            if(d[i+1][q]==0)d[i+1][q]=cont+1;
                            if(d[i-1][q]==0)d[i-1][q]=cont+1;
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
}
