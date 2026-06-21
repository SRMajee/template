vector<int> primes;
vector<int> spf;


void linear_sieve(int n)
{
    spf.assign(n + 1, 0);
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