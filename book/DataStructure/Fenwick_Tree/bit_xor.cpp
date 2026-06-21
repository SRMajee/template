// Bit Xor
struct BIT_Xor {
    int n;
    vector<ll> tree;

    void init(int n_) {
        n = n_;
        tree.assign(n + 1, 0);
    }

    void add(int i, ll v) {
        for (; i <= n; i += i & -i)
            tree[i] ^= v;
    }

    ll query(int i) {
        ll s = 0;
        for (; i > 0; i -= i & -i)
            s ^= tree[i];
        return s;
    }

    ll query(int l, int r) {
        if (l > r)
            return 0;
        return query(r) ^ query(l - 1);
    }
};
