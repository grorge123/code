int par[maxn], sz[maxn];
vector<pair<int*, int>> h;
vector<int> sp;
void init(int n) {
	iota(par, par + n, 0);
	fill_n(sz, n, 1);
	sp.clear();
	h.clear();
}
void assign(int *k, int v) {
	h.emplace_back(k, *k);
	*k = v;
}
void save() {
	sp.push_back(h.size());
}
void undo() {
	while (h.size() != sp.back()) {
		auto x = h.back();
		h.pop_back();
		*x.first = x.second;
	}
	sp.pop_back();
}
int find(int x) {
	while (x != par[x])
		x = par[x];
	return x;
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		if (sz[x] < sz[y])
			swap(x, y);
		assign(sz + x, sz[x] + sz[y]);
		assign(par + y, x);
	}
}
