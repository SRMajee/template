vector<int> primes;
vector<int> spf, p_inv;
mii revPrime;
vi mask_of;
ll binpow(ll a, ll e, ll m = MOD)
{
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

void linear_sieve(int n)
{
    spf.assign(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            revPrime[i] = SZ(primes);
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

void pre(int n)
{
    mask_of.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int t = 0;
        int temp = i;
        while (temp > 1)
        {
            int p = spf[temp];
            while (temp % p == 0)
                temp /= p;
            t |= 1ll << revPrime[p];
        }
        mask_of[i] = t;
    }
    p_inv.assign(SZ(primes), 0);
    for (auto &i : primes)
    {
        int j = revPrime[i];
        p_inv[j] = mul(i - 1, inv(i));
    }
}
int getTotient(int mask, int ans)
{
    while (mask)
    {
        int bit = mask & -mask;
        mask ^= bit;
        ans = mul(ans, p_inv[__builtin_ctzll(bit)]);
    }
    return ans;
}