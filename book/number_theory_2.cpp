#include "cp_utils.h"
// ---------- Prime Factorise a number (10^6)  -----------
hash_map<int, int> factorize(int x)
{
    hash_map<int, int> f;
    while (x > 1)
    {
        int p = spf[x], c = 0;
        while (x % p == 0)
            x /= p, c++;
        f[p] = c;
    }
    return f;
}
vi primeFact(int x)
{
    vi factors;
    while (x > 1)
    {
        int p = spf[x];
        while (x % p == 0)
            x /= p;
        factors.PB(p);
    }
    return factors;
}

// ---------- Prime Factorise a number (10^12)  -----------
hash_map<int, int> big_factorize(ll n)
{
    hash_map<int, int> mp;
    ll ans = 1;
    for (int p : primes)
    {
        if (p > n / p)
            break;
        if (n % p == 0)
        {
            ll c = 0;
            while (n % p == 0)
            {
                n /= p;
                c++;
            }
            mp[p] = c;
        }
    }
    if (n > 1)
    {
        mp[n] = 1;
    }
    return mp;
}

// ----------- Get Divisor from factors map --------------
vi generateDivisorsFromFactors(const mii &mp)
{
    vector<int> divisors = {1};
    for (const auto &pc : mp)
    {
        int p = pc.F;
        int cnt = pc.S;
        int sz = divisors.size();
        // multiply existing divisors by p^1, p^2, ... p^cnt
        long long power = 1;
        for (int k = 1; k <= cnt; ++k)
        {
            power *= p;
            for (int i = 0; i < sz; ++i)
            {
                divisors.push_back((int)(divisors[i] * power));
            }
        }
    }
    return divisors;
}

// ---------- Miller Rabin prime  -----------
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n % p == 0)
            return n == p;
    }
    int d = n - 1, s = 0;
    while ((d & 1) == 0)
        d >>= 1, s++;

    // Deterministic bases for 64-bit integers
    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
    {
        if (a % n == 0)
            continue;
        int x = binpow(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
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
        if (comp)
            return false;
    }
    return true;
}

// ---------- Split -----------
vector<string> split(const string &s, char delim = ' ')
{
    vector<string> result;
    string word;
    for (char c : s)
    {
        if (c == delim)
        {
            if (!word.empty())
            {
                result.push_back(word);
                word.clear();
            }
        }
        else
        {
            word += c;
        }
    }
    if (!word.empty())
        result.push_back(word);
    return result;
}
