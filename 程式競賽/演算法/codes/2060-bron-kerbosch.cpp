int ans;
bitset<128> adj[128];
int ctz(bitset<128> x) {
	bitset<128> y = x & std::bitset<128>(~0ULL);
	if (y.any())
		return __builtin_ctzll(y.to_ullong());
	return __builtin_ctzll((x >> 64).to_ullong()) + 64;
}
void dfs(bitset<128> r, bitset<128> p, bitset<128> x) {
	ans = max(ans, (int) r.count());
	int t = r.count() + p.count();
	if (t <= ans || !p.any()) return;
	int pivot = ctz(p | x);
	bitset<128> tp = p & ~adj[pivot];
	while (tp.any() && t > ans) {
		int v = ctz(tp);
		auto bv = bitset<128>(1) << v;
		dfs(r | bv, p & adj[v], x & adj[v]);
		p ^= bv;
		x |= bv;
		t--;
		if (t <= ans)
			return;
		tp ^= bv;
	}
}
