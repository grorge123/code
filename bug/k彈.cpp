#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m,k;
    while(cin >> n>> m>> k){
        vector<int> s;
        for(int i=1;i<=n;i++){
            s.push_back(i);
        }
        int born=0;
        for(int i=0;i<k;i++){
            for(int q=1;q<m;q++){
                born++;
                born%=s.size();
            }
            s.erase (s.begin()+born);
        }
        cout <<s[born%s.size()]<<endl;
    }
}
