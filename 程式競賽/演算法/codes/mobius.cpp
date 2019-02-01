// BZOJ 2301
// How many pairs of gcd(x , y) = k , a <= x <= b and c <= y <= d
const int MAX_N = 50000 + 10;
int mu[MAX_N];
ll sum[MAX_N];
vector<int> prime;
bool is_prime[MAX_N];
inline void predo() {
    REP1(i , 2 , MAX_N - 1) is_prime[i] = 1;
    mu[1] = 1;
    REP1(i , 2 , MAX_N - 1) {
        if(is_prime[i]) {
            prime.PB(i);
            mu[i] = -1;
        }
        REP(j , SZ(prime)) {
            int p = prime[j];
            if(p * i >= MAX_N) break;
            is_prime[p * i] = 0;
            if(i % p == 0) {
                mu[p * i] = 0;
                break;
            }
            else mu[p * i] = -mu[i];
        }
    }
    REP1(i , 1 , MAX_N - 1) sum[i] = sum[i - 1] + mu[i];
}
inline ll calc(int n , int m) {
    if(n > m) swap(n , m);
    ll ans = 0 , p;
    for(int i = 1; i <= n; i = p + 1) {
        p = min(n / (n / i) , m / (m / i));
        ans += (sum[p] - sum[i - 1]) * (n / i) * (m / i);
    }
    return ans;
}
int main() {
    predo();
    int n;
    scanf("%d",&n);
    while(n--) {
        int a , b , c , d , k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        printf("%lld\n",calc(b / k , d / k) - calc((a - 1) / k , d / k) - calc(b / k , (c - 1) / k) + calc((a - 1) / k , (c - 1) / k));
    }
    return 0;
}
