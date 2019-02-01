int inv[maxn + 1];
void build(int n) {
	inv[1] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = (long long) (mod - mod / i) * inv[mod % i] % mod;
}
