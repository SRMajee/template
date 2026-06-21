// O(√n)   n<=10^12
ll totient(ll n)
{
    ll res = n;
    for (ll p : primes)
    {
        if (1LL * p * p > n) break;
        if (n % p == 0)
        {
            while (n % p == 0) n /= p;
            res -= res / p;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

// O(nlog(log(n)))  n<=10^6
vi totient_1_to_n(int n)
{
    vi phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int p : primes)
    {
        if (p > n) break; 
        for (int j = p; j <= n; j += p)
        {
            phi[j] -= phi[j] / p;
        }
    }
    return phi;
}

int getTotient(int mask)
{
    int ans = 0;
    while (mask)
    {
        int bit = mask & -mask;
        mask ^= bit;
        ans |= 1ll << bit;
    }
    return ans;
}