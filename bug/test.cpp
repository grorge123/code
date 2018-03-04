#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct teq{
    int id;
    queue<int> qu;
};
int s[1000005]={};
int main(){
    int n,cont=0;
    while(cin >> n){
        memset(s,0,sizeof(s));
        vector<teq> li;
        int ran[1005];
        for(int i=0;i<n;i++){
            int k;
            cin >> k;
            for(int q=0;q<k;q++){
                int a;
                 cin >> a;
                 s[a]=i+1;
            }
            ran[i+1]=-1;
        }
        string cmd;
        int seto=0;
        cout <<"Line #"<< cont+1<<endl;
        vector<teq>::iterator out;
        int outnu=0;
        while(cin >>cmd ){
            if(cmd=="STOP")break;
            if(cmd=="ENQUEUE"){
                int a,fi=0;
                cin >> a;
//                system("pause");
//                cout << ran[s[a]]<<endl;
                if(ran[s[a]]-outnu!=-1&&s[a]!=0){
                        li[ran[s[a]]-outnu].qu.push(a);
                        fi=1;
                }
//                system("pause");
                if(!fi){
                    if(s[a]!=0){
                        ran[s[a]]=li.size();
                    }
//                    system("pause");
                    teq now;
                    now.id=s[a];
                    now.qu.push(a);
                    li.push_back(now);
                }
            }
            if(cmd=="DEQUEUE"){
                if(!seto){
                    out=li.begin();
                    seto=1;
                }
                cout << out->qu.front()<<endl;
                out->qu.pop();
                if(out->qu.size()==0){
                    li.erase(li.begin());
                    outnu++;
                }
            }
        }
        cont++;
    }
}
