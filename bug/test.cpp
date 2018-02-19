//http://www.tcgs.tc.edu.tw:1218/ShowProblem?problemid=h102
#include<iostream>
#include<deque>
#include<string.h>
using namespace std;
int main(){
    deque<char> vec[20005];
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            char com1[]={"pushfront"},com2[]={"pushback"},com3[]={"undo"},nowcom[8]={},w;
            cin >> nowcom>> w;
            vec[i].assign(vec[i-1].begin(),vec[i-1].end());
            if(strcmp(nowcom,com1)==0){
                vec[i].push_front(w);
            }else if(strcmp(nowcom,com2)==0){
                vec[i].push_back(w);

            }else if(strcmp(nowcom,com3)==0){
                vec[i].assign(vec[i-(w-'0')-1].begin(),vec[i-(w-'0')-1].end());

            }
            for(deque<char>::iterator it=vec[i].begin();it!=vec[i].end();it++){
                cout << *it;
            }
            cout << endl;
        }

    }
}
