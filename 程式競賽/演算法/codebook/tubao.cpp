#include<iostream>
#include<vector>
#include<stdio.h>
#include<utility>
#define X first
#define Y second
#define mp make_pair
#define PII pair<int,int>
#define ALL(x) (x).begin(), (x).end() 
using namespace std;
bool operator^(const PII& a,const PII& b){
	return a.X*b.Y - a.Y*b.X <= 0;
}
PII operator-( const PII& a,const PII& b){
	return mp( a.X-b.X , a.Y-b.Y );
}
vector<int> t;
int p[N];
void do_tubao(){
	int i,fsz;
	sort(ALL(p));
	int sz=0;
	for( i=0; i<n; i++ ){
		while(sz>1 && ((t[sz-1]-t[sz-2])^(p[i]-t[sz-1])) ) t.pop_back(), sz--;
		t.pb(p[i]),sz++;
	}
	fsz=sz;
	for( i=n-1; i>=0; i-- ){
		while(sz-fsz>0 && ((t[sz-1]-t[sz-2])^(p[i]-t[sz-1])) ) t.pop_back(), sz--;
		t.pb(p[i]),sz++;
	}
}

