bool isPrime(int n)
{
    if (n < 2) return false;
    for (int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n % p == 0) return n == p;
    }
    int d = n - 1, s = 0;
    while ((d & 1) == 0)
        d >>= 1, s++;

    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
    {
        if (a % n == 0) continue;
        int x = binpow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (int r = 1; r < s; r++)
        {
            x = mul(x, x, n);
            if (x == n - 1)
            {
                comp = false;
                break;
            }
        }
        if (comp) return false;
    }
    return true;
}