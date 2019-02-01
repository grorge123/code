int nl, nr, pre[maxn], mx[maxn], my[maxn];
ll slack[maxn], w[maxn][maxn], lx[maxn], ly[maxn];
bool vx[maxn], vy[maxn];
void augment(int u) {
	if (!u) return;
	augment(mx[pre[u]]);
	mx[pre[u]] = u;
	my[u] = pre[u];
}
void match(int x) {
	queue<int> que;
	que.push(x);
	while (true) {
		while (!que.empty()) {
			x = que.front();
			que.pop();
			vx[x] = 1;
			for (int y = 0; y < nr; y++) {
				if (vy[y]) continue;
				ll t = lx[x] + ly[y] - w[x][y];
				if (t > 0) {
					if (slack[y] >= t)
						slack[y] = t, pre[y] = x;
					continue;
				}
				pre[y] = x;
				if (!my[y]) {
					augment(y);
					return;
				}
				vy[y] = 1;
				que.push(my[y]);
			}
		}
		ll t = inf;
		for (int y = 0; y < nr; y++)
			if (!vy[y])
				t = min(t, slack[y]);
		for (int x = 0; x < nl; x++)
			if (vx[x])
				lx[x] -= t;
		for (int y = 0; y < nr; y++) {
			if (vy[y]) ly[y] += t;
			else slack[y] -= t;
		}
		for (int y = 0; y < nr; y++) {
			if (vy[y] || slack[y]) continue;
			if (!my[y]) {
				augment(y);
				return;
			}
			vy[y] = 1;
			que.push(my[y]);
		}
	}
}
int main() {
	for(int i = 0; i < nl; i++)
		lx[i] = *max_element(w[i], w[i] + nr);
	for(int i = 0; i < nl; i++) {
		fill_n(vx, nl, 0);
		fill_n(vy, nr, 0);
		fill_n(slack, nr, inf);	
		match(i);
	}
}
