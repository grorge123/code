using cplx = complex<double>;
constexpr double pi = acos(-1.0);
void fft(cplx *a, int n, bool inverse) {
	static cplx tmp[maxn];
	if (n == 1) return;
	copy_n(a, n, tmp);
	for (int i = 0; i < n; i++)
		a[(i & 1) ? (n >> 1) + (i >> 1) : (i >> 1)] = tmp[i];
	cplx *a1 = a, *a2 = a + (n >> 1);
	fft(a1, n >> 1, inverse);
	fft(a2, n >> 1, inverse);
	cplx w_base = polar(1.0, 2.0 * pi / n);
	if (inverse)
		w_base = conj(w_base);
	cplx w(1.0);
	for (int i = 0; (i << 1) < n; i++, w *= w_base) {
		tmp[i] = a1[i] + w * a2[i];
		tmp[(n >> 1) + i] = a1[i] - w * a2[i];
	}
	copy_n(tmp, n, a);
}
int mult(cplx *a, int la, cplx *b, int lb, cplx *c) {
	int n = 2;
	while (n < la + lb) n <<= 1;
	fill(a + la, a + n, cplx());
	fill(b + lb, b + n, cplx());
	fft(a, n, false);
	fft(b, n, false);
	for (int i = 0; i < n; i++) c[i] = a[i] * b[i];
	fft(c, n, true);
	for (int i = 0; i < n; i++) c[i] /= n;
	return la + lb - 1;
}
