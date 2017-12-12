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
}
