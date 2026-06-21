// Sum of count of 1 of all numbers <= n from 1
ll sum_count_of_1s(ll x, int step = 1) {
    ll ans = 0;
    x++;
    for (int i = step - 1; i < 60; i += step) {
        ll full = x / (1LL << (i + 1));
        ll left = x % (1LL << (i + 1));
        ans += full * (1LL << i) + max(0LL, left - (1LL << i));
    }
    return ans;
}

