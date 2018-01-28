#include<bits/stdc++.h>
using namespace std;
unsigned long long int a[110]={};
int v(int i){
    if(i==1)return 1;
    if(i==2)return 2;
    if(a[i]!=0)return a[i];
    a[i]=v(i-1)+v(i-2);
    return a[i];
}
int main(){
    int i;
    while(cin >> i){
        a[1]=1;
        a[2]=2;
        cout << v(i)<<endl;
    }
}

#include <iostream>
using namespace std;
int main()
{
int i,n;

long long arr[101];
    arr[1] = 1;
    arr[2] = 2;
    for(i=3;i<100;i++)
        arr[i] = arr[i-1] + arr[i-2];
    while(cin >> i)
        cout << arr[i]<<endl;
return 0;

}
