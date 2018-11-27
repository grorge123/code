#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int a[100];
vector<int >v;

int getid(int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }

    sort(v.begin(),v.end());
    cout << *unique(v.begin(),v.end())<<endl;
    v.erase(unique(v.begin(),v.end()) ,v.end());
    for(int i=0;i<(int)v.size();i++)
        printf("%d ",v[i]);
    printf("\n");

    for(int i=1;i<=n;i++)
    {
        printf("%d ",getid(a[i]));
    }
}
