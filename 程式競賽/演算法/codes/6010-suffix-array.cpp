const int MAX_N = 100000 + 7;
char str[MAX_N]; // need null character
// sa[0] = "", ht[i + 1] = lcp(sa[i], sa[i + 1])
int sa[MAX_N] , cnt[MAX_N] , rk[2][MAX_N] , ht[MAX_N];

inline void build_sa(int n , int m) {
    int *x = rk[0];
    int *y = rk[1];
    for(int i = 0; i < m; i++) cnt[i] = 0;
    for(int i = 0; i <= n; i++) cnt[x[i] = str[i]]++;
    for(int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
    for(int i = n; i >= 0; i--) sa[--cnt[x[i]]] = i;
    for(int k = 1; ; k <<= 1) {
        int p = 0;
        for(int i = n - k + 1; i <= n; i++) y[p++] = i;
        for(int i = 0; i <= n; i++) if(sa[i] >= k) y[p++] = sa[i] - k;
        for(int i = 0; i < m; i++) cnt[i] = 0;
        for(int i = 0; i <= n; i++) cnt[x[y[i]]]++;
        for(int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
        for(int i = n; i >= 0; i--) sa[--cnt[x[y[i]]]] = y[i];
        swap(x , y);
        p = 1;
        x[sa[0]] = 0;
        for(int i = 1; i <= n; i++) x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? p - 1 : p++);
        if(p >= n + 1) break;
        else m = p;
    }
}

inline void build_ht(int n) {
    int *x = rk[0];
    for(int i = 1; i <= n; i++) x[sa[i]] = i;
    for(int i = 0 , h = 0; i < n; i++) {
        int j = sa[x[i] - 1];
        if(h) h--;
        while(str[i + h] == str[j + h]) h++;
        ht[x[i]] = h;
    }
}

int main() {
    scanf("%s",str);
    int n = strlen(str);
    build_sa(n , 128);
    build_ht(n);
    for(int i = 1; i <= n; i++) printf("%d%c",sa[i] + 1," \n"[i == n]);
    for(int i = 2; i <= n; i++) printf("%d%c",ht[i]," \n"[i == n]);
    return 0;
}
