#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,s[10005];
        cin >> n;
        stack<int> st;
        list<int> ve;
        for(int i=0;i<n;i++){
            cin >> s[i];
            ve.push_back(i+1);
        }
        int en=0,i=0;
        while(i<n){
//            cout << "目標"<<s[i]<<" ";
//            for(list<int>::iterator it=ve.begin();it!=ve.end();it++)
//                cout << *it<<" ";
//            cout << endl;
            int old=i;
            for(list<int>::iterator it=ve.begin();it!=ve.end();it++){
                if(*it>s[i]){
                    en=1;
                    break;
                }
                if(*it<s[i]){
                    st.push(*it);
                    ve.erase(it);
                    it=ve.begin();
                    it--;
                    continue;
                }
                if(*it==s[i]){
                    i++;
                    ve.erase(it);
                    break;
                }
            }
            if(st.size()!=0&&st.top()==s[i]){
                i++;
                en=0;
                st.pop();
            }
            if(old==i){
                en=1;
                break;
            }
        }
        if(en==1)
            cout << "No"<<endl;
        else
            cout << "Yes"<<endl;
    }
}
