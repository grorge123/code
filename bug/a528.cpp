#include<stdio.h>#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main() {
    int a,cont=0;
    while ( cin >> a){
        char d[1005][105]={};
        int s[1005][105]={};
        for(int ss=0;ss<a;ss++){
            cin >> d[ss];
        }
        for(int i=0;i<1005;i++){
            for(int q=0;q<105;q++){
                s[i][q]=d[i][q]-'0';
            }
        }
        for(int i=0;i<a;i++){
            for(int q=0;q<a-1;q++){
                int a=strlen(d[q]),b=strlen(d[q+1]);
                if(d[q+1][0]!='-'&&d[q][0]!='-'){
                    if(a>b){
                        swap(s[q],s[q+1]);
                        swap(d[q],d[q+1]);
                    }
                    if(a==b){
                        for(int sd=a;sd>-1;sd--){
                            if(s[q][sd]>s[q+1][sd]){
                        swap(s[q],s[q+1]);
                        swap(d[q],d[q+1]);
                            }
                        }
                    }
                }else if(d[q+1][0]=='-'&&d[q][0]!='-'){
                        swap(s[q],s[q+1]);
                        swap(d[q],d[q+1]);
                }else if(d[q+1][0]=='-'&&d[q][0]=='-'){
                    if(a<b){
                        swap(s[q],s[q+1]);
                        swap(d[q],d[q+1]);
                    }
                    if(a==b){
                        for(int sd=a;sd>-1;sd--){
                            if(s[q][sd]<s[q+1][sd]){
                        swap(s[q],s[q+1]);
                        swap(d[q],d[q+1]);
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<a;i++){
            cout << d[i]<<endl;
        }
    }
}
