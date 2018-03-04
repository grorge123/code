#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin >> n;
    list<int> li;
    for(int i=0;i<n;i++){
        li.push_back(i+1);
    }
    cin >> t;
    while(t--){
        int a,b;
        cin >> a>> b;
        switch (a){
        case 0:
            for(list<int>::iterator it=li.begin();it!=li.end();it++){
                if(*it==b){
                    li.erase(it);
                    break;
                }
            }
            break;
        case 1:
            for(list<int>::iterator it=li.begin();it!=li.end();it++){
                if(*it==b){
                    if(*it==*li.begin())break;
                    list<int>::iterator it2=it;
                    it2--;
                    int change=*it;
                    *it=*it2;
                    *it2=change;
                    break;
                }
            }
            break;
        }
//        for(list<int>::iterator it=li.begin();it!=li.end();it++){
//            cout << *it<<" ";
//        }
    }
    int fi=0;
    for(list<int>::iterator it=li.begin();it!=li.end();it++){
        if(fi)
            cout <<" "<< *it;
        else{
            cout << *it;
            fi=1;
        }
    }
    cout << endl;

}
