int p[maxn], e[maxn], dp[2 * maxn];
vector<int> mul(const vector<int>& v1, const vector<int>& v2) {
	int n = v1.size();
	vector<int> v(2 * n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v[i + j + 1] = (v[i + j + 1] + (ll) v1[i] * v2[j]) % mod;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v[i + j + 1] = (v[i + j + 1] + (ll) v[i] * e[j]) % mod;
	v.erase(v.begin(), v.begin() + n);
	return v;
}
void pre_dp(int n) {
	copy_n(p, n, dp);
	for (int i = n; i < 2 * n; i++) {
		dp[i] = 0;
		for (int j = 0; j < n; j++)
			dp[i] = (dp[i] + (ll) e[j] * dp[i - j - 1]) % mod;
	}
}
int solve(int n, ll m) {
	if (m < 2 * n) return dp[m];
	vector<int> vi(e, e + n), va = vi;
	ll dlt = (m - n) / n, rdlt = dlt * n;
	while (dlt) {
		if (dlt & 1)
			vi = mul(vi, va);
		va = mul(va, va);
		dlt >>= 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + (ll) vi[i] * dp[m - i - 1 - rdlt]) % mod;
	return ans;
}
