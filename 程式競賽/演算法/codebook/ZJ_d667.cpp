#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int wid[105][105],usd[105][105],v[105],pre[105];
queue<int> q;
int main(){
	int n,st,ed,m,a,b,f,i,r=1,ans;
	while(cin>>n&&n!=0){
		cin>>st>>ed>>m;
		memset(wid,0,sizeof(wid));
		memset(usd,0,sizeof(usd));
		for(i=0;i<m;i++){
			cin>>a>>b>>f;
			wid[a][b]+=f;
			wid[b][a]+=f;
		}
		ans=0;
		while(1){
			memset(v,0,sizeof(v));
			v[st]=2147483647;
			q.push(st);
			while(!q.empty()){
				for(i=1;i<=n;i++){
					if( !v[i] && wid[q.front()][i]>usd[q.front()][i]){
						pre[i]=q.front();
						v[i]=min(v[q.front()],wid[q.front()][i]-usd[q.front()][i]);
						q.push(i);
					}
				}
				q.pop();
			}
			if(v[ed]==0) break;
			for(i=ed;i!=st;i=pre[i]){
				usd[pre[i]][i]+=v[ed];
				usd[i][pre[i]]-=v[ed];
			}
			ans+=v[ed];
		}
		cout<<"Network "<<r++<<endl;
		cout<<"The bandwidth is "<<ans<<'.'<<endl;
	}
	return 0;
}
// from 1 to n