#include<iostream>
#include<string.h>
using namespace std;
int main(){
    string a,b;
    getline(cin,a);
    cin >> b;
    for(int i=0;i<a.size();i++){
        for(int q=0,k=i;q<b.size();q++,k++){
//            cout << a[k]<<' '<<b[q]<<endl;
            if(a[k]!=b[q]){
                break;
            }
            if(q==b.size()-1){
                cout << i<<endl;
            }
        }
    }
    return 0;
}
