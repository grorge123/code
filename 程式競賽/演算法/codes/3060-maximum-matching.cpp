int n;
vector<int> adj[maxn];
int pa[maxn], match[maxn], st[maxn], color[maxn], vis[maxn];
int lca(int u, int v) {
	static int t = 0;
	for (++t; ; swap(u, v)) {
		if (u == 0) continue;
		if (vis[u] == t) return u;
		vis[u] = t;
		u = st[pa[match[u]]];
	}
}
void flower(int u, int v, int l, queue<int> &q) {
	while (st[u] != l) {
		pa[u] = v;
		v = match[u];
		if (color[v] == 1)
			q.push(v), color[v] = 0;
		st[u] = st[v] = l;
		u = pa[v];
	}
}
bool augment(int u, int v) {
	for (int lst; u; v = lst, u = pa[v]) {
		lst = match[u];
		match[u] = v;
		match[v] = u;
	}
}
bool bfs(int u) {
	iota(st, n, 0);
	fill_n(color, n, -1);
	queue<int> q;
	q.push(u), color[u] = 0;
	while (!q.empty()) {
		u = q.front(), q.pop();
		for (int v : adj[u]) {
			if (color[v] == -1){
				pa[v] = u;
				color[v] = 1;
				if (!match[v]) {
					augment(u, v);
					return true;
				}
				q.push(match[v]), color[match[v]] = 0;
			} else if (!color[v] && st[v] != st[u]) {
				int l = lca(v, u);
				flower(v, u, l, q);
				flower(u, v, l, q);
			}
		}
	}
	return false;
}
int blossom() {
	fill_n(pa, n, 0);
	fill_n(match, n, 0);
	int ans = 0;
	for(int i = 0; i < n; ++i)
		if (!match[i] && bfs(i))
			++ans;
	return ans;
}
