// Requires your previously defined ncr() function
ll lucas(ll n, ll m) 
{
    if (m == 0) return 1;
    int ni = n % MOD;
    int mi = m % MOD;
    if (mi > ni) return 0;
    
    return (lucas(n / MOD, m / MOD) * ncr(ni, mi)) % MOD; 
}