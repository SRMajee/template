ll fact_exact(int n)
{
    ll res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

ll nCr_exact(int n, int r)
{
    if (r < 0 || r > n) return 0;
    if (r > n - r) r = n - r; // symmetry

    i128 res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (n - r + i) / i;
    }
    return (ll)res; 
}

ll nPr_exact(int n, int r)
{
    if (r < 0 || r > n) return 0;

    i128 res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n - i); 
    }
    return (ll)res; 
}