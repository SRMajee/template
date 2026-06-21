#include "cp_utils.h"

static int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
// -------- Floor Div --------
inline int floordiv(int p, int q)
{
    if (q < 0)
        p = -p, q = -q;
    return (p >= 0 ? p / q : -((-p + q - 1) / q));
}

// -------- Ceil Div --------
inline int ceildiv(int p, int q) { return -floordiv(-p, q); }

ll totient(ll n);

// --------- Modular arithmetic ---------
ll binpow(ll a, ll e, ll m = MOD)
{
    // e = e % totient(m);
    int res = 1;
    a %= m;
    while (e)
    {
        if (e & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        e >>= 1;
    }
    return res;
}

ll inv(ll a, ll m = MOD) { return binpow(a, m - 2, m); }
inline ll add(ll a, ll b, ll m = MOD) { return (a + (b % m) + m) % m; }
inline ll sub(ll a, ll b, ll m = MOD) { return (a - (b % m) + m) % m; }
inline ll mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }
inline ll _div(ll a, ll b, ll m = MOD) { return mul((a % m), inv(b, m), m); }
// ∑ (subset_sum)^2 = 2^(c-1)*Q + 2^(c-2)*S^2
/*
 * c = count
 * S = sum
 * Q = sum of square
 */
inline ll subset_sum(ll c, ll S, ll Q)
{
    ll ans = add(mul(binpow(2, c - 1), Q), mul(binpow(2, c - 2), binpow(S, 2)));
}
// --------- Inverse Cache for inv(x) -----------
hash_map<int, int> inv_cache;
auto inv_memo = [](int x) -> int
{
    x = (x % MOD + MOD) % MOD;
    auto it = inv_cache.find(x);
    if (it != inv_cache.end())
        return it->second;
    int res = inv(x);
    inv_cache[x] = res;
    return res;
};

// ---------- Precompute Divisors -----------
vi divisors[MAXN];
void pre()
{
    fr(i, 1, MAXN - 9)
    {
        for (int j = i; j < MAXN - 9; j += i)
        {
            divisors[j].PB(i);
        }
    }
}

// ---------- Precompute Factorials and Inverse Factorials -----------
ll invfact[MAXN], fact[MAXN];

void pre_ncr()
{
    fact[0] = 1;
    for (int i = 1; i <= MAXN - 5; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invfact[MAXN - 5] = inv(fact[MAXN - 5], MOD);
    for (int i = MAXN - 5 - 1; i >= 0; i--)
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }
}

// ---------- nCr -----------
ll ncr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    ll ans = fact[n];
    ans = (ans * invfact[n - r]) % MOD;
    ans = (ans * invfact[r]) % MOD;
    return ans;
}
ll neg_nCr(int n, int k)
{
    if (k < 0)
        return 0;
    if (k == 0)
        return 1;
    return ncr(n + k - 1, k);
}
// ---------- nPr -----------
ll npr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    ll ans = fact[n];
    ans = (ans * invfact[n - r]) % MOD;
    return ans;
}
vvi nCr;
void precompute_nCr(int x)
{
    nCr.assign(x + 2, vi(x + 2, 0));
    for (int i = 0; i <= x; ++i)
    {
        nCr[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
        }
    }
}

// --------- Factorial Exact ----------
ll fact_exact(int n)
{
    ll res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

// ---------- nCr Exact ----------
ll nCr_exact(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    if (r > n - r)
        r = n - r; // symmetry

    i128 res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (n - r + i) / i;
    }
    return (ll)res; // cast back (be careful: may overflow!)
}

// ---------- npr Exact ----------
ll nPr_exact(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    i128 res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n - i); // multiply n * (n-1) * ... * (n-r+1)
    }
    return (ll)res; // careful: may overflow if result > 9e18
}

ll C[NCRange][NCRange];
ll prefix_NCR[NCRange][NCRange];

// ---------- Pre Compute nCr -----------
void compute_prefixNCR()
{
    int n = NCRange - 1, k = NCRange - 1;
    for (int i = 0; i <= n; i++)
    {
        prefix_NCR[i][0] = C[i][0] = 1;
        for (int j = 1; j <= min(i, k); j++)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
        for (int j = 1; j <= min(i, k); j++)
        {
            prefix_NCR[i][j] = (prefix_NCR[i][j - 1] + C[i][j]) % MOD;
        }
    }
}

// --------- GCD / LCM ---------
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

// --------- Sieve (primes + SPF) ---------
vector<int> primes;
int spf[MAXN];

void sieve(int n = 1e6)
{
    iota(spf, spf + n + 1, 0);
    for (int i = 2; i * i <= n; i++)
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    for (int i = 2; i <= n; i++)
        if (spf[i] == i)
            primes.PB(i);
}

void linear_sieve(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            primes.PB(i);
        }
        for (int p : primes)
        {
            if (p > spf[i] || i * p > n)
                break;
            spf[i * p] = p;
        }
    }
}

vi factorize(int x)
{
    vi factors;
    while (x > 1)
    {
        factors.PB(spf[x]);
        x /= spf[x]; // no division by arbitrary numbers
    }
    return factors;
}
// Returns a 2D vector where factors[i] contains all prime factors of i
vvi get_all_prime_factors(int n)
{
    vvi factors(n + 1);

    for (int i = 2; i <= n; i++)
    {
        int curr = i;
        while (curr > 1)
        {
            factors[i].push_back(spf[curr]);
            curr /= spf[curr];
        }
    }

    return factors;
}
// O(√n)   n<=10^12
// ---------- Totient ( 10^12 ) -----------
ll totient(ll n)
{
    ll res = n;
    for (ll p : primes)
    {
        if (1LL * p * p > n)
            break;
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            res -= res / p;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

// O(nlog(log(n)))  n<=10^6
// ---------- Totient from 1 to 10^6  -----------
vi totient_1_to_n(int n)
{
    vi phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int p : primes)
    {
        if (p > n)
            break; // only use primes ≤ n
        for (int j = p; j <= n; j += p)
        {
            phi[j] -= phi[j] / p;
        }
    }
    return phi;
}

// --------- Get Reduced Fraction ----------
pll get_red_frac(ll a, ll b)
{
    if (a == 0 && b == 0)
        return MP(0, 0);
    if (a == 0)
        return MP(0, 1);
    if (b == 0)
        return MP(1, 0);
    int neg = 1;
    if (a < 0)
    {
        a *= -1;
        neg *= -1;
    }
    if (b < 0)
    {
        b *= -1;
        neg *= -1;
    }
    ll g = __gcd(a, b);
    return MP(neg * a / g, b / g);
}

// ---------- Check Palindrome -----------
template <typename T>
bool is_palindrome(const T &container)
{
    int n = container.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (container[i] != container[n - i - 1])
            return false;
    }
    return true;
}

// ---------- Check if Pal Possible -----------
template <typename Container>
bool canFormPalindrome(const Container &cont)
{
    hash_map<typename Container::value_type, int> freq;
    for (auto &el : cont)
        ++freq[el];
    int oddCount = 0;
    for (auto &[val, count] : freq)
    {
        if (count % 2 != 0)
            oddCount++;
    }
    return oddCount <= 1; // at most one element can have odd frequency
}

// --------- Gen N Fib Nos ----------
vi gen_n_fib_no(int n)
{
    vi v;
    v.PB(0);
    v.PB(1);
    int a = 0, b = 1;
    while (true)
    {
        int c = a + b;
        if (c >= n)
            break;
        v.PB(c);
        a = b;
        b = c;
    }
    return v;
}
