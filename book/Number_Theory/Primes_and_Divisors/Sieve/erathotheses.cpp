vector<int> primes;
vector<int> spf;

void sieve(int n = 1e6)
{
    spf.assign(n + 1, 0);
    iota(spf.begin(), spf.end(), 0);
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