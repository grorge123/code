ll modpow(ll a, ll b, ll m) {
	ll r = 1;
	while (b) {
		if (b & 1) r = (__int128) r * a % m;
		a = (__int128) a * a % m;
		b >>= 1;
	}
	return r;
}
bool miller_rabin(ll n, ll a) {
	if (__gcd(a, n) == n) return true;
	if (__gcd(a, n) != 1) return false;
	ll d = n - 1, r = 0;
	while (~d & 1) r++, d >>= 1;
	ll res = modpow(a, d, n);
	if (res == 1 || res == n - 1) return true;
	while (r--) {
		res = (__int128) res * res % n;
		if(res == n - 1) return true;
	}
	return false;
}
bool is_prime(ll n) {
	// n < 4,759,123,141		{2, 7, 61}
	// n < 1,122,004,669,633	{2, 13, 23, 1662803}
	// n < 3,474,749,660,383	{primes <= 13}
	for (ll x : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
		if (!miller_rabin(n, x))
			return false;
	return true;
}
