#include<bits/stdc++.h>
using namespace std;
#define MA 1000005
struct peo{
    int gr,num;
};
peo s[MA];
int main(){
    int n,cont=1;
    while(cin >> n){
        list<peo> ve;
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++){
            int k;
            cin >> k;
            for(int q=0;q<k;q++){
                int a;
                cin >> a;
                s[a].num=a;
                s[a].gr=i;
            }
        }
        char cmd[50],STOP[]={"STOP"},ENQ[]={"ENQUEUE"},DEQ[]{"DEQUEUE"};
        cout << "Line #"<<cont<<endl;
        while(true){
            cin >> cmd;
            if(!strcmp(cmd,STOP))break;
            if(!strcmp(cmd,ENQ)){
                int a;
                cin >> a;
                if(ve.empty()){
                    s[a].num=a;
                    ve.push_back(s[a]);
                    continue;
                }
                int in=0;
                for(list<peo>::iterator it=ve.begin();it!=(ve.end()--);it++){
                    list<peo>::iterator it2=it;
                    it2++;
                    if(it->gr!=0&&s[a].gr==it->gr&&s[a].gr!=it2->gr){
                        ve.insert(it2,s[a]);
                        in=1;
                        break;
                    }
                }
                if(!in){
//                    cout << s[a].num<<" "<<s[a].gr;
                    s[a].num=a;
                    ve.push_back(s[a]);
                }
            }
            if(!strcmp(cmd,DEQ)){
                cout << ve.front().num <<endl;
                ve.pop_front();
            }
//            for(list<peo>::iterator it=ve.begin();it!=ve.end();it++){
//                cout << it->num<<" ";
//            }
//            cout << endl;
        }
        cont++;
    }
}
