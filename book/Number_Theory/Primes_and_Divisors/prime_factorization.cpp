// Note: Reuses the name "factorize" from your second file, which returns a map.
hash_map<int, int> factorize(int x) {
    hash_map<int, int> f;
    while (x > 1) {
        int p = spf[x], c = 0;
        while (x % p == 0)
            x /= p, c++;
        f[p] = c;
    }
    return f;
}

vi factorize(int x) {
    vi factors;
    while (x > 1) {
        factors.PB(spf[x]);
        x /= spf[x];
    }
    return factors;
}

vvi get_all_prime_factors(int n) {
    vvi factors(n + 1);

    for (int i = 2; i <= n; i++) {
        int curr = i;
        while (curr > 1) {
            factors[i].push_back(spf[curr]);
            curr /= spf[curr];
        }
    }

    return factors;
}

vi primeFact(int x) {
    vi factors;
    while (x > 1) {
        int p = spf[x];
        while (x % p == 0) x /= p;
        factors.PB(p);
    }
    return factors;
}

hash_map<int, int> big_factorize(ll n) {
    hash_map<int, int> mp;
    for (int p: primes) {
        if (p > n / p) break;
        if (n % p == 0) {
            ll c = 0;
            while (n % p == 0) {
                n /= p;
                c++;
            }
            mp[p] = c;
        }
    }
    if (n > 1) {
        mp[n] = 1;
    }
    return mp;
}

vi generateDivisorsFromFactors(const mii &mp) {
    vector<int> divisors = {1};
    for (const auto &pc: mp) {
        int p = pc.F;
        int cnt = pc.S;
        int sz = divisors.size();
        long long power = 1;
        for (int k = 1; k <= cnt; ++k) {
            power *= p;
            for (int i = 0; i < sz; ++i) {
                divisors.push_back((int) (divisors[i] * power));
            }
        }
    }
    return divisors;
}
