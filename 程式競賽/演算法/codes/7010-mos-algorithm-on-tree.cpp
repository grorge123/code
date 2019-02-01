constexpr int MAX_N = 50000 + 10;
constexpr int MAX_M = 50000 + 10;
constexpr int MAX_LOG_N = 17 + 1;
constexpr int MAX_SQRT_N = 1000 + 10;
int bk[MAX_N];
struct Query {
	int id, x, y, t;
	Query() {}
	Query(int id0, int x0, int y0, int t0): id(id0), x(x0), y(y0), t(t0) {}
	bool operator < (const Query &rhs) const {
		return bk[x] != bk[rhs.x] ? bk[x] < bk[rhs.x] : bk[y] != bk[rhs.y] ? bk[y] < bk[rhs.y] : t < rhs.t;
	}
};
struct Modify {
	int p, v, pre_v;
	Modify() {}
	Modify(int p0, int v0, int pre_v0): p(p0), v(v0), pre_v(pre_v0) {}
};
stack<int> stk;
vector<Query> qs;
vector<Modify> ms;
vector<int> G[MAX_N];
int depth[MAX_N], dfn[MAX_N], dfs_clock, N, bk_cnt, pre_v[MAX_N], A[MAX_N], cnt[MAX_N], ans[MAX_M], state[MAX_N], anc[MAX_N][MAX_LOG_N], bk_sz, bk_sz2, bk2[MAX_SQRT_N];
int dfs(int u) {
	int sz = 0;
	dfn[u] = ++dfs_clock;
	for (int i = 1; i < MAX_LOG_N; i++) {
		if (depth[u] < (1 << i))
			break;
		anc[u][i] = anc[anc[u][i-1]][i-1];
	}
	REP(i, SZ(G[u])) {
		int v = G[u][i];
		if (v == anc[u][0]) continue;
		depth[v] = depth[u] + 1;
		anc[v][0] = u;
		sz += dfs(v);
		if (sz >= bk_sz) {
			bk_cnt++;
			while (sz--) {
				int x = stk.top();
				stk.pop();
				bk[x] = bk_cnt;
			}
			sz = 0;
		}
	}
	stk.push(u);
	return sz + 1;
}
int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	int t = depth[u] - depth[v];
	for (int i = MAX_LOG_N - 1; i >= 0; i--) {
		if (t&(1<<i)) u = anc[u][i];
	}
	for (int i = MAX_LOG_N - 1; i >= 0; i--) {
		if (anc[u][i] != anc[v][i]) {
			u = anc[u][i];
			v = anc[v][i];
		}
	}
	return (u == v) ? u : anc[u][0];
}
void reverse(int u) {
	if (state[u]) {
		if (A[u] <= N && !--cnt[A[u]])
			bk2[A[u] / bk_sz2]--;
	} else {
		if (A[u] <= N && !cnt[A[u]]++)
			bk2[A[u] / bk_sz2]++;
	}
	state[u] ^= 1;
}
void change(int u, int x) {
	if (state[u]) {
		reverse(u);
		A[u] = x;
		reverse(u);
	} else
		A[u] = x;
}
void solve(int u, int v) {
	while (u != v) {
		if (depth[u] > depth[v]) {
			reverse(u);
			u = anc[u][0];
		} else {
			reverse(v);
			v = anc[v][0];
		}
	}
}
int get_mex() {
	for (int i = 0; ; i++)
		if (bk2[i] != bk_sz2)
			for (int j = 0; j < bk_sz2; j++)
				if (!cnt[bk_sz2 * i + j])
					return bk_sz2 * i + j;
}
int main() {
	int M;
	scanf("%d%d", &N, &M);
	bk_sz = (int) pow((double) N, 2.0 / 3.0);
	bk_sz2 = (int) sqrt((double) N);
	REP1 (i, 1, N) {
		scanf("%d",&A[i]);
		pre_v[i] = A[i];
	}
	REP (i, N - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].PB(y);
		G[y].PB(x);
	}
	dfs(1);
	while (!stk.empty()) {
		int x = stk.top();
		stk.pop();
		bk[x] = bk_cnt;
	}
	for (int i = 0; i < M; i++) {
		int op, a, b;
		scanf("%d%d%d", &op, &a, &b);
		if (op == 0) {
			ms.PB(Modify(a, b, pre_v[a]));
			pre_v[a] = b;
		} else {
			if (dfn[a] > dfn[b]) swap(a, b);
			qs.PB(Query(SZ(qs), a, b, SZ(ms) - 1));
		}
	}
	if (qs.empty()) return 0;
	sort(ALL(qs));
	for (int i = 0; i <= qs[0].t; i++)
		change(ms[i].p, ms[i].v);
	solve(qs[0].x, qs[0].y);
	int t = lca(qs[0].x, qs[0].y);
	reverse(t);
	ans[qs[0].id] = get_mex();
	reverse(t);
	for (int i = 1; i < (int) qs.size(); i++) {
		for (int j = qs[i-1].t + 1; j <= qs[i].t; j++)
			change(ms[j].p, ms[j].v);
		for (int j = qs[i-1].t; j > qs[i].t; j--)
			change(ms[j].p, ms[j].pre_v);
		solve(qs[i-1].x, qs[i].x);
		solve(qs[i-1].y, qs[i].y);
		t = lca(qs[i].x, qs[i].y);
		reverse(t);
		ans[qs[i].id] = get_mex();
		reverse(t);
	}
	REP (i, SZ(qs)) printf("%d\n", ans[i]);
	return 0;
}
