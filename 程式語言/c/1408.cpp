#include<iostream>
using namespace std;
int main(){
    string s[5000],fi;
    cin >> fi;
    fi[0]=fi[0]+'a'-'A';
    int i=0;
    while(cin >> s[i]){
        if(s[i].size()==1&&s[i][0]=='q')break;
        i++;
    }
    for(int q=0;q<i;q++){
        if(s[q]==fi){
            cout <<"YES"<<' '<<q+1<<endl;
            return 0;
        }
    }
    cout << "NO"<<' '<<i<<endl;
}
