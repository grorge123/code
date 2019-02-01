int p_tbl[MX];
vector<int> primes;
void sieve() {
  p_tbl[1] = 1;
  for (int i=2; i<MX; i++) {
    if (!p_tbl[i]) {
      p_tbl[i] = i;
      primes.PB(i);
    }
    for (auto p : primes) {
      if (i*p >= M) break;
      p_tbl[i*p] = p;
      if (i%p==0)
        break;
    }
  }
}
vector<int> factor(int x) {
  vector<int> fac{1};
  while (x > 1) {
    int fn=SZ(fac), p=p_tbl[x], pos=0;
    while (x%p == 0) {
      x /= p;
      for (int i=0; i<fn; i++)
        fac.PB(fac[pos++]*p);
    }
  }
  return fac;
}
