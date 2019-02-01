// # {(x, y) in [1, n] * [1, m] | gcd(x, y) = 1}
int mu[maxn + 1];
ll sum[maxn + 1];
vector<int> prime;
bool is_prime[maxn + 1];
void preprocess() {
	fill(is_prime + 2, is_prime + maxn + 1, true);
	mu[1] = 1;
	for (int i = 2; i <= maxn; i++) {
		if (is_prime[i]) {
			prime.push_back(i);
			mu[i] = -1;
		}
		for (int p : prime) {
			if (p * i > maxn)
				break;
			is_prime[p * i] = false;
			if (i % p == 0) {
				mu[p * i] = 0;
				break;
			}
			mu[p * i] = -mu[i];
		}
	}
	partial_sum(mu + 1, mu + maxn + 1, sum + 1);
}
ll count_coprime_pairs(int n, int m) {
	ll ans = 0;
	for(int i = 1, p; i <= min(n, m); i = p + 1) {
		p = min(n / (n / i), m / (m / i));
		ans += (sum[p] - sum[i - 1]) * (n / i) * (m / i);
	}
	return ans;
}
