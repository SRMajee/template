struct Fenwick {
    int n;
    vl bit;

    Fenwick(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }

    // Build from 1-indexed array a[1..n] in O(n)
    void build(const vl &a) {
        // a.size() should be n+1 with a[0] dummy
        init((int) a.size() - 1);
        for (int i = 1; i <= n; i++) bit[i] = a[i];
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }

    // add x at index i
    inline void add(int i, ll x) {
        for (; i <= n; i += i & -i) bit[i] += x;
    }

    // prefix query [1..i]
    inline ll query(int i) const {
        ll r = 0;
        for (; i > 0; i -= i & -i) r += bit[i];
        return r;
    }

    // range query [l..r]
    inline ll query(int l, int r) const {
        if (r < l) return 0;
        return query(r) - query(l - 1);
    }

    // smallest idx such that prefix query >= target
    // if target <= 0 returns 1; if target > total, returns n+1 (clamp outside)
    int lower_bound(ll target) const {
        if (target <= 0) return 1;
        ll pref = 0;
        int idx = 0;

        for (int step = 1 << 30; step; step >>= 1) {
            int next = idx + step;
            if (next <= n && pref + bit[next] < target) {
                pref += bit[next];
                idx = next;
            }
        }
        return idx + 1; // may be n+1 if target > total
    }
};
