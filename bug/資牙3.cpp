#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,s[10005];
        cin >> n;
        stack<int> st;
        vector<int> ve;
        for(int i=0;i<n;i++){
            cin >> s[i];
            ve.push_back(i+1);
        }
        int en=0,i=0;
        while(i<n){
//            cout << "¥Ø¼Ð"<<s[i]<<" ";
//            for(int q=0;q<ve.size();q++)
//                cout << ve[q]<<" ";
//            cout << endl;
            int old=i;
            for(int q=0;q<ve.size();q++){
                if(ve[q]>s[i]){
                    en=1;
                    break;
                }
                if(ve[q]<s[i]){
                    st.push(ve[q]);
                    ve.erase(ve.begin()+q);
                    q=-1;
                }
                if(ve[q]==s[i]){
                    i++;
                    ve.erase(ve.begin()+q);
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
