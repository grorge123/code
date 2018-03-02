//cout 改printf UVA才會過
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
    long long int n;
    while(scanf("%d", &n) != EOF){
        string s;
        for(int i=0;i<n;i++){
            cin >> s;
            sort(s.begin(),s.end());
            do{
                cout << s<<endl;
            }while(next_permutation(s.begin(),s.end()));
            cout << endl;
        }
    }
    return 0;
}
