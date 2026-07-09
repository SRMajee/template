// find primes int range L to R where (R-L) <=1e6 and R,L <= 1e18
vector<int> segmented_seive(int R, int L, vector<int> base_primes) {
    vector<bool> isPrime(R - L + 1, true);
    vector<int> primes;
    for (int p: base_primes) {
        if (p * p > R) break;
        int st = max(p * p, ((L + p - 1) / p) * p);
        for (int i = st; i <= R; i += p) {
            isPrime[i - L] = false;
        }
    }
    for (int i = 0; i <= R - L; i++) {
        if (isPrime[i] && (i + L) > 1) primes.push_back(i + L);
    }
}
