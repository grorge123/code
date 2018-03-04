#include<bits/stdc++.h>
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
        list<teq> li;
        for(int i=0;i<n;i++){
            int k;
            cin >> k;
            for(int q=0;q<k;q++){
                int a;
                 cin >> a;
                 s[a]=i+1;
            }
        }
        string cmd;
        cout <<"Line #"<< cont+1<<endl;
        while(cin >>cmd ){
            if(cmd=="STOP")break;
            if(cmd=="ENQUEUE"){
                int a,fi=0;
                cin >> a;
                for(list<teq>::iterator it=li.begin();it!=li.end();it++){
                    if(s[a]!=0&&it->id==s[a]){
                        it->qu.push(a);
                        fi=1;
                        break;
                    }
                }
                if(!fi){
                    teq now;
                    now.id=s[a];
                    now.qu.push(a);
                    li.push_back(now);
                }
            }
            if(cmd=="DEQUEUE"){
                cout << li.begin()->qu.front()<<endl;
                li.begin()->qu.pop();
                if(li.begin()->qu.size()==0)li.pop_front();
            }
        }
        cont++;
    }
}
