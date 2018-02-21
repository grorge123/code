#include<bits/stdc++.h>
using namespace std;
int s[10000];       // sequence
int length[10000];  // �� x �檺�Ȭ� s[0...x] �� LIS ����

void LIS(int a)
{
    // ��l�ơC�C�@�ӼƦr�����N�O���׬��@�� LIS�C
    for (int i=0; i<a; i++) length[i] = 1;

    for (int i=0; i<a; i++)
        // ��X s[i] �᭱�౵�W���ǼƦr�A
        // �Y�O�i�H���A���״N�W�[�C
        for (int j=i+1; j<a; j++)
            if (s[i] < s[j])
                length[j] = max(length[j], length[i] + 1);

    // length[] �����̤j���ȧY�� LIS �����סC
    int n = 0;
    for (int i=0; i<a; i++)
        n = max(n, length[i]);
    cout << "LIS�����׬O" << n;
}
int main(){
    int a;
    cin >> a;
    for(int i=0;i<a;i++){
        cin>>s[i];
    }
    LIS(a);
}
