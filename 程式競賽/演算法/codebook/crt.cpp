#include <bits/stdc++.h>
#define PII pair<int,int>
#define mp make_pair
#define X first
#define Y second
using namespace std;
PII extgcd(int a,int b){
	if(b==0) return mp(1,0);
	int p;
	PII q;
	p = a/b;
	q = extgcd(b,a%b);
	return mp(q.Y,q.X-q.Y*p);
}
int a[10],n[10],k;
ll crt (){
    ll i,alln,mf,ans,mi,ci;
    PII f;
    alln = 1;
    ans = 0;
    for(i=0;i<k;i++) alln *= n[i];
    for(i=0;i<k;i++){
        mi = alln/n[i];
        mf = extgcd(mi,n[i]).X; // m[i]*mf % n[i] = 1
        ci = mi*(mf % n[i]); // m[i] * (mf % n[i])
        ans= ( (ans + (a[i]*ci))%alln + alln)%alln;
    }
    return (ans==0?alln:ans);
}
int main() {
    a[0] = 4; a[1] = 5;
    n[0] = 5; n[1] = 11;
   	k = 2;
    printf("%d\n", crt());
    return 0;
}