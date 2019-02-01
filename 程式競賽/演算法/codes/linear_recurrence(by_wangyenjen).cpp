// codechef POWSUMS
const int MAX_N = 300 + 10;
const ll MOD = 1000000000LL + 7LL;
ll p[MAX_N] , e[MAX_N];
inline ll power(ll a , ll n) {
    a %= MOD;
    ll x = 1LL;
    while(n) {
        if(n&1LL) x = x * a % MOD;
        a = a * a % MOD;
        n >>= 1LL;
    }
    return x;
}
inline ll inv(ll x) {
    return power(x , MOD - 2LL);
}
ll n , m;
ll dp[MAX_N<<1];
inline void pre_dp() {
    ll bdr = min(n + n , m);
    for(ll i = 0; i <= bdr; i++) {
        if(i < n) dp[i] = p[i + 1];
        else {
            dp[i] = 0LL;
            REP1(j , 1 , int(n)) dp[i] = (dp[i] + e[j] * dp[i - j] % MOD) % MOD;
        }
    }
}
inline vector<ll> mul(vector<ll>& v1 , vector<ll>& v2) {
    int sz1 = (int)v1.size();
    int sz2 = (int)v2.size();
    vector<ll> _v(n + n);
    for(int i = 0; i < n + n; i++) _v[i] = 0;
    // expand
    for(int i = 0; i < sz1; i++) {
        for(int j = 0; j < sz2; j++) {
            (_v[i + j + 1] += v1[i] * v2[j] % MOD) %= MOD;
        }
    }
    // shrink
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= n; j++) {
            (_v[i + j] += _v[i] * e[j]) %= MOD;
        }
    }
    for(int i = 0; i < n; i++) _v[i] = _v[i + n];
    _v.resize(n);
    return _v;
}
vector<ll> I , A;
inline ll solve() {
    pre_dp();
    if(m <= n + n) return dp[m];
    I.resize(n);
    A.resize(n);
    for(int i = 0; i < n; i++) {
        I[i] = e[i + 1];
        A[i] = e[i + 1];
    }
    // dp[m] = /Sum_{i=0}^{n-1} A_i * dp[m - i - 1]
    ll dlt = (m - n) / n;
    ll rdlt = dlt * n;
    while(dlt) {
        if(dlt & 1LL) I = mul(I , A);
        A = mul(A , A);
        dlt >>= 1LL;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        (ans += I[i] * dp[m - i - 1 - rdlt] % MOD) %= MOD;
    }
    return ans;
}
int main() {
    int T;
    RI(T);
    while(T--) {
        int Q;
        RI(n , Q);
        REP1(i , 1 , int(n)) RI(p[i]);
        p[0] = 0LL;
        e[0] = 1LL;
        e[1] = p[1];
        REP1(i , 2 , int(n)) {
            ll sign = 1LL;
            e[i] = 0LL;
            REP1(j , 1 , i) {
                e[i] = (e[i] + (sign * e[i - j] * p[j] % MOD) + MOD) % MOD;
                sign *= -1LL;
            }
            e[i] = e[i] * inv((ll)i) % MOD;
        }
        REP1(i , 1 , int(n)) if(~i&1) e[i] = (MOD - e[i]) % MOD;
        vector<ll> ans;
        REP(i , Q) {
            RI(m);
            m--;
            ans.PB(solve());
        }
        REP(i , Q) printf("%lld%c",ans[i]," \n"[i == Q - 1]);
    }
    return 0;
}
