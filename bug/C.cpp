#include<cstring>
#include<iostream>
using namespace std;
int abs(int a){
    if(a>0)return a;
    return a*-1;
}
int main(){
    int a,index,max=0,s[100010]={},cont=0;
    cin >> a;
    for(int i=0;i<a;i++)
        cin >> s[i];
    index=a-1;
    for(int i=0;i<a;i++){
        for(int q=0;q<=index;q++){
            if(s[max]<s[q])
                max=q;
        }
//        cout << max<<endl;
        if(s[max]!=s[index]){
            swap(s[max],s[index]);
            cont+=abs(max-index);
        }
        index--;
        max=0;
    }
//    for(int i=0;i<a;i++){
//        cout << s[i];
//    }
    cout << cont<<endl;
}
