int pre[Z],dis[Z],mk[Z],st;
int SPFA(){
	queue<int> q;
	int i,u,v;
	for(i=0;i<=vertex;i++){
		dis[i] = 2e9;
		pre[i] = -1;
		mk[i] = 0;
	}
	dis[ st ] = 0;
	q.push(st);
	mk[st] = 1;
	while(!q.empty()){
		u = q.front();
		q.pop();
		mk[f] = 0;
		for(i=0;i<=vertex;i++){
			v=i;
			if(G[u][v].c_f==0) continue;
			if(G[u][v].v==2e9){
				G[u][v].v = -G[v][u].v;
			}
			if(dis[v]>dis[u]+G[u][V].v){
				dis[v] = dis[u]+G[u][v].v;
				pre[v] = u;
				if(!mk[v]){
					mk[v]=1;
					q.push(v);
				}
			}
		}
	}
}