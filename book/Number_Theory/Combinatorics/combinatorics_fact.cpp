vector<ll> invfact, fact;

void pre_ncr(int x = MAXN)
{
    fact.assign(x + 5, 0);
    invfact.assign(x + 5, 0);

    fact[0] = 1;
    for (int i = 1; i <= x; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invfact[x] = inv(fact[x], MOD);
    for (int i = x - 1; i >= 0; i--)
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }
}

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