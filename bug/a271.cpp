#include <stdio.h>
#include <string.h>
#include<math.h>
#include<iostream>
using namespace std;
int main(){
    int runnumber=0;
    scanf("%d",&runnumber);
    for(int run=0;run<runnumber;run++){
        int x,y,z,w,n,m;
        char day[100];
		cin >> x >> y >> z >> w >> n >> m;
		scanf("%s",day);
        int disease=0;
        for(int i=0;i<strlen(day);i++){
            switch (day[i]){
                case 1:
                    m+=x;
                    break;
                case 2:
                    m+=y;
                    break;
                case 3:
                    m-=z;
                    break;
                case 4:
                    m-=w;
                    disease+=n;
                    break;
            }
            m-=disease;
        }
        if(m>0){
            cout << m << "g" <<endl;
        }else {
            cout << "bye~Rabbit";
        }
        cout << "firstend";
    }
}
