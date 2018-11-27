#include<string.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int Max=200005;
int m[Max*4];
int build(int id,int l,int r){
    if(l==r){
        scanf("%d",&m[id]);
        return m[id];
    }
    build(id*2,l,(l+r)/2);
    build(id*2+1,(l+r)/2+1,r);
    m[id]=max(m[id*2],m[id*2+1]);
//    cout << l<<" "<<r<<" "<<id<<" "<<m[id]<<endl;
    return m[id];
}
int query(int will,int id,int l,int r){
    if(l==r){
        return m[id];
    }
    int m=(l+r)/2;
    if(will>m){
        return query(will,id*2+1,m+1,r);
    }else{
        return query(will,id*2,l,m);
    }
}
int query_line(int L,int R,int id,int l,int r){
//    cout << l<<" "<<r<<" "<<m[id]<<endl;
    if(L<=l&&R>=r){
//        cout << l<<" "<<r<<endl;
        return m[id];
    }
    int m2=(l+r)/2;
    int Ma=-1e9;
    if(m2>=L) Ma=max(Ma,query_line(L,R,id*2,l,m2));
    if(m2<R) Ma=max(query_line(L,R,id*2+1,m2+1,r),Ma);
    return Ma;

}
int update(int id,int l,int r,int will,int wid){
    if(l==r){
        m[id]=wid;
        return wid;
    }
    int m2=(l+r)/2;
    if(m2>=will){
        m[id]=max(update(id*2,l,m2,will,wid),m[id*2+1]);
    }else{
        m[id]=max(update(id*2+1,m2+1,r,will,wid),m[id*2]);
    }
    return m[id];
}
int main(){
    int n,m2;
    while(scanf("%d %d",&n,&m2)==2){
//        memset(m,0,sizeof(m));
        build(1,1,n);
        for(int i=0;i<m2;i++){
            char a;
            int b,c;
            scanf(" %c %d %d",&a,&b,&c);
            if(a=='Q'){
                printf("%d\n",query_line(b,c,1,1,n));
            }else if(a=='U'){
                update(1,1,n,b,c);
            }

        }
    }

}
