int par[maxn][20];
void init(int n) {
	for (int i = 0; i < n; i++)
		fill_n(par[i], 20, i);
}
int find(int x, int y = 0) {
	return (par[x][y] == x) ? x : (par[x][y] = find(par[x][y], y));
}
bool merge(int x, int y, int k) {
	x = find(x, k);
	y = find(y, k);
	if (x == y)
		return false;
	par[y][k] = x;
	if (k--) {
		merge(x, y, k);
		merge(x + (1 << k), y + (1 << k), k);
	}
	return true;
}
