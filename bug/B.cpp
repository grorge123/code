#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main () {
    int t,y,i=0;
    scanf("%d %d ",&t,&y);
    for(int ss=0;ss<t;ss++){
        char name[256],cl[256];
        cin.getline(name,256,'\n');
        cout << "Name: ";
        while(name[i]!=','){
            cout << name[i];
            i++;
        }
        cout << endl<<"Account: ";
        i++;
        while(name[i]!=','){
            if(name[i]>=65&&name[i]<=90){
                cout <<(char)(name[i]+32);
            }else{
                cout <<name[i];
            }
            i++;
        }
        cout << endl<<"Class: ";
        i++;
        int cla=0;
        while(name[i]!=','){
            cla*=10;
            int change=name[i]-'0';
            cla+=change;
            i++;
        }
        printf("%02d",cla);
        i++;
        cout << endl<<"Age: ";
        cla=0;
        while(i<strlen(name)){
            cla*=10;
            int change=name[i]-'0';
            cla+=change;
            i++;
        }
        cout << y-cla<<endl<<endl;
    }
  return 0;
}
