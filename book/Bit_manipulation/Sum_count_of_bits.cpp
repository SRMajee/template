// Sum of count of bits of all numbers <= n from 0
ll sum_count_of_bits(ll n) {
    if (n == 0) return 1LL;
    ll k = 64 - __builtin_clzll(n); // no of digits
    return k * (n + 1) - (1LL << k) + 2LL;
}

