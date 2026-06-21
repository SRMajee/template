ll binpow(ll a, ll e, ll m = MOD)
{
    int res = 1;
    a %= m;
    while (e)
    {
        if (e & 1) res = (res * a) % m;
        a = (a * a) % m;
        e >>= 1;
    }
    return res;
}

ll inv(ll a, ll m = MOD) { return binpow(a, m - 2, m); }
inline ll _div(ll a, ll b, ll m = MOD) { return mul((a % m), inv(b, m), m); }



inline ll add(ll a, ll b, ll m = MOD) { return (a + (b % m) + m) % m; }
inline ll sub(ll a, ll b, ll m = MOD) { return (a - (b % m) + m) % m; }
inline ll mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }

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