#include<bits/stdc++.h>
using namespace std;
int s[10000];       // sequence
int length[10000];  // 第 x 格的值為 s[0...x] 的 LIS 長度

void LIS(int a)
{
    // 初始化。每一個數字本身就是長度為一的 LIS。
    for (int i=0; i<a; i++) length[i] = 1;

    for (int i=0; i<a; i++)
        // 找出 s[i] 後面能接上哪些數字，
        // 若是可以接，長度就增加。
        for (int j=i+1; j<a; j++)
            if (s[i] < s[j])
                length[j] = max(length[j], length[i] + 1);

    // length[] 之中最大的值即為 LIS 的長度。
    int n = 0;
    for (int i=0; i<a; i++)
        n = max(n, length[i]);
    cout << "LIS的長度是" << n;
}
int main(){
    int a;
    cin >> a;
    for(int i=0;i<a;i++){
        cin>>s[i];
    }
    LIS(a);
}
