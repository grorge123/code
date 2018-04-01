#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
struct abc{
    double a,b,c;
};
double F(double a,double b,double c,double t){
    return a*((t-b)*(t-b))+c;
}
bool check(abc s[],double *l,double l2,double r2,double *r,int n){
    double sl[15]={},sr[15]={},sl2[15]={},sr2[15]={};
    for(int i=0;i<n;i++){
        sl[i]=(F(s[i].a,s[i].b,s[i].c,*l));
        sl2[i]=(F(s[i].a,s[i].b,s[i].c,l2));
        sr2[i]=(F(s[i].a,s[i].b,s[i].c,r2));
        sr[i]=(F(s[i].a,s[i].b,s[i].c,*r));
    }
    sort(sl,sl+n,greater<double>());
    sort(sl2,sl2+n,greater<double>());
    sort(sr2,sr2+n,greater<double>());
    sort(sr,sr+n,greater<double>());
    double asl=sl[0],asl2=sl2[0],asr2=sr2[0],asr=sr[0];
//    cout <<" "<< asl<<" "<<asl2<<" "<<asr2<<" "<<asr<<endl;
    if(asl<asl2&&asl2<asr2&&asr2<asr){
        *r=l2;
    }else if(asl>=asl2&&asl2<=asr2&&asr2<=asr){
        *r=r2;
    }else if(asl>=asl2&&asl2>=asr2&&asr2<=asr){
        *l=l2;
    }else if(asl>=asl2&&asl2>=asr2&&asr2>=asr){
        *l=r2;
    }
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        abc s[15];
        for(int i=0;i<n;i++){
            cin >> s[i].a>>s[i].b>>s[i].c;
        }
        double l=0,r=300;
        while(l<r&&r-l>0.0000000001){
            double l2=l+(r-l)/3,r2=l+(r-l)/3*2;
//            cout << l<<" "<<l2<<" "<<r2<<" "<<r<<endl;
            check(s,&l,l2,r2,&r,n);
        }
        double ans=0;
        for(int i=0;i<n;i++){
            if(ans<F(s[i].a,s[i].b,s[i].c,l)){
                ans=F(s[i].a,s[i].b,s[i].c,l);
            }
        }
//        cout << setprecision(6)<< ans<<'\n';
        printf("%.5f\n",ans);
    }
}
