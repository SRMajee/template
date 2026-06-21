// ---------- Range Add, Range query (Fenwick of two) ----------
struct RangeAddRangeSum {
    int n;
    Fenwick B1, B2;
    RangeAddRangeSum(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        B1.init(n);
        B2.init(n);
    }

    // internal: prefix query after range adds
    ll _pref(int x) const {
        return B1.query(x) * x - B2.query(x);
    }

    // add x to [l..r]
    void add(int l, int r, ll x) {
        if (l > r) return;
        B1.add(l, x);
        if (r + 1 <= n) B1.add(r + 1, -x);
        B2.add(l, x * (l - 1));
        if (r + 1 <= n) B2.add(r + 1, -x * r);
    }

    // range query [l..r]
    ll query(int l, int r) const {
        if (r < l) return 0;
        return _pref(r) - _pref(l - 1);
    }
};
