#include <bits/stdc++.h>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define ALL(x) x.begin(),x.end()
#define D double
#define ll long long
#define MS0(x) memset((x),0,sizeof((x)));
#define MS1(x) memset((x),-1,sizeof((x)));
#define pb push_back
#define LE(x) (int)((x).length())
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<D,D>
#define im guagua
#define debug 0
const double EPS = 1e-10 ;
using namespace std;
inline ll rit(){
	ll f=0,key=1;
	char c;
	do{
		c=getchar();
		if(c=='-') key=-1;
	}while(c<'0' || c>'9');
	do{
		f=f*10+c-'0';
		c=getchar();
	}while(c>='0' && c<='9');
	return f*key;
}
void init(){
}
const int Z = 1005 ;
int n,m,st,ed,k;
vector<PII> v[Z],rv[Z];
void read(){
	int i,a,b,f;
	n=rit(),m=rit();
	for(i=0;i<m;i++){
		a=rit(),b=rit(),f=rit();
		v[a].pb(mp(b,f));
		rv[b].pb(mp(a,f));
	}
	st=rit(),ed=rit(),k=rit();
}
int mk[Z],dis[Z];
struct srt{
	bool operator()(int a,int b){
		return dis[a]>dis[b];
	}
};
void dijkstra(){
	int i,f,tar,len;
	priority_queue<int,vector<int>,srt>q;
	MS0(mk);
	for(i=1;i<=n;i++) dis[i] = 2e9;
	dis[ed] = 0;
	q.push(ed);
	mk[ed] = 1;
	while(!q.empty()){
		f=q.top();
		q.pop();
		mk[f] = 0;
		for(i=0;i<(int)(rv[f].size());i++){
			tar = rv[f][i].X;
			len = rv[f][i].Y;
			if(dis[tar]>dis[f]+len){
				dis[tar] = dis[f] + len;
				if( mk[tar] == 0 ){
					mk[tar] = 1;
					q.push(tar) ;
				}
			}
		}
	}
}
struct node{
	int to,g,f;
	bool operator< (const node &a) const {
		if(a.f==f) return a.g<g;
		return a.f<f;
	}
};
int A_star(){
	node e,ne;
	int cnt = 0 ,i;
	PII f;
	priority_queue<node>q;
	if(st == ed) k++;
	if(dis[st] == 2e9) return -1;
	e.to = st;
	e.g = 0;
	e.f = e.g + dis[e.to] ;
	q.push(e);
	while(!q.empty()){
		e = q.top();
		q.pop();
		if(e.to == ed) cnt++;
		if(cnt == k) return e.g;
		for(i=0;i<(int)v[e.to].size();i++){
			f = v[e.to][i];
			ne.to = f.X;
			ne.g = e.g + f.Y;
			ne.f = ne.g + dis[ne.to];
			q.push(ne);
		}
	}
	return -1;
}
void solve(){
	dijkstra();
	cout<<A_star()<<endl;
}
int main(){
	int nn=1;
	// nn=rit();
	init();
	while(nn--){
		read();
		solve();
	}
	return 0;
}