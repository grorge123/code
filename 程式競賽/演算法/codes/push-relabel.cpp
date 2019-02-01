#include <algorithm>
#include <list>
constexpr int maxn = 604;
int c[maxn][maxn], f[maxn][maxn], h[maxn], e[maxn], g[2 * maxn + 1];
int max_flow(int s, int t, int n) {
  for (int i = 0; i < n; i++)
    fill_n(f[i], n, 0);
  fill_n(h, n, 0);
  fill_n(e, n, 0);
  fill_n(g, 2 * n + 1, 0);
  for (int i = 0; i < n; i++) {
    f[s][i] = e[i] = c[s][i];
    f[i][s] = -c[s][i];
  }
  h[s] = n;
  e[s]++, e[t]++;
  g[0] = n - 1;
  g[n] = 1;
  list<int> fifo;
  for (int i = 0; i < n; i++)
    if (i != s && i != t && e[i])
      fifo.push_back(i);
  while (!fifo.empty()) {
    int u = fifo.front();
    fifo.pop_front();
    while (e[u]) {
      for (int v = 0; e[u] && v < n; v++) {
        if (h[u] == h[v] + 1 && f[u][v] < c[u][v]) {
          if (e[v] == 0)
            fifo.push_back(v);
          int x = min(e[u], c[u][v] - f[u][v]);
          e[u] -= x;
          e[v] += x;
          f[u][v] += x;
          f[v][u] -= x;
        }
      }
      if (e[u]) {
        if (--g[h[u]] == 0 && h[u] < n)
          for (int i = 0; i < n; i++)
            if (h[i] > h[u] && h[i] < n)
              h[i] = n + 1;
        h[u] = 2 * n;
        for (int v = 0; v < n; v++)
          if (f[u][v] < c[u][v])
            h[u] = min(h[u], h[v] + 1);
        g[h[u]]++;
      }
    }
  }
  return e[t] - 1;
}
